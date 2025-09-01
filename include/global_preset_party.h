#pragma once
#include "global.h"
#include "constants/pokemon.h"

// Forward declarations
struct TrainerMon;

#if B_GLOBAL_PRESET_TEAMS

enum CompetitiveRole { 
    ROLE_LEAD, 
    ROLE_BREAKER, 
    ROLE_PIVOT, 
    ROLE_WALL, 
    ROLE_SPEED_CTRL, 
    ROLE_SETUP, 
    ROLE_WEATHER_SETTER, 
    ROLE_WEATHER_ABUSER, 
    ROLE_ACE, 
    ROLE_COUNT 
};

typedef u32 RoleMask; // bit per ROLE_*

typedef u32 ClassMask; // bit per trainer class bucket if you add one; use 0xFFFFFFFF for any

enum PresetTag { 
    PTAG_NONE=0, 
    PTAG_WEATHER_SAND_SETTER, 
    PTAG_WEATHER_SAND_ABUSER, 
    PTAG_WEATHER_RAIN_SETTER, 
    PTAG_WEATHER_RAIN_ABUSER, 
    PTAG_TR_SETTER, 
    PTAG_TR_ABUSER, 
    PTAG_HAZARD_SETTER, 
    PTAG_HAZARD_REMOVAL, 
    PTAG_PIVOT_TAG 
};

typedef u32 TagMask;

struct PresetSet {
    u16 species; 
    u16 form; 
    u8 levelMin, levelMax; 
    RoleMask roleMask; 
    u8 nature; 
    u8 evs[NUM_STATS]; 
    u8 ivs[NUM_STATS]; 
    u16 item; 
    u8 abilityPref[3]; 
    u16 moves[4]; 
    ClassMask classMask; 
    TagMask tagMask;
};

struct ClassConstraint { 
    bool8 doubles; 
    u8 teamSize; 
    u8 allowedTypesMask[2]; 
    u16 bannedSpeciesCount; 
    const u16 *bannedSpecies; 
    bool8 speciesClause; 
    bool8 formsAsSame; 
    bool8 itemClause; 
};

struct ClassProfile { 
    bool8 doubles; 
    u8 roles[6]; 
};

// Function declarations
void GeneratePresetTeam(u16 trainerId, struct TrainerMon *outParty, u8 outCount);
bool8 UsePresetBuilderForTrainer(u8 trainerClass);

#endif // B_GLOBAL_PRESET_TEAMS
