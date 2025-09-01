#include "global.h"
#include "mechanics_permissions.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "data.h"

#if B_GLOBAL_PRESET_TEAMS

struct MegaMap { u16 species; u16 stone; };
static const struct MegaMap sMegaMap[] = {
    { SPECIES_VENUSAUR, ITEM_VENUSAURITE },
    { SPECIES_CHARIZARD, ITEM_CHARIZARDITE_X }, // X by default
    { SPECIES_BLASTOISE, ITEM_BLASTOISINITE },
    { SPECIES_BEEDRILL, ITEM_BEEDRILLITE },
    { SPECIES_PIDGEOT, ITEM_PIDGEOTITE },
    { SPECIES_ALAKAZAM, ITEM_ALAKAZITE },
    { SPECIES_SLOWBRO, ITEM_SLOWBRONITE },
    { SPECIES_GENGAR, ITEM_GENGARITE },
    { SPECIES_KANGASKHAN, ITEM_KANGASKHANITE },
    { SPECIES_PINSIR, ITEM_PINSIRITE },
    { SPECIES_GYARADOS, ITEM_GYARADOSITE },
    { SPECIES_AERODACTYL, ITEM_AERODACTYLITE },
    { SPECIES_AMPHAROS, ITEM_AMPHAROSITE },
    { SPECIES_STEELIX, ITEM_STEELIXITE },
    { SPECIES_SCIZOR, ITEM_SCIZORITE },
    { SPECIES_HERACROSS, ITEM_HERACRONITE },
    { SPECIES_HOUNDOOM, ITEM_HOUNDOOMINITE },
    { SPECIES_TYRANITAR, ITEM_TYRANITARITE },
    { SPECIES_SCEPTILE, ITEM_SCEPTILITE },
    { SPECIES_BLAZIKEN, ITEM_BLAZIKENITE },
    { SPECIES_SWAMPERT, ITEM_SWAMPERTITE },
    { SPECIES_GARDEVOIR, ITEM_GARDEVOIRITE },
    { SPECIES_MAWILE, ITEM_MAWILITE },
    { SPECIES_AGGRON, ITEM_AGGRONITE },
    { SPECIES_MEDICHAM, ITEM_MEDICHAMITE },
    { SPECIES_MANECTRIC, ITEM_MANECTITE },
    { SPECIES_SHARPEDO, ITEM_SHARPEDONITE },
    { SPECIES_CAMERUPT, ITEM_CAMERUPTITE },
    { SPECIES_ALTARIA, ITEM_ALTARIANITE },
    { SPECIES_BANETTE, ITEM_BANETTITE },
    { SPECIES_ABSOL, ITEM_ABSOLITE },
    { SPECIES_GLALIE, ITEM_GLALITITE },
    { SPECIES_SALAMENCE, ITEM_SALAMENCITE },
    { SPECIES_METAGROSS, ITEM_METAGROSSITE },
    { SPECIES_LOPUNNY, ITEM_LOPUNNITE },
    { SPECIES_GARCHOMP, ITEM_GARCHOMPITE },
    { SPECIES_LUCARIO, ITEM_LUCARIONITE },
    { SPECIES_ABOMASNOW, ITEM_ABOMASITE },
    { SPECIES_GALLADE, ITEM_GALLADITE },
    { SPECIES_AUDINO, ITEM_AUDINITE },
    // Note: Diancie, Latias/Latios, Mewtwo, Rayquaza omitted (banned or special mechanics)
};

static const u16 sTypeToZCrystal[] = {
    [TYPE_NORMAL]   = ITEM_NORMALIUM_Z,
    [TYPE_FIGHTING] = ITEM_FIGHTINIUM_Z,
    [TYPE_FLYING]   = ITEM_FLYINIUM_Z,
    [TYPE_POISON]   = ITEM_POISONIUM_Z,
    [TYPE_GROUND]   = ITEM_GROUNDIUM_Z,
    [TYPE_ROCK]     = ITEM_ROCKIUM_Z,
    [TYPE_BUG]      = ITEM_BUGINIUM_Z,
    [TYPE_GHOST]    = ITEM_GHOSTIUM_Z,
    [TYPE_STEEL]    = ITEM_STEELIUM_Z,
    [TYPE_FIRE]     = ITEM_FIRIUM_Z,
    [TYPE_WATER]    = ITEM_WATERIUM_Z,
    [TYPE_GRASS]    = ITEM_GRASSIUM_Z,
    [TYPE_ELECTRIC] = ITEM_ELECTRIUM_Z,
    [TYPE_PSYCHIC]  = ITEM_PSYCHIUM_Z,
    [TYPE_ICE]      = ITEM_ICIUM_Z,
    [TYPE_DRAGON]   = ITEM_DRAGONIUM_Z,
    [TYPE_DARK]     = ITEM_DARKINIUM_Z,
    [TYPE_FAIRY]    = ITEM_FAIRIUM_Z,
};

static const u16 sGmaxSpecies[] = {
    SPECIES_VENUSAUR, SPECIES_CHARIZARD, SPECIES_BLASTOISE, SPECIES_BUTTERFREE,
    SPECIES_PIKACHU, SPECIES_MEOWTH, SPECIES_MACHAMP, SPECIES_GENGAR, SPECIES_KINGLER,
    SPECIES_LAPRAS, SPECIES_EEVEE, SPECIES_SNORLAX, SPECIES_GARBODOR, SPECIES_MELMETAL,
    SPECIES_RILLABOOM, SPECIES_CINDERACE, SPECIES_INTELEON, SPECIES_CORVIKNIGHT,
    SPECIES_ORBEETLE, SPECIES_DREDNAW, SPECIES_COALOSSAL, SPECIES_FLAPPLE, SPECIES_APPLETUN,
    SPECIES_SANDACONDA, SPECIES_TOXTRICITY, SPECIES_TOXTRICITY_LOW_KEY, SPECIES_CENTISKORCH,
    SPECIES_HATTERENE, SPECIES_GRIMMSNARL, SPECIES_ALCREMIE, SPECIES_COPPERAJAH,
    SPECIES_DURALUDON, SPECIES_URSHIFU_SINGLE_STRIKE, SPECIES_URSHIFU_RAPID_STRIKE,
};

static bool8 TryAssignMega(struct TrainerMon *party, u8 count) {
    for (u8 i=0;i<count;i++)
        for (u32 j=0;j<ARRAY_COUNT(sMegaMap);j++)
            if (party[i].species==sMegaMap[j].species){ 
                party[i].heldItem = sMegaMap[j].stone; 
                return TRUE; 
            }
    return FALSE;
}

static bool8 __attribute__((unused)) SpeciesInArray(u16 species, const u16 *arr, u32 n){ 
    for(u32 i=0;i<n;i++) 
        if(arr[i]==species) 
            return TRUE; 
    return FALSE; 
}

static void EnableDynamaxForBattle(void){ 
    /* set your battle flag here */ 
}

static void EnableGmaxIfSupported(struct TrainerMon *party, u8 count){ 
    (void)party; 
    (void)count; 
    /* mark G-Max form if your engine supports it */ 
}

static bool8 TryAssignZCrystal(struct TrainerMon *party, u8 count) {
    for (u8 i=0;i<count;i++) {
        u8 t1 = gSpeciesInfo[party[i].species].types[0];
        if (t1 < ARRAY_COUNT(sTypeToZCrystal) && sTypeToZCrystal[t1] != ITEM_NONE) { 
            party[i].heldItem = sTypeToZCrystal[t1]; 
            return TRUE; 
        }
    }
    return FALSE;
}

u8 ChooseMechanicForBattle(u16 trainerId, u8 allowedMask){ 
    u8 options[3]; 
    u8 n=0; 
    if(allowedMask&MECH_MEGA) options[n++]=MECH_MEGA; 
    if(allowedMask&MECH_ZMOVE) options[n++]=MECH_ZMOVE; 
    if(allowedMask&MECH_DMAX) options[n++]=MECH_DMAX; 
    if(!n) return MECH_NONE; 
    return options[trainerId % n]; 
}

void ApplyMechanicsToTeam(u8 mechanicMask, struct TrainerMon *party, u8 count){ 
    if(mechanicMask&MECH_MEGA) TryAssignMega(party,count); 
    if(mechanicMask&MECH_ZMOVE) TryAssignZCrystal(party,count); 
    if(mechanicMask&MECH_DMAX){ 
        EnableDynamaxForBattle(); 
        EnableGmaxIfSupported(party,count);
    } 
}

#endif // B_GLOBAL_PRESET_TEAMS
