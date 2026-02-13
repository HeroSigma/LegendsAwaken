#include "global.h"
#include "menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "match_call.h"
#include "field_message_box.h"
#include "text_window.h"
#include "script.h"
#include "field_name_box.h"

static EWRAM_DATA u8 sFieldMessageBoxMode = 0;
EWRAM_DATA u8 gWalkAwayFromSignpostTimer = 0;

static void ExpandStringAndStartDrawFieldMessage(const u8 *, bool32);
static void StartDrawFieldMessage(void);

void InitFieldMessageBox(void)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
    // Ensure nameplate window is marked as not present
    sNamePlateWindowId = WINDOW_NONE;
    gTextFlags.canABSpeedUpPrint = FALSE;
    gTextFlags.useAlternateDownArrow = FALSE;
    gTextFlags.autoScroll = FALSE;
    gTextFlags.forceMidTextSpeed = FALSE;
}

#define tState data[0]

static void Task_DrawFieldMessage(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
        case 0:
            if (gMsgIsSignPost)
                LoadSignPostWindowFrameGfx();
            else
                LoadMessageBoxAndBorderGfx();
            // If a speaker name is set, prepare the name plate before the main message box
            TryShowNamePlate();
            task->tState++;
            break;
        case 1:
        {
            u32 nameboxWinId = GetNameboxWindowId();
            DrawDialogueFrame(0, TRUE);
            if (nameboxWinId != WINDOW_NONE)
                DrawNamebox(nameboxWinId, NAME_BOX_BASE_TILE_NUM - NAME_BOX_BASE_TILES_TOTAL, TRUE);
            task->tState++;
            break;
        }
        case 2:
            if (RunTextPrintersAndIsPrinter0Active() != TRUE)
            {
                sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
                DestroyTask(taskId);
            }
    }
}

#undef tState

static void CreateTask_DrawFieldMessage(void)
{
    CreateTask(Task_DrawFieldMessage, 0x50);
}

static void DestroyTask_DrawFieldMessage(void)
{
    u8 taskId = FindTaskIdByFunc(Task_DrawFieldMessage);
    if (taskId != TASK_NONE)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

static void Task_HidePokenavMessageWhenDone(u8 taskId)
{
    if (!IsMatchCallTaskActive())
    {
        sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
        DestroyTask(taskId);
    }
}

bool8 ShowPokenavFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(Task_HidePokenavMessageWhenDone, 0);
    StartMatchCallFromScript(str);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessage(str, FALSE);
    return TRUE;
}

static bool8 UNUSED ForceShowFieldAutoScrollMessage(const u8 *str)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    return TRUE;
}

// Same as ShowFieldMessage, but instead of accepting a
// string arg it just prints whats already in gStringVar4
bool8 ShowFieldMessageFromBuffer(void)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    StartDrawFieldMessage();
    return TRUE;
}

static void ExpandStringAndStartDrawFieldMessage(const u8 *str, bool32 allowSkippingDelayWithButtonPress)
{
    TrySpawnNamebox(NAME_BOX_BASE_TILE_NUM);
    StringExpandPlaceholders(gStringVar4, str);
    // If a speaker name is set, render the name plate window before starting the message
    TryShowNamePlate();
    AddTextPrinterForMessage(allowSkippingDelayWithButtonPress);
    CreateTask_DrawFieldMessage();
}

static void StartDrawFieldMessage(void)
{
    AddTextPrinterForMessage(TRUE);
    CreateTask_DrawFieldMessage();
}

void HideFieldMessageBox(void)
{
    DestroyTask_DrawFieldMessage();
    ClearDialogWindowAndFrame(0, TRUE);
    DestroyNamebox();
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

u8 GetFieldMessageBoxMode(void)
{
    return sFieldMessageBoxMode;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (sFieldMessageBoxMode == FIELD_MESSAGE_BOX_HIDDEN)
        return TRUE;
    return FALSE;
}

static void UNUSED ReplaceFieldMessageWithFrame(void)
{
    DestroyTask_DrawFieldMessage();
    DrawStdWindowFrame(0, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

void StopFieldMessage(void)
{
    DestroyTask_DrawFieldMessage();
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

// Public setter to specify a speaker name for the next field message
void SetSpeakerName(const u8 *name)
{
    gSpeakerName = name;
}

// Helpers for name plate handling
static void TryShowNamePlate(void)
{
    // Skip drawing nameplate if suppressed via config or flag
    if (OW_SUPPRESS_SPEAKER_NAME || FlagGet(OW_FLAG_SUPPRESS_SPEAKER_NAME))
        return;

    if (gSpeakerName == NULL)
        return;

    if (sNamePlateWindowId == WINDOW_NONE)
    {
        // Compute a reasonable width for the name plate based on string width (in pixels)
        u16 widthPx = GetStringWidth(FONT_NORMAL, gSpeakerName, 0);
        // Add padding and convert to tiles (8px). Clamp within message box width.
        u8 widthTiles = (widthPx + 12 + 7) / 8; // ~1 tile padding
        if (widthTiles < 6)
            widthTiles = 6;
        if (widthTiles > 23)
            widthTiles = 23; // Leave margin inside 27-tile wide dialog

        // Position just above the main dialogue frame so clearing the frame also clears the plate
        struct WindowTemplate win = {
            .bg = 0,
            .tilemapLeft = 3,
            .tilemapTop = 14,
            .width = widthTiles,
            .height = 2,
            .paletteNum = STD_WINDOW_PALETTE_NUM,
            .baseBlock = 0x120 // use a free-ish range separate from 0's default
        };

        sNamePlateWindowId = AddWindow(&win);
        DrawStdWindowFrame(sNamePlateWindowId, TRUE);
        // Print the name (no delay) with slight inset
        AddTextPrinterParameterized(sNamePlateWindowId, FONT_NORMAL, gSpeakerName, 1, 1, TEXT_SKIP_DRAW, NULL);
        PutWindowTilemap(sNamePlateWindowId);
        CopyWindowToVram(sNamePlateWindowId, COPYWIN_FULL);
    }
}

static void DestroyNamePlate(void)
{
    if (sNamePlateWindowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrame(sNamePlateWindowId, TRUE);
        RemoveWindow(sNamePlateWindowId);
        sNamePlateWindowId = WINDOW_NONE;
    }
}
