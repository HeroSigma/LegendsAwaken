@ === WhirlIslands_B1F scripts (temporarily disabled) ===
@ === To re-enable: remove this file and restore from git ===
@
@ --- Original content (commented) ---
@ WhirlIslands_B1F_MapScripts::
@ 	.byte 0
@
@ WhirlIslands_B1F_Trigger_Sunlight::
@ 	setweather WEATHER_SUNNY
@ 	doweather
@ 	end
@
@ WhirlIslands_B1F_Trigger_Shade::
@ 	setweather WEATHER_SHADE
@ 	doweather
@ 	end
@
@ WhirlIslands_B1F_Trigger_Rain::
@ 	setweather WEATHER_RAIN
@ 	doweather
@ 	end
@
@ WhirlIslands_B1F_EventScript_Item_Big_Nugget::
@ 	finditem ITEM_BIG_NUGGET
@ 	end
@
@ WhirlIslands_B1F_EventScript_Item_Full_Restore::
@ 	finditem ITEM_FULL_RESTORE
@ 	end
@
@ WhirlIslands_B1F_EventScript_Item_Carbos::
@ 	finditem ITEM_CARBOS
@ 	end
@
@ WhirlIslands_B1F_EventScript_Item_Calcium::
@ 	finditem ITEM_CALCIUM
@ 	end
@
@ WhirlIslands_B1F_EventScript_Item_Escape_Rope::
@ 	finditem ITEM_ESCAPE_ROPE
@ 	end
@ --- End original content ---

WhirlIslands_B1F_MapScripts::
	.byte 0

WhirlIslands_B1F_Trigger_Sunlight::
	end

WhirlIslands_B1F_Trigger_Shade::
	end

WhirlIslands_B1F_Trigger_Rain::
	end

WhirlIslands_B1F_EventScript_Item_Big_Nugget::
	end

WhirlIslands_B1F_EventScript_Item_Full_Restore::
	end

WhirlIslands_B1F_EventScript_Item_Carbos::
	end

WhirlIslands_B1F_EventScript_Item_Calcium::
	end

WhirlIslands_B1F_EventScript_Item_Escape_Rope::
	end
