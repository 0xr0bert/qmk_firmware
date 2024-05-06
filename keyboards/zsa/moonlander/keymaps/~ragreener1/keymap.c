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

#include "keymap_extras/keymap_uk.h"

enum layers {
    BASE,  // default layer
    QWERTY, // QWERTY for gaming
    SYMB,  // symbols
    SYS, // nav + media
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5, XXXXXXX,                XXXXXXX, UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    UK_MINS,
        CW_TOGG, UK_Q,    UK_W,    UK_F,    UK_P,    UK_B, XXXXXXX,                XXXXXXX, UK_J,    UK_L,    UK_U,    UK_Y, UK_SCLN,     UK_EQL,
        KC_BSPC, UK_A,    UK_R,    UK_S,    UK_T,    UK_G, XXXXXXX,                XXXXXXX, UK_M,    UK_N,    UK_E,    UK_I,    UK_O,    UK_QUOT,
        UK_BSLS,GUI_T(UK_Z),ALT_T(UK_X),CTL_T(UK_C),SFT_T(UK_D),UK_V,              UK_K,SFT_T(UK_H),CTL_T(UK_COMM),ALGR_T(UK_DOT),GUI_T(UK_SLSH),UK_HASH,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    LT(SYMB,KC_SPC),  KC_TAB, XXXXXXX,                XXXXXXX, KC_DEL, LT(SYS,KC_ENT)
    ),

    [QWERTY] = LAYOUT(
        KC_ESC,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5, XXXXXXX,                KC_CAPS, UK_6,    UK_7,    UK_8,    UK_9,    UK_0, XXXXXXX,
        KC_TAB,  UK_Q,    UK_W,    UK_E,    UK_R,    UK_T, UK_MINS,                UK_LBRC, UK_Y,    UK_U,    UK_I,    UK_O,    UK_P, UK_SLSH,
        KC_BSPC, UK_A,    UK_S,    UK_D,    UK_F,    UK_G,  UK_EQL,                UK_RBRC, UK_H,    UK_J,    UK_K,    UK_L, UK_SCLN, UK_QUOT,
        KC_LSFT, UK_Z,    UK_X,    UK_C,    UK_V, XXXXXXX,                                  UK_B,    UK_N,    UK_M, UK_COMM,  UK_DOT, KC_RSFT,
        KC_LCTL, KC_LALT, XXXXXXX, UK_BSLS, UK_GRV, KC_LGUI,                            KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, KC_LCTL,
                                             KC_SPC, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, KC_ENT
    ),

    [SYMB] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,              _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        UK_GRV, UK_EXLM, UK_AT,   UK_HASH, UK_DLR,  UK_PERC, _______,            _______, UK_7,    UK_8,    UK_9,    UK_MINS, UK_SLSH, KC_F12,
        KC_LALT, UK_CIRC, UK_AMPR, UK_ASTR, UK_LPRN, UK_RPRN, _______,            _______, UK_4,    UK_5,    UK_6,    UK_PLUS, UK_ASTR, KC_BSPC,
        KC_LCTL, KC_LSFT, UK_LBRC, KC_RBRC, UK_LCBR, UK_RCBR,                              UK_1,    UK_2,    UK_3,    UK_DOT,  UK_EQL,  KC_ENT,
        _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
                                            _______, KC_LGUI, _______,            _______, KC_ALGR, UK_0
    ),

    [SYS] = LAYOUT(
        RGB_TOG, QK_KB,   RGB_MOD, RGB_M_P, RGB_VAD, RGB_VAI, _______,            _______,  _______, _______, _______, _______, _______, QK_BOOT,
        KC_CAPS, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,            _______,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______, _______,            _______,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                             C(S(KC_TAB)), C(KC_TAB), _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,            _______, _______, _______,
    ),
};

const uint16_t PROGMEM combo0[] = { UK_4, UK_5, UK_6, UK_7, COMBO_END};

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
        RGB_YLW, RGB_RDC, RGB_BLK, RGB_BLK, RGB_BLK,
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