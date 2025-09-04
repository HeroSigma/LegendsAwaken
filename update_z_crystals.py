#!/usr/bin/env python3

import re

# Read the file
with open('src/data/items.h', 'r') as f:
    content = f.read()

# Find all Z-crystal items (those with HOLD_EFFECT_Z_CRYSTAL)
z_crystal_pattern = r'(\[ITEM_\w*Z\] =\s*\{[^}]*?holdEffect = HOLD_EFFECT_Z_CRYSTAL[^}]*?)pocket = POCKET_ITEMS([^}]*?\})'

def replace_z_crystal(match):
    return match.group(1) + 'pocket = POCKET_Z_CRYSTALS' + match.group(2)

# Replace Z-crystals
updated_content = re.sub(z_crystal_pattern, replace_z_crystal, content, flags=re.DOTALL)

# Write back
with open('src/data/items.h', 'w') as f:
    f.write(updated_content)

print("Updated Z-crystals to POCKET_Z_CRYSTALS")
