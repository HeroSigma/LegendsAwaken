AlteringCave_MapScripts::
        map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
        map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnResume
        .byte 0

AlteringCave_OnTransition:
        setflag FLAG_LANDMARK_ALTERING_CAVE
        call_if_set FLAG_CAUGHT_MEWTWO, AlteringCave_HideMewtwo
        call_if_unset FLAG_CAUGHT_MEWTWO, AlteringCave_TryShowMewtwo
        end

AlteringCave_OnResume:
        call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_TryRemoveMewtwo
        end

AlteringCave_HideMewtwo::
        setflag FLAG_HIDE_MEWTWO
        return

AlteringCave_TryShowMewtwo::
        checkspecies SPECIES_MEW
        goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
        goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
        clearflag FLAG_HIDE_MEWTWO
        return

AlteringCave_TryRemoveMewtwo::
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
        removeobject LOCALID_ALTERING_CAVE_MEWTWO
        return

AlteringCave_Mewtwo::
        lock
        faceplayer
        waitse
        playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
        waitmoncry
        seteventmon SPECIES_MEWTWO, 70
        setflag FLAG_SYS_CTRL_OBJ_DELETE
        special BattleSetup_StartLegendaryBattle
        waitstate
        clearflag FLAG_SYS_CTRL_OBJ_DELETE
        specialvar VAR_RESULT, GetBattleOutcome
        goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_DefeatedMewtwo
        goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_RanFromMewtwo
        goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_RanFromMewtwo
        setflag FLAG_CAUGHT_MEWTWO
        release
        end

AlteringCave_DefeatedMewtwo::
        setflag FLAG_DEFEATED_MEWTWO
        setvar VAR_0x8004, SPECIES_MEWTWO
        goto Common_EventScript_LegendaryFlewAway
        end

AlteringCave_RanFromMewtwo::
        setvar VAR_0x8004, SPECIES_MEWTWO
        goto Common_EventScript_LegendaryFlewAway
        end

