#include "layers.h"
#include "keycodes.h"
#include "vi_commands.h"

#include QMK_KEYBOARD_H

void register_vi_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
}

bool process_vi_commands_adaviloper(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VI_BWRD:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                register_vi_keycode(A(KC_LEFT), record);
            } else {
                register_vi_keycode(C(KC_LEFT), record);
            }
            return false;
        case VI_WORD:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                register_vi_keycode(A(KC_RGHT), record);
            } else {
                register_vi_keycode(C(KC_RGHT), record);
            }
            return false;
        case VI_BSPC:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                register_vi_keycode(A(KC_BSPC), record);
            } else {
                register_vi_keycode(C(KC_BSPC), record);
            }
            return false;
        case VI_DEL:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                register_vi_keycode(C(KC_DEL), record);
            } else {
                register_vi_keycode(C(KC_DEL), record);
            }
            return false;
    }

    return true;
};
