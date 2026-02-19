# Color-Coded Battle Messages

This feature adds color coding to battle effectiveness messages to make them more visually distinct and intuitive.

## Implementation Details

### Modified File
- `src/battle_message.c` - Modified the `BattlePutTextOnWindow()` function

### Color Scheme
- **Super Effective**: Green text (`TEXT_COLOR_GREEN`) with dark gray shadow
- **Not Very Effective**: Red text (`TEXT_COLOR_RED`) with dark gray shadow  
- **Doesn't Affect**: Light gray text (`TEXT_COLOR_LIGHT_GRAY`) with dark gray shadow

### Messages Affected
- `STRINGID_SUPEREFFECTIVE` - "It's super effective!"
- `STRINGID_SUPEREFFECTIVETWOFOES` - "It's super effective on [Pokemon] and [Pokemon]!"
- `STRINGID_NOTVERYEFFECTIVE` - "It's not very effective…"
- `STRINGID_NOTVERYEFFECTIVETWOFOES` - "It's not very effective on [Pokemon] and [Pokemon]!"
- `STRINGID_ITDOESNTAFFECT` - "It doesn't affect [Pokemon]…"
- `STRINGID_ITDOESNTAFFECTTWOFOES` - "It doesn't affect [Pokemon] and [Pokemon]…"

### How It Works
The modification checks if the text being displayed to the main battle message window (`B_WIN_MSG`) matches any of the effectiveness message strings. If a match is found, it overrides the default text colors with the appropriate color before rendering.

### Technical Notes
- Only affects the main battle message window to avoid unintended color changes in other UI elements
- Uses existing `StringCompare()` function for reliable text matching
- Maintains original shadow color consistency across all effectiveness messages
- Preserves all other text rendering behavior

## Usage
This feature is automatically active when playing the game. No configuration is required.

## Compatibility
- Compatible with all battle types (single, double, link, etc.)
- Works with existing battle mechanics and message systems
- No impact on performance or battle flow
