@ === SixIsland_WaterPath scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ SixIsland_WaterPath_MapScripts::
@ 	.byte 0
@
@ SixIsland_WaterPath_EventScript_HornWantedSign::
@ 	msgbox SixIsland_WaterPath_Text_WantedUltimateHorn, MSGBOX_SIGN
@ 	end
@
@ SixIsland_WaterPath_EventScript_RouteSign::
@ 	msgbox SixIsland_WaterPath_Text_RouteSign, MSGBOX_SIGN
@ 	end
@
@ SixIsland_WaterPath_Text_WantedUltimateHorn::
@     .string "Wanted!\n"
@     .string "The Ultimate Horn!$"
@
@ SixIsland_WaterPath_Text_RouteSign::
@     .string "WATER PATH\n"
@     .string "Leads to RUIN VALLEY$"
@ --- End original content ---

SixIsland_WaterPath_MapScripts::
	.byte 0

SixIsland_WaterPath_EventScript_HornWantedSign::
	end

SixIsland_WaterPath_EventScript_RouteSign::
	end

SixIsland_WaterPath_Text_WantedUltimateHorn::
	end

SixIsland_WaterPath_Text_RouteSign::
	end
