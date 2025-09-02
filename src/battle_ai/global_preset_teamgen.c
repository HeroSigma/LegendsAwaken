#include "global.h"
#include "config/battle.h"
#include "constants/trainers.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "data.h"
#include "global_preset_party.h"
#include "species_presets.h"
#include "class_constraints.h"
#include "class_profiles.h"
#include "species_bans.h"
#include "mechanics_permissions.h"
#include "event_data.h"
#include "overworld.h"

#if B_GLOBAL_PRESET_TEAMS

#define ROLEBIT(r) (1u << (r))
#define TAGBIT(t)  (1u << (t))

static const struct ClassConstraint sDefaultConstraint = {
    .doubles = FALSE,
    .teamSize = 6,
    .allowedTypesMask = {0xFF, 0xFF},
    .bannedSpeciesCount = 0,
    .bannedSpecies = NULL,
    .speciesClause = TRUE,
    .formsAsSame = FALSE,
    .itemClause = TRUE
};

static const struct ClassProfile sDefaultProfile = {
    .doubles = FALSE,
    .roles = { ROLE_LEAD, ROLE_BREAKER, ROLE_PIVOT, ROLE_BREAKER, ROLE_SPEED_CTRL, ROLE_ACE }
};

static const struct ClassConstraint* GetClassConstraint(u8 trainerClass) {
    if (trainerClass == TRAINER_CLASS_BUG_CATCHER || 
        trainerClass == TRAINER_CLASS_HIKER ||
        trainerClass == TRAINER_CLASS_COOLTRAINER || 
        trainerClass == TRAINER_CLASS_EXPERT) {
        return &gClassConstraints[trainerClass];
    }
    return &sDefaultConstraint;
}

static const struct ClassProfile* GetClassProfile(u8 trainerClass) {
    if (trainerClass == TRAINER_CLASS_BUG_CATCHER || 
        trainerClass == TRAINER_CLASS_HIKER ||
        trainerClass == TRAINER_CLASS_COOLTRAINER || 
        trainerClass == TRAINER_CLASS_EXPERT) {
        return &gClassProfiles[trainerClass];
    }
    return &sDefaultProfile;
}

static u8 sTypeAllowed(const u8 mask[2], u8 t) { 
    return mask[t < 8 ? 0 : 1] & (1 << (t % 8)); 
}

// --- Badge-based level cap system uses existing Region enum from constants/regions.h ---

// --- Badge flags per region (fill with your project's flag names) ---
static const u16 sHoennBadgeFlags[8] = {
    FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
    FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
};
// TODO: Replace placeholders with your Johto/Kanto/Sinnoh badge flags when available
// For now, using Hoenn badges as fallback
static const u16 sJohtoBadgeFlags[8] = {
    FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
    FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
};
static const u16 sKantoBadgeFlags[8] = {
    FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
    FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
};
static const u16 sSinnohBadgeFlags[8] = {
    FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
    FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
};

// --- Cap tables per region (badge index 0..8). Tune to your balance.
// These top‑out at your regional caps: Hoenn 65 / Johto 72 / Kanto 82 / Sinnoh 100.
static const u8 sCapsHoenn[9] =  {12, 18, 22, 28, 34, 42, 55, 60, 65};
static const u8 sCapsJohto[9] =  {20, 26, 32, 38, 44, 52, 60, 68, 72};
static const u8 sCapsKanto[9] =  {54, 60, 66, 72, 76, 79, 81, 82, 82};
static const u8 sCapsSinnoh[9] = {92, 94, 96, 97, 98, 99,100,100,100};

static u8 CountBadges(const u16 flags[8]) {
    u8 c=0; for (u8 i=0;i<8;i++) if (FlagGet(flags[i])) c++; return c;
}

// If you already store the current region elsewhere, replace this with that getter.
static enum Region GetCurrentRegion(void) {
    // DEFAULT: Hoenn. Optionally, infer from map header or a saved variable.
    return REGION_HOENN;
}

static u8 CapForRegion(enum Region r, u8 badges) {
    const u8 i = (badges > 8) ? 8 : badges; // 0..8
    switch (r) {
    case REGION_HOENN: return sCapsHoenn[i];
    case REGION_JOHTO: return sCapsJohto[i];
    case REGION_KANTO: return sCapsKanto[i];
    case REGION_SINNOH: return sCapsSinnoh[i];
    default: return sCapsHoenn[i]; // fallback for other regions
    }
}

static u8 GetBattleLevelCap(u16 trainerId) {
    (void)trainerId;
    enum Region r = GetCurrentRegion();
    u8 badges = 0;
    switch (r) {
    case REGION_HOENN: badges = CountBadges(sHoennBadgeFlags); break;
    case REGION_JOHTO: badges = CountBadges(sJohtoBadgeFlags); break;
    case REGION_KANTO: badges = CountBadges(sKantoBadgeFlags); break;
    case REGION_SINNOH: badges = CountBadges(sSinnohBadgeFlags); break;
    default: badges = CountBadges(sHoennBadgeFlags); break; // fallback
    }
    return CapForRegion(r, badges);
}

// OPTIONAL: if a trainer forces Doubles, override the class profile on the fly
static bool8 TrainerForcesDoubles(u16 trainerId) {
    const struct Trainer *trainer = GetTrainerStructFromId(trainerId);
    return trainer->battleType == TRAINER_BATTLE_TYPE_DOUBLES;
}

static bool8 PassesClassConstraints(const struct PresetSet *p, const struct ClassConstraint *cc, u8 level) {
    if (level < p->levelMin || level > p->levelMax) 
        return FALSE;
    if (IsSpeciesBannedGlobal(p->species)) 
        return FALSE;
    // type filter
    if (!(sTypeAllowed(cc->allowedTypesMask, gSpeciesInfo[p->species].types[0]) ||
          sTypeAllowed(cc->allowedTypesMask, gSpeciesInfo[p->species].types[1])))
        return FALSE;
    // explicit bans list per class
    for (u16 i = 0; i < cc->bannedSpeciesCount; i++) 
        if (cc->bannedSpecies[i] == p->species) 
            return FALSE;
    return TRUE;
}

static u8 PickPreferredAbility(u16 species, const u8 pref[3]) {
    // Map 0->Ability 0, 1->Ability 1, 2->Hidden; return first available
    for (int i = 0; i < 3; i++) {
        u8 slot = pref[i];
        if (slot == 2) 
            return 2; // Hidden ability slot
        return slot; // 0 or 1
    }
    return 0;
}

static void BuildMonFromPreset(struct TrainerMon *t, const struct PresetSet *p, u8 level) {
    // Static arrays to persist EVs data
    static u8 evArrays[6][6]; // Support up to 6 Pokemon with 6 EVs each
    static u8 currentEvIndex = 0;
    
    t->species = p->species; 
    t->lvl = level; 
    t->heldItem = p->item; 
    t->nature = p->nature; 
    
    // For TrainerMon, ability is stored as the actual ability ID, not slot
    u8 abilitySlot = PickPreferredAbility(p->species, p->abilityPref);
    const struct SpeciesInfo *speciesInfo = &gSpeciesInfo[p->species];
    if (abilitySlot == 2 && speciesInfo->abilities[2] != ABILITY_NONE) {
        t->ability = speciesInfo->abilities[2]; // Hidden ability
    } else if (abilitySlot == 1 && speciesInfo->abilities[1] != ABILITY_NONE) {
        t->ability = speciesInfo->abilities[1]; // Second ability
    } else {
        t->ability = speciesInfo->abilities[0]; // First ability
    }
    
    // Set IVs - TrainerMon uses a single u32 for all IVs
    t->iv = 0;
    for (int s = 0; s < NUM_STATS; s++){
        t->iv |= (p->ivs[s] & 0x1F) << (s * 5);
    }
    
    // Set EVs - needs to be a persistent pointer to array
    u8 *evArray = evArrays[currentEvIndex % 6];
    currentEvIndex++;
    for (int s = 0; s < NUM_STATS; s++){
        evArray[s] = p->evs[s];
    }
    t->ev = evArray;
    
    for (int i = 0; i < 4; i++) 
        t->moves[i] = p->moves[i];
        
    // Initialize other fields
    t->nickname = NULL;
    t->ball = ITEM_POKE_BALL;
    t->friendship = 70;
    t->gender = TRAINER_MON_RANDOM_GENDER;
    t->isShiny = FALSE;
    t->teraType = 0;
    t->gigantamaxFactor = FALSE;
    t->shouldUseDynamax = FALSE;
    t->dynamaxLevel = 0;
    t->tags = 0;
}

static bool8 ViolatesClauses(const struct PresetSet *p, const struct ClassConstraint *cc, const struct TrainerMon *cur, u8 n) {
    if (cc->speciesClause) {
        for (u8 i=0;i<n;i++) 
            if (cur[i].species == p->species) 
                return TRUE;
        if (!cc->formsAsSame) 
            return FALSE; // forms allowed as distinct
        // Treat forms as same species by dex grouping if your fork supports it (skip for now)
    }
    if (cc->itemClause) {
        for (u8 i=0;i<n;i++) 
            if (cur[i].heldItem == p->item && p->item != ITEM_SITRUS_BERRY && p->item != ITEM_ORAN_BERRY) 
                return TRUE;
    }
    return FALSE;
}

static const struct PresetSet *PickForRole(u8 role, const struct PresetSet **pool, u16 poolCount, const struct ClassConstraint *cc, const struct TrainerMon *current, u8 currentCount) {
    for (u16 i=0;i<poolCount;i++) {
        const struct PresetSet *p = pool[i];
        if (!(p->roleMask & ROLEBIT(role))) 
            continue;
        if (ViolatesClauses(p, cc, current, currentCount)) 
            continue;
        return p;
    }
    return NULL;
}

bool8 UsePresetBuilderForTrainer(u8 trainerClass) {
    // Simple implementation - enable for all trainers by default
    // Can be customized based on trainer class or specific trainers
    (void)trainerClass;
    return TRUE;
}

void GeneratePresetTeam(u16 trainerClassOrId, struct TrainerMon *outParty, u8 outCount) {
    const u8 cls = trainerClassOrId; // Treat the parameter as trainer class for simplicity
    const struct ClassConstraint *cc = GetClassConstraint(cls);
    const struct ClassProfile *pf = GetClassProfile(cls);
    const u8 cap = GetBattleLevelCap(trainerClassOrId);

    // Handle doubles battles - if trainer forces doubles, treat teamSize = 4 and prefer doubles‑friendly presets
    bool8 forcesDoubles = TrainerForcesDoubles(trainerClassOrId);
    u8 effectiveTeamSize = forcesDoubles ? 4 : cc->teamSize;

    const u16 N = gSpeciesPresetsCount; // filter global library
    const struct PresetSet *filtered[1024]; 
    u16 f=0;
    for (u16 i=0;i<N;i++) 
        if (PassesClassConstraints(&gSpeciesPresets[i], cc, cap)) 
            filtered[f++] = &gSpeciesPresets[i];

    const u8 need = (cc->doubles || forcesDoubles) ? min(outCount, 4) : min(outCount, effectiveTeamSize);
    u8 built=0; 
    for (; built<need; built++) {
        u8 role = pf->roles[built];
        const struct PresetSet *pick = PickForRole(role, filtered, f, cc, outParty, built);
        if (!pick) 
            break;
        BuildMonFromPreset(&outParty[built], pick, cap);
    }

    // Mechanics (Mega/Z/Dyna) per class
    const struct ClassMechanicRule *mr = (cls == TRAINER_CLASS_LEADER) ? &gClassMechanics[cls] : NULL;
    if (mr && mr->policy == POLICY_ONE_OF) 
        ApplyMechanicsToTeam(ChooseMechanicForBattle(trainerClassOrId, mr->allowedMask), outParty, built);
    else if (mr)
        ApplyMechanicsToTeam(mr->allowedMask, outParty, built);
    else
        ApplyMechanicsToTeam(MECH_MEGA | MECH_ZMOVE | MECH_DMAX, outParty, built); // Default for unknown classes
}

#endif // B_GLOBAL_PRESET_TEAMS
