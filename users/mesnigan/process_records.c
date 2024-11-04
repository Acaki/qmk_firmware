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
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        case CTAB:
            if (record->event.pressed) {
                register_ctrl();
                register_code(KC_TAB);
            } else {
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
        case KVMPC1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCRL)SS_TAP(X_SCRL)"1");
            }
            return false;
        case KVMPC2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCRL)SS_TAP(X_SCRL)"2");
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
        case THUMB_R3:
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
            return TAPPING_TERM + 25;
        case COLEMAK_HOME_L2:
        case COLEMAK_HOME_R2:
            return TAPPING_TERM - 15;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK_HOME_L1:
        case COLEMAK_HOME_L2:
        case COLEMAK_HOME_L3:
        case COLEMAK_HOME_L4:
        case COLEMAK_HOME_R1:
        case COLEMAK_HOME_R2:
        case COLEMAK_HOME_R3:
        case COLEMAK_HOME_R4:
            return 75;
        default:
            return QUICK_TAP_TERM;
    }
}
