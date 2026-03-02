@ === Route26_House1 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ Route26_House1_MapScripts::
@ 	.byte 0
@
@ Route26_House1_EventScript_HealWoman::
@ 	lock
@ 	faceplayer
@ 	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
@ 	closemessage
@ 	call Common_EventScript_OutOfCenterPartyHeal
@ 	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
@ 	release
@ 	end
@
@
@ Route26_Text_HealHouseRest:
@     .string "Your POKéMON look a little tired.\p"
@     .string "You should rest them a while.$"
@
@ Route26_Text_HealHouseKeepAtIt:
@     .string "There!\p"
@     .string "Your POKéMON are looking good!\p"
@     .string "Keep at it!$"
@ --- End original content ---

Route26_House1_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	end
