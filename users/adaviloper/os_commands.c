#include "layers.h"
#include "keycodes.h"
#include "os_commands.h"

#include QMK_KEYBOARD_H

void register_os_keycode(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
    }
}

bool process_os_commands_adaviloper(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    switch (keycode) {
        case OS_ALL:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_A));
                } else {
                    tap_code16(C(KC_A));
                }
            }
            return false;
        case OS_COPY:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_C));
                } else {
                    tap_code16(C(KC_C));
                }
            }
            return false;
        case OS_FIND:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_F));
                } else {
                    tap_code16(C(KC_F));
                }
            }
            return false;
        case OS_NAPP:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_TAB));
                } else {
                    tap_code16(A(KC_TAB));
                }
            }
            return false;
        case OS_NWIN:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_TILD));
                } else {
                    tap_code16(G(S(KC_TILD)));
                }
            }
            return false;
        case OS_SPEC:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(A(KC_I)));
                } else {
                    tap_code16(C(KC_F));
                }
            }
            return false;
        case OS_URL:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_L));
                } else {
                    tap_code16(C(KC_L));
                }
            }
            return false;
        case OS_RFRS:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_R));
                } else {
                    tap_code16(C(KC_R));
                }
            }
            return false;
        case OS_SAVE:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_S));
                } else {
                    tap_code16(C(KC_S));
                }
            }
            return false;
        case OS_CTAB:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_W));
                } else {
                    tap_code16(C(KC_W));
                }
            }
            return false;
        case OS_PSTE:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_V));
                } else {
                    tap_code16(C(KC_V));
                }
            }
            return false;
        case OS_CUT:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(KC_X));
                } else {
                    tap_code16(C(KC_X));
                }
            }
            return false;
        case OS_REDO:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                register_os_keycode(G(S(KC_Z)), record);
            } else {
                register_os_keycode(C(KC_Y), record);
            }
            return false;
        case OS_UNDO:
            if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                register_os_keycode(G(KC_Z), record);
            } else {
                register_os_keycode(C(KC_Z), record);
            }
            return false;
        case OS_SNIP:
            if (record->event.pressed) {
                if (eeconfig_read_default_layer() == 1UL<<_MAC || eeconfig_read_default_layer() == 1UL<<_MAC_ALT) {
                    tap_code16(G(S(C(KC_4))));
                } else {
                    tap_code16(G(S(KC_S)));
                }
            }
            return false;
        case OS_SBSP:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    tap_code(KC_BSPC);
                    tap_code(KC_BSPC);
                    tap_code(KC_BSPC);
                }
                tap_code(KC_BSPC);
            }
            return false;
    }

    return true;
};
