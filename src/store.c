#include "global.h"
#include "main.h"
#include "menu.h"
#include "task.h"
#include "overworld.h"
#include "strings.h"
#include "constants/item.h"

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

static void Task_StoreMenu(u8 taskId);

void CB2_OpenStoreFromStartMenu(void)
{
    // Populate menu texts from the pocket name table
    sStoreMenuActions[0].text = gPocketNamesStringsTable[POCKET_ITEMS];
    sStoreMenuActions[1].text = gPocketNamesStringsTable[POCKET_MEDICINE];
    sStoreMenuActions[2].text = gPocketNamesStringsTable[POCKET_BATTLE_ITEMS];
    sStoreMenuActions[3].text = gPocketNamesStringsTable[POCKET_POKE_BALLS];
    sStoreMenuActions[4].text = gPocketNamesStringsTable[POCKET_TM_HM];
    sStoreMenuActions[5].text = gPocketNamesStringsTable[POCKET_BERRIES];

    CreateTask(Task_StoreMenu, 0);
}

static void Task_StoreMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        SetStandardWindowBorderStyle(0, FALSE);
        data[0] = 1;
        break;
    case 1:
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
        break;
    }
}
