#include "global.h"
#include "main.h"
#include "menu.h"
#include "task.h"
#include "overworld.h"
#include "shop.h"
#include "sound.h"
#include "strings.h"
#include "window.h"
#include "constants/item.h"
#include "constants/songs.h"

// Menu actions for the store interface. The text pointers are assigned
// at runtime using the pocket name string table to avoid non-constant
// initializers.
static struct MenuAction sStoreMenuActions[6] =
{
    {NULL, {.u8_void = NULL}},
    {NULL, {.u8_void = NULL}},
    {NULL, {.u8_void = NULL}},
    {NULL, {.u8_void = NULL}},
    {NULL, {.u8_void = NULL}},
    {NULL, {.u8_void = NULL}},
};

// Simple item lists for each pocket category.
static const u16 sStoreItems_Items[] =
{
    ITEM_REPEL,
    ITEM_ESCAPE_ROPE,
    ITEM_LIST_END
};

static const u16 sStoreItems_Medicine[] =
{
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_LIST_END
};

static const u16 sStoreItems_Battle[] =
{
    ITEM_X_ATTACK,
    ITEM_X_DEFENSE,
    ITEM_LIST_END
};

static const u16 sStoreItems_Balls[] =
{
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_LIST_END
};

static const u16 sStoreItems_TmHm[] =
{
    ITEM_TM01,
    ITEM_TM02,
    ITEM_LIST_END
};

static const u16 sStoreItems_Berries[] =
{
    ITEM_ORAN_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_LIST_END
};

static const u16 *const sStoreItemLists[] =
{
    sStoreItems_Items,
    sStoreItems_Medicine,
    sStoreItems_Battle,
    sStoreItems_Balls,
    sStoreItems_TmHm,
    sStoreItems_Berries,
};

enum {
    STORE_STATE_INIT,
    STORE_STATE_MAIN,
};

#define tState     data[0]
#define tWindowId  data[1]

static const struct WindowTemplate sStoreWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 1,
};

static void Task_StoreMenu(u8 taskId);
static void CB2_StoreMenu(void);
static void VBlankCB_StoreMenu(void);

static void CB2_StoreMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_StoreMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_OpenStoreFromStartMenu(void)
{
    // Populate menu texts from the pocket name table
    sStoreMenuActions[0].text = gPocketNamesStringsTable[POCKET_ITEMS];
    sStoreMenuActions[1].text = gPocketNamesStringsTable[POCKET_MEDICINE];
    sStoreMenuActions[2].text = gPocketNamesStringsTable[POCKET_BATTLE_ITEMS];
    sStoreMenuActions[3].text = gPocketNamesStringsTable[POCKET_POKE_BALLS];
    sStoreMenuActions[4].text = gPocketNamesStringsTable[POCKET_TM_HM];
    sStoreMenuActions[5].text = gPocketNamesStringsTable[POCKET_BERRIES];

    // Initialize graphics system
    LoadMessageBoxAndBorderGfx();
    
    // Set up graphics callbacks
    SetVBlankCallback(VBlankCB_StoreMenu);
    SetMainCallback2(CB2_StoreMenu);
    
    CreateTask(Task_StoreMenu, 0);
}

static void Task_StoreMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case STORE_STATE_INIT:
        tWindowId = AddWindow(&sStoreWindowTemplate);
        SetStandardWindowBorderStyle(tWindowId, FALSE);
        PrintMenuTable(tWindowId, ARRAY_COUNT(sStoreMenuActions), sStoreMenuActions);
        InitMenuInUpperLeftCornerNormal(tWindowId, ARRAY_COUNT(sStoreMenuActions), 0);
        ScheduleBgCopyTilemapToVram(0);
        tState = STORE_STATE_MAIN;
        break;
    case STORE_STATE_MAIN:
    {
        s8 input = Menu_ProcessInput();
        if (input == MENU_NOTHING_CHOSEN)
            break;

        ClearStdWindowAndFrameToTransparent(tWindowId, FALSE);
        ClearWindowTilemap(tWindowId);
        RemoveWindow(tWindowId);

        if (input == MENU_B_PRESSED)
        {
            PlaySE(SE_SELECT);
            DestroyTask(taskId);
            SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        else
        {
            PlaySE(SE_SELECT);
            CreateStoreMenu(sStoreItemLists[(u8)input]);
            DestroyTask(taskId);
        }
        break;
    }
    }
}

