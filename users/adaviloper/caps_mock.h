#pragma once

#include QMK_KEYBOARD_H

void enable_caps_mock(void);
void disable_caps_mock(void);

bool process_caps_mock_adaviloper(uint16_t keycode, const keyrecord_t *record);
