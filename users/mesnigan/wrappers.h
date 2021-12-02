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
#define _________________QWERTY_L2_________________        QWERTY_HOME_L4, QWERTY_HOME_L3, QWERTY_HOME_L2, QWERTY_HOME_L1, KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define _________________COMMON_LT_________________                          THUMB_L1, THUMB_L2, THUMB_L3

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    QWERTY_HOME_R1, QWERTY_HOME_R2, QWERTY_HOME_R3, QWERTY_HOME_R4
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH
#define _________________COMMON_RT_________________        THUMB_R3, THUMB_R2, THUMB_R1

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       COLEMAK_HOME_L4, COLEMAK_HOME_L3, COLEMAK_HOME_L2, COLEMAK_HOME_L1, KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M, COLEMAK_HOME_R1, COLEMAK_HOME_R2, COLEMAK_HOME_R3, COLEMAK_HOME_R4
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________GAMING_L1S________________        KC_T,    KC_Q,    KC_X,    KC_E,    KC_R
#define _________________GAMING_L2S________________        KC_G,    KC_A,    KC_W,    KC_D,    KC_F
#define _________________GAMING_L2_________________        KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _________________GAMING_L3S________________        KC_B,    KC_Z,    KC_S,    KC_C,    KC_V
#define _________________GAMING_R2_________________        KC_M,    KC_N,    KC_E,    KC_I,    KC_O

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

#define _________________LOWER_R1__________________        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP
#define _________________LOWER_R2__________________        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#define _________________LOWER_R3__________________        KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE

#define _________________RAISE_L1__________________        KC_EXLM, KC_AT  , KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L2__________________        KC_CIRC, KC_LCBR, KC_LBRC, KC_LPRN, KC_ASTR
#define _________________RAISE_L3__________________        KC_AMPR, KC_RCBR, KC_RBRC, KC_RPRN, _______

#define _________________RAISE_R1__________________        _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP
#define _________________RAISE_R2__________________        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#define _________________RAISE_R3__________________        KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE

#define _________________FUNCL_R1__________________        KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______
#define _________________FUNCL_R2__________________        KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______
#define _________________FUNCL_R3__________________        KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______

#define _________________ADJUST_L1_________________        _______, _______, _______, RESET,   _______
#define _________________ADJUST_L2_________________        _______, _______, COLEMAK, QWERTY,  _______
#define _________________ADJUST_L3_________________        ___________________BLANK___________________

#define _________________ADJUST_R1_________________        _______, _______, _______, _______, KC_PSCR
#define _________________ADJUST_R2_________________        _______, SPAMLC,  SPAMRC,  _______, _______
#define _________________ADJUST_R3_________________        ___________________BLANK___________________



// clang-format on
