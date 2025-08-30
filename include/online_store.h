#ifndef GUARD_ONLINE_STORE_H
#define GUARD_ONLINE_STORE_H

#include "global.h"

struct OnlineStoreCategory
{
    const u8 *name;
    bool8 (*filter)(u16 itemId);
};

extern const struct OnlineStoreCategory gOnlineStoreCategories[];
extern const u8 gOnlineStoreCategoryCount;

enum
{
    ONLINE_STORE_CATEGORY_BALLS,
    ONLINE_STORE_CATEGORY_MEDICINE,
    ONLINE_STORE_CATEGORY_TMTR,
    ONLINE_STORE_CATEGORY_COUNT,
};

// Opens the online store with the given inventory. If inventory is NULL the
// default inventory is used.
bool8 OnlineStore_Open(const u16 *inventory);

// Opens the specified store category if the context allows it.
void OnlineStore_OpenCategory(u8 categoryId);

// Returns the unit price for an item, including any surcharge.
u16 OnlineStore_GetUnitPrice(u16 itemId);

// Returns TRUE if the online store cannot be opened in the current context.
bool8 OnlineStore_IsContextBlocked(void);

// Sets a surcharge (in yen) that is added to the price of all items.
void OnlineStore_SetSurcharge(u16 yen);

bool32 AddToCart(u16 itemId, u16 quantity);
u32 CartGetTotalCost(void);
bool32 CartWillFitInBag(void);
void OnlineStore_StartCheckout(void);
void Store_QtyPrompt(u16 itemId);
void OnlineStore_SetCategory(u8 category);

#endif // GUARD_ONLINE_STORE_H
