#pragma once

#include "adaviloper.h"

#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...)                                 LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_4x12_wrapper(...)                      LAYOUT_ortho_4x12(__VA_ARGS__)

#define _________________NUMBER_L0_________________         KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBER_R0_________________         KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________QWERTY_L1_________________         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________         KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________CARPALX_L1________________         KC_Q,    KC_G,    KC_P,    KC_L,    KC_W
#define _________________CARPALX_L2________________         KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _________________CARPALX_L3________________         KC_Z,    KC_X,    KC_C,    KC_V,    KC_J

#define _________________CARPALX_R1________________         KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN
#define _________________CARPALX_R2________________         KC_I,    KC_A,    KC_E,    KC_O,    KC_H
#define _________________CARPALX_R3________________         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________DVORAK_L1_________________         KC_SCLN, KC_V,    KC_W,   KC_P,     KC_Y
#define _________________DVORAK_L2_________________         KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________         KC_Z,    KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________         KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________         KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________         KC_B,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________ALT_L1____________________         _________________CARPALX_L1________________
#define _________________ALT_L2____________________         _________________CARPALX_L2________________
#define _________________ALT_L3____________________         _________________CARPALX_L3________________

#define _________________ALT_R1____________________         _________________CARPALX_R1________________
#define _________________ALT_R2____________________         _________________CARPALX_R2________________
#define _________________ALT_R3____________________         _________________CARPALX_R3________________

#define _________________LAYOUT_L1_________________         _________________QWERTY_L1_________________
#define _________________LAYOUT_L2_________________         _________________QWERTY_L2_________________
#define _________________LAYOUT_L3_________________         _________________QWERTY_L3_________________

#define _________________LAYOUT_R1_________________         _________________QWERTY_R1_________________
#define _________________LAYOUT_R2_________________         _________________QWERTY_R2_________________
#define _________________LAYOUT_R3_________________         _________________QWERTY_R3_________________

#ifdef GAMING_ENABLE
#define _________________GAMING_L0_________________         _________________NUMBER_L0_________________
#define _________________GAMING_L1_________________         _________________QWERTY_L1_________________
#define _________________GAMING_L2_________________         _________________QWERTY_L2_________________
#define _________________GAMING_L3_________________         _________________QWERTY_L3_________________

#define _________________GAMING2_L1________________         KC_1,    KC_2,    KC_3,    KC_F1,   KC_F2
#define _________________GAMING2_L2________________         KC_4,    KC_5,    KC_6,    KC_F3,   KC_F4
#define _________________GAMING2_L3________________         KC_7,    KC_8,    KC_9,    KC_0,    _______

#define _________________GAMING_R0_________________         _________________NUMBER_R0_________________
#define _________________GAMING_R1_________________         _________________QWERTY_R1_________________
#define _________________GAMING_R2_________________         _________________QWERTY_R2_________________
#define _________________GAMING_R3_________________         _________________QWERTY_R3_________________
#endif

#define _________________FUNC_L0___________________         _______, _______, _______, _______, _______
#define _________________FUNC_L1___________________         _______, VI_WORD, _______, _______, KC_HOME
#define _________________FUNC_L2___________________         _______, _______, KC_PGDN, _______, _______
#define _________________FUNC_L3___________________         _______, _______, _______, _______, VI_BWRD

#define _________________FUNC_R0___________________         _______, _______, _______, _______, _______
#define _________________FUNC_R1___________________         KC_END,  KC_PGUP, _______, _______, _______
#define _________________FUNC_R2___________________         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________FUNC_R3___________________         _______, _______, _______, _______, _______

#ifdef GIT_ENABLE
#define _________________GIT_L0____________________         _______, _______, _______, _______, _______
#define _________________GIT_L1____________________         _______, _______, _______, GIT_RST, _______
#define _________________GIT_L2____________________         _______, GIT_SFT, _______, _______, _______
#define _________________GIT_L3____________________         _______, _______, _______, _______, GIT_BCK

#define _________________GIT_R0____________________         _______, _______, _______, _______, _______
#define _________________GIT_R1____________________         _______, _______, _______, _______, _______
#define _________________GIT_R2____________________         GIT_HRD, _______, _______, _______, _______
#define _________________GIT_R3____________________         _______, _______, _______, _______, _______
#endif

#define _________________RAISE_L1__________________         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_SLSH
#define _________________RAISE_L2__________________         KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_ASTR
#define _________________RAISE_L3__________________         KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MINS

#define _________________RAISE_R1__________________         KC_COLN, KC_7,    KC_8,    KC_9,    KC_0
#define _________________RAISE_R2__________________         KC_DLR,  KC_4,    KC_5,    KC_6,    KC_PLUS
#define _________________RAISE_R3__________________         KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT

#define _________________SYMBOL_L1_________________         KC_GRV,  KC_LABK, KC_RABK, KC_DQUO, KC_PERC
#define _________________SYMBOL_L2_________________         KC_HASH, KC_MINS, KC_PLUS, KC_EQL,  KC_CIRC
#define _________________SYMBOL_L3_________________         KC_EXLM, KC_SLSH, KC_ASTR, KC_BSLS, KC_TILD

#define _________________SYMBOL_R1_________________         KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_DOT
#define _________________SYMBOL_R2_________________         KC_DLR,  KC_COLN, KC_LPRN, KC_RPRN, KC_PIPE
#define _________________SYMBOL_R3_________________         DBL_CLN, KC_AT,   KC_LCBR, KC_RCBR, KC_QUES

#define _________________SYSTEM_L0_________________         _______, _______, _______, _______, _______
#define _________________SYSTEM_L1_________________         _______, OS_CTAB, OS_SPEC, OS_RFRS, TD_TAB
#define _________________SYSTEM_L2_________________         OS_ALL,  OS_SAVE, OS_URL,  OS_FIND, PR_TLE1
#define _________________SYSTEM_L3_________________         OS_UNDO, OS_CUT,  OS_COPY, OS_PSTE, PR_TLE2

#define _________________SYSTEM_R0_________________         _______, _______, _______, _______, _______
#define _________________SYSTEM_R1_________________         OS_REDO, _______, _______, _______, _______
#define _________________SYSTEM_R2_________________         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________SYSTEM_R3_________________         _______, CAP_WRD, CAMEL,   SNAKE,   KEBAB
// #define _________________SYSTEM_R3_________________         PR_TLE3, CW_TOGG, _______, _______, _______

#define ______THUMB_3_KEY_L______                                    OS_SNIP, LT_SMES, LT_REP
#define __________THUMB_4_KEY_L___________                  OS_SNIP, KC_NO,   LT_SMES, LT_REP

#define ______THUMB_3_KEY_R______                           LT_FUNC, RAISE,   ADJUST
#define __________THUMB_4_KEY_R___________                  LT_FUNC, RAISE,   C(KC_B),   ADJUST


