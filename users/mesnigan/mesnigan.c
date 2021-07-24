#include "mesnigan.h"

static bool is_mod_set = false;

void release_mod(int mod) {
    bool is_mod_on = get_mods() & MOD_BIT(mod);
    if (is_mod_set && is_mod_on) {
        unregister_code(mod);
        is_mod_set = false;
    }
};

void register_mod(int mod) {
    bool is_mod_on = get_mods() & MOD_BIT(mod);
    if (!is_mod_on) {
        register_code(mod);
        is_mod_set = true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            release_mod(KC_LALT);
            release_mod(KC_LCTL);
            break;
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_MPRV);
        } else {
            tap_code(KC_MNXT);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}
#endif

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif
