#include "mesnigan.h"

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

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            if (layer_state_is(_QWERTY)) {
                layer_on(_GAMING);
            } else {
                layer_clear();
            }
            break;
        case TD_SINGLE_HOLD:
            if (layer_state_is(_GAMING_S)) {
                layer_off(_GAMING_S);
            } else {
                layer_on(_GAMING_S);
            }
            break;
        case TD_DOUBLE_TAP:
            break;
        default:
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [GAMING_TD] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 200)
};

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
