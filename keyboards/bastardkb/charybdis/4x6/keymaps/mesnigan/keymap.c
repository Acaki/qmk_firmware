#include QMK_KEYBOARD_H
#include "mesnigan.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER
#include "timer.h"
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER

enum charybdis_keymap_keycodes {
#ifdef VIA_ENABLE
  USER_RESET = USER00,
#else
  USER_RESET = SAFE_RANGE,
#endif  // VIA_ENABLE
  POINTER_DEFAULT_DPI_FORWARD,
  POINTER_DEFAULT_DPI_REVERSE,
  POINTER_SNIPING_DPI_FORWARD,
  POINTER_SNIPING_DPI_REVERSE,
  SNIPING_MODE,
  SNIPING_MODE_TOGGLE,
  DRAGSCROLL_MODE,
  DRAGSCROLL_MODE_TOGGLE,
  KEYMAP_SAFE_RANGE,
};

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER
static uint16_t auto_pointer_layer_timer = 0;

#ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER

#define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#define SNIPING SNIPING_MODE
#define SNP_TOG SNIPING_MODE_TOGGLE
#define DRGSCRL DRAGSCROLL_MODE
#define DRG_TOG DRAGSCROLL_MODE_TOGGLE

/** Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _LOWER

#define LAYOUT_split_4x6_5_wrapper(...) LAYOUT_split_4x6_5(__VA_ARGS__)

// clang-format off
#define LAYOUT_charybdis_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K31, K32, K33, K34, K35, K36 \
  ) \
  LAYOUT_split_4x6_5_wrapper( \
      GAMING,  ________________NUMBER_LEFT________________,                                              ________________NUMBER_RIGHT_______________, KC_MPLY, \
      KC_TAB,  K01,    K02,    K03,    K04,    K05,                                                      K06,     K07,     K08,     K09,     K0A,     KC_EQL,  \
      KC_MINS, K11,    K12,    K13,    K14,    K15,                                                      K16,     K17,     K18,     K19,     K1A,     KC_QUOT, \
      KC_GRV,  K21,    K22,    K23,    K24,    K25,                                                      K26,     K27,     K28,     K29,     K2A,     KC_BSLS, \
                                       K31,    K32,    K33,                                              K34,     K35,     K36,     \
                                               DRGSCRL,KC_LOCK,                                          _______, DRGSCRL  \
  )
/* Re-pass though to allow templates to be used */
#define LAYOUT_charybdis_base_wrapper(...)       LAYOUT_charybdis_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_QWERTY] = LAYOUT_charybdis_base_wrapper(
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
        _________________QWERTY_LT_________________, _________________QWERTY_RT_________________
     ),

    [_GAMING] = LAYOUT_split_4x6_5_wrapper(
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, TD(SHADOWPLAY),
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        KC_LSFT, _________________GAMING_L2_________________,                                       _________________GAMING_R2_________________, _______,
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, KC_MINS,
                                  KC_LCTL, KC_SPC,  LT(_LOWER, KC_ESC),                             KC_BSPC, _______, _______,
                                           KC_LALT, _______,                                        _______, KC_DEL
    ),

    [_GAMING_S] = LAYOUT_split_4x6_5_wrapper(
        _______,  ___________________BLANK___________________,                                      ___________________BLANK___________________, TD(SHADOWPLAY),
        _______,  _________________GAMING_L1S________________,                                      ___________________BLANK___________________, _______,
        KC_LSFT,  _________________GAMING_L2S________________,                                      ___________________BLANK___________________, _______,
        _______,  _________________GAMING_L3S________________,                                      ___________________BLANK___________________, KC_MINS,
                                  KC_LCTL, KC_SPC,  LT(_LOWER, KC_ESC),                             KC_BSPC, _______, _______,
                                           KC_LALT, _______,                                        _______, KC_DEL
    ),

    [_MOUSE] = LAYOUT_split_4x6_5_wrapper(
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN5,                                       KC_BTN5, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, _______,
                                   _______, _______, MOUSE,                                         _______, _______, _______,
                                            _______, _______,                                       _______, _______
    ),

    [_LOWER] = LAYOUT_split_4x6_5_wrapper(
        KC_F11,  _________________FUNC_LEFT_________________,                                       _________________FUNC_RIGHT________________, KC_F12,
        _______, ___________________BLANK___________________,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
        _______, _________________LOWER_L2__________________,                                       _________________LOWER_R2__________________, KC_DQT,
        _______, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN5,                                       _________________LOWER_R3__________________, KC_PIPE,
                                   _______, _______, _______,                                       _______, _______, _______,
                                            _______, _______,                                       _______, _______
    ),

    [_RAISE] = LAYOUT_split_4x6_5_wrapper(
        KC_F11,  _________________FUNC_LEFT_________________,                                       _________________FUNC_RIGHT________________, KC_F12,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                       ___________________BLANK___________________, _______,
        KC_UNDS, _________________RAISE_L2__________________,                                       _________________RAISE_R2__________________, _______,
        KC_TILD, _________________RAISE_L3__________________,                                       _________________RAISE_R3__________________, _______,
                                   _______, _______, _______,                                       _______, _______, _______,
                                            _______, _______,                                       _______, _______
    ),

    [_ADJUST] = LAYOUT_charybdis_base_wrapper(
        _________________ADJUST_L1_________________,          _________________ADJUST_R1_________________,
        _______, S_D_MOD, DPI_MOD, _______, _______,          _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________,          _________________ADJUST_R3_________________,
        _________________QWERTY_LT_________________,          _________________QWERTY_RT_________________
    ),
};

/** Whether SHIFT mod is enabled. */
static bool _has_shift_mod(void) {
#ifdef NO_ACTION_ONESHOT
  return mod_config(get_mods()) & MOD_MASK_SHIFT;
#else
  return mod_config(get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
}

#ifdef POINTING_DEVICE_ENABLE
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case KC_MS_UP ... KC_MS_WH_RIGHT:
        auto_pointer_layer_timer = timer_read();
        break;
    case POINTER_DEFAULT_DPI_FORWARD:
      if (record->event.pressed) {
        // Step backward if shifted, forward otherwise.
        charybdis_cycle_pointer_default_dpi(/* forward= */ !_has_shift_mod());
      }
      break;
    case POINTER_DEFAULT_DPI_REVERSE:
      if (record->event.pressed) {
        // Step forward if shifted, backward otherwise.
        charybdis_cycle_pointer_default_dpi(/* forward= */ _has_shift_mod());
      }
      break;
    case POINTER_SNIPING_DPI_FORWARD:
      if (record->event.pressed) {
        // Step backward if shifted, forward otherwise.
        charybdis_cycle_pointer_sniping_dpi(/* forward= */ !_has_shift_mod());
      }
      break;
    case POINTER_SNIPING_DPI_REVERSE:
      if (record->event.pressed) {
        // Step forward if shifted, backward otherwise.
        charybdis_cycle_pointer_sniping_dpi(/* forward= */ _has_shift_mod());
      }
      break;
    case SNIPING_MODE:
      charybdis_set_pointer_sniping_enabled(record->event.pressed);
      break;
    case SNIPING_MODE_TOGGLE:
      if (record->event.pressed) {
        charybdis_set_pointer_sniping_enabled(
            !charybdis_get_pointer_sniping_enabled());
      }
      break;
    case DRAGSCROLL_MODE:
      charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
      break;
    case DRAGSCROLL_MODE_TOGGLE:
      if (record->event.pressed) {
        charybdis_set_pointer_dragscroll_enabled(
            !charybdis_get_pointer_dragscroll_enabled());
      }
      break;
  }
  return true;
}

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER
void process_mouse_report_user(report_mouse_t* mouse_report) {
  if (abs(mouse_report->x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD ||
      abs(mouse_report->y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
    if (auto_pointer_layer_timer == 0) {
      layer_on(_MOUSE);
#ifdef RGB_MATRIX_ENABLE
      rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
      rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#endif  // RGB_MATRIX_ENABLE
    }
    auto_pointer_layer_timer = timer_read();
  }
}

void matrix_scan_kb(void) {
  if (auto_pointer_layer_timer != 0 &&
      TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >=
          CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
    auto_pointer_layer_timer = 0;
    layer_off(_MOUSE);
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
#endif  // RGB_MATRIX_ENABLE
  }
  matrix_scan_user();
}
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER

#ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_kb(layer_state_t state) {
  state = layer_state_set_user(state);
  charybdis_set_pointer_sniping_enabled(
      layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
  return state;
}
#endif  // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif  // POINTING_DEVICE_ENABLE
