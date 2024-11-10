#include "adaviloper.h"
#include <stdint.h>

#include QMK_KEYBOARD_H

tap_dance_action_t tap_dance_actions[] = {
    [FN_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_finished, fn_reset),
    [ENT_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_esc_finished, ent_esc_reset),
    [HYPR_MEH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, hyper_meh_finished, hyper_meh_reset),
    [TAB_NEW_OLD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_new_old_finished, tab_new_old_reset),
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
    layer_state = default_layer;
}

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user_adaviloper(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
#ifdef CASE_MODES_ENABLE
    if (!process_case_modes(keycode, record)) { return false; }
    if (!process_caps_mock_adaviloper(keycode, record)) { return false; };
#endif
#ifdef GIT_ENABLE
    if (!process_git_adaviloper(keycode, record)) { return false; }
#endif
    if (!process_os_commands_adaviloper(keycode, record)) { return false; };
    if (!process_vi_commands_adaviloper(keycode, record)) { return false; };
    mod_state = get_mods();
    switch (keycode) {
        case MAC:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_MAC);
            }
            return false;
        case M_ALT:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_MAC_ALT);
            }
            return false;
        case WINDOWS:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_WINDOWS);
            }
            return false;
        case W_ALT:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_WINDOWS_ALT);
            }
            return false;
        case LT_REP:
            if (record->tap.count && record->event.pressed) {
                uint16_t last_key = get_last_keycode();
                tap_code16(last_key);
                return false;  // Skip default handling.
            }
            return true;  // Continue default handling.
#ifdef ART_ENABLE
        case ART:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_ART);
            }
            return false;
        case ART2:
            if (record->event.pressed) {
                layer_on(_ART2);
            } else {
                layer_off(_ART2);
            }
            return false;
#endif
#ifdef GAMING_ENABLE
        case GAMING:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_GAMING);
            }
            return false;
#endif
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_SYMBOL, _RAISE, _ADJUST);
            }
            return false;
        case FUNC:
            if (record->event.pressed) {
                layer_on(_FUNC);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            } else {
                layer_off(_FUNC);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            }
            return false;
        case FUNC2:
            if (record->event.pressed) {
                layer_on(_FUNC2);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            } else {
                layer_off(_FUNC2);
                update_tri_layer(_FUNC, _FUNC2, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
#ifdef RGBLIGHT_ENABLE
        case LIGHTS:
            if (record->event.pressed) {
                layer_on(_LIGHTS);
            } else {
                layer_off(_LIGHTS);
            }
            return false;
#endif
        case PR_TLE1:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
                register_code(KC_LALT);
                tap_code(KC_DEL);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
                tap_code(KC_DEL);
                SEND_STRING("LPR-");
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                unregister_code(KC_LALT);
                SEND_STRING(": ");
            }
            // Task/gn XXXXX/some description
            return false;
        case PR_TLE2:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
                register_code(KC_LALT);
                tap_code(KC_DEL);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
                tap_code(KC_DEL);
                SEND_STRING("RET-");
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                unregister_code(KC_LALT);
                SEND_STRING(": ");
            }
            // Task/gn XXXXX/some description
            return false;
        case PR_TLE3:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
                register_code(KC_LALT);
                tap_code(KC_DEL);
                tap_code(KC_DEL);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
                tap_code(KC_DEL);
                SEND_STRING("[UTTT-");
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                tap_code(KC_DEL);
                unregister_code(KC_LALT);
                SEND_STRING("] - ");
            }
            // Task/gn XXXXX/some description
            return false;
#ifdef CASE_MODES_ENABLE
        case KC_MOCK:
            if (record->event.pressed) {
                /* enable_caps_mock(); */
            }
            return false;
        case CAMEL:
            if (record->event.pressed) {
                enable_xcase_with(OSM(MOD_LSFT));
            }
            return false;
        case SNAKE:
            if (record->event.pressed) {
                enable_xcase_with(KC_UNDS);
            }
            return false;
        case KEBAB:
            if (record->event.pressed) {
                enable_xcase_with(KC_MINS);
            }
            return false;
        case CST_CSE:
            if (record->event.pressed) {
                enable_xcase();
            }
            return false;
#endif // CASE_MODES_ENABLE
        case DBL_EQ:
            if (record->event.pressed) {
                SEND_STRING("==");
            }
            return false;
        case TRIP_EQ:
            if (record->event.pressed) {
                SEND_STRING("===");
            }
            return false;
        case DBL_CLN:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            return false;
    }
    /* if (!process_repeat_key(keycode, record, RE_PEAT)) { return false; } */
    return true;
}
