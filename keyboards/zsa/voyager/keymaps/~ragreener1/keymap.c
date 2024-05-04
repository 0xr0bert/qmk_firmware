// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_extras/keymap_us_international.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  US_1,    US_2,    US_3,    US_4,    US_5,                         US_6,    US_7,    US_8,    US_9,    US_0,    US_MINS,
        CW_TOGG, US_Q,    US_W,    US_F,    US_P,    US_B,                         US_J,    US_L,    US_U,    US_Y, US_SCLN,     US_EQL,
        KC_BSPC, US_A,    US_R,    US_S,    US_T,    US_G,                         US_M,    US_N,    US_E,    US_I,    US_O,    US_ACUT,
        US_BSLS,GUI_T(US_Z),ALT_T(US_X),CTL_T(US_C),SFT_T(US_D),    US_V,                         US_K,SFT_T(US_H),CTL_T(US_COMM),ALGR_T(US_DOT),GUI_T(US_SLSH),US_DGRV,
                                    LT(1,KC_SPC),  KC_TAB,                         KC_DEL, LT(2,KC_ENT)
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_CAPS, US_EXLM, US_AT,   US_HASH, US_DLR,  US_PERC,                      US_7,    US_8,    US_9,    US_MINS, US_SLSH, KC_F12,
        KC_LALT, US_DCIR, US_AMPR, US_ASTR, US_LPRN, US_RPRN,                      US_4,    US_5,    US_6,    US_PLUS, US_ASTR, KC_BSPC,
        KC_LCTL, KC_LSFT, US_LBRC, KC_RBRC, US_LCBR, US_RCBR,                      US_1,    US_2,    US_3,    US_DOT,  US_EQL,  KC_ENT,
                                                     _______, KC_LGUI,    KC_ALGR, US_0
    ),
    [2] = LAYOUT(
        RGB_TOG, QK_KB,   RGB_MOD, RGB_M_P, RGB_VAD, RGB_VAI,                      _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, C(S(KC_TAB)), C(KC_TAB), _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
};
