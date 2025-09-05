InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	compare VAR_LITTLEROOT_INTRO_STATE, 0
	call_if_eq InsideOfTruck_EventScript_IntroText
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_EventScript_MysteriousBox::
	msgbox gText_Truck_MysteriousBox, MSGBOX_SIGN
	end

InsideOfTruck_EventScript_DevonBox::
	msgbox gText_Truck_DevenCorpBox, MSGBOX_SIGN
	end

InsideOfTruck_EventScript_MemoryBox::
	msgbox gText_Truck_MemoryBox, MSGBOX_SIGN
	end


// Always set the dynamic warp at the truck exit tile before leaving
InsideOfTruck_EventScript_TruckExitSetDynamicWarp::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_TruckExitSetDynamicWarpMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_TruckExitSetDynamicWarpFemale
	end

InsideOfTruck_EventScript_TruckExitSetDynamicWarpMale::
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	end

InsideOfTruck_EventScript_TruckExitSetDynamicWarpFemale::
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	end

InsideOfTruck_EventScript_IntroText::
	lockall
	msgbox gText_Truck_Intro, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, InsideOfTruck_Movement_PlayerLookAround
	waitmovement 0
	msgbox gText_Truck_ReadyToExit, MSGBOX_DEFAULT
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	releaseall
	end

InsideOfTruck_Movement_PlayerLookAround:
	delay_16
	face_left
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_down
	step_end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

