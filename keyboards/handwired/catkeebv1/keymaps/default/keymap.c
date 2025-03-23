// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// umlaut definition
#define UML_AE RALT(KC_Q)
#define UML_OE RALT(KC_P)
#define UML_UE RALT(KC_Y)
#define GER_SZ RALT(KC_S)
#define EU_EUR RALT(KC_5)

#define _BASE 0
#define _SPECIAL 1
#define _DEBUG 2

// encoder mapping
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { 
        ENCODER_CCW_CW(KC_UNDO, KC_AGAIN), 
        ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), 
    },
    [1] = { 
        ENCODER_CCW_CW(KC_UNDO, KC_AGAIN), 
        ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), 
    },
    [2] = { 
        ENCODER_CCW_CW(KC_UNDO, KC_AGAIN), 
        ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), 
    },
};
#endif

// custom mod stuff
enum custom_keycodes {
    SHIFT_F11 = SAFE_RANGE,
    MULTI_MOD
};


// We can enter DEBUG mode by holding escape, then using the mod button. We can exit debug mode by again holding ESC and pressing the mod button.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        LT(_SPECIAL, KC_ESC), KC_GRAVE,      KC_1,    KC_2,        KC_3,     KC_4, KC_5, KC_6,             KC_7,          KC_8,          KC_9,    KC_0,        KC_SLASH, KC_BSPC, KC_DEL,
        KC_NO,                KC_TAB,        KC_Q,    KC_W,        KC_E,     KC_R, KC_T, KC_LBRC,          KC_RBRC,       KC_Y,          KC_U,    KC_I,        KC_O,     KC_P,    KC_QUOT,
        KC_MFFD,              MO(_SPECIAL),  KC_A,    KC_S,        KC_D,     KC_F, KC_G, KC_MINUS,         KC_EQL,        KC_H,          KC_J,    KC_K,        KC_L,     KC_SCLN, KC_ENTER,
        KC_MPLY,              KC_LEFT_SHIFT, KC_Z,    KC_X,        KC_C,     KC_V, KC_B, KC_KB_MUTE,       KC_BSLS,       KC_N,          KC_M,    KC_COMM,     KC_DOT,   KC_UP,   KC_RIGHT_SHIFT,
        KC_MRWD,              KC_LEFT_CTRL,  KC_LGUI, KC_LEFT_ALT, KC_SPACE,                               KC_SPACE,      KC_LEFT,  KC_DOWN,     KC_RIGHT
    ),
    [_SPECIAL] = LAYOUT(
        _______,       _______,       KC_F1,   KC_F2,       KC_F3,    KC_F4,   KC_F5,   KC_F6,           KC_F7,         KC_F8,         KC_F9,   KC_F10,      KC_F11,   KC_F12,  _______,
        TG(_DEBUG),    _______,       _______, _______,     EU_EUR,   _______, _______, _______,         _______,       _______,       UML_UE,  _______,     UML_OE,   _______, _______,
        _______,       _______,       UML_AE,  GER_SZ,      _______,  _______, _______, _______,         _______,       _______,       _______, _______,     _______,  _______, _______,
        _______,       _______,       _______, _______,     _______,  _______, _______, _______,         _______,       _______,       _______, _______,     _______,  _______, _______,
        _______,       _______,       QK_BOOT, _______,     _______,                                     _______,       _______, _______,     _______
    ),
    [_DEBUG] = LAYOUT(
        LT(_SPECIAL, KC_ESC),       _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F12,        _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F11,        _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F10,        _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F6,         _______,       _______, _______,     _______,                                      _______,       _______, _______,     _______
    ) 
};
