#ifndef GUARD_ONLINE_STORE_H
#define GUARD_ONLINE_STORE_H

#include "global.h"

// Opens the online store interface.
bool8 OnlineStore_Open(void);

// Returns TRUE if the current game context blocks access to the store.
bool8 OnlineStore_IsContextBlocked(void);

// Gets the price for an item after applying the current surcharge.
u16 OnlineStore_GetUnitPrice(u16 itemId);

// Sets a surcharge to apply to all store prices.
void OnlineStore_SetSurcharge(u16 yen);

// Represents a category of items that can be shown in the store. Each
// category has a display name and an optional filter function which
// determines if an item belongs to that category.
struct OnlineStoreCategory {
    const u8 *name;
    bool8 (*filter)(u16 itemId);
};

// List of all categories available in the store.
extern const struct OnlineStoreCategory gOnlineStoreCategories[];
extern const u8 gOnlineStoreCategoryCount;

#endif // GUARD_ONLINE_STORE_H
