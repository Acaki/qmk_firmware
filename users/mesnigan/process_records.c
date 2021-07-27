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
        case ATAB:
            if (record->event.pressed) {
                register_mod(KC_LALT);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            return false;
        case CTAB:
            if (record->event.pressed) {
                register_mod(KC_LCTL);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            return false;
        case WINDOWS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SLCK)SS_TAP(X_SLCK)"1");
            }
            break;
        case MACOS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SLCK)SS_TAP(X_SLCK)"2");
            }
            break;
    }
    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB_L2:
            // Immediately select the hold action when another key is pressed.
            return true;
        case THUMB_R2:
            return true;
        case THUMB_R3:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_L4:
            return TAPPING_TERM + 50;
        case HOME_R4:
            return TAPPING_TERM + 50;
        case HOME_L2:
            return TAPPING_TERM - 15;
        case HOME_R2:
            return TAPPING_TERM - 15;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_L1:
            return true;
        case HOME_L2:
            return true;
        case HOME_L3:
            return true;
        case HOME_L4:
            return true;
        case HOME_R1:
            return true;
        case HOME_R2:
            return true;
        case HOME_R3:
            return true;
        case HOME_R4:
            return true;
        default:
            return false;
    }
}
