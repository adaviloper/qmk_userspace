#include "tap_dance.h"
#include "layers.h"
#include "keycodes.h"

#include QMK_KEYBOARD_H

td_state_t cur_dance(tap_dance_state_t *state, bool interruptable) {
    bool can_be_interrupted = interruptable || false;
    if (state->count == 1) {
        if ((state->interrupted && can_be_interrupted) || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->pressed) return TD_TRIPLE_HOLD;
        else return TD_TRIPLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    else {
        return TD_UNKNOWN;
    }
}

// // Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t fntap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void fn_finished(tap_dance_state_t *state, void *user_data) {
    fntap_state.state = cur_dance(state, true);
    switch (fntap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_FUNC);
            break;
        case TD_DOUBLE_TAP:
            register_code16(SPOTLHT);
            break;
        case TD_DOUBLE_HOLD:
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void fn_reset(tap_dance_state_t *state, void *user_data) {
    switch (fntap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_SPC);
            break;
        case TD_SINGLE_HOLD:
             layer_off(_FUNC);
             break;
        case TD_DOUBLE_TAP:
             unregister_code16(SPOTLHT);
             break;
        case TD_DOUBLE_HOLD:
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    fntap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t ent_esc_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void ent_esc_finished(tap_dance_state_t *state, void *user_data) {
    ent_esc_tap_state.state = cur_dance(state, false);
    switch (ent_esc_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
//            layer_on(_FUNC);
            break;
        case TD_DOUBLE_TAP:
            register_code(KC_ESC);
            break;
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void ent_esc_reset(tap_dance_state_t *state, void *user_data) {
    switch (ent_esc_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
//             layer_off(_FUNC);
             break;
        case TD_DOUBLE_TAP:
             unregister_code(KC_ESC);
             break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    ent_esc_tap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t hyper_mehtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void hyper_meh_finished(tap_dance_state_t *state, void *user_data) {
    hyper_mehtap_state.state = cur_dance(state, true);
    switch (hyper_mehtap_state.state) {
        case TD_SINGLE_TAP:
            set_oneshot_mods(MOD_HYPR);
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
            set_oneshot_mods(MOD_MEH);
            break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_NONE:
        default:
            register_code(KC_NO);
            break;
    }
}

void hyper_meh_reset(tap_dance_state_t *state, void *user_data) {
    switch (hyper_mehtap_state.state) {
        case TD_SINGLE_TAP:
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
            break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    hyper_mehtap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t tab_new_old_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void tab_new_old_finished(tap_dance_state_t *state, void *user_data) {
    tab_new_old_tap_state.state = cur_dance(state, false);
    switch (tab_new_old_tap_state.state) {
        case TD_SINGLE_TAP:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                tap_code16(G(KC_T));
            } else if (eeconfig_read_default_layer() == 1UL<<_LINUX) {
                tap_code16(C(KC_T));
            } else {
                tap_code16(C(KC_T));
            }
            break;
        case TD_DOUBLE_TAP:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                tap_code16(G(S(KC_T)));
            } else if (eeconfig_read_default_layer() == 1UL<<_LINUX) {
                tap_code16(C(S(KC_T)));
            } else {
                tap_code16(C(S(KC_T)));
            }
            break;
        default:
            register_code(KC_NO);
            break;
    }
}

void tab_new_old_reset(tap_dance_state_t *state, void *user_data) {
    switch (tab_new_old_tap_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
             break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    tab_new_old_tap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t close_tab_window_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void close_tab_window_finished(tap_dance_state_t *state, void *user_data) {
    close_tab_window_tap_state.state = cur_dance(state, false);
    switch (close_tab_window_tap_state.state) {
        case TD_SINGLE_TAP:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                tap_code16(G(KC_W));
            } else if (eeconfig_read_default_layer() == 1UL<<_LINUX) {
                tap_code16(C(KC_W));
            } else {
                tap_code16(C(KC_W));
            }
            break;
        case TD_SINGLE_HOLD:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                // tap_code16(G(S(KC_W)));
            } else if (eeconfig_read_default_layer() == 1UL<<_LINUX) {
                tap_code16(S(C(KC_W)));
            } else {
                // tap_code16(C(S(KC_W)));
            }
            break;
        default:
            register_code(KC_NO);
            break;
    }
}

void close_tab_window_reset(tap_dance_state_t *state, void *user_data) {
    switch (close_tab_window_tap_state.state) {
        case TD_SINGLE_TAP:
            break;
        case TD_SINGLE_HOLD:
            break;
        case TD_DOUBLE_TAP:
             break;
        case TD_DOUBLE_HOLD:
            break;
        case TD_TRIPLE_TAP:
            break;
        case TD_NONE:
        default:
             unregister_code(KC_NO);
    }
    close_tab_window_tap_state.state = TD_NONE;
}
