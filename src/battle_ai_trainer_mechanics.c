#include "global.h"
#include "battle.h"
#include "trainer_pools.h"
#include "data.h"
#include "pokemon.h"
#include "constants/items.h"
#include "constants/species.h"
#include "random.h"
#include "malloc.h"

// Assign beneficial items to all party members (except Mega/Z holders)
static void AssignBeneficialItems(struct TrainerMon *party, u8 partyCount)
{
    static const u16 beneficialItems[] = {
        ITEM_LEFTOVERS, ITEM_LIFE_ORB, ITEM_CHOICE_SCARF, ITEM_CHOICE_BAND,
        ITEM_CHOICE_SPECS, ITEM_FOCUS_SASH, ITEM_SITRUS_BERRY, ITEM_LUM_BERRY,
        ITEM_ASSAULT_VEST, ITEM_WEAKNESS_POLICY, ITEM_EXPERT_BELT, ITEM_WISE_GLASSES
    };

    for (u8 i = 0; i < partyCount; i++)
    {
        if (party[i].heldItem != ITEM_NONE)
            continue;   // already has special item

        party[i].heldItem = beneficialItems[Random() % ARRAY_COUNT(beneficialItems)];
    }
}

// Returns Mega Stone item ID for this species (or ITEM_NONE)
u16 GetMegaStoneForSpecies(u16 species)
{
    switch (species)
    {
        case SPECIES_VENUSAUR:          return ITEM_VENUSAURITE;
        case SPECIES_CHARIZARD:         return ITEM_CHARIZARDITE_X;   // or _Y
        case SPECIES_BLASTOISE:         return ITEM_BLASTOISINITE;
        case SPECIES_BEEDRILL:          return ITEM_BEEDRILLITE;
        case SPECIES_PIDGEOT:           return ITEM_PIDGEOTITE;
        case SPECIES_ALAKAZAM:          return ITEM_ALAKAZITE;
        case SPECIES_SLOWBRO:           return ITEM_SLOWBRONITE;
        case SPECIES_GENGAR:            return ITEM_GENGARITE;
        case SPECIES_KANGASKHAN:        return ITEM_KANGASKHANITE;
        case SPECIES_PINSIR:            return ITEM_PINSIRITE;
        case SPECIES_GYARADOS:          return ITEM_GYARADOSITE;
        case SPECIES_AERODACTYL:        return ITEM_AERODACTYLITE;
        case SPECIES_MEWTWO:            return ITEM_MEWTWONITE_X;     // or _Y
        case SPECIES_AMPHAROS:          return ITEM_AMPHAROSITE;
        case SPECIES_STEELIX:           return ITEM_STEELIXITE;
        case SPECIES_SCIZOR:            return ITEM_SCIZORITE;
        case SPECIES_HERACROSS:         return ITEM_HERACRONITE;
        case SPECIES_HOUNDOOM:          return ITEM_HOUNDOOMINITE;
        case SPECIES_TYRANITAR:         return ITEM_TYRANITARITE;
        case SPECIES_SCEPTILE:          return ITEM_SCEPTILITE;
        case SPECIES_BLAZIKEN:          return ITEM_BLAZIKENITE;
        case SPECIES_SWAMPERT:          return ITEM_SWAMPERTITE;
        case SPECIES_GARDEVOIR:         return ITEM_GARDEVOIRITE;
        case SPECIES_SABLEYE:           return ITEM_SABLENITE;
        case SPECIES_MAWILE:            return ITEM_MAWILITE;
        case SPECIES_AGGRON:            return ITEM_AGGRONITE;
        case SPECIES_MEDICHAM:          return ITEM_MEDICHAMITE;
        case SPECIES_MANECTRIC:         return ITEM_MANECTITE;
        case SPECIES_SHARPEDO:          return ITEM_SHARPEDONITE;
        case SPECIES_CAMERUPT:          return ITEM_CAMERUPTITE;
        case SPECIES_ALTARIA:           return ITEM_ALTARIANITE;
        case SPECIES_BANETTE:           return ITEM_BANETTITE;
        case SPECIES_ABSOL:             return ITEM_ABSOLITE;
        case SPECIES_GLALIE:            return ITEM_GLALITITE;
        case SPECIES_SALAMENCE:         return ITEM_SALAMENCITE;
        case SPECIES_METAGROSS:         return ITEM_METAGROSSITE;
        case SPECIES_LATIAS:            return ITEM_LATIASITE;
        case SPECIES_LATIOS:            return ITEM_LATIOSITE;
        case SPECIES_LOPUNNY:           return ITEM_LOPUNNITE;
        case SPECIES_GARCHOMP:          return ITEM_GARCHOMPITE;
        case SPECIES_LUCARIO:           return ITEM_LUCARIONITE;
        case SPECIES_ABOMASNOW:         return ITEM_ABOMASITE;
        case SPECIES_GALLADE:           return ITEM_GALLADITE;
        case SPECIES_AUDINO:            return ITEM_AUDINITE;
        // Add more as needed (all supported Megas in your project)
        default:                        return ITEM_NONE;
    }
}

// Returns Z-Crystal for this species/type (or ITEM_NONE)
u16 GetZCrystalForSpecies(u16 species)
{
    // Simple version: give Z-Crystal based on primary type
    u8 type1 = gSpeciesInfo[species].types[0];

    switch (type1)
    {
        case TYPE_NORMAL:   return ITEM_NORMALIUM_Z;
        case TYPE_FIRE:     return ITEM_FIRIUM_Z;
        case TYPE_WATER:    return ITEM_WATERIUM_Z;
        case TYPE_GRASS:    return ITEM_GRASSIUM_Z;
        case TYPE_ELECTRIC: return ITEM_ELECTRIUM_Z;
        case TYPE_ICE:      return ITEM_ICIUM_Z;
        case TYPE_FIGHTING: return ITEM_FIGHTINIUM_Z;
        case TYPE_POISON:   return ITEM_POISONIUM_Z;
        case TYPE_GROUND:   return ITEM_GROUNDIUM_Z;
        case TYPE_FLYING:   return ITEM_FLYINIUM_Z;
        case TYPE_PSYCHIC:  return ITEM_PSYCHIUM_Z;
        case TYPE_BUG:      return ITEM_BUGINIUM_Z;
        case TYPE_ROCK:     return ITEM_ROCKIUM_Z;
        case TYPE_GHOST:    return ITEM_GHOSTIUM_Z;
        case TYPE_DRAGON:   return ITEM_DRAGONIUM_Z;
        case TYPE_DARK:     return ITEM_DARKINIUM_Z;
        case TYPE_STEEL:    return ITEM_STEELIUM_Z;
        case TYPE_FAIRY:    return ITEM_FAIRIUM_Z;
        // Special Z-Crystals (Pikachu, Eevee, etc.) can be added here if species matches
        case SPECIES_PIKACHU: return ITEM_PIKANIUM_Z;
        case SPECIES_EEVEE:   return ITEM_EEVIUM_Z;
        default:              return ITEM_NONE;
    }
}

// Returns best Tera type (usually STAB)
u8 GetBestTeraType(u16 species)
{
    // Simple: return primary type
    return gSpeciesInfo[species].types[0];
}

// Main function to assign advanced mechanics to trainer party
void AssignAdvancedTrainerMechanics(struct Trainer *trainer)
{
    if (!trainer || trainer->partySize == 0)
        return;

    // Create a mutable copy of the party data
    struct TrainerMon *mutableParty = Alloc(sizeof(struct TrainerMon) * trainer->partySize);
    for (u8 i = 0; i < trainer->partySize; i++)
    {
        mutableParty[i] = trainer->party[i];
    }

    u8 megaIndex = 0xFF;
    u8 zIndex = 0xFF;
    u8 teraIndex = 0xFF;

    // 1. Mega Evolution (one per trainer)
    for (u8 i = 0; i < trainer->partySize; i++)
    {
        u16 species = mutableParty[i].species;
        u16 megaItem = GetMegaStoneForSpecies(species);
        if (megaItem != ITEM_NONE)
        {
            megaIndex = i;
            mutableParty[i].heldItem = megaItem;
            break;  // only one Mega
        }
    }

    // 2. Z-Move (one per trainer, different mon from Mega)
    for (u8 i = 0; i < trainer->partySize; i++)
    {
        if (i == megaIndex) continue;  // don't overwrite Mega holder

        u16 species = mutableParty[i].species;
        u16 zCrystal = GetZCrystalForSpecies(species);
        if (zCrystal != ITEM_NONE)
        {
            zIndex = i;
            mutableParty[i].heldItem = zCrystal;
            break;  // only one Z-Move
        }
    }

    // 3. Terastalize (one per trainer, different from Mega/Z)
    for (u8 i = 0; i < trainer->partySize; i++)
    {
        if (i == megaIndex || i == zIndex) continue;

        mutableParty[i].teraType = GetBestTeraType(mutableParty[i].species);
        teraIndex = i;
        break;
    }

    // 4. Dynamax (one per trainer, different from others)
    for (u8 i = 0; i < trainer->partySize; i++)
    {
        if (i == megaIndex || i == zIndex || i == teraIndex) continue;

        mutableParty[i].shouldUseDynamax = TRUE;
        mutableParty[i].dynamaxLevel = 10; // Max level
        break;
    }

    // 5. Fill remaining held items with beneficial ones
    AssignBeneficialItems(mutableParty, trainer->partySize);

    // Update the trainer's party pointer to point to our modified data
    trainer->party = mutableParty;
}
