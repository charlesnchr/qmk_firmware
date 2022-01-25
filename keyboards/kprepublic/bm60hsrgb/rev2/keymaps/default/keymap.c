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
_qwerty,
_numpad,
_gamer,
_colemak,
_spcfn,
_rgb,
_fn
};


enum keycodes {
gamer = SAFE_RANGE,
qwerty,
colemak
};

#define KC_SPFN LT(_spcfn, KC_SPC) // press for space, hold for function layer (aka spacefn)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_qwerty] = LAYOUT(
        LT(_numpad,KC_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LCTL_T(KC_ESC),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,    KC_UP,   RSFT_T(KC_F13),
        KC_CAPS, KC_LGUI, KC_LALT,                            KC_SPFN,                             KC_RGUI, KC_RALT,   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_numpad] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, KC_ENT,
        _______,            _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
        _______,   _______,   _______,                      _______,                              KC_KP_0, KC_KP_DOT,   _______,   _______, _______
    ),
    // Gamer standard qwerty layout but with normal space for jumping etc
    [_gamer] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            _______, MO(_fn), _______, _______, _______
    ),
    [_colemak] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  _______, _______, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,          _______,
        _______,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______,           _______, _______,
        _______, _______, _______,                            KC_SPFN,                            _______, _______, _______,  _______, _______
    ),
    [_spcfn] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______,     KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,
        KC_BTN1,       KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_MPLY,
        _______,            KC_SPC, LALT(KC_LCBR), LALT(KC_RCBR), LALT(KC_LBRC), LALT(KC_RBRC), KC_LPRN, KC_RPRN, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______,
        _______,   _______,   _______,                      KC_SPC,                              KC_RGUI, MO(_rgb),   _______,   _______, _______
    ),
    [_rgb] = LAYOUT(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______,       RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        qwerty, colemak, gamer,                            _______,                            _______, _______, _______, _______, _______
    ),
    [_fn] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, _______, KC_PGUP, _______, KC_LBRC, KC_RBRC,  _______, _______,   _______, _______, _______,  _______, _______,
        _______, _______, _______, KC_PGDN, KC_LCBR, KC_RCBR, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,          _______,
        _______,          _______, _______, _______, _______, KC_LPRN, KC_RPRN,  _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            _______,                            MO(_rgb), _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case qwerty:
        if (record->event.pressed) {
            layer_clear();
            layer_on(_qwerty);
            set_single_persistent_default_layer(_qwerty);
        }
        return false;
        break;
      case colemak:
        if (record->event.pressed) {
            layer_clear();
            layer_on(_colemak);
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

  }
  return true;
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
            //case _qwerty:
            //    rgb_matrix_set_color(26, 0xFF, 0x00, 0x00);
            //    break;
            case _colemak:
                rgb_matrix_set_color(55, 0xFF, 0xFF, 0xFF);
                break;
            case _spcfn:
                rgb_matrix_set_color(22, 0xFF, 0x00, 0x00);
                rgb_matrix_set_color(35, 0xFF, 0x00, 0x00);
                rgb_matrix_set_color(36, 0xFF, 0x00, 0x00);
                rgb_matrix_set_color(37, 0xFF, 0x00, 0x00);
                break;
            case _gamer:
                rgb_matrix_set_color(16, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(29, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(30, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(31, 0xFF, 0x00, 0xFF);
                break;
        }
    }
}

/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {*/
    /*[0] = LAYOUT(*/
        /*KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,*/
        /*KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,*/
        /*KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,*/
        /*KC_LSFT,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,        KC_UP,   KC_SLSH,*/
        /*KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT*/
    /*),*/
    /*[1] = LAYOUT(*/
        /*_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,*/
        /*_______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,*/
        /*_______,            _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______,*/
        /*_______,            _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,        _______, _______,*/
        /*_______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______*/
    /*)*/

/*};*/
