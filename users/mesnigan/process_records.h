#pragma once
#include "mesnigan.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    TOG_IME = PLACEHOLDER_SAFE_RANGE,
    RSTROM,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

#define MOUSE MO(_MOUSE)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMING TG(_GAMING)
// Left-hand home row mods
#define HOME_L1 LCTL_T(KC_F)
#define HOME_L2 LSFT_T(KC_D)
#define HOME_L3 LGUI_T(KC_S)
#define HOME_L4 LALT_T(KC_A)

// Right-hand home row mods
#define HOME_R1 RCTL_T(KC_J)
#define HOME_R2 RSFT_T(KC_K)
#define HOME_R3 RGUI_T(KC_L)
#define HOME_R4 LALT_T(KC_SCLN)
