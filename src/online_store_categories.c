#include "global.h"
#include "item.h"
#include "online_store.h"
#include "string_util.h"
#include "data.h"
#include "constants/pokemon.h"

extern const struct TypeInfo gTypesInfo[NUMBER_OF_MON_TYPES];

static const u8 sCategoryName_Balls[] = _("Poke Balls");
static const u8 sCategoryName_Medicine[] = _("Medicine");
static const u8 sCategoryName_TMTR[] = _("TMs/TRs");

static bool8 IsBall(u16 itemId)
{
    return gItemsInfo[itemId].pocket == POCKET_POKE_BALLS;
}

static bool8 IsMedicine(u16 itemId)
{
    return gItemsInfo[itemId].pocket == POCKET_MEDICINE;
}

static bool8 IsTMTR(u16 itemId)
{
    return gItemsInfo[itemId].pocket == POCKET_TM_HM;
}

const struct OnlineStoreCategory gOnlineStoreCategories[] =
{
    [ONLINE_STORE_CATEGORY_BALLS] = { sCategoryName_Balls,    IsBall },
    [ONLINE_STORE_CATEGORY_MEDICINE] = { sCategoryName_Medicine, IsMedicine },
    [ONLINE_STORE_CATEGORY_TMTR] = { sCategoryName_TMTR,     IsTMTR },
};

const u8 gOnlineStoreCategoryCount = ARRAY_COUNT(gOnlineStoreCategories);
