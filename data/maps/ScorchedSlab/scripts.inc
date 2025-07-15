ScorchedSlab_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
        map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_OnResume
        .byte 0

ScorchedSlab_OnTransition:
        setflag FLAG_LANDMARK_SCORCHED_SLAB
        call_if_set FLAG_CAUGHT_AZELF, ScorchedSlab_HideAzelf
        call_if_unset FLAG_CAUGHT_AZELF, ScorchedSlab_TryShowAzelf
        end

ScorchedSlab_OnResume:
        call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_TryRemoveAzelf
        end

ScorchedSlab_HideAzelf::
        setflag FLAG_HIDE_AZELF
        return

ScorchedSlab_TryShowAzelf::
        goto_if_set FLAG_DEFEATED_AZELF, Common_EventScript_NopReturn
        clearflag FLAG_HIDE_AZELF
        return

ScorchedSlab_TryRemoveAzelf::
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
        removeobject LOCALID_SCORCHED_SLAB_AZELF
        return

ScorchedSlab_Azelf::
        lock
        faceplayer
        waitse
        playmoncry SPECIES_AZELF, CRY_MODE_ENCOUNTER
        waitmoncry
        seteventmon SPECIES_AZELF, 50
        setflag FLAG_SYS_CTRL_OBJ_DELETE
        special BattleSetup_StartLegendaryBattle
        waitstate
        clearflag FLAG_SYS_CTRL_OBJ_DELETE
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlab_DefeatedAzelf
        goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ScorchedSlab_RanFromAzelf
        goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ScorchedSlab_RanFromAzelf
        setflag FLAG_CAUGHT_AZELF
        release
        end

ScorchedSlab_DefeatedAzelf::
        setflag FLAG_DEFEATED_AZELF
        setvar VAR_0x8004, SPECIES_AZELF
        goto Common_EventScript_LegendaryFlewAway
        end

ScorchedSlab_RanFromAzelf::
        setvar VAR_0x8004, SPECIES_AZELF
        goto Common_EventScript_LegendaryFlewAway
        end

