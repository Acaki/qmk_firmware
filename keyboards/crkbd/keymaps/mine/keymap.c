#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define MOUSE TG(_MOUSE)
#define ARROWS TG(_ARROWS)
#define RETURN TO(_QWERTY)
#define WINPAST G(KC_V)
#define CAPTURE SGUI(KC_S)
#define LALTTAB LALT_T(KC_TAB)
#define RALTDEL LALT_T(KC_DEL)
#define LSFTKCZ LSFT_T(KC_Z)
#define RSFTSLH RSFT_T(KC_SLSH)
enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
    _ARROWS,
};
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    RGBRST,
    ARROW,
    DBLARR,
    ATAB,
    ASFT,
    WIN0,
    WIN1,
    WIN2,
    WIN3,
    WIN4,
    WIN5,
    WIN6,
    WIN7,
    WIN8,
    WIN9
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, LSFTKCZ, KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFTSLH, KC_RALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, KC_SPC,  LOWER,                     RAISE,   KC_ENT,  KC_RCTL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                               KC_APP,  MOUSE,   KC_LABK, KC_RABK, KC_QUES, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, ATAB,    ASFT
                                 //└────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILD, KC_LCBR, KC_EQL,  KC_QUOT, KC_MINS, KC_RCBR,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LBRC, KC_PLUS, KC_DQT,  KC_UNDS, KC_RBRC,                            KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    ASFT,    ATAB,    _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, WIN1,    WIN2,    WIN3,    WIN4,    WIN5,                               WIN6,    WIN7,    WIN8,    WIN9,    WIN0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, ARROWS,  DBLARR,  WINPAST, ARROW,   CAPTURE,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGBRST,  RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, RESET,                              _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RETURN,  _______, _______, _______, _______, _______,                            _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN4, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),

   [_ARROWS] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      RETURN,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, KC_UP,   _______,
   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT,
   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┐                 ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______, _______, _______,                   _______, _______, _______
                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    ),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
#endif
#ifdef SSD1306OLED
    iota_gfx_init(!has_usb());
#endif
}

#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}

#endif//SSD1306OLED

static bool is_alt_set = false;

void release_alt(void) {
    bool is_alt_on = get_mods() & MOD_BIT(KC_LALT);
    if (is_alt_set && is_alt_on) {
        unregister_mods(MOD_LALT);
        is_alt_set = false;
    }
};

void register_alt(void) {
    bool is_alt_on = get_mods() & MOD_BIT(KC_LALT);
    if (!is_alt_on) {
        register_mods(MOD_LALT);
        is_alt_set = true;
    }
}

static bool is_gui_set = false;

void release_gui(void) {
    bool is_gui_on = get_mods() & MOD_BIT(KC_LGUI);
    if (is_gui_set && is_gui_on) {
        unregister_mods(MOD_LGUI);
        is_gui_set = false;
    }
};

void register_gui(void) {
    bool is_gui_on = get_mods() & MOD_BIT(KC_LGUI);
    if (!is_gui_on) {
        register_mods(MOD_LGUI);
        is_gui_set = true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
    #ifdef SSD1306OLED
        set_keylog(keycode, record);
    #endif
    }
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_QWERTY);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                release_alt();
                release_gui();
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                release_alt();
                release_gui();
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case RGB_MOD:
        #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
              rgblight_mode(RGB_current_mode);
              rgblight_step();
              RGB_current_mode = rgblight_config.mode;
            }
        #endif
            return false;
        case RGBRST:
        #ifdef RGBLIGHT_ENABLE
            if (record->event.pressed) {
              eeconfig_update_rgblight_default();
              rgblight_enable();
              RGB_current_mode = rgblight_config.mode;
            }
        #endif
            break;
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case DBLARR:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
        case ATAB:
            if (record->event.pressed) {
                register_alt();
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            return false;
        case ASFT:
            if (record->event.pressed) {
                register_alt();
                register_mods(MOD_LSFT);
            } else {
                unregister_mods(MOD_LSFT);
            }
            return false;
        case WIN0:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_0);
                unregister_code(KC_0);
            }
            return false;
        case WIN1:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_1);
                unregister_code(KC_1);
            }
            return false;
        case WIN2:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_2);
                unregister_code(KC_2);
            }
            return false;
        case WIN3:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_3);
                unregister_code(KC_3);
            }
            return false;
        case WIN4:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_4);
                unregister_code(KC_4);
            }
            return false;
        case WIN5:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_5);
                unregister_code(KC_5);
            }
            return false;
        case WIN6:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_6);
                unregister_code(KC_6);
            }
            return false;
        case WIN7:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_7);
                unregister_code(KC_7);
            }
            return false;
        case WIN8:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_8);
                unregister_code(KC_8);
            }
            return false;
        case WIN9:
            if (record->event.pressed) {
                register_gui();
                register_code(KC_9);
                unregister_code(KC_9);
            }
            return false;
    }
    return true;
}
