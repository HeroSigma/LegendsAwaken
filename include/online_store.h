#ifndef GUARD_ONLINE_STORE_H
#define GUARD_ONLINE_STORE_H

#include "global.h"

// Opens the online store interface. The optional `inventory` parameter is
// currently unused and should be passed as NULL.
bool8 OnlineStore_Open(const u16 *inventory);

// Returns TRUE if the current game context blocks access to the store.
bool8 OnlineStore_IsContextBlocked(void);

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
