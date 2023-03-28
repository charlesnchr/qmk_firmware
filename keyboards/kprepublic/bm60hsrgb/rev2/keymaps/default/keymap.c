/* Copyright 2021 bdtc123
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _mac,
    _gamer,
    _mouse,
    _rgb
};


enum keycodes {
    gamer = SAFE_RANGE,
    mac,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_mac] = LAYOUT_60_ansi_arrow(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    LSFT_T(KC_I),    LCTL_T(KC_O),    RCTL_T(KC_P),    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    LCTL_T(KC_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RCTL_T(KC_SCLN), KC_QUOT, KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   RSFT_T(KC_SLSH),   KC_UP, MO(_mouse),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RGUI, KC_RALT,   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_rgb] = LAYOUT_60_ansi_arrow(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______,       RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, mac, gamer,                            MO(_mouse),                            _______, _______, _______, _______, _______
    ),

    [_mouse] = LAYOUT_60_ansi_arrow(
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,
        _______,     KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, KC_HOME, _______, KC_END, _______, KC_PGUP,    KC_PGDN, _______,
        KC_BTN1,       KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, KC_LPRN, KC_RPRN,  _______, _______, _______, _______,           MO(_rgb), _______,
        _______, _______, _______,                            KC_SPC,                            MO(_rgb), _______, _______, _______, _______
    ),

    [_gamer] = LAYOUT_60_ansi_arrow(
            KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
            KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
            LCTL_T(KC_ESC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP, _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______
            ),

};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case mac:
            if (record->event.pressed) {
                layer_clear();
                layer_on(_mac);
                set_single_persistent_default_layer(_mac);
            }
            return false;
            break;
        case gamer:
            if (record->event.pressed) {
                layer_clear();
                layer_on(_gamer);
            }
            return false;
            break;
        default:
            return true;  // Process all other keycodes normally
    }
}

void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color( i, red, green, blue );
        }
    }
}


void rgb_matrix_indicators_kb(void)
{
    if (rgb_matrix_config.enable) {
        switch (get_highest_layer(layer_state)) {
            case _mac:
                break;
            /* case _fn: */
            /*     rgb_matrix_set_color(22, 0xFF, 0x00, 0x00); */
            /*     rgb_matrix_set_color(35, 0xFF, 0x00, 0x00); */
            /*     rgb_matrix_set_color(36, 0xFF, 0x00, 0x00); */
            /*     rgb_matrix_set_color(37, 0xFF, 0x00, 0x00); */
            /*     break; */
            case _gamer:
                rgb_matrix_set_color(16, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(29, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(30, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(31, 0xFF, 0x00, 0xFF);
                break;
        }
    }
}

