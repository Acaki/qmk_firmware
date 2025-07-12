/*
Copyright 2017 Christopher Courtney <drashna@live.com> @drashna

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include QMK_KEYBOARD_H

#include "wrappers.h"
#include "process_records.h"

/* Define layer names */
enum userspace_layers { _COLEMAK_MOD_DH = 0, _GAMING, _GAMING_S, _MOUSE, _ARROW, _LOWER, _LOWER_S, _RAISE, _SYMBL, _FUNCL, _ADJUST };

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    GAMING_TD,
    SHADOWPLAY
};

td_state_t cur_dance(tap_dance_state_t *state);
void dance_gaming_finished(tap_dance_state_t *state, void *user_data);
void dance_shadowplay_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);


void register_ctrl(void);
void register_alt(void);
void release_ctrl(void);
void release_alt(void);
void matrix_scan_keymap(void);

bool spam_lc;
bool spam_rc;
uint16_t spam_timer;
uint16_t spam_interval;
