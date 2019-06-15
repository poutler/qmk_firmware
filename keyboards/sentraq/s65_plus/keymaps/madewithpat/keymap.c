#include QMK_KEYBOARD_H

enum {
	TD_F1_11 = 0,
	TD_F2_12 = 1,
	TD_F3_13 = 2,
	TD_F4_14 = 3,
	TD_F5_15 = 4,
	TD_F6_16 = 5,
	TD_F7_17 = 6,
	TD_F8_18 = 7,
	TD_F9_19 = 8,
	TD_F10_20 = 9
};

qk_tap_dance_action_t tap_dance_actions[] = {
	// For each F{n} key, double tap for F{10+n}
	[TD_F1_11] =  ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
	[TD_F2_12] =  ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
	[TD_F3_13] =  ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F13),
	[TD_F4_14] =  ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F14),
	[TD_F5_15] =  ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F15),
	[TD_F6_16] =  ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_F16),
	[TD_F7_17] =  ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F17),
	[TD_F8_18] =  ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F18),
	[TD_F9_19] =  ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F19),
	[TD_F10_20] =  ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F20),
};

/* Layer Aliases */
#define _BL 0
#define _AL 1

/* Grave/Esc swap aliases */
#define GE_SWAP MAGIC_SWAP_GRAVE_ESC
#define GE_NORM MAGIC_UNSWAP_GRAVE_ESC


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Main layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │F1 │F2 │Esc│1 !│2 "│3 £│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│Bksp   │Del│
   * ├───┼───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │F3 │F4 │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│] }│\ |  │Prt│
   * ├───┼───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │F5 │F6 │CapsLk│ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│Enter   │Hom│
   * ├───┼───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │F7 │F8 │Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│Shift │Up │End│
   * ├───┼───┼────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │F9 │F10│Ctrl│GUI │Alt │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └───┴───┴────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 0: ANSI qwerty */
  [_BL] = LAYOUT_ansi(
    TD(TD_F1_11),   TD(TD_F2_12),   GRAVE_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    TD(TD_F3_13),   TD(TD_F4_14),   KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PSCR, \
    TD(TD_F5_15),   TD(TD_F6_16),   LT(_AL, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN, \
    TD(TD_F7_17),   TD(TD_F8_18),           KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,  \
    TD(TD_F9_19),   TD(TD_F10_20),  KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_AL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),


  /* 1: LED layer
	****   NEED TO UPDATE ****
   * ┌─────┬─────┬────┬────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │     │     │` ~ │    │   │   │   │   │   │   │   │   │   │   │   │ RESET │Pwr│
   * ├─────┼─────┼────┴─┬──┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │     │      │    │   │   │   │   │   │   │   │   │   │   │   │     │Slp│
   * ├─────┼─────┼──────┴┬───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │     │     │       │    │   │   │   │   │   │   │   │   │   │   │        │Wak│
   * ├─────┼─────┼───────┴──┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │     │     │          │    │    │    │    │    │    │    │Vol-│Vol+│Mute│      │WUp│   │
   * ├─────┼─────┼─────┬────┴┬───┴─┬──┴────┴────┴────┴────┴────┴───┬┴───┬┴───┬┴───┬────┼────┼────┤
   * │     │     │     │     │     │                          │    │    │    │ Wlt│ WDn│ Wrt│
   * └─────┴─────┴─────┴─────┴─────┴──────────────────────────┴────┴────┴────┴────┴────┴────┘
   */

  [_AL] = LAYOUT_ansi(
    RGB_HUD, RGB_HUI, KC_GRV,  KC_F1,   KC_F2, 	 KC_F3,   KC_F4, 	 KC_F5, 	KC_F6, 	 KC_F7, 	KC_F8, 	 KC_F9, 	 KC_F10,  	 KC_F11,   KC_F12,  RESET,   KC_PWR, \
    RGB_SAD, RGB_SAI, _______, KC_BTN1, KC_WH_U, KC_BTN2, _______, _______, _______, _______, _______, _______,  _______, 	 _______,  _______, KC_SLEP, KC_WAKE, \
    RGB_VAD, RGB_VAI, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, _______, _______, _______, _______,  AG_NORM,    AG_SWAP,           _______, KC_PGUP, \
    RGB_TOG, BL_TOGG, _______,          _______, _______, _______, _______, _______, _______, _______, KC_VOLD,  KC_VOLU, 	 KC_MUTE,  _______, KC_MS_U, KC_HOME, \
    BL_DEC,  BL_INC,  _______, _______, _______,                   _______,                            _______,  _______, 	 _______,  KC_MS_L, KC_MS_D, KC_MS_R  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

