#include "mesnigan.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        case ASFT:
            if (record->event.pressed) {
                register_alt();
                register_mods(MOD_LSFT);
            } else {
                unregister_mods(MOD_LSFT);
            }
            return false;
        case ATAB_ONE:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    if (default_layer_state > 1) {
                        register_code(KC_LGUI);
                    } else {
                        register_code(KC_LALT);
                    }
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        case WINDOWS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case MACOS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY_MAC);
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