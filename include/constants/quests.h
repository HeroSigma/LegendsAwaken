#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           2   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_REWARD           3   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       4   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_CHECK_UNLOCKED       5   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_INACTIVE       6 //check if a questID is inactive. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_ACTIVE         7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_REWARD         8  //checks if questId is in Reward state. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       9   //checks if questId has been completed. Returns result to gSpecialVar_Result
#define QUEST_MENU_BUFFER_QUEST_NAME    10   //buffers a quest name to gStringVar1

// quest number defines - Season 1 Legends Missions
#define QUEST_S1_01_MAIN_STORY       0  // S1–01 — Main Story: Hoenn • "Rifts Wake"
#define QUEST_S1_02_LEAGUE           1  // S1–02 — League: "Champion of Hoenn"
#define QUEST_S1_03_FACTION_AQUA     2  // S1–03 — Faction (Aqua): "Operation: Tide of Data"
#define QUEST_S1_04_FACTION_MAGMA    3  // S1–04 — Faction (Magma): "Operation: Ash & Ember"
#define QUEST_S1_05_FACTION_PLASMA   4  // S1–05 — Faction (Plasma/Colress): "Operation: Signal Chain"
#define QUEST_S1_06_RIVALS           5  // S1–06 — Rivals: "Hoenn Circuit"

// Future quest constants (7-30) - Not yet implemented
#define QUEST_7                      6  // ???? / Not yet implemented
#define QUEST_8                      7  // ???? / Not yet implemented
#define QUEST_9                      8  // ???? / Not yet implemented
#define QUEST_10                     9  // ???? / Not yet implemented
#define QUEST_11                     10 // ???? / Not yet implemented
#define QUEST_12                     11 // ???? / Not yet implemented
#define QUEST_13                     12 // ???? / Not yet implemented
#define QUEST_14                     13 // ???? / Not yet implemented
#define QUEST_15                     14 // ???? / Not yet implemented
#define QUEST_16                     15 // ???? / Not yet implemented
#define QUEST_17                     16 // ???? / Not yet implemented
#define QUEST_18                     17 // ???? / Not yet implemented
#define QUEST_19                     18 // ???? / Not yet implemented
#define QUEST_20                     19 // ???? / Not yet implemented
#define QUEST_21                     20 // ???? / Not yet implemented
#define QUEST_22                     21 // ???? / Not yet implemented
#define QUEST_23                     22 // ???? / Not yet implemented
#define QUEST_24                     23 // ???? / Not yet implemented
#define QUEST_25                     24 // ???? / Not yet implemented
#define QUEST_26                     25 // ???? / Not yet implemented
#define QUEST_27                     26 // ???? / Not yet implemented
#define QUEST_28                     27 // ???? / Not yet implemented
#define QUEST_29                     28 // ???? / Not yet implemented
#define QUEST_30                     29 // ???? / Not yet implemented

// Legacy compatibility mappings
#define QUEST_1          QUEST_S1_01_MAIN_STORY
#define QUEST_2          QUEST_S1_02_LEAGUE
#define QUEST_3          QUEST_S1_03_FACTION_AQUA
#define QUEST_4          QUEST_S1_04_FACTION_MAGMA
#define QUEST_5          QUEST_S1_05_FACTION_PLASMA
#define QUEST_6          QUEST_S1_06_RIVALS

#define QUEST_COUNT     30

// Legacy quest aliases for backwards compatibility
#define QUEST_1          QUEST_S1_01_MAIN_STORY
#define QUEST_2          QUEST_S1_02_LEAGUE
#define QUEST_3          QUEST_S1_03_FACTION_AQUA
#define QUEST_4          QUEST_S1_04_FACTION_MAGMA
#define QUEST_5          QUEST_S1_05_FACTION_PLASMA
#define QUEST_6          QUEST_S1_06_RIVALS
#define QUEST_7          6
#define QUEST_8          7
#define QUEST_9          8
#define QUEST_10         9
#define QUEST_11        10
#define QUEST_12        11
#define QUEST_13        12
#define QUEST_14        13
#define QUEST_15        14
#define QUEST_16        15
#define QUEST_17        16
#define QUEST_18        17
#define QUEST_19        18
#define QUEST_20        19
#define QUEST_21        20
#define QUEST_22        21
#define QUEST_23        22
#define QUEST_24        23
#define QUEST_25        24
#define QUEST_26        25
#define QUEST_27        26
#define QUEST_28        27
#define QUEST_29        28
#define QUEST_30        29

#define SUB_QUEST_S1_01_1        0  // 1.1 Go to Littleroot Lab and speak with Birch
#define SUB_QUEST_S1_01_2        1  // 1.2 Return home and watch the world report on TV
#define SUB_QUEST_S1_01_3        2  // 1.3 Check on the Devon Researcher in Petalburg Woods
#define SUB_QUEST_S1_01_4        3  // 1.4 Report to Devon HQ (Rustboro)
#define SUB_QUEST_S1_01_5        4  // 1.5 Meet Captain Stern at the Slateport Museum
#define SUB_QUEST_S1_01_6        5  // 1.6 Visit the meteor site and hear the Magma briefing
#define SUB_QUEST_S1_01_7        6  // 1.7 Go to the Weather Institute; stop the intrusion
#define SUB_QUEST_S1_01_8        7  // 1.8 Meet Colress at the Mossdeep Lab
#define SUB_QUEST_S1_01_9        8  // 1.9 Deliver Birch's Letter to Steven (Granite Cave)
#define SUB_QUEST_S1_01_10       9  // 1.10 Story update: "Challenge the Hoenn League"
#define SUB_QUEST_S1_01_11      10  // 1.11 After you're Champion: "Speak to Elm"

// League sub-objectives
#define SUB_QUEST_S1_02_ROXANNE  11  // Defeat Roxanne and get Mega Ring
#define SUB_QUEST_S1_02_BRAWLY   12  // Defeat Brawly and get Z-Power Bracelet
#define SUB_QUEST_S1_02_WATTSON  13  // Defeat Wattson and get Tera Orb
#define SUB_QUEST_S1_02_FLANNERY 14  // Defeat Flannery and get Dynamax Band
#define SUB_QUEST_S1_02_NORMAN   15  // Defeat Norman and get Normal Gems
#define SUB_QUEST_S1_02_WINONA   16  // Defeat Winona and get Flying Gems
#define SUB_QUEST_S1_02_TWINS    17  // Defeat Tate & Liza and get Psychic Gems
#define SUB_QUEST_S1_02_JUAN     18  // Defeat Juan and get Water Gems
#define SUB_QUEST_S1_02_E4_1     19  // Defeat E4 #1 and get Eon Ticket
#define SUB_QUEST_S1_02_E4_2     20  // Defeat E4 #2 and get Mystic Ticket
#define SUB_QUEST_S1_02_E4_3     21  // Defeat E4 #3 and get Aurora Ticket
#define SUB_QUEST_S1_02_E4_4     22  // Defeat E4 #4 and get Old Sea Map
#define SUB_QUEST_S1_02_CHAMPION 23  // Defeat Champion

// Legacy aliases
#define SUB_QUEST_1          0
#define SUB_QUEST_2          1
#define SUB_QUEST_3          2
#define SUB_QUEST_4          3
#define SUB_QUEST_5          4
#define SUB_QUEST_6          5
#define SUB_QUEST_7          6
#define SUB_QUEST_8          7
#define SUB_QUEST_9          8
#define SUB_QUEST_10         9
#define SUB_QUEST_11        10
#define SUB_QUEST_12        11
#define SUB_QUEST_13        12
#define SUB_QUEST_14        13
#define SUB_QUEST_15        14
#define SUB_QUEST_16        15
#define SUB_QUEST_17        16
#define SUB_QUEST_18        17
#define SUB_QUEST_19        18
#define SUB_QUEST_20        19
#define SUB_QUEST_21        20
#define SUB_QUEST_22        21
#define SUB_QUEST_23        22
#define SUB_QUEST_24        23
#define SUB_QUEST_25        24
#define SUB_QUEST_26        25
#define SUB_QUEST_27        26
#define SUB_QUEST_28        27
#define SUB_QUEST_29        28
#define SUB_QUEST_30        29

#define QUEST_S1_01_SUB_COUNT    11  // Main Story has 11 objectives
#define QUEST_S1_02_SUB_COUNT    13  // League has 13 objectives  
#define QUEST_1_SUB_COUNT QUEST_S1_01_SUB_COUNT
#define QUEST_2_SUB_COUNT QUEST_S1_02_SUB_COUNT
#define SUB_QUEST_COUNT (QUEST_S1_01_SUB_COUNT + QUEST_S1_02_SUB_COUNT)

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
