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

#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        HOME_L4, HOME_L3, HOME_L2, HOME_L1, KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define _________________QWERTY_LT_________________                          THUMB_L1, THUMB_L2, THUMB_L3

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    HOME_R1, HOME_R2, HOME_R3, HOME_R4
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
#define _________________QWERTY_RT_________________        THUMB_R3, THUMB_R2, THUMB_R1

#define _________________GAMING_L1S________________        KC_T,    KC_Q,    KC_X,    KC_E,    KC_R
#define _________________GAMING_L2S________________        KC_G,    KC_A,    KC_W,    KC_D,    KC_F
#define _________________GAMING_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________GAMING_L3S________________        KC_B,    KC_Z,    KC_S,    KC_C,    KC_V
#define _________________GAMING_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN

#define _________________MOUSE_L1__________________        KC_BTN4, KC_WH_U, KC_MS_U, KC_WH_D, _______
#define _________________MOUSE_L2__________________        KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_R, _______
#define _________________MOUSE_L3__________________        _______, KC_WH_L, _______, KC_WH_R, _______
#define _________________MOUSE_LT__________________                                   KC_BTN2, KC_BTN1, KC_BTN3

#define _________________MOUSE_R1__________________                 _______, KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN4
#define _________________MOUSE_R2__________________                 _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5
#define _________________MOUSE_R3__________________                 _______, KC_WH_L, _______, KC_WH_R, _______
#define _________________MOUSE_RT__________________        KC_BTN3, KC_BTN1, KC_BTN2

#define _________________LOWER_L1__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L2__________________        KC_F11,  ATAB,    KC_LSFT, CTAB,    KC_LOCK
#define _________________LOWER_L3__________________        A(KC_F1),A(KC_F2),A(KC_F9),A(KC_F10), _______

#define _________________LOWER_R1__________________        _________________FUNC_RIGHT________________
#define _________________LOWER_R2__________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12
#define _________________LOWER_R3__________________        KC_PGUP, KC_HOME, KC_END,  KC_PGDN, KC_INS

#define _________________RAISE_L1__________________        _________________FUNC_LEFT_________________
#define _________________RAISE_L2__________________        KC_F11,  KC_LCBR, KC_LBRC, KC_LPRN, _______
#define _________________RAISE_L3__________________        _______, KC_RCBR, KC_RBRC, KC_RPRN, _______

#define _________________RAISE_R1__________________        _________________FUNC_RIGHT________________
#define _________________RAISE_R2__________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F12
#define _________________RAISE_R3__________________        KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE

#define _________________ADJUST_L1_________________        _______, _______, _______, RESET,   _______
#define _________________ADJUST_L2_________________        ___________________BLANK___________________
#define _________________ADJUST_L3_________________        ___________________BLANK___________________

#define _________________ADJUST_R1_________________        _______, _______, _______, _______, KC_PSCR
#define _________________ADJUST_R2_________________        _______, SPAMLC,  SPAMRC,  _______, _______
#define _________________ADJUST_R3_________________        ___________________BLANK___________________



// clang-format on
