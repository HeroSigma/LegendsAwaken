#include "global.h"
#include "qol_scientist.h"
#include "event_data.h"
#include "pokemon.h"
#include "money.h"
#include "script.h"
#include "item.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/battle.h"

static struct Pokemon *sQolMon(void)
{
    u16 slot = VarGet(VAR_RESULT); // set by ChoosePartyMon
    if (slot >= PARTY_SIZE) slot = 0;
    return &gPlayerParty[slot];
}

/* ==================== NATURE ==================== */

void Script_QoL_SetNature(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    u16 nat = VarGet(VAR_0x8000); // 0..24
    struct Pokemon *mon = sQolMon();
    SetMonData(mon, MON_DATA_NATURE, &nat);
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

/* ==================== EVs ==================== */

static void ZeroEVs(struct Pokemon *mon)
{
    u8 z = 0;
    SetMonData(mon, MON_DATA_HP_EV, &z);
    SetMonData(mon, MON_DATA_ATK_EV, &z);
    SetMonData(mon, MON_DATA_DEF_EV, &z);
    SetMonData(mon, MON_DATA_SPEED_EV, &z);
    SetMonData(mon, MON_DATA_SPATK_EV, &z);
    SetMonData(mon, MON_DATA_SPDEF_EV, &z);
}

static void PutEV(struct Pokemon *mon, u8 stat, u8 val)
{
    if (val > 252) val = 252;
    switch (stat) {
    case STAT_HP:    SetMonData(mon, MON_DATA_HP_EV, &val); break;
    case STAT_ATK:   SetMonData(mon, MON_DATA_ATK_EV, &val); break;
    case STAT_DEF:   SetMonData(mon, MON_DATA_DEF_EV, &val); break;
    case STAT_SPEED: SetMonData(mon, MON_DATA_SPEED_EV, &val); break;
    case STAT_SPATK: SetMonData(mon, MON_DATA_SPATK_EV, &val); break;
    case STAT_SPDEF: SetMonData(mon, MON_DATA_SPDEF_EV, &val); break;
    }
}

static s8 NatureDelta(u8 nature, u8 stat); // provided by expansion; falls back below if missing
__attribute__((weak))
static s8 NatureDelta(u8 nature, u8 stat) { // +1 boosted, -1 reduced, 0 neutral
    s8 inc, dec;
    GetNatureStatMods(nature, &inc, &dec);
    if (stat == inc) return +1;
    if (stat == dec) return -1;
    return 0;
}

void Script_QoL_EVs_PresetByNature(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    struct Pokemon *mon = sQolMon();
    u8 nature = GetNature(mon);
    u8 boosted = STAT_SPEED; // default second bucket
    for (u8 s = STAT_ATK; s <= STAT_SPDEF; s++)
        if (NatureDelta(nature, s) > 0) { boosted = s; break; }

    ZeroEVs(mon);
    if (boosted == STAT_SPEED) {
        PutEV(mon, STAT_SPEED, 252);
        PutEV(mon, STAT_SPATK, 252);
    } else {
        PutEV(mon, boosted,    252);
        PutEV(mon, STAT_SPEED, 252);
    }
    PutEV(mon, STAT_HP, 6);
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

void Script_QoL_EVs_QuickCustom(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    u8 a = VarGet(VAR_0x8000); // 0..5
    u8 b = VarGet(VAR_0x8001); // 0..5
    if (a > 5) a = STAT_SPEED;
    if (b > 5 || b == a) b = STAT_SPEED;

    struct Pokemon *mon = sQolMon();
    ZeroEVs(mon);
    PutEV(mon, a, 252);
    PutEV(mon, b, 252);
    PutEV(mon, STAT_HP, 6);
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

void Script_QoL_EVs_Clear(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    struct Pokemon *mon = sQolMon();
    ZeroEVs(mon);
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

void Script_QoL_EVs_CustomFull(void)
{
    u16 e[6];
    e[0] = VarGet(VAR_0x8000);
    e[1] = VarGet(VAR_0x8001);
    e[2] = VarGet(VAR_0x8002);
    e[3] = VarGet(VAR_0x8003);
    e[4] = VarGet(VAR_0x8004);
    e[5] = VarGet(VAR_0x8005);
    for (int i=0;i<6;i++) if (e[i] > 252) e[i] = 252;
    u32 sum = e[0]+e[1]+e[2]+e[3]+e[4]+e[5];
    if (sum > 510) { VarSet(VAR_RESULT, 0); return; } // invalid, no charge

    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    struct Pokemon *mon = sQolMon();
    u8 v;
    v=e[0]; SetMonData(mon, MON_DATA_HP_EV,    &v);
    v=e[1]; SetMonData(mon, MON_DATA_ATK_EV,   &v);
    v=e[2]; SetMonData(mon, MON_DATA_DEF_EV,   &v);
    v=e[3]; SetMonData(mon, MON_DATA_SPEED_EV, &v);
    v=e[4]; SetMonData(mon, MON_DATA_SPATK_EV, &v);
    v=e[5]; SetMonData(mon, MON_DATA_SPDEF_EV, &v);
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

/* ==================== IVs ==================== */

static void SetAllIVs(struct Pokemon *mon, u8 iv)
{
    SetMonData(mon, MON_DATA_HP_IV,    &iv);
    SetMonData(mon, MON_DATA_ATK_IV,   &iv);
    SetMonData(mon, MON_DATA_DEF_IV,   &iv);
    SetMonData(mon, MON_DATA_SPEED_IV, &iv);
    SetMonData(mon, MON_DATA_SPATK_IV, &iv);
    SetMonData(mon, MON_DATA_SPDEF_IV, &iv);
}

void Script_QoL_IVs_Perfect31(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    struct Pokemon *mon = sQolMon();
    SetAllIVs(mon, 31);
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

void Script_QoL_IVs_TrickRoom(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    struct Pokemon *mon = sQolMon();
    SetAllIVs(mon, 31);
    u8 z = 0;
    SetMonData(mon, MON_DATA_SPEED_IV, &z);
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

void Script_QoL_IVs_SetStat(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }
    u8 stat = VarGet(VAR_0x8000);
    u8 iv   = VarGet(VAR_0x8001);
    if (iv > 31) iv = 31;
    struct Pokemon *mon = sQolMon();
    switch (stat) {
    case STAT_HP:    SetMonData(mon, MON_DATA_HP_IV,    &iv); break;
    case STAT_ATK:   SetMonData(mon, MON_DATA_ATK_IV,   &iv); break;
    case STAT_DEF:   SetMonData(mon, MON_DATA_DEF_IV,   &iv); break;
    case STAT_SPEED: SetMonData(mon, MON_DATA_SPEED_IV, &iv); break;
    case STAT_SPATK: SetMonData(mon, MON_DATA_SPATK_IV, &iv); break;
    case STAT_SPDEF: SetMonData(mon, MON_DATA_SPDEF_IV, &iv); break;
    }
    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}

/* ==================== Ball changer ==================== */

void Script_QoL_SetBall(void)
{
    struct Pokemon *mon = sQolMon();
    u16 item = VarGet(VAR_0x8000);
    if (!QoL_BallIsLegalForMon(item, mon)) { VarSet(VAR_RESULT, 3); return; }
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION))  { VarSet(VAR_RESULT, 2); return; }

    u8 ball = ItemIdToBallId(item); // expansion helper
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
    VarSet(VAR_RESULT, 1);
}

/* ==================== Hidden Power ==================== */

static const u8 sHpTypeOrder[16] = { // mapping index 0..15 -> TYPE_*
    TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON, TYPE_GROUND,
    TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL,
    TYPE_FIRE, TYPE_WATER, TYPE_GRASS, TYPE_ELECTRIC,
    TYPE_PSYCHIC, TYPE_ICE, TYPE_DRAGON, TYPE_DARK
};

static bool8 HiddenPowerTypeToIndex(u8 type, u8 *outIdx)
{
    for (u8 i = 0; i < 16; i++)
        if (sHpTypeOrder[i] == type) { *outIdx = i; return TRUE; }
    return FALSE;
}

void Script_QoL_SetHiddenPowerType(void)
{
    if (!QoL_TakeMoneyIfEnough(QOL_COST_PER_ACTION)) { VarSet(VAR_RESULT, 2); return; }

    struct Pokemon *mon = sQolMon();
    u8 idx;
    if (!HiddenPowerTypeToIndex(VarGet(VAR_0x8000), &idx)) { VarSet(VAR_RESULT, 0); return; }

    u8 bestS = 0;
    for (u8 S = 63; ; S--) {
        if (((S * 15) / 63) == idx) { bestS = S; break; }
        if (S == 0) break;
    }
    u8 odd[6] = {
        (bestS & 1) ? 1 : 0, (bestS & 2) ? 1 : 0, (bestS & 4) ? 1 : 0,
        (bestS & 8) ? 1 : 0, (bestS & 16)? 1 : 0, (bestS & 32)? 1 : 0,
    };
    u8 v;

    v = odd[0] ? 31 : 30; SetMonData(mon, MON_DATA_HP_IV,    &v);
    v = odd[1] ? 31 : 30; SetMonData(mon, MON_DATA_ATK_IV,   &v);
    v = odd[2] ? 31 : 30; SetMonData(mon, MON_DATA_DEF_IV,   &v);
    v = odd[3] ? 31 : 30; SetMonData(mon, MON_DATA_SPEED_IV, &v);
    v = odd[4] ? 31 : 30; SetMonData(mon, MON_DATA_SPATK_IV, &v);
    v = odd[5] ? 31 : 30; SetMonData(mon, MON_DATA_SPDEF_IV, &v);

    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}
