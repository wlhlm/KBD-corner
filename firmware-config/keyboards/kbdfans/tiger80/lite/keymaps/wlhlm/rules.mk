# Unfortunately, the build system doesn't support info.json in keymaps, so I
# have to use old-style build files. Alternatively, I could override info.json
# using keymap.json, however that would prevent me from using the C preprocessor
# for the keymap.

MOUSEKEY_ENABLE = no
TAP_DANCE_ENABLE = no
SECURE_ENABLE = no
SPACE_CADET_ENABLE = no
LOCKING_SUPPORT_ENABLE = no
LOCKING_RESYNC_ENABLE = no

MAGIC_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
LEADER_ENABLE = yes
#CAPS_WORD_ENABLE = yes

DEBOUNCE_TYPE = sym_eager_pk

