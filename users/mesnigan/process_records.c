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
    }
    return true;
}