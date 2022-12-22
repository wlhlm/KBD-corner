# Unfortunately, the build system doesn't support info.json in keymaps, so I
# have to use old-style build files. Alternatively, I could override info.json
# using keymap.json, however that would prevent me from using the C preprocessor
# for the keymap.

KEY_OVERRIDE_ENABLE = yes
LEADER_ENABLE = yes

DEBOUNCE_TYPE = sym_eager_pk
