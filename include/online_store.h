#ifndef GUARD_ONLINE_STORE_H
#define GUARD_ONLINE_STORE_H

// Interface for the optional Online Store feature.
//
// The real implementation lives in src/online_store.c and is only compiled
// when ONLINE_STORE_ENABLED is set.  In builds where the feature is disabled
// we provide lightweight stub versions so that other modules can call the
// functions without having to sprinkle feature checks everywhere.

#include "global.h"
#include "config/online_store.h"

#if ONLINE_STORE_ENABLED

// Launch the store with the provided inventory.  Returns TRUE if the store
// opened successfully.
bool8 OnlineStore_Open(const u16 *inventory);

// Open a specific category of the store.  Returns TRUE on success.
bool8 OnlineStore_OpenCategory(u8 categoryId);

// Determines whether the current game context allows store access.
bool8 OnlineStore_IsContextBlocked(void);

// Apply a price surcharge to all items in the store.
void OnlineStore_SetSurcharge(s16 yen);

#else  // ONLINE_STORE_ENABLED

// Stub implementations used when the Online Store feature is disabled.
static inline bool8 OnlineStore_Open(const u16 *inventory)
{
    (void)inventory;
    return FALSE;
}

static inline bool8 OnlineStore_OpenCategory(u8 categoryId)
{
    (void)categoryId;
    return FALSE;
}

static inline bool8 OnlineStore_IsContextBlocked(void)
{
    // If the feature is compiled out we consider the context blocked so the
    // caller will not attempt to open the store.
    return TRUE;
}

static inline void OnlineStore_SetSurcharge(s16 yen)
{
    (void)yen;
}

#endif // ONLINE_STORE_ENABLED

#endif // GUARD_ONLINE_STORE_H

