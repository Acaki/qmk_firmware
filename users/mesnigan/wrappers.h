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
#define LAYOUT_ergodox_wrapper(...)          LAYOUT_ergodox(__VA_ARGS__)
#define LAYOUT_ergodox_pretty_wrapper(...)   LAYOUT_ergodox_pretty(__VA_ARGS__)
#define KEYMAP_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_ortho_5x12_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

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

#define _________________QWERTY_L1_________________        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_TAB,  LALTKCZ, KC_X,    KC_C,    KC_V,    KC_B
#define _________________QWERTY_LT_________________                                   KC_LCTL, KC_SPC,  LOWER 

#define _________________GAMING_L1_________________        KC_TAB,  KC_T,    KC_Q,    KC_X,    KC_E,    KC_R
#define _________________GAMING_L2_________________        KC_LSFT, KC_G,    KC_A,    KC_W,    KC_D,    KC_F
#define _________________GAMING_L3_________________        KC_LCTL, KC_B,    KC_Z,    KC_S,    KC_C,    KC_V
#define _________________GAMING_LT_________________                                   KC_LALT, KC_SPC,  LOWER 

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  RALTSLH, KC_DEL
#define _________________QWERTY_RT_________________        RAISE,   KC_ENT,  KC_RCTL

#define ________________NUMBER_LEFT________________        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS
#define _________________FUNC_LEFT_________________        KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12

#define _________________MOUSE_R1__________________        _______, KC_WH_D, _______, KC_WH_U, KC_BTN4, _______
#define _________________MOUSE_R2__________________        _______, KC_MS_L, KC_MS_U, KC_MS_R, KC_BTN5, _______
#define _________________MOUSE_R3__________________        _______, KC_WH_L, KC_MS_D, KC_WH_R, _______, _______
#define _________________MOUSE_RT__________________        KC_BTN3, KC_BTN1, KC_BTN2

#define ___________________BLANK___________________        _______, _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        ________________NUMBER_LEFT________________
#define _________________LOWER_L2__________________        KC_LGUI, KC_6,    KC_7,    ASFT,    ATAB,    GAMING
#define _________________LOWER_L3__________________        _________________FUNC_LEFT_________________

#define _________________LOWER_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________LOWER_R2__________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______
#define _________________LOWER_R3__________________        _________________FUNC_RIGHT________________

#define _________________RAISE_L1__________________        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________RAISE_L2__________________        KC_TILD, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_GRV
#define _________________RAISE_L3__________________        _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_MINS, KC_TILD

#define _________________RAISE_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______
#define _________________RAISE_R2__________________        KC_BSLS, KC_QUOT, KC_DQT,  KC_EQL,  KC_PLUS, _______
#define _________________RAISE_R3__________________        KC_PIPE, _______, _______, _______, _______, _______

#define _________________ADJUST_L1_________________        RSTROM,  _______, _______, KC_HOME, RESET,  _______
#define _________________ADJUST_L2_________________        _______, _______, KC_PGUP, KC_END,  KC_PGDN, _______
#define _________________ADJUST_L3_________________        ___________________BLANK___________________

#define _________________ADJUST_R1_________________        ___________________BLANK___________________
#define _________________ADJUST_R2_________________        KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _______
#define _________________ADJUST_R3_________________        ___________________BLANK___________________

// clang-format on
