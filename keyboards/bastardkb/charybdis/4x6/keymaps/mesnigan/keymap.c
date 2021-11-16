#include "mesnigan.h"

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
                                       K31,    K32,    K33,                                              K34,     K36,     K35,     \
                                          DRAG_SCROLL, KC_LOCK,                                          _______, DRAG_SCROLL  \
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
        _______, SNIPER_CONFIG, DPI_CONFIG, _______, _______, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________,          _________________ADJUST_R3_________________,
        _________________QWERTY_LT_________________,          _________________QWERTY_RT_________________
    ),
};

static uint16_t mouse_timer           = 0;
static uint16_t mouse_debounce_timer  = 0;
static uint8_t  mouse_keycode_tracker = 0;

#    ifdef TAPPING_TERM_PER_KEY
#        define TAP_CHECK get_tapping_term(KC_BTN1, NULL)
#    else
#        ifndef TAPPING_TERM
#            define TAPPING_TERM 200
#        endif
#        define TAP_CHECK TAPPING_TERM
#    endif

void matrix_scan_keymap(void) {
    if (timer_elapsed(mouse_timer) > 650 && layer_state_is(_MOUSE) && !mouse_keycode_tracker) {
        layer_off(_MOUSE);
    }
}

void process_mouse_user(report_mouse_t* mouse_report, int16_t x, int16_t y) {
    mouse_timer = timer_read();
    if (timer_elapsed(mouse_debounce_timer) > TAP_CHECK) {
        mouse_report->x = x;
        mouse_report->y = y;
        if (!layer_state_is(_MOUSE)) {
            layer_on(_MOUSE);
        }
    }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case SNIPING:
        case DPI_CONFIG:
        case KC_MS_UP ... KC_MS_WH_RIGHT:
        case THUMB_L2:
            record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
            mouse_timer = timer_read();
            break;
        default:
            if (IS_NOEVENT(record->event)) break;
            if ((keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) && (((keycode >> 0x8) & 0xF) == _MOUSE)) {
                record->event.pressed ? mouse_keycode_tracker++ : mouse_keycode_tracker--;
                mouse_timer = timer_read();
                break;
            }
            if (layer_state_is(_MOUSE) && !mouse_keycode_tracker) {
                layer_off(_MOUSE);
            }
            mouse_keycode_tracker = 0;
            mouse_debounce_timer  = timer_read();
            break;
    }
    return true;
}