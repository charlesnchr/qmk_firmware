/* Copyright 2018 Milton Griffin
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

// Keyboard Layers

enum layers {
    _QW,
    _FN,
};

enum keycodes {
    MIDI_CC0 = SAFE_RANGE,
    MIDI_CC1,
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
    MIDI_CC64_on,
    MIDI_CC64_off,
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
    MIDI_CC_V12,
    MIDI_CC_V13,
    MIDI_CC_V14,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
    MIDI_CC_V0,  MIDI_CC_V1,    MIDI_CC_V2,    MIDI_CC_V3,    MIDI_CC_V4,    MIDI_CC_V5,    MIDI_CC_V6,    MIDI_CC_V7,    MIDI_CC_V8,    MIDI_CC_V9,    MIDI_CC_V10,    MIDI_CC_V11,    MIDI_CC_V12, MIDI_CC_V13, MIDI_CC_V14,
    MI_OCTU, MI_Cs_1,    MI_Ds_1,    KC_C,    MI_Fs_1,    MI_Gs_1,    MI_As_1,  KC_UP,   MI_Cs_2, MI_Ds_2,    KC_M,    MI_Fs_2, MI_Gs_2,  MI_As_2, KC_RSFT,
    MI_OCTD, MI_C_1,  MI_D_1,  MI_E_1,   MI_F_1,   MI_G_1, MI_A_1,   MI_B_1, MI_C_2,  MI_D_2,  MI_E_2,   MI_F_2,   MI_G_2, MI_A_2,   MI_B_2,
    KC_LSFT, MIDI_CC1,    MIDI_CC2,    MIDI_CC3,    MIDI_CC4,    MIDI_CC5,    MI_OCTU,    MI_VELU,    MIDI_CC64_on,    MIDI_CC6,    MIDI_CC7,    MIDI_CC8,    MIDI_CC9, MIDI_CC10, KC_H,
    MO(_FN), MIDI_CC11,    MIDI_CC12,    MIDI_CC13,    MIDI_CC14,    MIDI_CC15,    MI_OCTD,    MI_VELD,    MIDI_CC64_off, MIDI_CC16,    MIDI_CC17,    MIDI_CC18,    MIDI_CC19,    MIDI_CC20, KC_H
 ),

 /* [_QW] = LAYOUT_ortho_5x15( /1* QWERTY *1/ */
 /*    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, */
 /*    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, */
 /*    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, */
 /*    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */
 /*    KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  KC_SPC,  MO(_FN), KC_RALT, KC_RGUI, KC_RCTL */
 /* ), */


/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
    KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
    KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
    _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
 ),
};

static uint8_t current_MIDI_ccNumber         = 18;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case MIDI_CC0:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 32;
            } else {
            }
            return false;
            break;

        case MIDI_CC1:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 33;
            } else {
            }
            return false;
            break;

        case MIDI_CC2:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 34;
            } else {
            }
            return false;
            break;

        case MIDI_CC3:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 35;
            } else {
            }
            return false;
            break;

        case MIDI_CC4:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 36;
            } else {
            }
            return false;
            break;

        case MIDI_CC5:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 37;
            } else {
            }
            return false;
            break;

        case MIDI_CC6:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 38;
            } else {
            }
            return false;
            break;

        case MIDI_CC7:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 39;
            } else {
            }
            return false;
            break;

        case MIDI_CC8:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 40;
            } else {
            }
            return false;
            break;

        case MIDI_CC9:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 41;
            } else {
            }
            return false;
            break;

        case MIDI_CC10:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 42;
            } else {
            }
            return false;
            break;

        case MIDI_CC11:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 43;
            } else {
            }
            return false;
            break;

        case MIDI_CC12:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 44;
            } else {
            }
            return false;
            break;

        case MIDI_CC13:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 45;
            } else {
            }
            return false;
            break;

        case MIDI_CC14:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 46;
            } else {
            }
            return false;
            break;

        case MIDI_CC15:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 47;
            } else {
            }
            return false;
            break;

        case MIDI_CC16:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 48;
            } else {
            }
            return false;
            break;

        case MIDI_CC17:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 49;
            } else {
            }
            return false;
            break;

        case MIDI_CC18:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 50;
            } else {
            }
            return false;
            break;

        case MIDI_CC19:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 51;
            } else {
            }
            return false;
            break;


        case MIDI_CC64_on:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 64, 127);
            } else {
            }
            return false;
            break;


        case MIDI_CC64_off:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 64, 0);
            } else {
            }
            return false;
            break;


        case MIDI_CC_V0:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 0);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V1:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 9);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V2:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 18);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V3:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 27);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V4:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 36);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V5:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 45);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V6:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 54);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V7:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 64);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V8:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 73);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V9:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 82);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V10:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 91);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V11:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 100);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V12:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 109);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V13:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 118);
            } else {
            }
            return false;
            break;

        case MIDI_CC_V14:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 127);
            } else {
            }
            return false;
            break;



        /* case MIDI_CC80: */
        /*     if (record->event.pressed) { */
        /*         midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, MIDI_CC_ON); */
        /*     } else { */
        /*         midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, MIDI_CC_OFF); */
        /*     } */
        /*     return true; */
        /*     break; */
        default:
            return true;  // Process all other keycodes normally
    }
}

