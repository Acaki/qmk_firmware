#pragma once
#include "mesnigan.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    RSTROM = PLACEHOLDER_SAFE_RANGE,
    ATAB,
    CTAB,
    WINDOWS,
    MACOS,
    FARM,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

#define MOUSE MO(_MOUSE)
#define NUMBL MO(_NUMBL)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMING TD(GAMING_TD)

// Left-hand home row mods
#define HOME_L1 LCTL_T(KC_F)
#define HOME_L2 LSFT_T(KC_D)
#define HOME_L3 LALT_T(KC_S)
#define HOME_L4 LGUI_T(KC_A)

// Right-hand home row mods
#define HOME_R1 RCTL_T(KC_J)
#define HOME_R2 RSFT_T(KC_K)
#define HOME_R3 RALT_T(KC_L)
#define HOME_R4 RGUI_T(KC_SCLN)

#define THUMB_L1 KC_BSPC 
#define THUMB_L2 LT(_LOWER, KC_SPC) 
#define THUMB_L3 KC_DEL
#define THUMB_R1 MOUSE
#define THUMB_R2 LT(_RAISE, KC_ENT)
#define THUMB_R3 NUMBL