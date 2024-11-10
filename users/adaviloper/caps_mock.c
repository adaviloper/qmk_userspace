#include "caps_mock.h"

static bool is_upper_case(void){
    return rand() & 1;
}

static bool caps_mock_is_active = false;

void enable_caps_mock(void) {
    caps_mock_is_active = true;
}

void disable_caps_mock(void) {
    caps_mock_is_active = false;
}

bool process_caps_mock_adaviloper(uint16_t keycode, const keyrecord_t *record) {
    if (!caps_mock_is_active) {
        return true;
    }
    if ((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX)
        || (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX)) {
        // Earlier return if this has not been considered tapped yet
        if (record->tap.count == 0)
            return true;
        keycode = keycode & 0xFF;
    }

    if (keycode >= QK_LAYER_TAP && keycode <= QK_ONE_SHOT_LAYER_MAX) {
        // let special keys and normal modifiers go through
        return true;
    }
    switch (keycode) {
        case KC_ESC:
            disable_caps_mock();
            return true;
        case KC_A ... KC_Z:
            if (record->event.pressed) {
                if (is_upper_case()) {
                    set_oneshot_mods(MOD_BIT(KC_LSFT));
                } else {
                    clear_oneshot_mods();
                }
                return true;
            }
    }

    return true;
}
