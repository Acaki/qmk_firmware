#include QMK_KEYBOARD_H
#include "mesnigan.h"

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#include "timer.h"
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _LOWER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif  // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE



#define LAYOUT_charybdis_4x6_wrapper(...) LAYOUT_charybdis_4x6(__VA_ARGS__)

// clang-format off
#define LAYOUT_charybdis_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K31, K32, K33, K34, K35, K36 \
  ) \
  LAYOUT_charybdis_4x6_wrapper( \
      GAMING,  ________________NUMBER_LEFT________________,                                              ________________NUMBER_RIGHT_______________, KC_MPLY, \
      KC_DEL,  K01,    K02,    K03,    K04,    K05,                                                      K06,     K07,     K08,     K09,     K0A,     KC_EQL,  \
      KC_MINS, K11,    K12,    K13,    K14,    K15,                                                      K16,     K17,     K18,     K19,     K1A,     KC_QUOT, \
      KC_GRV,  K21,    K22,    K23,    K24,    K25,                                                      K26,     K27,     K28,     K29,     K2A,     KC_BSLS, \
                                       K31,    K32,    K33,                                              K34,     K35,     \
                                               DRGSCRL,SH_TT,                                            SH_TT  \
  )
/* Re-pass though to allow templates to be used */
#define LAYOUT_charybdis_base_wrapper(...)       LAYOUT_charybdis_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_charybdis_base_wrapper(
      _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
      _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
      _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_COLEMAK_MOD_DH] = LAYOUT_charybdis_base_wrapper(
      ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
      ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
      ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_GAMING] =LAYOUT_charybdis_4x6_wrapper(
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, TD(SHADOWPLAY),
        KC_TAB,  _________________QWERTY_L1_________________,                                       _________________QWERTY_R1_________________, KC_DEL,
        KC_LSFT, _________________GAMING_L2_________________,                                       _________________GAMING_R2_________________, _______,
        _______, _________________QWERTY_L3_________________,                                       _________________QWERTY_R3_________________, KC_MINS,
                                  KC_LCTL, KC_SPC,  LT(_LOWER, KC_ESC),                             KC_BSPC, _______,
                                           KC_LALT, _______,                                        _______
    ),

    [_GAMING_S]LAYOUT_charybdis_4x6_wrapper(
        _______,  ___________________BLANK___________________,                                      ___________________BLANK___________________, TD(SHADOWPLAY),
        KC_TAB,   _________________GAMING_L1S________________,                                      _________________QWERTY_R1_________________, KC_DEL,
        KC_LSFT,  _________________GAMING_L2S________________,                                      _________________GAMING_R2_________________, _______,
        _______,  _________________GAMING_L3S________________,                                      _________________QWERTY_L3_________________, KC_MINS,
                                  KC_LCTL, KC_SPC,  LT(_LOWER, KC_ESC),                             KC_BSPC, _______,
                                           KC_LALT, _______,                                        _______
    ),

    [_MOUSE] = LAYOUT_charybdis_4x6_wrapper(
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______,                                       _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______,
                                   _______, _______, _______,                                       _______, _______,
                                            _______, _______,                                       _______
    ),

    [_LOWER] = LAYOUT_charybdis_4x6_wrapper(
        _______, ________________NUMBER_RIGHT_______________,                                       ___________________BLANK___________________, _______,
        _______, _________________LOWER_L1__________________,                                       _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________,                                       _________________LOWER_R2__________________, _______,
        _______, KC_BTN4, KC_BTN3, KC_BTN2, KC_BTN1, KC_BTN5,                                       _________________LOWER_R3__________________, _______,
                                   _______, _______, _______,                                       _______, _______,
                                            _______, _______,                                       _______
    ),

    [_RAISE] = LAYOUT_charybdis_4x6_wrapper(
        _______, ___________________BLANK___________________,                                       ___________________BLANK___________________, _______,
        _______, _________________RAISE_L1__________________,                                       _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________,                                       _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________,                                       _________________RAISE_R3__________________, _______,
                                   _______, _______, _______,                                       _______, _______,
                                            _______, _______,                                       _______
    ),    

    [_FUNCL] = LAYOUT_charybdis_base_wrapper(
      ___________________BLANK___________________, _________________FUNCL_R1__________________,
      ___________________BLANK___________________, _________________FUNCL_R2__________________,
      ___________________BLANK___________________, _________________FUNCL_R3__________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_NUMBL] = LAYOUT_charybdis_base_wrapper(
      _________________NUMBL_L1__________________, ___________________BLANK___________________,
      _________________NUMBL_L2__________________, ___________________BLANK___________________,
      _________________NUMBL_L3__________________, ___________________BLANK___________________,
      _________________NUMBL_LT__________________, _________________COMMON_RT_________________
    ),

    [_ADJUST] = LAYOUT_charybdis_base_wrapper(
        _________________ADJUST_L1_________________,          _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________,          _________________ADJUST_R2_________________,
        _______, S_D_MOD, DPI_MOD, _______, _______,          _________________ADJUST_R3_________________,
        _________________COMMON_LT_________________,          _________________COMMON_RT_________________
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
    case QWERTY_HOME_L1:
    case QWERTY_HOME_L2:
    case QWERTY_HOME_L3:
    case QWERTY_HOME_L4:
    case QWERTY_HOME_R1:
    case QWERTY_HOME_R2:
    case QWERTY_HOME_R3:
    case QWERTY_HOME_R4:
    case COLEMAK_HOME_L1:
    case COLEMAK_HOME_L2:
    case COLEMAK_HOME_L3:
    case COLEMAK_HOME_R1:
    case COLEMAK_HOME_R2:
    case COLEMAK_HOME_R3:
    case COLEMAK_HOME_R4:
      if (layer_state_is(_MOUSE)) {
        auto_pointer_layer_timer = 0;
        layer_off(_MOUSE);
      }
      break;
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD ||
      abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
    if (auto_pointer_layer_timer == 0) {
      layer_on(_MOUSE);
#ifdef RGB_MATRIX_ENABLE
      rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
      rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#endif  // RGB_MATRIX_ENABLE
    }
    auto_pointer_layer_timer = timer_read();
  }
  return mouse_report;
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

#ifdef SWAP_HANDS_ENABLE
// clang-format off
__attribute__ ((weak)) const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5}},
    {{0,6}, {1,6}, {2,6}, {3,6}, {4,6}, {5,6}},
    {{0,7}, {1,7}, {2,7}, {3,7}, {4,7}, {5,7}},
    {{0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}},
    {{0,9}, {1,9}, {5,9}, {3,4}, {3,9}, {2,9}},
    /* Right hand, matrix positions */
    {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}},
    {{0,1}, {1,1}, {2,1}, {3,1}, {4,1}, {5,1}},
    {{0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}},
    {{0,3}, {1,3}, {2,3}, {3,3}, {4,3}, {5,3}},
    {{0,4}, {1,4}, {2,4}, {4,4}, {3,4}, {2,4}},
};
// clang-format on
#endif