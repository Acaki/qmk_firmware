#pragma once
#include "mesnigan.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    ATAB = PLACEHOLDER_SAFE_RANGE,
    ASFT,
    RSTROM,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

#define MOUSE MO(_MOUSE)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMING TG(_GAMING)

#define ESC_LWR LT(_LOWER, KC_ESC)
#define BSC_RAS LT(_RAISE, KC_BSPC)