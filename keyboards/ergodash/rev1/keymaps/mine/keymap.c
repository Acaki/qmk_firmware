#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_4key_2u_inner(
            KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
            KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_QUOT, KC_SLSH, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, OSL(1), OSL(1), KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, MO(1),
            KC_LCTL, KC_LGUI, KC_APP, KC_LALT, OSM(MOD_LSFT), KC_SPC, KC_LCTL, KC_RCTL, KC_BSPC, OSM(MOD_RSFT), KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
	        ),
    [1] = LAYOUT_4key_2u_inner(
            _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11, KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, RESET,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_UP, KC_BTN1, KC_MS_UP, KC_BTN2, KC_BTN4, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_BTN5, _______,
            _______, _______, _______, KC_CALC, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
            ),

};
