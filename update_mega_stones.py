#!/usr/bin/env python3

import re

# Read the file
with open('src/data/items.h', 'r') as f:
    content = f.read()

# Find all mega stone items (those ending in 'ITE]' and having HOLD_EFFECT_MEGA_STONE)
mega_stone_pattern = r'(\[ITEM_\w*ITE\] =\s*\{[^}]*?holdEffect = HOLD_EFFECT_MEGA_STONE[^}]*?)pocket = POCKET_ITEMS([^}]*?\})'

def replace_mega_stone(match):
    return match.group(1) + 'pocket = POCKET_MEGASTONES' + match.group(2)

# Replace mega stones
updated_content = re.sub(mega_stone_pattern, replace_mega_stone, content, flags=re.DOTALL)

# Write back
with open('src/data/items.h', 'w') as f:
    f.write(updated_content)

print("Updated mega stones to POCKET_MEGASTONES")
