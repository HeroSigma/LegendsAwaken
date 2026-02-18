#ifndef GUARD_TRAINER_POOLS_H
#define GUARD_TRAINER_POOLS_H

#include "constants/species.h"
#include "constants/pokemon.h"
#include "data.h"

#define MAX_EVO_STAGES          4
#define MAX_TRAINER_MON_LINES   64   // increase if you want more than 40 per class

// ─────────────────────────────────────────────────────────────
// TRAINER POOL CATEGORIES
// ─────────────────────────────────────────────────────────────
enum TrainerPoolCategory {
    POOL_CATEGORY_GENERIC,      // uses class pool (Youngster, Bug Catcher, etc.)
    POOL_CATEGORY_GYM_LEADER,   // custom per gym type
    POOL_CATEGORY_RIVAL,
    POOL_CATEGORY_ELITE_FOUR,
    POOL_CATEGORY_CHAMPION,
    POOL_CATEGORY_VILLAIN_ADMIN,
    POOL_CATEGORY_VILLAIN_LEADER,
    POOL_CATEGORY_FINAL_BOSS,   // your Dad
    POOL_CATEGORY_STATIC        // completely static (no pool, old data)
};

typedef struct {
    u16 species[MAX_EVO_STAGES];        // SPECIES_NONE terminates
    u8  min_level[MAX_EVO_STAGES];
    u8  min_badges[MAX_EVO_STAGES];
    u16 weight;
    u8  preferred_nature;
    u8  ev_spread[6];                   // HP / Atk / Def / SpA / SpD / Spe
} TrainerMonLine;

// Declare all pools (add one line per class you have)
extern const TrainerMonLine gYoungsterPool[];
extern const TrainerMonLine gLassPool[];
extern const TrainerMonLine gBugCatcherPool[];
extern const TrainerMonLine gHikerPool[];
extern const TrainerMonLine gFishermanPool[];
extern const TrainerMonLine gSwimmerMPool[];
extern const TrainerMonLine gSwimmerFPool[];
extern const TrainerMonLine gPicnickerPool[];
extern const TrainerMonLine gCamperPool[];
extern const TrainerMonLine gBlackBeltPool[];
extern const TrainerMonLine gCooltrainerPool[];
extern const TrainerMonLine gPsychicPool[];
extern const TrainerMonLine gGentlemanPool[];
extern const TrainerMonLine gBeautyPool[];
extern const TrainerMonLine gLadyPool[];
extern const TrainerMonLine gPokefanPool[];
extern const TrainerMonLine gNinjaBoyPool[];
extern const TrainerMonLine gParasolLadyPool[];
extern const TrainerMonLine gAromaLadyPool[];
extern const TrainerMonLine gDragonTamerPool[];
extern const TrainerMonLine gTriathletePool[];

// Villain teams (static)
extern const TrainerMonLine gTeamRocketPool[];
extern const TrainerMonLine gTeamAquaPool[];
extern const TrainerMonLine gTeamMagmaPool[];
extern const TrainerMonLine gTeamGalacticPool[];
extern const TrainerMonLine gTeamPlasmaPool[];
extern const TrainerMonLine gTeamFlarePool[];
extern const TrainerMonLine gTeamSkullPool[];
extern const TrainerMonLine gAetherPool[];
extern const TrainerMonLine gTeamYellMacroPool[];
extern const TrainerMonLine gTeamStarPool[];

// Special role pools (Gym Leaders, Rival, Elite Four, Champion, Villain Leaders)
extern const TrainerMonLine gRockGymPool[];
extern const TrainerMonLine gWaterGymPool[];
extern const TrainerMonLine gFireGymPool[];
extern const TrainerMonLine gGrassGymPool[];
extern const TrainerMonLine gElectricGymPool[];
extern const TrainerMonLine gPsychicGymPool[];
extern const TrainerMonLine gIceGymPool[];
extern const TrainerMonLine gDragonGymPool[];
extern const TrainerMonLine gDarkGymPool[];
extern const TrainerMonLine gFairyGymPool[];
extern const TrainerMonLine gFightingGymPool[];
extern const TrainerMonLine gPoisonGymPool[];
extern const TrainerMonLine gGroundGymPool[];
extern const TrainerMonLine gFlyingGymPool[];
extern const TrainerMonLine gNormalGymPool[];
extern const TrainerMonLine gSteelGymPool[];
extern const TrainerMonLine gBugGymPool[];

extern const TrainerMonLine gRivalPool[];
extern const TrainerMonLine gEliteFourSidneyPool[];
extern const TrainerMonLine gEliteFourPhoebePool[];
extern const TrainerMonLine gEliteFourGlaciaPool[];
extern const TrainerMonLine gEliteFourDrakePool[];
extern const TrainerMonLine gChampionPool[];
extern const TrainerMonLine gTeamAquaLeaderPool[];
extern const TrainerMonLine gTeamMagmaLeaderPool[];
extern const TrainerMonLine gYourDadPool[];

// Hoenn Gym Leader Pools
extern const TrainerMonLine gRoxannePool[];
extern const TrainerMonLine gBrawlyPool[];
extern const TrainerMonLine gWatsonPool[];
extern const TrainerMonLine gFlanneryPool[];
extern const TrainerMonLine gNormanPool[];
extern const TrainerMonLine gWinonaPool[];
extern const TrainerMonLine gTateLizaPool[];
extern const TrainerMonLine gJuanPool[];

// Hoenn Champion Pools
extern const TrainerMonLine gWallacePool[];     // Ruby/Sapphire Champion
extern const TrainerMonLine gStevenPool[];      // Emerald Champion

// Johto Gym Leader Pools
extern const TrainerMonLine gFalknerPool[];
extern const TrainerMonLine gBugsyPool[];
extern const TrainerMonLine gWhitneyPool[];
extern const TrainerMonLine gMortyPool[];
extern const TrainerMonLine gChuckPool[];
extern const TrainerMonLine gJasminePool[];
extern const TrainerMonLine gPrycePool[];
extern const TrainerMonLine gClairPool[];

// Kanto Gym Leader Pools
extern const TrainerMonLine gBrockPool[];
extern const TrainerMonLine gMistyPool[];
extern const TrainerMonLine gLtSurgePool[];
extern const TrainerMonLine gErikaPool[];
extern const TrainerMonLine gJanineKogaPool[];
extern const TrainerMonLine gSabrinaPool[];
extern const TrainerMonLine gBlainePool[];
extern const TrainerMonLine gBlueGymLeaderPool[];

// Rival & Champion Pools
extern const TrainerMonLine gBlueRivalPool[];
extern const TrainerMonLine gBlueChampionPool[];
extern const TrainerMonLine gRedRivalPool[];
extern const TrainerMonLine gRedChampionPool[];

// Kanto Elite Four Pools
extern const TrainerMonLine gLoreleiPool[];
extern const TrainerMonLine gBrunoPool[];
extern const TrainerMonLine gAgathaPool[];
extern const TrainerMonLine gLancePool[];

// Johto Elite Four Pools
extern const TrainerMonLine gWillPool[];
extern const TrainerMonLine gKogaPool[];
extern const TrainerMonLine gBrunoJohtoPool[];
extern const TrainerMonLine gKarenPool[];
extern const TrainerMonLine gLanceJohtoPool[];

// Sinnoh Elite Four & Champion Pools
extern const TrainerMonLine gAaronPool[];
extern const TrainerMonLine gBerthaPool[];
extern const TrainerMonLine gFlintPool[];
extern const TrainerMonLine gLucianPool[];
extern const TrainerMonLine gCynthiaPool[];

// Hoenn Elite Four & Champion Pools
extern const TrainerMonLine gSidneyPool[];
extern const TrainerMonLine gPhoebePool[];
extern const TrainerMonLine gGlaciaPool[];
extern const TrainerMonLine gDrakePool[];
extern const TrainerMonLine gStevenPool[];

// Function prototypes (add these if not already present)
bool8 TrainerClassUsesPool(u8 trainerClass, enum TrainerPoolCategory *outCategory);
const TrainerMonLine *GetPoolForTrainerClass(u8 trainerClass);
bool8 IsStaticTrainerClass(u8 trainerClass);
const TrainerMonLine *GetSpecialPoolForTrainer(u16 trainerId);
u16 GetAceSpeciesForTrainer(u16 trainerId);

// Special pool selector functions
const TrainerMonLine *GetGymLeaderPool(u16 trainerId);
u16 GetGymLeaderAce(u16 trainerId);
const TrainerMonLine *GetE4Pool(u16 trainerId);
u16 GetE4Ace(u16 trainerId);
const TrainerMonLine *GetChampionPool(u16 trainerId);
u16 GetChampionAce(u16 trainerId);
const TrainerMonLine *GetVillainAdminPool(u16 trainerId);
u16 GetVillainAdminAce(u16 trainerId);
const TrainerMonLine *GetVillainLeaderPool(u16 trainerId);
u16 GetVillainLeaderAce(u16 trainerId);

// Master Ace selector function
u16 GetAceSpeciesForTrainer(u16 trainerId);

// Special trainer party generation
void GenerateSpecialTrainerParty(struct Trainer *trainer, const TrainerMonLine *pool, u16 aceSpecies);

#endif // GUARD_TRAINER_POOLS_H
