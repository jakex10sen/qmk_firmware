#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1),      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          MT(MOD_RSFT, KC_UP),
        KC_LCTL,    KC_LGUI, KC_LALT,                            KC_SPC,                             LT(2, KC_INS), KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
    [1] = LAYOUT_60_ansi(
        KC_GRV,     KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______,   _______, QK_RBT, _______, _______, _______, _______,  KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        CTL_T(KC_CAPS),          _______, _______, _______, _______, QK_BOOT, _______, KC_MUTE, KC_VOLD, KC_VOLU,  _______,          KC_PGUP,
        _______, _______, _______,                            RGB_TOG,                            _______, KC_HOME, KC_PGDN, KC_END
    ),
    [2] = LAYOUT_60_ansi(
        _______, KC_ACL0, KC_ACL1,   KC_ACL2,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
        _______, KC_BTN1, KC_MS_U,   KC_BTN2, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,          KC_WH_U,
        _______, _______, _______,                            _______,                            _______, KC_WH_L, KC_WH_D, KC_WH_R
    )
    // [1] = LAYOUT_60_ansi(
    //     KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    //     _______, _______, _______,   _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,  KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
    //     _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______,          _______,
    //     CTL_T(KC_CAPS),          _______, _______, _______, _______, QK_BOOT, _______, KC_MUTE, KC_VOLD, KC_VOLU,  _______,          KC_PGUP,
    //     _______, _______, _______,                            RGB_TOG,                            _______, KC_HOME, KC_PGDN, KC_END
    // )
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_GREEN);
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index <= led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_TEAL);
                }
            }
        }
    }
}
