#include "global.h"
#include "online_store.h"
#include "config/online_store.h"
#include "event_data.h"
#include "item.h"
#include "money.h"
#include "script.h"
#include "task.h"
#include "list_menu.h"
#include "malloc.h"
#include "shop.h"
#include "menu.h"
#include "string_util.h"
#include "main.h"
#include "strings.h"
#include "text_window.h"
#include "script_menu.h"
#include "config/online_store.h"
#include "constants/items.h"
#include <stddef.h>

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

#define CART_CAPACITY 20
#define STORE_MAX_SHOWED 8

struct CartItem
{
    u16 itemId;
    u16 quantity;
};

static EWRAM_DATA struct CartItem sCart[CART_CAPACITY] = {0};
static EWRAM_DATA u8 sCartCount = 0;
static EWRAM_DATA u16 sSurcharge = ONLINE_STORE_SURCHARGE;

static void CartClear(void);
static bool32 HasEnoughMoneyForCart(void);
static void DeliverCartItems(void);
static bool32 IsItemEligible(u16 itemId);
static void FreeItemList(void);
static void DestroyStore(void);
static void StoreTask_BrowseCategory(u8 taskId);
static void OnlineStore_SetCategory(u8 category);
static void Store_QtyPrompt(u16 itemId);

bool8 OnlineStore_Open(const u16 *inventory)
{
    if (OnlineStore_IsContextBlocked())
        return FALSE;

    // The inventory parameter is currently unused but allows
    // external callers to specify a custom inventory in the future.
    (void)inventory;

    LockPlayerFieldControls();
    OnlineStore_SetCategory(0);
    CreateTask(StoreTask_BrowseCategory, 8);
    return TRUE;
}

bool8 OnlineStore_IsContextBlocked(void)
{
#if defined(CONFIG_ONLINE_STORE_BLOCK) && defined(FLAG_ONLINE_STORE_BLOCK)
    if (FlagGet(FLAG_ONLINE_STORE_BLOCK))
        return TRUE;
#endif
    return FALSE;
}

u16 OnlineStore_GetUnitPrice(u16 itemId)
{
    return GetItemPrice(itemId) + sSurcharge;
}

void OnlineStore_SetSurcharge(u16 yen)
{
    sSurcharge = yen;
}

static bool32 IsItemEligible(u16 itemId)
{
    if (GetItemPrice(itemId) == 0)
        return FALSE;
    if (GetItemImportance(itemId))
        return FALSE;
    return TRUE;
}

static bool32 AddToCart(u16 itemId, u16 quantity)
{
    u8 i;

    if (quantity == 0 || !IsItemEligible(itemId))
        return FALSE;

    for (i = 0; i < sCartCount; i++)
    {
        if (sCart[i].itemId == itemId)
        {
            sCart[i].quantity += quantity;
            return TRUE;
        }
    }

    if (sCartCount >= CART_CAPACITY)
        return FALSE;

    sCart[sCartCount].itemId = itemId;
    sCart[sCartCount].quantity = quantity;
    sCartCount++;
    return TRUE;
}

static u32 CartGetTotalCost(void)
{
    u32 total = 0;
    u8 i;
    for (i = 0; i < sCartCount; i++)
        total += OnlineStore_GetUnitPrice(sCart[i].itemId) * sCart[i].quantity;
    return total;
}

static bool32 CartWillFitInBag(void)
{
    u8 i, j;
    u16 total;

    for (i = 0; i < sCartCount; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (sCart[j].itemId == sCart[i].itemId)
                break;
        }
        if (j != i)
            continue;

        total = sCart[i].quantity;
        for (j = i + 1; j < sCartCount; j++)
        {
            if (sCart[j].itemId == sCart[i].itemId)
                total += sCart[j].quantity;
        }

        if (!CheckBagHasSpace(sCart[i].itemId, total))
            return FALSE;
    }

    return TRUE;
}

static bool32 HasEnoughMoneyForCart(void)
{
    return IsEnoughMoney(&gSaveBlock1Ptr->money, CartGetTotalCost());
}

static void DeliverCartItems(void)
{
    u8 i;
    for (i = 0; i < sCartCount; i++)
        AddBagItem(sCart[i].itemId, sCart[i].quantity);
}

static void OnlineStore_StartCheckout(void)
{
    if (CartWillFitInBag() && HasEnoughMoneyForCart())
    {
        RemoveMoney(&gSaveBlock1Ptr->money, CartGetTotalCost());
        DeliverCartItems();
    }
    CartClear();
}

static void CartClear(void)
{
    sCartCount = 0;
    memset(sCart, 0, sizeof(sCart));
}


struct OnlineStoreItem
{
    u16 itemId;
    u16 price;
    u8 name[ITEM_NAME_LENGTH + 1];
};

static struct OnlineStoreItem *sStoreItems = NULL;
static u16 sStoreItemCount = 0;
static u8 sCurrentCategory = 0;
static u8 sListTaskId;
static u8 sWindowId;
static struct ListMenuItem *sListItems = NULL;

static void PrintItemRow(u32 row);
static void StoreListMenu_ItemPrintFunc(u8 windowId, u32 row, u8 y);

static void FreeStoreItems(void)
{
    if (sStoreItems != NULL)
    {
        Free(sStoreItems);
        sStoreItems = NULL;
    }
    sStoreItemCount = 0;
}

static void FreeItemList(void)
{
    if (sListItems != NULL)
    {
        Free(sListItems);
        sListItems = NULL;
    }
}

static void DestroyStore(void)
{
    FreeItemList();
    CartClear();
}

static void PrintItemRow(u32 row)
{
    u8 y = row * 16;
    const struct OnlineStoreItem *item = &sStoreItems[row];

    AddTextPrinterParameterized(sWindowId, FONT_NARROW, item->name, 0, y, TEXT_SKIP_DRAW, NULL);
    ConvertIntToDecimalStringN(gStringVar1, item->price, STR_CONV_MODE_LEFT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    AddTextPrinterParameterized(sWindowId, FONT_NARROW, gStringVar4, 100, y, TEXT_SKIP_DRAW, NULL);
}

static void StoreListMenu_ItemPrintFunc(u8 windowId, u32 row, u8 y)
{
    PrintItemRow(row);
}

static int CompareItemsByName(const void *a, const void *b)
{
    const struct OnlineStoreItem *itemA = a;
    const struct OnlineStoreItem *itemB = b;
    return StringCompare(itemA->name, itemB->name);
}

static void BuildItemList(void)
{
    u16 i;
    const struct OnlineStoreCategory *category = &gOnlineStoreCategories[sCurrentCategory];

    FreeStoreItems();
    sStoreItems = Alloc(sizeof(*sStoreItems) * ITEMS_COUNT);
    if (sStoreItems == NULL)
        return;

    for (i = 1; i < ITEMS_COUNT; i++)
    {
        if (category->filter == NULL || category->filter(i))
        {
            sStoreItems[sStoreItemCount].itemId = i;
            sStoreItems[sStoreItemCount].price = OnlineStore_GetUnitPrice(i);
            CopyItemName(i, sStoreItems[sStoreItemCount].name);
            sStoreItemCount++;
        }
    }

    if (sStoreItemCount > 1)
        qsort(sStoreItems, sStoreItemCount, sizeof(*sStoreItems), CompareItemsByName);
}

static void OnlineStore_SetCategory(u8 category)
{
    if (category >= gOnlineStoreCategoryCount)
        category = 0;
    sCurrentCategory = category;
    BuildItemList();
}

//------------------------------------------------------------------------------
// Task handling
//------------------------------------------------------------------------------

// Task for browsing items within a category. This is a stub for the purposes
// of this repository; a full implementation would present the list to the
// player and allow purchases. The task currently performs no additional work.
void StoreTask_BrowseCategory(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    u16 i;

    switch (task->data[0])
    {
    case 0: // Initialize the list menu for the current category
        sListItems = Alloc(sizeof(*sListItems) * sStoreItemCount);
        if (sListItems == NULL)
        {
            DestroyTask(taskId);
            return;
        }

        for (i = 0; i < sStoreItemCount; i++)
        {
            sListItems[i].name = sStoreItems[i].name;
            sListItems[i].id = i;
        }

        gMultiuseListMenuTemplate.items = sListItems;
        gMultiuseListMenuTemplate.totalItems = sStoreItemCount;
        gMultiuseListMenuTemplate.maxShowed = (sStoreItemCount > STORE_MAX_SHOWED) ? STORE_MAX_SHOWED : sStoreItemCount;
        gMultiuseListMenuTemplate.itemPrintFunc = StoreListMenu_ItemPrintFunc;

        LoadMessageBoxAndBorderGfx();
        sWindowId = CreateWindowFromRect(0, 0, 19, gMultiuseListMenuTemplate.maxShowed * 2);
        SetStandardWindowBorderStyle(sWindowId, FALSE);
        CopyWindowToVram(sWindowId, COPYWIN_FULL);

        gMultiuseListMenuTemplate.windowId = sWindowId;
        sListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
        task->data[0] = 1;
        break;

    case 1:
    {
        s32 input = ListMenu_ProcessInput(sListTaskId);

        switch (input)
        {
        case LIST_NOTHING_CHOSEN:
            break;

        case LIST_CANCEL:
            DestroyListMenuTask(sListTaskId, 0, 0);
            RemoveWindow(sWindowId);
            FreeItemList();
            OnlineStore_StartCheckout();
            DestroyStore();
            ScriptContext_Enable();
            UnlockPlayerFieldControls();
            DestroyTask(taskId);
            break;

        default:
            DestroyListMenuTask(sListTaskId, 0, 0);
            RemoveWindow(sWindowId);
            FreeItemList();
            Store_QtyPrompt(sStoreItems[input].itemId);
            DestroyTask(taskId);
            break;
        }
        break;
    }
    }
}

//------------------------------------------------------------------------------
// Quantity prompt
//------------------------------------------------------------------------------

static u16 sQtyPromptItemId;

static void StoreQtyPrompt_AddToCart(u16 quantity)
{
    AddToCart(sQtyPromptItemId, quantity);
    OnlineStore_StartCheckout();
    DestroyStore();
    ScriptContext_Enable();
    UnlockPlayerFieldControls();
}

static void StoreQtyPrompt_Cancel(void)
{
    OnlineStore_StartCheckout();
    DestroyStore();
    ScriptContext_Enable();
    UnlockPlayerFieldControls();
}

// Opens a quantity selection prompt for the chosen item. The player may select
// up to the maximum number of that item that can fit in a single bag stack,
// factoring in the quantity already held and remaining bag space.
static void Store_QtyPrompt(u16 itemId)
{
    u16 owned = CountTotalItemQuantityInBag(itemId);
    u16 maxQuantity;

    sQtyPromptItemId = itemId;

    if (owned >= MAX_BAG_ITEM_CAPACITY)
        maxQuantity = 0;
    else
        maxQuantity = MAX_BAG_ITEM_CAPACITY - owned;

    while (maxQuantity > 0 && !CheckBagHasSpace(itemId, maxQuantity))
        maxQuantity--;

    if (maxQuantity == 0)
    {
        StoreQtyPrompt_Cancel();
        return;
    }

    Shop_DoQuantitySelect(maxQuantity, StoreQtyPrompt_AddToCart, StoreQtyPrompt_Cancel);
}

void OnlineStore_OpenCategory(u8 categoryId)
{
    if (!OnlineStore_IsContextBlocked())
        OnlineStore_SetCategory(categoryId);
}
