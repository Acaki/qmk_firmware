#pragma once
#include "mesnigan.h"

#if defined(KEYBOARD_bastardkb_charybdis_4x6)
#    define PLACEHOLDER_SAFE_RANGE CHARYBDIS_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    ATAB = PLACEHOLDER_SAFE_RANGE,
    CTAB,
    MOFFESC,
    SPAMLC,
    SPAMRC,
    COLEMAK,
    QWERTY,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

#define MOUSE MO(_MOUSE)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMING TD(GAMING_TD)
#define FUNCL MO(_FUNCL)

// Left-hand home row mods
#define QWERTY_HOME_L1 LCTL_T(KC_F)
#define QWERTY_HOME_L2 LSFT_T(KC_D)
#define QWERTY_HOME_L3 LALT_T(KC_S)
#define QWERTY_HOME_L4 LGUI_T(KC_A)
#define COLEMAK_HOME_L1 LCTL_T(KC_T)
#define COLEMAK_HOME_L2 LSFT_T(KC_S)
#define COLEMAK_HOME_L3 LALT_T(KC_R)
#define COLEMAK_HOME_L4 LGUI_T(KC_A)

// Right-hand home row mods
#define QWERTY_HOME_R1 RCTL_T(KC_J)
#define QWERTY_HOME_R2 RSFT_T(KC_K)
#define QWERTY_HOME_R3 RALT_T(KC_L)
#define QWERTY_HOME_R4 RGUI_T(KC_SCLN)
#define COLEMAK_HOME_R1 RCTL_T(KC_N)
#define COLEMAK_HOME_R2 RSFT_T(KC_E)
#define COLEMAK_HOME_R3 RALT_T(KC_I)
#define COLEMAK_HOME_R4 RGUI_T(KC_O)


#define THUMB_L1 KC_BSPC 
#define THUMB_L2 LT(_LOWER, KC_SPC) 
#define THUMB_L3 LT(_FUNCL, KC_TAB)
#define THUMB_R1 MOUSE
#define THUMB_R2 LT(_RAISE, KC_ENT)
#define THUMB_R3 LT(_NUMBL, KC_ESC)