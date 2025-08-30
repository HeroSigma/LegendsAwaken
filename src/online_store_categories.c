#include "global.h"
#include "item.h"
#include "online_store.h"
#include "string_util.h"
#include "data.h"
#include "constants/pokemon.h"

extern const struct TypeInfo gTypesInfo[NUMBER_OF_MON_TYPES];

static const u8 sCategoryName_Balls[] = _("Pok\xE9 Balls");
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

static bool8 IsTypeFormItem(u16 itemId)
{
    const u8 *name = ItemId_GetName(itemId);
    u8 i;

    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (StringContains(name, gTypesInfo[i].name))
            return TRUE;
    }

    return FALSE;
}

const struct OnlineStoreCategory gOnlineStoreCategories[] =
{
    [ONLINE_STORE_CATEGORY_BALLS] = { sCategoryName_Balls,    IsBall },
    [ONLINE_STORE_CATEGORY_MEDICINE] = { sCategoryName_Medicine, IsMedicine },
    [ONLINE_STORE_CATEGORY_TMTR] = { sCategoryName_TMTR,     IsTMTR },
};

const u8 gOnlineStoreCategoryCount = ARRAY_COUNT(gOnlineStoreCategories);
