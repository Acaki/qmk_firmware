#include "mesnigan.h"

bool spam_lc;
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
        case _QWERTY ... _MOUSE:
            release_ctrl();
            release_alt();
            break;
    }

    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

__attribute__((weak)) void matrix_scan_keymap(void) {}
void matrix_scan_user(void) {
    if (spam_lc && timer_elapsed(spam_timer) >= spam_interval) {
        spam_timer = timer_read();
        tap_code(KC_BTN1);
    }
    else if (spam_rc && timer_elapsed(spam_timer) >= spam_interval) {
        spam_timer = timer_read();
        tap_code(KC_BTN2);
    }
    matrix_scan_keymap();
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
void dance_gaming_finished(qk_tap_dance_state_t *state, void *user_data) {
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

void dance_shadowplay_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_F1)));
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_LALT(SS_TAP(X_F9)));
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_F10)));
        default:
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = TD_NONE;
}

void sentence_end(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {

        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LSHIFT));

            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [GAMING_TD] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_gaming_finished, ql_reset, 200),
    [SHADOWPLAY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_shadowplay_finished, ql_reset, 200),
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, ql_reset, NULL)
};
