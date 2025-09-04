//Declaration of side quest structures. Edits to quests are made here.
#define side_quest(n, d, dd, m, s, st, sq, ns) {.name = n, .desc = d, .donedesc = dd, .map = m, .sprite = s, .spritetype = st, .subquests = sq, .numSubquests = ns}
static const struct SideQuest sSideQuests[QUEST_COUNT] =
{
	// S1–01 — Main Story: Hoenn • "Rifts Wake"
	side_quest(
		gText_SideQuestName_1,
		gText_SideQuestDesc_1,
		gText_SideQuestDoneDesc_1,
		gText_SideQuestMap1,
		OBJ_EVENT_GFX_PROF_BIRCH,
		OBJECT,
		sSubQuests1,
		QUEST_S1_01_SUB_COUNT
	),
	
	// S1–02 — League: "Champion of Hoenn"
	side_quest(
		gText_SideQuestName_2,
		gText_SideQuestDesc_2,
		gText_SideQuestDoneDesc_2,
		gText_SideQuestMap2,
		OBJ_EVENT_GFX_WALLACE,
		OBJECT,
		sSubQuests2,
		QUEST_S1_02_SUB_COUNT
	),
	
	// S1–03 — Faction (Aqua): "Operation: Tide of Data"
	side_quest(
		gText_SideQuestName_3,
		gText_SideQuestDesc_3,
		gText_SideQuestDoneDesc_3,
		gText_SideQuestMap3,
		OBJ_EVENT_GFX_AQUA_MEMBER_M,
		OBJECT,
		NULL,
		0
	),
	
	// S1–04 — Faction (Magma): "Operation: Ash & Ember"
	side_quest(
		gText_SideQuestName_4,
		gText_SideQuestDesc_4,
		gText_SideQuestDoneDesc_4,
		gText_SideQuestMap4,
		OBJ_EVENT_GFX_MAGMA_MEMBER_M,
		OBJECT,
		NULL,
		0
	),
	
	// S1–05 — Faction (Plasma/Colress): "Operation: Signal Chain"
	side_quest(
		gText_SideQuestName_5,
		gText_SideQuestDesc_5,
		gText_SideQuestDoneDesc_5,
		gText_SideQuestMap5,
		OBJ_EVENT_GFX_SCIENTIST_1,
		OBJECT,
		NULL,
		0
	),
	
	// S1–06 — Rivals: "Hoenn Circuit"
	side_quest(
		gText_SideQuestName_6,
		gText_SideQuestDesc_6,
		gText_SideQuestDoneDesc_6,
		gText_SideQuestMap6,
		OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL,
		OBJECT,
		NULL,
		0
	)
};
