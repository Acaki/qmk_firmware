#include "mesnigan.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ATAB:
            if (record->event.pressed) {
                register_alt();
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            return false;
        case CTAB:
            if (record->event.pressed) {
                register_ctrl();
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            return false;
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
