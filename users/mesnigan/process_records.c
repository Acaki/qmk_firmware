#include "mesnigan.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    if (record->event.pressed) {
        uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
    }
#endif
    switch (keycode) {
        case RSTROM:
            eeconfig_init();
            return false;
        case TOG_IME:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_LOWER, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        case LT(_RAISE, KC_ENT):
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 150;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 150;
        case LSFT_T(KC_D):
            return TAPPING_TERM - 25;
        case RSFT_T(KC_K):
            return TAPPING_TERM - 25;
        default:
            return TAPPING_TERM;
    }
}
