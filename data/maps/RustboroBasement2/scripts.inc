RustboroBasement2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroBasement2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, RustboroBasement2_OnResume
	.byte 0

RustboroBasement2_OnTransition:
	call_if_set FLAG_CAUGHT_TYPE_NULL, RustboroBasement2_HideTypeNull
	call_if_unset FLAG_CAUGHT_TYPE_NULL, RustboroBasement2_TryShowTypeNull
	end

RustboroBasement2_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, RustboroBasement2_TryRemoveTypeNull
	end

RustboroBasement2_HideTypeNull::
	setflag FLAG_HIDE_TYPE_NULL
	return

RustboroBasement2_TryShowTypeNull::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_CAUGHT_HOOPA, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_TYPE_NULL
	return

RustboroBasement2_TryRemoveTypeNull::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_TYPE_NULL
	return

RustboroBasement2_TypeNull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TYPE_NULL, CRY_MODE_ENCOUNTER
	waitmoncry
	seteventmon SPECIES_TYPE_NULL, 20
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RustboroBasement2_DefeatedTypeNull
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RustboroBasement2_RanFromTypeNull
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RustboroBasement2_RanFromTypeNull
	setflag FLAG_CAUGHT_TYPE_NULL
	release
	end

RustboroBasement2_DefeatedTypeNull::
	setvar VAR_0x8004, SPECIES_TYPE_NULL
	goto Common_EventScript_LegendaryFlewAway
	end

RustboroBasement2_RanFromTypeNull::
	setvar VAR_0x8004, SPECIES_TYPE_NULL
	goto Common_EventScript_LegendaryFlewAway
	end
