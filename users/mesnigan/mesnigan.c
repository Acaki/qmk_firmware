#include "mesnigan.h"

static bool is_alt_set = false;

void release_alt(void) {
    int kc  = KC_LALT;
    int mod = MOD_LALT;
    if (default_layer_state > 1) {
        kc  = KC_LGUI;
        mod = MOD_LGUI;
    }
    bool is_alt_on = get_mods() & MOD_BIT(kc);
    if (is_alt_set && is_alt_on) {
        unregister_mods(mod);
        is_alt_set = false;
    }
};

void register_alt(void) {
    int kc  = KC_LALT;
    int mod = MOD_LALT;
    if (default_layer_state > 1) {
        kc  = KC_LGUI;
        mod = MOD_LGUI;
    }
    bool is_alt_on = get_mods() & MOD_BIT(kc);
    if (!is_alt_on) {
        register_mods(mod);
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