@ === CinnabarIsland_Mart scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ CinnabarIsland_Mart_MapScripts::
@ 	.byte 0
@
@ CinnabarIsland_Mart_EventScript_Clerk::
@ 	lock
@ 	faceplayer
@ 	message gText_HowMayIServeYou
@ 	waitmessage
@ 	pokemart CinnabarIsland_Mart_Pokemart
@ 	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
@ 	release
@ 	end
@
@ 	.align 2
@ CinnabarIsland_Mart_Pokemart:
@ 	.2byte ITEM_ULTRA_BALL
@ 	.2byte ITEM_NET_BALL
@ 	.2byte ITEM_HYPER_POTION
@ 	.2byte ITEM_FULL_HEAL
@ 	.2byte ITEM_REVIVE
@ 	.2byte ITEM_MAX_REPEL
@ 	.2byte ITEM_X_ATTACK
@ 	.2byte ITEM_X_DEFEND
@ 	.2byte ITEM_NONE
@ 	release
@ 	end
@ --- End original content ---

CinnabarIsland_Mart_MapScripts::
	.byte 0

CinnabarIsland_Mart_EventScript_Clerk::
	end
