/* Copyright 2019 mechmerlin
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

#include "midi.h"

extern MidiDevice midi_device;

enum layers {
    _qwerty,
    _fn1,
    _fn2,
    _fn3,
    _rgb,
    _mouse,
    _numpad,
    _gamer,
    _colemak
};

enum keycodes {
    MIDI_CC1 = SAFE_RANGE,
    MIDI_CC2,
    MIDI_CC3,
    MIDI_CC4,
    MIDI_CC5,
    MIDI_CC6,
    MIDI_CC7,
    MIDI_CC8,
    MIDI_CC9,
    MIDI_CC10,
    MIDI_CC11,
    MIDI_CC12,
    MIDI_CC13,
    MIDI_CC14,
    MIDI_CC15,
    MIDI_CC16,
    MIDI_CC17,
    MIDI_CC18,
    MIDI_CC19,
    MIDI_CC20,
    MIDI_CC21,
    MIDI_CC22,
    MIDI_CC23,
    MIDI_CC24,
    MIDI_CC25,
    MIDI_CC26,
    MIDI_CC_V0,
    MIDI_CC_V1,
    MIDI_CC_V2,
    MIDI_CC_V3,
    MIDI_CC_V4,
    MIDI_CC_V5,
    MIDI_CC_V6,
    MIDI_CC_V7,
    MIDI_CC_V8,
    MIDI_CC_V9,
    MIDI_CC_V10,
    MIDI_CC_V11,
};



#define MIDI_CC_OFF 0
#define MIDI_CC_ON  127



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* [_qwerty] = LAYOUT( */
    /*     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, */
    /*     LCTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT, */
    /*     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, */
    /*     MO(_fn3), KC_LGUI, KC_LALT, LT(_fn1,KC_SPC),                 LT(_fn2,KC_SPC),              MO(_fn3), KC_RCTL, KC_DOWN, KC_UP */
    /* ), */
    [_qwerty] = LAYOUT(
        MIDI_CC_V0,  MIDI_CC_V1,    MIDI_CC_V2,    MIDI_CC_V3,    MIDI_CC_V4,    MIDI_CC_V5,    MIDI_CC_V6,    MIDI_CC_V7,    MIDI_CC_V8,    MIDI_CC_V9,    MIDI_CC_V10,    MIDI_CC_V11,
        LCTL_T(KC_ESC),    MIDI_CC1,    MIDI_CC2,    MIDI_CC3,    MIDI_CC4,    MIDI_CC5,    MIDI_CC6,    MIDI_CC7,    MIDI_CC8,    MIDI_CC9,    MIDI_CC10,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,
        MO(_fn3), KC_LGUI, KC_LALT, LT(_fn1,KC_SPC),                 LT(_fn2,KC_SPC),              MO(_fn3), KC_RCTL, KC_DOWN, KC_UP
    ),
    [_fn1] = LAYOUT(
        KC_GRV,      S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5), S(KC_LBRC),  S(KC_RBRC),  S(KC_BSLS), KC_LBRC,  KC_RBRC,  KC_BSLS,
        _______,   LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), _______, KC_SCLN, KC_QUOT, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, S(KC_SCLN), S(KC_QUOT),
        _______, _______, _______, _______,                _______,             MO(_mouse), MO(_rgb), _______, _______
    ),
    [_fn2] = LAYOUT(
        S(KC_GRV),      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
        _______,   S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),
        _______,          KC_MINS,  KC_EQL,  S(KC_MINS),  S(KC_EQL), _______,  S(KC_LBRC),  S(KC_RBRC),  S(KC_BSLS), S(KC_SCLN), S(KC_QUOT),
        _______, _______, _______, _______,                _______,             MO(_mouse), MO(_rgb), _______, _______
    ),
    [_fn3] = LAYOUT(
        S(KC_GRV),      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_HOME, KC_PGUP, KC_PGDN, KC_END,
        _______, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,    KC_MPLY,
        _______,  _______, LCTL(KC_PGUP), LCTL(KC_PGDN), LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_LEFT), LCTL(KC_RGHT), KC_VOLD, KC_VOLU, KC_MPRV,
        _______, _______, _______, _______,                _______,             MO(_mouse), MO(_rgb), _______, KC_MNXT
    ),
    [_rgb] = LAYOUT(
        RESET,      KC_I, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   BL_TOGG, BL_DEC,  BL_INC,  BL_STEP, _______, _______, _______, _______, _______, _______,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),
    [_mouse] = LAYOUT(
        RESET,      KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, _______, _______, _______, _______, _______,
        KC_BTN1,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,
        _______, _______, _______, _______,                _______,             _______, _______, _______, _______
    ),

};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case MIDI_CC_V0:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 0);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V1:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 12);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V2:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 23);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V3:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 35);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V4:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 46);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V5:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 58);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V6:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 69);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V7:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 81);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V8:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 92);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V9:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 104);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V10:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 115);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V11:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 80, 127);
            } else {
            }
            return false;
            break;



        /* case MIDI_CC80: */
        /*     if (record->event.pressed) { */
        /*         midi_send_cc(&midi_device, 0, 80, MIDI_CC_ON); */
        /*     } else { */
        /*         midi_send_cc(&midi_device, 0, 80, MIDI_CC_OFF); */
        /*     } */
        /*     return true; */
        /*     break; */
        default:
            return true;  // Process all other keycodes normally
    }
}
