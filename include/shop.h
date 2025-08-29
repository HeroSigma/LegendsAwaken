#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

#include "config/online_store.h"

extern struct ItemSlot gMartPurchaseHistory[3];

void CreatePokemartMenu(const u16 *itemsForSale);
void CreateDecorationShop1Menu(const u16 *itemsForSale);
void CreateDecorationShop2Menu(const u16 *itemsForSale);
void CB2_ExitSellMenu(void);

// Reusable quantity selector used by marts and the online store.
void Shop_DoQuantitySelect(u16 maxQuantity, void (*onConfirm)(u16), void (*onCancel)(void));

#endif // GUARD_SHOP_H
