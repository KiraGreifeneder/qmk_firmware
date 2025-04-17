#define MATRIX_ROWS 10 // 10 because of the way QMK represents sides: left "above" right
#define MATRIX_COLS 8

#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS_RIGHT { NO_PIN, F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { D0, D4, C6, D7, E6 }

#define ENCODER_A_PINS { D2 }
#define ENCODER_B_PINS { D3 }
#define ENCODER_RESOLUTION 1
#define ENCODER_MAP_KEY_DELAY 10

// Serial through TRRS jack
#define SOFT_SERIAL_PIN D1
#define SELECT_SOFT_SERIAL_SPEED 1

#define SPLIT_HAND_PIN B4
#define	SPLIT_HAND_PIN_LOW_IS_LEFT

// share layer state across sides
#define SPLIT_LAYER_STATE_ENABLE

#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

#define SPLIT_USB_TIMEOUT 2500 

#define WAIT_FOR_USB

// #define SERIAL_DEBUG
// #define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_SPACE) | MOD_BIT(KC_B)) )