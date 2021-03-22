#include "mesnigan.h"

static bool is_alt_set = false;
static bool is_ctrl_set = false;

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

void release_ctrl(void) {
    int kc  = KC_LCTL;
    bool is_ctrl_on = get_mods() & MOD_BIT(kc);
    if (is_ctrl_set && is_ctrl_on) {
        unregister_code(kc);
        is_ctrl_set = false;
    }
};

void register_ctrl(void) {
    int kc  = KC_LCTL;
    bool is_ctrl_on = get_mods() & MOD_BIT(kc);
    if (!is_ctrl_on) {
        register_code(kc);
        is_ctrl_set = true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            release_alt();
            release_ctrl();
            break;
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
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
}
#endif

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif
