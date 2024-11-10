#include "adaviloper.h"

enum unicorne_keycodes {
    KC_MAKE = NEW_SAFE_RANGE,
};

#define LAYOUT_unicorne_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_unicorne_base_mac( \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, k21, k22, k23, k24, k25,           k28, k29, k2a, k2b, k2c, k2d, \
        k30, k31, k32, k33, k34, k35,           k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45,           k48, k49, k4a \
    ) \
    LAYOUT_unicorne_wrapper( \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, SFT_T(k21), GUI_T(k22), CTL_T(k23), ALT_T(k24), LT(_GIT, k25),   LT(_GIT, k28), ALT_T(k29), CTL_T(k2a), GUI_T(k2b), SFT_T(k2c), k2d, \
        k30, k31, k32, k33, k34, k35,           k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45,           k48, k49, k4a \
    )
#define LAYOUT_unicorne_base_win( \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, k21, k22, k23, k24, k25,           k28, k29, k2a, k2b, k2c, k2d, \
        k30, k31, k32, k33, k34, k35,           k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45,           k48, k49, k4a \
    ) \
    LAYOUT_unicorne_wrapper( \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, SFT_T(k21), CTL_T(k22), GUI_T(k23), ALT_T(k24), LT(_GIT, k25),   LT(_GIT, k28), ALT_T(k29), GUI_T(k2a), CTL_T(k2b), SFT_T(k2c), k2d, \
        k30, k31, k32, k33, k34, k35,           k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45,           k48, k49, k4a \
    )
#define LAYOUT_base_mac_wrapper(...) LAYOUT_unicorne_base_mac(__VA_ARGS__)
#define LAYOUT_base_win_wrapper(...) LAYOUT_unicorne_base_win(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAC] = LAYOUT_base_mac_wrapper(
        KC_TAB,  _________________LAYOUT_L1_________________,    _________________LAYOUT_R1_________________, KC_BSPC,
        KC_DEL,  _________________LAYOUT_L2_________________,    _________________LAYOUT_R2_________________, KC_QUOT,
        OSM_MEH, _________________LAYOUT_L3_________________,    _________________LAYOUT_R3_________________, OSM_HYP,
                                   ______THUMB_3_KEY_L______,    ______THUMB_3_KEY_R______
    ),
    [_MAC_ALT] = LAYOUT_base_mac_wrapper(
        _______, _________________ALT_L1____________________,    _________________ALT_R1____________________, _______,
        _______, _________________ALT_L2____________________,    _________________ALT_R2____________________, _______,
        _______, _________________ALT_L3____________________,    _________________ALT_R3____________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
    [_WINDOWS] = LAYOUT_base_win_wrapper(
        _______, _________________LAYOUT_L1_________________,    _________________LAYOUT_R1_________________, _______,
        _______, _________________LAYOUT_L2_________________,    _________________LAYOUT_R2_________________, _______,
        _______, _________________LAYOUT_L3_________________,    _________________LAYOUT_R3_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
    [_WINDOWS_ALT] = LAYOUT_base_win_wrapper(
        _______, _________________ALT_L1____________________,    _________________ALT_R1____________________, _______,
        _______, _________________ALT_L2____________________,    _________________ALT_R2____________________, _______,
        _______, _________________ALT_L3____________________,    _________________ALT_R3____________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
#ifdef GAMING_ENABLE
    [_GAMING] = LAYOUT_unicorne_wrapper(
        KC_TAB,  _________________GAMING_L1_________________,    _________________GAMING_R1_________________, _______,
        KC_LCTL, _________________GAMING_L2_________________,    _________________GAMING_R2_________________, _______,
        KC_LSFT, _________________GAMING_L3_________________,    _________________GAMING_R3_________________, _______,
                                   KC_LGUI, LT_GALT, KC_SPC,     _______, _______, _______
    ),
    [_GAMING2] = LAYOUT_unicorne_wrapper(
        KC_ESC,  _________________GAMING2_L1________________,    _________________GAMING_R1_________________, _______,
        KC_I,    _________________GAMING2_L2________________,    _________________GAMING_R2_________________, _______,
        KC_M,    _________________GAMING2_L3________________,    _________________GAMING_R3_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
#endif
#ifdef GIT_ENABLE
    [_GIT] = LAYOUT_unicorne_wrapper(
        _______, _________________GIT_L1____________________,    _________________GIT_R1____________________, _______,
        _______, _________________GIT_L2____________________,    _________________GIT_R2____________________, _______,
        _______, _________________GIT_L3____________________,    _________________GIT_R3____________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
#endif
    [_SYMBOL] = LAYOUT_unicorne_wrapper(
        _______, _________________SYMBOL_L1_________________,    _________________SYMBOL_R1_________________, _______,
        _______, _________________SYMBOL_L2_________________,    _________________SYMBOL_R2_________________, TRIP_EQ,
        _______, _________________SYMBOL_L3_________________,    _________________SYMBOL_R3_________________, DBL_EQ,
                                   _______, _______, _______,    _______, _______, _______
    ),
    [_RAISE] = LAYOUT_unicorne_wrapper(
        _______, _________________RAISE_L1__________________,    _________________RAISE_R1__________________, KC_MINS,
        _______, _________________RAISE_L2__________________,    _________________RAISE_R2__________________, KC_ASTR,
        _______, _________________RAISE_L3__________________,    _________________RAISE_R3__________________, KC_SLSH,
                                   _______, _______, _______,    _______, _______, _______
    ),
#ifdef ART_ENABLE
    [_ART] = LAYOUT_unicorne_wrapper(
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_HYPR),
                                   _______, KC_SPC,  ART2,       _______, _______, _______
    ),
    [_ART2] = LAYOUT_unicorne_wrapper(
        _______, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,       KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_LALT,
        _______, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,       KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    KC_LSFT,
        _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,       KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    KC_LCTL,
                                   _______, _______, KC_SPC,     _______, _______, _______
    ),
#endif
    [_SYSTEM] = LAYOUT_unicorne_wrapper(
        OS_NAPP, _________________SYSTEM_L1_________________,    _________________SYSTEM_R1_________________, _______,
        _______, _________________SYSTEM_L2_________________,    _________________SYSTEM_R2_________________, _______,
        OS_NWIN, _________________SYSTEM_L3_________________,    _________________SYSTEM_R3_________________, _______,
                                   _______, _______, _______,    _______, _______, _______
    ),
    [_FUNC] = LAYOUT_unicorne_wrapper(
        _______, _________________FUNC_L1___________________,    _________________FUNC_R1___________________, VI_BSPC,
        VI_DEL,  _________________FUNC_L2___________________,    _________________FUNC_R2___________________, _______,
        _______, _________________FUNC_L3___________________,    _________________FUNC_R3___________________, _______,
                                   _______, _______, _______,    _______, KC_MAKE, _______
    ),
    [_ADJUST] = LAYOUT_unicorne_wrapper(
        XXXXXXX, MAC,     WINDOWS, GAMING,  ART,     XXXXXXX,    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, M_ALT,   W_ALT,   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, RGB_M_R, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                   QK_BOOT, _______, _______,    _______, _______, QK_BOOT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user_adaviloper(keycode, record)) return false;
    switch (keycode) {
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("make boardsource/unicorne:adaviloper");
                tap_code(KC_ENT);
            }
            return false;
    };
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _MAC:
            rgb_matrix_set_color_all(202, 215, 235);
            break;
        case _WINDOWS:
            rgb_matrix_set_color_all(41, 109, 204);
            break;
        case _GAMING:
            rgb_matrix_set_color_all(204, 41, 68);
            break;
        case _GAMING2:
            rgb_matrix_set_color_all(255, 0, 255);
            break;
        case _ART:
        case _ART2:
            rgb_matrix_set_color_all(138, 12, 201);
            break;
        case _GIT:
            rgb_matrix_set_color_all(79, 142, 50);
            break;
        case _SYMBOL:
            rgb_matrix_set_color_all(16, 156, 39);
            break;
        case _RAISE:
            rgb_matrix_set_color_all(16, 156, 39);
            break;
        default:
            break;
    }
    return false;
}
