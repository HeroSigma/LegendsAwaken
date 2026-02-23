LittlerootTown_PlayersHouse_2F_MapScripts::
# 2 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PlayersHouse_2F_OnTransition
# 3 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_PlayersHouse_2F_OnWarp
	.byte 0


LittlerootTown_PlayersHouse_2F_OnTransition::
# 7 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	call SecretBase_EventScript_SetDecorationFlags
# 8 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	return


LittlerootTown_PlayersHouse_2F_OnWarp::
# 13 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	compare VAR_SECRET_BASE_INITIALIZED, 0
	goto_if_eq LittlerootTown_PlayersHouse_2F_OnWarp_2
LittlerootTown_PlayersHouse_2F_OnWarp_1:
# 16 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq LittlerootTown_PlayersHouse_2F_OnWarp_5
LittlerootTown_PlayersHouse_2F_OnWarp_4:
	return

LittlerootTown_PlayersHouse_2F_OnWarp_2:
# 14 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	goto LittlerootTown_PlayersHouse_2F_EventScript_CheckInitDecor
	goto LittlerootTown_PlayersHouse_2F_OnWarp_1

LittlerootTown_PlayersHouse_2F_OnWarp_5:
# 17 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	goto LittlerootTown_PlayersHouse_2F_EventScript_ShowTruckArrival
	goto LittlerootTown_PlayersHouse_2F_OnWarp_4


LittlerootTown_PlayersHouse_2F_EventScript_CheckInitDecor::
# 23 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	checkplayergender
# 24 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_PlayersHouse_2F_EventScript_CheckInitDecor_2
LittlerootTown_PlayersHouse_2F_EventScript_CheckInitDecor_1:
	return

LittlerootTown_PlayersHouse_2F_EventScript_CheckInitDecor_2:
# 25 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	goto SecretBase_EventScript_InitDecorations
	goto LittlerootTown_PlayersHouse_2F_EventScript_CheckInitDecor_1


LittlerootTown_PlayersHouse_2F_EventScript_ShowTruckArrival::
# 31 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	lockall
# 32 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox gText_Truck_Intro, MSGBOX_DEFAULT
# 33 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox gText_Truck_PlayerReflection, MSGBOX_DEFAULT
# 34 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox gText_Truck_ReadyToExit, MSGBOX_DEFAULT
# 35 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
# 36 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_PlayersHouse_2F_EventScript_PC::
# 41 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	lockall
# 42 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	checkplayergender
# 43 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_PlayersHouse_2F_EventScript_PC_2
LittlerootTown_PlayersHouse_2F_EventScript_PC_1:
# 46 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	goto LittlerootTown_PlayersHouse_2F_EventScript_CheckRivalsPC
	return

LittlerootTown_PlayersHouse_2F_EventScript_PC_2:
# 44 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	goto LittlerootTown_PlayersHouse_2F_EventScript_CheckPlayersPC
	goto LittlerootTown_PlayersHouse_2F_EventScript_PC_1


LittlerootTown_PlayersHouse_2F_EventScript_CheckPlayersPC::
# 50 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 51 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	special DoPCTurnOnEffect
# 52 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	playse SE_PC_ON
# 53 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
# 54 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	special BedroomPC
# 55 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 56 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_PlayersHouse_2F_EventScript_CheckRivalsPC::
# 61 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
# 62 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_PlayersHouse_2F_EventScript_TurnOffPlayerPC::
# 67 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
# 68 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 69 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	special DoPCTurnOffEffect
# 70 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_PlayersHouse_2F_EventScript_Notebook::
# 75 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	return


LittlerootTown_PlayersHouse_2F_EventScript_GameCube::
# 80 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	return


PlayersHouse_2F_EventScript_Notebook::
# 86 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	return


PlayersHouse_2F_EventScript_GameCube::
# 91 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	return


LittlerootTown_PlayersHouse_2F_EventScript_IntroFlicker::
# 96 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	lockall
# 97 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_FlickerThought, MSGBOX_DEFAULT
# 98 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


LittlerootTown_PlayersHouse_2F_EventScript_ZRingBall::
# 103 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	lockall
# 104 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	checkitem ITEM_Z_POWER_RING, 1
# 105 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LittlerootTown_PlayersHouse_2F_EventScript_ZRingBall_2
LittlerootTown_PlayersHouse_2F_EventScript_ZRingBall_1:
# 108 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_PlayerBallSpot, MSGBOX_DEFAULT
# 109 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_PlayerCallMom, MSGBOX_DEFAULT
# 110 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_MomReply, MSGBOX_DEFAULT
# 111 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8000, ITEM_Z_POWER_RING
# 112 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8001, 1
# 113 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	callstd STD_OBTAIN_ITEM
# 114 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_2F_ZRING_BALL
# 115 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	removeobject VAR_LAST_TALKED
# 116 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_DistantVoice, MSGBOX_DEFAULT
# 117 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return

LittlerootTown_PlayersHouse_2F_EventScript_ZRingBall_2:
# 106 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	goto LittlerootTown_PlayersHouse_2F_EventScript_ZRingBall_Empty
	goto LittlerootTown_PlayersHouse_2F_EventScript_ZRingBall_1


LittlerootTown_PlayersHouse_2F_EventScript_ZRingBall_Empty::
# 122 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	msgbox PlayersHouse_2F_Text_EmptyBall, MSGBOX_SIGN
# 123 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	releaseall
	return


PlayersHouse_2F_Text_ClockIsStopped::
# 128 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "The clock is stopped…\p"
	.string "Better set it and start it!\p"
	.string "$"

PlayersHouse_2F_Text_PlayerSafeEnough::
# 134 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "I guess this is safe enough.\n"
	.string "$"

PlayersHouse_2F_Text_Notebook::
# 139 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} flipped open notebook.\n"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open MENU with START.\n"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\n"
	.string "The remaining pages are blank…\p"
	.string "$"

PlayersHouse_2F_Text_ItsAGameCube::
# 149 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "It's a Nintendo GameCube.\n"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as Controller.\n"
	.string "$"

PlayersHouse_2F_Text_FlickerThought::
# 156 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}(Did light just flicker?\n"
	.string "Weird…){COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_PlayerBallSpot::
# 162 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: Huh? There's a Poké Ball here…\n"
	.string "{COLOR DARK_GRAY}$"

PlayersHouse_2F_Text_PlayerCallMom::
# 167 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: Mom, did you put a Poké Ball\n"
	.string "in my room?{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_MomReply::
# 173 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "MOM: No, dear! Maybe movers left it?\n"
	.string "Or maybe it's a welcome gift!\n"
	.string "$"

PlayersHouse_2F_Text_DistantVoice::
# 179 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "A distant voice: Your destiny awaits…\n"
	.string "$"

PlayersHouse_2F_Text_EmptyBall::
# 184 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "The Poké Ball is empty.\n"
	.string "$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom::
# 189 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "MOM: All set? The room looks nice.\n"
	.string "Good. Caelum will be glad you're safe.\n"
	.string "He said to take it easy for now.\n"
	.string "When things calm down, he'll catch up.\n"
	.string "Come downstairs when you're ready.\n"
	.string "$"

PlayersHouse_2F_Text_UpstairsIntro_Male_1::
# 198 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: So this is my room again…\n"
	.string "feels smaller than one back home.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_UpstairsIntro_Male_2::
# 205 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: Still, it's mine.\n"
	.string "A fresh start in HOENN.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_UpstairsIntro_Male_3::
# 212 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: …Back at the Archipelago,\n"
	.string "Father's study was always full of notes\n"
	.string "and machines. This room feels… quiet.\n"
	.string "in comparison.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_UpstairsIntro_Female_1::
# 221 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: So this is my room again…\n"
	.string "it's cozier than what I remember.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_UpstairsIntro_Female_2::
# 228 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: Guess I'll have to\n"
	.string "make it mine all over again.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_UpstairsIntro_Female_3::
# 235 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: …At the Archipelago, Father's\n"
	.string "study always echoed with machines\n"
	.string "and scribbled notes. This room feels…\n"
	.string "still.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_MomDidYouSetClock::
# 244 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "MOM: {PLAYER}! Did you set clock\n"
	.string "yet?\n"
	.string "$"

PlayersHouse_2F_Text_MomMakeSureSchedule::
# 250 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "MOM: Make sure it's right- we'll need\n"
	.string "to keep a proper schedule here in\n"
	.string "LITTLEROOT.\n"
	.string "$"

PlayersHouse_2F_Text_PlayerClockLine_Male::
# 257 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: Yeah, I'll set it. Something\n"
	.string "about seeing the hands move… feels\n"
	.string "grounding.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_PlayerClockLine_Female::
# 265 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: Mm. I'll set it. Something\n"
	.string "about ticking… feels steady.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_WakeUp_ClockDialogue::
# 273 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: The clock… it's stopped.\n"
	.string "How long have I been asleep?\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

PlayersHouse_2F_Text_WakeUp_AfterClock::
# 280 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: There. Clock's set.\n"
	.string "Time to figure out what's going on.\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "$"

Common_Text_LookCloserAtMap::
# 288 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.\n"
	.string "$"

Common_Text_LookCloserAtMapKanto::
# 294 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
	.string "KANTO region map.\n"
	.string "$"

Common_Text_LookCloserAtMapJohto::
# 300 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
	.string "JOHTO region map.\n"
	.string "$"

Common_Text_LookCloserAtMapSevii::
# 306 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{PLAYER} took a closer look at the\n"
	.string "SEVII ISLES map.\n"
	.string "$"

gText_Truck_Intro::
# 313 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}(Where… where am I?\n"
	.string "My head hurts…)\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "I'm in a moving truck…\p"
	.string "It's dark and cramped in here.\p"
	.string "$"

gText_Truck_PlayerReflection::
# 322 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}(How did I get here?\n"
	.string "I don't remember…)\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "The last thing I remember…\p"
	.string "was… what was it?\p"
	.string "$"

gText_Truck_ReadyToExit::
# 331 "data/maps/LittlerootTown_PlayersHouse_2F/scripts.pory"
	.string "{COLOR GREEN}(The truck stopped.\n"
	.string "I should get out.)\n"
	.string "{COLOR DARK_GRAY}\n"
	.string "Time to see what's outside.\p"
	.string "$"
