#include QMK_KEYBOARD_H

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    DBLARROW,
    COPY,
    PASTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_60_calbatr0ss(
	        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
	        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
	        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
	        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, PASTE,
	        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(2), KC_BSPC, KC_RALT, MO(2), KC_RCTL, COPY
	        ),
    [1] = LAYOUT_60_calbatr0ss(
            KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
            KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, PASTE,
            KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(2), KC_BSPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
            ),
    [2] = LAYOUT_60_calbatr0ss(
            KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, RESET,
            KC_NO, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_NO, KC_NO, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_NO, KC_NO, KC_NO,
            KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_ENT, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, ARROW, DBLARROW, KC_NO, KC_MUTE, KC_MPRV, KC_MNXT,
            KC_NO, KC_NO, KC_NO, TG(1), KC_TRNS, KC_NO, KC_MPLY, KC_TRNS, KC_VOLD, KC_VOLU
            ),
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
        case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("c"));
            }
            break;
        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("v"));
            }
            break;
    }
    return true;
};