#include "global.h"
#include "online_store.h"
#include "main.h"
#include "overworld.h"
#include "menu.h"
#include "bg.h"
#include "graphics.h"
#include "text.h"
#include "text_window.h"
#include "palette.h"
#include "window.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "sound.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "item.h"
#include "money.h"
#include "string_util.h"
#include "item_menu.h"
#include "start_menu.h"
#include "constants/items.h"
#include "field_weather.h"
#include "international_string_util.h"

// Function prototypes for missing functions
void PlayRainStoppingSoundEffect(void);
void CleanupOverworldWindowsAndTilemaps(void);

// Store state data
static struct OnlineStoreData *sOnlineStoreData = NULL;

// Text for store
static const u8 gText_OnlineStore[] = _("LEGENDS ONLINE STORE");

// Store category names
static const u8 sText_StoreItems[] = _("ITEMS");
static const u8 sText_StoreMedicine[] = _("MEDICINE");
static const u8 sText_StoreBalls[] = _("POKé BALLS");
static const u8 sText_StoreBattleItems[] = _("BATTLE ITEMS");
static const u8 sText_StoreTrainingItems[] = _("TRAINING");
static const u8 sText_StoreFormChanging[] = _("FORM ITEMS");
static const u8 sText_StoreTMs[] = _("TMs");

static const u8 *const sStoreCategoryNames[STORE_NUM_CATEGORIES] = 
{
    [STORE_CATEGORY_ITEMS] = sText_StoreItems,
    [STORE_CATEGORY_MEDICINE] = sText_StoreMedicine,
    [STORE_CATEGORY_BALLS] = sText_StoreBalls,
    [STORE_CATEGORY_BATTLE_ITEMS] = sText_StoreBattleItems,
    [STORE_CATEGORY_TRAINING_ITEMS] = sText_StoreTrainingItems,
    [STORE_CATEGORY_FORM_CHANGING_ITEMS] = sText_StoreFormChanging,
    [STORE_CATEGORY_TMS] = sText_StoreTMs,
};

// Store menu text
static const u8 sText_StoreWelcome[] = _("Welcome to the LEGENDS STORE!\nWhat would you like to browse?");
static const u8 sText_StorePrice[] = _("¥{STR_VAR_1}");
static const u8 sText_StoreBuySingle[] = _("BUY");
static const u8 sText_StoreAddToCart[] = _("ADD TO CART");
static const u8 sText_StoreViewCart[] = _("VIEW CART");
static const u8 sText_StoreCheckout[] = _("CHECKOUT");
static const u8 sText_StoreCancel[] = _("CANCEL");
static const u8 sText_StoreQuantity[] = _("How many?");
static const u8 sText_StoreCartEmpty[] = _("Your cart is empty!");
static const u8 sText_StoreCartFull[] = _("Your cart is full!");
static const u8 sText_StoreNotEnoughMoney[] = _("Not enough money!");
static const u8 sText_StorePurchaseComplete[] = _("Thank you for your purchase!");

// Item categories arrays
static const u16 sStoreItemsCategory[] = 
{
    // Field Items
    ITEM_REPEL, ITEM_SUPER_REPEL, ITEM_MAX_REPEL,
    ITEM_LURE, ITEM_SUPER_LURE, ITEM_MAX_LURE,
    ITEM_ESCAPE_ROPE, ITEM_POKE_DOLL, ITEM_FLUFFY_TAIL, ITEM_POKE_TOY,
    
    // Flutes
    ITEM_BLUE_FLUTE, ITEM_YELLOW_FLUTE, ITEM_RED_FLUTE,
    ITEM_BLACK_FLUTE, ITEM_WHITE_FLUTE,
    
    // Treasures
    ITEM_BOTTLE_CAP, ITEM_GOLD_BOTTLE_CAP, ITEM_NUGGET, ITEM_BIG_NUGGET,
    ITEM_TINY_MUSHROOM, ITEM_BIG_MUSHROOM, ITEM_BALM_MUSHROOM,
    ITEM_PEARL, ITEM_BIG_PEARL, ITEM_PEARL_STRING,
    ITEM_STARDUST, ITEM_STAR_PIECE, ITEM_COMET_SHARD,
    ITEM_SHOAL_SALT, ITEM_SHOAL_SHELL,
    ITEM_RED_SHARD, ITEM_BLUE_SHARD, ITEM_YELLOW_SHARD, ITEM_GREEN_SHARD,
    ITEM_HEART_SCALE, ITEM_HONEY, ITEM_RARE_BONE, ITEM_ODD_KEYSTONE, ITEM_PRETTY_FEATHER,
    
    // Fossils
    ITEM_HELIX_FOSSIL, ITEM_DOME_FOSSIL, ITEM_OLD_AMBER,
    ITEM_ROOT_FOSSIL, ITEM_CLAW_FOSSIL, ITEM_ARMOR_FOSSIL, ITEM_SKULL_FOSSIL,
    ITEM_COVER_FOSSIL, ITEM_PLUME_FOSSIL, ITEM_JAW_FOSSIL, ITEM_SAIL_FOSSIL,
    ITEM_FOSSILIZED_BIRD, ITEM_FOSSILIZED_FISH, ITEM_FOSSILIZED_DRAKE, ITEM_FOSSILIZED_DINO,
    
    // Mulch
    ITEM_GROWTH_MULCH, ITEM_DAMP_MULCH, ITEM_STABLE_MULCH, ITEM_GOOEY_MULCH,
    ITEM_RICH_MULCH, ITEM_SURPRISE_MULCH, ITEM_BOOST_MULCH, ITEM_AMAZE_MULCH,
    
    // Apricorns
    ITEM_RED_APRICORN, ITEM_BLUE_APRICORN, ITEM_YELLOW_APRICORN, ITEM_GREEN_APRICORN,
    ITEM_PINK_APRICORN, ITEM_WHITE_APRICORN, ITEM_BLACK_APRICORN,
    
    // Other
    ITEM_WISHING_PIECE, ITEM_GALARICA_TWIG, ITEM_ARMORITE_ORE, ITEM_DYNITE_ORE,
    
    ITEMS_COUNT // End marker
};

static const u16 sStoreMedicineCategory[] = 
{
    // Basic healing
    ITEM_POTION, ITEM_SUPER_POTION, ITEM_HYPER_POTION, ITEM_MAX_POTION, ITEM_FULL_RESTORE,
    ITEM_REVIVE, ITEM_MAX_REVIVE,
    
    // Drinks
    ITEM_FRESH_WATER, ITEM_SODA_POP, ITEM_LEMONADE, ITEM_MOOMOO_MILK,
    
    // Herbal medicines
    ITEM_ENERGY_POWDER, ITEM_ENERGY_ROOT, ITEM_HEAL_POWDER, ITEM_REVIVAL_HERB,
    
    // Status healers
    ITEM_ANTIDOTE, ITEM_PARALYZE_HEAL, ITEM_BURN_HEAL, ITEM_ICE_HEAL,
    ITEM_AWAKENING, ITEM_FULL_HEAL,
    
    // PP restoration
    ITEM_ETHER, ITEM_MAX_ETHER, ITEM_ELIXIR, ITEM_MAX_ELIXIR,
    
    // Special items
    ITEM_BERRY_JUICE, ITEM_SACRED_ASH, ITEM_SWEET_HEART, ITEM_MAX_HONEY,
    
    // Regional specialties
    ITEM_PEWTER_CRUNCHIES, ITEM_RAGE_CANDY_BAR, ITEM_LAVA_COOKIE, ITEM_OLD_GATEAU,
    ITEM_CASTELIACONE, ITEM_LUMIOSE_GALETTE, ITEM_SHALOUR_SABLE, ITEM_BIG_MALASADA,
    
    ITEMS_COUNT // End marker
};

static const u16 sStoreBallsCategory[] = 
{
    ITEM_POKE_BALL, ITEM_GREAT_BALL, ITEM_ULTRA_BALL, ITEM_MASTER_BALL, ITEM_PREMIER_BALL,
    ITEM_HEAL_BALL, ITEM_NET_BALL, ITEM_NEST_BALL, ITEM_DIVE_BALL, ITEM_DUSK_BALL,
    ITEM_TIMER_BALL, ITEM_QUICK_BALL, ITEM_REPEAT_BALL, ITEM_LUXURY_BALL,
    ITEM_LEVEL_BALL, ITEM_LURE_BALL, ITEM_MOON_BALL, ITEM_FRIEND_BALL,
    ITEM_LOVE_BALL, ITEM_FAST_BALL, ITEM_HEAVY_BALL, ITEM_DREAM_BALL,
    ITEM_SAFARI_BALL, ITEM_SPORT_BALL, ITEM_PARK_BALL, ITEM_BEAST_BALL, ITEM_CHERISH_BALL,
    ITEMS_COUNT // End marker
};

static const u16 sStoreBattleItemsCategory[] = 
{
    // X Items
    ITEM_X_ATTACK, ITEM_X_DEFENSE, ITEM_X_SP_ATK, ITEM_X_SP_DEF,
    ITEM_X_SPEED, ITEM_X_ACCURACY, ITEM_DIRE_HIT, ITEM_GUARD_SPEC,
    
    // Mega Stones (condensed list)
    ITEM_VENUSAURITE, ITEM_CHARIZARDITE_X, ITEM_CHARIZARDITE_Y, ITEM_BLASTOISINITE,
    ITEM_ALAKAZITE, ITEM_GENGARITE, ITEM_KANGASKHANITE, ITEM_GYARADOSITE,
    ITEM_AERODACTYLITE, ITEM_MEWTWONITE_X, ITEM_MEWTWONITE_Y,
    ITEM_AMPHAROSITE, ITEM_STEELIXITE, ITEM_SCIZORITE, ITEM_HERACRONITE,
    ITEM_SCEPTILITE, ITEM_BLAZIKENITE, ITEM_SWAMPERTITE, ITEM_GARDEVOIRITE,
    ITEM_SABLENITE, ITEM_MAWILITE, ITEM_AGGRONITE, ITEM_MEDICHAMITE,
    ITEM_SALAMENCITE, ITEM_METAGROSSITE, ITEM_LATIASITE, ITEM_LATIOSITE,
    ITEM_LUCARIONITE, ITEM_GALLADITE, ITEM_DIANCITE,
    
    // Z-Crystals (main types)
    ITEM_NORMALIUM_Z, ITEM_FIRIUM_Z, ITEM_WATERIUM_Z, ITEM_ELECTRIUM_Z,
    ITEM_GRASSIUM_Z, ITEM_ICIUM_Z, ITEM_FIGHTINIUM_Z, ITEM_POISONIUM_Z,
    ITEM_GROUNDIUM_Z, ITEM_FLYINIUM_Z, ITEM_PSYCHIUM_Z, ITEM_BUGINIUM_Z,
    ITEM_ROCKIUM_Z, ITEM_GHOSTIUM_Z, ITEM_DRAGONIUM_Z, ITEM_DARKINIUM_Z,
    ITEM_STEELIUM_Z, ITEM_FAIRIUM_Z,
    
    // Gems
    ITEM_NORMAL_GEM, ITEM_FIRE_GEM, ITEM_WATER_GEM, ITEM_ELECTRIC_GEM,
    ITEM_GRASS_GEM, ITEM_ICE_GEM, ITEM_FIGHTING_GEM, ITEM_POISON_GEM,
    ITEM_GROUND_GEM, ITEM_FLYING_GEM, ITEM_PSYCHIC_GEM, ITEM_BUG_GEM,
    ITEM_ROCK_GEM, ITEM_GHOST_GEM, ITEM_DRAGON_GEM, ITEM_DARK_GEM,
    ITEM_STEEL_GEM, ITEM_FAIRY_GEM,
    
    // Popular Held Items
    ITEM_CHOICE_BAND, ITEM_CHOICE_SPECS, ITEM_CHOICE_SCARF,
    ITEM_FLAME_ORB, ITEM_TOXIC_ORB, ITEM_LIFE_ORB, ITEM_FOCUS_SASH,
    ITEM_ASSAULT_VEST, ITEM_SAFETY_GOGGLES, ITEM_ROCKY_HELMET,
    ITEM_LEFTOVERS, ITEM_BLACK_SLUDGE, ITEM_EVIOLITE, ITEM_AIR_BALLOON,
    ITEM_WEAKNESS_POLICY, ITEM_RED_CARD, ITEM_EJECT_BUTTON,
    
    // Type-boosting items
    ITEM_SILK_SCARF, ITEM_CHARCOAL, ITEM_MYSTIC_WATER, ITEM_MAGNET,
    ITEM_MIRACLE_SEED, ITEM_NEVER_MELT_ICE, ITEM_BLACK_BELT, ITEM_POISON_BARB,
    ITEM_SOFT_SAND, ITEM_SHARP_BEAK, ITEM_TWISTED_SPOON, ITEM_SILVER_POWDER,
    ITEM_HARD_STONE, ITEM_SPELL_TAG, ITEM_DRAGON_FANG, ITEM_BLACK_GLASSES, ITEM_METAL_COAT,
    
    // Weather items
    ITEM_DAMP_ROCK, ITEM_HEAT_ROCK, ITEM_SMOOTH_ROCK, ITEM_ICY_ROCK,
    
    // Terrain seeds
    ITEM_ELECTRIC_SEED, ITEM_PSYCHIC_SEED, ITEM_MISTY_SEED, ITEM_GRASSY_SEED,
    
    // Gen IX items
    ITEM_ABILITY_SHIELD, ITEM_CLEAR_AMULET, ITEM_PUNCHING_GLOVE,
    ITEM_COVERT_CLOAK, ITEM_LOADED_DICE, ITEM_BOOSTER_ENERGY, ITEM_MIRROR_HERB,
    
    ITEMS_COUNT // End marker
};

static const u16 sStoreTrainingItemsCategory[] = 
{
    // Vitamins
    ITEM_HP_UP, ITEM_PROTEIN, ITEM_IRON, ITEM_CALCIUM,
    ITEM_ZINC, ITEM_CARBOS, ITEM_PP_UP, ITEM_PP_MAX,
    
    // EV Feathers
    ITEM_HEALTH_FEATHER, ITEM_MUSCLE_FEATHER, ITEM_RESIST_FEATHER,
    ITEM_GENIUS_FEATHER, ITEM_CLEVER_FEATHER, ITEM_SWIFT_FEATHER,
    
    // Ability modifiers
    ITEM_ABILITY_CAPSULE, ITEM_ABILITY_PATCH,
    
    // Mints
    ITEM_LONELY_MINT, ITEM_ADAMANT_MINT, ITEM_NAUGHTY_MINT, ITEM_BRAVE_MINT,
    ITEM_BOLD_MINT, ITEM_IMPISH_MINT, ITEM_LAX_MINT, ITEM_RELAXED_MINT,
    ITEM_MODEST_MINT, ITEM_MILD_MINT, ITEM_RASH_MINT, ITEM_QUIET_MINT,
    ITEM_CALM_MINT, ITEM_GENTLE_MINT, ITEM_CAREFUL_MINT, ITEM_SASSY_MINT,
    ITEM_TIMID_MINT, ITEM_HASTY_MINT, ITEM_JOLLY_MINT, ITEM_NAIVE_MINT, ITEM_SERIOUS_MINT,
    
    // Candy
    ITEM_RARE_CANDY, ITEM_EXP_CANDY_XS, ITEM_EXP_CANDY_S,
    ITEM_EXP_CANDY_M, ITEM_EXP_CANDY_L, ITEM_EXP_CANDY_XL, ITEM_DYNAMAX_CANDY,
    
    // Power Items
    ITEM_MACHO_BRACE, ITEM_POWER_WEIGHT, ITEM_POWER_BRACER, ITEM_POWER_BELT,
    ITEM_POWER_LENS, ITEM_POWER_BAND, ITEM_POWER_ANKLET,
    
    // Training enhancers
    ITEM_EXP_SHARE, ITEM_LUCKY_EGG, ITEM_SOOTHE_BELL,
    
    // Mochi (Gen IX)
    ITEM_HEALTH_MOCHI, ITEM_MUSCLE_MOCHI, ITEM_RESIST_MOCHI,
    ITEM_GENIUS_MOCHI, ITEM_CLEVER_MOCHI, ITEM_SWIFT_MOCHI, ITEM_FRESH_START_MOCHI,
    
    ITEMS_COUNT // End marker
};

static const u16 sStoreFormChangingItemsCategory[] = 
{
    // Arceus Plates
    ITEM_FLAME_PLATE, ITEM_SPLASH_PLATE, ITEM_ZAP_PLATE, ITEM_MEADOW_PLATE,
    ITEM_ICICLE_PLATE, ITEM_FIST_PLATE, ITEM_TOXIC_PLATE, ITEM_EARTH_PLATE,
    ITEM_SKY_PLATE, ITEM_MIND_PLATE, ITEM_INSECT_PLATE, ITEM_STONE_PLATE,
    ITEM_SPOOKY_PLATE, ITEM_DRACO_PLATE, ITEM_DREAD_PLATE, ITEM_IRON_PLATE, ITEM_PIXIE_PLATE,
    
    // Genesect Drives
    ITEM_DOUSE_DRIVE, ITEM_SHOCK_DRIVE, ITEM_BURN_DRIVE, ITEM_CHILL_DRIVE,
    
    // Silvally Memories
    ITEM_FIRE_MEMORY, ITEM_WATER_MEMORY, ITEM_ELECTRIC_MEMORY, ITEM_GRASS_MEMORY,
    ITEM_ICE_MEMORY, ITEM_FIGHTING_MEMORY, ITEM_POISON_MEMORY, ITEM_GROUND_MEMORY,
    ITEM_FLYING_MEMORY, ITEM_PSYCHIC_MEMORY, ITEM_BUG_MEMORY, ITEM_ROCK_MEMORY,
    ITEM_GHOST_MEMORY, ITEM_DRAGON_MEMORY, ITEM_DARK_MEMORY, ITEM_STEEL_MEMORY, ITEM_FAIRY_MEMORY,
    
    // Legendary Orbs
    ITEM_ADAMANT_ORB, ITEM_LUSTROUS_ORB, ITEM_GRISEOUS_ORB,
    ITEM_RED_ORB, ITEM_BLUE_ORB,
    ITEM_ADAMANT_CRYSTAL, ITEM_GRISEOUS_CORE, ITEM_LUSTROUS_GLOBE,
    
    // Zacian/Zamazenta items
    ITEM_RUSTED_SWORD, ITEM_RUSTED_SHIELD,
    
    // Ogerpon Masks  
    ITEM_CORNERSTONE_MASK, ITEM_WELLSPRING_MASK, ITEM_HEARTHFLAME_MASK,
    
    // Other form-changing items
    ITEM_SOUL_DEW, ITEM_RED_NECTAR, ITEM_YELLOW_NECTAR, ITEM_PINK_NECTAR, ITEM_PURPLE_NECTAR,
    
    ITEMS_COUNT // End marker
};

static const u16 sStoreTMsCategory[] = 
{
    ITEM_TM01, ITEM_TM02, ITEM_TM03, ITEM_TM04, ITEM_TM05,
    ITEM_TM06, ITEM_TM07, ITEM_TM08, ITEM_TM09, ITEM_TM10,
    ITEM_TM11, ITEM_TM12, ITEM_TM13, ITEM_TM14, ITEM_TM15,
    ITEM_TM16, ITEM_TM17, ITEM_TM18, ITEM_TM19, ITEM_TM20,
    ITEM_TM21, ITEM_TM22, ITEM_TM23, ITEM_TM24, ITEM_TM25,
    ITEM_TM26, ITEM_TM27, ITEM_TM28, ITEM_TM29, ITEM_TM30,
    ITEM_TM31, ITEM_TM32, ITEM_TM33, ITEM_TM34, ITEM_TM35,
    ITEM_TM36, ITEM_TM37, ITEM_TM38, ITEM_TM39, ITEM_TM40,
    ITEM_TM41, ITEM_TM42, ITEM_TM43, ITEM_TM44, ITEM_TM45,
    ITEM_TM46, ITEM_TM47, ITEM_TM48, ITEM_TM49, ITEM_TM50,
    ITEM_TM51, ITEM_TM52, ITEM_TM53, ITEM_TM54, ITEM_TM55,
    ITEM_TM56, ITEM_TM57, ITEM_TM58, ITEM_TM59, ITEM_TM60,
    ITEM_TM61, ITEM_TM62, ITEM_TM63, ITEM_TM64, ITEM_TM65,
    ITEM_TM66, ITEM_TM67, ITEM_TM68, ITEM_TM69, ITEM_TM70,
    ITEM_TM71, ITEM_TM72, ITEM_TM73, ITEM_TM74, ITEM_TM75,
    ITEM_TM76, ITEM_TM77, ITEM_TM78, ITEM_TM79, ITEM_TM80,
    ITEM_TM81, ITEM_TM82, ITEM_TM83, ITEM_TM84, ITEM_TM85,
    ITEM_TM86, ITEM_TM87, ITEM_TM88, ITEM_TM89, ITEM_TM90,
    ITEM_TM91, ITEM_TM92, ITEM_TM93, ITEM_TM94, ITEM_TM95,
    ITEM_TM96, ITEM_TM97, ITEM_TM98, ITEM_TM99, ITEM_TM100,
    ITEMS_COUNT // End marker
};

// Array of category item arrays
static const u16 *const sStoreCategoryItems[STORE_NUM_CATEGORIES] = 
{
    [STORE_CATEGORY_ITEMS] = sStoreItemsCategory,
    [STORE_CATEGORY_MEDICINE] = sStoreMedicineCategory,
    [STORE_CATEGORY_BALLS] = sStoreBallsCategory,
    [STORE_CATEGORY_BATTLE_ITEMS] = sStoreBattleItemsCategory,
    [STORE_CATEGORY_TRAINING_ITEMS] = sStoreTrainingItemsCategory,
    [STORE_CATEGORY_FORM_CHANGING_ITEMS] = sStoreFormChangingItemsCategory,
    [STORE_CATEGORY_TMS] = sStoreTMsCategory,
};

// Window IDs
enum
{
    WIN_HEADER,
    WIN_CATEGORY,
    WIN_ITEM_LIST,
    WIN_DESCRIPTION,
    WIN_COUNT
};

// Window templates
static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    [WIN_CATEGORY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 28,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 57,
    },
    [WIN_ITEM_LIST] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 7,
        .width = 28,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 113,
    },
    DUMMY_WIN_TEMPLATE
};

// Background templates
static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

// Function declarations
static void OnlineStoreVBlankCallback(void);
static void OnlineStoreMainCB2(void);
static void Task_OnlineStoreMain(u8 taskId);
static void HandleStoreInput(u8 taskId);
static void ExitOnlineStore(void);
static void DrawStoreHeader(void);
static void DrawCurrentCategory(void);
static void DrawItemList(void);

// Window IDs storage - no longer needed, using direct indices
// static u8 sStoreWindowIds[WIN_COUNT];

// Main callback function
void CB2_OnlineStore(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, 1);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        InitWindows(sWindowTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 4:
        // Allocate store data
        if (sOnlineStoreData == NULL)
        {
            sOnlineStoreData = AllocZeroed(sizeof(struct OnlineStoreData));
            sOnlineStoreData->currentCategory = STORE_CATEGORY_ITEMS;
            sOnlineStoreData->selectedItemIndex = 0;
            sOnlineStoreData->scrollOffset = 0;
            sOnlineStoreData->cartSize = 0;
            sOnlineStoreData->isViewingCart = FALSE;
            sOnlineStoreData->needsRefresh = TRUE;
        }
        gMain.state++;
        break;
    case 5:
        PutWindowTilemap(WIN_HEADER);
        DrawStoreHeader();
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_CATEGORY);
        DrawCurrentCategory();
        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_ITEM_LIST);
        DrawItemList();
        gMain.state++;
        break;
    case 8:
        {
            u8 taskId = CreateTask(Task_OnlineStoreMain, 0);
            gTasks[taskId].data[0] = 0; // Initialize task data
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetVBlankCallback(OnlineStoreVBlankCallback);
            SetMainCallback2(OnlineStoreMainCB2);
            return;
        }
    }
}

static void OnlineStoreVBlankCallback(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void OnlineStoreMainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void DrawStoreHeader(void)
{
    const u8 color[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
    
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_HEADER, FONT_NORMAL, 4, 1, 0, 0, color, TEXT_SKIP_DRAW, gText_OnlineStore);
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawCurrentCategory(void)
{
    const u8 color[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
    const u8 *categoryName;
    
    if (sOnlineStoreData == NULL)
        return;
    
    // Get category name
    categoryName = GetStoreCategoryName(sOnlineStoreData->currentCategory);
    if (categoryName == NULL)
        categoryName = sText_StoreItems;
    
    FillWindowPixelBuffer(WIN_CATEGORY, PIXEL_FILL(1));
    AddTextPrinterParameterized4(WIN_CATEGORY, FONT_NORMAL, 4, 1, 0, 0, color, TEXT_SKIP_DRAW, categoryName);
    AddTextPrinterParameterized4(WIN_CATEGORY, FONT_SMALL, 4, 17, 0, 0, color, TEXT_SKIP_DRAW, sText_StorePrice);
    CopyWindowToVram(WIN_CATEGORY, COPYWIN_FULL);
}

static void DrawItemList(void)
{
    const u8 color[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
    const u16 *categoryItems;
    u16 itemCount;
    u8 displayCount;
    u8 startIndex;
    u8 i, y;
    u16 itemId;
    const u8 *itemName;
    
    if (sOnlineStoreData == NULL)
        return;
    
    // Get items for current category
    categoryItems = GetStoreCategoryItems(sOnlineStoreData->currentCategory);
    itemCount = GetStoreCategoryItemCount(sOnlineStoreData->currentCategory);
    
    if (categoryItems == NULL || itemCount == 0)
    {
        FillWindowPixelBuffer(WIN_ITEM_LIST, PIXEL_FILL(1));
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 4, 4, 0, 0, color, TEXT_SKIP_DRAW, sText_StoreCartEmpty);
        CopyWindowToVram(WIN_ITEM_LIST, COPYWIN_FULL);
        return;
    }
    
    // Calculate display parameters
    displayCount = 10; // Show 10 items at once (12 lines available, leaving space for borders)
    startIndex = sOnlineStoreData->scrollOffset;
    
    // Ensure we don't scroll past the end
    if (startIndex + displayCount > itemCount)
        startIndex = (itemCount > displayCount) ? itemCount - displayCount : 0;
    
    FillWindowPixelBuffer(WIN_ITEM_LIST, PIXEL_FILL(1));
    
    // Draw items
    for (i = 0; i < displayCount && (startIndex + i) < itemCount; i++)
    {
        itemId = categoryItems[startIndex + i];
        itemName = GetItemName(itemId);
        y = (i * 12) + 4; // 12 pixels per line, 4 pixel top margin
        
        // Highlight selected item
        if ((startIndex + i) == sOnlineStoreData->selectedItemIndex)
        {
            // Draw selection background
            FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 2, y - 2, 220, 12);
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 6, y, 0, 0, color, TEXT_SKIP_DRAW, itemName);
        }
        else
        {
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 4, y, 0, 0, color, TEXT_SKIP_DRAW, itemName);
        }
    }
    
    // Draw scroll indicators if needed
    if (startIndex > 0)
    {
        // Up arrow indicator
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 210, 4, 0, 0, color, TEXT_SKIP_DRAW, (const u8*)"↑");
    }
    
    if (startIndex + displayCount < itemCount)
    {
        // Down arrow indicator  
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 210, 108, 0, 0, color, TEXT_SKIP_DRAW, (const u8*)"↓");
    }
    
    CopyWindowToVram(WIN_ITEM_LIST, COPYWIN_FULL);
}

static void Task_OnlineStoreMain(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sOnlineStoreData == NULL)
        {
            ExitOnlineStore();
            DestroyTask(taskId);
            return;
        }
        
        // Refresh display if needed
        if (sOnlineStoreData->needsRefresh)
        {
            DrawCurrentCategory();
            DrawItemList();
            sOnlineStoreData->needsRefresh = FALSE;
        }
        
        HandleStoreInput(taskId);
    }
}

static void HandleStoreInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_EXIT);
        ExitOnlineStore();
        DestroyTask(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        // Handle item selection here later
    }
    else if (JOY_NEW(DPAD_UP))
    {
        u16 itemCount = GetStoreCategoryItemCount(sOnlineStoreData->currentCategory);
        if (itemCount > 0)
        {
            PlaySE(SE_SELECT);
            if (sOnlineStoreData->selectedItemIndex > 0)
                sOnlineStoreData->selectedItemIndex--;
            else
                sOnlineStoreData->selectedItemIndex = itemCount - 1;
            
            // Update scroll position if needed
            if (sOnlineStoreData->selectedItemIndex < sOnlineStoreData->scrollOffset)
            {
                sOnlineStoreData->scrollOffset = sOnlineStoreData->selectedItemIndex;
            }
            else if (sOnlineStoreData->selectedItemIndex >= sOnlineStoreData->scrollOffset + 10)
            {
                sOnlineStoreData->scrollOffset = sOnlineStoreData->selectedItemIndex - 9;
            }
            
            DrawItemList();
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        u16 itemCount = GetStoreCategoryItemCount(sOnlineStoreData->currentCategory);
        if (itemCount > 0)
        {
            PlaySE(SE_SELECT);
            if (sOnlineStoreData->selectedItemIndex < itemCount - 1)
                sOnlineStoreData->selectedItemIndex++;
            else
                sOnlineStoreData->selectedItemIndex = 0;
            
            // Update scroll position if needed
            if (sOnlineStoreData->selectedItemIndex < sOnlineStoreData->scrollOffset)
            {
                sOnlineStoreData->scrollOffset = sOnlineStoreData->selectedItemIndex;
            }
            else if (sOnlineStoreData->selectedItemIndex >= sOnlineStoreData->scrollOffset + 10)
            {
                sOnlineStoreData->scrollOffset = sOnlineStoreData->selectedItemIndex - 9;
            }
            
            DrawItemList();
        }
    }
    else if (JOY_NEW(L_BUTTON))
    {
        PlaySE(SE_SELECT);
        // Cycle categories left
        if (sOnlineStoreData->currentCategory > 0)
            sOnlineStoreData->currentCategory--;
        else
            sOnlineStoreData->currentCategory = STORE_NUM_CATEGORIES - 1;
        
        // Reset item selection when changing categories
        sOnlineStoreData->selectedItemIndex = 0;
        sOnlineStoreData->scrollOffset = 0;
        sOnlineStoreData->needsRefresh = TRUE;
    }
    else if (JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_SELECT);
        // Cycle categories right
        if (sOnlineStoreData->currentCategory < STORE_NUM_CATEGORIES - 1)
            sOnlineStoreData->currentCategory++;
        else
            sOnlineStoreData->currentCategory = 0;
        
        // Reset item selection when changing categories
        sOnlineStoreData->selectedItemIndex = 0;
        sOnlineStoreData->scrollOffset = 0;
        sOnlineStoreData->needsRefresh = TRUE;
    }
}

static void ExitOnlineStore(void)
{
    // Begin fade out
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    
    // Free store data
    if (sOnlineStoreData != NULL)
    {
        Free(sOnlineStoreData);
        sOnlineStoreData = NULL;
    }
    
    // Set callback to return to field
    SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
}

// Implementation of store functions
void InitOnlineStore(void)
{
    if (sOnlineStoreData == NULL)
    {
        sOnlineStoreData = AllocZeroed(sizeof(struct OnlineStoreData));
        sOnlineStoreData->currentCategory = STORE_CATEGORY_ITEMS;
        sOnlineStoreData->selectedItemIndex = 0;
        sOnlineStoreData->scrollOffset = 0;
        sOnlineStoreData->cartSize = 0;
        sOnlineStoreData->isViewingCart = FALSE;
        sOnlineStoreData->needsRefresh = TRUE;
    }
}

void UpdateStoreDisplay(void)
{
    if (sOnlineStoreData != NULL && sOnlineStoreData->needsRefresh)
    {
        DrawStoreInterface();
        sOnlineStoreData->needsRefresh = FALSE;
    }
}

void DrawStoreInterface(void)
{
    // Basic store interface drawing
    // This would need proper window and text rendering
}

void ShowCartContents(void)
{
    if (sOnlineStoreData != NULL)
    {
        sOnlineStoreData->isViewingCart = TRUE;
        sOnlineStoreData->needsRefresh = TRUE;
    }
}

bool8 AddItemToCart(u16 itemId, u16 quantity)
{
    if (sOnlineStoreData == NULL || sOnlineStoreData->cartSize >= MAX_CART_ITEMS)
        return FALSE;
    
    // Check if item already exists in cart
    for (u8 i = 0; i < sOnlineStoreData->cartSize; i++)
    {
        if (sOnlineStoreData->cart[i].itemId == itemId)
        {
            u32 newQuantity = sOnlineStoreData->cart[i].quantity + quantity;
            if (newQuantity > MAX_ITEM_QUANTITY)
                newQuantity = MAX_ITEM_QUANTITY;
            sOnlineStoreData->cart[i].quantity = newQuantity;
            return TRUE;
        }
    }
    
    // Add new item to cart
    sOnlineStoreData->cart[sOnlineStoreData->cartSize].itemId = itemId;
    sOnlineStoreData->cart[sOnlineStoreData->cartSize].quantity = quantity;
    sOnlineStoreData->cartSize++;
    return TRUE;
}

bool8 RemoveItemFromCart(u16 itemId, u16 quantity)
{
    if (sOnlineStoreData == NULL)
        return FALSE;
    
    for (u8 i = 0; i < sOnlineStoreData->cartSize; i++)
    {
        if (sOnlineStoreData->cart[i].itemId == itemId)
        {
            if (sOnlineStoreData->cart[i].quantity <= quantity)
            {
                // Remove entire item
                for (u8 j = i; j < sOnlineStoreData->cartSize - 1; j++)
                {
                    sOnlineStoreData->cart[j] = sOnlineStoreData->cart[j + 1];
                }
                sOnlineStoreData->cartSize--;
            }
            else
            {
                // Reduce quantity
                sOnlineStoreData->cart[i].quantity -= quantity;
            }
            return TRUE;
        }
    }
    return FALSE;
}

void ClearCart(void)
{
    if (sOnlineStoreData != NULL)
    {
        sOnlineStoreData->cartSize = 0;
    }
}

u32 GetCartTotalCost(void)
{
    if (sOnlineStoreData == NULL)
        return 0;
    
    u32 total = 0;
    for (u8 i = 0; i < sOnlineStoreData->cartSize; i++)
    {
        total += STORE_ITEM_PRICE * sOnlineStoreData->cart[i].quantity;
    }
    return total;
}

bool8 IsCartEmpty(void)
{
    return (sOnlineStoreData == NULL || sOnlineStoreData->cartSize == 0);
}

const u16 *GetStoreCategoryItems(u8 category)
{
    if (category >= STORE_NUM_CATEGORIES)
        return NULL;
    return sStoreCategoryItems[category];
}

u16 GetStoreCategoryItemCount(u8 category)
{
    if (category >= STORE_NUM_CATEGORIES)
        return 0;
    
    const u16 *items = sStoreCategoryItems[category];
    u16 count = 0;
    while (items[count] != ITEMS_COUNT)
        count++;
    
    return count;
}

const u8 *GetStoreCategoryName(u8 category)
{
    if (category >= STORE_NUM_CATEGORIES)
        return NULL;
    return sStoreCategoryNames[category];
}

bool8 PurchaseCartItems(void)
{
    if (sOnlineStoreData == NULL || sOnlineStoreData->cartSize == 0)
        return FALSE;
    
    u32 totalCost = GetCartTotalCost();
    if (GetMoney(&gSaveBlock1Ptr->money) < totalCost)
        return FALSE;
    
    // Process purchase
    for (u8 i = 0; i < sOnlineStoreData->cartSize; i++)
    {
        AddBagItem(sOnlineStoreData->cart[i].itemId, sOnlineStoreData->cart[i].quantity);
    }
    
    RemoveMoney(&gSaveBlock1Ptr->money, totalCost);
    ClearCart();
    return TRUE;
}

bool8 PurchaseSingleItem(u16 itemId, u16 quantity)
{
    u32 cost = STORE_ITEM_PRICE * quantity;
    if (GetMoney(&gSaveBlock1Ptr->money) < cost)
        return FALSE;
    
    if (!CheckBagHasSpace(itemId, quantity))
        return FALSE;
    
    AddBagItem(itemId, quantity);
    RemoveMoney(&gSaveBlock1Ptr->money, cost);
    return TRUE;
}

// Start menu callback implementation
bool8 StartMenuStoreCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        // Skip RemoveExtraStartMenuWindows() as it's static in start_menu.c
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OnlineStore);
        return TRUE;
    }
    return FALSE;
}
