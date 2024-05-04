/* Copyright 2024 Robert Greener <dev at greener dot sh>
 * Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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

#include "keymap_extras/keymap_us_international.h"

enum layers {
    BASE,  // default layer
    QWERTY, // QWERTY for gaming
    SYMB,  // symbols
    SYS, // nav + media
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  US_1,    US_2,    US_3,    US_4,    US_5, XXXXXXX,                XXXXXXX, US_6,    US_7,    US_8,    US_9,    US_0,    US_MINS,
        CW_TOGG, US_Q,    US_W,    US_F,    US_P,    US_B, XXXXXXX,                XXXXXXX, US_J,    US_L,    US_U,    US_Y, US_SCLN,     US_EQL,
        KC_BSPC, US_A,    US_R,    US_S,    US_T,    US_G, XXXXXXX,                XXXXXXX, US_M,    US_N,    US_E,    US_I,    US_O,    US_ACUT,
        US_BSLS,GUI_T(US_Z),ALT_T(US_X),CTL_T(US_C),SFT_T(US_D),US_V,              US_K,SFT_T(US_H),CTL_T(US_COMM),ALGR_T(US_DOT),GUI_T(US_SLSH),US_DGRV,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    LT(SYMB,KC_SPC),  KC_TAB, XXXXXXX,                XXXXXXX, KC_DEL, LT(SYS,KC_ENT)
    ),

    [QWERTY] = LAYOUT(
        KC_ESC,  US_1,    US_2,    US_3,    US_4,    US_5, XXXXXXX,                KC_CAPS, US_6,    US_7,    US_8,    US_9,    US_0, XXXXXXX,
        KC_TAB,  US_Q,    US_W,    US_E,    US_R,    US_T, US_MINS,                US_LBRC, US_Y,    US_U,    US_I,    US_O,    US_P, US_SLSH,
        KC_BSPC, US_A,    US_S,    US_D,    US_F,    US_G,  US_EQL,                US_RBRC, US_H,    US_J,    US_K,    US_L, US_SCLN, US_ACUT,
        KC_LSFT, US_Z,    US_X,    US_C,    US_V, XXXXXXX,                                  US_B,    US_N,    US_M, US_COMM,  US_DOT, KC_RSFT,
        KC_LCTL, KC_LALT, XXXXXXX, US_BSLS, US_DGRV, KC_LGUI,                            KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, KC_LCTL,
                                             KC_SPC, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, KC_ENT
    ),

    [SYMB] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,              _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_CAPS, US_EXLM, US_AT,   US_HASH, US_DLR,  US_PERC, _______,            _______, US_7,    US_8,    US_9,    US_MINS, US_SLSH, KC_F12,
        KC_LALT, US_DCIR, US_AMPR, US_ASTR, US_LPRN, US_RPRN, _______,            _______, US_4,    US_5,    US_6,    US_PLUS, US_ASTR, KC_BSPC,
        KC_LCTL, KC_LSFT, US_LBRC, KC_RBRC, US_LCBR, US_RCBR,                              US_1,    US_2,    US_3,    US_DOT,  US_EQL,  KC_ENT,
        _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
                                            _______, KC_LGUI, _______,            _______, KC_ALGR, US_0
    ),

    [SYS] = LAYOUT(
        RGB_TOG, QK_KB,   RGB_MOD, RGB_M_P, RGB_VAD, RGB_VAI, _______,            _______,  _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,            _______,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______, _______,            _______,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                             C(S(KC_TAB)), C(KC_TAB), _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,            _______, _______, _______,
    ),
};

const uint16_t PROGMEM combo0[] = { US_4, US_5, US_6, US_7, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo0, TG(QWERTY)),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


#define RGB_RDC {255, 0, 0}
#define RGB_IND {0x61, 0, 0xFF}
#define RGB_BRN {0, 240, 255}
#define RGB_WTR {0, 14, 255}
#define RGB_NGT {0, 5, 84}
#define RGB_YLW {0xFF, 0xF5, 0}
#define RGB_BLK {0, 0, 0}
#define RGB_SPK {0, 0x75, 0xFF}
#define RGB_FFA {0xFF, 0x00, 0x8A}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [SYMB] = {
        // left col 1
        RGB_RDC, RGB_IND, RGB_NGT, RGB_NGT, RGB_BLK,
        // left col 2
        RGB_RDC, RGB_IND, RGB_IND, RGB_NGT, RGB_BLK,
        // left col 3
        RGB_RDC, RGB_IND, RGB_IND, RGB_YLW, RGB_BLK,
        // left col 4
        RGB_RDC, RGB_IND, RGB_IND, RGB_YLW, RGB_BLK,
        // left col 5
        RGB_RDC, RGB_IND, RGB_YLW, RGB_YLW, RGB_BLK,
        // left col 6
        RGB_RDC, RGB_IND, RGB_YLW, RGB_YLW,
        // left col 7
        RGB_BLK, RGB_BLK, RGB_BLK,
        // left thumb
        RGB_RDC, RGB_NGT, RGB_BLK, RGB_BLK,
        // right col 7
        RGB_RDC, RGB_RDC, RGB_NGT, RGB_WTR, RGB_BLK,
        // right col 6
        RGB_RDC, RGB_WTR, RGB_WTR, RGB_WTR, RGB_BLK,
        // right col 5
        RGB_RDC, RGB_WTR, RGB_WTR, RGB_WTR, RGB_BLK,
        // right col 4
        RGB_RDC, RGB_BRN, RGB_BRN, RGB_BRN, RGB_BLK,
        // right col 3
        RGB_RDC, RGB_BRN, RGB_BRN, RGB_BRN, RGB_BLK,
        // right col 2
        RGB_RDC, RGB_BRN, RGB_BRN, RGB_BRN,
        // right col 1
        RGB_BLK, RGB_BLK, RGB_BLK,
        // right thumb
        RGB_BRN, RGB_NGT, RGB_BLK, RGB_BLK
    },
    [SYS] = {
        // left col 1
        RGB_YLW, RGB_BLK, RGB_BLK, RGB_BLK, RGB_BLK,
        // left col 2
        RGB_YLW, RGB_BLK, RGB_BRN, RGB_BLK, RGB_BLK,
        // left col 3
        RGB_YLW, RGB_SPK, RGB_BRN, RGB_BLK, RGB_BLK,
        // left col 4
        RGB_YLW, RGB_SPK, RGB_BRN, RGB_BLK, RGB_BLK,
        // left col 5
        RGB_YLW, RGB_SPK, RGB_BRN, RGB_BLK, RGB_BLK,
        // left col 6
        RGB_YLW, RGB_BLK, RGB_BLK, RGB_BLK,
        // left col 7
        RGB_BLK, RGB_BLK, RGB_BLK,
        // left thumb
        RGB_BLK, RGB_BLK, RGB_BLK, RGB_BLK,
        // right col 7
        RGB_RDC, RGB_BLK, RGB_BLK, RGB_BLK, RGB_BLK,
        // right col 6
        RGB_BLK, RGB_BLK, RGB_BLK, RGB_BLK, RGB_BLK,
        // right col 5
        RGB_BLK, RGB_YLW, RGB_SPK, RGB_BLK, RGB_BLK,
        // right col 4
        RGB_BLK, RGB_YLW, RGB_SPK, RGB_FFA, RGB_BLK,
        // right col 3
        RGB_BLK, RGB_YLW, RGB_SPK, RGB_FFA, RGB_BLK,
        // right col 2
        RGB_BLK, RGB_YLW, RGB_YLW, RGB_BLK,
        // right col 1
        RGB_BLK, RGB_BLK, RGB_BLK,
        // right thumb
        RGB_RDC, RGB_BLK, RGB_BLK, RGB_BLK
    }
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!rgb.r && !rgb.g && !rgb.b) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case SYMB:
      set_layer_color(SYMB);
      break;
    case SYS:
      set_layer_color(SYS);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}