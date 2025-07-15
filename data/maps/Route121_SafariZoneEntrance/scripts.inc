Route121_SafariZoneEntrance_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, Route121_SafariZoneEntrance_OnTransition
        map_script MAP_SCRIPT_ON_RESUME, Route121_SafariZoneEntrance_OnResume
        map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_OnFrame
        .byte 0

Route121_SafariZoneEntrance_OnTransition:
        call_if_set FLAG_CAUGHT_TAPU_BULU, Route121_SafariZoneEntrance_HideTapuBulu
        call_if_unset FLAG_CAUGHT_TAPU_BULU, Route121_SafariZoneEntrance_TryShowTapuBulu
        end

Route121_SafariZoneEntrance_OnResume:
        call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route121_SafariZoneEntrance_TryRemoveTapuBulu
        return

Route121_SafariZoneEntrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, Route121_SafariZoneEntrance_EventScript_ExitSafariZone
	.2byte 0

Route121_SafariZoneEntrance_EventScript_ExitSafariZone::
	lockall
	applymovement LOCALID_PLAYER, Route121_SafariZoneEntrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
        releaseall
        end

Route121_SafariZoneEntrance_HideTapuBulu::
        setflag FLAG_HIDE_TAPU_BULU
        return

Route121_SafariZoneEntrance_TryShowTapuBulu::
        goto_if_set FLAG_DEFEATED_TAPU_BULU, Common_EventScript_NopReturn
        clearflag FLAG_HIDE_TAPU_BULU
        return

Route121_SafariZoneEntrance_TryRemoveTapuBulu::
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
        removeobject LOCALID_SAFARI_ZONE_ENTRANCE_TAPU_BULU
        return

Route121_SafariZoneEntrance_TapuBulu::
        lock
        faceplayer
        waitse
        playmoncry SPECIES_TAPU_BULU, CRY_MODE_ENCOUNTER
        waitmoncry
        seteventmon SPECIES_TAPU_BULU, 70
        setflag FLAG_SYS_CTRL_OBJ_DELETE
        special BattleSetup_StartLegendaryBattle
        waitstate
        clearflag FLAG_SYS_CTRL_OBJ_DELETE
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route121_SafariZoneEntrance_DefeatedTapuBulu
        goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route121_SafariZoneEntrance_RanFromTapuBulu
        goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route121_SafariZoneEntrance_RanFromTapuBulu
        setflag FLAG_CAUGHT_TAPU_BULU
        release
        end

Route121_SafariZoneEntrance_DefeatedTapuBulu::
        setflag FLAG_DEFEATED_TAPU_BULU
        setvar VAR_0x8004, SPECIES_TAPU_BULU
        goto Common_EventScript_LegendaryFlewAway
        end

Route121_SafariZoneEntrance_RanFromTapuBulu::
        setvar VAR_0x8004, SPECIES_TAPU_BULU
        goto Common_EventScript_LegendaryFlewAway
        end

Route121_SafariZoneEntrance_Movement_ExitSafariZone:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route121_SafariZoneEntrance_EventScript_WelcomeAttendant::
	msgbox Route121_SafariZoneEntrance_Text_WelcomeToSafariZone, MSGBOX_NPC
	end

Route121_SafariZoneEntrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox Route121_SafariZoneEntrance_Text_WelcomeFirstTime, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_FirstTimeInfo
	msgbox Route121_SafariZoneEntrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_FirstTimeInfo::
	msgbox Route121_SafariZoneEntrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
	release
	end

Route121_SafariZoneEntrance_EventScript_EntranceCounterTrigger::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showmoneybox 0, 0
	msgbox Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone
	msgbox Route121_SafariZoneEntrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_TryEnterSafariZone::
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NoPokeblockCase
	call Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, Route121_SafariZoneEntrance_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox Route121_SafariZoneEntrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message Route121_SafariZoneEntrance_Text_Received30SafariBalls
	waitfanfare
	msgbox Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, Route121_SafariZoneEntrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	clearflag FLAG_GOOD_LUCK_SAFARI_ZONE
	warp MAP_SAFARI_ZONE_SOUTH, 32, 33
	waitstate
	end

Route121_SafariZoneEntrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon
	msgbox Route121_SafariZoneEntrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_HasRoomForPokemon::
	return

Route121_SafariZoneEntrance_EventScript_NoPokeblockCase::
	msgbox Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_NotEnoughMoney::
	msgbox Route121_SafariZoneEntrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter
	end

Route121_SafariZoneEntrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, Route121_SafariZoneEntrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

Route121_SafariZoneEntrance_Movement_BackAwayFromCounter:
	walk_right
	step_end

Route121_SafariZoneEntrance_Movement_EnterSafariZone:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	delay_16
	step_end

Route121_SafariZoneEntrance_EventScript_TrainerTipSign::
	msgbox Route121_SafariZoneEntrance_Text_TrainerTip, MSGBOX_SIGN
	end

