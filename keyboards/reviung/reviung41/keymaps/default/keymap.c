/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    LT(4,KC_TAB),   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    LSFT_T(KC_F13),  HYPR_T(KC_Z),     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                            KC_LALT,   LOWER,    LT(5,KC_SPC),   RAISE,    KC_LGUI
  ),

  [_LOWER] = LAYOUT_reviung41(
    KC_NUBS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    KC_LCTL,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_Z,   KC_LGUI,  KC_LALT,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  KC_SPC,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

  [_RAISE] = LAYOUT_reviung41(
    KC_TAB,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),

  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  RGB_SPI,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            QK_BOOT,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),

  [4] = LAYOUT_reviung41(
    XXXXXXX, HYPR(KC_Q), LALT(KC_W), HYPR(KC_E), HYPR(KC_R), LALT(KC_T),              KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_SLASH,  KC_KP_ASTERISK,  XXXXXXX,
    _______, HYPR(KC_A), LALT(KC_H), HYPR(KC_D),  HYPR(KC_F), HYPR(KC_G),           KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,  KC_KP_MINUS,  XXXXXXX,
    KC_LCTL,   KC_Z, _______,  XXXXXXX,  XXXXXXX,   XXXXXXX,       KC_KP_1, KC_KP_2, KC_KP_3,  KC_KP_DOT,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  KC_KP_0,  KC_ENT
  ),

  [5] = LAYOUT_reviung41(
    KC_ESC, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,  KC_WH_R,            KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  XXXXXXX,  KC_MPRV,
    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,   KC_WH_L,            KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  XXXXXXX,  KC_MNXT,
    _______, KC_LCTL, LALT(KC_LCBR), LALT(KC_RCBR), LALT(KC_LBRC), LALT(KC_RBRC),   XXXXXXX, XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_MPLY,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

