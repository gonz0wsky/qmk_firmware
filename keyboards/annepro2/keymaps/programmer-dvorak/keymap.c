#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _SHIFT_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  $  |  &  |  [  |  {  |  }  |  (  |  =  |  *  |  )  |  +  |  ]  |  !  |  #  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  ;  |  ,  |  .  |  p  |  y  |  f  |  g  |  c  |  r  |  l  |  /  |  @  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  a  |  o  |  e  |  u  |  i  |  d  |  h  |  t  |  n  |  s  |  -  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  '  |  q  |  j  |  k  |  x  |  b  |  m  |  w  |  v  |  z  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_DLR, KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL, KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH, KC_BSPC,
    KC_TAB, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_AT, KC_BSLS,
    KC_CAPS, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
    KC_LSFT, KC_QUOT, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, LT(_SHIFT_LAYER,KC_SPC), KC_RALT, LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _SHIFT_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  |  %  |  7  |  5  |  3  |  1  |  9  |  0  |  2  |  4  |  6  |  8  |  `  |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  :  |  <  |  >  |     |     |     |     |     |     |     |  ?  |  ^  |   |    |
  * |-----------------------------------------------------------------------------------------+
  * | Caps    |     |     |     |     |     |     |     |     |     |     |  _  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  "  |     |     |     |     |     |     |     |     |     |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_SHIFT_LAYER] = KEYMAP( /* Base */
    KC_TILD, KC_PERC, KC_P7, KC_P5, KC_P3, KC_P1, KC_P9, KC_P0, KC_P2, KC_P4, KC_P6, KC_P8, KC_GRV, KC_DEL,
    KC_TAB, KC_COLN, KC_LT, KC_GT, S(KC_P), S(KC_Y), S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), S(KC_SLSH), KC_CIRC, KC_PIPE,
    KC_CAPS, S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), S(KC_MINS), KC_ENT,
    _SHIFT_LAYER, KC_DQUO, S(KC_Q), S(KC_J), S(KC_K), S(KC_X), S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | UP  |     |     |     |     |     |     |     | PS | HOME | END |        |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|     |     |     |     |     |     | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |     |     |     |     |     |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |     | BT1 | BT2 | BT3 | BT4 |     |     |     |LEDOF|LEDON|     |     |     |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | UP  |     |     |     |     |     |     |     | PS | HOME | END |        |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|     |     |     |     |     |     | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |     |     |     |     |     |     |     |     |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_TRNS
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _SHIFT_LAYER:
      // Set the leds to red
      annepro2LedSetForegroundColor(0xFF, 0x00, 0x00);
      break;
    case _FN1_LAYER:
      // Set the leds to green
      annepro2LedSetForegroundColor(0x00, 0xFF, 0x00);
      break;
    case _FN2_LAYER:
      // Set the leds to blue
      annepro2LedSetForegroundColor(0x00, 0x00, 0xFF);
      break;
    default:
      // Reset back to the current profile
      annepro2LedResetForegroundColor();
      break;
  }
  return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    // Set the caps-lock to red
    const annepro2Led_t color = {
        .p.red = 0xff,
        .p.green = 0x00,
        .p.blue = 0x00,
        .p.alpha = 0xff
    };

    annepro2LedMaskSetKey(2, 0, color);
    /* NOTE: Instead of colouring the capslock only, you can change the whole
       keyboard with annepro2LedSetForegroundColor */
  } else {
    // Reset the capslock if there is no layer active
    if(!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER) && !layer_state_is(_SHIFT_LAYER)) {
      const annepro2Led_t color = {
          .p.red = 0xff,
          .p.green = 0x00,
          .p.blue = 0x00,
          .p.alpha = 0x00
      };
      annepro2LedMaskSetKey(2, 0, color);
    }
  }

  return true;
}
