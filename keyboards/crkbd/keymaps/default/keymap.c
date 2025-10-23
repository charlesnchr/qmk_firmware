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

// Custom keycodes
enum custom_keycodes {
    qwerty = SAFE_RANGE,
    gamer,
};

// Readability macros - Keep all keys 5 chars or less
#define XXXXX KC_NO
#define _____ KC_TRNS

// Layer tap macros
#define CESCP LCTL_T(KC_ESC)
#define SAFTA LSFT_T(KC_A)
#define SALTS LALT_T(KC_S)
#define LGUID LGUI_T(KC_D)
#define LCTLF LCTL_T(KC_F)
#define SFTZC LSFT_T(KC_Z)
#define LALTX LALT_T(KC_X)
#define RALTN RALT_T(KC_N)
#define LALTM LALT_T(KC_M)
#define RGUIC RGUI_T(KC_COMM)
#define RCTLD RCTL_T(KC_DOT)
#define RSFTS RSFT_T(KC_SLSH)
#define RSFTE RSFT_T(KC_ENT)
#define LT2MN LT(2, KC_MINS)
#define LT6SP LT(6, KC_SPC)
#define LGUSP LGUI_T(KC_SPC)
#define LT3BR LT(3, KC_LBRC)
#define LT5BR LT(5, KC_RBRC)
#define LCTSC LCTL_T(KC_SCLN)
#define LT7A_ LT(7, KC_A)

// Standard key shortcuts
#define TAB__ KC_TAB
#define ESC__ KC_ESC
#define SPC__ KC_SPC
#define BSPC_ KC_BSPC
#define ENT__ KC_ENT
#define DEL__ KC_DEL
#define MINS_ KC_MINS
#define LBRC_ KC_LBRC
#define RBRC_ KC_RBRC
#define SCLN_ KC_SCLN
#define QUOT_ KC_QUOT
#define COMM_ KC_COMM
#define DOT__ KC_DOT
#define SLSH_ KC_SLSH
#define GRV__ KC_GRV

// Numbers
#define NUM1_ KC_1
#define NUM2_ KC_2
#define NUM3_ KC_3
#define NUM4_ KC_4
#define NUM5_ KC_5
#define NUM6_ KC_6
#define NUM7_ KC_7
#define NUM8_ KC_8
#define NUM9_ KC_9
#define NUM0_ KC_0

// Arrow keys and navigation
#define UP___ KC_UP
#define DOWN_ KC_DOWN
#define LEFT_ KC_LEFT
#define RGHT_ KC_RGHT
#define HOME_ KC_HOME
#define END__ KC_END
#define PGUP_ KC_PGUP
#define PGDN_ KC_PGDN

// Function keys
#define F1___ KC_F1
#define F2___ KC_F2
#define F3___ KC_F3
#define F4___ KC_F4
#define F5___ KC_F5
#define F6___ KC_F6
#define F7___ KC_F7
#define F8___ KC_F8
#define F9___ KC_F9
#define F10__ KC_F10
#define F11__ KC_F11
#define F12__ KC_F12

// Media keys
#define VOLU_ KC_VOLU
#define VOLD_ KC_VOLD
#define MUTE_ KC_MUTE
#define MNXT_ KC_MNXT
#define MPRV_ KC_MPRV
#define MPLY_ KC_MPLY

// Mouse keys
#define BTN1_ KC_BTN1
#define BTN2_ KC_BTN2
#define MSUP_ KC_MS_UP
#define MSDN_ KC_MS_DOWN
#define MSLT_ KC_MS_LEFT
#define MSRT_ KC_MS_RIGHT
#define WHU__ KC_WH_U
#define WHD__ KC_WH_D
#define WHL__ KC_WH_L
#define WHR__ KC_WH_R

// Layer momentary switches
#define MO2__ MO(2)
#define MO3__ MO(3)
#define MO6__ MO(6)
#define MO7__ MO(7)
#define MO8__ MO(8)

// Special keys
#define BOOT_ QK_BOOT
#define QWERT qwerty
#define GAMR_ gamer

// Letter keys
#define Q____ KC_Q
#define W____ KC_W
#define E____ KC_E
#define R____ KC_R
#define T____ KC_T
#define Y____ KC_Y
#define U____ KC_U
#define I____ KC_I
#define O____ KC_O
#define P____ KC_P
#define A____ KC_A
#define S____ KC_S
#define D____ KC_D
#define F____ KC_F
#define G____ KC_G
#define H____ KC_H
#define J____ KC_J
#define K____ KC_K
#define L____ KC_L
#define Z____ KC_Z
#define X____ KC_X
#define C____ KC_C
#define V____ KC_V
#define B____ KC_B
#define N____ KC_N
#define M____ KC_M

// Modifiers
#define LGUI_ KC_LGUI
#define LCTL_ KC_LCTL
#define LSFT_ KC_LSFT
#define LALT_ KC_LALT

// Mac function key triggers - RCmd+RCtrl+RShift+key (Karabiner maps these to Fn+F keys)
#define FN1__ RCMD(RCTL(RSFT(KC_1)))  // Triggers Fn+F1 via Karabiner
#define FN2__ RCMD(RCTL(RSFT(KC_2)))  // Triggers Fn+F2 via Karabiner
#define FN3__ RCMD(RCTL(RSFT(KC_3)))  // Triggers Fn+F3 via Karabiner
#define FN4__ RCMD(RCTL(RSFT(KC_4)))  // Triggers Fn+F4 via Karabiner
#define FN5__ RCMD(RCTL(RSFT(KC_5)))  // Triggers Fn+F5 via Karabiner
#define FN6__ RCMD(RCTL(RSFT(KC_6)))  // Triggers Fn+F6 via Karabiner
#define FN7__ RCMD(RCTL(RSFT(KC_7)))  // Triggers Fn+F7 via Karabiner
#define FN8__ RCMD(RCTL(RSFT(KC_8)))  // Triggers Fn+F8 via Karabiner
#define FN9__ RCMD(RCTL(RSFT(KC_9)))  // Triggers Fn+F9 via Karabiner
#define FN10_ RCMD(RCTL(RSFT(KC_0)))  // Triggers Fn+F10 via Karabiner
#define FN11_ RCMD(RCTL(RSFT(KC_MINS))) // Triggers Fn+F11 via Karabiner
#define FN12_ RCMD(RCTL(RSFT(KC_EQL)))  // Triggers Fn+F12 via Karabiner

// Programming symbols - Python-focused layout
#define EXCL_ LSFT(KC_1)     // !
#define AT___ LSFT(KC_2)     // @
#define HASH_ LSFT(KC_3)     // #
#define DOLR_ LSFT(KC_4)     // $
#define PERC_ LSFT(KC_5)     // %
#define CARET LSFT(KC_6)     // ^
#define AMPR_ LSFT(KC_7)     // &
#define ASTR_ LSFT(KC_8)     // *
#define LPRN_ LSFT(KC_9)     // (
#define RPRN_ LSFT(KC_0)     // )
#define LCBR_ LSFT(KC_LBRC)  // {
#define RCBR_ LSFT(KC_RBRC)  // }
#define LT___ LSFT(KC_COMM)  // <
#define GT___ LSFT(KC_DOT)   // >
#define PIPE_ LSFT(KC_BSLS)  // |
#define QUES_ LSFT(KC_SLSH)  // ?
#define UNDS_ LSFT(KC_MINS)  // _
#define PLUS_ LSFT(KC_EQL)   // +
#define TILD_ LSFT(KC_GRV)   // ~
#define COLN_ LSFT(KC_SCLN)  // : (important for Python)
#define BSLS_ KC_BSLS
#define EQL__ KC_EQL

// Nordic characters (lowercase and uppercase) - Karabiner mappings
#define OE_LC RCMD(RCTL(RSFT(KC_QUOT))) // ø
#define AE_LC RCMD(RCTL(RSFT(KC_SCLN))) // æ
#define AA_LC RCMD(RCTL(RSFT(KC_LBRC))) // å
#define OE_UC RCMD(RCTL(RSFT(LSFT(KC_QUOT))))  // Ø
#define AE_UC RCMD(RCTL(RSFT(LSFT(KC_SCLN))))  // Æ
#define AA_UC RCMD(RCTL(RSFT(LSFT(KC_LBRC))))  // Å

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Base (QWERTY) with home row mods
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TAB__, Q____, W____, E____, R____, T____,                               Y____, U____, I____, O____, P____, BSPC_,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       CESCP, LT7A_, SALTS, LGUID, LCTLF, G____,                               H____, J____, K____, L____, LCTSC, QUOT_,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LSFT_, SFTZC, LALTX, C____, V____, B____,                               RALTN, LALTM, RGUIC, RCTLD, RSFTS, RSFTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  LGUI_, LT2MN, LT6SP,                 LGUSP, LT3BR, LT5BR
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 1: Gamer mode (no home row mods for gaming)
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TAB__, Q____, W____, E____, R____, T____,                               Y____, U____, I____, O____, P____, BSPC_,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LCTL_, A____, S____, D____, F____, G____,                               H____, J____, K____, L____, SCLN_, QUOT_,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LSFT_, Z____, X____, C____, V____, B____,                               N____, M____, COMM_, DOT__, SLSH_, RSFTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  MO2__, LALT_, SPC__,                 LGUI_, _____, _____
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 2: Numbers and Symbols
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       GRV__, EXCL_, AT___, HASH_, DOLR_, PERC_,                               CARET, AMPR_, ASTR_, UNDS_, PLUS_, DEL__,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       F5___, LCTL(KC_6), XXXXX, MINS_, UNDS_, CARET,                          AMPR_, NUM4_, NUM5_, NUM6_, NUM0_, EQL__,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MO3__, MO3__, XXXXX, EQL__, PLUS_, ASTR_,                               PIPE_, NUM1_, NUM2_, NUM3_, BSLS_, _____,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _____, _____, _____,                 NUM0_, LPRN_, RPRN_
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 3: Function Keys and Numbers
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TILD_, F1___, F2___, F3___, F4___, F5___,                               F6___, F7___, F8___, F9___, F10__, DEL__,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_CAPS, NUM1_, NUM2_, NUM3_, NUM4_, NUM5_,                             NUM6_, NUM7_, NUM8_, NUM9_, NUM0_, DEL__,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _____, BSLS_, QK_LOCK, XXXXX, EQL__, PLUS_,                             F11__, F12__, PIPE_, XXXXX, XXXXX, _____,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _____, MO4__, _____,                 _____, _____, NUM0_
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 4: Mac Function Keys via Karabiner
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       BOOT_, FN1__, FN2__, FN3__, FN4__, FN5__,                               FN6__, FN7__, FN8__, FN9__, FN10_, XXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXX, XXXXX,                       XXXXX, XXXXX, XXXXX, XXXXX, FN11_, FN12_,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXX, XXXXX,                       XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _____, _____, _____,                 _____, _____, _____
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 5: Mouse and Navigation
    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       ESC__, XXXXX, MSUP_, BTN2_, WHU__, WHL__,                               XXXXX, HOME_, UP___, END__, XXXXX, XXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       BTN1_, MSLT_, MSDN_, MSRT_, WHD__, WHR__,                               PGUP_, LEFT_, DOWN_, RGHT_, PGDN_, XXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MO7__, MO7__, LGUI(KC_F1), LGUI(KC_F2), LGUI(KC_F3), LGUI(KC_F4),       XXXXX, QWERT, GAMR_, XXXXX, XXXXX, XXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _____, _____, _____,                 NUM0_, _____, _____
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 6: Media and Advanced Navigation
    [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       LALT(KC_TAB), HOME_, UP___, END__, VOLU_, MNXT_,                        Y____, U____, I____, O____, P____, LCTL(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LCAG(KC_ESC), LEFT_, DOWN_, RGHT_, VOLD_, MPRV_,                        LEFT_, DOWN_, UP___, RGHT_, XXXXX, XXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _____, LSFT_T(KC_INS), LCAG(KC_X), LCAG(KC_C), MUTE_, MPLY_,            LCTL(KC_LEFT), LCTL(KC_RGHT), HOME_, END__, RSFT_T(KC_F4), RSFTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _____, MO1__, _____,                 _____, KC_RALT, XXXXX
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 7: Programming Symbols (Python-focused) with Nordic characters
    [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _____, _____, _____, _____, _____, _____,                               CARET, AMPR_, ASTR_, AE_LC, OE_LC, AA_LC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _____, _____, _____, _____, _____, _____,                               LBRC_, RBRC_, LPRN_, RPRN_, LCBR_, RCBR_,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       MO8__, _____, _____, _____, _____, _____,                               PLUS_, EQL__, GT___, LT___, COLN_, QUES_,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _____, _____, _____,                 _____, UNDS_, PIPE_
                                      //`--------------------------'  `--------------------------'
    ),

    // Layer 8: Uppercase Nordic Characters
    [8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _____, _____, _____, _____, _____, _____,                               CARET, AMPR_, ASTR_, AE_UC, OE_UC, AA_UC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _____, _____, _____, _____, _____, _____,                               LBRC_, RBRC_, LPRN_, RPRN_, LCBR_, RCBR_,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _____, _____, _____, _____, _____, _____,                               PLUS_, EQL__, GT___, LT___, COLN_, QUES_,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                  _____, _____, _____,                 _____, UNDS_, PIPE_
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
        oled_render_logo();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
