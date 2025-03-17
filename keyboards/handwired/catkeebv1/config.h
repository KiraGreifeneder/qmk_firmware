#define MATRIX_ROWS 10
#define MATRIX_COLS 8

#define MATRIX_COL_PINS { F4, B6, B2, B3, B1, F7, F6, F5 }
#define MATRIX_COL_PINS_RIGHT { B6, B2, B3, B1, F7, F6, F5, NO_PIN }
#define MATRIX_ROW_PINS { D0, D4, C6, D7, E6 }

#define ENCODER_A_PINS { D2 }
#define ENCODER_B_PINS { D3 }
#define ENCODER_RESOLUTION 1
#define ENCODER_MAP_KEY_DELAY 10

#define MASTER_LEFT
#define SOFT_SERIAL_PIN D1
#define SELECT_SOFT_SERIAL_SPEED 5
#define SPLIT_MAX_CONNECTION_ERRORS 10 // 10 attempts until it is assumed the other half isn't connected and gives up
#define SPLIT_LAYER_STATE_ENABLE
