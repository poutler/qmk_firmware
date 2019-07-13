/* Copyright 2015-2017 Jack Humbert
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

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _MINI4,
  _MINI8,
  _MINI12,
  _WORKMAN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum my_keycodes {
  QWERTY = SAFE_RANGE,
  MINI4,
  MINI8,
  MINI12,
  WORKMAN,
  LOWER,
  RAISE,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | GUI  | Alt  |Lower | Space| Space|Raise | RAlt | RGUI | RCTL |Shift |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT ,
    KC_LCTL,  KC_LCTL, KC_LGUI, KC_LALT, LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),

  /* MiniMak 4
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   D  |   R  |   K  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   T  |   F  |   G  |   H  |   J  |   E  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | GUI  | Alt  |Lower | Space| Space|Raise | RAlt | RGUI | RCTL |Shift |
   * `-----------------------------------------------------------------------------------'
   */
  [_MINI4] = LAYOUT_ortho_4x12(
    KC_ESC,      KC_Q,    KC_W,    KC_D,    KC_R,  KC_K,    KC_Y,   KC_U,  KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,      KC_A,    KC_S,    KC_T,    KC_F,  KC_G,    KC_H,   KC_J,  KC_E,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,   KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT ,
    KC_LCTL,     KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC,  KC_SPC, RAISE, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),

  /* MiniMak 8
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   D  |   R  |   K  |   Y  |   U  |   I  |   L  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   T  |   F  |   G  |   H  |   N  |   E  |   O  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   J  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | GUI  | Alt  |Lower | Space| Space|Raise | RAlt | RGUI | RCTL |Shift |
   * `-----------------------------------------------------------------------------------'
   */
  [_MINI8] = LAYOUT_ortho_4x12(
    KC_ESC,      KC_Q,    KC_W,    KC_D,    KC_R,    KC_K,    KC_Y,    KC_U,  KC_I,     KC_L,     KC_P,     KC_BSPC,
    KC_TAB,      KC_A,    KC_S,    KC_T,    KC_F,    KC_G,    KC_H,    KC_N,  KC_E,     KC_O,     KC_SCLN,  KC_QUOT,
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_J,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT ,
    KC_LCTL,     KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),

  /* MiniMak 12
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   D  |   F  |   K  |   Y  |   U  |   I  |   L  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   T  |   R  |   G  |   H  |   N  |   E  |   O  |   P  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   J  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | GUI  | Alt  |Lower | Space| Space|Raise | RAlt | RGUI | RCTL |Shift |
   * `-----------------------------------------------------------------------------------'
   */
  [_MINI12] = LAYOUT_ortho_4x12(
    KC_ESC,      KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_Y,    KC_U,  KC_I,     KC_L,     KC_SCLN,  KC_BSPC,
    KC_TAB,      KC_A,    KC_S,    KC_T,    KC_R,    KC_G,    KC_H,    KC_N,  KC_E,     KC_O,     KC_P,     KC_QUOT,
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_J,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT ,
    KC_LCTL,     KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),

  /* Workman
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | GUI  | Alt  |Lower | Space| Space|Raise | RAlt | RGUI | RCTL |Shift |
   * `-----------------------------------------------------------------------------------'
   */
  [_WORKMAN] = LAYOUT_ortho_4x12(
    KC_ESC,      KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_Y,    KC_U,  KC_I,     KC_L,     KC_SCLN,  KC_BSPC,
    KC_TAB,      KC_A,    KC_S,    KC_T,    KC_R,    KC_G,    KC_H,    KC_N,  KC_E,     KC_O,     KC_P,     KC_QUOT,
    KC_LSFT,     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_J,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT ,
    KC_LCTL,     KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE, KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CAPS |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |   |  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Left | Down |  Up  |Right |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Home | PgDn | PgUp | End  |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),
  
  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |  ~`  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | CAPS |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * | Reset| QWER | WORK | MIN4 | MIN8 | MIN12|NumLck|  7   |  8   |  9   |   /  |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      | Enter|  4   |  5   |  6   |   *  |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  1   |  2   |  3   |   -  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |  0   |   .  |   +  |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
    RESET,   QWERTY,  WORKMAN, MINI4,   MINI8,   MINI12,  KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______,
    _______, _______, _______, _______, _______, _______, KC_PENT, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_PPLS, _______
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        print("mode just switched to Workman\n");
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case MINI4:
      if (record->event.pressed) {
        print("mode just switched to MiniMak 4 key\n");
        set_single_persistent_default_layer(_MINI4);
      }
      return false;
      break;
    case MINI8:
      if (record->event.pressed) {
        print("mode just switched to MiniMak 4 key\n");
        set_single_persistent_default_layer(_MINI8);
      }
      return false;
      break;
    case MINI12:
      if (record->event.pressed) {
        print("mode just switched to MiniMak 4 key\n");
        set_single_persistent_default_layer(_MINI12);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    
  }
  return true;
}
