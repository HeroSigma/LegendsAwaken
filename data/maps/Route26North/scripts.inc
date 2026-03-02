@ === Route26North scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ Route26North_MapScripts::
@ 	.byte 0
@
@ Route26North_Trigger::
@ 	setflag FLAG_VISITED_RECEPTION_GATE
@ 	setvar VAR_TEMP_0, 1
@ 	end
@ --- End original content ---

Route26North_MapScripts::
	.byte 0

Route26North_Trigger::
	end
