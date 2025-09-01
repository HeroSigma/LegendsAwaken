TimelessWood_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, TimelessWood_OnFrame
    .byte 0

TimelessWood_OnFrame:
    map_script_2 VAR_UNUSED_0x40DB, 0, TimelessWood_EventScript_EntryMonologue
    .2byte 0

TimelessWood_EventScript_EntryMonologue::
    lockall
    msgbox TimelessWood_Text_PlayerLine1, MSGBOX_DEFAULT
    msgbox TimelessWood_Text_PlayerLine2, MSGBOX_DEFAULT
    msgbox TimelessWood_Text_PlayerLine3, MSGBOX_DEFAULT
    msgbox TimelessWood_Text_PlayerLine4, MSGBOX_DEFAULT
    msgbox TimelessWood_Text_PlayerLine5, MSGBOX_DEFAULT
    msgbox TimelessWood_Text_PlayerLine6, MSGBOX_DEFAULT
    setvar VAR_UNUSED_0x40DB, 1
    releaseall
    end

@ Red encounter (triggered by coord event)
TimelessWood_EventScript_RedEncounter::
    goto_if_set FLAG_UNUSED_0x027, TimelessWood_EventScript_End
    lockall
    addobject LOCALID_TIMELESS_RED
    setobjectxy LOCALID_TIMELESS_RED, 24, 12
    turnobject LOCALID_TIMELESS_RED, DIR_SOUTH
    special SpawnCameraObject
    applymovement LOCALID_CAMERA, TimelessWood_Movement_CameraPanToRed
    waitmovement 0
    msgbox TimelessWood_Text_RedLine1, MSGBOX_DEFAULT
    msgbox TimelessWood_Text_RedLine2, MSGBOX_DEFAULT
    applymovement LOCALID_TIMELESS_RED, TimelessWood_Movement_RedRight6
    waitmovement 0
    removeobject LOCALID_TIMELESS_RED
    setflag FLAG_UNUSED_0x027
    applymovement LOCALID_CAMERA, TimelessWood_Movement_CameraPanToPlayer
    waitmovement 0
    special RemoveCameraObject
    msgbox TimelessWood_Text_PlayerWhoWasThat, MSGBOX_DEFAULT
    setvar VAR_UNUSED_0x40E5, 1
    releaseall
    end

TimelessWood_Movement_RedRight6:
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

TimelessWood_Movement_CameraPanToRed:
    walk_right
    walk_right
    walk_right
    step_end

TimelessWood_Movement_CameraPanToPlayer:
    walk_left
    walk_left
    walk_left
    step_end

TimelessWood_Text_RedLine1:
    .string "RED: Where am I...?$"

TimelessWood_Text_RedLine2:
    .string "RED: I need to leave. Now.$"

TimelessWood_Text_PlayerWhoWasThat:
    .string "{PLAYER}: Who was that?$"

TimelessWood_Text_PlayerLine1:
	.string "{PLAYER}: Timeless Woods...$"

TimelessWood_Text_PlayerLine2:
	.string "{PLAYER}: Is this what Professor\n"
	.string "Birch meant?$"

TimelessWood_Text_PlayerLine3:
	.string "{PLAYER}: The air feels… still.$"

TimelessWood_Text_PlayerLine4:
	.string "{PLAYER}: Weird… this place feels\n"
	.string "familiar somehow.$"

TimelessWood_Text_PlayerLine5:
	.string "{PLAYER}: I'll keep the DEXNAV on\n"
	.string "and watch the statics.$"

TimelessWood_Text_PlayerLine6:
	.string "{PLAYER}: Move carefully.$"

TimelessWood_EventScript_End::
	end
