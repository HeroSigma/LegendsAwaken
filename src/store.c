#include "global.h"
#include "item.h"
#include "menu.h"
#include "overworld.h"
#include "shop.h"
#include "strings.h"

// Buffer for generated item lists
static EWRAM_DATA u16 sStoreItemBuffer[ITEMS_COUNT + 1] = {0};

static void Store_OpenCategory(u8 pocket);
static void Task_StoreMenu(u8 taskId);

void CB2_OpenStoreFromStartMenu(void)
{
    u8 taskId = CreateTask(Task_StoreMenu, 8);
    (void)taskId;
}

static const struct MenuAction sStoreMenuActions[] = {
    {gPocketNamesStringsTable[POCKET_ITEMS],      {.u8_void = NULL}},
    {gPocketNamesStringsTable[POCKET_MEDICINE],   {.u8_void = NULL}},
    {gPocketNamesStringsTable[POCKET_BATTLE_ITEMS], {.u8_void = NULL}},
    {gPocketNamesStringsTable[POCKET_POKE_BALLS], {.u8_void = NULL}},
    {gPocketNamesStringsTable[POCKET_TM_HM],      {.u8_void = NULL}},
    {gPocketNamesStringsTable[POCKET_BERRIES],    {.u8_void = NULL}},
    {gText_Cancel, {.u8_void = NULL}},
};

static void Task_StoreMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[1])
    {
    case 0:
    {
        struct WindowTemplate template = {0};
        template.bg = 0;
        template.tilemapLeft = 1;
        template.tilemapTop = 1;
        template.width = 13;
        template.height = ARRAY_COUNT(sStoreMenuActions) * 2;
        template.paletteNum = 15;
        template.baseBlock = 1;
        data[0] = AddWindow(&template);
        SetStdWindowBorderStyle(data[0], FALSE);
        PrintMenuTable(data[0], ARRAY_COUNT(sStoreMenuActions), sStoreMenuActions);
        InitMenuInUpperLeftCornerNormal(data[0], ARRAY_COUNT(sStoreMenuActions), 0);
        PutWindowTilemap(data[0]);
        CopyWindowToVram(data[0], COPYWIN_MAP);
        data[1]++;
        break;
    }
    case 1:
    {
        s8 input = Menu_ProcessInputNoWrap();
        if (input == MENU_NOTHING_CHOSEN)
            break;
        ClearStdWindowAndFrameToTransparent(data[0], TRUE);
        RemoveWindow(data[0]);
        if (input == MENU_B_PRESSED || input == ARRAY_COUNT(sStoreMenuActions) - 1)
        {
            SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        }
        else
        {
            static const u8 sPocketMap[] = {
                POCKET_ITEMS,
                POCKET_MEDICINE,
                POCKET_BATTLE_ITEMS,
                POCKET_POKE_BALLS,
                POCKET_TM_HM,
                POCKET_BERRIES,
            };
            Store_OpenCategory(sPocketMap[input]);
        }
        DestroyTask(taskId);
        break;
    }
    }
}

static void Store_OpenCategory(u8 pocket)
{
    u16 count = 0;
    for (u16 i = 1; i < ITEMS_COUNT; i++)
    {
        if (gItemsInfo[i].pocket == pocket && gItemsInfo[i].price > 0)
        {
            if (pocket == POCKET_TM_HM && i >= ITEM_HM01 && i <= ITEM_HM08)
                continue; // Skip HMs
            sStoreItemBuffer[count++] = i;
        }
    }
    sStoreItemBuffer[count] = ITEM_NONE;
    CreateStoreMenu(sStoreItemBuffer);
}
