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

// Tap Dance declarations
enum {
    TD_SPECIAL_DEBUG, // Tap dance for SPECIAL layer hold, DEBUG layer toggle
};

// check how many taps and if it is being held
void tap_dance_special_debug_finished(tap_dance_state_t *state, void *user_data) {
    // Recognize one tap
    if (state->count == 1) {
        // recognise being held
        if (state->pressed) {
            layer_on(_SPECIAL); // Activate SPECIAL layer
        }
    } else if (state->count >= 2) {
        // We have been double tapped - toggle DEBUG layer
        layer_invert(_DEBUG);
    }
}

// is called after tap dance finshed and actions have been taken
void tap_dance_special_debug_reset(tap_dance_state_t *state, void *user_data) {
    // Always turn the special layer off when the tap dance is reset, i.e. when we stop pressing the button
    layer_off(_SPECIAL);
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // 0: Do nothing on one tap, 1: actions to be taken after taps have been recognised, 2: after actions have been taken
    [TD_SPECIAL_DEBUG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_special_debug_finished, tap_dance_special_debug_reset),
};

// encoder mapping
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { 
        ENCODER_CCW_CW(KC_BRID, KC_BRIU), 
        ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), 
    },
    [1] = { 
        ENCODER_CCW_CW(KC_BRID, KC_BRIU), 
        ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), 
    },
    [2] = { 
        ENCODER_CCW_CW(KC_BRID, KC_BRIU), 
        ENCODER_CCW_CW(KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP), 
    },
};
#endif

// custom mod stuff
enum custom_keycodes {
    SHIFT_F11 = SAFE_RANGE,
    MULTI_MOD
};


// double tapping the mod key switches to the debug layer, holding momentarily switches to the special layer
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,              KC_GRAVE,              KC_1,    KC_2,        KC_3,     KC_4, KC_5, KC_6,             KC_7,     KC_8,    KC_9,    KC_0,    KC_SLASH, KC_BSPC, KC_DEL,
        KC_NO,               KC_TAB,                KC_Q,    KC_W,        KC_E,     KC_R, KC_T, KC_LBRC,          KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_QUOT,
        KC_MEDIA_NEXT_TRACK, TD(TD_SPECIAL_DEBUG),  KC_A,    KC_S,        KC_D,     KC_F, KC_G, KC_MINUS,         KC_EQL,   KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_ENTER,
        KC_MEDIA_PLAY_PAUSE, KC_LEFT_SHIFT,         KC_Z,    KC_X,        KC_C,     KC_V, KC_B, KC_KB_MUTE,       KC_BSLS,  KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_UP,   KC_RIGHT_SHIFT,
        KC_MEDIA_PREV_TRACK, KC_LEFT_CTRL,          KC_LGUI, KC_LEFT_ALT, KC_SPACE,                               KC_SPACE, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_SPECIAL] = LAYOUT(
        _______,       _______,       KC_F1,   KC_F2,       KC_F3,    KC_F4,   KC_F5,   KC_F6,           KC_F7,         KC_F8,         KC_F9,   KC_F10,      KC_F11,   KC_F12,  _______,
        _______,       _______,       _______, _______,     EU_EUR,   _______, _______, _______,         _______,       _______,       UML_UE,  _______,     UML_OE,   _______, _______,
        _______,       _______,       UML_AE,  GER_SZ,      _______,  _______, _______, _______,         _______,       _______,       _______, _______,     _______,  _______, _______,
        _______,       _______,       _______, _______,     _______,  _______, _______, _______,         _______,       _______,       _______, _______,     _______,  _______, _______,
        _______,       _______,       QK_BOOT, _______,     _______,                                     _______,       _______, _______,     _______
    ),
    [_DEBUG] = LAYOUT(
        _______,       _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F12,        _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F11,        _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F10,        _______,       _______, _______,     _______,  _______, _______, _______,          _______,       _______,       _______, _______,     _______,  _______, _______,
        KC_F6,         _______,       _______, _______,     _______,                                      _______,       _______, _______,     _______
    ) 
};
