#include "adaviloper.h"

enum lulu_keycodes {
    KC_MAKE = NEW_SAFE_RANGE,
};

#define LAYOUT_lulu_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_lulu_base_mac( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, k21, k22, k23, k24, k25,           k28, k29, k2a, k2b, k2c, k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    ) \
    LAYOUT_lulu_wrapper( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, SFT_T(k21), GUI_T(k22), CTL_T(k23), ALT_T(k24), LT(_GIT, k25),   LT(_GIT, k28), ALT_T(k29), CTL_T(k2a), GUI_T(k2b), SFT_T(k2c), k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    )
#define LAYOUT_lulu_base_win( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, k21, k22, k23, k24, k25,           k28, k29, k2a, k2b, k2c, k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    ) \
    LAYOUT_lulu_wrapper( \
        k00, k01, k02, k03, k04, k05,           k08, k09, k0a, k0b, k0c, k0d, \
        k10, k11, k12, k13, k14, k15,           k18, k19, k1a, k1b, k1c, k1d, \
        k20, SFT_T(k21), CTL_T(k22), GUI_T(k23), ALT_T(k24), LT(_GIT, k25),   LT(_GIT, k28), ALT_T(k29), GUI_T(k2a), CTL_T(k2b), SFT_T(k2c), k2d, \
        k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, \
                       k43, k44, k45, k46, k47, k48, k49, k4a \
    )
#define LAYOUT_base_mac_wrapper(...) LAYOUT_lulu_base_mac(__VA_ARGS__)
#define LAYOUT_base_win_wrapper(...) LAYOUT_lulu_base_win(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAC] = LAYOUT_base_mac_wrapper(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_BSPC,
        KC_TAB,  _________________LAYOUT_L1_________________,                     _________________LAYOUT_R1_________________, KC_NO,
        KC_DEL,  _________________LAYOUT_L2_________________,                     _________________LAYOUT_R2_________________, KC_QUOT,
        OSM_MEH, _________________LAYOUT_L3_________________, KC_LBRC,   KC_RBRC, _________________LAYOUT_R3_________________, OSM_HYP,
                                   __________THUMB_4_KEY_L___________,    __________THUMB_4_KEY_R___________
    ),

    [_MAC_ALT] = LAYOUT_base_mac_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _________________ALT_L1____________________,                     _________________ALT_R1____________________, _______,
        _______, _________________ALT_L2____________________,                     _________________ALT_R2____________________, _______,
        _______, _________________ALT_L3____________________, KC_LBRC,   KC_RBRC, _________________ALT_R3____________________, _______,
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    ),

    [_WINDOWS] = LAYOUT_base_win_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _________________LAYOUT_L1_________________,                     _________________LAYOUT_R1_________________, _______,
        _______, _________________LAYOUT_L2_________________,                     _________________LAYOUT_R2_________________, _______,
        _______, _________________LAYOUT_L3_________________, _______,   _______, _________________LAYOUT_R3_________________, _______,
                                   _______, _______, _______, _______,   _______, _______, _______, _______

    ),
    [_WINDOWS_ALT] = LAYOUT_base_win_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _________________ALT_L1____________________,                     _________________ALT_R1____________________, _______,
        _______, _________________ALT_L2____________________,                     _________________ALT_R2____________________, _______,
        _______, _________________ALT_L3____________________, KC_LBRC,   KC_RBRC, _________________ALT_R3____________________, _______,
                                   _______, _______, _______, _______,   _______, _______, _______, _______

    ),
#ifdef GAMING_ENABLE
    [_GAMING] = LAYOUT_wrapper(
        KC_ESC,  _________________GAMING_L0_________________,                     _________________GAMING_R0_________________, _______,
        KC_TAB,  _________________GAMING_L1_________________,                     _________________GAMING_R1_________________, _______,
        KC_LCTL, _________________GAMING_L2_________________,                     _________________GAMING_R2_________________, _______,
        KC_LSFT, _________________GAMING_L3_________________, _______,   _______, _________________GAMING_R3_________________, _______,
                                   KC_LGUI, KC_ENT,  KC_LALT, KC_SPC,    _______, _______, _______, _______
    ),

#endif
#ifdef GIT_ENABLE
    [_GIT] = LAYOUT_wrapper(
        _______, _________________GIT_L0____________________,                     _________________GIT_R0____________________, _______,
        _______, _________________GIT_L1____________________,                     _________________GIT_R1____________________, _______,
        _______, _________________GIT_L2____________________,                     _________________GIT_R2____________________, _______,
        _______, _________________GIT_L3____________________, _______,   _______, _________________GIT_R3____________________, _______,
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    ),
#endif

    [_SYMBOL] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _________________SYMBOL_L1_________________,                     _________________SYMBOL_R1_________________, _______,
        _______, _________________SYMBOL_L2_________________,                     _________________SYMBOL_R2_________________, TRIP_EQ,
        _______, _________________SYMBOL_L3_________________, _______,   _______, _________________SYMBOL_R3_________________, DBL_EQ,
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______, _________________RAISE_L1__________________,                     _________________RAISE_R1__________________, KC_MINS,
        _______, _________________RAISE_L2__________________,                     _________________RAISE_R2__________________, KC_ASTR,
        _______, _________________RAISE_L3__________________, _______,   _______, _________________RAISE_R3__________________, KC_SLSH,
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    ),

#ifdef ART_ENABLE
    [_ART] = LAYOUT_wrapper(
        KC_ESC,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_LALT, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,   _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_HYPR),
                                   _______, _______, KC_SPC,  ART2,      _______, _______, _______, _______
    ),

    [_ART2] = LAYOUT_wrapper(
        _______, KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,                      KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_ESC,
        _______, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                        KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_LALT,
        _______, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,                        KC_G,    KC_F,    KC_D,    KC_S,    KC_A,    KC_LSFT,
        _______, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    _______,   _______, KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    KC_LCTL,
                                   _______, _______, KC_SPC,  _______,   _______, _______, _______, _______
    ),
#endif

    [_SYSTEM] = LAYOUT_wrapper(
        _______, _________________SYSTEM_L0_________________,                     _________________SYSTEM_R0_________________, _______,
        OS_NAPP, _________________SYSTEM_L1_________________,                     _________________SYSTEM_R1_________________, _______,
        _______, _________________SYSTEM_L2_________________,                     _________________SYSTEM_R2_________________, _______,
        _______, _________________SYSTEM_L3_________________, _______,   _______, _________________SYSTEM_R3_________________, _______,
                                   _______, _______, _______, _______,   _______, _______, _______, _______
    ),

    [_FUNC] = LAYOUT_wrapper(
        _______, _________________FUNC_L0___________________,                     _________________FUNC_R0___________________, VI_BSPC,
        _______, _________________FUNC_L1___________________,                     _________________FUNC_R1___________________, VI_BSPC,
        VI_DEL,  _________________FUNC_L2___________________,                     _________________FUNC_R2___________________, _______,
        _______, _________________FUNC_L3___________________, _______,   _______, _________________FUNC_R3___________________, _______,
                                   _______, _______, _______, _______,   _______, _______, KC_MAKE, _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        XXXXXXX, MAC,     WINDOWS, GAMING,  ART,     XXXXXXX,                     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, M_ALT,   W_ALT,   XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, RGB_M_R, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
                                   QK_BOOT, _______, _______, _______,   _______, _______, _______, QK_BOOT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user_adaviloper(keycode, record)) return false;
    switch (keycode) {
        case KC_MAKE:
            if (record->event.pressed) {
                SEND_STRING("make boardsource/lulu/rp2040:adaviloper");
                tap_code(KC_ENT);
            }
            return false;
    };
    return true;
}
