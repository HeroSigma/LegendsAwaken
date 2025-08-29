#ifndef GUARD_ONLINE_STORE_H
#define GUARD_ONLINE_STORE_H

void OnlineStore_Open(const u16 *inventory);
void OnlineStore_OpenCategory(u8 categoryId);
u16 OnlineStore_GetUnitPrice(u16 itemId);
bool8 OnlineStore_IsContextBlocked(void);
void OnlineStore_SetSurcharge(u16 yen);

#endif // GUARD_ONLINE_STORE_H