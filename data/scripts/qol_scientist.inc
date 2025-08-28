EventScript_QoLScientist::
    lock
    faceplayer
    callnative Script_QoL_Msg_Hello
    msgbox gStringVar4 MSG_NORMAL

.MainLoop:
    multichoice 0, 0, MULTI_QOL_MAIN, 0
    switch VAR_RESULT
        case 0, .DoNature
        case 1, .DoEVs
        case 2, .DoIVs
        case 3, .DoBall
        case 4, .DoHidden
        case 5, .End
    goto .MainLoop

.DoNature:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon           @ sets VAR_RESULT
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .MainLoop
    msgbox gText_QoLChooseNature MSG_NORMAL
    multichoice 0, 0, MULTI_QOL_NATURES, 0
    setvar VAR_0x8000, VAR_RESULT   @ 0..24
    callnative Script_QoL_SetNature
    call .ResultMsg
    goto .MainLoop

.DoEVs:
    multichoice 0, 0, MULTI_QOL_EVS, 0
    switch VAR_RESULT
        case 0, .EV_Preset
        case 1, .EV_Quick
        case 2, .EV_Full
        case 3, .EV_Clear
        case 4, .MainLoop

.EV_Preset:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .DoEVs
    callnative Script_QoL_EVs_PresetByNature
    call .ResultMsg
    goto .DoEVs

.EV_Quick:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .DoEVs
    msgbox gText_QoLPickStat1 MSG_NORMAL
    multichoice 0, 0, MULTI_QOL_STATS, 0
    compare VAR_RESULT, 6
    goto_if_eq .DoEVs
    setvar VAR_0x8000, VAR_RESULT      @ 0..5
    msgbox gText_QoLPickStat2 MSG_NORMAL
    multichoice 0, 0, MULTI_QOL_STATS, 0
    compare VAR_RESULT, 6
    goto_if_eq .DoEVs
    setvar VAR_0x8001, VAR_RESULT      @ 0..5
    callnative Script_QoL_EVs_QuickCustom
    call .ResultMsg
    goto .DoEVs

.EV_Full:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .DoEVs

    setvar VAR_0x8000, 0
    setvar VAR_0x8001, 252

    setvar VAR_0x8002, 0
    callnative Script_QoL_PromptNumber
    copyvar VAR_0x8000, VAR_RESULT    @ HP

    setvar VAR_0x8002, 0
    callnative Script_QoL_PromptNumber
    copyvar VAR_0x8001, VAR_RESULT    @ ATK

    setvar VAR_0x8002, 0
    callnative Script_QoL_PromptNumber
    copyvar VAR_0x8002, VAR_RESULT    @ DEF

    setvar VAR_0x8002, 0
    callnative Script_QoL_PromptNumber
    copyvar VAR_0x8003, VAR_RESULT    @ SPE

    setvar VAR_0x8002, 0
    callnative Script_QoL_PromptNumber
    copyvar VAR_0x8004, VAR_RESULT    @ SPA

    setvar VAR_0x8002, 0
    callnative Script_QoL_PromptNumber
    copyvar VAR_0x8005, VAR_RESULT    @ SPD

    callnative Script_QoL_EVs_CustomFull
    call .ResultMsg
    goto .DoEVs

.EV_Clear:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .DoEVs
    callnative Script_QoL_EVs_Clear
    call .ResultMsg
    goto .DoEVs

.DoIVs:
    multichoice 0, 0, MULTI_QOL_IVS, 0
    switch VAR_RESULT
        case 0, .IV_31
        case 1, .IV_TR
        case 2, .IV_SetStat
        case 3, .MainLoop

.IV_31:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .DoIVs
    callnative Script_QoL_IVs_Perfect31
    call .ResultMsg
    goto .DoIVs

.IV_TR:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .DoIVs
    callnative Script_QoL_IVs_TrickRoom
    call .ResultMsg
    goto .DoIVs

.IV_SetStat:
    msgbox gText_QoLPickAStat MSG_NORMAL
    multichoice 0, 0, MULTI_QOL_STATS, 0
    compare VAR_RESULT, 6
    goto_if_eq .DoIVs
    setvar VAR_0x8000, VAR_RESULT            @ stat 0..5
    setvar VAR_0x8000, 0
    setvar VAR_0x8001, 31
    setvar VAR_0x8002, 31
    callnative Script_QoL_PromptNumber
    copyvar VAR_0x8001, VAR_RESULT           @ iv
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .DoIVs
    callnative Script_QoL_IVs_SetStat
    call .ResultMsg
    goto .DoIVs

.DoBall:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .MainLoop
    msgbox gText_QoLPickBall MSG_NORMAL
    multichoice 0, 0, MULTI_QOL_BALLS, 0
    compare VAR_RESULT, 10
    goto_if_eq .MainLoop
    switch VAR_RESULT
        case 0, .B0
        case 1, .B1
        case 2, .B2
        case 3, .B3
        case 4, .B4
        case 5, .B5
        case 6, .B6
        case 7, .B7
        case 8, .B8
        case 9, .B9
.B0: setvar VAR_0x8000, ITEM_POKE_BALL;   goto .BApply
.B1: setvar VAR_0x8000, ITEM_GREAT_BALL;  goto .BApply
.B2: setvar VAR_0x8000, ITEM_ULTRA_BALL;  goto .BApply
.B3: setvar VAR_0x8000, ITEM_PREMIER_BALL;goto .BApply
.B4: setvar VAR_0x8000, ITEM_DIVE_BALL;   goto .BApply
.B5: setvar VAR_0x8000, ITEM_DUSK_BALL;   goto .BApply
.B6: setvar VAR_0x8000, ITEM_TIMER_BALL;  goto .BApply
.B7: setvar VAR_0x8000, ITEM_QUICK_BALL;  goto .BApply
.B8: setvar VAR_0x8000, ITEM_CHERISH_BALL;goto .BApply
.B9: setvar VAR_0x8000, ITEM_BEAST_BALL;  goto .BApply
.BApply:
    callnative Script_QoL_SetBall
    call .ResultMsg
    goto .MainLoop

.DoHidden:
    msgbox gText_QoLChooseMon MSG_NORMAL
    special ChoosePartyMon
    compare VAR_RESULT, PARTY_SIZE
    goto_if_ge .MainLoop
    msgbox gText_QoLPickHPType MSG_NORMAL
    multichoice 0, 0, MULTI_QOL_HP_TYPES, 0
    compare VAR_RESULT, 16
    goto_if_eq .MainLoop
    setvar VAR_0x8000, TYPE_FIGHTING
    addvar VAR_0x8000, VAR_RESULT
    callnative Script_QoL_SetHiddenPowerType
    call .ResultMsg
    goto .MainLoop

.ResultMsg:
    compare VAR_RESULT, 1
    goto_if_eq .MsgCharged
    compare VAR_RESULT, 2
    goto_if_eq .MsgNoMoney
    compare VAR_RESULT, 3
    goto_if_eq .MsgIllegal
    goto .MsgCanceled

.MsgCharged:
    callnative Script_QoL_Msg_Charged
    msgbox gStringVar4 MSG_NORMAL
    return
.MsgNoMoney:
    callnative Script_QoL_Msg_NotEnoughMoney
    msgbox gStringVar4 MSG_NORMAL
    return
.MsgIllegal:
    callnative Script_QoL_Msg_IllegalBall
    msgbox gStringVar4 MSG_NORMAL
    return
.MsgCanceled:
    callnative Script_QoL_Msg_Canceled
    msgbox gStringVar4 MSG_NORMAL
    return

.End:
    release
    end
