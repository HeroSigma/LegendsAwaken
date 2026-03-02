@ === Gate_MahoganyTown_Route43 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ Gate_MahoganyTown_Route43_MapScripts::
@ 	.byte 0
@
@ Gate_MahoganyTown_Route43_EventScript_Cop::
@ 	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, Gate_MahoganyTown_Route43_EventScript_CopAfter
@ 	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_NPC
@ 	end
@
@ Gate_MahoganyTown_Route43_EventScript_CopAfter::
@ 	msgbox Route43MahoganyGate_Text_Officer_RocketsCleared, MSGBOX_NPC
@ 	end
@
@ Route43MahoganyGate_Text_Officer:
@     .string "Only people headed up to LAKE OF\n"
@     .string "RAGE have been through here lately.$"
@
@ Route43MahoganyGate_Text_Officer_RocketsCleared:
@     .string "Nobody goes up to LAKE OF RAGE\n"
@     .string "these days.$"
@ --- End original content ---

Gate_MahoganyTown_Route43_MapScripts::
	.byte 0

Gate_MahoganyTown_Route43_EventScript_Cop::
	end

Gate_MahoganyTown_Route43_EventScript_CopAfter::
	end
