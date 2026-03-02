@ === Gate_EcruteakCity_Route42 scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ Gate_EcruteakCity_Route42_MapScripts::
@ 	.byte 0
@
@ Gate_EcruteakCity_Route42_EventScript_Policeman::
@ 	lock
@ 	faceplayer
@ 	msgbox Route42_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
@ 	closemessage
@ 	release
@ 	end
@
@ Route42_Text_EcruteakGateOfficer:
@ 	.string "MT.MORTAR is like a maze\n"
@ 	.string "inside.\p"
@ 	.string "Be careful. Don't get lost\n"
@ 	.string "in there.$"
@ --- End original content ---

Gate_EcruteakCity_Route42_MapScripts::
	.byte 0

Gate_EcruteakCity_Route42_EventScript_Policeman::
	end
