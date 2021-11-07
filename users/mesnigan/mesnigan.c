#include "mesnigan.h"

bool spam_rc;
uint16_t spam_timer = false;
uint16_t spam_interval = 100;

static bool is_ctrl_set = false;
static bool is_alt_set = false;

void release_ctrl() {
    bool is_ctrl_on = get_mods() & MOD_BIT(KC_LCTL);
    if (is_ctrl_set && is_ctrl_on) {
        unregister_code(KC_LCTL);
        is_ctrl_set = false;
    }
};

void register_ctrl() {
    bool is_ctrl_on = get_mods() & MOD_BIT(KC_LCTL);
    if (!is_ctrl_on) {
        register_code(KC_LCTL);
        is_ctrl_set = true;
    }
}

void release_alt() {
    bool is_alt_on = get_mods() & MOD_BIT(KC_LALT);
    if (is_alt_set && is_alt_on) {
        unregister_code(KC_LALT);
        is_alt_set = false;
    }
};

void register_alt() {
    bool is_alt_on = get_mods() & MOD_BIT(KC_LALT);
    if (!is_alt_on) {
        register_code(KC_LALT);
        is_alt_set = true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            release_ctrl();
            release_alt();
            break;
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

__attribute__((weak)) void matrix_scan_keymap(void) {}
void matrix_scan_user(void) {
    if (spam_rc && timer_elapsed(spam_timer) >= spam_interval) {
        spam_timer = timer_read();
        tap_code(KC_BTN2);
    }
    matrix_scan_keymap();
}
