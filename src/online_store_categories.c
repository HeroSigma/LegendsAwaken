#include "global.h"
#include "item.h"
#include "online_store.h"
#include "config/online_store.h"

static const u8 sCategoryName_Items[]    = _("Items");
static const u8 sCategoryName_Medicine[] = _("Medicine");
static const u8 sCategoryName_Battle[]   = _("Battle Items");
static const u8 sCategoryName_Balls[]    = _("Poke Balls");
static const u8 sCategoryName_TMHM[]     = _("TMs/TRs");
static const u8 sCategoryName_Berries[]  = _("Berries");
static const u8 sCategoryName_KeyItems[] = _("Key Items");

static bool8 IsItem(u16 itemId)     { return gItemsInfo[itemId].pocket == POCKET_ITEMS; }
static bool8 IsMedicine(u16 itemId) { return gItemsInfo[itemId].pocket == POCKET_MEDICINE; }
static bool8 IsBattle(u16 itemId)   { return gItemsInfo[itemId].pocket == POCKET_BATTLE_ITEMS; }
static bool8 IsBall(u16 itemId)     { return gItemsInfo[itemId].pocket == POCKET_POKE_BALLS; }
static bool8 IsTMHM(u16 itemId)     { return gItemsInfo[itemId].pocket == POCKET_TM_HM; }
static bool8 IsBerry(u16 itemId)    { return gItemsInfo[itemId].pocket == POCKET_BERRIES; }
static bool8 IsKeyItem(u16 itemId)  { return gItemsInfo[itemId].pocket == POCKET_KEY_ITEMS; }

const struct OnlineStoreCategory gOnlineStoreCategories[] =
{
#if ONLINE_STORE_CATEGORY_ITEMS
    { sCategoryName_Items,    IsItem },
#endif
#if ONLINE_STORE_CATEGORY_MEDICINE
    { sCategoryName_Medicine, IsMedicine },
#endif
#if ONLINE_STORE_CATEGORY_BATTLE_ITEMS
    { sCategoryName_Battle,   IsBattle },
#endif
#if ONLINE_STORE_CATEGORY_BALLS
    { sCategoryName_Balls,    IsBall },
#endif
#if ONLINE_STORE_CATEGORY_TMHM
    { sCategoryName_TMHM,     IsTMHM },
#endif
#if ONLINE_STORE_CATEGORY_BERRIES
    { sCategoryName_Berries,  IsBerry },
#endif
#if ONLINE_STORE_CATEGORY_KEY_ITEMS
    { sCategoryName_KeyItems, IsKeyItem },
#endif
};

const u8 gOnlineStoreCategoryCount = ARRAY_COUNT(gOnlineStoreCategories);
