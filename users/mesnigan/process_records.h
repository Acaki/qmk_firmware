#pragma once
#include "mesnigan.h"

enum userspace_custom_keycodes {
    ATAB = SAFE_RANGE,
    CTAB,
    MOFFESC,
    SPAMLC,
    SPAMRC,
    KVMPC1,
    KVMPC2,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

#define MOUSE MO(_MOUSE)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAMING TD(GAMING_TD)
#define FUNCL MO(_FUNCL)

// Left-hand home row mods
#define COLEMAK_HOME_L1 LCTL_T(KC_T)
#define COLEMAK_HOME_L2 LSFT_T(KC_S)
#define COLEMAK_HOME_L3 LALT_T(KC_R)
#define COLEMAK_HOME_L3A LGUI_T(KC_R)
#define COLEMAK_HOME_L4 LGUI_T(KC_A)
#define COLEMAK_HOME_L4A LALT_T(KC_A)

// Right-hand home row mods
#define COLEMAK_HOME_R1 RCTL_T(KC_N)
#define COLEMAK_HOME_R2 RSFT_T(KC_E)
#define COLEMAK_HOME_R3 RALT_T(KC_I)
#define COLEMAK_HOME_R3A RGUI_T(KC_I)
#define COLEMAK_HOME_R4 RGUI_T(KC_O)
#define COLEMAK_HOME_R4A RALT_T(KC_O)


#define THUMB_L1 KC_BSPC 
#define THUMB_L2 LT(_LOWER, KC_SPC) 
#define THUMB_L3 LT(_SYMBL, KC_TAB)
#define THUMB_R1 MOUSE
#define THUMB_R2 LT(_RAISE, KC_ENT)
#define THUMB_R3 LT(_FUNCL, KC_ESC)

#define PRVD C(G(KC_LEFT))
#define NXTD C(G(KC_RGHT))
#define MPRVD C(S(G(KC_LEFT)))
#define MNXTD C(S(G(KC_RGHT)))
