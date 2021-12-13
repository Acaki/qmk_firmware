#include "mesnigan.h"
#include "features/caps_word.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
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
        case MOFFESC:
            if (record->event.pressed) {
                layer_off(_MOUSE);
                register_code(KC_ESC);
                unregister_code(KC_ESC);
            }
            return false;
        case SPAMRC:
            if (record->event.pressed) {
                if (spam_rc) {
                    spam_rc = false;
                    return false;
                }
                spam_rc = true;
                spam_timer = timer_read();
            }
            return false;
    }
    return process_record_keymap(keycode, record);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case THUMB_L2:
        case THUMB_L3:
        case THUMB_R2:
        case LT(_LOWER, KC_ESC):
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK_HOME_L4:
        case COLEMAK_HOME_R4:
            return TAPPING_TERM + 50;
        case COLEMAK_HOME_L2:
        case COLEMAK_HOME_R2:
            return TAPPING_TERM - 15;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK_HOME_L1:
        case COLEMAK_HOME_L2:
        case COLEMAK_HOME_L3:
        case COLEMAK_HOME_L4:
        case COLEMAK_HOME_R1:
        case COLEMAK_HOME_R2:
        case COLEMAK_HOME_R3:
        case COLEMAK_HOME_R4:
            return true;
        default:
            return false;
    }
}
