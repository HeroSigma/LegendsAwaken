#include "fieldmap.h"

// Whether a palette has a night version, located at ((x + 9) % 16).pal
#define SWAP_PAL(x) ((x) < NUM_PALS_IN_PRIMARY ? 1 << (x) : 1 << ((x) - NUM_PALS_IN_PRIMARY))

const struct Tileset gTileset_General =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General,
    .palettes = gTilesetPalettes_General,
    .metatiles = gMetatiles_General,
    .metatileAttributes = gMetatileAttributes_General,
    .callback = InitTilesetAnim_General,
};

const struct Tileset gTileset_Petalburg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Petalburg,
    .palettes = gTilesetPalettes_Petalburg,
    .metatiles = gMetatiles_Petalburg,
    .metatileAttributes = gMetatileAttributes_Petalburg,
    .callback = InitTilesetAnim_Petalburg,
};

const struct Tileset gTileset_Rustboro =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Rustboro,
    .palettes = gTilesetPalettes_Rustboro,
    .metatiles = gMetatiles_Rustboro,
    .metatileAttributes = gMetatileAttributes_Rustboro,
    .callback = InitTilesetAnim_Rustboro,
};

const struct Tileset gTileset_Dewford =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Dewford,
    .palettes = gTilesetPalettes_Dewford,
    .metatiles = gMetatiles_Dewford,
    .metatileAttributes = gMetatileAttributes_Dewford,
    .callback = InitTilesetAnim_Dewford,
};

const struct Tileset gTileset_Slateport =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Slateport,
    .palettes = gTilesetPalettes_Slateport,
    .metatiles = gMetatiles_Slateport,
    .metatileAttributes = gMetatileAttributes_Slateport,
    .callback = InitTilesetAnim_Slateport,
};

const struct Tileset gTileset_Mauville =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mauville,
    .palettes = gTilesetPalettes_Mauville,
    .metatiles = gMetatiles_Mauville,
    .metatileAttributes = gMetatileAttributes_Mauville,
    .callback = InitTilesetAnim_Mauville,
};

const struct Tileset gTileset_Lavaridge =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lavaridge,
    .palettes = gTilesetPalettes_Lavaridge,
    .metatiles = gMetatiles_Lavaridge,
    .metatileAttributes = gMetatileAttributes_Lavaridge,
    .callback = InitTilesetAnim_Lavaridge,
};

const struct Tileset gTileset_Fallarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fallarbor,
    .palettes = gTilesetPalettes_Fallarbor,
    .metatiles = gMetatiles_Fallarbor,
    .metatileAttributes = gMetatileAttributes_Fallarbor,
    .callback = InitTilesetAnim_Fallarbor,
};

const struct Tileset gTileset_Fortree =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fortree,
    .palettes = gTilesetPalettes_Fortree,
    .metatiles = gMetatiles_Fortree,
    .metatileAttributes = gMetatileAttributes_Fortree,
    .callback = InitTilesetAnim_Fortree,
};

const struct Tileset gTileset_Lilycove =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lilycove,
    .palettes = gTilesetPalettes_Lilycove,
    .metatiles = gMetatiles_Lilycove,
    .metatileAttributes = gMetatileAttributes_Lilycove,
    .callback = InitTilesetAnim_Lilycove,
};

const struct Tileset gTileset_Mossdeep =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mossdeep,
    .palettes = gTilesetPalettes_Mossdeep,
    .metatiles = gMetatiles_Mossdeep,
    .metatileAttributes = gMetatileAttributes_Mossdeep,
    .callback = InitTilesetAnim_Mossdeep,
};

const struct Tileset gTileset_EverGrande =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EverGrande,
    .palettes = gTilesetPalettes_EverGrande,
    .metatiles = gMetatiles_EverGrande,
    .metatileAttributes = gMetatileAttributes_EverGrande,
    .callback = InitTilesetAnim_EverGrande,
};

const struct Tileset gTileset_Pacifidlog =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Pacifidlog,
    .palettes = gTilesetPalettes_Pacifidlog,
    .metatiles = gMetatiles_Pacifidlog,
    .metatileAttributes = gMetatileAttributes_Pacifidlog,
    .callback = InitTilesetAnim_Pacifidlog,
};

const struct Tileset gTileset_Sootopolis =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Sootopolis,
    .palettes = gTilesetPalettes_Sootopolis,
    .metatiles = gMetatiles_Sootopolis,
    .metatileAttributes = gMetatileAttributes_Sootopolis,
    .callback = InitTilesetAnim_Sootopolis,
};

const struct Tileset gTileset_BattleFrontierOutsideWest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideWest,
    .palettes = gTilesetPalettes_BattleFrontierOutsideWest,
    .metatiles = gMetatiles_BattleFrontierOutsideWest,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideWest,
    .callback = InitTilesetAnim_BattleFrontierOutsideWest,
};

const struct Tileset gTileset_BattleFrontierOutsideEast =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideEast,
    .palettes = gTilesetPalettes_BattleFrontierOutsideEast,
    .metatiles = gMetatiles_BattleFrontierOutsideEast,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideEast,
    .callback = InitTilesetAnim_BattleFrontierOutsideEast,
};

const struct Tileset gTileset_Building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_InsideBuilding,
    .palettes = gTilesetPalettes_InsideBuilding,
    .metatiles = gMetatiles_InsideBuilding,
    .metatileAttributes = gMetatileAttributes_InsideBuilding,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_Shop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Shop,
    .palettes = gTilesetPalettes_Shop,
    .metatiles = gMetatiles_Shop,
    .metatileAttributes = gMetatileAttributes_Shop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenter =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter,
    .palettes = gTilesetPalettes_PokemonCenter,
    .metatiles = gMetatiles_PokemonCenter,
    .metatileAttributes = gMetatileAttributes_PokemonCenter,
    .callback = NULL,
};

const struct Tileset gTileset_Cave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave,
    .palettes = gTilesetPalettes_Cave,
    .metatiles = gMetatiles_Cave,
    .metatileAttributes = gMetatileAttributes_Cave,
    .callback = InitTilesetAnim_Cave,
};

const struct Tileset gTileset_PokemonSchool =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonSchool,
    .palettes = gTilesetPalettes_PokemonSchool,
    .metatiles = gMetatiles_PokemonSchool,
    .metatileAttributes = gMetatileAttributes_PokemonSchool,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonFanClub =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonFanClub,
    .palettes = gTilesetPalettes_PokemonFanClub,
    .metatiles = gMetatiles_PokemonFanClub,
    .metatileAttributes = gMetatileAttributes_PokemonFanClub,
    .callback = NULL,
};

const struct Tileset gTileset_Unused1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused1,
    .palettes = gTilesetPalettes_Unused1,
    .metatiles = gMetatiles_Unused1,
    .metatileAttributes = gMetatileAttributes_Unused1,
    .callback = NULL,
};

const struct Tileset gTileset_MeteorFalls =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MeteorFalls,
    .palettes = gTilesetPalettes_MeteorFalls,
    .metatiles = gMetatiles_MeteorFalls,
    .metatileAttributes = gMetatileAttributes_MeteorFalls,
    .callback = NULL,
};

const struct Tileset gTileset_OceanicMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OceanicMuseum,
    .palettes = gTilesetPalettes_OceanicMuseum,
    .metatiles = gMetatiles_OceanicMuseum,
    .metatileAttributes = gMetatileAttributes_OceanicMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_CableClub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClub,
    .palettes = gTilesetPalettes_CableClub,
    .metatiles = gMetatiles_CableClub,
    .metatileAttributes = gMetatileAttributes_CableClub,
    .callback = NULL,
};

const struct Tileset gTileset_SeashoreHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeashoreHouse,
    .palettes = gTilesetPalettes_SeashoreHouse,
    .metatiles = gMetatiles_SeashoreHouse,
    .metatileAttributes = gMetatileAttributes_SeashoreHouse,
    .callback = NULL,
};

const struct Tileset gTileset_PrettyPetalFlowerShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PrettyPetalFlowerShop,
    .palettes = gTilesetPalettes_PrettyPetalFlowerShop,
    .metatiles = gMetatiles_PrettyPetalFlowerShop,
    .metatileAttributes = gMetatileAttributes_PrettyPetalFlowerShop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonDayCare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonDayCare,
    .palettes = gTilesetPalettes_PokemonDayCare,
    .metatiles = gMetatiles_PokemonDayCare,
    .metatileAttributes = gMetatileAttributes_PokemonDayCare,
    .callback = NULL,
};

const struct Tileset gTileset_Facility =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Facility,
    .palettes = gTilesetPalettes_Facility,
    .metatiles = gMetatiles_Facility,
    .metatileAttributes = gMetatileAttributes_Facility,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop,
    .palettes = gTilesetPalettes_BikeShop,
    .metatiles = gMetatiles_BikeShop,
    .metatileAttributes = gMetatileAttributes_BikeShop,
    .callback = InitTilesetAnim_BikeShop,
};

const struct Tileset gTileset_RusturfTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RusturfTunnel,
    .palettes = gTilesetPalettes_RusturfTunnel,
    .metatiles = gMetatiles_RusturfTunnel,
    .metatileAttributes = gMetatileAttributes_RusturfTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBrownCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBrownCave,
    .palettes = gTilesetPalettes_SecretBaseBrownCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseTree =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseTree,
    .palettes = gTilesetPalettes_SecretBaseTree,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseShrub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseShrub,
    .palettes = gTilesetPalettes_SecretBaseShrub,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBlueCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBlueCave,
    .palettes = gTilesetPalettes_SecretBaseBlueCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseYellowCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseYellowCave,
    .palettes = gTilesetPalettes_SecretBaseYellowCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseRedCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseRedCave,
    .palettes = gTilesetPalettes_SecretBaseRedCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_InsideOfTruck =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideOfTruck,
    .palettes = gTilesetPalettes_InsideOfTruck,
    .metatiles = gMetatiles_InsideOfTruck,
    .metatileAttributes = gMetatileAttributes_InsideOfTruck,
    .callback = NULL,
};

const struct Tileset gTileset_Unused2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused2,
    .palettes = gTilesetPalettes_Unused2,
    .metatiles = gMetatiles_Unused2,
    .metatileAttributes = gMetatileAttributes_Unused2,
    .callback = NULL,
};

const struct Tileset gTileset_Contest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Contest,
    .palettes = gTilesetPalettes_Contest,
    .metatiles = gMetatiles_Contest,
    .metatileAttributes = gMetatileAttributes_Contest,
    .callback = NULL,
};

const struct Tileset gTileset_LilycoveMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LilycoveMuseum,
    .palettes = gTilesetPalettes_LilycoveMuseum,
    .metatiles = gMetatiles_LilycoveMuseum,
    .metatileAttributes = gMetatileAttributes_LilycoveMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_BrendansMaysHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BrendansMaysHouse,
    .palettes = gTilesetPalettes_BrendansMaysHouse,
    .metatiles = gMetatiles_BrendansMaysHouse,
    .metatileAttributes = gMetatileAttributes_BrendansMaysHouse,
    .callback = NULL,
};

const struct Tileset gTileset_Lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lab,
    .palettes = gTilesetPalettes_Lab,
    .metatiles = gMetatiles_Lab,
    .metatileAttributes = gMetatileAttributes_Lab,
    .callback = NULL,
};

const struct Tileset gTileset_Underwater =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Underwater,
    .palettes = gTilesetPalettes_Underwater,
    .metatiles = gMetatiles_Underwater,
    .metatileAttributes = gMetatileAttributes_Underwater,
    .callback = InitTilesetAnim_Underwater,
};

const struct Tileset gTileset_PetalburgGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PetalburgGym,
    .palettes = gTilesetPalettes_PetalburgGym,
    .metatiles = gMetatiles_PetalburgGym,
    .metatileAttributes = gMetatileAttributes_PetalburgGym,
    .callback = NULL,
};

const struct Tileset gTileset_SootopolisGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootopolisGym,
    .palettes = gTilesetPalettes_SootopolisGym,
    .metatiles = gMetatiles_SootopolisGym,
    .metatileAttributes = gMetatileAttributes_SootopolisGym,
    .callback = InitTilesetAnim_SootopolisGym,
};

const struct Tileset gTileset_GenericBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding,
    .palettes = gTilesetPalettes_GenericBuilding,
    .metatiles = gMetatiles_GenericBuilding,
    .metatileAttributes = gMetatileAttributes_GenericBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGameCorner,
    .palettes = gTilesetPalettes_MauvilleGameCorner,
    .metatiles = gMetatiles_MauvilleGameCorner,
    .metatileAttributes = gMetatileAttributes_MauvilleGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_RustboroGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RustboroGym,
    .palettes = gTilesetPalettes_RustboroGym,
    .metatiles = gMetatiles_RustboroGym,
    .metatileAttributes = gMetatileAttributes_RustboroGym,
    .callback = NULL,
};

const struct Tileset gTileset_DewfordGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DewfordGym,
    .palettes = gTilesetPalettes_DewfordGym,
    .metatiles = gMetatiles_DewfordGym,
    .metatileAttributes = gMetatileAttributes_DewfordGym,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGym,
    .palettes = gTilesetPalettes_MauvilleGym,
    .metatiles = gMetatiles_MauvilleGym,
    .metatileAttributes = gMetatileAttributes_MauvilleGym,
    .callback = InitTilesetAnim_MauvilleGym,
};

const struct Tileset gTileset_LavaridgeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavaridgeGym,
    .palettes = gTilesetPalettes_LavaridgeGym,
    .metatiles = gMetatiles_LavaridgeGym,
    .metatileAttributes = gMetatileAttributes_LavaridgeGym,
    .callback = NULL,
};

const struct Tileset gTileset_TrickHousePuzzle =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrickHousePuzzle,
    .palettes = gTilesetPalettes_TrickHousePuzzle,
    .metatiles = gMetatiles_TrickHousePuzzle,
    .metatileAttributes = gMetatileAttributes_TrickHousePuzzle,
    .callback = NULL,
};

const struct Tileset gTileset_FortreeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FortreeGym,
    .palettes = gTilesetPalettes_FortreeGym,
    .metatiles = gMetatiles_FortreeGym,
    .metatileAttributes = gMetatileAttributes_FortreeGym,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGym,
    .palettes = gTilesetPalettes_MossdeepGym,
    .metatiles = gMetatiles_MossdeepGym,
    .metatileAttributes = gMetatileAttributes_MossdeepGym,
    .callback = NULL,
};

const struct Tileset gTileset_InsideShip =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideShip,
    .palettes = gTilesetPalettes_InsideShip,
    .metatiles = gMetatiles_InsideShip,
    .metatileAttributes = gMetatileAttributes_InsideShip,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBase =
{
    .isCompressed = FALSE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SecretBase,
    .palettes = gTilesetPalettes_SecretBase,
    .metatiles = gMetatiles_SecretBasePrimary,
    .metatileAttributes = gMetatileAttributes_SecretBasePrimary,
    .callback = NULL,
};

const struct Tileset *const gTilesetPointer_SecretBase = &gTileset_SecretBase;
const struct Tileset *const gTilesetPointer_SecretBaseRedCave = &gTileset_SecretBaseRedCave;

const struct Tileset gTileset_EliteFour =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EliteFour,
    .palettes = gTilesetPalettes_EliteFour,
    .metatiles = gMetatiles_EliteFour,
    .metatileAttributes = gMetatileAttributes_EliteFour,
    .callback = InitTilesetAnim_EliteFour,
};

const struct Tileset gTileset_BattleFrontier =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontier,
    .palettes = gTilesetPalettes_BattleFrontier,
    .metatiles = gMetatiles_BattleFrontier,
    .metatileAttributes = gMetatileAttributes_BattleFrontier,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePalace =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePalace,
    .palettes = gTilesetPalettes_BattlePalace,
    .metatiles = gMetatiles_BattlePalace,
    .metatileAttributes = gMetatileAttributes_BattlePalace,
    .callback = NULL,
};

const struct Tileset gTileset_BattleDome =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleDome,
    .palettes = gTilesetPalettes_BattleDome,
    .metatiles = gMetatiles_BattleDome,
    .metatileAttributes = gMetatileAttributes_BattleDome,
    .callback = InitTilesetAnim_BattleDome,
};

const struct Tileset gTileset_BattleFactory =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFactory,
    .palettes = gTilesetPalettes_BattleFactory,
    .metatiles = gMetatiles_BattleFactory,
    .metatileAttributes = gMetatileAttributes_BattleFactory,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePike =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePike,
    .palettes = gTilesetPalettes_BattlePike,
    .metatiles = gMetatiles_BattlePike,
    .metatileAttributes = gMetatileAttributes_BattlePike,
    .callback = NULL,
};

const struct Tileset gTileset_BattleArena =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleArena,
    .palettes = gTilesetPalettes_BattleArena,
    .metatiles = gMetatiles_BattleArena,
    .metatileAttributes = gMetatileAttributes_BattleArena,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePyramid =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePyramid,
    .palettes = gTilesetPalettes_BattlePyramid,
    .metatiles = gMetatiles_BattlePyramid,
    .metatileAttributes = gMetatileAttributes_BattlePyramid,
    .callback = InitTilesetAnim_BattlePyramid,
};

const struct Tileset gTileset_MirageTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MirageTower,
    .palettes = gTilesetPalettes_MirageTower,
    .metatiles = gMetatiles_MirageTower,
    .metatileAttributes = gMetatileAttributes_MirageTower,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGameCorner,
    .palettes = gTilesetPalettes_MossdeepGameCorner,
    .metatiles = gMetatiles_MossdeepGameCorner,
    .metatileAttributes = gMetatileAttributes_MossdeepGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_IslandHarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IslandHarbor,
    .palettes = gTilesetPalettes_IslandHarbor,
    .metatiles = gMetatiles_IslandHarbor,
    .metatileAttributes = gMetatileAttributes_IslandHarbor,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerHill =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerHill,
    .palettes = gTilesetPalettes_TrainerHill,
    .metatiles = gMetatiles_TrainerHill,
    .metatileAttributes = gMetatileAttributes_TrainerHill,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRock =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRock,
    .palettes = gTilesetPalettes_NavelRock,
    .metatiles = gMetatiles_NavelRock,
    .metatileAttributes = gMetatileAttributes_NavelRock,
    .callback = NULL,
};

const struct Tileset gTileset_BattleFrontierRankingHall =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierRankingHall,
    .palettes = gTilesetPalettes_BattleFrontierRankingHall,
    .metatiles = gMetatiles_BattleFrontierRankingHall,
    .metatileAttributes = gMetatileAttributes_BattleFrontierRankingHall,
    .callback = NULL,
};

const struct Tileset gTileset_BattleTent =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleTent,
    .palettes = gTilesetPalettes_BattleTent,
    .metatiles = gMetatiles_BattleTent,
    .metatileAttributes = gMetatileAttributes_BattleTent,
    .callback = NULL,
};

const struct Tileset gTileset_MysteryEventsHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MysteryEventsHouse,
    .palettes = gTilesetPalettes_MysteryEventsHouse,
    .metatiles = gMetatiles_MysteryEventsHouse,
    .metatileAttributes = gMetatileAttributes_MysteryEventsHouse,
    .callback = NULL,
};

const struct Tileset gTileset_UnionRoom =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnionRoom,
    .palettes = gTilesetPalettes_UnionRoom,
    .metatiles = gMetatiles_UnionRoom,
    .metatileAttributes = gMetatileAttributes_UnionRoom,
    .callback = NULL,
};

const struct Tileset gTileset_KantoGeneral =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_KantoGeneral,
    .palettes = gTilesetPalettes_KantoGeneral,
    .metatiles = gMetatiles_KantoGeneral,
    .metatileAttributes = gMetatileAttributes_KantoGeneral,
    .callback = InitTilesetAnim_KantoGeneral,
};

const struct Tileset gTileset_JohtoGeneral =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_JohtoGeneral,
    .palettes = gTilesetPalettes_JohtoGeneral,
    .metatiles = gMetatiles_JohtoGeneral,
    .metatileAttributes = gMetatileAttributes_JohtoGeneral,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_SinnohGeneral =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SinnohGeneral,
    .palettes = gTilesetPalettes_SinnohGeneral,
    .metatiles = gMetatiles_SinnohGeneral,
    .metatileAttributes = gMetatileAttributes_SinnohGeneral,
    .callback = InitTilesetAnim_SinnohGeneral,
};

const struct Tileset gTileset_KantoBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_KantoBuilding,
    .palettes = gTilesetPalettes_KantoBuilding,
    .metatiles = gMetatiles_KantoBuilding,
    .metatileAttributes = gMetatileAttributes_KantoBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_JohtoBuilding,
    .palettes = gTilesetPalettes_JohtoBuilding,
    .metatiles = gMetatiles_JohtoBuilding,
    .metatileAttributes = gMetatileAttributes_JohtoBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_SinnohBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SinnohBuilding,
    .palettes = gTilesetPalettes_SinnohBuilding,
    .metatiles = gMetatiles_SinnohBuilding,
    .metatileAttributes = gMetatileAttributes_SinnohBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_SinnohOutdoor =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SinnohOutdoor,
    .palettes = gTilesetPalettes_SinnohOutdoor,
    .metatiles = gMetatiles_SinnohOutdoor,
    .metatileAttributes = gMetatileAttributes_SinnohOutdoor,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonCity,
    .palettes = gTilesetPalettes_CeladonCity,
    .metatiles = gMetatiles_CeladonCity,
    .metatileAttributes = gMetatileAttributes_CeladonCity,
    .callback = NULL,
};

const struct Tileset gTileset_TanobyRuins =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TanobyRuins,
    .palettes = gTilesetPalettes_TanobyRuins,
    .metatiles = gMetatiles_TanobyRuins,
    .metatileAttributes = gMetatileAttributes_TanobyRuins,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoBuilding1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoBuilding1,
    .palettes = gTilesetPalettes_JohtoBuilding1,
    .metatiles = gMetatiles_JohtoBuilding1,
    .metatileAttributes = gMetatileAttributes_JohtoBuilding1,
    .callback = NULL,
};

const struct Tileset gTileset_KantoHarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoHarbor,
    .palettes = gTilesetPalettes_KantoHarbor,
    .metatiles = gMetatiles_KantoHarbor,
    .metatileAttributes = gMetatileAttributes_KantoHarbor,
    .callback = NULL,
};

const struct Tileset gTileset_BerryForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BerryForest,
    .palettes = gTilesetPalettes_BerryForest,
    .metatiles = gMetatiles_BerryForest,
    .metatileAttributes = gMetatileAttributes_BerryForest,
    .callback = NULL,
};

const struct Tileset gTileset_RockTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RockTunnel,
    .palettes = gTilesetPalettes_RockTunnel,
    .metatiles = gMetatiles_RockTunnel,
    .metatileAttributes = gMetatileAttributes_RockTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_AzaleaGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_AzaleaGym,
    .palettes = gTilesetPalettes_AzaleaGym,
    .metatiles = gMetatiles_AzaleaGym,
    .metatileAttributes = gMetatileAttributes_AzaleaGym,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoDepartmentStore =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoDepartmentStore,
    .palettes = gTilesetPalettes_JohtoDepartmentStore,
    .metatiles = gMetatiles_JohtoDepartmentStore,
    .metatileAttributes = gMetatileAttributes_JohtoDepartmentStore,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCityMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCityMuseum,
    .palettes = gTilesetPalettes_PewterCityMuseum,
    .metatiles = gMetatiles_PewterCityMuseum,
    .metatileAttributes = gMetatileAttributes_PewterCityMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodGym,
    .palettes = gTilesetPalettes_GoldenrodGym,
    .metatiles = gMetatiles_GoldenrodGym,
    .metatileAttributes = gMetatileAttributes_GoldenrodGym,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCityBikeShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCityBikeShop,
    .palettes = gTilesetPalettes_CeruleanCityBikeShop,
    .metatiles = gMetatiles_CeruleanCityBikeShop,
    .metatileAttributes = gMetatileAttributes_CeruleanCityBikeShop,
    .callback = NULL,
};

const struct Tileset gTileset_PagodaTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PagodaTower,
    .palettes = gTilesetPalettes_PagodaTower,
    .metatiles = gMetatiles_PagodaTower,
    .metatileAttributes = gMetatileAttributes_PagodaTower,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarIsland =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarIsland,
    .palettes = gTilesetPalettes_CinnabarIsland,
    .metatiles = gMetatiles_CinnabarIsland,
    .metatileAttributes = gMetatileAttributes_CinnabarIsland,
    .callback = NULL,
};

const struct Tileset gTileset_BlackthornCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BlackthornCity,
    .palettes = gTilesetPalettes_BlackthornCity,
    .metatiles = gMetatiles_BlackthornCity,
    .metatileAttributes = gMetatileAttributes_BlackthornCity,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCityGym,
    .palettes = gTilesetPalettes_ViridianCityGym,
    .metatiles = gMetatiles_ViridianCityGym,
    .metatileAttributes = gMetatileAttributes_ViridianCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_MtMoon =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MtMoon,
    .palettes = gTilesetPalettes_MtMoon,
    .metatiles = gMetatiles_MtMoon,
    .metatileAttributes = gMetatileAttributes_MtMoon,
    .callback = NULL,
};

const struct Tileset gTileset_DiglettsCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DiglettsCave,
    .palettes = gTilesetPalettes_DiglettsCave,
    .metatiles = gMetatiles_DiglettsCave,
    .metatileAttributes = gMetatileAttributes_DiglettsCave,
    .callback = NULL,
};

const struct Tileset gTileset_KantoBuilding1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoBuilding1,
    .palettes = gTilesetPalettes_KantoBuilding1,
    .metatiles = gMetatiles_KantoBuilding1,
    .metatileAttributes = gMetatileAttributes_KantoBuilding1,
    .callback = NULL,
};

const struct Tileset gTileset_KantoPokeMart =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoPokeMart,
    .palettes = gTilesetPalettes_KantoPokeMart,
    .metatiles = gMetatiles_KantoPokeMart,
    .metatileAttributes = gMetatileAttributes_KantoPokeMart,
    .callback = NULL,
};

const struct Tileset gTileset_PalletTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PalletTown,
    .palettes = gTilesetPalettes_PalletTown,
    .metatiles = gMetatiles_PalletTown,
    .metatileAttributes = gMetatileAttributes_PalletTown,
    .callback = NULL,
};

const struct Tileset gTileset_KantoPokemonLeague =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoPokemonLeague,
    .palettes = gTilesetPalettes_KantoPokemonLeague,
    .metatiles = gMetatiles_KantoPokemonLeague,
    .metatileAttributes = gMetatileAttributes_KantoPokemonLeague,
    .callback = NULL,
};

const struct Tileset gTileset_RadioTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RadioTower,
    .palettes = gTilesetPalettes_RadioTower,
    .metatiles = gMetatiles_RadioTower,
    .metatileAttributes = gMetatileAttributes_RadioTower,
    .callback = NULL,
};

const struct Tileset gTileset_KantoDayCare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoDayCare,
    .palettes = gTilesetPalettes_KantoDayCare,
    .metatiles = gMetatiles_KantoDayCare,
    .metatileAttributes = gMetatileAttributes_KantoDayCare,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoBikeShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoBikeShop,
    .palettes = gTilesetPalettes_JohtoBikeShop,
    .metatiles = gMetatiles_JohtoBikeShop,
    .metatileAttributes = gMetatileAttributes_JohtoBikeShop,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCity,
    .palettes = gTilesetPalettes_CeruleanCity,
    .metatiles = gMetatiles_CeruleanCity,
    .metatileAttributes = gMetatileAttributes_CeruleanCity,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionCityGym,
    .palettes = gTilesetPalettes_VermilionCityGym,
    .metatiles = gMetatiles_VermilionCityGym,
    .metatileAttributes = gMetatileAttributes_VermilionCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_VioletCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VioletCity,
    .palettes = gTilesetPalettes_VioletCity,
    .metatiles = gMetatiles_VioletCity,
    .metatileAttributes = gMetatileAttributes_VioletCity,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianForest,
    .palettes = gTilesetPalettes_ViridianForest,
    .metatiles = gMetatiles_ViridianForest,
    .metatileAttributes = gMetatileAttributes_ViridianForest,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIsles3 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIsles3,
    .palettes = gTilesetPalettes_SeviiIsles3,
    .metatiles = gMetatiles_SeviiIsles3,
    .metatileAttributes = gMetatileAttributes_SeviiIsles3,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIsles2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIsles2,
    .palettes = gTilesetPalettes_SeviiIsles2,
    .metatiles = gMetatiles_SeviiIsles2,
    .metatileAttributes = gMetatileAttributes_SeviiIsles2,
    .callback = NULL,
};

const struct Tileset gTileset_SeaCottage =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeaCottage,
    .palettes = gTilesetPalettes_SeaCottage,
    .metatiles = gMetatiles_SeaCottage,
    .metatileAttributes = gMetatileAttributes_SeaCottage,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoUnderground =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoUnderground,
    .palettes = gTilesetPalettes_JohtoUnderground,
    .metatiles = gMetatiles_JohtoUnderground,
    .metatileAttributes = gMetatileAttributes_JohtoUnderground,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCityGym,
    .palettes = gTilesetPalettes_CeruleanCityGym,
    .metatiles = gMetatiles_CeruleanCityGym,
    .metatileAttributes = gMetatileAttributes_CeruleanCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_Condominiums =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Condominiums,
    .palettes = gTilesetPalettes_Condominiums,
    .metatiles = gMetatiles_Condominiums,
    .metatileAttributes = gMetatileAttributes_Condominiums,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaCity,
    .palettes = gTilesetPalettes_FuchsiaCity,
    .metatiles = gMetatiles_FuchsiaCity,
    .metatileAttributes = gMetatileAttributes_FuchsiaCity,
    .callback = NULL,
};

const struct Tileset gTileset_KantoBuilding3 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoBuilding3,
    .palettes = gTilesetPalettes_KantoBuilding3,
    .metatiles = gMetatiles_KantoBuilding3,
    .metatileAttributes = gMetatileAttributes_KantoBuilding3,
    .callback = NULL,
};

const struct Tileset gTileset_GameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GameCorner,
    .palettes = gTilesetPalettes_GameCorner,
    .metatiles = gMetatiles_GameCorner,
    .metatileAttributes = gMetatileAttributes_GameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_MtEmber =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MtEmber,
    .palettes = gTilesetPalettes_MtEmber,
    .metatiles = gMetatiles_MtEmber,
    .metatileAttributes = gMetatileAttributes_MtEmber,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionCity,
    .palettes = gTilesetPalettes_VermilionCity,
    .metatiles = gMetatiles_VermilionCity,
    .metatileAttributes = gMetatileAttributes_VermilionCity,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity,
    .palettes = gTilesetPalettes_SaffronCity,
    .metatiles = gMetatiles_SaffronCity,
    .metatileAttributes = gMetatileAttributes_SaffronCity,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoDayCare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoDayCare,
    .palettes = gTilesetPalettes_JohtoDayCare,
    .metatiles = gMetatiles_JohtoDayCare,
    .metatileAttributes = gMetatileAttributes_JohtoDayCare,
    .callback = NULL,
};

const struct Tileset gTileset_NewBarkTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NewBarkTown,
    .palettes = gTilesetPalettes_NewBarkTown,
    .metatiles = gMetatiles_NewBarkTown,
    .metatileAttributes = gMetatileAttributes_NewBarkTown,
    .callback = NULL,
};

const struct Tileset gTileset_SeafoamIslands =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeafoamIslands,
    .palettes = gTilesetPalettes_SeafoamIslands,
    .metatiles = gMetatiles_SeafoamIslands,
    .metatileAttributes = gMetatileAttributes_SeafoamIslands,
    .callback = NULL,
};

const struct Tileset gTileset_KantoTrainerTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoTrainerTower,
    .palettes = gTilesetPalettes_KantoTrainerTower,
    .metatiles = gMetatiles_KantoTrainerTower,
    .metatileAttributes = gMetatileAttributes_KantoTrainerTower,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIsles1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIsles1,
    .palettes = gTilesetPalettes_SeviiIsles1,
    .metatiles = gMetatiles_SeviiIsles1,
    .metatileAttributes = gMetatileAttributes_SeviiIsles1,
    .callback = NULL,
};

const struct Tileset gTileset_SilphCo =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SilphCo,
    .palettes = gTilesetPalettes_SilphCo,
    .metatiles = gMetatiles_SilphCo,
    .metatileAttributes = gMetatileAttributes_SilphCo,
    .callback = NULL,
};

const struct Tileset gTileset_KantoPokeCenter =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoPokeCenter,
    .palettes = gTilesetPalettes_KantoPokeCenter,
    .metatiles = gMetatiles_KantoPokeCenter,
    .metatileAttributes = gMetatileAttributes_KantoPokeCenter,
    .callback = NULL,
};

const struct Tileset gTileset_OlivineCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OlivineCity,
    .palettes = gTilesetPalettes_OlivineCity,
    .metatiles = gMetatiles_OlivineCity,
    .metatileAttributes = gMetatileAttributes_OlivineCity,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarIslandGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarIslandGym,
    .palettes = gTilesetPalettes_CinnabarIslandGym,
    .metatiles = gMetatiles_CinnabarIslandGym,
    .metatileAttributes = gMetatileAttributes_CinnabarIslandGym,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCity,
    .palettes = gTilesetPalettes_ViridianCity,
    .metatiles = gMetatiles_ViridianCity,
    .metatileAttributes = gMetatileAttributes_ViridianCity,
    .callback = NULL,
};

const struct Tileset gTileset_EcruteakCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EcruteakCity,
    .palettes = gTilesetPalettes_EcruteakCity,
    .metatiles = gMetatiles_EcruteakCity,
    .metatileAttributes = gMetatileAttributes_EcruteakCity,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoForest,
    .palettes = gTilesetPalettes_JohtoForest,
    .metatiles = gMetatiles_JohtoForest,
    .metatileAttributes = gMetatileAttributes_JohtoForest,
    .callback = NULL,
};

const struct Tileset gTileset_KantoPowerPlant =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoPowerPlant,
    .palettes = gTilesetPalettes_KantoPowerPlant,
    .metatiles = gMetatiles_KantoPowerPlant,
    .metatileAttributes = gMetatileAttributes_KantoPowerPlant,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonTower,
    .palettes = gTilesetPalettes_PokemonTower,
    .metatiles = gMetatiles_PokemonTower,
    .metatileAttributes = gMetatileAttributes_PokemonTower,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCityGym,
    .palettes = gTilesetPalettes_SaffronCityGym,
    .metatiles = gMetatiles_SaffronCityGym,
    .metatileAttributes = gMetatileAttributes_SaffronCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_MagnetTrain =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MagnetTrain,
    .palettes = gTilesetPalettes_MagnetTrain,
    .metatiles = gMetatiles_MagnetTrain,
    .metatileAttributes = gMetatileAttributes_MagnetTrain,
    .callback = NULL,
};

const struct Tileset gTileset_KantoOaksLab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoOaksLab,
    .palettes = gTilesetPalettes_KantoOaksLab,
    .metatiles = gMetatiles_KantoOaksLab,
    .metatileAttributes = gMetatileAttributes_KantoOaksLab,
    .callback = NULL,
};

const struct Tileset gTileset_KantoSafariBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoSafariBuilding,
    .palettes = gTilesetPalettes_KantoSafariBuilding,
    .metatiles = gMetatiles_KantoSafariBuilding,
    .metatileAttributes = gMetatileAttributes_KantoSafariBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonCityGym,
    .palettes = gTilesetPalettes_CeladonCityGym,
    .metatiles = gMetatiles_CeladonCityGym,
    .metatileAttributes = gMetatileAttributes_CeladonCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoCave,
    .palettes = gTilesetPalettes_JohtoCave,
    .metatiles = gMetatiles_JohtoCave,
    .metatileAttributes = gMetatileAttributes_JohtoCave,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCityCrimeHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCityCrimeHouse,
    .palettes = gTilesetPalettes_CeruleanCityCrimeHouse,
    .metatiles = gMetatiles_CeruleanCityCrimeHouse,
    .metatileAttributes = gMetatileAttributes_CeruleanCityCrimeHouse,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonDepartmentStore =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonDepartmentStore,
    .palettes = gTilesetPalettes_CeladonDepartmentStore,
    .metatiles = gMetatiles_CeladonDepartmentStore,
    .metatileAttributes = gMetatileAttributes_CeladonDepartmentStore,
    .callback = NULL,
};

const struct Tileset gTileset_IndigoPlateau =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IndigoPlateau,
    .palettes = gTilesetPalettes_IndigoPlateau,
    .metatiles = gMetatiles_IndigoPlateau,
    .metatileAttributes = gMetatileAttributes_IndigoPlateau,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCity,
    .palettes = gTilesetPalettes_PewterCity,
    .metatiles = gMetatiles_PewterCity,
    .metatileAttributes = gMetatileAttributes_PewterCity,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonHotel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonHotel,
    .palettes = gTilesetPalettes_CeladonHotel,
    .metatiles = gMetatiles_CeladonHotel,
    .metatileAttributes = gMetatileAttributes_CeladonHotel,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaCityGym,
    .palettes = gTilesetPalettes_FuchsiaCityGym,
    .metatiles = gMetatiles_FuchsiaCityGym,
    .metatileAttributes = gMetatileAttributes_FuchsiaCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCityGym,
    .palettes = gTilesetPalettes_PewterCityGym,
    .metatiles = gMetatiles_PewterCityGym,
    .metatileAttributes = gMetatileAttributes_PewterCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlph =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlph,
    .palettes = gTilesetPalettes_RuinsOfAlph,
    .metatiles = gMetatiles_RuinsOfAlph,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlph,
    .callback = NULL,
};

const struct Tileset gTileset_KantoHallOfFame =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoHallOfFame,
    .palettes = gTilesetPalettes_KantoHallOfFame,
    .metatiles = gMetatiles_KantoHallOfFame,
    .metatileAttributes = gMetatileAttributes_KantoHallOfFame,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonMansion =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonMansion,
    .palettes = gTilesetPalettes_PokemonMansion,
    .metatiles = gMetatiles_PokemonMansion,
    .metatileAttributes = gMetatileAttributes_PokemonMansion,
    .callback = NULL,
};

const struct Tileset gTileset_AzaleaTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_AzaleaTown,
    .palettes = gTilesetPalettes_AzaleaTown,
    .metatiles = gMetatiles_AzaleaTown,
    .metatileAttributes = gMetatileAttributes_AzaleaTown,
    .callback = NULL,
};

const struct Tileset gTileset_MahoganyTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MahoganyTown,
    .palettes = gTilesetPalettes_MahoganyTown,
    .metatiles = gMetatiles_MahoganyTown,
    .metatileAttributes = gMetatileAttributes_MahoganyTown,
    .callback = NULL,
};

const struct Tileset gTileset_LavenderTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavenderTown,
    .palettes = gTilesetPalettes_LavenderTown,
    .metatiles = gMetatiles_LavenderTown,
    .metatileAttributes = gMetatileAttributes_LavenderTown,
    .callback = NULL,
};

const struct Tileset gTileset_UndergroundPass =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UndergroundPass,
    .palettes = gTilesetPalettes_UndergroundPass,
    .metatiles = gMetatiles_UndergroundPass,
    .metatileAttributes = gMetatileAttributes_UndergroundPass,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodCity,
    .palettes = gTilesetPalettes_GoldenrodCity,
    .metatiles = gMetatiles_GoldenrodCity,
    .metatileAttributes = gMetatileAttributes_GoldenrodCity,
    .callback = NULL,
};

const struct Tileset gTileset_VioletCityGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VioletCityGym,
    .palettes = gTilesetPalettes_VioletCityGym,
    .metatiles = gMetatiles_VioletCityGym,
    .metatileAttributes = gMetatileAttributes_VioletCityGym,
    .callback = NULL,
};

const struct Tileset gTileset_KantoBuilding2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoBuilding2,
    .palettes = gTilesetPalettes_KantoBuilding2,
    .metatiles = gMetatiles_KantoBuilding2,
    .metatileAttributes = gMetatileAttributes_KantoBuilding2,
    .callback = NULL,
};

const struct Tileset gTileset_NationalPark =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NationalPark,
    .palettes = gTilesetPalettes_NationalPark,
    .metatiles = gMetatiles_NationalPark,
    .metatileAttributes = gMetatileAttributes_NationalPark,
    .callback = NULL,
};

const struct Tileset gTileset_CianwoodCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CianwoodCity,
    .palettes = gTilesetPalettes_CianwoodCity,
    .metatiles = gMetatiles_CianwoodCity,
    .metatileAttributes = gMetatileAttributes_CianwoodCity,
    .callback = NULL,
};

const struct Tileset gTileset_DottedHole =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DottedHole,
    .palettes = gTilesetPalettes_DottedHole,
    .metatiles = gMetatiles_DottedHole,
    .metatileAttributes = gMetatileAttributes_DottedHole,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCave,
    .palettes = gTilesetPalettes_CeruleanCave,
    .metatiles = gMetatiles_CeruleanCave,
    .metatileAttributes = gMetatileAttributes_CeruleanCave,
    .callback = NULL,
};

const struct Tileset gTileset_JubilifeCitySecondary =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JubilifeCitySecondary,
    .palettes = gTilesetPalettes_JubilifeCitySecondary,
    .metatiles = gMetatiles_JubilifeCitySecondary,
    .metatileAttributes = gMetatileAttributes_JubilifeCitySecondary,
    .callback = NULL,
};

const struct Tileset gTileset_General_Jubilife =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General_Jubilife,
    .palettes = gTilesetPalettes_General_Jubilife,
    .metatiles = gMetatiles_General_Jubilife,
    .metatileAttributes = gMetatileAttributes_General_Jubilife,
    .callback = NULL,
};

const struct Tileset gTileset_Hearthome =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Hearthome,
    .palettes = gTilesetPalettes_Hearthome,
    .metatiles = gMetatiles_Hearthome,
    .metatileAttributes = gMetatileAttributes_Hearthome,
    .callback = NULL,
};

const struct Tileset gTileset_Celestic =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Celestic,
    .palettes = gTilesetPalettes_Celestic,
    .metatiles = gMetatiles_Celestic,
    .metatileAttributes = gMetatileAttributes_Celestic,
    .callback = NULL,
};

const struct Tileset gTileset_Veilstone =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Veilstone,
    .palettes = gTilesetPalettes_Veilstone,
    .metatiles = gMetatiles_Veilstone,
    .metatileAttributes = gMetatileAttributes_Veilstone,
    .callback = NULL,
};

const struct Tileset gTileset_Canalave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Canalave,
    .palettes = gTilesetPalettes_Canalave,
    .metatiles = gMetatiles_Canalave,
    .metatileAttributes = gMetatileAttributes_Canalave,
    .callback = NULL,
};

const struct Tileset gTileset_Snowpoint =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Snowpoint,
    .palettes = gTilesetPalettes_Snowpoint,
    .metatiles = gMetatiles_Snowpoint,
    .metatileAttributes = gMetatileAttributes_Snowpoint,
    .callback = NULL,
};

const struct Tileset gTileset_Sunnyshore =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Sunnyshore,
    .palettes = gTilesetPalettes_Sunnyshore,
    .metatiles = gMetatiles_Sunnyshore,
    .metatileAttributes = gMetatileAttributes_Sunnyshore,
    .callback = NULL,
};

const struct Tileset gTileset_Valor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Valor,
    .palettes = gTilesetPalettes_Valor,
    .metatiles = gMetatiles_Valor,
    .metatileAttributes = gMetatileAttributes_Valor,
    .callback = NULL,
};

const struct Tileset gTileset_Pasos =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Pasos,
    .palettes = gTilesetPalettes_Pasos,
    .metatiles = gMetatiles_Pasos,
    .metatileAttributes = gMetatileAttributes_Pasos,
    .callback = NULL,
};

const struct Tileset gTileset_AMapSI =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_AMapSI,
    .palettes = gTilesetPalettes_AMapSI,
    .metatiles = gMetatiles_AMapSI,
    .metatileAttributes = gMetatileAttributes_AMapSI,
    .callback = NULL,
};

const struct Tileset gTileset_Littleroot =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Littleroot,
    .palettes = gTilesetPalettes_Littleroot,
    .metatiles = gMetatiles_Littleroot,
    .metatileAttributes = gMetatileAttributes_Littleroot,
    .callback = NULL,
};

const struct Tileset gTileset_MauvillePrime =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_MauvillePrime,
    .palettes = gTilesetPalettes_MauvillePrime,
    .metatiles = gMetatiles_MauvillePrime,
    .metatileAttributes = gMetatileAttributes_MauvillePrime,
    .callback = NULL,
};

const struct Tileset gTileset_Jublife =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Jublife,
    .palettes = gTilesetPalettes_Jublife,
    .metatiles = gMetatiles_Jublife,
    .metatileAttributes = gMetatileAttributes_Jublife,
    .callback = NULL,
};

const struct Tileset gTileset_JublifePrime =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_JublifePrime,
    .palettes = gTilesetPalettes_JublifePrime,
    .metatiles = gMetatiles_JublifePrime,
    .metatileAttributes = gMetatileAttributes_JublifePrime,
    .callback = NULL,
};

const struct Tileset gTileset_general_jubilife =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General_Jubilife,
    .palettes = gTilesetPalettes_General_Jubilife,
    .metatiles = gMetatiles_General_Jubilife,
    .metatileAttributes = gMetatileAttributes_General_Jubilife,
    .callback = NULL,
};

const struct Tileset gTileset_jubilife_city_secondary =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JubilifeCitySecondary,
    .palettes = gTilesetPalettes_JubilifeCitySecondary,
    .metatiles = gMetatiles_JubilifeCitySecondary,
    .metatileAttributes = gMetatileAttributes_JubilifeCitySecondary,
    .callback = NULL,
};

const struct Tileset gTileset_Ore =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Ore,
    .palettes = gTilesetPalettes_Ore,
    .metatiles = gMetatiles_Ore,
    .metatileAttributes = gMetatileAttributes_Ore,
    .callback = NULL,
};

const struct Tileset gTileset_Ore2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Ore2,
    .palettes = gTilesetPalettes_Ore2,
    .metatiles = gMetatiles_Ore2,
    .metatileAttributes = gMetatileAttributes_Ore2,
    .callback = NULL,
};

const struct Tileset gTileset_SinnohSecond =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SinnohSecond,
    .palettes = gTilesetPalettes_SinnohSecond,
    .metatiles = gMetatiles_SinnohSecond,
    .metatileAttributes = gMetatileAttributes_SinnohSecond,
    .callback = NULL,
};

const struct Tileset gTileset_SinnohSecon =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SinnohSecon,
    .palettes = gTilesetPalettes_SinnohSecon,
    .metatiles = gMetatiles_SinnohSecon,
    .metatileAttributes = gMetatileAttributes_SinnohSecon,
    .callback = NULL,
};

const struct Tileset gTileset_EternaCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EternaCity,
    .palettes = gTilesetPalettes_EternaCity,
    .metatiles = gMetatiles_EternaCity,
    .metatileAttributes = gMetatileAttributes_EternaCity,
    .callback = NULL,
};

const struct Tileset gTileset_Celesti =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Celesti,
    .palettes = gTilesetPalettes_Celesti,
    .metatiles = gMetatiles_Celesti,
    .metatileAttributes = gMetatileAttributes_Celesti,
    .callback = NULL,
};

const struct Tileset gTileset_Snowpoin =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Snowpoin,
    .palettes = gTilesetPalettes_Snowpoin,
    .metatiles = gMetatiles_Snowpoin,
    .metatileAttributes = gMetatileAttributes_Snowpoin,
    .callback = NULL,
};

const struct Tileset gTileset_Snow =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Snow,
    .palettes = gTilesetPalettes_Snow,
    .metatiles = gMetatiles_Snow,
    .metatileAttributes = gMetatileAttributes_Snow,
    .callback = NULL,
};

const struct Tileset gTileset_Sunny =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Sunny,
    .palettes = gTilesetPalettes_Sunny,
    .metatiles = gMetatiles_Sunny,
    .metatileAttributes = gMetatileAttributes_Sunny,
    .callback = NULL,
};

const struct Tileset gTileset_route212 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_route212,
    .palettes = gTilesetPalettes_route212,
    .metatiles = gMetatiles_route212,
    .metatileAttributes = gMetatileAttributes_route212,
    .callback = NULL,
};

const struct Tileset gTileset_juu =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_juu,
    .palettes = gTilesetPalettes_juu,
    .metatiles = gMetatiles_juu,
    .metatileAttributes = gMetatileAttributes_juu,
    .callback = NULL,
};

const struct Tileset gTileset_209 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_209,
    .palettes = gTilesetPalettes_209,
    .metatiles = gMetatiles_209,
    .metatileAttributes = gMetatileAttributes_209,
    .callback = NULL,
};

const struct Tileset gTileset_jubi =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_jubi,
    .palettes = gTilesetPalettes_jubi,
    .metatiles = gMetatiles_jubi,
    .metatileAttributes = gMetatileAttributes_jubi,
    .callback = NULL,
};

const struct Tileset gTileset_Distortion =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Distortion,
    .palettes = gTilesetPalettes_Distortion,
    .metatiles = gMetatiles_Distortion,
    .metatileAttributes = gMetatileAttributes_Distortion,
    .callback = NULL,
};

const struct Tileset gTileset_NewCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NewCave,
    .palettes = gTilesetPalettes_NewCave,
    .metatiles = gMetatiles_NewCave,
    .metatileAttributes = gMetatileAttributes_NewCave,
    .callback = NULL,
};

const struct Tileset gTileset_Champion =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Champion,
    .palettes = gTilesetPalettes_Champion,
    .metatiles = gMetatiles_Champion,
    .metatileAttributes = gMetatileAttributes_Champion,
    .callback = NULL,
};

const struct Tileset gTileset_Newturf =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Newturf,
    .palettes = gTilesetPalettes_Newturf,
    .metatiles = gMetatiles_Newturf,
    .metatileAttributes = gMetatileAttributes_Newturf,
    .callback = NULL,
};

const struct Tileset gTileset_JubiPrime =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_JubiPrime,
    .palettes = gTilesetPalettes_JubiPrime,
    .metatiles = gMetatiles_JubiPrime,
    .metatileAttributes = gMetatileAttributes_JubiPrime,
    .callback = NULL,
};

const struct Tileset gTileset_JubiSecond =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JubiSecond,
    .palettes = gTilesetPalettes_JubiSecond,
    .metatiles = gMetatiles_JubiSecond,
    .metatileAttributes = gMetatileAttributes_JubiSecond,
    .callback = NULL,
};

const struct Tileset gTileset_world =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_world,
    .palettes = gTilesetPalettes_world,
    .metatiles = gMetatiles_world,
    .metatileAttributes = gMetatileAttributes_world,
    .callback = NULL,
};

const struct Tileset gTileset_distortion =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_distortion,
    .palettes = gTilesetPalettes_distortion,
    .metatiles = gMetatiles_distortion,
    .metatileAttributes = gMetatileAttributes_distortion,
    .callback = NULL,
};

const struct Tileset gTileset_HoennInt =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_HoennInt,
    .palettes = gTilesetPalettes_HoennInt,
    .metatiles = gMetatiles_HoennInt,
    .metatileAttributes = gMetatileAttributes_HoennInt,
    .callback = NULL,
};

const struct Tileset gTileset_HoennInt2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HoennInt2,
    .palettes = gTilesetPalettes_HoennInt2,
    .metatiles = gMetatiles_HoennInt2,
    .metatileAttributes = gMetatileAttributes_HoennInt2,
    .callback = NULL,
};

const struct Tileset gTileset_Birch =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Birch,
    .palettes = gTilesetPalettes_Birch,
    .metatiles = gMetatiles_Birch,
    .metatileAttributes = gMetatileAttributes_Birch,
    .callback = NULL,
};

const struct Tileset gTileset_BLab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BLab,
    .palettes = gTilesetPalettes_BLab,
    .metatiles = gMetatiles_BLab,
    .metatileAttributes = gMetatileAttributes_BLab,
    .callback = NULL,
};

const struct Tileset gTileset_PokecenterN =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_PokecenterN,
    .palettes = gTilesetPalettes_PokecenterN,
    .metatiles = gMetatiles_PokecenterN,
    .metatileAttributes = gMetatileAttributes_PokecenterN,
    .callback = NULL,
};

const struct Tileset gTileset_CenterPoke =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CenterPoke,
    .palettes = gTilesetPalettes_CenterPoke,
    .metatiles = gMetatiles_CenterPoke,
    .metatileAttributes = gMetatileAttributes_CenterPoke,
    .callback = NULL,
};

const struct Tileset gTileset_PokeMart =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_PokeMart,
    .palettes = gTilesetPalettes_PokeMart,
    .metatiles = gMetatiles_PokeMart,
    .metatileAttributes = gMetatileAttributes_PokeMart,
    .callback = NULL,
};

const struct Tileset gTileset_ShopN =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ShopN,
    .palettes = gTilesetPalettes_ShopN,
    .metatiles = gMetatiles_ShopN,
    .metatileAttributes = gMetatileAttributes_ShopN,
    .callback = NULL,
};

const struct Tileset gTileset_UpdateHoenn =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_UpdateHoenn,
    .palettes = gTilesetPalettes_UpdateHoenn,
    .metatiles = gMetatiles_UpdateHoenn,
    .metatileAttributes = gMetatileAttributes_UpdateHoenn,
    .callback = NULL,
};

const struct Tileset gTileset_UpdateHoennSecond =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UpdateHoennSecond,
    .palettes = gTilesetPalettes_UpdateHoennSecond,
    .metatiles = gMetatiles_UpdateHoennSecond,
    .metatileAttributes = gMetatileAttributes_UpdateHoennSecond,
    .callback = NULL,
};

const struct Tileset gTileset_HoennGeneral =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_HoennGeneral,
    .palettes = gTilesetPalettes_HoennGeneral,
    .metatiles = gMetatiles_HoennGeneral,
    .metatileAttributes = gMetatileAttributes_HoennGeneral,
    .callback = NULL,
};

const struct Tileset gTileset_Contester =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Contester,
    .palettes = gTilesetPalettes_Contester,
    .metatiles = gMetatiles_Contester,
    .metatileAttributes = gMetatileAttributes_Contester,
    .callback = NULL,
};

const struct Tileset gTileset_SootHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootHouse,
    .palettes = gTilesetPalettes_SootHouse,
    .metatiles = gMetatiles_SootHouse,
    .metatileAttributes = gMetatileAttributes_SootHouse,
    .callback = NULL,
};

const struct Tileset gTileset_SootHouses =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SootHouses,
    .palettes = gTilesetPalettes_SootHouses,
    .metatiles = gMetatiles_SootHouses,
    .metatileAttributes = gMetatileAttributes_SootHouses,
    .callback = NULL,
};

const struct Tileset gTileset_Dungeons =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Dungeons,
    .palettes = gTilesetPalettes_Dungeons,
    .metatiles = gMetatiles_Dungeons,
    .metatileAttributes = gMetatileAttributes_Dungeons,
    .callback = NULL,
};

const struct Tileset gTileset_PacifidlogTown =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_PacifidlogTown,
    .palettes = gTilesetPalettes_PacifidlogTown,
    .metatiles = gMetatiles_PacifidlogTown,
    .metatileAttributes = gMetatileAttributes_PacifidlogTown,
    .callback = NULL,
};

const struct Tileset gTileset_InsideShipPrimary =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_InsideShipPrimary,
    .palettes = gTilesetPalettes_InsideShipPrimary,
    .metatiles = gMetatiles_InsideShipPrimary,
    .metatileAttributes = gMetatileAttributes_InsideShipPrimary,
    .callback = NULL,
};

const struct Tileset gTileset_UnderwaterPrimary =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_UnderwaterPrimary,
    .palettes = gTilesetPalettes_UnderwaterPrimary,
    .metatiles = gMetatiles_UnderwaterPrimary,
    .metatileAttributes = gMetatileAttributes_UnderwaterPrimary,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRockNew =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRockNew,
    .palettes = gTilesetPalettes_NavelRockNew,
    .metatiles = gMetatiles_NavelRockNew,
    .metatileAttributes = gMetatileAttributes_NavelRockNew,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRockNewTop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRockNewTop,
    .palettes = gTilesetPalettes_NavelRockNewTop,
    .metatiles = gMetatiles_NavelRockNewTop,
    .metatileAttributes = gMetatileAttributes_NavelRockNewTop,
    .callback = NULL,
};

const struct Tileset gTileset_Route206 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Route206,
    .palettes = gTilesetPalettes_Route206,
    .metatiles = gMetatiles_Route206,
    .metatileAttributes = gMetatileAttributes_Route206,
    .callback = NULL,
};

const struct Tileset gTileset_JubilifePrimary =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_JubilifePrimary,
    .palettes = gTilesetPalettes_JubilifePrimary,
    .metatiles = gMetatiles_JubilifePrimary,
    .metatileAttributes = gMetatileAttributes_JubilifePrimary,
    .callback = NULL,
};

const struct Tileset gTileset_JubilifeSecondary =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JubilifeSecondary,
    .palettes = gTilesetPalettes_JubilifeSecondary,
    .metatiles = gMetatiles_JubilifeSecondary,
    .metatileAttributes = gMetatileAttributes_JubilifeSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_NewCavePrime =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_NewCavePrime,
    .palettes = gTilesetPalettes_NewCavePrime,
    .metatiles = gMetatiles_NewCavePrime,
    .metatileAttributes = gMetatileAttributes_NewCavePrime,
    .callback = NULL,
};

const struct Tileset gTileset_SpearPillarPrimary =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SpearPillarPrimary,
    .palettes = gTilesetPalettes_SpearPillarPrimary,
    .metatiles = gMetatiles_SpearPillarPrimary,
    .metatileAttributes = gMetatileAttributes_SpearPillarPrimary,
    .callback = NULL,
};

const struct Tileset gTileset_SpearPillarSecondary =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SpearPillarSecondary,
    .palettes = gTilesetPalettes_SpearPillarSecondary,
    .metatiles = gMetatiles_SpearPillarSecondary,
    .metatileAttributes = gMetatileAttributes_SpearPillarSecondary,
    .callback = NULL,
};

// === Kanto/Johto/HnS Tilesets ===

const struct Tileset gTileset_AzaleaTown_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_azalea_town_gym,
    .palettes = gTilesetPalettes_azalea_town_gym,
    .metatiles = gMetatiles_azalea_town_gym,
    .metatileAttributes = gMetatileAttributes_azalea_town_gym,
    .callback = InitTilesetAnim_AzaleaTown_Gym,
};

const struct Tileset gTileset_AzaleaTown_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_AzaleaTown_HnS,
    .palettes = gTilesetPalettes_AzaleaTown_HnS,
    .metatiles = gMetatiles_AzaleaTown_HnS,
    .metatileAttributes = gMetatileAttributes_AzaleaTown_HnS,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Barn =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Barn,
    .palettes = gTilesetPalettes_Barn,
    .metatiles = gMetatiles_Barn,
    .metatileAttributes = gMetatileAttributes_Barn,
    .callback = NULL,
};

const struct Tileset gTileset_BellchimeTrail =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BellchimeTrail,
    .palettes = gTilesetPalettes_BellchimeTrail,
    .metatiles = gMetatiles_BellchimeTrail,
    .metatileAttributes = gMetatileAttributes_BellchimeTrail,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop_HnS,
    .palettes = gTilesetPalettes_BikeShop_HnS,
    .metatiles = gMetatiles_BikeShop_HnS,
    .metatileAttributes = gMetatileAttributes_BikeShop_HnS,
    .callback = InitTilesetAnim_BikeShop,
};

const struct Tileset gTileset_Blackthorn =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Blackthorn,
    .palettes = gTilesetPalettes_Blackthorn,
    .metatiles = gMetatiles_Blackthorn,
    .metatileAttributes = gMetatileAttributes_Blackthorn,
    .callback = NULL,
};

const struct Tileset gTileset_BlackthornGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BlackthornGym,
    .palettes = gTilesetPalettes_BlackthornGym,
    .metatiles = gMetatiles_BlackthornGym,
    .metatileAttributes = gMetatileAttributes_BlackthornGym,
    .callback = InitTilesetAnim_Lavaridge,
};

const struct Tileset gTileset_Building_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_InsideBuilding_HnS,
    .palettes = gTilesetPalettes_InsideBuilding_HnS,
    .metatiles = gMetatiles_InsideBuilding_HnS,
    .metatileAttributes = gMetatileAttributes_InsideBuilding_HnS,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_BurnedTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BurnedTower,
    .palettes = gTilesetPalettes_BurnedTower,
    .metatiles = gMetatiles_BurnedTower,
    .metatileAttributes = gMetatileAttributes_BurnedTower,
    .callback = NULL,
};

const struct Tileset gTileset_Cafe =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cafe,
    .palettes = gTilesetPalettes_Cafe,
    .metatiles = gMetatiles_Cafe,
    .metatileAttributes = gMetatileAttributes_Cafe,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Default =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Default,
    .palettes = gTilesetPalettes_Cave_Default,
    .metatiles = gMetatiles_Cave_Default,
    .metatileAttributes = gMetatileAttributes_Cave_Default,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_DragonsDen =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_DragonsDen,
    .palettes = gTilesetPalettes_Cave_DragonsDen,
    .metatiles = gMetatiles_Cave_DragonsDen,
    .metatileAttributes = gMetatileAttributes_Cave_DragonsDen,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Gray =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Gray,
    .palettes = gTilesetPalettes_Cave_Gray,
    .metatiles = gMetatiles_Cave_Gray,
    .metatileAttributes = gMetatileAttributes_Cave_Gray,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Green =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Green,
    .palettes = gTilesetPalettes_Cave_Green,
    .metatiles = gMetatiles_Cave_Green,
    .metatileAttributes = gMetatileAttributes_Cave_Green,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_HnS,
    .palettes = gTilesetPalettes_Cave_HnS,
    .metatiles = gMetatiles_Cave_HnS,
    .metatileAttributes = gMetatileAttributes_Cave_HnS,
    .callback = InitTilesetAnim_Cave,
};

const struct Tileset gTileset_Cave_Ice =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Ice,
    .palettes = gTilesetPalettes_Cave_Ice,
    .metatiles = gMetatiles_Cave_Ice,
    .metatileAttributes = gMetatileAttributes_Cave_Ice,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_MtMoon =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_MtMoon,
    .palettes = gTilesetPalettes_Cave_MtMoon,
    .metatiles = gMetatiles_Cave_MtMoon,
    .metatileAttributes = gMetatileAttributes_Cave_MtMoon,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Sandy =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Sandy,
    .palettes = gTilesetPalettes_Cave_Sandy,
    .metatiles = gMetatiles_Cave_Sandy,
    .metatileAttributes = gMetatileAttributes_Cave_Sandy,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonApartments =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonApartments,
    .palettes = gTilesetPalettes_CeladonApartments,
    .metatiles = gMetatiles_CeladonApartments,
    .metatileAttributes = gMetatileAttributes_CeladonApartments,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonCity_HnS,
    .palettes = gTilesetPalettes_CeladonCity_HnS,
    .metatiles = gMetatiles_CeladonCity_HnS,
    .metatileAttributes = gMetatileAttributes_CeladonCity_HnS,
    .callback = InitTilesetAnim_CeladonCity,
};

const struct Tileset gTileset_CeruleanCity_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCity_Gym,
    .palettes = gTilesetPalettes_CeruleanCity_Gym,
    .metatiles = gMetatiles_CeruleanCity_Gym,
    .metatileAttributes = gMetatileAttributes_CeruleanCity_Gym,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCity_HnS,
    .palettes = gTilesetPalettes_CeruleanCity_HnS,
    .metatiles = gMetatiles_CeruleanCity_HnS,
    .metatileAttributes = gMetatileAttributes_CeruleanCity_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_CherrygroveCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CherrygroveCity,
    .palettes = gTilesetPalettes_CherrygroveCity,
    .metatiles = gMetatiles_CherrygroveCity,
    .metatileAttributes = gMetatileAttributes_CherrygroveCity,
    .callback = NULL,
};

const struct Tileset gTileset_CianwoodCity_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CianwoodCity_Gym,
    .palettes = gTilesetPalettes_CianwoodCity_Gym,
    .metatiles = gMetatiles_CianwoodCity_Gym,
    .metatileAttributes = gMetatileAttributes_CianwoodCity_Gym,
    .callback = NULL,
};

const struct Tileset gTileset_CianwoodCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CianwoodCity_HnS,
    .palettes = gTilesetPalettes_CianwoodCity_HnS,
    .metatiles = gMetatiles_CianwoodCity_HnS,
    .metatileAttributes = gMetatileAttributes_CianwoodCity_HnS,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_CyclingRoad =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CyclingRoad,
    .palettes = gTilesetPalettes_CyclingRoad,
    .metatiles = gMetatiles_CyclingRoad,
    .metatileAttributes = gMetatileAttributes_CyclingRoad,
    .callback = NULL,
};

const struct Tileset gTileset_DepartmentStore =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DepartmentStore,
    .palettes = gTilesetPalettes_DepartmentStore,
    .metatiles = gMetatiles_DepartmentStore,
    .metatileAttributes = gMetatileAttributes_DepartmentStore,
    .callback = NULL,
};

const struct Tileset gTileset_DragonsDen_Shrine =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DragonsDen_Shrine,
    .palettes = gTilesetPalettes_DragonsDen_Shrine,
    .metatiles = gMetatiles_DragonsDen_Shrine,
    .metatileAttributes = gMetatileAttributes_DragonsDen_Shrine,
    .callback = NULL,
};

const struct Tileset gTileset_EcruteakCity_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EcruteakCity_Gym,
    .palettes = gTilesetPalettes_EcruteakCity_Gym,
    .metatiles = gMetatiles_EcruteakCity_Gym,
    .metatileAttributes = gMetatileAttributes_EcruteakCity_Gym,
    .callback = NULL,
};

const struct Tileset gTileset_EcruteakTheater =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EcruteakTheater,
    .palettes = gTilesetPalettes_EcruteakTheater,
    .metatiles = gMetatiles_EcruteakTheater,
    .metatileAttributes = gMetatileAttributes_EcruteakTheater,
    .callback = InitTilesetAnim_ecruteak_theater,
};

const struct Tileset gTileset_Ecruteak_City =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Ecruteak_City,
    .palettes = gTilesetPalettes_Ecruteak_City,
    .metatiles = gMetatiles_Ecruteak_City,
    .metatileAttributes = gMetatileAttributes_Ecruteak_City,
    .callback = NULL,
};

const struct Tileset gTileset_Fuchsia =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fuchsia,
    .palettes = gTilesetPalettes_Fuchsia,
    .metatiles = gMetatiles_Fuchsia,
    .metatileAttributes = gMetatileAttributes_Fuchsia,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaCity_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaCity_Gym,
    .palettes = gTilesetPalettes_FuchsiaCity_Gym,
    .metatiles = gMetatiles_FuchsiaCity_Gym,
    .metatileAttributes = gMetatileAttributes_FuchsiaCity_Gym,
    .callback = NULL,
};

const struct Tileset gTileset_GameCorner_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GameCorner_HnS,
    .palettes = gTilesetPalettes_GameCorner_HnS,
    .metatiles = gMetatiles_GameCorner_HnS,
    .metatileAttributes = gMetatileAttributes_GameCorner_HnS,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_Gate_Standard =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Gate_Standard,
    .palettes = gTilesetPalettes_Gate_Standard,
    .metatiles = gMetatiles_Gate_Standard,
    .metatileAttributes = gMetatileAttributes_Gate_Standard,
    .callback = NULL,
};

const struct Tileset gTileset_General_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General,
    .palettes = gTilesetPalettes_General,
    .metatiles = gMetatiles_General,
    .metatileAttributes = gMetatileAttributes_General,
    .callback = InitTilesetAnim_General,
};

const struct Tileset gTileset_Goldenrod =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Goldenrod,
    .palettes = gTilesetPalettes_Goldenrod,
    .metatiles = gMetatiles_Goldenrod,
    .metatileAttributes = gMetatileAttributes_Goldenrod,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodCity_TrainStation =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodCity_TrainStation,
    .palettes = gTilesetPalettes_GoldenrodCity_TrainStation,
    .metatiles = gMetatiles_GoldenrodCity_TrainStation,
    .metatileAttributes = gMetatileAttributes_GoldenrodCity_TrainStation,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodUndergroundRocket =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodUndergroundRocket,
    .palettes = gTilesetPalettes_GoldenrodUndergroundRocket,
    .metatiles = gMetatiles_GoldenrodUndergroundRocket,
    .metatileAttributes = gMetatileAttributes_GoldenrodUndergroundRocket,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodUndergroundTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodUndergroundTunnel,
    .palettes = gTilesetPalettes_GoldenrodUndergroundTunnel,
    .metatiles = gMetatiles_GoldenrodUndergroundTunnel,
    .metatileAttributes = gMetatileAttributes_GoldenrodUndergroundTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_Goldenrod_Underground_Storage =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Goldenrod_Underground_Storage,
    .palettes = gTilesetPalettes_Goldenrod_Underground_Storage,
    .metatiles = gMetatiles_Goldenrod_Underground_Storage,
    .metatileAttributes = gMetatileAttributes_Goldenrod_Underground_Storage,
    .callback = NULL,
};

const struct Tileset gTileset_HallOfFame =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HallOfFame,
    .palettes = gTilesetPalettes_HallOfFame,
    .metatiles = gMetatiles_HallOfFame,
    .metatileAttributes = gMetatileAttributes_HallOfFame,
    .callback = NULL,
};

const struct Tileset gTileset_House_2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_House_2,
    .palettes = gTilesetPalettes_House_2,
    .metatiles = gMetatiles_House_2,
    .metatileAttributes = gMetatileAttributes_House_2,
    .callback = NULL,
};

const struct Tileset gTileset_House_Lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_House_Lab,
    .palettes = gTilesetPalettes_House_Lab,
    .metatiles = gMetatiles_House_Lab,
    .metatileAttributes = gMetatileAttributes_House_Lab,
    .callback = NULL,
};

const struct Tileset gTileset_IlexForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IlexForest,
    .palettes = gTilesetPalettes_IlexForest,
    .metatiles = gMetatiles_IlexForest,
    .metatileAttributes = gMetatileAttributes_IlexForest,
    .callback = NULL,
};

const struct Tileset gTileset_IndigoPlateau_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IndigoPlateau_HnS,
    .palettes = gTilesetPalettes_IndigoPlateau_HnS,
    .metatiles = gMetatiles_IndigoPlateau_HnS,
    .metatileAttributes = gMetatileAttributes_IndigoPlateau_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoBikeShop_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoBikeShop_HnS,
    .palettes = gTilesetPalettes_JohtoBikeShop_HnS,
    .metatiles = gMetatiles_JohtoBikeShop_HnS,
    .metatileAttributes = gMetatileAttributes_JohtoBikeShop_HnS,
    .callback = InitTilesetAnim_BikeShop,
};

const struct Tileset gTileset_JohtoMart =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoMart,
    .palettes = gTilesetPalettes_JohtoMart,
    .metatiles = gMetatiles_JohtoMart,
    .metatileAttributes = gMetatileAttributes_JohtoMart,
    .callback = NULL,
};

const struct Tileset gTileset_Johto_Building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_Building,
    .palettes = gTilesetPalettes_Johto_Building,
    .metatiles = gMetatiles_Johto_Building,
    .metatileAttributes = gMetatileAttributes_Johto_Building,
    .callback = NULL,
};

const struct Tileset gTileset_Johto_General =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_General,
    .palettes = gTilesetPalettes_Johto_General,
    .metatiles = gMetatiles_Johto_General,
    .metatileAttributes = gMetatileAttributes_Johto_General,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Johto_NorthEast =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_NorthEast,
    .palettes = gTilesetPalettes_Johto_NorthEast,
    .metatiles = gMetatiles_Johto_NorthEast,
    .metatileAttributes = gMetatileAttributes_Johto_NorthEast,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Johto_NorthWest =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_NorthWest,
    .palettes = gTilesetPalettes_Johto_NorthWest,
    .metatiles = gMetatiles_Johto_NorthWest,
    .metatileAttributes = gMetatileAttributes_Johto_NorthWest,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Johto_South =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_South,
    .palettes = gTilesetPalettes_Johto_South,
    .metatiles = gMetatiles_Johto_South,
    .metatileAttributes = gMetatileAttributes_Johto_South,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_KantoMart =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoMart,
    .palettes = gTilesetPalettes_KantoMart,
    .metatiles = gMetatiles_KantoMart,
    .metatileAttributes = gMetatileAttributes_KantoMart,
    .callback = NULL,
};

const struct Tileset gTileset_Kanto_Building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Kanto_Building,
    .palettes = gTilesetPalettes_Kanto_Building,
    .metatiles = gMetatiles_Kanto_Building,
    .metatileAttributes = gMetatileAttributes_Kanto_Building,
    .callback = NULL,
};

const struct Tileset gTileset_Kanto_General =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Kanto_General,
    .palettes = gTilesetPalettes_Kanto_General,
    .metatiles = gMetatiles_Kanto_General,
    .metatileAttributes = gMetatileAttributes_Kanto_General,
    .callback = InitTilesetAnim_KantoGeneral,
};

const struct Tileset gTileset_Kanto_PokemonCenter =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Kanto_PokemonCenter,
    .palettes = gTilesetPalettes_Kanto_PokemonCenter,
    .metatiles = gMetatiles_Kanto_PokemonCenter,
    .metatileAttributes = gMetatileAttributes_Kanto_PokemonCenter,
    .callback = NULL,
};

const struct Tileset gTileset_KurtsHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KurtsHouse,
    .palettes = gTilesetPalettes_KurtsHouse,
    .metatiles = gMetatiles_KurtsHouse,
    .metatileAttributes = gMetatileAttributes_KurtsHouse,
    .callback = NULL,
};

const struct Tileset gTileset_Lavaridge_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lavaridge_HnS,
    .palettes = gTilesetPalettes_Lavaridge_HnS,
    .metatiles = gMetatiles_Lavaridge_HnS,
    .metatileAttributes = gMetatileAttributes_Lavaridge_HnS,
    .callback = InitTilesetAnim_Lavaridge,
};

const struct Tileset gTileset_LavenderTown_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavenderTown_HnS,
    .palettes = gTilesetPalettes_LavenderTown_HnS,
    .metatiles = gMetatiles_LavenderTown_HnS,
    .metatileAttributes = gMetatileAttributes_LavenderTown_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_Lighthouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lighthouse,
    .palettes = gTilesetPalettes_Lighthouse,
    .metatiles = gMetatiles_Lighthouse,
    .metatileAttributes = gMetatileAttributes_Lighthouse,
    .callback = NULL,
};

const struct Tileset gTileset_MahoganyTown_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MahoganyTown_HnS,
    .palettes = gTilesetPalettes_MahoganyTown_HnS,
    .metatiles = gMetatiles_MahoganyTown_HnS,
    .metatileAttributes = gMetatileAttributes_MahoganyTown_HnS,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_MeteorFalls_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MeteorFalls_HnS,
    .palettes = gTilesetPalettes_MeteorFalls_HnS,
    .metatiles = gMetatiles_MeteorFalls_HnS,
    .metatileAttributes = gMetatileAttributes_MeteorFalls_HnS,
    .callback = InitTilesetAnim_Cave,
};

const struct Tileset gTileset_MtSilverSnow =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MtSilverSnow,
    .palettes = gTilesetPalettes_MtSilverSnow,
    .metatiles = gMetatiles_MtSilverSnow,
    .metatileAttributes = gMetatileAttributes_MtSilverSnow,
    .callback = NULL,
};

const struct Tileset gTileset_Museum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Museum,
    .palettes = gTilesetPalettes_Museum,
    .metatiles = gMetatiles_Museum,
    .metatileAttributes = gMetatileAttributes_Museum,
    .callback = NULL,
};

const struct Tileset gTileset_NationalPark_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NationalPark_HnS,
    .palettes = gTilesetPalettes_NationalPark_HnS,
    .metatiles = gMetatiles_NationalPark_HnS,
    .metatileAttributes = gMetatileAttributes_NationalPark_HnS,
    .callback = InitTilesetAnim_NationalPark,
};

const struct Tileset gTileset_NewBarkTown_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NewBarkTown_HnS,
    .palettes = gTilesetPalettes_NewBarkTown_HnS,
    .metatiles = gMetatiles_NewBarkTown_HnS,
    .metatileAttributes = gMetatileAttributes_NewBarkTown_HnS,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_OlivineCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OlivineCity_HnS,
    .palettes = gTilesetPalettes_OlivineCity_HnS,
    .metatiles = gMetatiles_OlivineCity_HnS,
    .metatileAttributes = gMetatileAttributes_OlivineCity_HnS,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Pacifidlog_HnS =
{
    .isCompressed = TRUE,
    .swapPalettes = SWAP_PAL(9),
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Pacifidlog_HnS,
    .palettes = gTilesetPalettes_Pacifidlog_HnS,
    .metatiles = gMetatiles_Pacifidlog_HnS,
    .metatileAttributes = gMetatileAttributes_Pacifidlog_HnS,
    .callback = InitTilesetAnim_Pacifidlog,
};

const struct Tileset gTileset_PalletTown_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PalletTown_HnS,
    .palettes = gTilesetPalettes_PalletTown_HnS,
    .metatiles = gMetatiles_PalletTown_HnS,
    .metatileAttributes = gMetatileAttributes_PalletTown_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCity_HnS,
    .palettes = gTilesetPalettes_PewterCity_HnS,
    .metatiles = gMetatiles_PewterCity_HnS,
    .metatileAttributes = gMetatileAttributes_PewterCity_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_PlayersHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PlayersHouse,
    .palettes = gTilesetPalettes_PlayersHouse,
    .metatiles = gMetatiles_PlayersHouse,
    .metatileAttributes = gMetatileAttributes_PlayersHouse,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenter_White =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter_White,
    .palettes = gTilesetPalettes_PokemonCenter_White,
    .metatiles = gMetatiles_PokemonCenter_White,
    .metatileAttributes = gMetatileAttributes_PokemonCenter_White,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonDayCare_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonDayCare_HnS,
    .palettes = gTilesetPalettes_PokemonDayCare_HnS,
    .metatiles = gMetatiles_PokemonDayCare_HnS,
    .metatileAttributes = gMetatileAttributes_PokemonDayCare_HnS,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_PokemonLeague =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonLeague,
    .palettes = gTilesetPalettes_PokemonLeague,
    .metatiles = gMetatiles_PokemonLeague,
    .metatileAttributes = gMetatileAttributes_PokemonLeague,
    .callback = NULL,
};

const struct Tileset gTileset_PortIndoor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PortIndoor,
    .palettes = gTilesetPalettes_PortIndoor,
    .metatiles = gMetatiles_PortIndoor,
    .metatileAttributes = gMetatileAttributes_PortIndoor,
    .callback = NULL,
};

const struct Tileset gTileset_PowerPlant_GeneratorRoom =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PowerPlant_GeneratorRoom,
    .palettes = gTilesetPalettes_PowerPlant_GeneratorRoom,
    .metatiles = gMetatiles_PowerPlant_GeneratorRoom,
    .metatileAttributes = gMetatileAttributes_PowerPlant_GeneratorRoom,
    .callback = NULL,
};

const struct Tileset gTileset_Route32 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Route32,
    .palettes = gTilesetPalettes_Route32,
    .metatiles = gMetatiles_Route32,
    .metatileAttributes = gMetatileAttributes_Route32,
    .callback = NULL,
};

const struct Tileset gTileset_Route38_Farmland =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Route38_Farmland,
    .palettes = gTilesetPalettes_Route38_Farmland,
    .metatiles = gMetatiles_Route38_Farmland,
    .metatileAttributes = gMetatileAttributes_Route38_Farmland,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlphWriting =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlphWriting,
    .palettes = gTilesetPalettes_RuinsOfAlphWriting,
    .metatiles = gMetatiles_RuinsOfAlphWriting,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlphWriting,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlph_B1F =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlph_B1F,
    .palettes = gTilesetPalettes_RuinsOfAlph_B1F,
    .metatiles = gMetatiles_RuinsOfAlph_B1F,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlph_B1F,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlph_Outside =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlph_Outside,
    .palettes = gTilesetPalettes_RuinsOfAlph_Outside,
    .metatiles = gMetatiles_RuinsOfAlph_Outside,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlph_Outside,
    .callback = NULL,
};

const struct Tileset gTileset_Rustboro_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Rustboro_HnS,
    .palettes = gTilesetPalettes_Rustboro_HnS,
    .metatiles = gMetatiles_Rustboro_HnS,
    .metatileAttributes = gMetatileAttributes_Rustboro_HnS,
    .callback = InitTilesetAnim_Rustboro,
};

const struct Tileset gTileset_SafariZoneJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SafariZoneJohto,
    .palettes = gTilesetPalettes_SafariZoneJohto,
    .metatiles = gMetatiles_SafariZoneJohto,
    .metatileAttributes = gMetatileAttributes_SafariZoneJohto,
    .callback = NULL,
};

const struct Tileset gTileset_SafariZone_Entrance =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SafariZone_Entrance,
    .palettes = gTilesetPalettes_SafariZone_Entrance,
    .metatiles = gMetatiles_SafariZone_Entrance,
    .metatileAttributes = gMetatileAttributes_SafariZone_Entrance,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity_FightingDojoVIP =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity_FightingDojoVIP,
    .palettes = gTilesetPalettes_SaffronCity_FightingDojoVIP,
    .metatiles = gMetatiles_SaffronCity_FightingDojoVIP,
    .metatileAttributes = gMetatileAttributes_SaffronCity_FightingDojoVIP,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity_Gym,
    .palettes = gTilesetPalettes_SaffronCity_Gym,
    .metatiles = gMetatiles_SaffronCity_Gym,
    .metatileAttributes = gMetatileAttributes_SaffronCity_Gym,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity_HnS,
    .palettes = gTilesetPalettes_SaffronCity_HnS,
    .metatiles = gMetatiles_SaffronCity_HnS,
    .metatileAttributes = gMetatileAttributes_SaffronCity_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_SeaCottage_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeaCottage_HnS,
    .palettes = gTilesetPalettes_SeaCottage_HnS,
    .metatiles = gMetatiles_SeaCottage_HnS,
    .metatileAttributes = gMetatileAttributes_SeaCottage_HnS,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_ShopRooftop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ShopRooftop,
    .palettes = gTilesetPalettes_ShopRooftop,
    .metatiles = gMetatiles_ShopRooftop,
    .metatileAttributes = gMetatileAttributes_ShopRooftop,
    .callback = NULL,
};

const struct Tileset gTileset_Shop_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Shop_HnS,
    .palettes = gTilesetPalettes_Shop_HnS,
    .metatiles = gMetatiles_Shop_HnS,
    .metatileAttributes = gMetatileAttributes_Shop_HnS,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_SilphCo_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SilphCo_HnS,
    .palettes = gTilesetPalettes_SilphCo_HnS,
    .metatiles = gMetatiles_SilphCo_HnS,
    .metatileAttributes = gMetatileAttributes_SilphCo_HnS,
    .callback = InitTilesetAnim_SilphCo,
};

const struct Tileset gTileset_SootopolisGym_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootopolisGym_HnS,
    .palettes = gTilesetPalettes_SootopolisGym_HnS,
    .metatiles = gMetatiles_SootopolisGym_HnS,
    .metatileAttributes = gMetatileAttributes_SootopolisGym_HnS,
    .callback = InitTilesetAnim_SootopolisGym,
};

const struct Tileset gTileset_SoulHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SoulHouse,
    .palettes = gTilesetPalettes_SoulHouse,
    .metatiles = gMetatiles_SoulHouse,
    .metatileAttributes = gMetatileAttributes_SoulHouse,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerHill_Courtyard =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerHill_Courtyard,
    .palettes = gTilesetPalettes_TrainerHill_Courtyard,
    .metatiles = gMetatiles_TrainerHill_Courtyard,
    .metatileAttributes = gMetatileAttributes_TrainerHill_Courtyard,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerSchool =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerSchool,
    .palettes = gTilesetPalettes_TrainerSchool,
    .metatiles = gMetatiles_TrainerSchool,
    .metatileAttributes = gMetatileAttributes_TrainerSchool,
    .callback = NULL,
};

const struct Tileset gTileset_Unused3 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused3,
    .palettes = gTilesetPalettes_Unused3,
    .metatiles = gMetatiles_Unused3,
    .metatileAttributes = gMetatileAttributes_Unused3,
    .callback = NULL,
};

const struct Tileset gTileset_Vermilion =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Vermilion,
    .palettes = gTilesetPalettes_Vermilion,
    .metatiles = gMetatiles_Vermilion,
    .metatileAttributes = gMetatileAttributes_Vermilion,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionCity_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionCity_Gym,
    .palettes = gTilesetPalettes_VermilionCity_Gym,
    .metatiles = gMetatiles_VermilionCity_Gym,
    .metatileAttributes = gMetatileAttributes_VermilionCity_Gym,
    .callback = NULL,
};

const struct Tileset gTileset_VioletCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VioletCity_HnS,
    .palettes = gTilesetPalettes_VioletCity_HnS,
    .metatiles = gMetatiles_VioletCity_HnS,
    .metatileAttributes = gMetatileAttributes_VioletCity_HnS,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_ViridianCity_Gym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCity_Gym,
    .palettes = gTilesetPalettes_ViridianCity_Gym,
    .metatiles = gMetatiles_ViridianCity_Gym,
    .metatileAttributes = gMetatileAttributes_ViridianCity_Gym,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCity_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCity_HnS,
    .palettes = gTilesetPalettes_ViridianCity_HnS,
    .metatiles = gMetatiles_ViridianCity_HnS,
    .metatileAttributes = gMetatileAttributes_ViridianCity_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianForest_HnS =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianForest_HnS,
    .palettes = gTilesetPalettes_ViridianForest_HnS,
    .metatiles = gMetatiles_ViridianForest_HnS,
    .metatileAttributes = gMetatileAttributes_ViridianForest_HnS,
    .callback = NULL,
};

const struct Tileset gTileset_WhirlIslands =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_WhirlIslands,
    .palettes = gTilesetPalettes_WhirlIslands,
    .metatiles = gMetatiles_WhirlIslands,
    .metatileAttributes = gMetatileAttributes_WhirlIslands,
    .callback = NULL,
};

const struct Tileset gTileset_ssaqua =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ssaqua,
    .palettes = gTilesetPalettes_ssaqua,
    .metatiles = gMetatiles_ssaqua,
    .metatileAttributes = gMetatileAttributes_ssaqua,
    .callback = NULL,
};
