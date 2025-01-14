/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    aes = SAFE_RANGE,
    ae,
    oe,
    oes,
    aa,
    aas,
    autorun,
    endash,
    emdash,
    qwerty,
    gamer,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_T(KC_ESC),    LSFT_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LCTL_T(KC_F),    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L, LCTL_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    LSFT_T(KC_Z),    LALT_T(KC_X),    KC_C,    KC_V,    KC_B,                         RALT_T(KC_N),    LALT_T(KC_M), RGUI_T(KC_COMM),  RCTL_T(KC_DOT), RSFT_T(KC_SLSH),  RSFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                          KC_LGUI,   LT(2, KC_MINS),  LT(6, KC_SPC),     LGUI_T(KC_SPC),   LT(3, KC_LBRC), LT(5, KC_RBRC)
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L, LCTL_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    LSFT_T(KC_Z),    LALT_T(KC_X),    LGUI_T(KC_C),    KC_V,    KC_B,                         RALT_T(KC_N),    LALT_T(KC_M), RGUI_T(KC_COMM),  RCTL_T(KC_DOT), RSFT_T(KC_SLSH),  RSFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                          KC_LCTL,   LT(3, KC_BSPC),  KC_SPC,     LGUI_T(KC_SPC),   LT(2, KC_LBRC), LT(5, KC_RBRC)
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_EXLM, KC_AT, KC_HASH,  KC_DLR, KC_PERC,                        XXXXXXX,KC_7, KC_8, KC_9, aa, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F5, LCTL(KC_6), XXXXXXX, KC_MINS, KC_UNDS, KC_CIRC,                           KC_AMPR, KC_4, KC_5, KC_6, ae, oe,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(6), MO(6), XXXXXXX, KC_EQL, KC_PLUS, KC_ASTR,                         KC_PIPE, KC_1, KC_2, KC_3, KC_BSLS, LT(6, KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_0, KC_LPRN, KC_RPRN
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                              KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,   KC_8,    KC_9,  KC_0, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_BSLS, autorun,  QK_LOCK, KC_EQL, KC_PLUS,                      KC_F11, KC_F12, KC_PIPE, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(4),  KC_SPC,     KC_ENT, _______, KC_0
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC, XXXXXXX, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L,                      XXXXXXX, KC_HOME, KC_UP, KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R,             KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(7), MO(7), LGUI(KC_F1), LGUI(KC_F2), LGUI(KC_F3), LGUI(KC_F4),                           XXXXXXX, qwerty, gamer, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_0, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LALT(KC_TAB),    KC_HOME,    KC_UP,    KC_END,    KC_VOLU, KC_MNXT,   KC_Y,   KC_U, endash,  emdash, aas,  LCTL(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCAG(KC_ESC),    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_VOLD,    KC_MPRV,   KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT, aes, oes,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    LSFT_T(KC_INS), LCAG(KC_X), LCAG(KC_C), KC_MUTE, KC_MPLY, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_HOME,  KC_END,  RSFT_T(KC_F4),  RSFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     RGUI_T(KC_SPC),   KC_RALT, aes
                                      //`--------------------------'  `--------------------------'
  )

};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x81, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        /* oled_render_layer_state(); */
        /* oled_render_keylog(); */
        oled_render_logo();
    } else {
        oled_render_logo();
    }
    return false;
}

bool autorun_active = false;
uint16_t autopress_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // this is for display key log
  /* if (record->event.pressed) { */
  /*   set_keylog(keycode, record); */
  /* } */

    switch (keycode) {
        case ae:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("a"));
                SEND_STRING("e");
            }
            return false;
            break;
        case oe:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("o"));
                SEND_STRING("/");
            }
            return false;
            break;
        case aes:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("A"));
                SEND_STRING("E");
            }
            return false;
        case oes:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("O"));
                SEND_STRING("/");
            }
            return false;
            break;
        case aa:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("a"));
                SEND_STRING("a");
            }
            return false;
            break;
        case aas:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("A"));
                SEND_STRING("A");
            }
            return false;
            break;
        case endash:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("-"));
                SEND_STRING("-.");
            }
            return false;
            break;
        case emdash:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("-"));
                SEND_STRING("--");
            }
            return false;
            break;
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
        case autorun:
            if (record->event.pressed) {
                autorun_active = !autorun_active;
                if (autorun_active) {
                    autopress_timer = timer_read();
                }
            }
            return false;
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (autorun_active) {
        if (timer_elapsed(autopress_timer) > 50) {
            tap_code(KC_W);
            autopress_timer = timer_read();
        }
    }
}
