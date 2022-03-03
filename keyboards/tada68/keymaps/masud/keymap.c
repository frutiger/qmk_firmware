#include QMK_KEYBOARD_H

enum CUSTOM_KEYCODES {
    KC_GLHF = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base Layer (default layer)
   * ,---------------------------------------------------------------.
   * |~ `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp|Ins|
   * |---------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del|
   * |---------------------------------------------------------------|
   * |Esc   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Return |PgU|
   * |---------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
   * |---------------------------------------------------------------|
   * |Ctrl|Gui |Alt |         Space          |Alt| Fn|Ctl|Lef|Dow|Rig|
   * `---------------------------------------------------------------'
   */
[0] = LAYOUT_ansi(
KC_GRV,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  \
KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  \
KC_ESC,  KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
KC_LSFT,          KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
KC_LCTL, KC_LGUI, KC_LALT,              KC_SPC,                KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Mac Layer
   * ,---------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |
   * |---------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
   * |---------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
   * |---------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
   * |---------------------------------------------------------------|
   * |    |Alt |Gui |                        |   |   |   |   |   |   |
   * `---------------------------------------------------------------'
   */
[1] = LAYOUT_ansi(
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, \
_______, KC_LALT, KC_LGUI,                 _______,                              _______, _______, _______, _______, _______, _______),

  /* Function Layer
   * ,---------------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|    Del|Ins|
   * |---------------------------------------------------------------|
   * |     |   | Up|   |   |   |   |   |   |   |   |   |Pse| ScrL|Hme|
   * |---------------------------------------------------------------|
   * |      |Lef|Dow|Rig|   |   |   |   |   |   |   |   |        |End|
   * |---------------------------------------------------------------|
   * |        |   |   |BL-| BL|BL+|   |VL-|VL+| VL|   |  McL |MsU|McR|
   * |---------------------------------------------------------------|
   * |    |    |    |                        |   |   |   |MsL|MsD|MsR|
   * `---------------------------------------------------------------'
   */

[2] = LAYOUT_ansi(
_______, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS , \
_______, KC_GLHF, KC_UP,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_SCRL, KC_HOME, \
_______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_END,  \
_______, _______, _______, BL_DOWN,  BL_TOGG, BL_UP,   _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,          KC_BTN1, KC_MS_U, KC_BTN2, \
_______, _______, _______,                 _______,                               TO(0),   _______, TO(1),   KC_MS_L, KC_MS_D, KC_MS_R),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (keycode == KC_GLHF && record->event.pressed) {
        // This keycode is for StarCraft II.
        //
        // The following sequence sends the "gl hf" message to all players in
        // the game.

        tap_code16(LSFT(KC_ENT));
        SEND_STRING("gl hf\n");
        return false;
    }

    return true;
}

