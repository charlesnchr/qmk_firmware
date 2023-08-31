// Copyright 2022 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
          KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
          KC_CAPS, LSFT_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LCTL_T(KC_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LCTL_T(KC_SCLN), KC_QUOT, KC_ENT,
          KC_LSFT, LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    RALT_T(KC_M), RGUI_T(KC_COMM),  RCTL_T(KC_DOT), RSFT_T(KC_SLSH), KC_UP, KC_UP,
          KC_LCTL, KC_LGUI, KC_LALT, KC_LALT,  KC_SPC,          _______, LT(_FN1,KC_SPC), KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
          ),

  [_FN1] = LAYOUT(
    KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,
    _______, KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, KC_HOME, _______, KC_END, _______, KC_PGUP,    KC_PGDN, _______,
    KC_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_TILD, _______, _______, _______, MO(_FN2),         _______, MO(_FN2), _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT(
    RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC,
    RGB_TOG, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  )

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
