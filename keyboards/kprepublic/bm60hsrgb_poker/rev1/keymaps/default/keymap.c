/* Copyright 2020 ipetepete
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
_fn,
_mouse,
_rgb
};


enum keycodes {
gamer = SAFE_RANGE,
qwerty,
colemak
};

// Tap Dance declarations
enum {
    TD_LBR,
    TD_RBR,
};


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_qwerty] = LAYOUT_60_ansi(
        LT(_numpad,KC_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_LBR), TD(TD_RBR), KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,           KC_RGUI, KC_RALT, KC_LCTL, MO(_mouse)
    ),
    [_numpad] = LAYOUT_60_ansi(
        RESET,   LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     _______, LALT(KC_T), _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_5, KC_KP_6, _______, KC_ENT,
        _______,            _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______,
        _______,   _______,   _______,                      _______,                              KC_KP_0, KC_KP_DOT,   _______,   _______
    ),
    // Gamer standard qwerty layout but with normal space for jumping etc
    [_gamer] = LAYOUT_60_ansi(
        KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP,
        KC_LCTL, KC_LGUI, _______,                            KC_SPACE,                            MO(_fn), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_colemak] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  _______, _______, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,          _______,
        _______,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______,           _______,
        _______, _______, _______,                            LT(_fn,KC_SPC),                            _______, _______, _______,  _______
    ),
    [_fn] = LAYOUT_60_ansi(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        LALT(KC_T),     _______, LALT(KC_W), _______, _______, _______, _______, _______, LCTL(KC_U), LCTL(KC_D), KC_HOME, KC_PGUP, KC_PGDN, KC_END,
        _______,       LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_MPLY,
        _______,            KC_SPC, LALT(KC_LCBR), LALT(KC_RCBR), LALT(KC_LBRC), LALT(KC_RBRC), LGUI(KC_LEFT), LGUI(KC_RIGHT), KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT,
        MO(_mouse),   _______,   _______,                      KC_SPC,                              MO(_mouse),   MO(_rgb),   _______,   _______
    ),
    [_rgb] = LAYOUT_60_ansi(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______,       RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        qwerty, colemak, gamer,                      _______,                              _______,   _______,   _______,   _______
    ),
    [_mouse] = LAYOUT_60_ansi(
        KC_ESC,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
        _______,     KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
        KC_BTN1,       KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, MO(_rgb),
        _______,   _______,   _______,                      KC_SPC,                              KC_LEFT,   KC_DOWN,   KC_RIGHT,   _______
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
            case _gamer:
                rgb_matrix_set_color(16, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(29, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(30, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(31, 0xFF, 0x00, 0xFF);
                break;
        }
    }
}


/* LEADER_EXTERNS(); */

/* void matrix_scan_user(void) { */
/*   LEADER_DICTIONARY() { */
/*     leading = false; */
/*     leader_end(); */

/*     SEQ_ONE_KEY(KC_F) { */
/*       // Anything you can do in a macro. */
/*       SEND_STRING("QMK is awesome."); */
/*     } */
/*     SEQ_TWO_KEYS(KC_D, KC_D) { */
/*       SEND_STRING(SS_LCMD("a") SS_LCMD("c")); */
/*     } */
/*     SEQ_THREE_KEYS(KC_D, KC_D, KC_S) { */
/*       SEND_STRING("https://start.duckduckgo.com\n"); */
/*     } */
/*   } */
/* } */
