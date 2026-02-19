#include "global.h"
#include "constants/species.h"
#include "constants/wild_pools.h"

// ════════════════════════════════════════════════════════════════════════════
//                        POOL_GRASS: OPEN FIELDS/BIRDS
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gGrassPool[] = {
    // Early common normal / rodent types (high weight)
    {{SPECIES_ZIGZAGOON,     SPECIES_LINOONE,      SPECIES_NONE,         SPECIES_NONE},
     {  2,                   16,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     200,  0},

    {{SPECIES_ZIGZAGOON_GALAR, SPECIES_LINOONE_GALAR, SPECIES_NONE,         SPECIES_NONE},
     {  2,                   16,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     180,  0},

    {{SPECIES_SENTRET,       SPECIES_FURRET,       SPECIES_NONE,         SPECIES_NONE},
     {  3,                   15,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     190,  0},

    {{SPECIES_BUNNELBY,      SPECIES_DIGGERSBY,    SPECIES_NONE,         SPECIES_NONE},
     {  4,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     180,  0},

    {{SPECIES_RATTATA,       SPECIES_RATICATE,     SPECIES_NONE,         SPECIES_NONE},
     {  3,                   18,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     170,  2},   // night bias

    {{SPECIES_RATTATA_ALOLA, SPECIES_RATICATE_ALOLA, SPECIES_NONE,         SPECIES_NONE},
     {  3,                   18,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     140,  2},   // night bias

    {{SPECIES_FURRET,        SPECIES_STOUTLAND,      SPECIES_NONE,         SPECIES_NONE},
     {  3,                   15,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     130,  0},

    {{SPECIES_MEOWTH,        SPECIES_PERSIAN,      SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120,  0},

    {{SPECIES_MEOWTH_ALOLA,  SPECIES_PERSIAN_ALOLA, SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     100,  2},   // night bias

    {{SPECIES_DIGLETT,       SPECIES_DUGTRIO,      SPECIES_NONE,         SPECIES_NONE},
     {  3,                   16,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     110,  0},

    {{SPECIES_DIGLETT_ALOLA, SPECIES_DUGTRIO_ALOLA, SPECIES_NONE,         SPECIES_NONE},
     {  3,                   16,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     90,   0},

    {{SPECIES_BIDOOF,        SPECIES_BIBAREL,      SPECIES_NONE,         SPECIES_NONE},
     {  3,                   15,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     100,  0},

    {{SPECIES_PATRAT,        SPECIES_WATCHOG,      SPECIES_NONE,         SPECIES_NONE},
     {  3,                   16,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     90,  0},

    {{SPECIES_LILLIPUP,       SPECIES_HERDIER,      SPECIES_STOUTLAND,    SPECIES_NONE},
     {  3,                   16,                  32,                    0 },
     {  0,                    2,                   5,                    0 },
     80, 0},

    {{SPECIES_SKWOVET,        SPECIES_GREEDENT,     SPECIES_NONE,         SPECIES_NONE},
     {  4,                   18,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     130, 0},

    {{SPECIES_LECHONK,        SPECIES_OINKOLOGNE,   SPECIES_NONE,         SPECIES_NONE},
     { 4,                   18,                   0,                    0 },
     { 0,                    3,                   0,                    0 },
     120, 0},

    {{SPECIES_YUNGOOS,        SPECIES_GUMSHOOS,     SPECIES_NONE,         SPECIES_NONE},
     {  4,                   17,                   0,                    0 },
     { 0,                    3,                   0,                    0 },
     110, 0},

    {{SPECIES_MINCCINO,       SPECIES_CINCCINO,      SPECIES_NONE,         SPECIES_NONE},
     {  5,                   22,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     30,   0},

    // Bird lines (high weight)
    {{SPECIES_PIDGEY,        SPECIES_PIDGEOTTO,    SPECIES_PIDGEOT,     SPECIES_NONE},
     {  3,                   18,                  36,                    0 },
     {  0,                    2,                   5,                    0 },
     180,  0},

    {{SPECIES_SPEAROW,       SPECIES_FEAROW,      SPECIES_NONE,         SPECIES_NONE},
     {  3,                   20,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     170,  0},

    {{SPECIES_FARFETCHD,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     50,   0},

    {{SPECIES_FARFETCHD_GALAR, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     40,   0},

    {{SPECIES_EKANS,         SPECIES_ARBOK,       SPECIES_NONE,         SPECIES_NONE},
     {  8,                   28,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     80,   0},

    {{SPECIES_PIKACHU,       SPECIES_RAICHU,      SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     70,   0},

    {{SPECIES_PIKACHU, SPECIES_RAICHU_ALOLA, SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     60,   0},

    {{SPECIES_PIKACHU_COSPLAY, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_ROCK_STAR, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_BELLE,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_POP_STAR, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_PHD,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_LIBRE,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_ORIGINAL, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_HOENN,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_SINNOH,  SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_UNOVA,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_KALOS,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_PARTNER, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PIKACHU_WORLD,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_PICHU_SPIKY_EARED, SPECIES_NONE,       SPECIES_NONE,         SPECIES_NONE},
     {  2,                   15,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     40,   0},

    {{SPECIES_NIDORAN_F,     SPECIES_NIDORINA,    SPECIES_NIDOQUEEN,    SPECIES_NONE},
     {  3,                   16,                  36,                    0 },
     {  0,                    2,                   6,                    0 },
     65,   0},

    {{SPECIES_NIDORAN_M,     SPECIES_NIDORINO,    SPECIES_NIDOKING,     SPECIES_NONE},
     {  3,                   16,                  36,                    0 },
     {  0,                    2,                   6,                    0 },
     65,   0},

    {{SPECIES_CLEFAIRY,      SPECIES_CLEFABLE,    SPECIES_NONE,         SPECIES_NONE},
     {  4,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   1},   // day bias

    {{SPECIES_JIGGLYPUFF,    SPECIES_WIGGLYTUFF,  SPECIES_NONE,         SPECIES_NONE},
     {  6,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     45,   0},

    {{SPECIES_MANKEY,        SPECIES_PRIMEAPE,    SPECIES_NONE,         SPECIES_NONE},
     {  5,                   28,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     40,   0},

    {{SPECIES_POLIWAG,       SPECIES_POLIWHIRL,   SPECIES_POLIWRATH,   SPECIES_NONE},
     {  5,                   25,                  36,                    0 },
     {  0,                    3,                   6,                    0 },
     35,   0},

    {{SPECIES_ABRA,          SPECIES_KADABRA,     SPECIES_ALAKAZAM,     SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    3,                   6,                    0 },
     30,   0},

    {{SPECIES_MACHOP,        SPECIES_MACHOKE,     SPECIES_MACHAMP,      SPECIES_NONE},
     {  5,                   28,                  36,                    0 },
     {  0,                    3,                   6,                    0 },
     25,   0},

    {{SPECIES_TENTACOOL,     SPECIES_TENTACRUEL,  SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_PARAS,         SPECIES_PARASECT,    SPECIES_NONE,         SPECIES_NONE},
     {  6,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     18,   0},

    {{SPECIES_VENONAT,       SPECIES_VENOMOTH,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   31,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_DODUO,         SPECIES_DODRIO,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   34,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     12,   0},

    {{SPECIES_SEEL,          SPECIES_DEWGONG,     SPECIES_NONE,         SPECIES_NONE},
     { 12,                   34,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     10,   0},

    {{SPECIES_GRIMER,        SPECIES_MUK,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   38,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_GRIMER_ALOLA,  SPECIES_MUK_ALOLA,   SPECIES_NONE,         SPECIES_NONE},
     {  8,                   38,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     6,    0},

    {{SPECIES_KOFFING,       SPECIES_WEEZING,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   38,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_WEEZING_GALAR, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   38,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     6,    0},

    {{SPECIES_RHYHORN,       SPECIES_RHYDON,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   42,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     6,    0},

    {{SPECIES_CHANSEY,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     4,    0},

    {{SPECIES_TANGELA,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   12,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     4,    0},

    {{SPECIES_KANGASKHAN,    SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     3,    0},

    {{SPECIES_TAUROS,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     3,    0},

    {{SPECIES_TAUROS_PALDEA_COMBAT, SPECIES_NONE,    SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     2,    0},

    {{SPECIES_TAUROS_PALDEA_BLAZE, SPECIES_NONE,     SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     2,    0},

    {{SPECIES_TAUROS_PALDEA_AQUA, SPECIES_NONE,      SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     2,    0},

    {{SPECIES_SNORLAX,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 20,                   20,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     2,    0},

    {{SPECIES_DITTO,         SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     2,    0},

    // Early grass types (medium weight)
    {{SPECIES_ODDISH,        SPECIES_GLOOM,        SPECIES_VILEPLUME,    SPECIES_NONE},
     {  3,                   21,                  36,                    0 },
     {  0,                    2,                   4,                    0 },
     120, 0},

    {{SPECIES_BELLSPROUT,    SPECIES_WEEPINBELL,   SPECIES_VICTREEBEL,   SPECIES_NONE},
     {  3,                   21,                  36,                    0 },
     {  0,                    2,                   4,                    0 },
     110, 0},

    {{SPECIES_HOPPIP,        SPECIES_SKIPLOOM,     SPECIES_JUMPLUFF,     SPECIES_NONE},
     {  3,                   18,                  27,                    0 },
     { 0,                    2,                   5,                    0 },
     100, 1},   // day bias

    {{SPECIES_SUNKERN,       SPECIES_SUNFLORA,     SPECIES_NONE,         SPECIES_NONE},
     {  5,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     90,   1},   // day bias

    {{SPECIES_SEEDOT,        SPECIES_NUZLEAF,      SPECIES_SHIFTRY,     SPECIES_NONE},
     {  3,                   14,                  29,                    0 },
     {  0,                    1,                   4,                    0 },
     85,   0},

    {{SPECIES_LOTAD,         SPECIES_LOMBRE,       SPECIES_LUDICOLO,     SPECIES_NONE},
     {  3,                   14,                  29,                    0 },
     {  0,                    1,                   4,                    0 },
     80,   0},

    {{SPECIES_ROSELIA,       SPECIES_ROSERADE,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   34,                   0,                    0 },
     { 0,                    4,                   0,                    0 },
     70,   0},

    // Modern grass types (medium weight)
    {{SPECIES_PETILIL,       SPECIES_LILLIGANT,    SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     { 0,                    3,                   0,                    0 },
     65,   0},

    {{SPECIES_COTTONEE,      SPECIES_WHIMSICOTT,   SPECIES_NONE,         SPECIES_NONE},
     {  4,                   24,                   0,                    0 },
     { 0,                    3,                   0,                    0 },
     60,   0},

    {{SPECIES_BOUNSWEET,     SPECIES_STEENEE,      SPECIES_TSAREENA,     SPECIES_NONE},
     { 4,                   18,                  32,                    0 },
     { 0,                    2,                   5,                    0 },
     55,   0},

    {{SPECIES_SMOLIV,        SPECIES_DOLLIV,       SPECIES_ARBOLIVA,     SPECIES_NONE},
     {  4,                   17,                  35,                    0 },
     { 0,                    2,                   6,                    0 },
     50,   0},

    {{SPECIES_FLABEBE_RED,   SPECIES_FLOETTE_RED,  SPECIES_FLORGES_RED,  SPECIES_NONE},
     { 4,                   19,                  36,                    0 },
     { 0,                    2,                   5,                    0 },
     45,   0},

    {{SPECIES_CAPSAKID,      SPECIES_SCOVILLAIN,   SPECIES_NONE,         SPECIES_NONE},
     { 6,                   28,                   0,                    0 },
     { 0,                    3,                   0,                    0 },
     40,   0},

    // Special/utility lines (lower weight)
    {{SPECIES_SHROOMISH,     SPECIES_BRELOOM,      SPECIES_NONE,         SPECIES_NONE},
     { 6,                   23,                   0,                    0 },
     { 0,                    3,                   0,                    0 },
     35,   0},

    {{SPECIES_EEVEE,         SPECIES_VAPOREON,     SPECIES_JOLTEON,      SPECIES_FLAREON},
     { 10,                  25,                  25,                   25 },
     {  3,                   5,                   5,                    5 },
     15,   0},

    // Rare encounters (very low weight)
    {{SPECIES_RALTS,         SPECIES_KIRLIA,       SPECIES_GARDEVOIR,     SPECIES_NONE},
     { 4,                   20,                  30,                    0 },
     { 1,                    3,                   6,                    0 },
     12,   0},

    {{SPECIES_RIOLU,         SPECIES_LUCARIO,      SPECIES_NONE,         SPECIES_NONE},
     { 8,                   28,                   0,                    0 },
     { 0,                    4,                   0,                    0 },
     10,   0},

    {{SPECIES_HERACROSS,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     { 4,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_PINSIR,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     { 4,                    4,                   0,                    0 },
     8,    0},

    // Pseudo-legendaries (extremely rare, postgame)
    {{SPECIES_BAGON,         SPECIES_SHELGON,      SPECIES_SALAMENCE,    SPECIES_NONE},
     { 8,                   30,                  50,                    0 },
     { 0,                    4,                   8,                    0 },
     3,    0},

    {{SPECIES_AXEW,          SPECIES_FRAXURE,      SPECIES_HAXORUS,      SPECIES_NONE},
     {10,                   38,                  48,                    0 },
     { 0,                    6,                  12,                    0 },
     3,    0},

    {{SPECIES_LARVITAR,      SPECIES_PUPITAR,      SPECIES_TYRANITAR,    SPECIES_NONE},
     { 8,                   30,                  55,                    0 },
     { 0,                    4,                   8,                    0 },
     3,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gGrassPoolCount = ARRAY_COUNT(gGrassPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                     POOL_FOREST: BUG/GRASS HEAVY
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gForestPool[] = {
    // Early bug lines (high weight)
    {{SPECIES_CATERPIE,     SPECIES_METAPOD,      SPECIES_BUTTERFREE,    SPECIES_NONE},
     {  2,                    7,                  10,                    0 },
     {  0,                    0,                   3,                    0 },
     200,  1},   // day bias

    {{SPECIES_WEEDLE,        SPECIES_KAKUNA,       SPECIES_BEEDRILL,      SPECIES_NONE},
     {  2,                    7,                  10,                    0 },
     {  0,                    0,                   3,                    0 },
     190,  0},

    {{SPECIES_WURMPLE,       SPECIES_SILCOON,      SPECIES_BEAUTIFLY,    SPECIES_NONE},
     {  2,                    7,                  10,                    0 },
     {  0,                    0,                   3,                    0 },
     180,  1},   // day bias

    {{SPECIES_WURMPLE,       SPECIES_CASCOON,      SPECIES_DUSTOX,       SPECIES_NONE},
     {  2,                    7,                  10,                    0 },
     {  0,                    0,                   3,                    0 },
     170,  2},   // night bias

    {{SPECIES_WURMPLE,       SPECIES_SILCOON,      SPECIES_BEAUTIFLY,    SPECIES_NONE},
     {  2,                    7,                  10,                    0 },
     {  0,                    0,                   3,                    0 },
     170,  1},   // day bias

    {{SPECIES_LEDYBA,        SPECIES_LEDIAN,       SPECIES_ARIADOS,       SPECIES_NONE},
     {  3,                   18,                  36,                    0 },
     {  0,                    2,                   5,                    0 },
     160,  0},

    {{SPECIES_SPINARAK,     SPECIES_ARIADOS,      SPECIES_NONE,         SPECIES_NONE},
     {  4,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     80,   0},

    {{SPECIES_LEDYBA,        SPECIES_LEDIAN,       SPECIES_NONE,         SPECIES_NONE},
     {  5,                   22,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     70,   0},

    {{SPECIES_KRICKETOT,    SPECIES_KRICKETUNE,   SPECIES_NONE,         SPECIES_NONE},
     {  6,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     60,   0},

    {{SPECIES_PINECO,        SPECIES_FORRETRESS, SPECIES_NONE,         SPECIES_NONE},
     {  8,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_BURMY_PLANT,  SPECIES_WORMADAM_PLANT, SPECIES_NONE,         SPECIES_NONE},
     {  5,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     40,   0},

    {{SPECIES_BURMY_SANDY,  SPECIES_WORMADAM_SANDY, SPECIES_NONE,         SPECIES_NONE},
     {  5,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     40,   0},

    {{SPECIES_BURMY_TRASH,  SPECIES_WORMADAM_TRASH, SPECIES_NONE,         SPECIES_NONE},
     {  5,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     40,   0},

    {{SPECIES_COMBEE,        SPECIES_VESPIQUEN,   SPECIES_NONE,         SPECIES_NONE},
     {  8,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     35,   0},

    {{SPECIES_NINCADA,       SPECIES_NINJASK,     SPECIES_SHEDINJA,    SPECIES_NONE},
     {  4,                   20,                  20,                    0 },
     {  0,                    3,                   3,                    0 },
     30,   0},

    {{SPECIES_SCYTHER,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   12,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     25,   0},

    {{SPECIES_HERACROSS,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_VOLBEAT,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_ILLUMISE,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_VIVILLON_POLAR, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_TUNDRA, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_CONTINENTAL, SPECIES_NONE,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_GARDEN, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_ELEGANT, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_MEADOW, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_MODERN, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_MARINE, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_ARCHIPELAGO, SPECIES_NONE,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_HIGH_PLAINS, SPECIES_NONE,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_SANDSTORM, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_RIVER, SPECIES_NONE,           SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_MONSOON, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_SAVANNA, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_SUN, SPECIES_NONE,             SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_OCEAN, SPECIES_NONE,            SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_JUNGLE, SPECIES_NONE,           SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_VIVILLON_FANCY, SPECIES_NONE,           SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_DEERLING_SPRING, SPECIES_SAWSBUCK_SPRING, SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_DEERLING_SUMMER, SPECIES_SAWSBUCK_SUMMER, SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_DEERLING_AUTUMN, SPECIES_SAWSBUCK_AUTUMN, SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_DEERLING_WINTER, SPECIES_SAWSBUCK_WINTER, SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_CHERRIM_OVERCAST, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_CHERRIM_SUNSHINE, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   1},   // day bias

    {{SPECIES_SHELLOS_WEST,   SPECIES_GASTRODON_WEST, SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_SHELLOS_EAST,   SPECIES_GASTRODON_EAST, SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_FLABEBE_YELLOW, SPECIES_FLOETTE_YELLOW, SPECIES_FLORGES_YELLOW, SPECIES_NONE},
     {  4,                   19,                  36,                    0 },
     {  0,                    2,                   5,                    0 },
     45,   0},

    {{SPECIES_FLABEBE_ORANGE, SPECIES_FLOETTE_ORANGE, SPECIES_FLORGES_ORANGE, SPECIES_NONE},
     {  4,                   19,                  36,                    0 },
     {  0,                    2,                   5,                    0 },
     45,   0},

    {{SPECIES_FLABEBE_BLUE,   SPECIES_FLOETTE_BLUE,   SPECIES_FLORGES_BLUE,   SPECIES_NONE},
     {  4,                   19,                  36,                    0 },
     {  0,                    2,                   5,                    0 },
     45,   0},

    {{SPECIES_FLABEBE_WHITE,  SPECIES_FLOETTE_WHITE,  SPECIES_FLORGES_WHITE,  SPECIES_NONE},
     {  4,                   19,                  36,                    0 },
     {  0,                    2,                   5,                    0 },
     45,   0},

    {{SPECIES_FLOETTE_ETERNAL, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 25,                   25,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     25,   0},

    {{SPECIES_FURFROU_NATURAL, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_HEART,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_STAR,    SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_DIAMOND, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_DEBUTANTE, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_MATRON,  SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_DANDY,   SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_LA_REINE, SPECIES_NONE,        SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_KABUKI,  SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_FURFROU_PHARAOH, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_KRICKETOT,     SPECIES_KRICKETUNE,   SPECIES_NONE,         SPECIES_NONE},
     {  3,                   16,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     140,  0},

    {{SPECIES_SEWADDLE,      SPECIES_SWADLOON,     SPECIES_LEAVANNY,     SPECIES_NONE},
     {  3,                   20,                  36,                    0 },
     {  0,                    2,                   5,                    0 },
     130,  0},

    {{SPECIES_SCATTERBUG,    SPECIES_SPEWPA,       SPECIES_VIVILLON,     SPECIES_NONE},
     {  3,                    9,                  12,                    0 },
     {  0,                    1,                   4,                    0 },
     120,  0},

    {{SPECIES_TAROUNTULA,    SPECIES_SPIDOPS,      SPECIES_NONE,         SPECIES_NONE},
     {  4,                   20,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     110,  0},

    {{SPECIES_NYMBLE,        SPECIES_VIKAVOLT,     SPECIES_NOIVERN,       SPECIES_NONE},
     {  4,                   20,                  40,                    0 },
     {  0,                    4,                   8,                    0 },
     100,  0},

    {{SPECIES_COMBEE,        SPECIES_VESPIQUEN,    SPECIES_NONE,         SPECIES_NONE},
     {  4,                   20,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     90,   0},

    // Mid-tier bugs and forest dwellers (medium weight)
    {{SPECIES_PARAS,         SPECIES_PARASECT,     SPECIES_NONE,         SPECIES_NONE},
     {  5,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     80,   0},

    {{SPECIES_VENONAT,       SPECIES_VENOMOTH,     SPECIES_NONE,         SPECIES_NONE},
     {  7,                   31,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     75,   0},

    {{SPECIES_PINECO,        SPECIES_FORRETRESS,    SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     70,   0},

    {{SPECIES_SHROOMISH,     SPECIES_BRELOOM,      SPECIES_NONE,         SPECIES_NONE},
     {  6,                   23,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     65,   0},

    {{SPECIES_FOONGUS,       SPECIES_AMOONGUSS,    SPECIES_NONE,         SPECIES_NONE},
     {  4,                   22,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     60,   0},

    {{SPECIES_MORELULL,      SPECIES_SHIINOTIC,    SPECIES_NONE,         SPECIES_NONE},
     {  4,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     55,   0},

    {{SPECIES_PHANTUMP,      SPECIES_TREVENANT,    SPECIES_NONE,         SPECIES_NONE},
     {  5,                   26,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     50,   0},

    {{SPECIES_ORBEETLE,      SPECIES_LURANTIS,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     45,   0},

    // Poison/forest predators (lower weight)
    {{SPECIES_CROAGUNK,      SPECIES_TOXICROAK,    SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     40,   0},

    {{SPECIES_BUDEW,         SPECIES_ROSERADE,     SPECIES_NONE,         SPECIES_NONE},
     { 6,                    22,                  34,                    0 },
     {  0,                    3,                   5,                    0 },
     35,   0},

    // Forest birds (lower weight)
    {{SPECIES_HOOTHOOT,       SPECIES_NOCTOWL,      SPECIES_NONE,         SPECIES_NONE},
     { 4,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     30,   2},   // night bias

    {{SPECIES_MURKROW,       SPECIES_HONCHKROW,    SPECIES_NONE,         SPECIES_NONE},
     {  5,                   24,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     25,   2},   // night bias

    {{SPECIES_PIDOVE,        SPECIES_TRANQUILL,    SPECIES_UNFEZANT,     SPECIES_BLITZLE},
     {  4,                   21,                  32,                  40 },
     {  0,                    3,                   5,                    7 },
     20,   0},

    // Rare forest encounters (very low weight)
    {{SPECIES_DEINO,         SPECIES_ZWEILOUS,     SPECIES_HYDREIGON,    SPECIES_NONE},
     { 8,                   30,                  50,                    0 },
     {  0,                    4,                   8,                    0 },
     8,    0},

    {{SPECIES_BAGON,         SPECIES_SHELGON,      SPECIES_SALAMENCE,    SPECIES_NONE},
     { 8,                   30,                  50,                    0 },
     {  0,                    4,                   8,                    0 },
     6,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gForestPoolCount = ARRAY_COUNT(gForestPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                  POOL_VOLCANO: FIRE/ROCK/GROUND HEAVY
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gVolcanoPool[] = {
    // Classic fire lines (high weight)
    {{SPECIES_SLUGMA,        SPECIES_MAGCARGO,     SPECIES_NONE,         SPECIES_NONE},
     {  8,                   38,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     200,  0},

    {{SPECIES_NUMEL,         SPECIES_CAMERUPT,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   33,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     180,  0},

    {{SPECIES_GROWLITHE,     SPECIES_ARCANINE,    SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     160,  0},

    {{SPECIES_VULPIX,        SPECIES_NINETALES,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     140,  0},

    {{SPECIES_PONYTA,        SPECIES_RAPIDASH,    SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120,  0},

    {{SPECIES_CUBONE,        SPECIES_MAROWAK,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     80,   0},

    {{SPECIES_MAROWAK_ALOLA, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     60,   0},

    {{SPECIES_GROWLITHE_HISUI, SPECIES_ARCANINE_HISUI, SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     30,   0},

    {{SPECIES_VOLTORB_HISUI, SPECIES_ELECTRODE_HISUI, SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     25,   0},

    {{SPECIES_VULPIX_ALOLA,  SPECIES_NINETALES_ALOLA, SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_PONYTA_GALAR,  SPECIES_RAPIDASH_GALAR, SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_GROWLITHE_HISUI, SPECIES_ARCANINE_HISUI, SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     40,   0},   // rare form

    // Modern fire lines (medium weight)
    {{SPECIES_ROLYCOLY,      SPECIES_CARKOL,       SPECIES_COALOSSAL,    SPECIES_NONE},
     {  6,                   18,                  40,                    0 },
     {  0,                    4,                  10,                    0 },
     140,  0},

    {{SPECIES_HOUNDOUR,      SPECIES_HOUNDOOM,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120,  0},

    {{SPECIES_SALANDIT,      SPECIES_SALAZZLE,    SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     100,  0},

    {{SPECIES_STUNFISK_GALAR, SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     80,   0},

    // Rock/Ground types (medium weight)
    {{SPECIES_GEODUDE,       SPECIES_GRAVELER,     SPECIES_GOLEM,        SPECIES_NONE},
     {  8,                   25,                  40,                    0 },
     {  0,                    4,                   8,                    0 },
     130,  0},

    {{SPECIES_KOFFING,       SPECIES_WEEZING,      SPECIES_RHYHORN,      SPECIES_RHYDON},
     {  4,                   18,                  32,                  42 },
     {  0,                    2,                   4,                   6 },
     110,  0},

    {{SPECIES_CACNEA,        SPECIES_CACTURNE,     SPECIES_SWABLU,       SPECIES_ALTARIA},
     {  6,                   24,                  36,                  44 },
     {  0,                    2,                   4,                   6 },
     90,   0},

    // Special volcanic/fire types (lower weight)
    {{SPECIES_TORKOAL,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   12,                   0,                    0 },
     {  0,                    0,                   0,                    0 },
     70,   0},

    {{SPECIES_MAGBY,         SPECIES_MILTANK,     SPECIES_NONE,         SPECIES_NONE},
     {  8,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     60,   0},

    // Pseudo-legendaries (very low weight, postgame)
    {{SPECIES_LARVITAR,      SPECIES_PUPITAR,      SPECIES_TYRANITAR,    SPECIES_NONE},
     { 8,                   30,                  55,                    0 },
     {  0,                    4,                   8,                    0 },
     8,    0},

    {{SPECIES_DEINO,         SPECIES_ZWEILOUS,     SPECIES_HYDREIGON,    SPECIES_NONE},
     { 8,                   30,                  50,                    0 },
     {  0,                    4,                   8,                    0 },
     6,    0},

    {{SPECIES_LARVESTA,      SPECIES_VOLCARONA,    SPECIES_COBALION,     SPECIES_TERRAKION},
     {  6,                   25,                  40,                  50 },
     {  0,                    3,                   6,                   8 },
     4,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gVolcanoPoolCount = ARRAY_COUNT(gVolcanoPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                   POOL_WETLAND: POISON/WATER/BUG MIX
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gWetlandPool[] = {
    // Water/bug lines (high weight)
    {{SPECIES_WOOPER,        SPECIES_QUAGSIRE,     SPECIES_NONE,         SPECIES_NONE},
     {  5,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     200,  0},

    {{SPECIES_TYMPOLE,      SPECIES_POLITOED,     SPECIES_POLIWRATH,    SPECIES_NONE},
     {  4,                   20,                  30,                    0 },
     {  0,                    2,                   4,                   6 },
     180,  0},

    {{SPECIES_SURSKIT,       SPECIES_MASQUERAIN,   SPECIES_NONE,         SPECIES_NONE},
     {  5,                   22,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     160,  0},

    {{SPECIES_WINGULL,       SPECIES_PELIPPER,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     140,  0},

    // Poison types (medium weight)
    {{SPECIES_GRIMER,        SPECIES_MUK,          SPECIES_NONE,         SPECIES_NONE},
     {  5,                   33,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     120,  2},   // night bias

    {{SPECIES_NINCADA,       SPECIES_NINJASK,      SPECIES_SHEDINJA,     SPECIES_NONE},
     {  5,                   20,                  20,                    0 },
     {  0,                    3,                   3,                    0 },
     100,  0},

    {{SPECIES_CROAGUNK,      SPECIES_TOXICROAK,    SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     90,   0},

    {{SPECIES_SKORUPI,       SPECIES_DRAPION,      SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     80,   0},

    // Swamp/water dwellers (medium weight)
    {{SPECIES_FOONGUS,       SPECIES_AMOONGUSS,    SPECIES_NONE,         SPECIES_NONE},
     {  4,                   22,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     70,   0},

    {{SPECIES_SHIINOTIC,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  4,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     65,   0},

    {{SPECIES_GOOMY,         SPECIES_SLIGGOO,      SPECIES_GOODRA,        SPECIES_NONE},
     {  4,                   20,                  30,                  40 },
     {  0,                    2,                   4,                   6 },
     60,   0},

    {{SPECIES_TOXEL,         SPECIES_TOXTRICITY,   SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     55,   0},

    {{SPECIES_MAREANIE,      SPECIES_TOXAPEX,      SPECIES_MUDBRAY,     SPECIES_MUDSDALE},
     {  4,                   20,                  32,                  40 },
     {  0,                    2,                   4,                   6 },
     50,   0},

    // Plant/water hybrids (lower weight)
    {{SPECIES_LOTAD,         SPECIES_LOMBRE,       SPECIES_LUDICOLO,     SPECIES_NONE},
     {  3,                   14,                  29,                    0 },
     {  0,                    1,                   4,                    0 },
     40,   0},

    {{SPECIES_CARNIVINE,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     35,   0},

    // Rare encounters (very low weight)
    {{SPECIES_TROPIUS,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  4,                    4,                   0,                    0 },
     15,   0},

    // Postgame pseudo-legendaries (extremely rare, postgame)
    {{SPECIES_GIBLE,         SPECIES_GABITE,       SPECIES_GARCHOMP,     SPECIES_NONE},
     { 8,                   24,                  48,                    0 },
     {  0,                    4,                   6,                    0 },
     8,    0},

    {{SPECIES_AXEW,          SPECIES_FRAXURE,      SPECIES_HAXORUS,      SPECIES_NONE},
     {10,                   38,                  48,                    0 },
     {  0,                    6,                  12,                    0 },
     6,    0},

    {{SPECIES_BAGON,         SPECIES_SHELGON,      SPECIES_SALAMENCE,    SPECIES_NONE},
     { 8,                   30,                  50,                    0 },
     {  0,                    4,                   8,                    0 },
     5,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gWetlandPoolCount = ARRAY_COUNT(gWetlandPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                   POOL_MOUNTAIN: ROCK/FIGHTING/GROUND
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gMountainPool[] = {
    // Classic rock lines (high weight)
    {{SPECIES_GEODUDE,       SPECIES_GRAVELER,     SPECIES_GOLEM,        SPECIES_NONE},
     {  8,                   25,                  40,                    0 },
     {  0,                    4,                   8,                    0 },
     200,  0},

    {{SPECIES_GEODUDE_ALOLA, SPECIES_GRAVELER_ALOLA, SPECIES_GOLEM_ALOLA, SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     30,   0},

    {{SPECIES_SNEASEL_HISUI, SPECIES_SAMUROTT_HISUI, SPECIES_NONE,         SPECIES_NONE},
     { 10,                   35,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     25,   0},

    {{SPECIES_TYROGUE,       SPECIES_HITMONTOP,   SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     30,   0},

    {{SPECIES_SMOOCHUM,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  5,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     25,   0},

    {{SPECIES_ELEKID,        SPECIES_ELECTABUZZ, SPECIES_ELECTIVIRE, SPECIES_NONE},
     { 10,                   30,                  40,                    0 },
     {  0,                    4,                   8,                    0 },
     20,   0},

    {{SPECIES_MAGBY,         SPECIES_MAGMAR,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    {{SPECIES_MACHOP,        SPECIES_MACHOKE,     SPECIES_MACHAMP,      SPECIES_NONE},
     {  5,                   28,                  36,                    0 },
     {  0,                    3,                   6,                    0 },
     25,   0},

    {{SPECIES_ONIX,         SPECIES_STEELIX,      SPECIES_NONE,         SPECIES_NONE},
     {  8,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     180,  0},

    {{SPECIES_ARON,          SPECIES_LAIRON,       SPECIES_AGGRON,       SPECIES_NONE},
     {  6,                   18,                  42,                    0 },
     {  0,                    3,                   6,                    0 },
     160,  0},

    // Fighting lines (high weight)
    {{SPECIES_MANKEY,        SPECIES_PRIMEAPE,     SPECIES_NONE,         SPECIES_NONE},
     {  7,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     190,  0},

    {{SPECIES_MACHOP,        SPECIES_MACHOKE,      SPECIES_MACHAMP,      SPECIES_NONE},
     { 10,                   28,                  48,                    0 },
     {  0,                    5,                  12,                    0 },
     170,  0},

    {{SPECIES_MAKUHITA,      SPECIES_HARIYAMA,     SPECIES_AZURILL,      SPECIES_NONE},
     {  6,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     150,  0},

    {{SPECIES_NOSEPASS,       SPECIES_SKITTY,       SPECIES_DELCATTY,     SPECIES_SABLEYE},
     {  6,                   24,                  36,                  48 },
     {  0,                    3,                   5,                    7 },
     140,  0},

    // Rock/Ground hybrids (medium weight)
    {{SPECIES_ROCKRUFF,      SPECIES_LYCANROC,     SPECIES_NONE,         SPECIES_NONE},
     {  7,                   25,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     120,  0},

    {{SPECIES_ROGGENROLA,    SPECIES_BOLDORE,      SPECIES_GIGALITH,     SPECIES_NONE},
     {  6,                   24,                  42,                    0 },
     {  0,                    3,                   6,                    0 },
     100,  0},

    {{SPECIES_GLIGAR,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     80,   0},

    {{SPECIES_SKARMORY,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     70,   0},

    // Ground types (lower weight)
    {{SPECIES_RHYHORN,       SPECIES_RHYDON,       SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                  42,                    0 },
     {  0,                    4,                   6,                    0 },
     60,   0},

    // Special rock/steel types (lower weight)
    {{SPECIES_MEDITITE,      SPECIES_MEDICHAM,    SPECIES_ELECTRIKE,   SPECIES_MANECTRIC},
     {  6,                   24,                  36,                  48 },
     {  0,                    3,                   5,                   7 },
     50,   0},

    // Postgame pseudo-legendaries (very low weight, postgame)
    {{SPECIES_GIBLE,         SPECIES_GABITE,       SPECIES_GARCHOMP,     SPECIES_NONE},
     { 8,                   24,                  48,                    0 },
     {  0,                    4,                   6,                    0 },
     8,    0},

    {{SPECIES_SALAMENCE,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    8,                   0,                    0 },
     6,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gMountainPoolCount = ARRAY_COUNT(gMountainPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                        POOL_CAVE: BATS/ROCK/GROUND
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gCavePool[] = {
    // Classic bat lines (high weight)
    {{SPECIES_ZUBAT,         SPECIES_GOLBAT,       SPECIES_CROBAT,       SPECIES_NONE},
     {  5,                   22,                  36,                    0 },
     {  0,                    3,                   6,                    0 },
     200,  2},   // night bias

    {{SPECIES_WOOBAT,        SPECIES_SWOOBAT,     SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     140,  2},   // night bias

    {{SPECIES_NOIBAT,        SPECIES_NOIVERN,     SPECIES_NONE,         SPECIES_NONE},
     { 12,                   40,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     100,  2},   // night bias

    {{SPECIES_WOOBAT,        SPECIES_SWOOBAT,      SPECIES_NONE,         SPECIES_NONE},
     {  6,                   25,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     180,  0},

    // Ghost/Dark types (high weight)
    {{SPECIES_DUSKULL,       SPECIES_DUSCLOPS,    SPECIES_NONE,         SPECIES_NONE},
     {  6,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     160,  0},

    {{SPECIES_SABLEYE,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     140,  0},

    {{SPECIES_MISDREAVUS,    SPECIES_MISMAGIUS,    SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120,  0},

    // Rock/Ground types (medium weight)
    {{SPECIES_GEODUDE,       SPECIES_GRAVELER,     SPECIES_GOLEM,        SPECIES_NONE},
     {  5,                   20,                  40,                    0 },
     {  0,                    3,                   6,                    0 },
     100,  0},

    {{SPECIES_ONIX,         SPECIES_STEELIX,      SPECIES_NONE,         SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    4,                   6,                    0 },
     90,   0},

    {{SPECIES_ARON,          SPECIES_LAIRON,       SPECIES_AGGRON,       SPECIES_NONE},
     {  6,                   18,                  42,                    0 },
     {  0,                    3,                   6,                    0 },
     80,   0},

    {{SPECIES_ROGGENROLA,    SPECIES_BOLDORE,      SPECIES_GIGALITH,     SPECIES_NONE},
     {  6,                   20,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     70,   0},

    // Ghost/Fire types (lower weight)
    {{SPECIES_LITWICK,       SPECIES_LAMPENT,     SPECIES_CHANDELURE,    SPECIES_NONE},
     {  4,                   18,                  32,                    0 },
     {  0,                    2,                   4,                    0 },
     60,   0},

    {{SPECIES_GOLETT,        SPECIES_GOLURK,       SPECIES_PAWNIARD,     SPECIES_BISHARP},
     {  4,                   20,                  32,                  40 },
     {  0,                    2,                   4,                   6 },
     50,   0},

    // Special cave dwellers (lower weight)
    {{SPECIES_NOSEPASS,       SPECIES_SKITTY,       SPECIES_DELCATTY,     SPECIES_SABLEYE},
     {  4,                   20,                  32,                  40 },
     {  0,                    2,                   4,                   6 },
     40,   0},

    // Very rare encounters (postgame)
    {{SPECIES_DEINO,         SPECIES_ZWEILOUS,     SPECIES_HYDREIGON,    SPECIES_NONE},
     {  8,                   30,                  50,                    0 },
     {  0,                    4,                   8,                    0 },
     8,    0},

    {{SPECIES_BAGON,         SPECIES_SHELGON,      SPECIES_SALAMENCE,    SPECIES_NONE},
     { 8,                   30,                  50,                    0 },
     {  0,                    4,                   8,                    0 },
     6,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gCavePoolCount = ARRAY_COUNT(gCavePool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                    POOL_WATER: SURF & WATER
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gWaterPool[] = {
    // Common water lines (high weight)
    {{SPECIES_MAGIKARP,      SPECIES_GYARADOS,     SPECIES_NONE,         SPECIES_NONE},
     {  2,                   20,                  40,                    0 },
     {  0,                    2,                   6,                    0 },
     200,  0},

    {{SPECIES_WINGULL,       SPECIES_PELIPPER,    SPECIES_NONE,         SPECIES_NONE},
     {  3,                   25,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     180,  0},

    {{SPECIES_BUIZEL,        SPECIES_FLOATZEL,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   24,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     160,  0},

    {{SPECIES_HORSEA,        SPECIES_SEADRA,       SPECIES_NONE,         SPECIES_NONE},
     {  5,                   32,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     140,  0},

    {{SPECIES_GOLDEEN,       SPECIES_SEAKING,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120,  0},

    {{SPECIES_STARYU,        SPECIES_STARMIE,     SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     100,  0},

    {{SPECIES_SHELLDER,      SPECIES_CLOYSTER,    SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     90,   0},

    {{SPECIES_REMORAID,      SPECIES_OCTILLERY,   SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     80,   0},

    {{SPECIES_BASCULIN_RED_STRIPED, SPECIES_NONE,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_BASCULIN_BLUE_STRIPED, SPECIES_NONE,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_BASCULIN_WHITE_STRIPED, SPECIES_NONE,    SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_WOOPER_PALDEA, SPECIES_QUAGSIRE,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     20,   0},

    // Psychic water lines (medium weight)
    {{SPECIES_PSYDUCK,       SPECIES_GOLDUCK,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   28,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     140,  0},

    {{SPECIES_STARYU,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120,  0},

    // Special water types (medium weight)
    {{SPECIES_FEEBAS,        SPECIES_MILOTIC,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   35,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     100,  0},

    {{SPECIES_REMORAID,      SPECIES_OCTILLERY,   SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     90,   0},

    // Plant/water hybrids (lower weight)
    {{SPECIES_LOTAD,         SPECIES_LOMBRE,       SPECIES_LUDICOLO,     SPECIES_NONE},
     {  3,                   14,                  29,                    0 },
     {  0,                    1,                   4,                    0 },
     70,   0},

    {{SPECIES_SURSKIT,       SPECIES_MASQUERAIN,   SPECIES_NONE,         SPECIES_NONE},
     {  5,                   22,                   0,                    0 },
     {  0,                    2,                   0,                    0 },
     60,   0},

    // Rare encounters (very low weight)
    {{SPECIES_GOLDEEN,       SPECIES_SEAKING,     SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     30,   0},

    {{SPECIES_LUVDISC,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   40,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     20,   0},

    {{SPECIES_DRATINI,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  4,                    4,                   0,                    0 },
     15,   0},

    {{SPECIES_BARBOACH,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 20,                   30,                   0,                    0 },
     {  4,                    4,                   0,                    0 },
     10,   0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gWaterPoolCount = ARRAY_COUNT(gWaterPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                  POOL_POWERPLANT: ELECTRIC/STEEL HEAVY
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gPowerplantPool[] = {
    // Electric lines (high weight)
    {{SPECIES_MAGNETON,     SPECIES_MAGNEZONE,    SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     180,  0},

    {{SPECIES_ELEKID,       SPECIES_ELECTABUZZ, SPECIES_ELECTIVIRE, SPECIES_NONE},
     { 10,                   30,                  40,                    0 },
     {  0,                    4,                   8,                    0 },
     160,  0},

    {{SPECIES_PLUSLE,       SPECIES_MINUN,       SPECIES_NONE,         SPECIES_NONE},
     { 12,                   24,                  36,                    0 },
     {  0,                    4,                   6,                    0 },
     140,  0},

    {{SPECIES_JOLTIK,       SPECIES_GALVANTULA, SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                  40,                    0 },
     {  0,                    4,                   8,                    0 },
     120,  0},

    {{SPECIES_VOLTORB,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   10,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     180,  0},

    {{SPECIES_ELECTRIKE,     SPECIES_ELECTRODE,   SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     160,  0},

    // Steel lines (high weight)
    {{SPECIES_SHINX,         SPECIES_BLITZLE,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     180,  0},

    {{SPECIES_YAMPER,        SPECIES_PAWMI,       SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     160,  0},

    {{SPECIES_KLINK,         SPECIES_KLANG,       SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     140,  0},

    // Industrial/tech lines (medium weight)
    {{SPECIES_BRONZOR,      SPECIES_BRONZONG,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     120,  0},

    {{SPECIES_BELDUM,       SPECIES_METAGROSS,    SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     100,  0},

    {{SPECIES_ROLYCOLY,      SPECIES_ROLYCOLY,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   18,                  32,                    0 },
     {  0,                    3,                   5,                    0 },
     90,   0},

    {{SPECIES_FERROSEED,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     80,   0},

    // Special industrial types (lower weight)
    {{SPECIES_GRIMER,         SPECIES_MUK,          SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     70,   0},

    {{SPECIES_TRUBBISH,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     60,   0},

    {{SPECIES_PORYGON,       SPECIES_PORYGON2,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     50,   0},

    {{SPECIES_ROTOM,         SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     40,   0},

    // Very rare encounters (very low weight, postgame)
    {{SPECIES_METAGROSS,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  4,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gPowerplantPoolCount = ARRAY_COUNT(gPowerplantPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                      POOL_OLD_ROD: FISHING
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gOldRodPool[] = {
    {{SPECIES_MAGIKARP,      SPECIES_GYARADOS,     SPECIES_NONE,         SPECIES_NONE},
     {  5,                   20,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     400,  0},   // very common early

    {{SPECIES_FEEBAS,        SPECIES_MILOTIC,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   35,                   0,                    0 },
     {  0,                    8,                   0,                    0 },
     40,   0},   // rare early

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gOldRodPoolCount = ARRAY_COUNT(gOldRodPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//              POOL_GOOD_ROD & POOL_SUPER_ROD (stubs for now)
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gGoodRodPool[] = {
    // Medium-level water species (high weight)
    {{SPECIES_POLIWAG,       SPECIES_POLIWHIRL,    SPECIES_POLIWRATH,    SPECIES_NONE},
     {  8,                   24,                  30,                    0 },
     {  0,                    3,                   5,                    0 },
     180,  0},

    {{SPECIES_GOLDEEN,       SPECIES_SEAKING,     SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     160,  0},

    {{SPECIES_TENTACOOL,    SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     140,  0},

    // Special encounters (medium weight)
    {{SPECIES_HORSEA,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   25,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120,  0},

    {{SPECIES_CASTFORM_NORMAL, SPECIES_CASTFORM,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   20,                  30,                    0 },
     {  0,                    3,                   5,                    0 },
     100,  0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gGoodRodPoolCount = ARRAY_COUNT(gGoodRodPool) - 1;

const EvolutionLine gSuperRodPool[] = {
    // High-level water species (high weight)
    {{SPECIES_GYARADOS,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 20,                   40,                   0,                    0 },
     {  0,                    8,                   0,                    0 },
     200,  0},

    {{SPECIES_LUVDISC,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   40,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     180,  0},

    // Rare water species (medium weight)
    {{SPECIES_BARBOACH,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 20,                   30,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     120,  0},

    {{SPECIES_FEEBAS,        SPECIES_MILOTIC,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   35,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     100,  0},

    {{SPECIES_DRATINI,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                   0,                    0 },
     {  4,                    4,                   0,                    0 },
     80,   0},

    // Special encounters (lower weight)
    {{SPECIES_REMORAID,     SPECIES_OCTILLERY,   SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     60,   0},

    {{SPECIES_OCTILLERY,    SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     50,   0},

    // Very rare encounters (very low weight)
    {{SPECIES_MILOTIC,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 35,                   35,                   0,                    0 },
     {  4,                    4,                   0,                    0 },
     30,   0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gSuperRodPoolCount = ARRAY_COUNT(gSuperRodPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//              POOL_TANOBY_RUINS (Unown-only ancient ruins)
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gTanobyRuinsPool[] = {
    // All Unown forms with equal weight for variety
    {{SPECIES_UNOWN,           SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_B,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_C,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_D,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_E,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_F,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_G,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_H,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_I,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_J,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_K,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_L,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_M,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_N,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_O,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_P,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_Q,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_R,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_S,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_T,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_U,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_V,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_W,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_X,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_Y,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_Z,         SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                      0,           0,           0 },
     { 0,                      0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_EXCLAMATION, SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                        0,           0,           0 },
     { 0,                        0,           0,           0 },
     100, 0},

    {{SPECIES_UNOWN_QUESTION,    SPECIES_NONE, SPECIES_NONE, SPECIES_NONE},
     { 5,                        0,           0,           0 },
     { 0,                        0,           0,           0 },
     100, 0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gTanobyRuinsPoolCount = ARRAY_COUNT(gTanobyRuinsPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//              POOL_RUINS_OF_ALPH (Ancient fossil ruins - Johto)
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gRuinsOfAlphPool[] = {
    // Classic fossil lines (high weight)
    {{SPECIES_OMANYTE,       SPECIES_OMASTAR,      SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     200, 0},

    {{SPECIES_KABUTO,        SPECIES_KABUTOPS,     SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     200, 0},

    {{SPECIES_AERODACTYL,    SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   0,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     180, 0},

    // Gen 3 fossil lines (medium weight)
    {{SPECIES_ANORITH,       SPECIES_ARMALDO,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     150, 0},

    {{SPECIES_LILEEP,        SPECIES_CRADILY,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     150, 0},

    // Ancient relic species (medium weight)
    {{SPECIES_RELICANTH,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   0,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     120, 0},

    {{SPECIES_CRANIDOS,      SPECIES_RAMPARDOS,    SPECIES_NONE,         SPECIES_NONE},
     { 12,                   36,                   0,                    0 },
     {  0,                    7,                   0,                    0 },
     100, 0},

    {{SPECIES_SHIELDON,      SPECIES_BASTIODON,    SPECIES_NONE,         SPECIES_NONE},
     { 12,                   36,                   0,                    0 },
     {  0,                    7,                   0,                    0 },
     100, 0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gRuinsOfAlphPoolCount = ARRAY_COUNT(gRuinsOfAlphPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//              POOL_SOLACEON_RUINS (Ancient fossil ruins - Sinnoh)
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gSolaceonRuinsPool[] = {
    // Gen 5 fossil lines (high weight)
    {{SPECIES_ARCHEN,        SPECIES_ARCHEOPS,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   35,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     200, 0},

    {{SPECIES_TIRTOUGA,      SPECIES_CARRACOSTA,    SPECIES_NONE,         SPECIES_NONE},
     { 10,                   35,                   0,                    0 },
     {  0,                    6,                   0,                    0 },
     200, 0},

    // Gen 8 fossil lines (high weight)
    {{SPECIES_DRACOZOLT,    SPECIES_NONE,          SPECIES_NONE,         SPECIES_NONE},
     { 15,                   0,                   0,                    0 },
     {  0,                    7,                   0,                    0 },
     180, 0},

    {{SPECIES_ARCTOZOLT,    SPECIES_NONE,          SPECIES_NONE,         SPECIES_NONE},
     { 15,                   0,                   0,                    0 },
     {  0,                    7,                   0,                    0 },
     180, 0},

    {{SPECIES_DRACOVISH,    SPECIES_NONE,          SPECIES_NONE,         SPECIES_NONE},
     { 15,                   0,                   0,                    0 },
     {  0,                    7,                   0,                    0 },
     180, 0},

    {{SPECIES_ARCTOVISH,    SPECIES_NONE,          SPECIES_NONE,         SPECIES_NONE},
     { 15,                   0,                   0,                    0 },
     {  0,                    7,                   0,                    0 },
     180, 0},

    // Ancient ice/rock lines (medium weight)
    {{SPECIES_TYRUNT,        SPECIES_TYRANTRUM,     SPECIES_NONE,         SPECIES_NONE},
     { 12,                   38,                   0,                    0 },
     {  0,                    8,                   0,                    0 },
     150, 0},

    {{SPECIES_AMAURA,        SPECIES_AURORUS,       SPECIES_NONE,         SPECIES_NONE},
     { 12,                   38,                   0,                    0 },
     {  0,                    8,                   0,                    0 },
     150, 0},

    // Classic ancient species (lower weight)
    {{SPECIES_OMANYTE,       SPECIES_OMASTAR,      SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     100, 0},

    {{SPECIES_KABUTO,        SPECIES_KABUTOPS,     SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    5,                   0,                    0 },
     100, 0},

    {{SPECIES_RELICANTH,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   0,                   0,                    0 },
     {  0,                    4,                   0,                    0 },
     80, 0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gSolaceonRuinsPoolCount = ARRAY_COUNT(gSolaceonRuinsPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//                        POOL_SNOW: ICE/SNOW AREAS
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine gSnowPool[] = {
    // Ice lines (high weight)
    {{SPECIES_SWINUB,        SPECIES_PILOSWINE,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     200,  0},

    {{SPECIES_MAMOSWINE,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     180,  0},

    {{SPECIES_SNOVER,         SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                  0,                    0 },
     {  0,                    4,                   0,                    0 },
     160,  0},

    // Snow/ice hybrids (medium weight)
    {{SPECIES_ABOMASNOW,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     140,  0},

    {{SPECIES_SEALEO,       SPECIES_SEALEO,      SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                  36,                    0 },
     {  0,                    4,                   6,                    0 },
     120,  0},

    {{SPECIES_WALREIN,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     100,  0},

    {{SPECIES_CUBCHOO,       SPECIES_BEARTIC,     SPECIES_NONE,         SPECIES_NONE},
     {  6,                   18,                  32,                    0 },
     {  0,                    3,                   5,                    0 },
     90,   0},

    {{SPECIES_SNOM,          SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     80,   0},

    // Special ice/rock types (lower weight)
    {{SPECIES_SEALEO,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                  0,                    0 },
     {  0,                    4,                   0,                    0 },
     70,   0},

    {{SPECIES_BERGMITE,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                  0,                    0 },
     {  0,                    4,                   0,                    0 },
     60,   0},

    {{SPECIES_AVALUGG,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     50,   0},

    {{SPECIES_VULPIX_ALOLA,  SPECIES_NINETALES_ALOLA, SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                  0,                    0 },
     {  0,                    4,                   0,                    0 },
     30,   0},

    {{SPECIES_SANDSHREW_ALOLA, SPECIES_SANDSLASH_ALOLA, SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                  0,                    0 },
     {  0,                    4,                   0,                    0 },
     30,   0},

    // Very rare encounters (very low weight, postgame)
    {{SPECIES_GLACEON,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 20,                   40,                   0,                    0 },
     {  0,                    8,                   0,                    0 },
     30,   0},

    {{SPECIES_FRIGIBAX,      SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   30,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     20,   0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gSnowPoolCount = ARRAY_COUNT(gSnowPool) - 1;

// ══════════════════════════════════════════════════════════════════════════
//                    POOL_GRAVEYARD: GHOST/DARK/CRYPTIC
// ══════════════════════════════════════════════════════════════════════════

const EvolutionLine gGraveyardPool[] = {
    // Ghost/Dark core lines (high weight)
    {{SPECIES_GASTLY,         SPECIES_HAUNTER,     SPECIES_GENGAR,       SPECIES_NONE},
     {   8,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     200,  0},

    {{SPECIES_MISMAGIUS,    SPECIES_MISMAGIUS,    SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     180,  0},

    {{SPECIES_DUSKULL,       SPECIES_DUSCLOPS,    SPECIES_NONE,         SPECIES_NONE},
     {  6,                   24,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     160,  0},

    {{SPECIES_MURKROW,       SPECIES_HONCHKROW,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                  36,                    0 },
     {  0,                    4,                   8,                    0 },
     140,  0},

    {{SPECIES_ZORUA,         SPECIES_ZOROARK,     SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     120,  0},

    {{SPECIES_ZOROARK,       SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     100,  0},

    // Dark/sinister lines (medium weight)
    {{SPECIES_HONCHKROW,       SPECIES_UMBREON,    SPECIES_NONE,         SPECIES_NONE},
     { 10,                   30,                  36,                    0 },
     {  0,                    4,                   8,                    0 },
     140, 0},

    {{SPECIES_UMBREON,       SPECIES_PAWNIARD,     SPECIES_BISHARP,       SPECIES_NONE},
     { 10,                   30,                  36,                    0 },
     {  0,                    4,                   8,                    0 },
     120, 0},

    {{SPECIES_YAMASK,         SPECIES_COFAGRIGUS,   SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                  36,                    0 },
     {  0,                    3,                   5,                    0 },
     100,  0},

    {{SPECIES_YAMASK_GALAR,  SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {  8,                   30,                   0,                    0 },
     {  0,                    3,                   0,                    0 },
     80,   0},

    {{SPECIES_ZORUA_HISUI,   SPECIES_ZOROARK_HISUI, SPECIES_NONE,         SPECIES_NONE},
     { 10,                   32,                  48,                    0 },
     {  0,                    4,                   8,                    0 },
     70,   0},

    // Ghost/fire lines (lower weight)
    {{SPECIES_LITWICK,       SPECIES_LAMPENT,     SPECIES_CHANDELURE,    SPECIES_NONE},
     {   4,                   18,                  32,                    0 },
     {  0,                    2,                   4,                    0 },
     60,   0},

    {{SPECIES_PHANTUMP,      SPECIES_TREVENANT,    SPECIES_NONE,         SPECIES_NONE},
     {  8,                   26,                  32,                    0 },
     {  0,                    3,                   5,                    0 },
     50,   0},

    {{SPECIES_SPIRITOMB,     SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 12,                   32,                  0,                    0 },
     {  0,                    4,                   0,                    0 },
     40,   0},

    // Cryptic/eerie species (lower weight)
    {{SPECIES_GOLETT,        SPECIES_GOLURK,       SPECIES_PAWNIARD,     SPECIES_BISHARP},
     {    4,                   20,                  32,                  40 },
     {  0,                    2,                   4,                   6 },
     50,   0},

    {{SPECIES_SABLEYE,        SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     {   8,                   30,                  0,                    0 },
     {  0,                    4,                   0,                    0 },
     30,   0},

    // Very rare encounters (very low weight, postgame)
    {{SPECIES_GENGAR,         SPECIES_NONE,         SPECIES_NONE,         SPECIES_NONE},
     { 15,                   15,                  0,                    0 },
     {  4,                    4,                   0,                    0 },
     8,    0},

    {{SPECIES_NONE}, {0}, {0}, 0, 0}
};

const u32 gGraveyardPoolCount = ARRAY_COUNT(gGraveyardPool) - 1;

// ════════════════════════════════════════════════════════════════════════════
//        POOL ARRAY: Maps WildPoolType to the actual pools
// ════════════════════════════════════════════════════════════════════════════

const EvolutionLine *const gWildPools[NUM_WILD_POOLS] = {
    [POOL_GRASS]      = gGrassPool,
    [POOL_FOREST]     = gForestPool,
    [POOL_VOLCANO]    = gVolcanoPool,
    [POOL_WETLAND]    = gWetlandPool,
    [POOL_MOUNTAIN]   = gMountainPool,
    [POOL_CAVE]       = gCavePool,
    [POOL_WATER]      = gWaterPool,
    [POOL_POWERPLANT] = gPowerplantPool,
    [POOL_OLD_ROD]    = gOldRodPool,
    [POOL_GOOD_ROD]   = gGoodRodPool,
    [POOL_SUPER_ROD]  = gSuperRodPool,
    [POOL_SNOW]       = gSnowPool,
    [POOL_GRAVEYARD] = gGraveyardPool,
    [POOL_TANOBY_RUINS] = gTanobyRuinsPool,
    [POOL_RUINS_OF_ALPH] = gRuinsOfAlphPool,
    [POOL_SOLACEON_RUINS] = gSolaceonRuinsPool,
};

// Pool counts (must match array size - 1 for terminator)
const u32 gWildPoolCounts[NUM_WILD_POOLS] = {
    [POOL_GRASS]      = ARRAY_COUNT(gGrassPool) - 1,
    [POOL_FOREST]     = ARRAY_COUNT(gForestPool) - 1,
    [POOL_VOLCANO]    = ARRAY_COUNT(gVolcanoPool) - 1,
    [POOL_WETLAND]    = ARRAY_COUNT(gWetlandPool) - 1,
    [POOL_MOUNTAIN]   = ARRAY_COUNT(gMountainPool) - 1,
    [POOL_CAVE]       = ARRAY_COUNT(gCavePool) - 1,
    [POOL_WATER]      = ARRAY_COUNT(gWaterPool) - 1,
    [POOL_POWERPLANT] = ARRAY_COUNT(gPowerplantPool) - 1,
    [POOL_OLD_ROD]    = ARRAY_COUNT(gOldRodPool) - 1,
    [POOL_GOOD_ROD]   = ARRAY_COUNT(gGoodRodPool) - 1,
    [POOL_SUPER_ROD]  = ARRAY_COUNT(gSuperRodPool) - 1,
    [POOL_SNOW]       = ARRAY_COUNT(gSnowPool) - 1,
    [POOL_GRAVEYARD] = ARRAY_COUNT(gGraveyardPool) - 1,
    [POOL_TANOBY_RUINS] = ARRAY_COUNT(gTanobyRuinsPool) - 1,
    [POOL_RUINS_OF_ALPH] = ARRAY_COUNT(gRuinsOfAlphPool) - 1,
    [POOL_SOLACEON_RUINS] = ARRAY_COUNT(gSolaceonRuinsPool) - 1,
};
