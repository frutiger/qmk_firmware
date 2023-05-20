// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdio.h>

#include QMK_KEYBOARD_H
#include "transactions.h"

#include "futura.h"

// Custom keycode declarations
enum {
    KC_CUSTOM_START = SAFE_RANGE,
    KC_TGLDSP       = KC_CUSTOM_START,

    KC_CUSTOM_END,
};

// Tap Dance declarations
enum {
    LGA,
    RGA,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [LGA] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LALT),
    [RGA] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_RALT),
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /**
   *  BASE
   * ,------------------------.                ,------------------------.
   * | `  | 1 | 2 | 3 | 4 | 5 |                | 6 | 7 | 8 | 9 | 0 | -  |
   * |------------------------|                |------------------------|
   * |Tab | Q | W | E | R | T |                | Y | U | I | O | P | \  |
   * |------------------------|                |------------------------|
   * |Esc | A | S | D | F | G |-----.    ,-----| H | J | K | L | ; | '  |
   * |------------------------|  [  |    |  ]  |------------------------|
   * |LSft| Z | X | C | V | B |-----|    |-----| N | M | , | . | / |RSft|
   * `-----------------------/     /     \     \------------------------'
   *        |LCtl|LAlt|Lwr |/ Spc /       \Entr \| Rse|RGui|RCtl|
   *        `--------------------'         '----''--------------'
   */
[0] = LAYOUT(
KC_GRV,  KC_1, KC_2, KC_3,    KC_4,    KC_5,                    KC_6,  KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
KC_TAB,  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                    KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
KC_ESC,  KC_A, KC_S, KC_D,    KC_F,    KC_G,                    KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,    KC_B,  KC_LBRC, KC_RBRC, KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                     KC_LCTL, KC_LALT, MO(2), KC_SPC,  KC_ENT,  MO(1), KC_RGUI, KC_RCTL
),

  /**
   * RAISE
   * ,------------------------.                ,------------------------.
   * | `  | F1| F2| F3| F4| F5|                | F6| F7| F8| F9|F10|BOOT|
   * |------------------------|                |------------------------|
   * |Tab |   |   |   | - |   |                |   |   |   |   |   | \  |
   * |------------------------|                |------------------------|
   * |Esc |   |   |   | ( | < |-----.    ,-----| > | ) |   |   |   |TgDp|
   * |------------------------|     |    |     |------------------------|
   * |LSft|   |   |   |   |   |-----|    |-----|   |   |   |   |   |RSft|
   * `-----------------------/     /     \     \------------------------'
   *        |LCtl|LGA |Del |/ Spc /       \Entr \| Rse| RGA|RCtl|
   *        `--------------------'         '----''--------------'
   */
[1] = LAYOUT(
_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,                       KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  QK_BOOT,
_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS,    XXXXXXX,                     XXXXXXX,   KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
_______, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_9),    S(KC_COMM),                  S(KC_DOT), S(KC_0), XXXXXXX, XXXXXXX, XXXXXXX, KC_TGLDSP,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                           _______, _______,    KC_DEL,    _______, _______, _______,   _______, _______
),

  /**
   * LOWER
   * ,------------------------.                ,------------------------.
   * | `  |   |   |   |   |   |                |   |   |   |   |   | -  |
   * |------------------------|                |------------------------|
   * |Tab |   |   |   |   |   |                |Hme|PgD|PgU|End|   | \  |
   * |------------------------|                |------------------------|
   * |Esc |   |   |   |   |   |-----.    ,-----|Lft|Dwn| Up|Rgt|   |TgDp|
   * |------------------------|     |    |     |------------------------|
   * |LSft|   |   |   |   |   |-----|    |-----|   |   |   |   |   |RSft|
   * `-----------------------/     /     \     \------------------------'
   *        |LCtl|LGA |Lwr |/ Spc /       \Entr \|Bksp| RGA|RCtl|
   *        `--------------------'         '----''--------------'
   */
[2] = LAYOUT(
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                           _______, _______, _______, _______, _______, KC_BSPC, _______, _______
),
};

static uint32_t keydown_count = 0;

void on_keydown(void) {
    ++keydown_count;
}

static bool display_on = TRUE;

void on_toggle_display(void) {
    display_on = !display_on;
    if (!display_on) {
        oled_clear();
    }
}

void remote_keydown(uint8_t     id,
                    const void *input,
                    uint8_t     input_size,
                    void       *output) {
    on_keydown();
}

void remote_toggle_display(uint8_t     id,
                           const void *input,
                           uint8_t     input_size,
                           void       *output) {
    on_toggle_display();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        // this is a key up event, don't do any custom processing
        return true;
    }

    if (record->event.key.row <= 4) {
        // left hand side
        on_keydown();
    }
    else {
        // right hand side
        transaction_rpc_send(NOTIFY_KEYDOWN, 0, 0);
    }

    if (keycode < KC_CUSTOM_START || keycode >= KC_CUSTOM_END) {
        // outside of custom range, don't do any custom processing
        return true;
    }

    if (keycode == KC_TGLDSP) {
        // Toggle display

        // left hand side
        on_toggle_display();

        // right hand side
        transaction_rpc_send(NOTIFY_TOGGLE_DISPLAY, 0, 0);
    }

    // we handled this event, don't do any standard processing
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

void keyboard_post_init_user() {
    transaction_register_rpc(NOTIFY_KEYDOWN,        &remote_keydown);
    transaction_register_rpc(NOTIFY_TOGGLE_DISPLAY, &remote_toggle_display);
    rgblight_disable();
}

void paint_glyph(uint8_t position, uint8_t index) {
    const bool *glyph = FUTURA[index];
    for (uint8_t x = 0; x < 16; ++x) {
        for (uint8_t y = 0; y < 32; ++y) {
            oled_write_pixel(16 * position + x, y, glyph[16 * y + x]);
        }
    }
}

void paint_count(uint32_t keydown_count) {
    uint32_t position = 7;
    for (uint32_t x = keydown_count; x != 0; x /= 10) {
        paint_glyph(position, x % 10);
        --position;
    }
}

uint32_t last_painted_count = 0;
bool oled_task_user() {
    if (display_on && (last_painted_count != keydown_count)) {
        oled_clear();
        paint_count(keydown_count);
        last_painted_count = keydown_count;
    }

    return false;
}

