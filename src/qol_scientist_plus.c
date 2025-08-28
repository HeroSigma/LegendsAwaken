#include "global.h"
#include "qol_scientist.h"
#include "event_data.h"
#include "money.h"
#include "overworld.h"
#include "pokemon.h"
#include "script.h"
#include "task.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "input.h"
#include "string_util.h"
#include "strings.h"
#include "item.h"
#include "constants/items.h"
#include "constants/species.h"
#include "constants/region_map_sections.h"

// ---------- Region detection (adjust MAPSEC ranges to your project) ----------
static u8 RegionFromMapsec(u16 mapsec)
{
    switch (mapsec) {
    case MAPSEC_PALLET_TOWN ... MAPSEC_SEAFOAM_ISLANDS: return QOL_REGION_KANTO;
    case MAPSEC_NEW_BARK_TOWN ... MAPSEC_MOUNT_SILVER:  return QOL_REGION_JOHTO;
    case MAPSEC_KINDLE_ROAD  ... MAPSEC_TANOBY_CHAMBERS:return QOL_REGION_SEVII;
    case MAPSEC_TWINLEAF_TOWN... MAPSEC_SPEAR_PILLAR:   return QOL_REGION_SINNOH;
    default: return QOL_REGION_HOENN;
    }
}
u8 QoL_GetCurrentRegionId(void) { return RegionFromMapsec(gMapHeader.regionMapSectionId); }

// ---------- Money ----------
bool8 QoL_TakeMoneyIfEnough(u32 cost)
{
    if (GetMoney(&gSaveBlock1Ptr->money) < cost) return FALSE;
    RemoveMoney(&gSaveBlock1Ptr->money, cost);
    return TRUE;
}

// ---------- Mon checks ----------
bool8 QoL_IsMonShiny(struct Pokemon *mon) { return GetMonData(mon, MON_DATA_IS_SHINY, NULL); }

__attribute__((weak)) bool8 IsLegendarySpecies(u16 species) { return FALSE; }
__attribute__((weak)) bool8 IsMythicalSpecies(u16 species) { return FALSE; }
__attribute__((weak)) bool8 IsUltraBeastSpecies(u16 species){ return FALSE; }

bool8 QoL_IsMonLegendaryOrMythical(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    return IsLegendarySpecies(species) || IsMythicalSpecies(species);
}
bool8 QoL_IsMonUltraBeast(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    return IsUltraBeastSpecies(species);
}

// ---------- Ball legality ----------
static bool8 ItemIsBall_(u16 item)
{
    return ItemId_GetPocket(item) == POCKET_ITEMS && GetItemEffectType(item) == ITEM_EFFECT_POKE_BALL;
}

bool8 QoL_BallIsLegalForMon(u16 item, struct Pokemon *mon)
{
    if (!ItemIsBall_(item)) return FALSE;
    if (GetMonData(mon, MON_DATA_IS_EGG, NULL)) return FALSE;

    if (item == ITEM_CHERISH_BALL)
        if (!QoL_IsMonShiny(mon) && !QoL_IsMonLegendaryOrMythical(mon))
            return FALSE;

    if (item == ITEM_BEAST_BALL)
        if (!QoL_IsMonUltraBeast(mon))
            return FALSE;

    return TRUE;
}

// ---------- Region strings (externs) ----------
extern const u8 gText_QoLHello_Hoenn[],  gText_QoLHello_Johto[],  gText_QoLHello_Kanto[],  gText_QoLHello_Sevii[],  gText_QoLHello_Sinnoh[];
extern const u8 gText_QoL_NotEnoughMoney_Hoenn[], gText_QoL_NotEnoughMoney_Johto[], gText_QoL_NotEnoughMoney_Kanto[], gText_QoL_NotEnoughMoney_Sevii[], gText_QoL_NotEnoughMoney_Sinnoh[];
extern const u8 gText_QoL_IllegalBall_Hoenn[],  gText_QoL_IllegalBall_Johto[],  gText_QoL_IllegalBall_Kanto[],  gText_QoL_IllegalBall_Sevii[],  gText_QoL_IllegalBall_Sinnoh[];
extern const u8 gText_QoL_Charged_Hoenn[], gText_QoL_Charged_Johto[], gText_QoL_Charged_Kanto[], gText_QoL_Charged_Sevii[], gText_QoL_Charged_Sinnoh[];
extern const u8 gText_QoL_Canceled_Hoenn[], gText_QoL_Canceled_Johto[], gText_QoL_Canceled_Kanto[], gText_QoL_Canceled_Sevii[], gText_QoL_Canceled_Sinnoh[];

static const u8 *Sel(const u8 *const tbl[5])
{
    static u8 r; r = QoL_GetCurrentRegionId();
    return tbl[r];
}

static void CopyRegional(const u8 *const tbl[5])
{
    StringCopy(gStringVar4, Sel(tbl));
}

void Script_QoL_Msg_Hello(void) {
    static const u8 *const t[5] = {gText_QoLHello_Hoenn,gText_QoLHello_Johto,gText_QoLHello_Kanto,gText_QoLHello_Sevii,gText_QoLHello_Sinnoh};
    CopyRegional(t);
}
void Script_QoL_Msg_NotEnoughMoney(void) {
    static const u8 *const t[5] = {gText_QoL_NotEnoughMoney_Hoenn,gText_QoL_NotEnoughMoney_Johto,gText_QoL_NotEnoughMoney_Kanto,gText_QoL_NotEnoughMoney_Sevii,gText_QoL_NotEnoughMoney_Sinnoh};
    CopyRegional(t);
}
void Script_QoL_Msg_IllegalBall(void) {
    static const u8 *const t[5] = {gText_QoL_IllegalBall_Hoenn,gText_QoL_IllegalBall_Johto,gText_QoL_IllegalBall_Kanto,gText_QoL_IllegalBall_Sevii,gText_QoL_IllegalBall_Sinnoh};
    CopyRegional(t);
}
void Script_QoL_Msg_Charged(void) {
    static const u8 *const t[5] = {gText_QoL_Charged_Hoenn,gText_QoL_Charged_Johto,gText_QoL_Charged_Kanto,gText_QoL_Charged_Sevii,gText_QoL_Charged_Sinnoh};
    CopyRegional(t);
}
void Script_QoL_Msg_Canceled(void) {
    static const u8 *const t[5] = {gText_QoL_Canceled_Hoenn,gText_QoL_Canceled_Johto,gText_QoL_Canceled_Kanto,gText_QoL_Canceled_Sevii,gText_QoL_Canceled_Sinnoh};
    CopyRegional(t);
}

// ---------- Numeric Input UI ----------
enum {
    QT_WIN=0, QT_VAL, QT_MIN, QT_MAX, QT_CANCEL
};

static const struct WindowTemplate sNumWinTemplate = {
    .bg=0, .tilemapLeft=10, .tilemapTop=7, .width=10, .height=4, .paletteNum=15, .baseBlock=0x1
};

static void PrintNumber(u8 windowId, u16 val, const u8 *label)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    DrawStdWindowFrame(windowId, FALSE);
    if (label) AddTextPrinterParameterized(windowId, 1, label, 8, 4, 0, NULL);
    ConvertIntToDecimalStringN(gStringVar1, val, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized(windowId, 1, gStringVar1, 8, 20, 0, NULL);
    CopyWindowToVram(windowId, 2);
}

static void Task_QoL_NumberInput(u8 taskId)
{
    u16 *d = gTasks[taskId].data;
    u8 win = d[QT_WIN];

    if (JOY_NEW(B_BUTTON)) {
        d[QT_CANCEL] = TRUE;
        ClearStdWindowAndFrameToTransparent(win, TRUE);
        RemoveWindow(win);
        ScriptContext_Enable();
        DestroyTask(taskId);
        return;
    }
    if (JOY_NEW(A_BUTTON)) {
        VarSet(VAR_RESULT, d[QT_VAL]);
        ClearStdWindowAndFrameToTransparent(win, TRUE);
        RemoveWindow(win);
        ScriptContext_Enable();
        DestroyTask(taskId);
        return;
    }
    if (JOY_REPEAT(DPAD_RIGHT) && d[QT_VAL] < d[QT_MAX]) d[QT_VAL]++;
    if (JOY_REPEAT(DPAD_LEFT)  && d[QT_VAL] > d[QT_MIN]) d[QT_VAL]--;
    if (JOY_REPEAT(DPAD_UP))   d[QT_VAL] = (d[QT_VAL] + 10 <= d[QT_MAX]) ? d[QT_VAL] + 10 : d[QT_MAX];
    if (JOY_REPEAT(DPAD_DOWN)) d[QT_VAL] = (d[QT_VAL] >= d[QT_MIN] + 10) ? d[QT_VAL] - 10 : d[QT_MIN];

    PrintNumber(win, d[QT_VAL], gText_ThreeHyphens); // any small label; replace if desired
}

void Script_QoL_PromptNumber(void)
{
    u16 min  = VarGet(VAR_0x8000);
    u16 max  = VarGet(VAR_0x8001);
    u16 init = VarGet(VAR_0x8002);
    if (init < min) init = min;
    if (init > max) init = max;

    ScriptContext_Stop();
    u8 win = AddWindow(&sNumWinTemplate);
    DrawStdWindowFrame(win, FALSE);
    PrintNumber(win, init, gText_EmptyString2);

    u8 taskId = CreateTask(Task_QoL_NumberInput, 0);
    u16 *d = gTasks[taskId].data;
    d[QT_WIN]   = win;
    d[QT_VAL]   = init;
    d[QT_MIN]   = min;
    d[QT_MAX]   = max;
    d[QT_CANCEL]= FALSE;
}
