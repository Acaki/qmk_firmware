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
#define _________________QWERTY_L2_________________        HOME_L4, HOME_L3, HOME_L2, HOME_L1, KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define _________________QWERTY_LT_________________                                   LT(_NAV, KC_TAB), KC_BSPC, LT(_LOWER, KC_DEL)

#define _________________QWERTY_R1_________________                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________                            KC_H,    HOME_R1, HOME_R2, HOME_R3, HOME_R4
#define _________________QWERTY_R3_________________                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
#define _________________QWERTY_RT_________________        LT(_RAISE, KC_ENT), KC_SPC,  LT(_MOUSE, KC_ESC)

#define ________________NUMBER_LEFT________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________GAMING_L1_________________        KC_T,    KC_Q,    KC_W,    KC_E,    KC_R
#define _________________GAMING_L2_________________        KC_G,    KC_A,    KC_S,    KC_D,    KC_F
#define _________________GAMING_L3_________________        KC_B,    KC_Z,    KC_X,    KC_C,    KC_V
#define _________________GAMING_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN

#define _________________FUNC_LEFT_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define _________________MOUSE_L1__________________        KC_BTN4, KC_WH_U, KC_MS_U, KC_WH_D, _______
#define _________________MOUSE_L2__________________        KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_R, _______
#define _________________MOUSE_L3__________________        _______, KC_WH_L, _______, KC_WH_R, _______
#define _________________MOUSE_LT__________________                                   KC_BTN2, KC_BTN1, KC_BTN3

#define _________________MOUSE_R1__________________                 _______, KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN4
#define _________________MOUSE_R2__________________                 _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5
#define _________________MOUSE_R3__________________                 _______, KC_WH_L, _______, KC_WH_R, _______
#define _________________MOUSE_RT__________________        KC_BTN3, KC_BTN1, KC_BTN2


#define ___________________BLANK___________________        _______, _______, _______, _______, _______

#define _________________NAV_R1____________________        _______, _______, KC_INS,  _______, KC_PSCR
#define _________________NAV_R2____________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________NAV_R3____________________        KC_PGUP, KC_HOME, KC_END,  KC_PGDN, _______

#define _________________LOWER_L1__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L2__________________        ________________NUMBER_LEFT________________
#define _________________LOWER_L3__________________        A(KC_F1), A(KC_F2), A(KC_F9), A(KC_F10), GAMING

#define _________________LOWER_R1__________________        _________________FUNC_RIGHT________________
#define _________________LOWER_R2__________________        ________________NUMBER_RIGHT_______________
#define _________________LOWER_R3__________________        KC_F11,  KC_F12,  _______, _______, _______

#define _________________RAISE_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L2__________________        _______, KC_LCBR, KC_LBRC, KC_LPRN, _______
#define _________________RAISE_L3__________________        _______, KC_RCBR, KC_RBRC, KC_RPRN, _______

#define _________________RAISE_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, _______, _______
#define _________________RAISE_R2__________________        KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY
#define _________________RAISE_R3__________________        _______, KC_MUTE, _______, _______, _______

#define _________________ADJUST_L1_________________        _______, _______, _______, RESET,   RSTROM
#define _________________ADJUST_L2_________________        _______, KC_SLCK, WINDOWS, MACOS,   _______
#define _________________ADJUST_L3_________________        ___________________BLANK___________________

#define _________________ADJUST_R1_________________        ___________________BLANK___________________
#define _________________ADJUST_R2_________________        ___________________BLANK___________________
#define _________________ADJUST_R3_________________        ___________________BLANK___________________



// clang-format on
