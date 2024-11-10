#pragma once

#include "rows.h"
#include "layers.h"
#include "g/keymap_combo.h"
#include "combos.h"
#include "keycodes.h"
#include "tap_dance.h"
#include "os_commands.h"
#include "vi_commands.h"
// #include "repeat_keys.h"

// #ifdef CASE_MODES_ENABLE
//     #include "case_modes.h"
//     #include "caps_mock.h"
// #endif

#ifdef ENCODER_ENABLE
    #include "encoders.h"
#endif

#ifdef GIT_ENABLE
    #include "git.h"
#endif

// #ifdef OLED_ENABLE
//     #include "oled.h"
// #endif

// #ifdef RGBLIGHT_LAYERS
//     #include "rgblight_layers.h"
// #endif

bool process_record_user_adaviloper(uint16_t keycode, keyrecord_t *record);
