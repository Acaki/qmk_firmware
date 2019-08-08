#include QMK_KEYBOARD_H

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    DBLARROW
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_b_mine(
	        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
	        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
	        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
	        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(1),
	        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, OSM(MOD_RCTL), MO(1), KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
	        ),
    [1] = LAYOUT_60_b_mine(
	        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, RESET,
	        KC_HOME, KC_PGUP, KC_UP, KC_PGDN, _______, DBLARROW, _______, _______, _______, _______, _______, _______, _______, _______,
	        KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC, ARROW, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, _______, _______,
	        _______, _______, KC_CALC, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______,
	        _______, _______, _______, KC_ENT, TG(2), _______, MO(3), KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
	        ),
    [2] = LAYOUT_60_b_mine(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_UP, KC_BTN2, KC_BTN4, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_BTN5, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, KC_MS_WH_DOWN, KC_MS_WH_UP, _______, _______, _______, _______,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_60_b_mine(
	        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	        _______, RGB_MOD, RGB_RMOD, RGB_VAI, RGB_VAD, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______,
	        _______, _______, RGB_HUI, RGB_HUD, RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______,
	        _______, _______, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;
        case DBLARROW:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
    }
    return true;
};
