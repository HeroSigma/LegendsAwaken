GraniteCave_StevensRoom_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_StevensRoom_OnTransition
        map_script MAP_SCRIPT_ON_RESUME, GraniteCave_StevensRoom_OnResume
        .byte 0

GraniteCave_StevensRoom_OnTransition:
        call_if_set FLAG_CAUGHT_YVELTAL, GraniteCave_StevensRoom_HideYveltal
        call_if_unset FLAG_CAUGHT_YVELTAL, GraniteCave_StevensRoom_TryShowYveltal
        return

GraniteCave_StevensRoom_OnResume:
        call_if_set FLAG_SYS_CTRL_OBJ_DELETE, GraniteCave_StevensRoom_TryRemoveYveltal
        end

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_StevenCarvingsGreeting, MSGBOX_DEFAULT
	msgbox GraniteCave_StevensRoom_Text_PlayerDeliverLine, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_StevenDevonSilphRifts, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_SteelWingGift, MSGBOX_DEFAULT
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_StevenJourneyForeshadow, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	msgbox GraniteCave_StevensRoom_Text_PlayerThoughtFather, MSGBOX_DEFAULT
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
        applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
        applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
        waitmovement 0
        return

GraniteCave_StevensRoom_EventScript_BagFull::
        msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
        return

GraniteCave_StevensRoom_HideYveltal::
        setflag FLAG_HIDE_YVELTAL
        return

GraniteCave_StevensRoom_TryShowYveltal::
        goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
        goto_if_unset FLAG_CAUGHT_HOOPA, Common_EventScript_NopReturn
        clearflag FLAG_HIDE_YVELTAL
        return

GraniteCave_StevensRoom_TryRemoveYveltal::
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
        removeobject LOCALID_GRANITE_CAVE_YVELTAL
        return

GraniteCave_StevensRoom_Yveltal::
        lock
        faceplayer
        waitse
        playmoncry SPECIES_YVELTAL, CRY_MODE_ENCOUNTER
        waitmoncry
        seteventmon SPECIES_YVELTAL, 70
        setflag FLAG_SYS_CTRL_OBJ_DELETE
        special BattleSetup_StartLegendaryBattle
        waitstate
        clearflag FLAG_SYS_CTRL_OBJ_DELETE
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCave_StevensRoom_DefeatedYveltal
        goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCave_StevensRoom_RanFromYveltal
        goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCave_StevensRoom_RanFromYveltal
        setflag FLAG_CAUGHT_YVELTAL
        release
        end

GraniteCave_StevensRoom_DefeatedYveltal::
        setvar VAR_0x8004, SPECIES_YVELTAL
        goto Common_EventScript_LegendaryFlewAway
        end

GraniteCave_StevensRoom_RanFromYveltal::
        setvar VAR_0x8004, SPECIES_YVELTAL
        goto Common_EventScript_LegendaryFlewAway
        end

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_StevenCarvingsGreeting:
	.string "{COLOR BLUE}STEVEN:\n"
	.string "Remarkable... These carvings predate\n"
	.string "even Hoenn's first records.\p"
	.string "They speak of distortions--tears in\n"
	.string "the fabric of reality itself.\p"
	.string "Ah. You must be {PLAYER}.\p"
	.string "BIRCH mentioned you, but I didn't\n"
	.string "expect you so soon.$"

GraniteCave_StevensRoom_Text_PlayerDeliverLine:
	.string "{COLOR GREEN}{PLAYER}:\n"
	.string "Mr. STONE asked me to deliver this\n"
	.string "to you.$"

GraniteCave_StevensRoom_Text_StevenDevonSilphRifts:
	.string "{COLOR BLUE}STEVEN:\n"
	.string "So DEVON suspects as well...\n"
	.string "SILPH's research agrees.\p"
	.string "The balance of this region is\n"
	.string "shifting.\p"
	.string "Look closely--figures lost to rifts,\n"
	.string "POKEMON twisted into new forms.\p"
	.string "This is no myth. The ZOROARK you saw\n"
	.string "near LITTLEROOT was proof.$"

GraniteCave_StevensRoom_Text_SteelWingGift:
	.string "{COLOR BLUE}STEVEN:\n"
	.string "Take this. Steel endures.\p"
	.string "May it serve you when all else feels\n"
	.string "uncertain.\p"
	.string "{COLOR DARK_GRAY}You received TM47 (STEEL WING)!$"

GraniteCave_StevensRoom_Text_StevenJourneyForeshadow:
	.string "{COLOR BLUE}STEVEN:\n"
	.string "Your journey is crossing paths with\n"
	.string "powers greater than you know.\p"
	.string "Others are watching too... silent\n"
	.string "for now.\p"
	.string "When the time comes, we will meet\n"
	.string "again--and perhaps then, the truth\n"
	.string "will no longer hide itself.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "{COLOR DARK_GRAY}Oh, your BAG is full...\n"
	.string "That's too bad, then.$"

GraniteCave_StevensRoom_Text_PlayerThoughtFather:
	.string "{PLAYER}: (Vanished…? Could he be talking\n"
	.string "about Father?)$"
