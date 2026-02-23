LittlerootTown_PlayersHouse_1F_MapScripts::
# 2 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_PlayersHouse_1F_OnLoad
# 3 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_PlayersHouse_1F_OnTransition
	.byte 0


LittlerootTown_PlayersHouse_1F_OnLoad::
# 7 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	compare VAR_INTRO_STATE, 6
	goto_if_lt LittlerootTown_PlayersHouse_1F_OnLoad_2
LittlerootTown_PlayersHouse_1F_OnLoad_1:
	return

LittlerootTown_PlayersHouse_1F_OnLoad_2:
# 8 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	goto LittlerootTown_PlayersHouse_1F_EventScript_SetMovingBoxes
	goto LittlerootTown_PlayersHouse_1F_OnLoad_1


LittlerootTown_PlayersHouse_1F_OnTransition::
# 14 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	compare VAR_INTRO_STATE, 3
	goto_if_eq LittlerootTown_PlayersHouse_1F_OnTransition_2
LittlerootTown_PlayersHouse_1F_OnTransition_1:
# 17 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	compare VAR_INTRO_STATE, 5
	goto_if_eq LittlerootTown_PlayersHouse_1F_OnTransition_5
LittlerootTown_PlayersHouse_1F_OnTransition_4:
# 20 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	compare VAR_INTRO_STATE, 6
	goto_if_eq LittlerootTown_PlayersHouse_1F_OnTransition_8
LittlerootTown_PlayersHouse_1F_OnTransition_7:
	return

LittlerootTown_PlayersHouse_1F_OnTransition_2:
# 15 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	goto LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToDoor
	goto LittlerootTown_PlayersHouse_1F_OnTransition_1

LittlerootTown_PlayersHouse_1F_OnTransition_5:
# 18 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	goto LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToStairs
	goto LittlerootTown_PlayersHouse_1F_OnTransition_4

LittlerootTown_PlayersHouse_1F_OnTransition_8:
# 21 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	goto LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToTV
# 23 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_INTRO_STATE, 7
	goto LittlerootTown_PlayersHouse_1F_OnTransition_7


LittlerootTown_PlayersHouse_1F_EventScript_SetMovingBoxes::
# 29 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
# 30 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return


LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToDoor::
# 35 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setobjectxyperm 1, 8, 4
# 36 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToStairs::
# 41 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setobjectxyperm 1, 4, 5
# 42 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_PlayersHouse_1F_EventScript_MoveMomToTV::
# 47 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setobjectxyperm 1, 4, 5
# 48 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


LittlerootTown_PlayersHouse_1F_EventScript_GoSeeRoom::
# 53 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	lockall
# 54 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 55 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_0x8005, MALE
# 56 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 57 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 58 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	goto LittlerootTown_PlayersHouse_1F_EventScript_MomGoSeeRoom
	return


LittlerootTown_PlayersHouse_1F_EventScript_MomGoSeeRoom::
# 63 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox LittlerootTown_PlayersHouse_1F_Text_MomSeeRoom, MSGBOX_DEFAULT
	return


LittlerootTown_PlayersHouse_1F_EventScript_PetalburgGymReport::
# 68 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_INTRO_STATE, 7
# 69 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterRight
# 70 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 71 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	call LittlerootTown_PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
# 72 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_PlayersHouse_1F_Movement_PlayerApproachTVForGym
# 73 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 74 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
# 75 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
# 76 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 77 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement VAR_0x8005, LittlerootTown_PlayersHouse_1F_Movement_MomMakeRoomToSeeTV
# 78 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 79 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_PlayersHouse_1F_Movement_PlayerMoveToTV
# 80 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 81 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	call LittlerootTown_PlayersHouse_1F_EventScript_WatchBroadcastWithFlicker
# 82 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 83 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 84 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
# 85 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
# 86 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox LittlerootTown_PlayersHouse_1F_Text_ThingsMovedOut, MSGBOX_DEFAULT
# 87 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox LittlerootTown_PlayersHouse_1F_Text_StartYourAdventure, MSGBOX_DEFAULT
# 88 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	givemon SPECIES_PICHU, 3
# 89 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 90 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 91 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 92 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	message LittlerootTown_PlayersHouse_1F_Text_PlayerReceivedPichu
# 93 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmessage
# 94 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitfanfare
# 95 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 96 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_PlayersHouse_1F_EventScript_PetalburgGymReport_2
LittlerootTown_PlayersHouse_1F_EventScript_PetalburgGymReport_1:
# 99 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	call LittlerootTown_PlayersHouse_1F_EventScript_MomLeaving
	return

LittlerootTown_PlayersHouse_1F_EventScript_PetalburgGymReport_2:
# 97 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	goto LittlerootTown_PlayersHouse_1F_EventScript_NicknameMon
	goto LittlerootTown_PlayersHouse_1F_EventScript_PetalburgGymReport_1


LittlerootTown_PlayersHouse_1F_EventScript_NicknameMon::
# 104 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_0x8004, 0
# 105 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 106 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	call LittlerootTown_PlayersHouse_1F_EventScript_MomLeaving
	return


LittlerootTown_PlayersHouse_1F_EventScript_MomLeaving::
# 111 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox LittlerootTown_PlayersHouse_1F_Text_TakeCareOfHouse, MSGBOX_DEFAULT
# 112 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_PlayersHouse_1F_Movement_WalkRight
# 113 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement VAR_0x8005, LittlerootTown_PlayersHouse_1F_Movement_MomLeaveAndReturn
# 114 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 115 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox LittlerootTown_PlayersHouse_1F_Text_AlmostForgot, MSGBOX_DEFAULT
# 116 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	givemon SPECIES_RAYQUAZA, 100
# 117 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	givemon SPECIES_SWAMPERT, 100
# 118 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	givemon SPECIES_TROPIUS, 100
# 119 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_HM_SURF
# 120 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_HM_FLY
# 121 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_HM_DIVE
# 122 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 123 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_HM_CUT
# 124 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_HM_ROCK_SMASH
# 125 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_HM_FLASH
# 126 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_MACH_BIKE
# 127 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_ACRO_BIKE
# 128 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement VAR_0x8005, LittlerootTown_PlayersHouse_1F_Movement_MomLeave
# 129 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 130 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	removeobject 1
# 131 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	playse SE_EXIT
# 132 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_HIDE_PLAYERS_HOUSE_MOM
# 133 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 134 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_SYS_B_DASH
	return


LittlerootTown_PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
# 139 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox LittlerootTown_PlayersHouse_1F_Text_MomNoticeGymBroadcast, MSGBOX_DEFAULT
	return


LittlerootTown_PlayersHouse_1F_EventScript_WatchBroadcastWithFlicker::
# 144 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 145 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 146 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_TVHoennCollab_Intro, MSGBOX_DEFAULT
# 147 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	special TurnOffTVScreen
# 148 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	playse SE_THUNDER
# 149 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_0x8004, 1
# 150 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_0x8005, 1
# 151 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_0x8006, 6
# 152 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_0x8007, 3
# 153 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	special ShakeCamera
# 154 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	waitstate
# 155 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	delay 20
# 156 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	special TurnOnTVScreen
# 157 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	msgbox PlayersHouse_1F_Text_TVHoennCollab_Distortion, MSGBOX_DEFAULT
# 158 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	fadedefaultbgm
# 159 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	special TurnOffTVScreen
# 160 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_SYS_TV_HOME
# 161 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	delay 35
	return


# 166 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
LittlerootTown_PlayersHouse_1F_Movement_PlayerApproachTVForGym:
# 167 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 167 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 168 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 168 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 168 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 169 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	step_end

# 172 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
LittlerootTown_PlayersHouse_1F_Movement_WalkRight:
# 173 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 173 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 173 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 174 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	step_end

# 177 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
LittlerootTown_PlayersHouse_1F_Movement_MomMakeRoomToSeeTV:
# 178 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_in_place_faster_down
# 179 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	step_end

# 182 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
LittlerootTown_PlayersHouse_1F_Movement_PlayerMoveToTV:
# 183 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 183 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_left
# 184 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	step_end

# 187 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
LittlerootTown_PlayersHouse_1F_Movement_MomLeaveAndReturn:
# 188 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 188 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 188 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 189 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 189 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 190 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 190 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 191 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 191 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 192 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 192 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 193 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	delay_16
# 193 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	delay_16
# 194 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 195 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	step_end

# 198 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
LittlerootTown_PlayersHouse_1F_Movement_MomLeave:
# 199 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 199 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 199 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 200 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 200 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 201 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 201 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	walk_right
# 202 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	step_end

PlayersHouse_1F_Text_GoSetTheClock::
# 206 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: {PLAYER}, could you set the\n"
	.string "clock for me?\p"
	.string "It's upstairs in your room.\n$"

LittlerootTown_PlayersHouse_1F_Text_MomSeeRoom::
# 212 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: How do you like your room?\p"
	.string "It's smaller than our old one,\n"
	.string "but it's cozy, right?\n$"

LittlerootTown_PlayersHouse_1F_Text_MomNoticeGymBroadcast::
# 218 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Oh! They're making an\n"
	.string "announcement on TV!\p"
	.string "$"

PlayersHouse_1F_Text_MaybeDadWillBeOn::
# 224 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Maybe your father will be on!\n"
	.string "He sometimes appears on TV when\n"
	.string "there are big discoveries.\p"
	.string "$"

PlayersHouse_1F_Text_TVHoennCollab_Intro::
# 231 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "ANNOUNCER: We interrupt this program\n"
	.string "with breaking news from the HOENN\n"
	.string "region!\p"
	.string "$"

PlayersHouse_1F_Text_TVHoennCollab_Distortion::
# 238 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "ANNOUNCER: Strange energy readings\n"
	.string "detected across the region. Scientists\n"
	.string "are calling it 'distortion events'.\p"
	.string "Citizens are advised to stay alert\n"
	.string "and report unusual activity.\p"
	.string "$"

PlayersHouse_1F_Text_ItsOverWeMissedHim::
# 247 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Oh, it's over!\n"
	.string "We missed him!\p"
	.string "$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor::
# 253 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Go introduce yourself to the\n"
	.string "neighbor next door!\p"
	.string "$"

LittlerootTown_PlayersHouse_1F_Text_ThingsMovedOut::
# 259 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: All of our things are finally\n"
	.string "moved in.\p"
	.string "It feels like everything is ready\n"
	.string "for you to begin your journey.\p"
	.string "$"

LittlerootTown_PlayersHouse_1F_Text_StartYourAdventure::
# 267 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: It's time to start your very own\n"
	.string "adventure, {PLAYER}!\p"
	.string "Go make friends and discover new\n"
	.string "POKEMON!\p"
	.string "$"

LittlerootTown_PlayersHouse_1F_Text_PlayerReceivedPichu::
# 275 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "{PLAYER} received PICHU!\p"
	.string "$"

LittlerootTown_PlayersHouse_1F_Text_TakeCareOfHouse::
# 280 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Take care of the house while\n"
	.string "I'm away, okay?\p"
	.string "I'll be thinking of you!\p"
	.string "$"

LittlerootTown_PlayersHouse_1F_Text_AlmostForgot::
# 287 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: I almost forgot!\p"
	.string "I spoke to a man named Professor Birch\n"
	.string "here in Littleroot earlier today.\p"
	.string "He wants you to visit him in his lab,\p"
	.string "please go and see him!\p"
	.string "Bye {PLAYER}!\p"
	.string "$"

PlayersHouse_1F_Text_SeeYouHoney::
# 298 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: See you later, honey!\p"
	.string "Take care!\n$"

PlayersHouse_1F_Text_TakeCareHoney::
# 303 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Take care of the house while\n"
	.string "I'm away, honey!\p"
	.string "I'll be thinking of you!\n$"

PlayersHouse_1F_Text_DidYouMeetProfBirch::
# 309 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Did you meet Professor Birch?\p"
	.string "He wanted to see you, right?\n$"

PlayersHouse_1F_Text_Vigoroth1::
# 314 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "VIGOROTH: Vigoroth!\n$"

PlayersHouse_1F_Text_Vigoroth2::
# 318 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "VIGOROTH: Vigoroth vigoroth!\n$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou::
# 322 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: A ticket from Briney came for you!\p"
	.string "It's a S.S. TICKET!\p"
	.string "You can take the ferry to SLATEPORT\n"
	.string "or LILYCOVE now!\p"
	.string "$"

PlayersHouse_1F_Text_PortsInSlateportLilycove::
# 330 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: The ferry can take you to\n"
	.string "SLATEPORT or LILYCOVE.\p"
	.string "Be sure to visit the markets there!\p"
	.string "$"

PlayersHouse_1F_Text_BetterGetBackToGym::
# 337 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Your father should get back\n"
	.string "to his GYM soon.\p"
	.string "He's been away too long!\p"
	.string "$"

PlayersHouse_1F_Text_DadShouldStayLonger::
# 344 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Your father should stay\n"
	.string "longer with us.\p"
	.string "But he has his duties...\p"
	.string "$"

PlayersHouse_1F_Text_IsThatABreakingStory::
# 351 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Is that a breaking story?\p"
	.string "Let's watch!\p"
	.string "$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash::
# 357 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "ANNOUNCER: Emergency news flash!\p"
	.string "Legendary LATIOS/LATIAS spotted!\p"
	.string "Citizens advised to stay alert!\p"
	.string "$"

PlayersHouse_1F_Text_WhatColorDidTheySay::
# 364 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: What color did they say?\p"
	.string "I missed it!\p"
	.string "$"

PlayersHouse_1F_Text_StillUnknownPokemon::
# 370 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Still so many unknown\n"
	.string "POKEMON in the world...\p"
	.string "Amazing!\p"
	.string "$"

PlayersHouse_1F_Text_RunningShoesManual::
# 377 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Here are some RUNNING SHOES!\p"
	.string "You can run by holding the B button!\p"
	.string "Try it out!\p"
	.string "$"

PlayersHouse_1F_Text_OhComeQuickly::
# 385 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Oh, come quickly!\p"
	.string "They're making an announcement on TV!\p"
	.string "$"

PlayersHouse_1F_Text_ReportFromPetalburgGym::
# 391 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "ANNOUNCER: We have a report from\n"
	.string "the PETALBURG GYM!\p"
	.string "Norman's research is making headlines!\p"
	.string "$"

PlayersHouse_1F_Text_IsntItNiceInHere::
# 398 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Isn't it nice in here?\p"
	.string "All settled in finally.\p"
	.string "$"

PlayersHouse_1F_Text_DontPushYourselfTooHard::
# 404 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Don't push yourself too hard!\p"
	.string "Take breaks when you need them.\p"
	.string "$"

PlayersHouse_1F_Text_IsThatAPokenav::
# 410 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Is that a POKÉNAV?\p"
	.string "Let me register my number!\p"
	.string "$"

PlayersHouse_1F_Text_RegisteredMom::
# 416 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: I've registered my number!\p"
	.string "Call me anytime!\p"
	.string "$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom::
# 422 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: You got Dad's badge?\p"
	.string "Here's something from me!\p"
	.string "$"

PlayersHouse_1F_Text_YouShouldRestABit::
# 428 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: You should rest a bit.\p"
	.string "Your POKEMON look tired.\p"
	.string "$"

PlayersHouse_1F_Text_TheresAMovieOnTV::
# 435 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: There's a movie on TV!\p"
	.string "Want to watch it together?\p"
	.string "$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock::
# 441 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: The movers brought our things!\p"
	.string "Your POKEMON are all settled in.\p"
	.string "Could you set the clock upstairs?\p"
	.string "$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom::
# 448 "data/maps/LittlerootTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Aren't you interested in your room?\p"
	.string "Go take a look upstairs!\p"
	.string "$"
