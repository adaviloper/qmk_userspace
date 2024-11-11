#include QMK_KEYBOARD_H

enum lulu_keycodes {
    KC_MAKE = SAFE_RANGE,
    EN_SWAP,
    ART2,
    MAC,
};

enum layers {
    _BASE = 0,
    _ART,
    _ADJUST,
};

enum encoder_state_t {
    ENCODER_BRUSH_SIZE = 0,
    ENCODER_CANVAS_ROTATE,
    ENCODER_MAX_COUNT,
};

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

    [_BASE] = LAYOUT_wrapper(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    EN_SWAP,   XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_HYPR),
                                   XXXXXXX, XXXXXXX, KC_SPC,  ART2,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADJUST] = LAYOUT_wrapper(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, RGB_M_R, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                   QK_BOOT, _______, _______, _______,   _______, _______, _______, QK_BOOT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("make boardsource/lulu/rp2040:artboard");
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

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint16_t highest_layer = get_highest_layer(layer_state|default_layer_state);
    if (index == 0) { // Encoder on master side
        if (highest_layer == _ART) {
            if (clockwise) {
                tap_code(KC_LBRC);
            } else {
                tap_code(KC_RBRC);
            }
        }
        else {
            if (clockwise) {
                tap_code(KC_KB_VOLUME_DOWN);
            } else {
                tap_code(KC_KB_VOLUME_UP);
            }
        }
    }
    else if (index == 1) { // Encoder on slave side
    }
    return true;
}
