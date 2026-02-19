#ifndef GUARD_WILD_POOLS_H
#define GUARD_WILD_POOLS_H

#include "constants/species.h"

#define MAX_EVO_STAGES 4

typedef struct {
    u16 species[MAX_EVO_STAGES];        // SPECIES_NONE terminates
    u8  min_level[MAX_EVO_STAGES];      // min level for this stage
    u8  min_badges[MAX_EVO_STAGES];     // min badges required for this stage
    u16 weight;                         // relative spawn chance
    u8  time_bias;                      // 0 = any, 1 = day/morning bias, 2 = night/evening bias
} EvolutionLine;

// Pool theme types (assign per map/area)
enum WildPoolType {
    POOL_GRASS,      // Open fields (normal/early mix)
    POOL_FOREST,     // Bug/forest heavy
    POOL_VOLCANO,    // Fire/rock/ground
    POOL_WETLAND,    // Poison/water/bug
    POOL_MOUNTAIN,   // Rock/fighting/ground
    POOL_CAVE,       // Bats/rock
    POOL_WATER,      // Surf encounters
    POOL_POWERPLANT, // Electric/steel areas
    POOL_OLD_ROD,
    POOL_GOOD_ROD,
    POOL_SUPER_ROD,
    POOL_SNOW,       // Ice/snow areas
    POOL_GRAVEYARD, // Ghost/dark/cryptic
    POOL_TANOBY_RUINS, // Unown-only ruins
    POOL_RUINS_OF_ALPH, // Ancient fossil ruins (Johto)
    POOL_SOLACEON_RUINS, // Ancient fossil ruins (Sinnoh)
    NUM_WILD_POOLS
};

// Pool arrays and counts indexed by WildPoolType
extern const EvolutionLine *const gWildPools[NUM_WILD_POOLS];
extern const u32 gWildPoolCounts[NUM_WILD_POOLS];

// Functions
u16 GetWildSpeciesFromPool(enum WildPoolType poolType, u8 level, u8 badgeCount);

#endif // GUARD_WILD_POOLS_H
