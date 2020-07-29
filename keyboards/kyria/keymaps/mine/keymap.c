#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

extern uint8_t is_master;

#define A_ALT LALT_T(KC_A)
#define A_GUI LGUI_T(KC_A)
#define S_CTL LCTL_T(KC_S)
#define S_ALT LALT_T(KC_S)
#define D_SFT LSFT_T(KC_D)
#define F_GUI LGUI_T(KC_F)
#define F_CTL LCTL_T(KC_F)

#define J_GUI RGUI_T(KC_J)
#define J_CTL RCTL_T(KC_J)
#define K_SFT RSFT_T(KC_K)
#define L_CTL RCTL_T(KC_L)
#define L_ALT RALT_T(KC_L)
#define SC_ALT RALT_T(KC_SCLN)
#define SC_GUI RGUI_T(KC_SCLN)

enum layers {
    _QWERTY,
    _QWERTY_MAC,
    _GAMING,
    _NAVR,
    _MOUR,
    _MEDR,
    _NSL,
    _NSLG,
    _NSSL,
    _FUNL,
};
enum custom_keycodes {
    ATAB = SAFE_RANGE,
    WINDOWS,
    MACOS,
    CAPSLK,
};

#define GAMING TG(_GAMING)
#define NAVR LT(_NAVR, KC_SPC)
#define MOUR LT(_MOUR, KC_TAB)
#define MEDR LT(_MEDR, KC_DEL)
#define NSL LT(_NSL, KC_ESC)
#define NSLG MO(_NSLG)
#define NSSL LT(_NSSL, KC_ENT)
#define FUNL LT(_FUNL, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [_QWERTY] = LAYOUT(
        KC_MINS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
        CAPSLK,  A_GUI,   S_ALT,   D_SFT,   F_CTL,   KC_G,                                           KC_H,    J_CTL,   K_SFT,   L_ALT,   SC_GUI,  KC_QUOT,
        KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                   GAMING,  MOUR,    NAVR,    NSL,     _______,    _______, FUNL,    NSSL,    MEDR,    KC_MPLY
     ),

    [_QWERTY_MAC] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
        _______, A_ALT,   S_CTL,   D_SFT,   F_GUI,   _______,                                        _______, J_GUI,   K_SFT,   L_CTL,   SC_ALT,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_GAMING] = LAYOUT(
        KC_ESC,  KC_T,    KC_Q,    KC_X,    KC_E,    KC_R,                                              _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_G,    KC_A,    KC_W,    KC_D,    KC_F,                                              _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_B,    KC_Z,    KC_S,    KC_C,    KC_V,    _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, KC_LALT, KC_SPC,  NSLG,    _______,      _______, _______, _______, _______, _______
    ),

    [_NAVR] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        _______, _______, _______, _______, ATAB,    _______,                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,  _______,
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_MOUR] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                        _______, KC_WH_D, _______, KC_WH_U, KC_BTN4, _______,
        _______, _______, _______, _______, _______, _______,                                        _______, KC_MS_L, KC_MS_U, KC_MS_R, KC_BTN5, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_WH_L, KC_MS_D, KC_WH_R, _______, _______,
                                   _______, _______, _______, _______, _______,    _______, KC_BTN2, KC_BTN1, KC_BTN3, _______
    ),


    [_MEDR] = LAYOUT(
        _______, _______, _______, _______, RESET,   _______,                                        _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MPRV, KC_VOLU, KC_MNXT, _______,                                        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_VOLD, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),

    [_NSL] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,     _______, KC_BSPC, KC_ENT,  KC_DEL,  _______
    ),

    [_NSLG] = LAYOUT(
        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                            _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                            _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

    [_NSSL] = LAYOUT(
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, _______,                                         _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                         KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,
        _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, KC_TAB,  KC_SPC,  _______, _______,     _______, _______, _______, _______, _______
    ),

    [_FUNL] = LAYOUT(
        _______, KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______,                                          _______, _______, _______, _______, _______, _______,
        _______, KC_F5,  KC_F6,   KC_F7,   KC_F8,   _______,                                          _______, _______, _______, _______, _______, _______,
        _______, KC_F1,  KC_F2,   KC_F3,   KC_F4,   _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, KC_TAB,  KC_SPC,  _______, _______,      _______, _______, _______, _______, _______
    )
};
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.1\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Windows\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case _NAVR:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _MOUR:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _MEDR:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case _NSL:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _NSLG:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case _NSSL:
            oled_write_P(PSTR("S_symbol\n"), false);
            break;
        case _FUNL:
            oled_write_P(PSTR("Function\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

static bool is_alt_set = false;

void release_alt(void) {
    int kc = KC_LALT;
    int mod = MOD_LALT;
    if (default_layer_state > 1) {
        kc = KC_LGUI;
        mod = MOD_LGUI;
    }
    bool is_alt_on = get_mods() & MOD_BIT(kc);
    if (is_alt_set && is_alt_on) {
        unregister_mods(mod);
        is_alt_set = false;
    }
};

void register_alt(void) {
    int kc = KC_LALT;
    int mod = MOD_LALT;
    if (default_layer_state > 1) {
        kc = KC_LGUI;
        mod = MOD_LGUI;
    }
    bool is_alt_on = get_mods() & MOD_BIT(kc);
    if (!is_alt_on) {
        register_mods(mod);
        is_alt_set = true;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        default:
            release_alt();
            break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ATAB:
            if (record->event.pressed) {
                register_alt();
                register_code(KC_TAB);
                unregister_code(KC_TAB);
            }
            return false;
        case WINDOWS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case MACOS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY_MAC);
            }
        case CAPSLK:
            if (record->event.pressed) {
                tap_code(KC_CAPS);
            }
    }
    return true;
}
