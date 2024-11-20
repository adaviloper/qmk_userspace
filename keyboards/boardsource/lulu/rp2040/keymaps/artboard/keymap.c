#include QMK_KEYBOARD_H

// Tool Shortcuts
#define TL_BRSH KC_B // Brush
#define TL_OPRL KC_D // Operation (Select layer)
#define TL_ERSE KC_E // Eraser
#define TL_FILL KC_G // Fill
#define TL_HAND KC_H // Hand
#define TL_MLYR KC_K // Move Layer
#define TL_SLCT KC_L // Select
#define TL_ZOOM KC_Z // Zoom
#define TL_BLND KC_J // Blend
#define TL_OPRO KC_O // Operation (Select object)
#define TL_PEN KC_P // Pen
#define TL_ROT KC_R // Rotate
#define TL_RULE KC_U // Ruler

// Layer
#define LY_NAME C(A(KC_G)) // Change layer name

// Edit Menu
#define ED_COPY G(KC_C)
#define ED_CUT G(KC_X)
#define ED_PSTE G(KC_V)
#define ED_REDO G(KC_Y)
#define ED_UNDO G(KC_Z)

// View Menu
#define VU_ROTL KC_MINS
#define VU_ROTR KC_QUOT

// Tool Property Palette
#define TP_OINC G(KC_LBRC)
#define TP_ODEC G(KC_RBRC)

// Brush Size Palette
#define BS_INC KC_LBRC
#define BS_DEC KC_RBRC

// Sub-Tool Palette
#define NXT_TOOL KC_DOT
#define PRV_TOOL KC_COMM

// Drawing Color
#define CLR_INV KC_X
#define CLR_TRN KC_C

enum lulu_keycodes {
    KC_MAKE = SAFE_RANGE,
    TOOLS,
    EN_SWAP,
    MOVE,
    ADJUST
};

enum layers {
    _TOOLS = 0,
    _MOVEMENT,
    _QWERTY,
    _ADJUST,
};

enum encoder_state_t {
    ENCODER_BRUSH_SIZE = 0,
    ENCODER_CANVAS_ROTATE,
    ENCODER_MAX_COUNT,
};

uint8_t current_layer = _TOOLS;

enum encoder_state_t encoder_state = ENCODER_BRUSH_SIZE;

enum encoder_state_t get_encoder_state(void) {
    return encoder_state;
}

void increment_encoder_state(void) {
    encoder_state = encoder_state + 1;
    if (encoder_state >= ENCODER_MAX_COUNT) {
        encoder_state = 0;
    }
}

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_TOOLS] = LAYOUT_wrapper(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_LALT, TL_OPRL, KC_W,    TL_ERSE, TL_HAND, KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_LSFT, KC_A,    TL_SLCT, TL_MLYR, TL_PEN,  TL_FILL,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, TL_ZOOM, CLR_INV, CLR_TRN, KC_V,    TL_BRSH, EN_SWAP,   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_HYPR),
                                   ADJUST,  XXXXXXX, MOVE,    KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX, ADJUST
    ),

    [_MOVEMENT] = LAYOUT_wrapper(
        TOOLS,   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        LY_NAME, TL_BLND, KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    EN_SWAP,   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_HYPR),
                                   XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_QWERTY] = LAYOUT_wrapper(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TOOLS,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    EN_SWAP,   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_HYPR),
                                   XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADJUST] = LAYOUT_wrapper(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, RGB_M_R, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                   _______, _______, _______, _______,   _______, _______, _______, _______

    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOOLS:
            if (record->event.pressed) {
                layer_move(_TOOLS);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case MOVE:
            if (record->event.pressed) {
                layer_move(_MOVEMENT);
            }
            return false;
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb boardsource/lulu/rp2040 -km artboard");
                tap_code(KC_ENT);
            }
            return false;
        case EN_SWAP:
            if (record->event.pressed) {
                increment_encoder_state();
            }
            return false;
    };
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _TOOLS:
        current_layer = _TOOLS;
        break;
    case _MOVEMENT:
        current_layer = _MOVEMENT;
        break;
    case _QWERTY:
        current_layer = _QWERTY;
        break;
    case _ADJUST:
        current_layer = _ADJUST;
        break;
    default: //  for any other layers, or the default layer
        current_layer = _TOOLS;
        break;
    }
  return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Encoder on master side
        if (encoder_state == ENCODER_BRUSH_SIZE) {
            if (clockwise) {
                tap_code(KC_LBRC);
            } else {
                tap_code(KC_RBRC);
            }
        } else if (encoder_state == ENCODER_CANVAS_ROTATE) {
            if (clockwise) {
                tap_code(VU_ROTR);
            } else {
                tap_code(VU_ROTL);
            }
        }
    }
    else if (index == 1) { // Encoder on slave side
    }

    return false;
}
