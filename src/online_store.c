#include "global.h"
#include "online_store.h"
#include "event_data.h"
#include "item.h"
#include "money.h"
#include "script.h"
#include "task.h"
#include "shop.h"
#include "constants/items.h"

#define CART_CAPACITY 20

struct CartItem
{
    u16 itemId;
    u16 quantity;
};

static EWRAM_DATA struct CartItem sCart[CART_CAPACITY] = {0};
static EWRAM_DATA u8 sCartCount = 0;

static void CartClear(void);
static bool32 HasEnoughMoneyForCart(void);
static void DeliverCartItems(void);
static bool32 IsItemEligible(u16 itemId);
static void Task_OnlineStore(u8 taskId);

bool8 OnlineStore_Open(void)
{
#if defined(CONFIG_ONLINE_STORE_BLOCK) && defined(FLAG_ONLINE_STORE_BLOCK)
    if (FlagGet(FLAG_ONLINE_STORE_BLOCK))
        return FALSE;
#endif

    LockPlayerFieldControls();
    CreateTask(Task_OnlineStore, 8);
    return TRUE;
}

static bool32 IsItemEligible(u16 itemId)
{
    if (GetItemPrice(itemId) == 0)
        return FALSE;
    if (GetItemImportance(itemId))
        return FALSE;
    return TRUE;
}

bool32 AddToCart(u16 itemId, u16 quantity)
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

u32 CartGetTotalCost(void)
{
    u32 total = 0;
    u8 i;
    for (i = 0; i < sCartCount; i++)
        total += GetItemPrice(sCart[i].itemId) * sCart[i].quantity;
    return total;
}

bool32 CartWillFitInBag(void)
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

void OnlineStore_StartCheckout(void)
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

static void Task_OnlineStore(u8 taskId)
{
    OnlineStore_StartCheckout();
    ScriptContext_Enable();
    UnlockPlayerFieldControls();
    DestroyTask(taskId);
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

static void FreeStoreItems(void)
{
    if (sStoreItems != NULL)
    {
        Free(sStoreItems);
        sStoreItems = NULL;
    }
    sStoreItemCount = 0;
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
            sStoreItems[sStoreItemCount].price = gItemsInfo[i].price;
            CopyItemName(i, sStoreItems[sStoreItemCount].name);
            sStoreItemCount++;
        }
    }

    if (sStoreItemCount > 1)
        qsort(sStoreItems, sStoreItemCount, sizeof(*sStoreItems), CompareItemsByName);
}

void OnlineStore_SetCategory(u8 category)
{
    if (category >= gOnlineStoreCategoryCount)
        category = 0;
    sCurrentCategory = category;
    BuildItemList();
}

//------------------------------------------------------------------------------
// Task handling
//------------------------------------------------------------------------------

// Task for selecting a category. In a full implementation this would handle
// input from the player. Here it simply rebuilds the item list for the
// category stored in gTasks[taskId].data[0].
void StoreTask_SelectCategory(u8 taskId)
{
    u8 category = gTasks[taskId].data[0];
    OnlineStore_SetCategory(category);
    gTasks[taskId].func = StoreTask_BrowseCategory;
}

// Task for browsing items within a category. This is a stub for the purposes
// of this repository; a full implementation would present the list to the
// player and allow purchases. The task currently performs no additional work.
void StoreTask_BrowseCategory(u8 taskId)
{
    // Placeholder implementation.
    (void)taskId;
}

//------------------------------------------------------------------------------
// Quantity prompt
//------------------------------------------------------------------------------

static u16 sQtyPromptItemId;

static void StoreQtyPrompt_AddToCart(u16 quantity)
{
    AddToCart(sQtyPromptItemId, quantity);
}

static void StoreQtyPrompt_Cancel(void)
{
    // Currently no additional behaviour on cancel.
}

// Opens a quantity selection prompt for the chosen item. The player may select
// up to the maximum number of that item that can fit in a single bag stack,
// factoring in the quantity already held and remaining bag space.
void Store_QtyPrompt(u16 itemId)
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