#include "mesnigan.h"

static bool is_alt_set = false;

void release_alt(void) {
    int kc  = KC_LALT;
    if (default_layer_state > 1) {
        kc  = KC_LGUI;
    }
    bool is_alt_on = get_mods() & MOD_BIT(kc);
    if (is_alt_set && is_alt_on) {
        unregister_code(kc);
        is_alt_set = false;
    }
};

void register_alt(void) {
    int kc  = KC_LALT;
    if (default_layer_state > 1) {
        kc  = KC_LGUI;
    }
    bool is_alt_on = get_mods() & MOD_BIT(kc);
    if (!is_alt_on) {
        register_code(kc);
        is_alt_set = true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            release_alt();
            break;
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            if (default_layer_state > 1) {
                unregister_code(KC_LGUI);
            } else {
                unregister_code(KC_LALT);
            }
            is_alt_tab_active = false;
        }
    }
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                if (default_layer_state > 1) {
                    register_code(KC_LGUI);
                } else {
                    register_code(KC_LALT);
                }
            }
            alt_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
        } else {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                if (default_layer_state > 1) {
                    register_code(KC_LGUI);
                } else {
                    register_code(KC_LALT);
                }
            }
            alt_tab_timer = timer_read();
            tap_code(KC_TAB);
        }
    } else if (index == 1) { /* Second encoder */
        switch (get_highest_layer(layer_state)) {
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_MPRV);
                } else {
                    tap_code(KC_MNXT);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
        }
    }
}
#endif
