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
#include "task.h"
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

// Store function prototypes  
static void HandleQuantitySelectInput(u8 taskId);
static void HandleCartViewInput(u8 taskId);

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
static const u8 sText_StoreQuantity[] = _("Qty: {STR_VAR_1}");
static const u8 sText_StoreTotalCost[] = _("Total: ¥{STR_VAR_1}");
static const u8 sText_StoreMoney[] = _("Money: ¥{STR_VAR_1}");
static const u8 sText_StoreQuantityInstructions[] = _("Use up/down for +/-1, left/right for +/-10");
static const u8 sText_StoreCartEmpty[] = _("Your cart is empty!");
static const u8 sText_StoreCartFull[] = _("Your cart is full!");
static const u8 sText_StoreNotEnoughMoney[] = _("Not enough money!");
static const u8 sText_StorePurchaseComplete[] = _("Thank you for your purchase!");
static const u8 sText_StoreCartHeader[] = _("SHOPPING CART");
static const u8 sText_StoreCartTotal[] = _("Cart Total: ¥{STR_VAR_1}");
static const u8 sText_StoreCartInstructions[] = _("Up/Down: Navigate  A: Remove  B: Back  START: Checkout");
static const u8 sText_StoreRemoveItem[] = _("Remove from cart?");
static const u8 sText_StoreItemRemoved[] = _("Item removed from cart!");
static const u8 sText_StoreCartItems[] = _("Items: {STR_VAR_1}");
static const u8 sText_StoreCartItemFormat[] = _("x{STR_VAR_1} = ¥{STR_VAR_2}");
static const u8 sText_StoreCartControls[] = _("A: Remove  B: Back  START: Checkout");

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
    // // X Items
    // ITEM_X_ATTACK, ITEM_X_DEFENSE, ITEM_X_SP_ATK, ITEM_X_SP_DEF,
    // ITEM_X_SPEED, ITEM_X_ACCURACY, ITEM_DIRE_HIT, ITEM_GUARD_SPEC,
    
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
    ITEM_EXP_CANDY_M, ITEM_EXP_CANDY_L, ITEM_EXP_CANDY_XL,
    
    // Power Items
    ITEM_MACHO_BRACE, ITEM_POWER_WEIGHT, ITEM_POWER_BRACER, ITEM_POWER_BELT,
    ITEM_POWER_LENS, ITEM_POWER_BAND, ITEM_POWER_ANKLET,
    
    // Training enhancers
    ITEM_LUCKY_EGG, ITEM_SOOTHE_BELL,
    
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
static void HandleItemListInput(u8 taskId);
static void HandleItemActionMenuInput(u8 taskId);
static void ExitOnlineStore(void);
static void DrawStoreHeader(void);
static void DrawCurrentCategory(void);
static void DrawItemList(void);
static void DrawItemActionMenu(void);
static void DrawQuantitySelection(void);

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
            sOnlineStoreData->state = STORE_STATE_ITEM_LIST;
            sOnlineStoreData->currentCategory = STORE_CATEGORY_ITEMS;
            sOnlineStoreData->selectedItemIndex = 0;
            sOnlineStoreData->selectedActionIndex = 0;
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
    displayCount = 9; // Show 9 items at once with improved spacing (was 10)
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
        y = (i * 14) + 6; // 14 pixels per line for better spacing, 6 pixel top margin
        
        // Highlight selected item
        if ((startIndex + i) == sOnlineStoreData->selectedItemIndex)
        {
            // Draw selection background with proper padding and centering (lowered by 2 pixels)
            FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 1, y - 1, 218, 13);
            // Add a subtle border effect
            FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(15), 2, y, 216, 11);
            FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 3, y + 1, 214, 9);
            
            // Draw text with white color for contrast on dark background
            const u8 highlightColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, y, 0, 0, highlightColor, TEXT_SKIP_DRAW, itemName);
        }
        else
        {
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, y, 0, 0, color, TEXT_SKIP_DRAW, itemName);
        }
    }
    
    // Draw scroll indicators if needed
    if (startIndex > 0)
    {
        // Up arrow indicator
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 210, 6, 0, 0, color, TEXT_SKIP_DRAW, (const u8*)"↑");
    }
    
    if (startIndex + displayCount < itemCount)
    {
        // Down arrow indicator  
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 210, 120, 0, 0, color, TEXT_SKIP_DRAW, (const u8*)"↓");
    }
    
    CopyWindowToVram(WIN_ITEM_LIST, COPYWIN_FULL);
}

static void DrawItemActionMenu(void)
{
    const u8 color[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
    const u8 *actionTexts[] = {
        sText_StoreBuySingle,
        sText_StoreAddToCart,
        sText_StoreViewCart,
        sText_StoreCheckout
    };
    
    FillWindowPixelBuffer(WIN_ITEM_LIST, PIXEL_FILL(0));
    
    // Show current item name at top
    const u16 *categoryItems = GetStoreCategoryItems(sOnlineStoreData->currentCategory);
    if (categoryItems != NULL)
    {
        u16 selectedItemId = categoryItems[sOnlineStoreData->selectedItemIndex];
        const u8 *itemName = GetItemName(selectedItemId);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 6, 0, 0, color, TEXT_SKIP_DRAW, itemName);
        
        // Show item price
        ConvertIntToDecimalStringN(gStringVar1, GetStoreItemPrice(selectedItemId), STR_CONV_MODE_LEFT_ALIGN, 6);
        StringExpandPlaceholders(gStringVar2, sText_StorePrice);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 22, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2);
    }
    
    // Draw action menu
    for (u8 i = 0; i < 4; i++)
    {
        u8 y = (i * 14) + 40; // 4 options with good spacing
        
        // Highlight selected action
        if (i == sOnlineStoreData->selectedActionIndex)
        {
            const u8 highlightColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 12, y, 0, 0, highlightColor, TEXT_SKIP_DRAW, actionTexts[i]);
        }
        else
        {
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 12, y, 0, 0, color, TEXT_SKIP_DRAW, actionTexts[i]);
        }
    }
    
    CopyWindowToVram(WIN_ITEM_LIST, COPYWIN_FULL);
}

static void DrawQuantitySelection(void)
{
    const u8 color[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
    const u8 highlightColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};
    
    FillWindowPixelBuffer(WIN_ITEM_LIST, PIXEL_FILL(0));
    
    // Get current item info
    const u16 *categoryItems = GetStoreCategoryItems(sOnlineStoreData->currentCategory);
    if (categoryItems != NULL)
    {
        u16 selectedItemId = categoryItems[sOnlineStoreData->selectedItemIndex];
        const u8 *itemName = GetItemName(selectedItemId);
        u32 itemPrice = GetStoreItemPrice(selectedItemId);
        u32 totalCost = itemPrice * sOnlineStoreData->selectedQuantity;
        
        // Show current item name
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 6, 0, 0, color, TEXT_SKIP_DRAW, itemName);
        
        // Show unit price
        ConvertIntToDecimalStringN(gStringVar1, itemPrice, STR_CONV_MODE_LEFT_ALIGN, 6);
        StringExpandPlaceholders(gStringVar2, sText_StorePrice);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 22, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2);
        
        // Show quantity selection (highlighted)
        ConvertIntToDecimalStringN(gStringVar1, sOnlineStoreData->selectedQuantity, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar2, sText_StoreQuantity);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 38, 0, 0, highlightColor, TEXT_SKIP_DRAW, gStringVar2);
        
        // Show total cost
        ConvertIntToDecimalStringN(gStringVar1, totalCost, STR_CONV_MODE_LEFT_ALIGN, 8);
        StringExpandPlaceholders(gStringVar2, sText_StoreTotalCost);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 54, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2);
        
        // Show current money
        ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_LEFT_ALIGN, 8);
        StringExpandPlaceholders(gStringVar2, sText_StoreMoney);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 70, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2);
        
        // Show instructions
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 8, 90, 0, 0, color, TEXT_SKIP_DRAW, sText_StoreQuantityInstructions);
        
        // Show if affordable
        if (totalCost > GetMoney(&gSaveBlock1Ptr->money))
        {
            const u8 errorColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GRAY};
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 8, 106, 0, 0, errorColor, TEXT_SKIP_DRAW, sText_StoreNotEnoughMoney);
        }
    }
    
    CopyWindowToVram(WIN_ITEM_LIST, COPYWIN_FULL);
}

void ShowCartContents(void)
{
    const u8 color[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
    const u8 highlightColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY};
    
    FillWindowPixelBuffer(WIN_ITEM_LIST, PIXEL_FILL(0));
    
    if (sOnlineStoreData->cartSize == 0)
    {
        // Show empty cart message
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 40, 0, 0, color, TEXT_SKIP_DRAW, sText_StoreCartEmpty);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 8, 60, 0, 0, color, TEXT_SKIP_DRAW, sText_StoreCancel);
    }
    else
    {
        u32 cartTotal = 0;
        u8 displayCount = 0;
        u8 maxDisplayItems = 5;  // Show up to 5 items in cart view (reduced due to increased spacing)
        u8 startIndex = 0;
        
        // Calculate scroll offset if needed
        if (sOnlineStoreData->selectedItemIndex >= maxDisplayItems)
        {
            startIndex = sOnlineStoreData->selectedItemIndex - maxDisplayItems + 1;
        }
        
        // Display cart items
        for (u8 i = startIndex; i < sOnlineStoreData->cartSize && displayCount < maxDisplayItems; i++)
        {
            u16 itemId = sOnlineStoreData->cart[i].itemId;
            u16 quantity = sOnlineStoreData->cart[i].quantity;
            u32 itemPrice = GetStoreItemPrice(itemId);
            u32 itemTotal = itemPrice * quantity;
            cartTotal += itemTotal;
            
            const u8 *itemName = GetItemName(itemId);
            u8 y = (displayCount * 24) + 8;  // Increased spacing from 16 to 24 pixels
            
            // Highlight selected item
            if (i == sOnlineStoreData->selectedItemIndex)
            {
                // Item name (highlighted)
                AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, y, 0, 0, highlightColor, TEXT_SKIP_DRAW, itemName);
                
                // Quantity and total (highlighted)
                ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEFT_ALIGN, 3);
                ConvertIntToDecimalStringN(gStringVar2, itemTotal, STR_CONV_MODE_LEFT_ALIGN, 8);
                StringExpandPlaceholders(gStringVar3, sText_StoreCartItemFormat);
                AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 16, y + 12, 0, 0, highlightColor, TEXT_SKIP_DRAW, gStringVar3);
            }
            else
            {
                // Item name (normal)
                AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, y, 0, 0, color, TEXT_SKIP_DRAW, itemName);
                
                // Quantity and total (normal)
                ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEFT_ALIGN, 3);
                ConvertIntToDecimalStringN(gStringVar2, itemTotal, STR_CONV_MODE_LEFT_ALIGN, 8);
                StringExpandPlaceholders(gStringVar3, sText_StoreCartItemFormat);
                AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 16, y + 12, 0, 0, color, TEXT_SKIP_DRAW, gStringVar3);
            }
            
            displayCount++;
        }
        
        // Show cart total at bottom
        ConvertIntToDecimalStringN(gStringVar1, cartTotal, STR_CONV_MODE_LEFT_ALIGN, 8);
        StringExpandPlaceholders(gStringVar2, sText_StoreCartTotal);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 130, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2);
        
        // Show current money
        ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_LEFT_ALIGN, 8);
        StringExpandPlaceholders(gStringVar2, sText_StoreMoney);
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_NORMAL, 8, 144, 0, 0, color, TEXT_SKIP_DRAW, gStringVar2);
        
        // Show instructions
        AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 8, 158, 0, 0, color, TEXT_SKIP_DRAW, sText_StoreCartControls);
        
        // Show affordability
        if (cartTotal > GetMoney(&gSaveBlock1Ptr->money))
        {
            const u8 errorColor[3] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GRAY};
            AddTextPrinterParameterized4(WIN_ITEM_LIST, FONT_SMALL, 8, 172, 0, 0, errorColor, TEXT_SKIP_DRAW, sText_StoreNotEnoughMoney);
        }
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
            if (sOnlineStoreData->state == STORE_STATE_ITEM_ACTION_MENU)
            {
                DrawItemActionMenu();
            }
            else if (sOnlineStoreData->state == STORE_STATE_QUANTITY_SELECT)
            {
                DrawQuantitySelection();
            }
            else if (sOnlineStoreData->state == STORE_STATE_CART_VIEW)
            {
                ShowCartContents();
            }
            else
            {
                DrawItemList();
            }
            sOnlineStoreData->needsRefresh = FALSE;
        }
        
        HandleStoreInput(taskId);
    }
}

static void HandleStoreInput(u8 taskId)
{
    switch (sOnlineStoreData->state)
    {
        case STORE_STATE_ITEM_LIST:
            HandleItemListInput(taskId);
            break;
        case STORE_STATE_ITEM_ACTION_MENU:
            HandleItemActionMenuInput(taskId);
            break;
        case STORE_STATE_QUANTITY_SELECT:
            HandleQuantitySelectInput(taskId);
            break;
        case STORE_STATE_CART_VIEW:
            HandleCartViewInput(taskId);
            break;
        default:
            HandleItemListInput(taskId);
            break;
    }
}

static void HandleItemListInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_EXIT);
        ExitOnlineStore();
        DestroyTask(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        // Handle item selection - show action menu
        const u16 *categoryItems = GetStoreCategoryItems(sOnlineStoreData->currentCategory);
        u16 itemCount = GetStoreCategoryItemCount(sOnlineStoreData->currentCategory);
        
        if (categoryItems != NULL && itemCount > 0 && sOnlineStoreData->selectedItemIndex < itemCount)
        {
            PlaySE(SE_SELECT);
            sOnlineStoreData->state = STORE_STATE_ITEM_ACTION_MENU;
            sOnlineStoreData->selectedActionIndex = 0;
            sOnlineStoreData->needsRefresh = TRUE;
        }
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
            else if (sOnlineStoreData->selectedItemIndex >= sOnlineStoreData->scrollOffset + 5)
            {
                sOnlineStoreData->scrollOffset = sOnlineStoreData->selectedItemIndex - 4;
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
            else if (sOnlineStoreData->selectedItemIndex >= sOnlineStoreData->scrollOffset + 5)
            {
                sOnlineStoreData->scrollOffset = sOnlineStoreData->selectedItemIndex - 4;
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

static void HandleItemActionMenuInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_EXIT);
        sOnlineStoreData->state = STORE_STATE_ITEM_LIST;
        sOnlineStoreData->needsRefresh = TRUE;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        // Handle action selection
        switch (sOnlineStoreData->selectedActionIndex)
        {
            case STORE_ACTION_BUY_SINGLE:
                sOnlineStoreData->state = STORE_STATE_QUANTITY_SELECT;
                sOnlineStoreData->selectedQuantity = 1;
                sOnlineStoreData->needsRefresh = TRUE;
                break;
                
            case STORE_ACTION_ADD_TO_CART:
                sOnlineStoreData->state = STORE_STATE_QUANTITY_SELECT;
                sOnlineStoreData->selectedQuantity = 1;
                sOnlineStoreData->needsRefresh = TRUE;
                break;
                
            case STORE_ACTION_VIEW_CART:
                PlaySE(SE_SELECT);
                sOnlineStoreData->state = STORE_STATE_CART_VIEW;
                sOnlineStoreData->isViewingCart = TRUE;
                sOnlineStoreData->selectedItemIndex = 0;  // Start at first cart item
                sOnlineStoreData->needsRefresh = TRUE;
                break;
                
            case STORE_ACTION_CHECKOUT:
                if (PurchaseCartItems())
                {
                    PlaySE(SE_SHOP);
                    ClearCart();
                    // Show purchase complete message
                }
                else
                {
                    PlaySE(SE_FAILURE);
                    // Show not enough money message
                }
                sOnlineStoreData->state = STORE_STATE_ITEM_LIST;
                sOnlineStoreData->needsRefresh = TRUE;
                break;
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        if (sOnlineStoreData->selectedActionIndex > 0)
            sOnlineStoreData->selectedActionIndex--;
        else
            sOnlineStoreData->selectedActionIndex = STORE_ACTION_CHECKOUT;
        sOnlineStoreData->needsRefresh = TRUE;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        if (sOnlineStoreData->selectedActionIndex < STORE_ACTION_CHECKOUT)
            sOnlineStoreData->selectedActionIndex++;
        else
            sOnlineStoreData->selectedActionIndex = 0;
        sOnlineStoreData->needsRefresh = TRUE;
    }
}

// Handle quantity selection input
static void HandleQuantitySelectInput(u8 taskId)
{
    const u16 *categoryItems = GetStoreCategoryItems(sOnlineStoreData->currentCategory);
    u16 selectedItemId = categoryItems[sOnlineStoreData->selectedItemIndex];
    u32 itemPrice = GetStoreItemPrice(selectedItemId);
    u32 totalCost = itemPrice * sOnlineStoreData->selectedQuantity;
    u32 playerMoney = GetMoney(&gSaveBlock1Ptr->money);
    
    if (JOY_NEW(DPAD_UP))
    {
        if (sOnlineStoreData->selectedQuantity < MAX_ITEM_QUANTITY && totalCost + itemPrice <= playerMoney)
        {
            sOnlineStoreData->selectedQuantity++;
            sOnlineStoreData->needsRefresh = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOnlineStoreData->selectedQuantity > 1)
        {
            sOnlineStoreData->selectedQuantity--;
            sOnlineStoreData->needsRefresh = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (sOnlineStoreData->selectedQuantity > 10)
            sOnlineStoreData->selectedQuantity -= 10;
        else
            sOnlineStoreData->selectedQuantity = 1;
        sOnlineStoreData->needsRefresh = TRUE;
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        u16 maxAffordable = playerMoney / itemPrice;
        u16 newQuantity = sOnlineStoreData->selectedQuantity + 10;
        if (newQuantity <= maxAffordable && newQuantity <= MAX_ITEM_QUANTITY)
            sOnlineStoreData->selectedQuantity = newQuantity;
        else if (maxAffordable <= MAX_ITEM_QUANTITY)
            sOnlineStoreData->selectedQuantity = maxAffordable;
        else
            sOnlineStoreData->selectedQuantity = MAX_ITEM_QUANTITY;
        sOnlineStoreData->needsRefresh = TRUE;
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        // Process the purchase based on the action that brought us here
        if (sOnlineStoreData->selectedActionIndex == STORE_ACTION_BUY_SINGLE)
        {
            if (PurchaseSingleItem(selectedItemId, sOnlineStoreData->selectedQuantity))
            {
                PlaySE(SE_SHOP);
                // Show purchase complete message
            }
            else
            {
                PlaySE(SE_FAILURE);
                // Show error message
            }
        }
        else if (sOnlineStoreData->selectedActionIndex == STORE_ACTION_ADD_TO_CART)
        {
            if (AddItemToCart(selectedItemId, sOnlineStoreData->selectedQuantity))
            {
                PlaySE(SE_SELECT);
            }
            else
            {
                PlaySE(SE_FAILURE);
                // Show cart full message
            }
        }
        sOnlineStoreData->state = STORE_STATE_ITEM_LIST;
        sOnlineStoreData->needsRefresh = TRUE;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        sOnlineStoreData->state = STORE_STATE_ITEM_ACTION_MENU;
        sOnlineStoreData->needsRefresh = TRUE;
        PlaySE(SE_EXIT);
    }
}

// Handle cart view input
static void HandleCartViewInput(u8 taskId)
{
    if (sOnlineStoreData->cartSize == 0)
    {
        // Empty cart - only allow exit
        if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            sOnlineStoreData->state = STORE_STATE_ITEM_LIST;
            sOnlineStoreData->isViewingCart = FALSE;
            sOnlineStoreData->needsRefresh = TRUE;
            PlaySE(SE_EXIT);
        }
        return;
    }
    
    // Navigate cart items
    if (JOY_NEW(DPAD_UP))
    {
        if (sOnlineStoreData->selectedItemIndex > 0)
        {
            sOnlineStoreData->selectedItemIndex--;
            sOnlineStoreData->needsRefresh = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sOnlineStoreData->selectedItemIndex < sOnlineStoreData->cartSize - 1)
        {
            sOnlineStoreData->selectedItemIndex++;
            sOnlineStoreData->needsRefresh = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    
    // Remove item from cart
    if (JOY_NEW(A_BUTTON))
    {
        if (sOnlineStoreData->selectedItemIndex < sOnlineStoreData->cartSize)
        {
            // Remove the selected item
            u8 removeIndex = sOnlineStoreData->selectedItemIndex;
            
            // Shift remaining items down
            for (u8 i = removeIndex; i < sOnlineStoreData->cartSize - 1; i++)
            {
                sOnlineStoreData->cart[i] = sOnlineStoreData->cart[i + 1];
            }
            
            sOnlineStoreData->cartSize--;
            
            // Adjust selection if needed
            if (sOnlineStoreData->selectedItemIndex >= sOnlineStoreData->cartSize && sOnlineStoreData->cartSize > 0)
            {
                sOnlineStoreData->selectedItemIndex = sOnlineStoreData->cartSize - 1;
            }
            
            sOnlineStoreData->needsRefresh = TRUE;
            PlaySE(SE_SELECT);
        }
    }
    
    // Exit cart view
    if (JOY_NEW(B_BUTTON))
    {
        sOnlineStoreData->state = STORE_STATE_ITEM_LIST;
        sOnlineStoreData->isViewingCart = FALSE;
        sOnlineStoreData->selectedItemIndex = 0;  // Reset selection
        sOnlineStoreData->needsRefresh = TRUE;
        PlaySE(SE_EXIT);
    }
    
    // Checkout (START button)
    if (JOY_NEW(START_BUTTON))
    {
        if (sOnlineStoreData->cartSize > 0)
        {
            // Calculate total cost
            u32 totalCost = 0;
            for (u8 i = 0; i < sOnlineStoreData->cartSize; i++)
            {
                u16 itemId = sOnlineStoreData->cart[i].itemId;
                u16 quantity = sOnlineStoreData->cart[i].quantity;
                totalCost += GetStoreItemPrice(itemId) * quantity;
            }
            
            // Check if player can afford it
            if (totalCost <= GetMoney(&gSaveBlock1Ptr->money))
            {
                // Process checkout
                for (u8 i = 0; i < sOnlineStoreData->cartSize; i++)
                {
                    u16 itemId = sOnlineStoreData->cart[i].itemId;
                    u16 quantity = sOnlineStoreData->cart[i].quantity;
                    AddBagItem(itemId, quantity);
                }
                
                // Deduct money
                RemoveMoney(&gSaveBlock1Ptr->money, totalCost);
                
                // Clear cart
                sOnlineStoreData->cartSize = 0;
                
                // Show success message and return to item list
                sOnlineStoreData->state = STORE_STATE_ITEM_LIST;
                sOnlineStoreData->isViewingCart = FALSE;
                sOnlineStoreData->selectedItemIndex = 0;
                sOnlineStoreData->needsRefresh = TRUE;
                PlaySE(SE_SHOP);
            }
            else
            {
                // Not enough money
                PlaySE(SE_FAILURE);
            }
        }
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
        total += GetStoreItemPrice(sOnlineStoreData->cart[i].itemId) * sOnlineStoreData->cart[i].quantity;
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
    u32 cost = GetStoreItemPrice(itemId) * quantity;
    if (GetMoney(&gSaveBlock1Ptr->money) < cost)
        return FALSE;
    
    if (!CheckBagHasSpace(itemId, quantity))
        return FALSE;
    
    AddBagItem(itemId, quantity);
    RemoveMoney(&gSaveBlock1Ptr->money, cost);
    return TRUE;
}

// Get dynamic pricing for store items
u32 GetStoreItemPrice(u16 itemId)
{
    switch (itemId)
    {
        // Items Category
        case ITEM_POTION: return 300;
        case ITEM_ANTIDOTE: return 100;
        case ITEM_BURN_HEAL: return 250;
        case ITEM_ICE_HEAL: return 250;
        case ITEM_AWAKENING: return 250;
        case ITEM_PARALYZE_HEAL: return 200;
        case ITEM_FULL_RESTORE: return 3000;
        case ITEM_MAX_POTION: return 2500;
        case ITEM_HYPER_POTION: return 1200;
        case ITEM_SUPER_POTION: return 700;
        case ITEM_FULL_HEAL: return 600;
        case ITEM_REVIVE: return 1500;
        case ITEM_MAX_REVIVE: return 4000;
        case ITEM_FRESH_WATER: return 200;
        case ITEM_SODA_POP: return 300;
        case ITEM_LEMONADE: return 350;
        case ITEM_MOOMOO_MILK: return 500;
        case ITEM_ENERGY_POWDER: return 500;
        case ITEM_ENERGY_ROOT: return 800;
        case ITEM_HEAL_POWDER: return 450;
        case ITEM_REVIVAL_HERB: return 2800;
        case ITEM_ETHER: return 1200;
        case ITEM_MAX_ETHER: return 2000;
        case ITEM_ELIXIR: return 3000;
        case ITEM_MAX_ELIXIR: return 4500;
        case ITEM_LAVA_COOKIE: return 200;
        case ITEM_BLUE_FLUTE: return 100;
        case ITEM_YELLOW_FLUTE: return 200;
        case ITEM_RED_FLUTE: return 100;
        case ITEM_BLACK_FLUTE: return 400;
        case ITEM_WHITE_FLUTE: return 500;
        case ITEM_BERRY_JUICE: return 100;
        case ITEM_SACRED_ASH: return 20000;
        case ITEM_POKE_DOLL: return 1000;
        case ITEM_FLUFFY_TAIL: return 1000;
        case ITEM_POKE_TOY: return 800;
        case ITEM_ESCAPE_ROPE: return 550;
        case ITEM_REPEL: return 350;
        case ITEM_SUPER_REPEL: return 500;
        case ITEM_MAX_REPEL: return 700;
        case ITEM_LURE: return 400;
        case ITEM_SUPER_LURE: return 550;
        case ITEM_MAX_LURE: return 750;
        case ITEM_SUN_STONE: return 2100;
        case ITEM_MOON_STONE: return 2100;
        case ITEM_FIRE_STONE: return 2100;
        case ITEM_THUNDER_STONE: return 2100;
        case ITEM_WATER_STONE: return 2100;
        case ITEM_LEAF_STONE: return 2100;
        case ITEM_SHINY_STONE: return 2100;
        case ITEM_DUSK_STONE: return 2100;
        case ITEM_DAWN_STONE: return 2100;
        case ITEM_ICE_STONE: return 2100;
        case ITEM_OVAL_STONE: return 2100;
        case ITEM_TINY_MUSHROOM: return 500;
        case ITEM_BIG_MUSHROOM: return 5000;
        case ITEM_PEARL: return 1400;
        case ITEM_BIG_PEARL: return 7500;
        case ITEM_STARDUST: return 2000;
        case ITEM_STAR_PIECE: return 9800;
        case ITEM_NUGGET: return 10000;
        case ITEM_HEART_SCALE: return 100;
        
        // Medicine Category (already included above)
        
        // Pokeballs Category
        case ITEM_POKE_BALL: return 200;
        case ITEM_GREAT_BALL: return 600;
        case ITEM_ULTRA_BALL: return 1200;
        case ITEM_MASTER_BALL: return 250000;
        case ITEM_PREMIER_BALL: return 200;
        case ITEM_HEAL_BALL: return 300;
        case ITEM_NET_BALL: return 1000;
        case ITEM_NEST_BALL: return 1000;
        case ITEM_DIVE_BALL: return 1000;
        case ITEM_DUSK_BALL: return 1000;
        case ITEM_TIMER_BALL: return 1000;
        case ITEM_QUICK_BALL: return 1000;
        case ITEM_REPEAT_BALL: return 1000;
        case ITEM_LUXURY_BALL: return 1000;
        case ITEM_LEVEL_BALL: return 300;
        case ITEM_LURE_BALL: return 300;
        case ITEM_MOON_BALL: return 300;
        case ITEM_FRIEND_BALL: return 300;
        case ITEM_LOVE_BALL: return 300;
        case ITEM_HEAVY_BALL: return 300;
        case ITEM_FAST_BALL: return 300;
        case ITEM_SPORT_BALL: return 300;
        case ITEM_PARK_BALL: return 0;
        case ITEM_CHERISH_BALL: return 1000;
        case ITEM_SAFARI_BALL: return 0;
        
        // Battle Items Category
        case ITEM_X_ATTACK: return 500;
        case ITEM_X_DEFEND: return 550;
        case ITEM_X_SPEED: return 350;
        case ITEM_X_ACCURACY: return 950;
        case ITEM_X_SPECIAL: return 350;
        case ITEM_X_SP_DEF: return 350;
        case ITEM_DIRE_HIT: return 650;
        case ITEM_GUARD_SPEC: return 700;
        case ITEM_POKE_FLUTE: return 20000;
        case ITEM_ABILITY_CAPSULE: return 10000;
        case ITEM_BOTTLE_CAP: return 5000;
        case ITEM_GOLD_BOTTLE_CAP: return 20000;
        case ITEM_DYNAMAX_CANDY: return 40000;
        case ITEM_MAX_HONEY: return 8000;
        
        // Held Items & Battle Items
        case ITEM_CHOICE_BAND: return 15000;
        case ITEM_CHOICE_SPECS: return 15000;
        case ITEM_CHOICE_SCARF: return 15000;
        case ITEM_FLAME_ORB: return 8000;
        case ITEM_TOXIC_ORB: return 8000;
        case ITEM_LIFE_ORB: return 12000;
        case ITEM_FOCUS_SASH: return 6000;
        case ITEM_ASSAULT_VEST: return 10000;
        case ITEM_SAFETY_GOGGLES: return 5000;
        case ITEM_ROCKY_HELMET: return 8000;
        case ITEM_LEFTOVERS: return 15000;
        case ITEM_BLACK_SLUDGE: return 8000;
        case ITEM_EVIOLITE: return 12000;
        case ITEM_AIR_BALLOON: return 5000;
        case ITEM_WEAKNESS_POLICY: return 8000;
        case ITEM_RED_CARD: return 3000;
        case ITEM_EJECT_BUTTON: return 4000;
        
        // Type-boosting items
        case ITEM_SILK_SCARF: return 2000;
        case ITEM_CHARCOAL: return 2000;
        case ITEM_MYSTIC_WATER: return 2000;
        case ITEM_MAGNET: return 2000;
        case ITEM_MIRACLE_SEED: return 2000;
        case ITEM_NEVER_MELT_ICE: return 2000;
        case ITEM_BLACK_BELT: return 2000;
        case ITEM_POISON_BARB: return 2000;
        case ITEM_SOFT_SAND: return 2000;
        case ITEM_SHARP_BEAK: return 2000;
        case ITEM_TWISTED_SPOON: return 2000;
        case ITEM_SILVER_POWDER: return 2000;
        case ITEM_HARD_STONE: return 2000;
        case ITEM_SPELL_TAG: return 2000;
        case ITEM_DRAGON_FANG: return 2000;
        case ITEM_BLACK_GLASSES: return 2000;
        case ITEM_METAL_COAT: return 2000;
        
        // Weather items
        case ITEM_DAMP_ROCK: return 3000;
        case ITEM_HEAT_ROCK: return 3000;
        case ITEM_SMOOTH_ROCK: return 3000;
        case ITEM_ICY_ROCK: return 3000;
        
        // Z-Crystals
        case ITEM_NORMALIUM_Z: return 20000;
        case ITEM_FIRIUM_Z: return 20000;
        case ITEM_WATERIUM_Z: return 20000;
        case ITEM_ELECTRIUM_Z: return 20000;
        case ITEM_GRASSIUM_Z: return 20000;
        case ITEM_ICIUM_Z: return 20000;
        case ITEM_FIGHTINIUM_Z: return 20000;
        case ITEM_POISONIUM_Z: return 20000;
        case ITEM_GROUNDIUM_Z: return 20000;
        case ITEM_FLYINIUM_Z: return 20000;
        case ITEM_PSYCHIUM_Z: return 20000;
        case ITEM_BUGINIUM_Z: return 20000;
        case ITEM_ROCKIUM_Z: return 20000;
        case ITEM_GHOSTIUM_Z: return 20000;
        case ITEM_DRAGONIUM_Z: return 20000;
        case ITEM_DARKINIUM_Z: return 20000;
        case ITEM_STEELIUM_Z: return 20000;
        case ITEM_FAIRIUM_Z: return 20000;
        
        // Gems
        case ITEM_NORMAL_GEM: return 5000;
        case ITEM_FIRE_GEM: return 5000;
        case ITEM_WATER_GEM: return 5000;
        case ITEM_ELECTRIC_GEM: return 5000;
        case ITEM_GRASS_GEM: return 5000;
        case ITEM_ICE_GEM: return 5000;
        case ITEM_FIGHTING_GEM: return 5000;
        case ITEM_POISON_GEM: return 5000;
        case ITEM_GROUND_GEM: return 5000;
        case ITEM_FLYING_GEM: return 5000;
        case ITEM_PSYCHIC_GEM: return 5000;
        case ITEM_BUG_GEM: return 5000;
        case ITEM_ROCK_GEM: return 5000;
        case ITEM_GHOST_GEM: return 5000;
        case ITEM_DRAGON_GEM: return 5000;
        case ITEM_DARK_GEM: return 5000;
        case ITEM_STEEL_GEM: return 5000;
        case ITEM_FAIRY_GEM: return 5000;
        
        // Training - EV Feathers
        case ITEM_HEALTH_FEATHER: return 1500;
        case ITEM_MUSCLE_FEATHER: return 1500;
        case ITEM_RESIST_FEATHER: return 1500;
        case ITEM_GENIUS_FEATHER: return 1500;
        case ITEM_CLEVER_FEATHER: return 1500;
        case ITEM_SWIFT_FEATHER: return 1500;
        
        // Ability modifiers
        case ITEM_ABILITY_PATCH: return 25000;
        
        // Nature Mints
        case ITEM_LONELY_MINT: return 12000;
        case ITEM_ADAMANT_MINT: return 12000;
        case ITEM_NAUGHTY_MINT: return 12000;
        case ITEM_BRAVE_MINT: return 12000;
        case ITEM_BOLD_MINT: return 12000;
        case ITEM_IMPISH_MINT: return 12000;
        case ITEM_LAX_MINT: return 12000;
        case ITEM_RELAXED_MINT: return 12000;
        case ITEM_MODEST_MINT: return 12000;
        case ITEM_MILD_MINT: return 12000;
        case ITEM_RASH_MINT: return 12000;
        case ITEM_QUIET_MINT: return 12000;
        case ITEM_CALM_MINT: return 12000;
        case ITEM_GENTLE_MINT: return 12000;
        case ITEM_CAREFUL_MINT: return 12000;
        case ITEM_SASSY_MINT: return 12000;
        case ITEM_TIMID_MINT: return 12000;
        case ITEM_HASTY_MINT: return 12000;
        case ITEM_JOLLY_MINT: return 12000;
        case ITEM_NAIVE_MINT: return 12000;
        case ITEM_SERIOUS_MINT: return 12000;
        
        // Terrain seeds
        case ITEM_ELECTRIC_SEED: return 3000;
        case ITEM_PSYCHIC_SEED: return 3000;
        case ITEM_MISTY_SEED: return 3000;
        case ITEM_GRASSY_SEED: return 3000;
        
        // Gen IX items
        case ITEM_ABILITY_SHIELD: return 8000;
        case ITEM_CLEAR_AMULET: return 6000;
        case ITEM_PUNCHING_GLOVE: return 7000;
        case ITEM_COVERT_CLOAK: return 9000;
        case ITEM_LOADED_DICE: return 5000;
        case ITEM_BOOSTER_ENERGY: return 15000;
        case ITEM_MIRROR_HERB: return 10000;
        
        // Training Category
        case ITEM_HP_UP: return 9800;
        case ITEM_PROTEIN: return 9800;
        case ITEM_IRON: return 9800;
        case ITEM_CARBOS: return 9800;
        case ITEM_CALCIUM: return 9800;
        case ITEM_RARE_CANDY: return 4800;
        case ITEM_PP_UP: return 9800;
        case ITEM_ZINC: return 9800;
        case ITEM_PP_MAX: return 9800;
        case ITEM_EXP_SHARE: return 3000;
        case ITEM_MACHO_BRACE: return 3000;
        case ITEM_POWER_WEIGHT: return 3000;
        case ITEM_POWER_BRACER: return 3000;
        case ITEM_POWER_BELT: return 3000;
        case ITEM_POWER_LENS: return 3000;
        case ITEM_POWER_BAND: return 3000;
        case ITEM_POWER_ANKLET: return 3000;
        
        // Form Items Category
        case ITEM_BLUE_ORB: return 50000;
        case ITEM_RED_ORB: return 50000;
        case ITEM_PRISON_BOTTLE: return 100000;
        case ITEM_DNA_SPLICERS: return 100000;
        case ITEM_REVEAL_GLASS: return 75000;
        case ITEM_GRACIDEA: return 25000;
        case ITEM_METEORITE: return 30000;
        case ITEM_N_LUNARIZER: return 100000;
        case ITEM_N_SOLARIZER: return 100000;
        case ITEM_RUSTED_SWORD: return 150000;
        case ITEM_RUSTED_SHIELD: return 150000;
        case ITEM_REINS_OF_UNITY: return 200000;
        
        // Mega Stones
        case ITEM_VENUSAURITE: return 75000;
        case ITEM_CHARIZARDITE_X: return 75000;
        case ITEM_CHARIZARDITE_Y: return 75000;
        case ITEM_BLASTOISINITE: return 75000;
        case ITEM_BEEDRILLITE: return 65000;
        case ITEM_PIDGEOTITE: return 65000;
        case ITEM_ALAKAZITE: return 75000;
        case ITEM_SLOWBRONITE: return 70000;
        case ITEM_GENGARITE: return 75000;
        case ITEM_KANGASKHANITE: return 80000;
        case ITEM_PINSIRITE: return 65000;
        case ITEM_GYARADOSITE: return 75000;
        case ITEM_AERODACTYLITE: return 70000;
        case ITEM_MEWTWONITE_X: return 100000;
        case ITEM_MEWTWONITE_Y: return 100000;
        case ITEM_AMPHAROSITE: return 70000;
        case ITEM_STEELIXITE: return 70000;
        case ITEM_SCIZORITE: return 80000;
        case ITEM_HERACRONITE: return 75000;
        case ITEM_HOUNDOOMINITE: return 70000;
        case ITEM_TYRANITARITE: return 80000;
        case ITEM_SCEPTILITE: return 75000;
        case ITEM_BLAZIKENITE: return 80000;
        case ITEM_SWAMPERTITE: return 75000;
        case ITEM_GARDEVOIRITE: return 75000;
        case ITEM_SABLENITE: return 70000;
        case ITEM_MAWILITE: return 70000;
        case ITEM_AGGRONITE: return 70000;
        case ITEM_MEDICHAMITE: return 70000;
        case ITEM_MANECTITE: return 70000;
        case ITEM_SHARPEDONITE: return 70000;
        case ITEM_CAMERUPTITE: return 70000;
        case ITEM_ALTARIANITE: return 70000;
        case ITEM_BANETTITE: return 70000;
        case ITEM_ABSOLITE: return 75000;
        case ITEM_GLALITITE: return 70000;
        case ITEM_SALAMENCITE: return 80000;
        case ITEM_METAGROSSITE: return 80000;
        case ITEM_LATIASITE: return 85000;
        case ITEM_LATIOSITE: return 85000;
        case ITEM_LOPUNNITE: return 70000;
        case ITEM_GARCHOMPITE: return 80000;
        case ITEM_LUCARIONITE: return 75000;
        
        // Arceus Plates
        case ITEM_FLAME_PLATE: return 35000;
        case ITEM_SPLASH_PLATE: return 35000;
        case ITEM_ZAP_PLATE: return 35000;
        case ITEM_MEADOW_PLATE: return 35000;
        case ITEM_ICICLE_PLATE: return 35000;
        case ITEM_FIST_PLATE: return 35000;
        case ITEM_TOXIC_PLATE: return 35000;
        case ITEM_EARTH_PLATE: return 35000;
        case ITEM_SKY_PLATE: return 35000;
        case ITEM_MIND_PLATE: return 35000;
        case ITEM_INSECT_PLATE: return 35000;
        case ITEM_STONE_PLATE: return 35000;
        case ITEM_SPOOKY_PLATE: return 35000;
        case ITEM_DRACO_PLATE: return 35000;
        case ITEM_DREAD_PLATE: return 35000;
        case ITEM_IRON_PLATE: return 35000;
        case ITEM_PIXIE_PLATE: return 35000;
        
        // Genesect Drives
        case ITEM_DOUSE_DRIVE: return 45000;
        case ITEM_SHOCK_DRIVE: return 45000;
        case ITEM_BURN_DRIVE: return 45000;
        case ITEM_CHILL_DRIVE: return 45000;
        
        // Silvally Memories
        case ITEM_FIRE_MEMORY: return 40000;
        case ITEM_WATER_MEMORY: return 40000;
        case ITEM_ELECTRIC_MEMORY: return 40000;
        case ITEM_GRASS_MEMORY: return 40000;
        case ITEM_ICE_MEMORY: return 40000;
        case ITEM_FIGHTING_MEMORY: return 40000;
        case ITEM_POISON_MEMORY: return 40000;
        case ITEM_GROUND_MEMORY: return 40000;
        case ITEM_FLYING_MEMORY: return 40000;
        case ITEM_PSYCHIC_MEMORY: return 40000;
        case ITEM_BUG_MEMORY: return 40000;
        case ITEM_ROCK_MEMORY: return 40000;
        case ITEM_GHOST_MEMORY: return 40000;
        case ITEM_DRAGON_MEMORY: return 40000;
        case ITEM_DARK_MEMORY: return 40000;
        case ITEM_STEEL_MEMORY: return 40000;
        case ITEM_FAIRY_MEMORY: return 40000;
        
        // Legendary Orbs
        case ITEM_ADAMANT_ORB: return 85000;
        case ITEM_LUSTROUS_ORB: return 85000;
        case ITEM_GRISEOUS_ORB: return 85000;
        
        // Other Form Items
        case ITEM_SOUL_DEW: return 60000;
        case ITEM_RED_NECTAR: return 5000;
        case ITEM_YELLOW_NECTAR: return 5000;
        case ITEM_PINK_NECTAR: return 5000;
        case ITEM_PURPLE_NECTAR: return 5000;
        
        // Enhanced Legendary Orbs
        case ITEM_ADAMANT_CRYSTAL: return 120000;
        case ITEM_GRISEOUS_CORE: return 120000;
        case ITEM_LUSTROUS_GLOBE: return 120000;
        
        // Ogerpon Masks
        case ITEM_CORNERSTONE_MASK: return 90000;
        case ITEM_WELLSPRING_MASK: return 90000;
        case ITEM_HEARTHFLAME_MASK: return 90000;
        
        // TMs Category (TM01-TM100)
        case ITEM_TM01: return 3000;
        case ITEM_TM02: return 3000;
        case ITEM_TM03: return 3000;
        case ITEM_TM04: return 1500;
        case ITEM_TM05: return 2000;
        case ITEM_TM06: return 3000;
        case ITEM_TM07: return 2000;
        case ITEM_TM08: return 1500;
        case ITEM_TM09: return 2000;
        case ITEM_TM10: return 2000;
        case ITEM_TM11: return 2000;
        case ITEM_TM12: return 3000;
        case ITEM_TM13: return 3000;
        case ITEM_TM14: return 5500;
        case ITEM_TM15: return 7500;
        case ITEM_TM16: return 2000;
        case ITEM_TM17: return 2000;
        case ITEM_TM18: return 2000;
        case ITEM_TM19: return 3000;
        case ITEM_TM20: return 2000;
        case ITEM_TM21: return 3000;
        case ITEM_TM22: return 3000;
        case ITEM_TM23: return 3000;
        case ITEM_TM24: return 3000;
        case ITEM_TM25: return 5500;
        case ITEM_TM26: return 5500;
        case ITEM_TM27: return 3000;
        case ITEM_TM28: return 2000;
        case ITEM_TM29: return 3000;
        case ITEM_TM30: return 3000;
        case ITEM_TM31: return 3000;
        case ITEM_TM32: return 1500;
        case ITEM_TM33: return 2000;
        case ITEM_TM34: return 3000;
        case ITEM_TM35: return 3000;
        case ITEM_TM36: return 3000;
        case ITEM_TM37: return 2000;
        case ITEM_TM38: return 5500;
        case ITEM_TM39: return 2000;
        case ITEM_TM40: return 2000;
        case ITEM_TM41: return 1500;
        case ITEM_TM42: return 3000;
        case ITEM_TM43: return 2000;
        case ITEM_TM44: return 3000;
        case ITEM_TM45: return 3000;
        case ITEM_TM46: return 2000;
        case ITEM_TM47: return 3000;
        case ITEM_TM48: return 3000;
        case ITEM_TM49: return 3000;
        case ITEM_TM50: return 5500;
        
        // Berries Category
        case ITEM_CHERI_BERRY: return 500;
        case ITEM_CHESTO_BERRY: return 500;
        case ITEM_PECHA_BERRY: return 500;
        case ITEM_RAWST_BERRY: return 500;
        case ITEM_ASPEAR_BERRY: return 500;
        case ITEM_LEPPA_BERRY: return 1000;
        case ITEM_ORAN_BERRY: return 800;
        case ITEM_PERSIM_BERRY: return 700;
        case ITEM_LUM_BERRY: return 2000;
        case ITEM_SITRUS_BERRY: return 1500;
        case ITEM_FIGY_BERRY: return 1200;
        case ITEM_WIKI_BERRY: return 1200;
        case ITEM_MAGO_BERRY: return 1200;
        case ITEM_AGUAV_BERRY: return 1200;
        case ITEM_IAPAPA_BERRY: return 1200;
        case ITEM_RAZZ_BERRY: return 800;
        case ITEM_BLUK_BERRY: return 800;
        case ITEM_NANAB_BERRY: return 800;
        case ITEM_WEPEAR_BERRY: return 800;
        case ITEM_PINAP_BERRY: return 800;
        case ITEM_POMEG_BERRY: return 1500;
        case ITEM_KELPSY_BERRY: return 1500;
        case ITEM_QUALOT_BERRY: return 1500;
        case ITEM_HONDEW_BERRY: return 1500;
        case ITEM_GREPA_BERRY: return 1500;
        case ITEM_TAMATO_BERRY: return 1500;
        case ITEM_CORNN_BERRY: return 1000;
        case ITEM_MAGOST_BERRY: return 1000;
        case ITEM_RABUTA_BERRY: return 1000;
        case ITEM_NOMEL_BERRY: return 1000;
        case ITEM_SPELON_BERRY: return 1000;
        case ITEM_PAMTRE_BERRY: return 1000;
        case ITEM_WATMEL_BERRY: return 1000;
        case ITEM_DURIN_BERRY: return 1000;
        case ITEM_BELUE_BERRY: return 1000;
        case ITEM_LIECHI_BERRY: return 3000;
        case ITEM_GANLON_BERRY: return 3000;
        case ITEM_SALAC_BERRY: return 3000;
        case ITEM_PETAYA_BERRY: return 3000;
        case ITEM_APICOT_BERRY: return 3000;
        case ITEM_LANSAT_BERRY: return 5000;
        case ITEM_STARF_BERRY: return 5000;
        case ITEM_ENIGMA_BERRY: return 4000;
        
        // Default price for items not in the list
        default: return 1000;
    }
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
