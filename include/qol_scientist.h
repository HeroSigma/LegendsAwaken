#pragma once
#include "global.h"
#include "pokemon.h"

#define QOL_COST_PER_ACTION 1000  // ₽1000 per successful edit

enum QoLRegionId {
    QOL_REGION_HOENN  = 0,
    QOL_REGION_JOHTO  = 1,
    QOL_REGION_KANTO  = 2,
    QOL_REGION_SEVII  = 3,
    QOL_REGION_SINNOH = 4,
};

u8  QoL_GetCurrentRegionId(void);
bool8 QoL_TakeMoneyIfEnough(u32 cost);
bool8 QoL_IsMonShiny(struct Pokemon *mon);
bool8 QoL_IsMonLegendaryOrMythical(struct Pokemon *mon);
bool8 QoL_IsMonUltraBeast(struct Pokemon *mon);
bool8 QoL_BallIsLegalForMon(u16 item, struct Pokemon *mon);

// Numeric input spinner: 0x8000=min, 0x8001=max, 0x8002=initial; returns VAR_RESULT
void Script_QoL_PromptNumber(void);

// Region-aware message fillers -> copy regional text into gStringVar4
void Script_QoL_Msg_Hello(void);
void Script_QoL_Msg_NotEnoughMoney(void);
void Script_QoL_Msg_IllegalBall(void);
void Script_QoL_Msg_Charged(void);
void Script_QoL_Msg_Canceled(void);

// Service callnatives (set VAR_RESULT = 1 success, 2 not enough money, 3 illegal)
void Script_QoL_SetNature(void);             // VAR_0x8000 = nature 0..24; uses chosen party mon (VAR_RESULT from ChoosePartyMon)
void Script_QoL_EVs_PresetByNature(void);
void Script_QoL_EVs_QuickCustom(void);       // VAR_0x8000=a stat (0..5), VAR_0x8001=b stat (0..5)
void Script_QoL_EVs_Clear(void);
void Script_QoL_EVs_CustomFull(void);        // VAR_0x8000..0x8005 = HP,ATK,DEF,SPE,SPA,SPD (0..252 each, total ≤510)

void Script_QoL_IVs_Perfect31(void);
void Script_QoL_IVs_TrickRoom(void);
void Script_QoL_IVs_SetStat(void);           // VAR_0x8000 = stat (0..5), VAR_0x8001 = iv (0..31)

void Script_QoL_SetBall(void);               // VAR_0x8000 = itemId (ITEM_* Ball)
void Script_QoL_SetHiddenPowerType(void);    // VAR_0x8000 = TYPE_FIGHTING..TYPE_DARK indexable HP type
