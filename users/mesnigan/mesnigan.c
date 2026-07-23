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

#ifdef CHORDAL_HOLD
// Per-chord customization for Chordal Hold.
// Returning true forces the tap-hold key to settle as held (modifier/layer),
// bypassing the default "opposite hands" rule.
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        // Thumb layer taps: always trigger the layer hold, regardless of which
        // hand the other key is on, so layer access is reliable.
        case THUMB_L2:  // LT(_LOWER, KC_SPC)
        case THUMB_L3:  // LT(_SYMBL, KC_TAB)
        case THUMB_R2:  // LT(_RAISE, KC_ENT)
        case THUMB_R3:  // LT(_FUNCL, KC_ESC)
        // Gaming layer taps: same reliable layer hold in the gaming layers.
        case LT(_LOWER, KC_ESC):
        case LT(_LOWER_S, KC_ESC):
            return true;

        // Left-handed Ctrl+C / Ctrl+X / Ctrl+V (hold T = Left Ctrl).
        // Works on both macOS and Windows (Ctrl is unaffected by the swap).
        case COLEMAK_HOME_L1:  // LCTL_T(KC_T)
            if (other_keycode == KC_C || other_keycode == KC_X || other_keycode == KC_V) {
                return true;
            }
            break;

        // macOS one-handed Cmd+C / Cmd+X / Cmd+V (hold R = Left Alt,
        // which macOS interprets as Command after the Cmd<->Opt swap).
        case COLEMAK_HOME_L3:  // LALT_T(KC_R)
            if (other_keycode == KC_C || other_keycode == KC_X || other_keycode == KC_V) {
                return true;
            }
            break;

        // Windows one-handed Win+V clipboard history (hold A = Left Gui,
        // which is Win on Windows as-is).
        case COLEMAK_HOME_L4:  // LGUI_T(KC_A)
            if (other_keycode == KC_V) {
                return true;
            }
            break;
    }

    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _COLEMAK_MOD_DH ... _MOUSE:
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
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void dance_gaming_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            if (layer_state_is(_COLEMAK_MOD_DH)) {
                layer_on(_GAMING_S);
            } else {
                layer_clear();
            }
            break;
        case TD_SINGLE_HOLD:
            if (layer_state_is(_GAMING)) {
                layer_off(_GAMING);
            } else {
                layer_on(_GAMING);
            }
            break;
        case TD_DOUBLE_TAP:
            if (layer_state_is(_ARROW)) {
                layer_off(_ARROW);
            } else {
                layer_on(_ARROW);
            }
            break;
        default:
            break;
    }
}

void dance_shadowplay_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_F1)));
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_LALT(SS_TAP(X_F9)));
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_F10)));
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [GAMING_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_gaming_finished, ql_reset),
    [SHADOWPLAY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_shadowplay_finished, ql_reset)
};