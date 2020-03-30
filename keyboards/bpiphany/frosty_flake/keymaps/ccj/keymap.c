#include QMK_KEYBOARD_H

#define _FN       4
#define _MOUSE    3
#define _SYMBOL   2
#define _CHROMEOS 1
#define _BASE     0

/**
 * Default Layer (_BASE) is vanilla QWERTY with the following twiddles:
 *   + modifier key locations match typical Apple keyboard
 *   + Caps Lock is: Tap ESC, Hold CTRL
 *   + Enter is: Tap ENT, Hold CTRL
 *   + Space Cadet Shifts
 *   + Layer Tap on Space (hold for _MOUSE layer)
 *   + Layer Tap on Tab (hold for _NUMPAD layer)
 */

#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3

#define Z_NUMPAD LT(_SYMBOL, KC_Z)
#define SEMI_SYM LT(_SYMBOL, KC_SCLN)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_ENT MT(MOD_LCTL, KC_ENT)

/* Goofiness to do MT with swapped ESC/Search key. Note: WIP because it looks like MT can't send LGUI by itself‽ */
#define ALT_ESC MT(MOD_LALT, KC_LGUI) // this is the keycode for Search on Chromebooks, probably.
#define ALT_ENT MT(MOD_LALT, KC_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_FN] = LAYOUT_tkl(\
  _______,      _______,  _______,  _______,  _______,       KC_MPLY,  KC_MSTP,  KC_MPRV,  KC_MNXT,       _______,  KC_MUTE,  KC_VOLD,  KC_VOLU,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,    _______,  _______,                _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,            _______, \
  _______,  _______,  _______,                      _______,                           _______,    _______,    _______,   _______,                 _______, _______, _______  ),

/* VIM style mouse layer
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md
 * TODO: mouse wheel: KC_WH_{U,D,L,R}.
 * TODO: change to Constant Mode and add acceleration control: KC_ACL{0,1,2}
 * TODO: may also need to adjust base repeat rate.
 */
[_MOUSE] = LAYOUT_tkl(\
  _______,      _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,   KC_UP,  KC_RIGHT,  _______,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,  MS_BTN1,  MS_BTN3,  MS_BTN2,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,                _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,             KC_MS_U, \
  _______,  _______,  _______,                      _______,                             _______,   _______,   _______,   _______,                 KC_MS_L,  KC_MS_D,  KC_MS_R  ),

/* Reproduce classic Numpad under right home area.
 * 
 *
[_NUMPAD] = LAYOUT_tkl(\
  _______,      _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_TAB, KC_SLSH,  KC_ASTR,    KC_BSPC,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_7,     KC_8,     KC_9,     KC_MINS,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_4,     KC_5,     KC_6,     KC_PLUS,  _______,                _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,    KC_ENT,                  _______,            _______, \
  _______,  _______,  _______,                      KC_0,                                KC_DOT,      KC_ENT,      _______,   _______,             _______, _______, _______  ),
*/

/* TODO: Add symbols in left home area (note: already have spacekey shifts, so no parens.) Inspired by: https://configure.ergodox-ez.com/ergodox-ez/layouts/9D5J7/latest/1
 * biased toward JS & HTML && vim 
 * TODO, maybe: |?/\@
 * QWERT => `&*[]
 * ASDFG => $%^{}
 *   XCVB =>  !#<>
 *
 */
[_SYMBOL] = LAYOUT_tkl(\
  _______,      _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_TAB, KC_SLSH,  KC_ASTR,    KC_BSPC,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,   KC_GRV,  KC_AMPR,  KC_ASTR,  KC_LBRC,  KC_RBRC,  _______,  KC_7,     KC_8,     KC_9,     KC_MINS,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,   KC_DLR,  KC_PERC,  KC_CIRC,  KC_LCBR,  KC_RCBR,  _______,  KC_4,     KC_5,     KC_6,     KC_PLUS,  _______,                _______, \
  _______,  _______,  _______,  KC_EXLM,  KC_HASH,  KC_LABK,  KC_RABK,  _______,  KC_1,     KC_2,     KC_3,    KC_ENT,                  _______,            _______, \
  _______,  _______,  _______,                      KC_0,                                KC_DOT,      KC_ENT,      _______,   _______,             _______, _______, _______  ),

/* I have switched several sets of keys on ChromeOS local keyboard: CTL <-> ALT & Search <-> ESC. This layer keeps me somewhat sane if I am using the native keyboard, though the native keyboard lacks. e.g. CTL_ESC. */ 
/* TODO: still haven't figured out what the keycode for "Search" key is so this layer is pretty useless. */
[_CHROMEOS] = LAYOUT_tkl(\
  KC_WSCH,      _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,   _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,   _______,  _______,  _______, \
  ALT_ESC,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,    _______,  _______,                ALT_ENT, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,            _______, \
  KC_LALT,  KC_LCTL,  KC_LALT,                      _______,                           KC_LALT,     KC_LCTL,   _______,   KC_LALT,                 _______, _______, _______  ),

[_BASE] = LAYOUT_tkl(\
  KC_ESC,       KC_F1,    KC_F2,    KC_F3,    KC_F4,        KC_F5,    KC_F6,    KC_F7,    KC_F8,          KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_PSCR, KC_SLCK, TG(_CHROMEOS), \
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,       KC_BSPC,   KC_INS,  KC_HOME,  KC_PGUP, \
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,      KC_BSLS,   KC_DEL,  KC_END,   KC_PGDN, \
  CTL_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     SEMI_SYM, KC_QUOT,                CTL_ENT, \
  KC_LSPO,  KC_NUBS,  Z_NUMPAD, KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                KC_RSPC,            KC_UP, \
  KC_LCTL,  KC_LALT,  KC_LGUI,              LT(_MOUSE, KC_SPC),                        KC_RGUI,       KC_RALT,    KC_APP,    KC_RCTL,              KC_LEFT, KC_DOWN,  KC_RGHT  )
};

/* TODO: when _CHROMEOS layer is toggled, light up scroll lock LED. */
// NOTE: this is stupid as it throws away current LED state. Need to find function that shows current mask and modify that. (https://beta.docs.qmk.fm/detailed-guides/custom_quantum_functions#led-control)
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _CHROMEOS:
        led_set_user(USB_LED_SCROLL_LOCK);
        break;
    default: //  for any other layers, or the default layer
        led_set_user(0);
        break;
    }
    return state;
}
