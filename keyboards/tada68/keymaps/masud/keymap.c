#include QMK_KEYBOARD_H

enum CUSTOM_KEYCODES {
    KC_CUSTOM_START = SAFE_RANGE,
    KC_GLHF         = KC_CUSTOM_START,
    CB_LING,
    CB_SEER,
    CB_UNIMP,
    CB_MUTA,
    CB_LARVA,
    CB_LOL,
    CB_HYDRA,
    CB_DRONE,
    CB_DERP,
    CB_SLEEP,
    KC_CUSTOM_END,
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
_______, _______, _______, BL_DOWN,  BL_TOGG, BL_UP,   _______, KC_VOLD, KC_VOLU, KC_MUTE, MO(3),            KC_BTN1, KC_MS_U, KC_BTN2, \
_______, _______, _______,                 _______,                               TO(0),   _______, TO(1),   KC_MS_L, KC_MS_D, KC_MS_R),

  /* Carbot Layer */

[3] = LAYOUT_ansi(
_______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
_______, CB_LING,  CB_MUTA, CB_HYDRA, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
_______, CB_DRONE, CB_SEER, CB_LARVA, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
_______, CB_UNIMP, CB_LOL,  CB_SLEEP, CB_DERP, _______, _______, _______, _______, _______, _______,          _______, _______, _______, \
_______, _______,  _______,                _______,                              _______, _______, _______, _______, _______, _______),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (keycode < KC_CUSTOM_START || keycode >= KC_CUSTOM_END) {
        // outside of custom range, don't do any custom processing
        return true;
    }

    if (!record->event.pressed) {
        // this is a key up event, don't do any custom processing
        return true;
    }

    // emit shift+enter to begin message to all players
    tap_code16(LSFT(KC_ENT));

    // emit string based on custom keycode
    switch (keycode) {
        case KC_GLHF:  SEND_STRING("gl hf");           break;
        case CB_LING:  SEND_STRING("(cbzergling)");    break;
        case CB_SEER:  SEND_STRING("(cboverseer)");    break;
        case CB_UNIMP: SEND_STRING("(cbunimpressed)"); break;
        case CB_MUTA:  SEND_STRING("(cbmuta)");        break;
        case CB_LARVA: SEND_STRING("(cblarva)");       break;
        case CB_LOL:   SEND_STRING("(cbinfestedlol)"); break;
        case CB_HYDRA: SEND_STRING("(cbhydra)");       break;
        case CB_DRONE: SEND_STRING("(cbdrone)");       break;
        case CB_DERP:  SEND_STRING("(cbderp)");        break;
        case CB_SLEEP: SEND_STRING("(cbsleep)");       break;
    }

    // emit enter to complete message
    tap_code16(KC_ENT);

    // don't do default processing
    return false;
}

