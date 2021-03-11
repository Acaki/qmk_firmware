#pragma once
#include "mesnigan.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        WIN_A,   WIN_S,   WIN_D,   WIN_F,   KC_G
#define _______________QWERTY_MAC_L2_______________        MAC_A,   MAC_S,   MAC_D,   MAC_F,   KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define _________________QWERTY_LT_________________                                   MOUSE,   KC_SPC,  LT(_LOWER, KC_ESC)

#define _________________QWERTY_R1_________________                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________                            KC_H,    WIN_J,   WIN_K,   WIN_L,   WIN_SCLN
#define _______________QWERTY_MAC_R2_______________                            KC_H,    MAC_J,   MAC_K,   MAC_L,   MAC_SCLN
#define _________________QWERTY_R3_________________                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
#define _________________QWERTY_RT_________________        LT(_RAISE, KC_ENT), KC_BSPC, KC_DEL

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________GAMING_L1_________________        KC_T,    KC_Q,    KC_W,    KC_E,    KC_R
#define _________________GAMING_L2_________________        KC_G,    KC_A,    KC_S,    KC_D,    KC_F
#define _________________GAMING_L3_________________        KC_B,    KC_Z,    KC_X,    KC_C,    KC_V

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________MOUSE_R1__________________                 _______, KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN4
#define _________________MOUSE_R2__________________                 _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5
#define _________________MOUSE_R3__________________                 _______, KC_WH_L, _______, KC_WH_R, _______
#define _________________MOUSE_RT__________________        KC_BTN3, KC_BTN1, KC_BTN2

#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L2__________________        KC_F11,  CTAB,    ASFT,    ATAB,    _______
#define _________________LOWER_L3__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC

#define _________________LOWER_R1__________________        _________________FUNC_RIGHT________________
#define _________________LOWER_R2__________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12
#define _________________LOWER_R3__________________        KC_CIRC, KC_AMPR, KC_ASTR, _______, _______

#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_PLUS
#define _________________RAISE_L3__________________        KC_RCBR, KC_RBRC, KC_RPRN, KC_MINS, KC_ASTR

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS
#define _________________RAISE_R3__________________        ___________________BLANK___________________

#define _________________ADJUST_L1_________________        RSTROM,  WINDOWS, _______, RESET,   _______
#define _________________ADJUST_L2_________________        ___________________BLANK___________________
#define _________________ADJUST_L3_________________        ___________________BLANK___________________

#define _________________ADJUST_R1_________________        _______, _______, _______, _______, KC_PSCR
#define _________________ADJUST_R2_________________        KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY
#define _________________ADJUST_R3_________________        _______, MACOS,   _______, _______, _______

// clang-format on
