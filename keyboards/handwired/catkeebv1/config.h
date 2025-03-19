#define MATRIX_ROWS 10
#define MATRIX_COLS 8

#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS_RIGHT { NO_PIN, F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { D0, D4, C6, D7, E6 }

#define ENCODER_A_PINS { D2 }
#define ENCODER_B_PINS { D3 }
#define ENCODER_RESOLUTION 1
#define ENCODER_MAP_KEY_DELAY 10

#define MASTER_LEFT
#define SOFT_SERIAL_PIN D1
#define SELECT_SOFT_SERIAL_SPEED 1
// #define SPLIT_MAX_CONNECTION_ERRORS 10 // 10 attempts until it is assumed the other half isn't connected and gives up
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_USB_DETECT

#define SPLIT_USB_TIMEOUT 2500 

#define SERIAL_DEBUG
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_SPACE) | MOD_BIT(KC_B)) )