# Quest System Technical Reference

## File Structure

### Core Quest Files
```
include/constants/quests.h    - Quest constants and definitions
src/strings.c                 - Quest text strings and descriptions  
src/quests.c                  - Quest logic and array definitions
```

## Constants Reference (`include/constants/quests.h`)

### Quest Count
```c
#define QUEST_COUNT 30
```

### Season 1 Quest Constants
```c
#define QUEST_S1_01_MAIN_STORY    0  // 'Rifts Wake'
#define QUEST_S1_02_LEAGUE        1  // 'Champion of Hoenn'
#define QUEST_S1_03_FACTION_AQUA  2  // 'Operation: Tide of Data'
#define QUEST_S1_04_FACTION_MAGMA 3  // 'Operation: Ash & Ember'
#define QUEST_S1_05_FACTION_PLASMA 4 // 'Operation: Signal Chain'
#define QUEST_S1_06_RIVALS        5  // 'Hoenn Circuit'
```

### Future Expansion Constants
```c
#define QUEST_7  6   // Future Season content
#define QUEST_8  7   // Future Season content
// ... continuing through QUEST_30 (index 29)
```

## String System (`src/strings.c`)

### Text String Arrays
- **Quest Names**: `gText_SideQuestName_1` through `gText_SideQuestName_30`
- **Descriptions**: `gText_SideQuestDesc_1` through `gText_SideQuestDesc_30`
- **Completion Text**: `gText_SideQuestComplete_1` through `gText_SideQuestComplete_30`
- **Map Locations**: `gText_SideQuestMap_1` through `gText_SideQuestMap_30`

### Example Implementation
```c
const u8 gText_SideQuestName_1[] = _("S1-01 Main Story: 'Rifts Wake'");
const u8 gText_SideQuestDesc_1[] = _("A mysterious energy disturbance has been detected in Petalburg Woods...");
```

## Quest Logic (`src/quests.c`)

### Main Quest Array
```c
const struct SideQuest sSideQuests[QUEST_COUNT] = {
    // Implemented quests with full functionality
    side_quest(gText_SideQuestName_1, gText_SideQuestDesc_1, ...),
    
    // Placeholder quests for future implementation
    side_quest(gText_SideQuestName_7, gText_SideQuestDesc_7, ..., TRUE),
};
```

### Sub-Quest Implementation
```c
static const u8 *const sSubQuests1[] = {
    _("Investigate the strange energy readings"),
    _("Locate the dimensional rift"),
    // ... additional objectives
};
```

### Quest Macro Parameters
```c
side_quest(
    name,                    // Quest name string
    description,            // Quest description string
    completion_text,        // Completion message string
    map_location,          // Associated map location string
    object_event_gfx,      // Character sprite constant
    sub_quests,            // Sub-quest array (or NULL)
    sub_quest_count,       // Number of sub-quests (or 0)
    not_yet_implemented    // Boolean flag for implementation status
)
```

## Implementation Patterns

### Fully Implemented Quest
```c
side_quest(
    gText_SideQuestName_1,
    gText_SideQuestDesc_1,
    gText_SideQuestComplete_1,
    gText_SideQuestMap_1,
    OBJ_EVENT_GFX_PROF_BIRCH,
    sSubQuests1,
    ARRAY_COUNT(sSubQuests1),
    FALSE
),
```

### Placeholder Quest
```c
side_quest(
    gText_SideQuestName_7,
    gText_SideQuestDesc_7,
    gText_SideQuestComplete_7,
    gText_SideQuestMap_7,
    OBJ_EVENT_GFX_YOUNGSTER,
    NULL,
    0,
    TRUE
),
```

## Development Workflow

### Adding a New Quest
1. **Define Constant**: Add to `include/constants/quests.h`
2. **Create Strings**: Add to `src/strings.c`
3. **Implement Logic**: Add to `src/quests.c`
4. **Test Build**: Run `make` to verify compilation
5. **Test Functionality**: Verify in-game behavior

### Expanding Existing Quest
1. **Update Description**: Modify string in `src/strings.c`
2. **Add Sub-Quests**: Create sub-quest array if needed
3. **Update Quest Entry**: Modify entry in `sSideQuests` array
4. **Set Implementation Flag**: Change `TRUE` to `FALSE`

## Memory Considerations

- **Quest Array Size**: 30 * sizeof(struct SideQuest)
- **String Memory**: All quest strings stored in ROM
- **Sub-Quest Arrays**: Additional memory per quest with objectives

## Debugging and Testing

### Compilation Checks
```bash
cd /root/LegendsAwaken
make clean
make
```

### Common Issues
- **String Length**: Ensure quest descriptions fit display constraints
- **Array Bounds**: Verify QUEST_COUNT matches actual array size
- **Missing Strings**: All referenced strings must be defined

### Validation Points
- All quest constants properly defined
- String arrays complete and properly referenced
- Quest array size matches QUEST_COUNT
- No compilation warnings or errors

## Future Development Notes

### Season Expansion Strategy
- Quests 1-6: Season 1 content
- Quests 7-12: Potential Season 2 content
- Quests 13-18: Potential Season 3 content
- Quests 19-24: Potential Season 4 content
- Quests 25-30: Potential Season 5 content

### Scalability Considerations
- Current implementation supports 30 quests efficiently
- System can be expanded by updating QUEST_COUNT
- All arrays and string definitions scale automatically
- Memory usage remains manageable for GBA constraints

---

**Last Updated**: September 3, 2025  
**Branch**: Legends-Missions  
**Compatibility**: LegendsAwaken ROM Hack
