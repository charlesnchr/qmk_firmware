/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3,
    _gamer,
    _colemak,
    _spcfn,
    _spcfnMac,
    _rgb,
    _mouse
};

enum custom_keycodes {
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD,
    KC_TASK,
    KC_FLXP,
    gamer = SAFE_RANGE,
    qwerty,
    colemak
};

#define KC_WAVE S(KC_GRV)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

enum combos {
  FJ_ESC,
};

const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [FJ_ESC] = COMBO(fj_combo, KC_MEDIA_SELECT),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_VOLD, KC_MUTE, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_CAPS, KC_LOPT, KC_LCMD,                            LT(_spcfnMac,KC_SPC),                             KC_RCMD, MO(_FN1), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_all(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_VOLD, KC_MUTE, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,          LGUI(LALT(KC_H)),
        LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,   KC_ENT,           LGUI(LALT(KC_L)),
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             RSFT_T(KC_F13),          KC_UP,
        KC_CAPS, KC_LGUI, LALT_T(KC_F13),                            LT(_spcfn,KC_SPC),                             RCTL_T(KC_F13), MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_all(
        KC_GRV,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,   KC_TRNS,          KC_VOLD, KC_MUTE, KC_VOLU,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN2] = LAYOUT_all(
        KC_GRV,  KC_BRID, KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,   KC_TRNS,          KC_VOLD, KC_MUTE, KC_VOLU,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN3] = LAYOUT_all(
        KC_WAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    RESET,          KC_VOLD, KC_MUTE, KC_VOLU,
        RGB_TOG,  KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_BTN1,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_gamer] = LAYOUT_all(
            KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______,
            KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
            LCTL_T(KC_ESC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP, _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______, _______
            ),

    [_colemak] = LAYOUT_all(
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______,
            _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  _______, _______, _______, _______,
            _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,          _______, _______,
            _______,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______,           _______, _______,
            _______, _______, _______,                            LT(_spcfn,KC_SPC),                            _______, _______, _______,  _______, _______,  _______
            ),

    [_spcfn] = LAYOUT_all(
            KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  LCTL(KC_BSPC), KC_VOLD, KC_MUTE, KC_VOLU,
            KC_HOME,  LGUI(KC_Q), LCTL(KC_W), KC_END, LGUI(KC_R), LCTL(KC_T), LGUI(KC_ENT), LCTL(KC_U), LCTL(KC_D), LCTL(KC_6), KC_PGDN, KC_PGUP, LCTL(KC_DEL), KC_DEL, LGUI(LSFT(KC_H)),
            _______,       LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_MPLY, LGUI(LSFT(KC_L)),
            _______,            KC_SPC, LCTL(KC_PGUP), LCTL(KC_PGDN),LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_LEFT), LCTL(KC_RGHT), KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______,
            MO(_mouse),   _______,   _______,                      KC_SPC,                              MO(_mouse),   MO(_rgb),   _______,   _______,   _______,   _______
            ),
    [_spcfnMac] = LAYOUT_all(
            KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_VOLD, KC_MUTE, KC_VOLU,
            LALT(KC_T),     _______, LALT(KC_W), _______, _______, _______, _______, _______, LCTL(KC_U), LCTL(KC_D), KC_HOME, KC_PGUP, KC_PGDN, KC_END, _______,
            _______,       LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_MPLY, _______,
            _______,            KC_SPC, LALT(KC_LCBR), LALT(KC_RCBR), LALT(KC_LBRC), LALT(KC_RBRC), LGUI(KC_LEFT), LGUI(KC_RIGHT), KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______,
            MO(_mouse),   _______,   _______,                      KC_SPC,                              MO(_mouse),   MO(_rgb),   _______,   _______,   _______,   _______
            ),
    [_rgb] = LAYOUT_all(
            RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU,
            _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,
            _______,       RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            qwerty, colemak, gamer,                      _______,                              _______,   _______,   _______,   _______,   _______,   _______
            ),
    [_mouse] = LAYOUT_all(
            KC_ESC,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______, KC_VOLD, KC_MUTE, KC_VOLU,
            _______,     KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            KC_BTN1,       KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______,
            _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______,   _______,   _______,                      KC_SPC,                              _______,   _______,   _______,   _______,   _______,   _______
            )
};

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{ 8, 4 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 7, 4 }};

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void matrix_scan_user(void) {
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_LWIN);
                unregister_code(KC_TAB);
            }
            return false;  // Skip all further processing of this key
        case KC_FLXP:
            if (record->event.pressed) {
                register_code(KC_LWIN);
                register_code(KC_E);
            } else {
                unregister_code(KC_LWIN);
                unregister_code(KC_E);
            }
            return false;  // Skip all further processing of this key
        case qwerty:
            if (record->event.pressed) {
                layer_clear();
                layer_on(WIN_BASE);
                set_single_persistent_default_layer(WIN_BASE);
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
        default:
            return true;  // Process all other keycodes normally
    }
}

void rgb_matrix_indicators_kb(void)
{
	if (rgb_matrix_config.enable) {
        switch (get_highest_layer(layer_state)) {
            /* case WIN_BASE: */
            /*     rgb_matrix_set_color(57, 0xFF, 0x00, 0x00); */
            /*     break; */
            case _colemak:
                rgb_matrix_set_color(58, 0xFF, 0xFF, 0xFF);
                break;
            case _gamer:
                rgb_matrix_set_color(17, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(31, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(32, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(33, 0xFF, 0x00, 0xFF);
                break;
        }
    }
}
