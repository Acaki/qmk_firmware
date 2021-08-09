#include "mesnigan.h"

bool spam_kd;
bool spam_lc;
uint16_t spam_timer = false;
uint16_t spam_interval = 200;
uint16_t spam_lc_interval = 100;

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
        case WINDOWS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SLCK)SS_TAP(X_SLCK)"1");
            }
            break;
        case CCLICK:
            if (record->event.pressed) {
                if (spam_lc) {
                    spam_lc = false;
                    return false;
                }
                spam_lc = true;
                spam_timer = timer_read();
            }
            return false;
        case FARM:
            if (record->event.pressed) {
                spam_kd = true;
                spam_timer = timer_read();
            } else {
                spam_kd = false;
            }
            return false;
        case FIRE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_D)SS_DELAY(50)SS_TAP(X_D)SS_DELAY(50)SS_TAP(X_I)SS_DELAY(50)SS_TAP(X_I));
            }
            return false;
        case MACOS:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SLCK)SS_TAP(X_SLCK)"2");
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
  if (spam_kd && timer_elapsed(spam_timer) >= spam_interval) {
      spam_timer = timer_read();
      SEND_STRING(SS_DOWN(X_K)SS_DELAY(50)SS_DOWN(X_D)SS_DELAY(50)SS_UP(X_K)SS_UP(X_D));
  }
  else if (spam_lc && timer_elapsed(spam_timer) >= spam_lc_interval) {
      spam_timer = timer_read();
      tap_code(KC_BTN1);
  }
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
        case LT(_LOWER, KC_ESC):
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
