/* Copyright 2020 Stefano Maragò
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.a
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // 12+11+11+9
  [0] = LAYOUT(
    LT(1,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI, LT(7,KC_SPC), LT(8,KC_SPC), TT(1), TT(4), TT(2), TT(6) ),
  [1] = LAYOUT(
    KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_QUOT, KC_NUHS, KC_EQL,
    KC_LSFT, KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_QUOT, KC_PGUP, KC_SLSH,
    KC_LCTL, KC_LALT, KC_LGUI, _______, MT(MOD_RSFT,KC_SPC), LT(3,KC_INS), KC_HOME, KC_PGDN, KC_END ),
  [2] = LAYOUT(
    DF(0), KC_PSCR, KC_SLCK, KC_PAUS, KC_PSLS, KC_PAST, KC_7, KC_8, KC_9, KC_PMNS, KC_PEQL, KC_BSPC,
    DF(0), KC_MPLY, KC_STOP, KC_MPRV, KC_MNXT, XXXXXXX, KC_4, KC_5, KC_6, KC_PPLS, KC_PENT,
    DF(2), KC_MUTE, KC_VOLD, KC_VOLU, KC_COMM, KC_1, KC_2, KC_3, _______, _______, _______,
    DF(3), XXXXXXX, XXXXXXX, _______, KC_0, KC_DOT, KC_MS_LEFT, _______, _______ ),
  [3] = LAYOUT(
    DF(0), KC_SLEP, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
    XXXXXXX, BL_TOGG, BL_DEC, BL_INC, BL_STEP, BL_BRTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),
  [4] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),
  [5] = LAYOUT(
    TT(9), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),S(KC_MINS),
    TT(6), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_QUOT, KC_NUHS, KC_EQL,
    TT(7), KC_LBRC, S(KC_LBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_RBRC), KC_RBRC, S(KC_0),
    _______, _______, _______, _______, KC_DEL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),
  [6] = LAYOUT(
    XXXXXXX, KC_HOME, KC_UP, KC_END, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, S(KC_0), XXXXXXX, KC_DEL,
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),
  [7] = LAYOUT(
    TT(5), KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_MS_WH_UP, S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),S(KC_MINS),
    TT(6), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_BSLS, S(KC_SCLN), KC_SCLN, KC_QUOT, KC_NUHS, KC_EQL,
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), KC_NUBS, XXXXXXX, KC_MINS, S(KC_EQL), XXXXXXX, XXXXXXX,
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),
  [8] = LAYOUT(
    KC_NUBS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_9), KC_LBRC, KC_RBRC, S(KC_0),
    _______, KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, KC_SLSH,   
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),
  [9] = LAYOUT(
    XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, KC_PSLS, KC_PAST, KC_7, KC_8, KC_9, KC_PMNS, KC_PEQL, KC_BSPC,
    KC_CAPS, KC_MPLY, KC_STOP, KC_MPRV, KC_MNXT, XXXXXXX, KC_4, KC_5, KC_6, KC_PPLS, KC_PENT,
    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_COMM, KC_1, KC_2, KC_3, KC_PAST, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, KC_0, KC_DOT, KC_PSLS, XXXXXXX, XXXXXXX ),
  [10] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ),
};

