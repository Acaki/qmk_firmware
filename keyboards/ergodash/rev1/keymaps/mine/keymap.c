#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_4key(
            KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
            KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_MINS, KC_EQL, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, MO(1), KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TG(2),
            KC_LCTL, KC_APP, KC_LGUI, KC_LALT, KC_SPC, KC_LSFT, KC_LCTL, KC_RCTL, KC_RSFT, KC_BSPC, KC_RALT, C(KC_C), C(KC_V), KC_MPLY
	        ),
    [1] = LAYOUT_4key(
            _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11, KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, RESET,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP, KC_PGDN, KC_HOME, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______,
            _______, _______, _______, KC_CALC, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            ),
    [2] = LAYOUT_4key(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_UP, KC_BTN1, KC_MS_UP, KC_BTN2, KC_BTN4, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_BTN5, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
            ),

};
