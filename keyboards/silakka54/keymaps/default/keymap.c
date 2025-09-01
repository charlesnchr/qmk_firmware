// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

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
#define LT2GV LT(2, KC_GRV)
#define CESCP LCTL_T(KC_ESC)
#define SAFTA LSFT_T(KC_A)
#define SALTS LALT_T(KC_S)
#define LGUID LGUI_T(KC_D)
#define LCTLX LCTL_T(KC_X)
#define LT7F_ LT(7, KC_F)
#define LT5SC LT(5, KC_SCLN)
#define LT5I_ LT(5, KC_I)
#define LT5O_ LT(5, KC_O)
#define SFTZC LSFT_T(KC_Z)
#define LT5VC LT(5, KC_V)
#define RALTN RALT_T(KC_N)
#define LALTM LALT_T(KC_M)
#define RGUIC RGUI_T(KC_COMM)
#define RCTLD RCTL_T(KC_DOT)
#define RSFTS RSFT_T(KC_SLSH)
#define LCTLR LCTL_T(KC_RBRC)
#define ALTMN LALT_T(KC_MINS)
#define LT2SP LT(2, KC_SPC)
#define LT5SP LT(5, KC_SPC)
#define LT4EN LT(4, KC_ENT)

// Standard key shortcuts
#define ESC__ KC_ESC
#define TAB__ KC_TAB
#define LCTL_ KC_LCTL
#define LSFT_ KC_LSFT
#define LGUI_ KC_LGUI
#define LALT_ KC_LALT
#define SPC__ KC_SPC
#define BSPC_ KC_BSPC
#define ENT__ KC_ENT
#define DEL__ KC_DEL
#define MINS_ KC_MINS
#define EQL__ KC_EQL
#define LBRC_ KC_LBRC
#define RBRC_ KC_RBRC
#define BSLS_ KC_BSLS
#define SCLN_ KC_SCLN
#define QUOT_ KC_QUOT
#define GRV__ KC_GRV
#define COMM_ KC_COMM
#define DOT__ KC_DOT
#define SLSH_ KC_SLSH

// Numbers and letters
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
#define MNXT_ KC_MNXT
#define MPRV_ KC_MPRV

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

// Shifted keys
#define RGUI_ KC_RGUI
#define RSFT_ KC_RSFT

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

// Layer access
#define LT7A_ LT(7, KC_A)    // Layer tap 7 on A key

// Nordic characters (lowercase and uppercase)
#define OE_LC RCMD(RCTL(RSFT(KC_QUOT))) // ø
#define AE_LC RCMD(RCTL(RSFT(KC_SCLN))) // æ
#define AA_LC RCMD(RCTL(RSFT(KC_LBRC))) //
#define OE_UC RCMD(RCTL(RSFT(LSFT(KC_QUOT))))     // Ä (ae uppercase - Option+u)
#define AE_UC RCMD(RCTL(RSFT(LSFT(KC_SCLN))))  // Ø (oe uppercase - Option+slash)
#define AA_UC RCMD(RCTL(RSFT(LSFT(KC_LBRC))))  // Å (aa uppercase - Option+[)

// Layer momentary for uppercase Nordic chars
#define MO8__ MO(8)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: Base (QWERTY)
    [0] = LAYOUT(
        LT2GV, NUM1_, NUM2_, NUM3_, NUM4_, NUM5_,                               NUM6_, NUM7_, NUM8_, NUM9_, NUM0_, DEL__,
        TAB__, Q____, W____, E____, R____, T____,                               Y____, U____, LT5I_, LT5O_, P____, LBRC_,
        CESCP, LT7A_, SALTS, LGUID, LT7F_, G____,                               H____, J____, K____, L____, LT5SC, QUOT_,
        LSFT_, SFTZC, LCTLX, C____, LT5VC, B____,                               RALTN, LALTM, RGUIC, RCTLD, RSFTS, LCTLR,
                                     LGUI_, ALTMN, LT2SP,             LT5SP, BSPC_, LT4EN
    ),
    // Layer 1: Gamer
    [1] = LAYOUT(
        ESC__, NUM1_, NUM2_, NUM3_, NUM4_, NUM5_,                               NUM6_, NUM7_, NUM8_, NUM9_, NUM0_, MINS_,
        TAB__, Q____, W____, E____, R____, T____,                               Y____, U____, I____, O____, P____, BSPC_,
        LCTL_, A____, S____, D____, F____, G____,                               H____, J____, K____, L____, SCLN_, QUOT_,
        LSFT_, Z____, X____, C____, V____, B____,                               N____, M____, COMM_, DOT__, SLSH_, RSFT_,
                                     MO2__, LALT_, SPC__,             RGUI_, _____, _____
    ),
    // Layer 2: Function/Navigation
    [2] = LAYOUT(
        GRV__, F1___, F2___, F3___, F4___, F5___,                               F6___, F7___, F8___, F9___, F10__, DEL__,
        ENT__, HOME_, UP___, END__, VOLU_, MNXT_,                               PGUP_, PGDN_, HOME_, END__, F11__, F12__,
        MO3__, LEFT_, DOWN_, RGHT_, VOLD_, MPRV_,                               LEFT_, DOWN_, UP___, RGHT_, LBRC_, RBRC_,
        _____, _____, _____, _____, EQL__, PLUS_,                               _____, _____, _____, _____, BSLS_, _____,
                                     _____, _____, _____,             _____, _____, _____
    ),
    // Layer 3: Numpad
    [3] = LAYOUT(
        _____, FN1__, FN2__, FN3__, FN4__, FN5__,                               FN6__, FN7__, FN8__, FN9__, FN10_, MO6__,
        _____, NUM7_, NUM8_, NUM9_, _____, _____,                               _____, _____, _____, _____, FN11_, FN12_,
        _____, NUM4_, NUM5_, NUM6_, NUM0_, _____,                               _____, _____, _____, _____, _____, _____,
        _____, NUM1_, NUM2_, NUM3_, _____, _____,                               _____, _____, _____, _____, _____, _____,
                                     _____, _____, _____,             _____, _____, _____
    ),
    // Layer 4: Mouse/Navigation/Mac Function Keys
    [4] = LAYOUT(
        _____, FN1__, FN2__, FN3__, FN4__, FN5__,                               FN6__, FN7__, FN8__, FN9__, FN10_, MO6__,
        _____, HOME_, UP___, END__, _____, _____,                               _____, HOME_, UP___, END__, FN11_, FN12_,
        _____, LEFT_, DOWN_, RGHT_, _____, _____,                               PGUP_, LEFT_, DOWN_, RGHT_, PGDN_, _____,
        _____, _____, _____, _____, _____, _____,                               _____, _____, _____, _____, _____, _____,
                                     _____, _____, _____,             _____, _____, _____
    ),
    // Layer 5: Programming Symbols/Numbers (Python-focused)
    [5] = LAYOUT(
        _____, _____, _____, ASTR_, AMPR_, CARET,                               _____, _____, _____, _____, _____, MO6__,
        LCBR_, RCBR_, LPRN_, RPRN_, LBRC_, RBRC_,                               RGHT_, NUM7_, NUM8_, NUM9_, DEL__, F12__,
        QUES_, PIPE_, COLN_, MINS_, UNDS_, BSPC_,                               LEFT_, NUM4_, NUM5_, NUM6_, LBRC_, RBRC_,
        BSLS_, SLSH_, LT___, GT___, EQL__, PLUS_,                               NUM0_, NUM1_, NUM2_, NUM3_, BSLS_, _____,
                                     _____, _____, _____,             NUM0_, _____, _____
    ),
    // Layer 6: Adjust/Reset
    [6] = LAYOUT(
        BOOT_, _____, _____, _____, _____, _____,                               _____, _____, _____, _____, _____, _____,
        _____, _____, MSUP_, BTN2_, WHU__, WHL__,                               _____, _____, _____, _____, _____, _____,
        BTN1_, MSLT_, MSDN_, MSRT_, WHD__, WHR__,                               _____, _____, _____, _____, _____, _____,
        _____, _____, _____, _____, _____, _____,                               QWERT, GAMR_, _____, _____, _____, _____,
                                     _____, _____, _____,             _____, _____, _____
    ),

    // Layer 7: Programming Symbols (Right Side) - Python-focused, accessed via layer tap on A
    [7] = LAYOUT(
        _____, _____, _____, _____, _____, _____,                               CARET, AMPR_, ASTR_, AE_LC, OE_LC, AA_LC,
        _____, _____, _____, _____, _____, _____,                               LBRC_, RBRC_, LPRN_, RPRN_, LCBR_, RCBR_,
        _____, _____, _____, _____, _____, _____,                               _____, UNDS_, MINS_, COLN_, PIPE_, QUES_,
        MO8__, _____, _____, _____, _____, _____,                               PLUS_, EQL__, GT___, LT___, SLSH_, BSLS_,
                                     _____, _____, _____,             _____, _____, _____
    ),

    // Layer 8: Uppercase Nordic Characters - accessed via MO(8) on layer 7
    [8] = LAYOUT(
        _____, _____, _____, _____, _____, _____,                               CARET, AMPR_, ASTR_, AE_UC, OE_UC, AA_UC,
        _____, _____, _____, _____, _____, _____,                               LBRC_, RBRC_, LPRN_, RPRN_, LCBR_, RCBR_,
        _____, _____, _____, _____, _____, _____,                               _____, UNDS_, MINS_, COLN_, PIPE_, QUES_,
        _____, _____, _____, _____, _____, _____,                               PLUS_, EQL__, GT___, LT___, SLSH_, BSLS_,
                                     _____, _____, _____,             _____, _____, _____
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
