#ifndef GUARD_ONLINE_STORE_H
#define GUARD_ONLINE_STORE_H

#include "global.h"
#include "online_store.h"
#include "config/online_store.h"
#include "event_data.h"
#include "item.h"
#include "money.h"
#include "script.h"
#include "task.h"

#define CART_CAPACITY 20

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

bool8 OnlineStore_Open(const u16 *inventory)
{
    if (!OnlineStore_IsContextBlocked())
    {
        OnlineStore_SetInventory(inventory);
        return TRUE;
    }
    return FALSE;
}

void OnlineStore_OpenCategory(u8 categoryId)
{
    if (!OnlineStore_IsContextBlocked())
    {
        OnlineStore_SetCategory(categoryId);
    }
}

u16 OnlineStore_GetUnitPrice(u16 itemId)
{
    if (!OnlineStore_IsContextBlocked())
    {
        return GetItemPrice(itemId) + sSurcharge;
    }
    return 0;
}

bool8 OnlineStore_IsContextBlocked(void)
{
    return FALSE;
}

void OnlineStore_SetSurcharge(u16 yen)
{
    sSurcharge = yen;
}

bool8 OnlineStore_Open(void);
bool32 AddToCart(u16 itemId, u16 quantity);
u32 CartGetTotalCost(void);
bool32 CartWillFitInBag(void);
void OnlineStore_StartCheckout(void);
void Store_QtyPrompt(u16 itemId);

#endif // GUARD_ONLINE_STORE_H
