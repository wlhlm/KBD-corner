#include "config_common.h"

#define LAYER_STATE_8BIT // Limits maximum number of layers to 8

// Remove a bunch of the default RGB effects I don't need.
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT

#undef RGBLIGHT_DEFAULT_MODE
