#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    FN_CTL,
    ENT_ESC,
    HYPR_MEH,
    CTL_NAV,
    DBL_DOT,
    TAB_NEW_OLD,
    TAB_TAB_WINDOW,
    PASTE_CODE_BLOCK,
    PASTE_QUOTE,
};

#define TD_FNCT TD(FN_CTL)
#define TD_DBDT TD(DBL_DOT)
#define TD_TAB  TD(TAB_NEW_OLD)
#define TD_CTAB TD(TAB_TAB_WINDOW)
#define TD_CBLK TD(PASTE_CODE_BLOCK)
#define TD_PQTE TD(PASTE_QUOTE)

td_state_t cur_dance(tap_dance_state_t *state, bool interruptable);

void fn_reset(tap_dance_state_t *state, void *user_data);
void fn_finished(tap_dance_state_t *state, void *user_data);

void ent_esc_finished(tap_dance_state_t *state, void *user_data);
void ent_esc_reset(tap_dance_state_t *state, void *user_data);

void hyper_meh_finished(tap_dance_state_t *state, void *user_data);
void hyper_meh_reset(tap_dance_state_t *state, void *user_data);

void tab_new_old_finished(tap_dance_state_t *state, void *user_data);
void tab_new_old_reset(tap_dance_state_t *state, void *user_data);

void close_tab_window_finished(tap_dance_state_t *state, void *user_data);
void close_tab_window_reset(tap_dance_state_t *state, void *user_data);

void paste_code_block_finished(tap_dance_state_t *state, void *user_data);
void paste_code_block_reset(tap_dance_state_t *state, void *user_data);

void paste_quote_finished(tap_dance_state_t *state, void *user_data);
void paste_quote_reset(tap_dance_state_t *state, void *user_data);

