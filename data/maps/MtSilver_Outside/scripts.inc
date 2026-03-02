@ === MtSilver_Outside scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ MtSilver_Outside_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_Outside_OnTransition
@ 	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
@ 	.byte 0
@
@ MtSilver_Outside_OnTransition: 
@ 	callnative SetTimeBasedEncounters
@ 	setflag FLAG_VISITED_MT_SILVER
@ 	end
@
@ MtSilver_Outside_EventScript_Sign::
@ 	msgbox MtSilver_Outside_Text_Sign, MSGBOX_SIGN
@ 	end
@
@ MtSilver_Outside_Text_Sign:
@ 	.string "MT. SILVER$"
@ --- End original content ---

MtSilver_Outside_MapScripts::
	.byte 0

MtSilver_Outside_EventScript_Sign::
	end
