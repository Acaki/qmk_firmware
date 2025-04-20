#include "mesnigan.h"

// clang-format off
#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
              K31, K32, K33, K34, K35, K36 \
  ) \
  LAYOUT_wrapper( \
      KC_DEL,  K01,     K02,     K03,     K04,     K05,                                             K06,     K07,     K08,     K09,     K0A,     KC_EQL, \
      KC_MINS, K11,     K12,     K13,     K14,     K15,                                             K16,     K17,     K18,     K19,     K1A,     KC_QUOT, \
      KC_GRV,  K21,     K22,     K23,     K24,     K25,                                             K26,     K27,     K28,     K29,     K2A,     KC_BSLS, \
                                          K31,     K32,     K33,                          K34,      K35,     K36 \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_crkbd_base_wrapper(...)       LAYOUT_crkbd_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_COLEMAK_MOD_DH] = LAYOUT_crkbd_base_wrapper(
        ______________COLEMAK_MOD_DH_L1____________, ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________, ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________, ______________COLEMAK_MOD_DH_R3____________,
        _________________COMMON_LT_________________, _________________COMMON_RT_________________
     ),

    [_GAMING] = LAYOUT_wrapper(
        KC_ESC,  _________________GAMING_L1_________________,                                       _________________GAMING_R1_________________, _______,
        KC_LSFT, _________________GAMING_L2_________________,                                       _________________GAMING_R2_________________, _______,
        _______, _________________GAMING_L3_________________,                                       _________________GAMING_R3_________________, _______,
                                            KC_LCTL, _______, _______,                     _______, _______, _______
    ),

    [_MOUSE] = LAYOUT_crkbd_base_wrapper(
        _________________MOUSE_L1__________________, _________________MOUSE_R1__________________,
        _________________MOUSE_L2__________________, _________________MOUSE_R2__________________,
        _________________MOUSE_L3__________________, _________________MOUSE_R3__________________,
        _________________MOUSE_LT__________________, _________________COMMON_RT_________________
    ),

    [_LOWER] = LAYOUT_crkbd_base_wrapper(
        _________________LOWER_L1__________________, ________________NUMBER_RIGHT_______________,
        _________________LOWER_L2__________________, _________________LOWER_R2__________________,
        _________________LOWER_L3__________________, _________________LOWER_R3__________________,
        _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_RAISE] = LAYOUT_crkbd_base_wrapper(
        _________________RAISE_L1__________________, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _________________RAISE_R3__________________,
        _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_SYMBL] = LAYOUT_crkbd_base_wrapper(
      ___________________BLANK___________________, _________________SYMBL_R1__________________,
      ___________________BLANK___________________, _________________SYMBL_R2__________________,
      ___________________BLANK___________________, _________________SYMBL_R3__________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_FUNCL] = LAYOUT_crkbd_base_wrapper(
      _________________FUNCL_L1__________________, _________________FUNCL_R1__________________,
      _________________FUNCL_L2__________________, _________________FUNCL_R2__________________,
      _________________FUNCL_L3__________________, _________________FUNCL_R3__________________,
      _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),

    [_ADJUST] = LAYOUT_crkbd_base_wrapper(
        _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________, _________________ADJUST_R3_________________,
        _________________COMMON_LT_________________, _________________COMMON_RT_________________
    ),
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_DRIVER_ENABLE