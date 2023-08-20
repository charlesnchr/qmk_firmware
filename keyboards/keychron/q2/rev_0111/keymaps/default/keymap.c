/* Copyright 2021 bdtc123
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "print.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    _MAC_FN4,
    _FN4,
    _FN5,
    _gamer,
    _spcfn,
    _spcfnMac,
    _FN_i3,
    _FN_i3_r,
    _FN_i3_y,
    _FN_i3_shift,
    _FN_i3ws,
    _FN_i3move,
    _FN_i3bring,
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
    aes,
    ae,
    oe,
    oes,
    aa,
    aas,
    pnd,
    eur,
    endash,
    emdash,
    i3layer,
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
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_VOLD, KC_MPLY, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,          KC_DEL,
        KC_CAPS,   KC_A,    KC_S,    KC_D,  LCTL_T(KC_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,   KC_ENT,            KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT,          KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(_MAC_FN4), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_all(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_VOLD, KC_MPLY, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,   KC_BSLS,          LGUI(LALT(KC_H)),
        LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,   KC_ENT,           LGUI(LALT(KC_L)),
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT,          KC_UP,
        MO(_FN4), KC_LGUI, KC_LALT,                            LT(_spcfn,KC_SPC),                             KC_RCTL, MO(_FN4), MO(_FN_i3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_MAC_FN4] = LAYOUT_all(
        KC_WAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    RESET,          KC_VOLD, KC_MUTE, KC_VOLU,
        RGB_TOG,  KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_A),  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_BTN1,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_QUOT), LALT(KC_O),      KC_MPLY,          KC_TRNS,
        MO(_FN5),          KC_INS, KC_APP, KC_RALT, KC_TRNS, KC_TRNS, endash, emdash, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_SPC,                            MO(_rgb), MO(_rgb),  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN4] = LAYOUT_all(
        KC_WAVE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    RESET,          KC_VOLD, KC_MUTE, KC_VOLU,
        RGB_TOG,  KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, aa,  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_BTN1,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ae, oe,           KC_MPLY,          KC_TRNS,
        MO(_FN5),          KC_INS, KC_APP, KC_RALT, KC_TRNS, KC_TRNS, endash, emdash, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_SPC,                            MO(_rgb), MO(_rgb),  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN5] = LAYOUT_all(
        KC_WAVE, KC_F1,   KC_F2,   pnd,   eur,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,    RESET,          KC_VOLD, KC_MUTE, KC_VOLU,
        RGB_TOG,  KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, aas,  KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_BTN1,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, aes, oes,           KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS),

    [_gamer] = LAYOUT_all(
            KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  _______, _______,
            KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
            LCTL_T(KC_ESC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP, _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______, _______
            ),

    [_spcfn] = LAYOUT_all(
            KC_ESC,   S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),  S(KC_MINS),  S(KC_EQL),  LCTL(KC_BSPC), KC_MPRV, KC_MUTE, KC_MNXT,
            LGUI(KC_TAB),  LGUI(KC_Q), LCTL(KC_W), LCAG(KC_E), i3layer, LCTL(KC_T), OSL(_FN_i3_y), LCTL(KC_U), LCTL(KC_D), LCTL(KC_6), KC_HOME, S(KC_LBRC), S(KC_RBRC), KC_DEL, LGUI(LSFT(KC_H)),
            _______,       HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), LGUI(KC_4), LGUI(KC_5), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, LGUI(LCTL(KC_H)), LGUI(LCTL(KC_L)), LGUI(KC_ENT), LGUI(LSFT(KC_L)),
            _______,            KC_SPC, LCTL(KC_PGUP), LCTL(KC_PGDN),LALT(KC_LEFT), LALT(KC_RGHT), LCTL(KC_LEFT), LCTL(KC_RGHT), LCAG(KC_COMM), LCAG(KC_DOT), OSL(_FN_i3ws), LGUI(LALT(KC_ENT)), LGUI(LSFT(KC_UP)),
            MO(_mouse),   _______,   _______,                      KC_SPC,                              MO(_mouse),   MO(_rgb),   _______,   LGUI(LSFT(KC_LEFT)),   LGUI(LSFT(KC_DOWN)),   LGUI(LSFT(KC_RIGHT))
            ),

    [_spcfnMac] = LAYOUT_all(
            KC_ESC,   S(KC_1),    S(KC_2),    S(KC_3),    S(KC_4),    S(KC_5),    S(KC_6),    S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),  S(KC_MINS),  S(KC_EQL),  LGUI(KC_BSPC), KC_VOLD, KC_MUTE, KC_VOLU,
            LGUI(KC_B),  LALT(KC_Q), LALT(KC_W), KC_END, OSL(_FN_i3_r), LALT(KC_T), OSL(_FN_i3_y), LCTL(KC_U), LCTL(KC_D), LCTL(KC_6), KC_HOME, S(KC_LBRC), S(KC_RBRC), KC_DEL, LGUI(LSFT(KC_H)),
            _______,       LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), i3layer, OSL(_FN_i3ws), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, LGUI(LCTL(KC_H)), LGUI(LCTL(KC_L)), LGUI(KC_ENT), LGUI(LSFT(KC_L)),
            _______,            KC_SPC, LALT(S(KC_LBRC)), LALT(S(KC_RBRC)), LALT(KC_LEFT), LALT(KC_RGHT), LGUI(KC_LEFT), LGUI(KC_RGHT), LGUI(KC_H), LGUI(KC_L), OSL(_FN_i3ws), LGUI(LALT(KC_ENT)), LGUI(LSFT(KC_UP)),
            MO(_mouse),   _______,   _______,                      KC_SPC,                              MO(_mouse),   MO(_rgb),   _______,   LGUI(LSFT(KC_LEFT)),   LGUI(LSFT(KC_DOWN)),   LGUI(LSFT(KC_RIGHT))
            ),

    [_FN_i3] = LAYOUT_all(
        TO(WIN_BASE),  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_VOLD, KC_MPLY, KC_VOLU,
        KC_TAB,  LGUI(KC_F),    OSL(_FN_i3_shift),    OSL(_FN_i3bring),    OSL(_FN_i3_r),    KC_T,    KC_Y,    KC_PGUP,    KC_PGDN,    OSL(_FN_i3move),    LCAG(KC_1),    KC_LBRC,  KC_RBRC,   KC_BSLS,          LGUI(LALT(KC_H)),
        LCTL_T(KC_ESC),   LCTL(LGUI(KC_H)),    LCTL(LGUI(KC_L)),    OSL(_FN_i3_shift),    LCAG(KC_F),    LCAG(KC_G),    LGUI(KC_H),    LGUI(KC_J),    LGUI(KC_K),    LGUI(KC_L),    LAG(KC_H),  LAG(KC_L),   LGUI(KC_F),           LGUI(LALT(KC_L)),
        KC_LSFT,          LCAG(KC_Z),    LCAG(KC_X),    LCAG(KC_C),    LCAG(KC_V),    LCAG(KC_B),    LCAG(KC_N),    LCAG(KC_M),    LCAG(KC_COMM), LCAG(KC_DOT),  LCAG(KC_SLSH),             LCAG(KC_1),          LAG(KC_UP),
        MO(_FN4), KC_LGUI, KC_LALT,                            LT(_spcfn,KC_SPC),                             KC_RCTL, MO(_FN4), MO(_FN_i3), LAG(KC_LEFT), LAG(KC_DOWN), LAG(KC_RGHT)
        ),

    [_FN_i3_r] = LAYOUT_all(
        TO(WIN_BASE),  LCAG(KC_1),    LCAG(KC_2),    LCAG(KC_3),    LCAG(KC_4),    LCAG(KC_5),    LCAG(KC_6),    LCAG(KC_7),    LCAG(KC_8),    LCAG(KC_9),    LCAG(KC_0),    LCAG(KC_MINS),  LCAG(KC_EQL),    LCAG(KC_BSPC),          KC_VOLD, KC_MPLY, KC_VOLU,
        KC_TAB,  KC_Q,    LCAG(KC_W),    LCAG(KC_E),    LCAG(KC_R),    LCAG(KC_T),    LCAG(KC_Y),    LCAG(KC_U),    LCAG(KC_I),    LCAG(KC_O),    LCAG(KC_P),    LCAG(KC_LBRC),  LCAG(KC_RBRC),   LCAG(KC_BSLS),          LGUI(LALT(KC_H)),
        LCTL_T(KC_ESC),   LCAG(KC_A),    LCAG(KC_S),    LCAG(KC_D),    LCAG(KC_F),    LCAG(KC_G),    LCAG(KC_H),    LCAG(KC_J),    LCAG(KC_K),    LCAG(KC_L),    LCAG(KC_SCLN),  KC_QUOT,   KC_ENT,           LGUI(LALT(KC_L)),
        KC_LSFT,          LCAG(KC_Z),    LCAG(KC_X),    LCAG(KC_C),    LCAG(KC_V),    LCAG(KC_B),    LCAG(KC_N),    LCAG(KC_M),    LCAG(KC_COMM), LCAG(KC_DOT),  LCAG(KC_SLSH),             KC_RSFT,          LAG(KC_UP),
        _______, KC_LGUI, KC_LALT,                            LT(_spcfn,KC_SPC),                             KC_RCTL, _______, MO(_FN_i3), LAG(KC_LEFT), LAG(KC_DOWN), LAG(KC_RGHT)),

    [_FN_i3_y] = LAYOUT_all(
        TO(WIN_BASE),  HYPR(KC_1),    HYPR(KC_2),    HYPR(KC_3),    HYPR(KC_4),    HYPR(KC_5),    HYPR(KC_6),    HYPR(KC_7),    HYPR(KC_8),    HYPR(KC_9),    HYPR(KC_0),    KC_MINS,  KC_EQL,    KC_BSPC,          KC_VOLD, KC_MPLY, KC_VOLU,
        KC_TAB,  KC_Q,    HYPR(KC_W),    HYPR(KC_E),    HYPR(KC_R),    HYPR(KC_T),    HYPR(KC_Y),    HYPR(KC_U),    HYPR(KC_I),    HYPR(KC_O),    HYPR(KC_P),    HYPR(KC_LBRC),  HYPR(KC_RBRC),   HYPR(KC_BSLS),          LGUI(LALT(KC_H)),
        LCTL_T(KC_ESC),   HYPR(KC_A),    HYPR(KC_S),    HYPR(KC_D),    HYPR(KC_F),    HYPR(KC_G),    HYPR(KC_H),    HYPR(KC_J),    HYPR(KC_K),    HYPR(KC_L),    HYPR(KC_SCLN),  KC_QUOT,   KC_ENT,           LGUI(LALT(KC_L)),
        KC_LSFT,          HYPR(KC_Z),    HYPR(KC_X),    HYPR(KC_C),    HYPR(KC_V),    HYPR(KC_B),    HYPR(KC_N),    HYPR(KC_M),    HYPR(KC_COMM), HYPR(KC_DOT),  HYPR(KC_SLSH),             KC_RSFT,          KC_UP,
        _______, KC_LGUI, KC_LALT,                            LT(_spcfn,KC_SPC),                             KC_RCTL, _______, MO(_FN_i3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN_i3_shift] = LAYOUT_all(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,    KC_BSPC,          KC_VOLD, KC_MPLY, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    LCAG(KC_4),    KC_LBRC,  KC_RBRC,   KC_BSLS,          LGUI(LALT(KC_H)),
        LCTL_T(KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    LGUI(LSFT(KC_H)),    LGUI(LSFT(KC_J)),    LGUI(LSFT(KC_K)),    LGUI(LSFT(KC_L)), LGUI(LSFT(KC_SCLN)),  LGUI(LSFT(KC_QUOT)),    LGUI(KC_F),       LGUI(LALT(KC_L)),
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LGUI(LSFT(KC_N)),    LGUI(LSFT(KC_M)),    LGUI(LSFT(KC_COMM)), LGUI(LSFT(KC_DOT)),  LGUI(LSFT(KC_SLSH)),             LCAG(KC_4),          LGUI(LALT(LSFT(KC_UP))),
        _______, KC_LGUI, KC_LALT,                            LT(_spcfn,KC_SPC),                             KC_RCTL, _______, MO(_FN_i3), LGUI(LALT(LSFT(KC_LEFT))), LGUI(LALT(LSFT(KC_DOWN))), LGUI(LALT(LSFT(KC_RGHT)))
        ),

    [_rgb] = LAYOUT_all(
            RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_MUTE, KC_VOLU,
            _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,
            _______,       RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            qwerty, _______, gamer,                      _______,                              _______,   _______,   _______,   _______,   _______,   _______
            ),

    [_mouse] = LAYOUT_all(
            KC_ESC,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______, KC_VOLD, KC_MUTE, KC_VOLU,
            _______,     KC_BTN1, KC_MS_UP, KC_BTN2, KC_WH_U, KC_WH_L, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            KC_BTN1,       KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______, _______, _______,
            _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
            _______,   _______,   _______,                      KC_SPC,                              _______,   _______,   _______,   _______,   _______,   _______
            ),

    [_FN_i3ws] = LAYOUT_all(
            KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______, _______,  _______, _______, _______,  _______, _______,
            KC_TAB, _______, _______, _______, LGUI(KC_EQL), _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
            LCTL_T(KC_ESC), LGUI(KC_1),    LGUI(KC_2),    LGUI(KC_3),    LGUI(KC_4),    LGUI(KC_5),    LGUI(KC_6),    LGUI(KC_7),    LGUI(KC_8),  LGUI(KC_9), LGUI(KC_0), LGUI(KC_MINS),  _______, _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_UP, _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______, _______
            ),

    [_FN_i3move] = LAYOUT_all(
            KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______, _______,  _______, _______, _______,  _______, _______,
            LSG(KC_B),  KC_Q,    KC_W,    KC_E,    LSG(KC_EQL),    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    LCAG(KC_3),    KC_LBRC,  KC_RBRC,   KC_BSLS,          LGUI(LALT(KC_H)),
            LCTL_T(KC_ESC), LSG(KC_1),    LSG(KC_2),    LSG(KC_3),    LSG(KC_4),    LSG(KC_5),    LSG(KC_6),    LSG(KC_7),    LSG(KC_8),    LSG(KC_9), LSG(KC_0), LSG(KC_MINS),          _______, _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          LCAG(KC_3), _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______, _______
            ),

    [_FN_i3bring] = LAYOUT_all(
            KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, _______, _______,  _______, _______, _______,  _______, _______,
            LAG(KC_B),  KC_Q,    KC_W,    KC_E,    LAG(KC_EQL),    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    LCAG(KC_2),    KC_LBRC,  KC_RBRC,   KC_BSLS,          LGUI(LALT(KC_H)),
            LCTL_T(KC_ESC), LAG(KC_1),    LAG(KC_2),    LAG(KC_3),    LAG(KC_4),    LAG(KC_5),    LAG(KC_6),    LAG(KC_7),    LAG(KC_8),    LAG(KC_9), LAG(KC_0), LAG(KC_MINS),          _______, _______,
            KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          LCAG(KC_2), _______,
            KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPACE,                            KC_RALT, MO(_rgb), _______, _______, _______, _______
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
                    layer_on(WIN_BASE);
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
                    layer_on(WIN_BASE);
                }
                break;
            case LCTL_T(KC_ESC):
                if (record->event.pressed) {							//When key is pressed
                    i3_bool = false;
                    i3_returnlayer = false;
                    layer_clear();
                    layer_on(WIN_BASE);
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
            /* case _colemak: */
            /*     rgb_matrix_set_color(58, 0xFF, 0xFF, 0xFF); */
            /*     break; */
            case _gamer:
                rgb_matrix_set_color(17, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(31, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(32, 0xFF, 0x00, 0xFF);
                rgb_matrix_set_color(33, 0xFF, 0x00, 0xFF);
                break;
        }
    }
}
