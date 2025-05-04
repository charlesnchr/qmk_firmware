// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    qwerty = SAFE_RANGE,
    gamer,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        LT(2, KC_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        LCTL_T(KC_ESC), LSFT_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),   LCTL_T(KC_F),    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    LT(5, KC_SCLN), KC_QUOT,
        KC_LSFT, LSFT_T(KC_Z),    KC_X,    KC_C,    LT(5, KC_V),    KC_B,                               RALT_T(KC_N),    LALT_T(KC_M), RGUI_T(KC_COMM),  RCTL_T(KC_DOT),  RSFT_T(KC_SLSH), LCTL_T(KC_RBRC),
                                           KC_LGUI, LALT_T(KC_MINS), LT(2, KC_SPC),             LGUI_T(KC_SPC), KC_BSPC,  LT(4, KC_ENT)
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            MO(2), KC_LALT, KC_SPC,           KC_RGUI,  KC_TRNS,  KC_TRNS
    ),
    [2] = LAYOUT(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_ENT,  KC_HOME,    KC_UP,    KC_END,    KC_VOLU, KC_MNXT,                      KC_PGUP, KC_PGDN, KC_HOME, KC_END,  KC_F11,  KC_F12,
        MO(3),  KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD,  KC_MPRV,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC, KC_RBRC,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, KC_PLUS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_4, KC_5, KC_6, KC_0, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [4] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(6),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [5] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(6),
        KC_TRNS,  KC_TRNS, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L,                            KC_PGUP, KC_7, KC_8, KC_9,  KC_DEL,  KC_F12,
        KC_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R,                            KC_LEFT, KC_4, KC_5, KC_6, KC_LBRC, KC_RBRC,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_0,  KC_0,  KC_TRNS
    ),
    [6] = LAYOUT(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            qwerty, gamer, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // this is for display key log
  /* if (record->event.pressed) { */
  /*   set_keylog(keycode, record); */
  /* } */

    switch (keycode) {
        case qwerty:
            if (record->event.pressed) {
                layer_clear();
                layer_on(0);
            }
            return false;
            break;
        case gamer:
            if (record->event.pressed) {
                layer_clear();
                layer_on(1);
            }
            return false;
            break;
    }
    return true;
}