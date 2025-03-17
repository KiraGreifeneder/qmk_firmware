// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// umlaut definition
#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)
#define GER_SZ RALT(KC_S)
#define EU_EUR RALT(KC_5)

// encoder mapping
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_A, KC_B)},
    //[1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

// custom mod stuff
enum custom_keycodes {
    SHIFT_F11 = SAFE_RANGE,
    MULTI_MOD
};


/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SHIFT_F11:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LEFT_SHIFT) SS_DOWN(X_F11) SS_UP(X_LEFT_SHIFT) SS_DOWN(X_F11));
        }
        // register the double tap of the mod key to switch to debug mode
        break;
    return true;
}; */


// TODO: Column mod keys, other half
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESCAPE,     KC_GRAVE,      KC_1,    KC_2,        KC_3,     KC_4, KC_5, KC_6,             KC_7,          KC_8,          KC_9,    KC_0,        KC_SLASH, KC_NUBS, KC_BSPC,
        KC_F12,        KC_TAB,        KC_Q,    KC_W,        KC_E,     KC_R, KC_T, KC_LBRC,          KC_RBRC,       KC_Y,          KC_U,    KC_I,        KC_O,     KC_P,    KC_QUOT,
        KC_F11,        KC_F5,         KC_A,    KC_S,        KC_D,     KC_F, KC_G, KC_MINUS,         KC_EQL,        KC_H,          KC_J,    KC_K,        KC_L,     KC_SCLN, KC_ENTER,
        KC_F10,        KC_LEFT_SHIFT, KC_Z,    KC_X,        KC_C,     KC_V, KC_B, KC_KB_MUTE,       KC_NO,         KC_N,          KC_M,    KC_COMM,     KC_DOT,   KC_UP,   KC_RIGHT_SHIFT,
        KC_F6,         KC_LEFT_CTRL,  KC_HOME, KC_LEFT_ALT, KC_SPACE,                               KC_SPACE,      KC_LEFT,  KC_DOWN,     KC_RIGHT
    )/* ,
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, EU_EUR,  _______, _______, _______,
        _______, _______, UML_AE,  GER_SZ,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______
    ) */
};
