#include "adaviloper.h"

#include QMK_KEYBOARD_H
#define MAIN_UNDERGLOW_START 0
#define UNDERGLOW_LED_PER_HALF 6
#define PER_KEY_LED_PER_HALF 29
#define MAIN_PER_KEY_START (MAIN_UNDERGLOW_START + UNDERGLOW_LED_PER_HALF)
#define SPLIT_UNDERGLOW_START (MAIN_PER_KEY_START + PER_KEY_LED_PER_HALF)
#define SPLIT_PER_KEY_START (SPLIT_UNDERGLOW_START + UNDERGLOW_LED_PER_HALF)


const rgblight_segment_t PROGMEM mac_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {MAIN_UNDERGLOW_START,  UNDERGLOW_LED_PER_HALF, 0, 0, 255},
    {SPLIT_UNDERGLOW_START, UNDERGLOW_LED_PER_HALF, 0, 0, 255}
//    {SPLIT_PER_KEY_START + 12, 4, 85, 255, 255} // VIM
);
const rgblight_segment_t PROGMEM windows_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//    {0, 7, 140, 255, 255},
    {MAIN_UNDERGLOW_START,  UNDERGLOW_LED_PER_HALF, 140, 255, 255},
    {SPLIT_UNDERGLOW_START, UNDERGLOW_LED_PER_HALF, 140, 255, 255}
);
#ifdef GAMING_ENABLE
const rgblight_segment_t PROGMEM gaming_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {MAIN_UNDERGLOW_START,  UNDERGLOW_LED_PER_HALF, 85, 255, 255},
//    {MAIN_PER_KEY_START + 8,  1, 21, 255, 255},
//    {MAIN_PER_KEY_START + 14,  3, 21, 255, 255},
    {SPLIT_UNDERGLOW_START, UNDERGLOW_LED_PER_HALF, 85, 255, 255}
);
#endif
const rgblight_segment_t PROGMEM symbol_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {MAIN_UNDERGLOW_START,  UNDERGLOW_LED_PER_HALF, 180, 255, 255},
    {SPLIT_UNDERGLOW_START, UNDERGLOW_LED_PER_HALF, 180, 255, 255}
);
const rgblight_segment_t PROGMEM adjust_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {MAIN_UNDERGLOW_START,  UNDERGLOW_LED_PER_HALF, 0, 255, 255},
    {SPLIT_UNDERGLOW_START, UNDERGLOW_LED_PER_HALF, 0, 255, 255}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [_MAC] = mac_rgb_layer,    // Overrides caps lock layer
    [_MAC_ALT] = mac_rgb_layer,    // Overrides caps lock layer
    [_WINDOWS] = windows_rgb_layer,    // Overrides other layers
    [_WINDOWS_ALT] = windows_rgb_layer,    // Overrides other layers
#ifdef GAMING_ENABLE
    [_GAMING] = gaming_rgb_layer,     // Overrides other layers
#endif
    [_SYMBOL] = symbol_rgb_layer,
    [_ADJUST] = adjust_rgb_layer
);

void keyboard_post_init_kb(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_MAC, layer_state_cmp(state, _MAC));
    rgblight_set_layer_state(_WINDOWS, layer_state_cmp(state, _WINDOWS));
    rgblight_set_layer_state(_SYMBOL, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
#ifdef GAMING_ENABLE
    rgblight_set_layer_state(_GAMING, layer_state_cmp(state, _GAMING));
#endif
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_SYMBOL, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
    return state;
}
