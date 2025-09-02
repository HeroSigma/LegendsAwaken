#pragma once
#include "global.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "global_preset_party.h"

#if B_GLOBAL_PRESET_TEAMS

#define ROLEBIT(r) (1u << (r))
#define TAGBIT(t)  (1u << (t))
#define CLASSMASK_ANY 0xFFFFFFFFu

extern const struct PresetSet gSpeciesPresets[];
extern const u16 gSpeciesPresetsCount;

#endif // B_GLOBAL_PRESET_TEAMS
