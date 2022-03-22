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
    _fn,
    _FN4,
    _FN5,
    _spcfn,
    _spcfnMac,
    _FN_i3,
    _FN_i3_shift,
    _FN_i3ws,
    _FN_i3move,
    _FN_i3bring,
    _rgb,
    _mouse
};


enum keycodes {
    gamer = SAFE_RANGE,
    qwerty,
    colemak,
    aes,
    ae,
    oe,
    oes,
    aa,
    aas,
    pnd,
    eur,
    i3,
    i3ws,
    i3nav,
    i3apps,
    i3moveto,
    i3bringto,
    i3layer,
    endash,
    emdash,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_qwerty] = LAYOUT_60_ansi_arrow(
        LT(_numpad,KC_GRV),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LCTL_T(KC_ESC),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   RSFT_T(KC_SLSH),   KC_UP, KC_SLSH,
        LT(_FN4,KC_F13), KC_LGUI, LALT_T(KC_F13),                            LT(_spcfn,KC_SPC),                             RCTL_T(KC_F13), LT(_FN4, KC_F13),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_numpad] = LAYOUT_60_ansi_arrow(
        RESET,   LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, _______, _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, _______, KC_ENT,
        _______,            _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______,
        _______,   _______,   _______,                      _______,                              KC_KP_0, KC_KP_DOT,   _______,   _______, _______
    ),

    // Gamer standard qwerty layout but with normal space for jumping etc
    [_gamer] = LAYOUT_60_ansi_arrow(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            MO(_fn), _______, _______, _______, _______
    ),

    [_colemak] = LAYOUT_60_ansi_arrow(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  _______, _______, _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT,          _______,
        _______,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______,           _______, _______,
        _______, _______, _______,                            LT(_spcfn,KC_SPC),                            _______, _______, _______,  _______, _______
    ),

    [_fn] = LAYOUT_60_ansi_arrow(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        LALT(KC_T),     _______, LALT(KC_W), _______, _______, _______, _______, _______, LCTL(KC_U), LCTL(KC_D), KC_HOME, KC_PGUP, KC_PGDN, KC_END,
        _______,       LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, KC_MPLY,
        _______,            KC_SPC, LCTL(KC_PGUP), LCTL(KC_PGDN),LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_LEFT), LCTL(KC_RGHT), KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______,
        _______,   _______,   _______,                      MO(_mouse),                              MO(_mouse), MO(_rgb),   _______,   _______, _______
    ),

    [_mouse] = LAYOUT_60_ansi_arrow(
        KC_ESC,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
        _______,     KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_BTN1,       KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, KC_LPRN, KC_RPRN,  _______, _______, _______, _______,           _______, _______,
        _______, _______, _______,                            KC_SPC,                            MO(_rgb), _______, _______, _______, _______
    ),

    [_FN4] = LAYOUT_60_ansi_arrow(
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    RESET,
        RGB_TOG,  KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, aa,  KC_TRNS, KC_TRNS,
        KC_BTN1,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ae, oe,           KC_TRNS,
        MO(_FN5),          KC_INS, KC_APP, KC_RALT, KC_TRNS, KC_TRNS, endash, emdash, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, _______,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_SPC,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS
        ),

    [_FN5] = LAYOUT_60_ansi_arrow(
        KC_ESC, KC_F1,   KC_F2,   pnd,   eur,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    RESET,
        RGB_TOG,  KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, aas,  KC_TRNS, KC_TRNS,
        KC_BTN1,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, aes, oes,           KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,
        ),

    [_gamer] = LAYOUT_60_ansi_arrow(
            KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
            KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
            LCTL_T(KC_ESC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP, _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______
            ),

    [_spcfn] = LAYOUT_60_ansi_arrow(
            KC_ESC,   S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),  S(KC_MINS),  S(KC_EQL),  LCTL(KC_BSPC),
            LGUI(KC_B),  LGUI(KC_Q), LCTL(KC_W), KC_END, i3, LCTL(KC_T), i3apps, LCTL(KC_U), LCTL(KC_D), LCTL(KC_6), KC_HOME, S(KC_LBRC), S(KC_RBRC), KC_DEL,
            _______,       LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), i3layer, OSL(_FN_i3ws), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, LGUI(LCTL(KC_H)), LGUI(LCTL(KC_L)), LGUI(KC_ENT),
            _______,            KC_SPC, LCTL(KC_PGUP), LCTL(KC_PGDN), LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_LEFT), LCTL(KC_RGHT), LGUI(KC_H), LGUI(KC_L), LGUI(KC_B), LGUI(LALT(KC_ENT)), _______,
            MO(_mouse),   _______,   _______,                      KC_SPC,                              MO(_mouse),   MO(_rgb),   _______,   _______,   _______
            ),

    [_rgb] = LAYOUT_60_ansi_arrow(
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______,       RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        qwerty, colemak, gamer,                            _______,                            _______, _______, _______, _______, _______
    ),


    [_FN_i3] = LAYOUT_60_ansi_arrow(
        TO(_qwerty),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,
        KC_TAB,  LGUI(KC_F),    KC_W,    OSL(_FN_i3bring),    LCAG(KC_R),    KC_T,    KC_Y,    KC_PGUP,    KC_PGDN,    OSL(_FN_i3move),    LCAG(KC_1),    KC_LBRC,  KC_RBRC,   KC_BSLS,
        LCTL_T(KC_ESC),   LCTL(LGUI(KC_H)),    LCTL(LGUI(KC_L)),    OSL(_FN_i3_shift),    i3layer,    KC_G,    LGUI(KC_H),    LGUI(KC_J),    LGUI(KC_K),    LGUI(KC_L),    LAG(KC_H),  LAG(KC_L),   LGUI(KC_F),
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LCAG(KC_N),    LCAG(KC_M),    LCAG(KC_COMM), LCAG(KC_DOT),  KC_SLSH,             LCAG(KC_1), _______,
        LGUI_T(KC_F13), KC_LGUI, LALT_T(KC_F13),                            LT(_spcfn,KC_SPC),                             RCTL_T(KC_F13), LT(_FN4, KC_F13), KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_FN_i3_shift] = LAYOUT_60_ansi_arrow(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    LCAG(KC_4),    KC_LBRC,  KC_RBRC,   KC_BSLS,
        LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    LGUI(LSFT(KC_H)),    LGUI(LSFT(KC_J)),    LGUI(LSFT(KC_K)),    LGUI(LSFT(KC_L)), LCAG(KC_H),   LCAG(KC_L),    LGUI(KC_F),
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    HYPR(KC_N),    HYPR(KC_M),    HYPR(KC_COMM), HYPR(KC_DOT),  KC_SLSH,             LCAG(KC_4), _______,
        LGUI_T(KC_F13), KC_LGUI, LALT_T(KC_F13),                            LT(_spcfn,KC_SPC),                             RCTL_T(KC_F13), LT(_FN4, KC_F13), KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_FN_i3ws] = LAYOUT_60_ansi_arrow(
            KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______, _______,  _______, _______,
            KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
            LCTL_T(KC_ESC), LGUI(KC_1),    LGUI(KC_2),    LGUI(KC_3),    LGUI(KC_4),    LGUI(KC_5),    LGUI(KC_6),    LGUI(KC_7),    LGUI(KC_8),    LGUI(KC_9), _______, _______,          _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP, _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______
            ),

    [_FN_i3move] = LAYOUT_60_ansi_arrow(
            KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______, _______,  _______, _______,
            LSG(KC_B),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    LCAG(KC_3),    KC_LBRC,  KC_RBRC,   KC_BSLS,
            LCTL_T(KC_ESC), LSG(KC_1),    LSG(KC_2),    LSG(KC_3),    LSG(KC_4),    LSG(KC_5),    LSG(KC_6),    LSG(KC_7),    LSG(KC_8),    LSG(KC_9), _______, _______,          _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          LCAG(KC_3), _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______
            ),

    [_FN_i3bring] = LAYOUT_60_ansi_arrow(
            KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______, _______,  _______, _______,
            LAG(KC_B),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    LCAG(KC_2),    KC_LBRC,  KC_RBRC,   KC_BSLS,
            LCTL_T(KC_ESC), LAG(KC_1),    LAG(KC_2),    LAG(KC_3),    LAG(KC_4),    LAG(KC_5),    LAG(KC_6),    LAG(KC_7),    LAG(KC_8),    LAG(KC_9), _______, _______,          _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          LCAG(KC_2), _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______
            )

};




bool i3_bool = false;											//Global repeat variable
bool i3layer_used = false;											//Global repeat variable
bool i3layer_btn_released = false;											//Global repeat variable
bool i3_returnlayer = false;											//Global repeat variable
/* static uint16_t key_timer; */



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if(layer_state_is(_FN_i3)) {

        /* if (i3layer_btn_released && timer_read() - key_timer > 1000) { */
        /*     layer_off(_FN_i3); */
        /*     i3layer_used = false; */
        /*     i3layer_btn_released = false; */
        /* } */
        if (i3layer_btn_released && i3layer_used) {
            layer_off(_FN_i3);
            i3layer_used = false;
            i3layer_btn_released = false;
        }

        switch (keycode) {
            case i3layer:
                if (record->event.pressed) {							//When key is pressed
                    layer_on(_FN_i3);
                    i3layer_btn_released = false;
                    i3layer_used = false;
                    /* key_timer = timer_read(); */
                } else {
                    i3layer_btn_released = true;
                }
                return true;
            default:
                if (record->event.pressed) {							//When key is pressed
                    i3layer_used = true;
                } else {
                }
                break;
        }
    }


    if (i3_returnlayer) {
        switch (keycode) {
            case LT(_spcfn,KC_SPC):
                if (record->event.pressed) {							//When key is pressed
                } else {
                    i3_bool = false;
                    layer_clear();
                    layer_on(_qwerty);
                    return false;
                }
                break;
            default:
                break;
        }
        layer_clear();
        layer_on(_spcfn);
        i3_returnlayer = false;
        i3_bool = false;
    }

    if (i3_bool) {
        switch (keycode) {
            case LT(_spcfn,KC_SPC):
                if (record->event.pressed) {							//When key is pressed
                } else {
                    i3_bool = false;
                    i3_returnlayer = false;
                    layer_clear();
                    layer_on(_qwerty);
                }
                break;
            case LCTL_T(KC_ESC):
                if (record->event.pressed) {							//When key is pressed
                    i3_bool = false;
                    i3_returnlayer = false;
                    layer_clear();
                    layer_on(_qwerty);
                } else {
                }
                break;
            default:
                if (record->event.pressed) {							//When key is pressed
                    i3_returnlayer = true;
                } else {
                    // release is handled on the next call of process_record_user
                }
                break;
        }
    }


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
            break;
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
        case pnd:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("l"));
                SEND_STRING("-");
            }
            return false;
            break;
        case eur:
            if (record->event.pressed) {
                SEND_STRING(SS_RALT("="));
                SEND_STRING("e");
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
        case i3layer:
            if (record->event.pressed) {
                layer_on(_FN_i3);
                i3layer_used = false;
                i3layer_btn_released = false;
                /* key_timer = timer_read(); */
                // currently interferes with OSL functionality, not sure why
                /* i3_bool = true; // to reset layer after next click */
            } else {
                i3layer_btn_released = true;
            }
            return false;
            break;
        case i3:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_R);
                unregister_code(KC_LGUI);
                unregister_code(KC_R);
                layer_clear();
                layer_on(_qwerty);
                i3_bool = true;
            } else {
            }
            return false;
            break;
            /* case i3nav: */
            /*     if (record->event.pressed) { */
            /*         register_code(KC_LGUI); */
            /*         register_code(KC_R); */
            /*         unregister_code(KC_LGUI); */
            /*         unregister_code(KC_R); */
            /*         layer_clear(); */
            /*         layer_on(_qwerty); */
            /*         i3_bool = true; */
            /*     } else { */
            /*     } */
            /*     return false; */
            /*     break; */
        case i3apps:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_Y);
                unregister_code(KC_LGUI);
                unregister_code(KC_Y);
                layer_clear();
                layer_on(_qwerty);
                i3_bool = true;
            } else {
            }
            return false;
            break;
        default:
            return true;  // Process all other keycodes normally
    }
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
            case _fn:
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

