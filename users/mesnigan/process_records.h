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
    CTAB,
    RSTROM,
    TOG_OS,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

#define MOUSE MO(_MOUSE)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMING TG(_GAMING)
// Left-hand home row mods
#define WIN_A LGUI_T(KC_A)
#define WIN_S LALT_T(KC_S)
#define WIN_D LSFT_T(KC_D)
#define WIN_F LCTL_T(KC_F)

#define MAC_A LALT_T(KC_A)
#define MAC_S LCTL_T(KC_S)
#define MAC_D LSFT_T(KC_D)
#define MAC_F LGUI_T(KC_F)

// Right-hand home row mods
#define WIN_J RCTL_T(KC_J)
#define WIN_K RSFT_T(KC_K)
#define WIN_L LALT_T(KC_L)
#define WIN_SCLN RGUI_T(KC_SCLN)

#define MAC_J RGUI_T(KC_J)
#define MAC_K RSFT_T(KC_K)
#define MAC_L RCTL_T(KC_L)
#define MAC_SCLN LALT_T(KC_SCLN)
