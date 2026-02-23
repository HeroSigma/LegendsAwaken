Route101_MapScripts::
# 2 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
# 3 "data/maps/Route101/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route101_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Route101/scripts.pory"
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0


Route101_OnTransition::
# 7 "data/maps/Route101/scripts.pory"
	call ProfBirch_EventScript_UpdateLocation
	return


Route101_EventScript_HideMapNamePopup::
# 12 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 13 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 1
	return


Route101_EventScript_StartBirchRescue::
# 18 "data/maps/Route101/scripts.pory"
	lockall
# 19 "data/maps/Route101/scripts.pory"
	playbgm MUS_HELP, TRUE
# 20 "data/maps/Route101/scripts.pory"
	setflag FLAG_TEMP_5
# 21 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
# 22 "data/maps/Route101/scripts.pory"
	closemessage
# 23 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_BIRCH, 0, 15
# 24 "data/maps/Route101/scripts.pory"
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 0, 16
# 25 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
# 26 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunAway1
# 27 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
# 28 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 29 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
# 30 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunInCircles
# 31 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 32 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_WalkInPlaceFasterRight
# 33 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 34 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
# 35 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchFaceZigzagoon
# 36 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 37 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchUseOneQuick, MSGBOX_DEFAULT
# 38 "data/maps/Route101/scripts.pory"
	closemessage
# 39 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 2
# 40 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_PreventExit::
# 45 "data/maps/Route101/scripts.pory"
	lockall
# 46 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 47 "data/maps/Route101/scripts.pory"
	closemessage
# 49 "data/maps/Route101/scripts.pory"
	switch VAR_0x8008
# 50 "data/maps/Route101/scripts.pory"
	case 0, Route101_EventScript_PreventExit_3
# 51 "data/maps/Route101/scripts.pory"
	case 1, Route101_EventScript_PreventExit_4
# 52 "data/maps/Route101/scripts.pory"
	case 2, Route101_EventScript_PreventExit_5
Route101_EventScript_PreventExit_1:
# 54 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 55 "data/maps/Route101/scripts.pory"
	releaseall
	return

Route101_EventScript_PreventExit_3:
# 50 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
	goto Route101_EventScript_PreventExit_1

Route101_EventScript_PreventExit_4:
# 51 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
	goto Route101_EventScript_PreventExit_1

Route101_EventScript_PreventExit_5:
# 52 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
	goto Route101_EventScript_PreventExit_1


# 59 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitSouth:
# 60 "data/maps/Route101/scripts.pory"
	walk_up
# 61 "data/maps/Route101/scripts.pory"
	step_end

# 64 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitWest:
# 65 "data/maps/Route101/scripts.pory"
	walk_right
# 66 "data/maps/Route101/scripts.pory"
	step_end

# 69 "data/maps/Route101/scripts.pory"
Route101_Movement_PreventExitNorth:
# 70 "data/maps/Route101/scripts.pory"
	walk_down
# 71 "data/maps/Route101/scripts.pory"
	step_end

Route101_EventScript_Youngster::
# 75 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	return


Route101_EventScript_Boy::
# 80 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	return


Route101_EventScript_RouteSign::
# 85 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	return


Route101_EventScript_BirchsBag::
# 90 "data/maps/Route101/scripts.pory"
	lock
# 91 "data/maps/Route101/scripts.pory"
	faceplayer
# 92 "data/maps/Route101/scripts.pory"
	goto_if_set FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG, Route101_EventScript_BirchsBag_2
Route101_EventScript_BirchsBag_1:
# 95 "data/maps/Route101/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 96 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_SelectStarter
# 97 "data/maps/Route101/scripts.pory"
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
# 98 "data/maps/Route101/scripts.pory"
	releaseall
	return

Route101_EventScript_BirchsBag_2:
# 93 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_BirchsBag_Empty
	goto Route101_EventScript_BirchsBag_1


Route101_EventScript_BirchsBag_Empty::
# 103 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchsBagEmpty, MSGBOX_SIGN
# 104 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_SelectStarter::
# 109 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ChooseTreecko, MSGBOX_YESNO
# 110 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route101_EventScript_SelectStarter_2
Route101_EventScript_SelectStarter_1:
# 113 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ChooseTorchic, MSGBOX_YESNO
# 114 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route101_EventScript_SelectStarter_5
Route101_EventScript_SelectStarter_4:
# 117 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_ChooseMudkip, MSGBOX_YESNO
# 118 "data/maps/Route101/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Route101_EventScript_SelectStarter_8
Route101_EventScript_SelectStarter_7:
# 121 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_SelectStarter
	return

Route101_EventScript_SelectStarter_2:
# 111 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveTreecko
	goto Route101_EventScript_SelectStarter_1

Route101_EventScript_SelectStarter_5:
# 115 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveTorchic
	goto Route101_EventScript_SelectStarter_4

Route101_EventScript_SelectStarter_8:
# 119 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveMudkip
	goto Route101_EventScript_SelectStarter_7


Route101_EventScript_GiveTreecko::
# 125 "data/maps/Route101/scripts.pory"
	givemon SPECIES_TREECKO, 5
# 126 "data/maps/Route101/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 127 "data/maps/Route101/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 128 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 129 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 130 "data/maps/Route101/scripts.pory"
	waitmessage
# 131 "data/maps/Route101/scripts.pory"
	waitfanfare
# 132 "data/maps/Route101/scripts.pory"
	closemessage
	return


Route101_EventScript_GiveTorchic::
# 137 "data/maps/Route101/scripts.pory"
	givemon SPECIES_TORCHIC, 5
# 138 "data/maps/Route101/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 139 "data/maps/Route101/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 140 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 141 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 142 "data/maps/Route101/scripts.pory"
	waitmessage
# 143 "data/maps/Route101/scripts.pory"
	waitfanfare
# 144 "data/maps/Route101/scripts.pory"
	closemessage
	return


Route101_EventScript_GiveMudkip::
# 149 "data/maps/Route101/scripts.pory"
	givemon SPECIES_MUDKIP, 5
# 150 "data/maps/Route101/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 151 "data/maps/Route101/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 152 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 153 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 154 "data/maps/Route101/scripts.pory"
	waitmessage
# 155 "data/maps/Route101/scripts.pory"
	waitfanfare
# 156 "data/maps/Route101/scripts.pory"
	closemessage
	return


Route101_EventScript_ZoroarkTrigger::
# 161 "data/maps/Route101/scripts.pory"
	lockall
# 162 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchStarterHint, MSGBOX_DEFAULT
# 163 "data/maps/Route101/scripts.pory"
	closemessage
# 164 "data/maps/Route101/scripts.pory"
	waitse
# 165 "data/maps/Route101/scripts.pory"
	playmoncry SPECIES_ZOROARK_HISUI, CRY_MODE_ENCOUNTER
# 166 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8004, 1
# 167 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8005, 1
# 168 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8006, 4
# 169 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8007, 2
# 170 "data/maps/Route101/scripts.pory"
	special ShakeCamera
# 171 "data/maps/Route101/scripts.pory"
	waitstate
# 172 "data/maps/Route101/scripts.pory"
	waitmoncry
# 173 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_UnwinnableEncounter
# 174 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_UnwinnableEncounter::
# 179 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 180 "data/maps/Route101/scripts.pory"
	delay 20
# 181 "data/maps/Route101/scripts.pory"
	playse SE_MUGSHOT
# 182 "data/maps/Route101/scripts.pory"
	delay 30
# 183 "data/maps/Route101/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 184 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8004, 1
# 185 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8005, 1
# 186 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8006, 5
# 187 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8007, 3
# 188 "data/maps/Route101/scripts.pory"
	special ShakeCamera
# 189 "data/maps/Route101/scripts.pory"
	waitstate
# 190 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_PlayerOverwhelmed, MSGBOX_DEFAULT
# 191 "data/maps/Route101/scripts.pory"
	closemessage
# 192 "data/maps/Route101/scripts.pory"
	fadescreen FADE_TO_BLACK
# 193 "data/maps/Route101/scripts.pory"
	delay 16
# 194 "data/maps/Route101/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 195 "data/maps/Route101/scripts.pory"
	delay 16
# 196 "data/maps/Route101/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 197 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8004, 1
# 198 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8005, 1
# 199 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8006, 3
# 200 "data/maps/Route101/scripts.pory"
	setvar VAR_0x8007, 2
# 201 "data/maps/Route101/scripts.pory"
	special ShakeCamera
# 202 "data/maps/Route101/scripts.pory"
	waitstate
# 203 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_VoiceNotYet, MSGBOX_DEFAULT
# 204 "data/maps/Route101/scripts.pory"
	closemessage
# 205 "data/maps/Route101/scripts.pory"
	removeobject LOCALID_ROUTE101_ZIGZAGOON
# 206 "data/maps/Route101/scripts.pory"
	delay 20
# 207 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
# 208 "data/maps/Route101/scripts.pory"
	closemessage
# 209 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_PlayerVoiceProtecting, MSGBOX_DEFAULT
# 210 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_PlayerUneasyFeeling, MSGBOX_DEFAULT
# 211 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchWhatWasThat, MSGBOX_DEFAULT
# 212 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchNoMatterToLab, MSGBOX_DEFAULT
# 213 "data/maps/Route101/scripts.pory"
	call Route101_EventScript_BirchGivesRemainingStarters
# 214 "data/maps/Route101/scripts.pory"
	setvar VAR_ROUTE101_STATE, 3
# 215 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_BirchGivesRemainingStarters::
# 220 "data/maps/Route101/scripts.pory"
	lock
# 221 "data/maps/Route101/scripts.pory"
	faceplayer
# 222 "data/maps/Route101/scripts.pory"
	bufferleadmonspeciesname STR_VAR_1
# 223 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchChoseMon, MSGBOX_DEFAULT
# 224 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchNotEnough, MSGBOX_DEFAULT
# 225 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_BirchTakeRemaining, MSGBOX_DEFAULT
# 226 "data/maps/Route101/scripts.pory"
	switch VAR_STARTER_MON
# 227 "data/maps/Route101/scripts.pory"
	case 0, Route101_EventScript_BirchGivesRemainingStarters_3
# 228 "data/maps/Route101/scripts.pory"
	case 1, Route101_EventScript_BirchGivesRemainingStarters_4
# 229 "data/maps/Route101/scripts.pory"
	case 2, Route101_EventScript_BirchGivesRemainingStarters_5
Route101_EventScript_BirchGivesRemainingStarters_1:
# 231 "data/maps/Route101/scripts.pory"
	release
	return

Route101_EventScript_BirchGivesRemainingStarters_3:
# 227 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveTorchicAndMudkip
	goto Route101_EventScript_BirchGivesRemainingStarters_1

Route101_EventScript_BirchGivesRemainingStarters_4:
# 228 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveTreeckoAndMudkip
	goto Route101_EventScript_BirchGivesRemainingStarters_1

Route101_EventScript_BirchGivesRemainingStarters_5:
# 229 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveTreeckoAndTorchic
	goto Route101_EventScript_BirchGivesRemainingStarters_1


Route101_EventScript_GiveTorchicAndMudkip::
# 236 "data/maps/Route101/scripts.pory"
	givemon SPECIES_TORCHIC, 5
# 237 "data/maps/Route101/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
# 238 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 239 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 240 "data/maps/Route101/scripts.pory"
	waitmessage
# 241 "data/maps/Route101/scripts.pory"
	waitfanfare
# 242 "data/maps/Route101/scripts.pory"
	givemon SPECIES_MUDKIP, 5
# 243 "data/maps/Route101/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
# 244 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 245 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 246 "data/maps/Route101/scripts.pory"
	waitmessage
# 247 "data/maps/Route101/scripts.pory"
	waitfanfare
# 248 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveRemainingStarters_End
	return


Route101_EventScript_GiveTreeckoAndMudkip::
# 252 "data/maps/Route101/scripts.pory"
	givemon SPECIES_TREECKO, 5
# 253 "data/maps/Route101/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
# 254 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 255 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 256 "data/maps/Route101/scripts.pory"
	waitmessage
# 257 "data/maps/Route101/scripts.pory"
	waitfanfare
# 258 "data/maps/Route101/scripts.pory"
	givemon SPECIES_MUDKIP, 5
# 259 "data/maps/Route101/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
# 260 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 261 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 262 "data/maps/Route101/scripts.pory"
	waitmessage
# 263 "data/maps/Route101/scripts.pory"
	waitfanfare
# 264 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveRemainingStarters_End
	return


Route101_EventScript_GiveTreeckoAndTorchic::
# 268 "data/maps/Route101/scripts.pory"
	givemon SPECIES_TREECKO, 5
# 269 "data/maps/Route101/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
# 270 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 271 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 272 "data/maps/Route101/scripts.pory"
	waitmessage
# 273 "data/maps/Route101/scripts.pory"
	waitfanfare
# 274 "data/maps/Route101/scripts.pory"
	givemon SPECIES_TORCHIC, 5
# 275 "data/maps/Route101/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
# 276 "data/maps/Route101/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 277 "data/maps/Route101/scripts.pory"
	message Route101_Text_PlayerReceivedStarter
# 278 "data/maps/Route101/scripts.pory"
	waitmessage
# 279 "data/maps/Route101/scripts.pory"
	waitfanfare
# 280 "data/maps/Route101/scripts.pory"
	goto Route101_EventScript_GiveRemainingStarters_End
	return


Route101_EventScript_GiveRemainingStarters_End::
# 284 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_PlayerAllThreeInner, MSGBOX_DEFAULT
# 285 "data/maps/Route101/scripts.pory"
	release
	return


# 289 "data/maps/Route101/scripts.pory"
Route101_Movement_EnterScene:
# 290 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 291 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 292 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 293 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 294 "data/maps/Route101/scripts.pory"
	walk_in_place_faster_left
# 295 "data/maps/Route101/scripts.pory"
	step_end

# 298 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChaseInCircles:
# 299 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 299 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 299 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 300 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 300 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 300 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 301 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 301 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 301 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 302 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 302 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 302 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 303 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 303 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 303 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 304 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 304 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 304 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 305 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 305 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 305 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 306 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 306 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 306 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 307 "data/maps/Route101/scripts.pory"
	step_end

# 310 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonChase1:
# 311 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 311 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 311 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 311 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 312 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 312 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 312 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 313 "data/maps/Route101/scripts.pory"
	step_end

# 316 "data/maps/Route101/scripts.pory"
Route101_Movement_ZigzagoonFaceBirch:
# 317 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 317 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 317 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 317 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_left
# 318 "data/maps/Route101/scripts.pory"
	step_end

# 321 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunInCircles:
# 322 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 322 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 322 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 323 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 323 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 323 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 324 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 324 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 324 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 325 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 325 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 325 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 326 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 326 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 326 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 327 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 327 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 327 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 328 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 328 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 328 "data/maps/Route101/scripts.pory"
	walk_fast_down
# 329 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 329 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 329 "data/maps/Route101/scripts.pory"
	walk_fast_left
# 330 "data/maps/Route101/scripts.pory"
	step_end

# 333 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchRunAway1:
# 334 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 334 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 334 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 334 "data/maps/Route101/scripts.pory"
	walk_fast_right
# 335 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 335 "data/maps/Route101/scripts.pory"
	walk_fast_up
# 336 "data/maps/Route101/scripts.pory"
	step_end

# 339 "data/maps/Route101/scripts.pory"
Route101_Movement_BirchFaceZigzagoon:
# 340 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 340 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 340 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 340 "data/maps/Route101/scripts.pory"
	walk_in_place_fast_right
# 341 "data/maps/Route101/scripts.pory"
	step_end

Route101_EventScript_PreventExitSouth::
# 458 "data/maps/Route101/scripts.pory"
	lockall
# 459 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 460 "data/maps/Route101/scripts.pory"
	closemessage
# 461 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
# 462 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 463 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_PreventExitWest::
# 468 "data/maps/Route101/scripts.pory"
	lockall
# 469 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 470 "data/maps/Route101/scripts.pory"
	closemessage
# 471 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
# 472 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 473 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_EventScript_PreventExitNorth::
# 478 "data/maps/Route101/scripts.pory"
	lockall
# 479 "data/maps/Route101/scripts.pory"
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
# 480 "data/maps/Route101/scripts.pory"
	closemessage
# 481 "data/maps/Route101/scripts.pory"
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
# 482 "data/maps/Route101/scripts.pory"
	waitmovement 0
# 483 "data/maps/Route101/scripts.pory"
	releaseall
	return


Route101_Text_HelpMe::
# 344 "data/maps/Route101/scripts.pory"
	.string "BIRCH: H-Help! Somebody- please!\n$"

Route101_Text_BirchUseOneQuick::
# 348 "data/maps/Route101/scripts.pory"
	.string "BIRCH: YOU!! Quick- there's no time!\n"
	.string "Use one of my POKéMON!\n$"

Route101_Text_DontLeaveMe::
# 353 "data/maps/Route101/scripts.pory"
	.string "BIRCH: Don't leave me here!\n$"

Route101_Text_TakeTiredPokemonToPokeCenter::
# 357 "data/maps/Route101/scripts.pory"
	.string "If POKéMON get tired, take them to a\n"
	.string "POKéMON CENTER. There's one in OLDALE\n"
	.string "TOWN right close by. They'll heal your\n"
	.string "POKéMON for free.\n$"

Route101_Text_WildPokemonInTallGrass::
# 364 "data/maps/Route101/scripts.pory"
	.string "Wild POKéMON will jump out at you in tall\n"
	.string "grass. If you want to catch POKéMON, you\n"
	.string "have to go into the tall grass and search.\n"
	.string "Be careful, though. Wild POKéMON can be\n"
	.string "strong.\n$"

Route101_Text_RouteSign::
# 372 "data/maps/Route101/scripts.pory"
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN\n$"

Route101_Text_BirchsBagEmpty::
# 377 "data/maps/Route101/scripts.pory"
	.string "The bag is empty.\n$"

Route101_Text_ChooseTreecko::
# 381 "data/maps/Route101/scripts.pory"
	.string "Do you want TREECKO, the Grass Pokémon?\n$"

Route101_Text_ChooseTorchic::
# 385 "data/maps/Route101/scripts.pory"
	.string "Do you want TORCHIC, the Fire Pokémon?\n$"

Route101_Text_ChooseMudkip::
# 389 "data/maps/Route101/scripts.pory"
	.string "Do you want MUDKIP, the Water Pokémon?\n$"

Route101_Text_PlayerReceivedStarter::
# 393 "data/maps/Route101/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!\n$"

Route101_Text_BirchStarterHint::
# 397 "data/maps/Route101/scripts.pory"
	.string "BIRCH: Quick- use one of those POKéMON!\n$"

Route101_Text_PlayerOverwhelmed::
# 401 "data/maps/Route101/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: This power… I can't stop it…!\n"
	.string "{COLOR DARK_GRAY}$"

Route101_Text_VoiceNotYet::
# 406 "data/maps/Route101/scripts.pory"
	.string "{COLOR LIGHT_RED}??? : …Not yet. Your path is not ready.\n"
	.string "{COLOR DARK_GRAY}$"

Route101_Text_YouSavedMe::
# 411 "data/maps/Route101/scripts.pory"
	.string "BIRCH: You saved me! Thank you!\n$"

Route101_Text_PlayerVoiceProtecting::
# 415 "data/maps/Route101/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: That voice… it was protecting me?\n"
	.string "{COLOR DARK_GRAY}$"

Route101_Text_PlayerUneasyFeeling::
# 420 "data/maps/Route101/scripts.pory"
	.string "{COLOR GREEN}{PLAYER}: Is this uneasy feeling I've had…\n"
	.string "or something else entirely?\n"
	.string "{COLOR DARK_GRAY}$"

Route101_Text_BirchWhatWasThat::
# 426 "data/maps/Route101/scripts.pory"
	.string "BIRCH: What was that just now? That Pokémon-\n"
	.string "I've never seen anything like it in HOENN.\n"
	.string "BIRCH: And that voice… Who was it speaking to?\n"
	.string "Who… are You, {PLAYER}?\n$"

Route101_Text_BirchNoMatterToLab::
# 433 "data/maps/Route101/scripts.pory"
	.string "BIRCH: No matter. Quick- let's get to my lab\n"
	.string "before anything else happens!\n$"

Route101_Text_BirchChoseMon::
# 438 "data/maps/Route101/scripts.pory"
	.string "BIRCH: So you chose {STR_VAR_1}!\n$"

Route101_Text_BirchNotEnough::
# 442 "data/maps/Route101/scripts.pory"
	.string "BIRCH: That's not enough! The wild POKéMON-\n"
	.string "they're too strong!\n$"

Route101_Text_BirchTakeRemaining::
# 447 "data/maps/Route101/scripts.pory"
	.string "BIRCH: Take the remaining two!\n$"

Route101_Text_PlayerAllThreeInner::
# 451 "data/maps/Route101/scripts.pory"
	.string "BIRCH: Now you have all three!\n"
	.string "Be careful out there!\n$"
