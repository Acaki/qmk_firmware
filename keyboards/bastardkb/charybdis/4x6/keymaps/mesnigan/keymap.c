#include QMK_KEYBOARD_H
#include "mesnigan.h"

// Automatically enable sniping-mode on the pointer layer.
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _LOWER

#define LAYOUT_charybdis_4x6_wrapper(...) LAYOUT_charybdis_4x6(__VA_ARGS__)

// clang-format off
#define LAYOUT_charybdis_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K31, K32, K33, K34, K35, K36 \
  ) \
  LAYOUT_charybdis_4x6_wrapper( \
      GAMING,  _________________FUNC_LEFT_________________,                                              _________________FUNC_RIGHT________________, KC_MUTE, \
      KC_DEL,  K01,    K02,    K03,    K04,    K05,                                                      K06,     K07,     K08,     K09,     K0A,     KC_EQL,  \
      KC_MINS, K11,    K12,    K13,    K14,    K15,                                                      K16,     K17,     K18,     K19,     K1A,     KC_QUOT, \
      KC_GRV,  K21,    K22,    K23,    K24,    K25,                                                      K26,     K27,     K28,     K29,     K2A,     KC_BSLS, \
                                       K31,    K32,    K33,                                              K34,     K35,     \
                                               DRGSCRL,SH_OS,                                            SH_OS  \
  )
/* Re-pass though to allow templates to be used */
#define LAYOUT_charybdis_base_wrapper(...)       LAYOUT_charybdis_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_MOD_DH] = LAYOUT_charybdis_base_wrapper(
      ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
      ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
      ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_GAMING] = LAYOUT_charybdis_4x6_wrapper(
      _______, ________________NUMBER_LEFT________________,                                       ________________NUMBER_RIGHT_______________, TD(SHADOWPLAY),
      KC_TAB,  _________________GAMING_L1_________________,                                       _________________GAMING_R1_________________, KC_DEL,
      KC_LSFT, _________________GAMING_L2_________________,                                       _________________GAMING_R2_________________, _______,
      _______, _________________GAMING_L3_________________,                                       _________________GAMING_R3_________________, KC_MINS,
                                KC_LCTL, KC_SPC,  LT(_LOWER, KC_ESC),                             MO(_RAISE), KC_ENT,
                                         KC_LALT, _______,                                        KC_BSPC
    ),

    [_GAMING_S] = LAYOUT_charybdis_4x6_wrapper(
      _______,  ________________NUMBER_LEFT_S______________,                                      ________________NUMBER_RIGHT_______________, TD(SHADOWPLAY),
      KC_GRV,   _________________GAMING_L1S________________,                                      _________________GAMING_R1_________________, KC_DEL,
      KC_G,     _________________GAMING_L2S________________,                                      _________________GAMING_R2_________________, _______,
      KC_B,     _________________GAMING_L3S________________,                                      _________________GAMING_R3_________________, KC_MINS,
                                KC_LCTL, KC_SPC,  LT(_LOWER, KC_ESC),                             MO(_RAISE), KC_ENT,
                                         KC_LALT, _______,                                        KC_BSPC
    ),

    [_MOUSE] = LAYOUT_charybdis_base_wrapper(
      _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______,
      ___________________BLANK___________________, ___________________BLANK___________________,
      ___________________BLANK___________________, ___________________BLANK___________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_ARROW] = LAYOUT_charybdis_base_wrapper(
      ___________________BLANK___________________, _________________ARROW_R1__________________,
      _______, KC_C,    KC_X,    KC_Z,    _______, _________________ARROW_R2__________________,
      _______, KC_T,    KC_S,    KC_R,    _______, ___________________BLANK___________________,
             KC_LCTL, KC_SPC,  LT(_LOWER, KC_ESC), _________________COMMON_RT_________________
    ),

    [_LOWER] = LAYOUT_charybdis_4x6_wrapper(
      _______, ________________NUMBER_RIGHT_______________,                                       _________________FUNC_RIGHT________________, _______,
      _______, _________________LOWER_L1__________________,                                       _________________LOWER_R1__________________, _______,
      KC_CAPS, _________________LOWER_L2__________________,                                       _________________LOWER_R2__________________, _______,
      _______, _________________LOWER_L3__________________,                                       _________________LOWER_R3__________________, _______,
                                 _______, _______, _______,                                       _______, _______,
                                          _______, _______,                                       _______
    ),

    [_LOWER_S] = LAYOUT_charybdis_4x6_wrapper(
      _______, ________________NUMBER_RIGHT_S_____________,                                       _________________FUNC_RIGHT________________, _______,
      _______, _________________FUNC_LEFT_S_______________,                                       _________________LOWER_R1__________________, _______,
      _______, _________________LOWER_L2__________________,                                       _________________LOWER_R2__________________, _______,
      _______, _________________LOWER_L3__________________,                                       _________________LOWER_R3__________________, _______,
                                 _______, _______, _______,                                       _______, _______, 
                                          _______, _______,                                       _______
    ),

    [_RAISE] = LAYOUT_charybdis_base_wrapper(
      _________________RAISE_L1__________________, _________________RAISE_R1__________________,
      _________________RAISE_L2__________________, _________________RAISE_R2__________________,
      _________________RAISE_L3__________________, _________________RAISE_R3__________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),    

    [_SYMBL] = LAYOUT_charybdis_base_wrapper(
      ___________________BLANK___________________, _________________SYMBL_R1__________________,
      ___________________BLANK___________________, _________________SYMBL_R2__________________,
      ___________________BLANK___________________, _________________SYMBL_R3__________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_FUNCL] = LAYOUT_charybdis_base_wrapper(
      _________________FUNCL_L1__________________, _________________FUNCL_R1__________________,
      _________________FUNCL_L2__________________, _________________FUNCL_R2__________________,
      _________________FUNCL_L3__________________, _________________FUNCL_R3__________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_ADJUST] = LAYOUT_charybdis_base_wrapper(
      _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,
      _________________ADJUST_L2_________________, _________________ADJUST_R2_________________,
      _______, S_D_MOD, DPI_MOD, _______, _______, _________________ADJUST_R3_________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),
};

bool is_pointing_device_initialized = false;

#ifdef POINTING_DEVICE_ENABLE
#ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_kb(layer_state_t state) {
    // Ensure that the pointing device is initialized or it will mess up with ROTATIONAL_TRANSFORM_ANGLE
    if (is_pointing_device_initialized) {
        charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    }
    return layer_state_set_user(state);
}
#endif  // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
    is_pointing_device_initialized = true;
}

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
