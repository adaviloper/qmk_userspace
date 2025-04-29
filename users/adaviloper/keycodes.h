#pragma once

#include QMK_KEYBOARD_H

#define XX KC_NO
#define SPOTLHT LGUI(KC_SPC)
#define OSM_MEH OSM(MOD_MEH)
#define OSM_HYP OSM(MOD_HYPR)
#define LT_SMES LT(_SYMBOL, KC_ESC)
#define TAB_NXT C(KC_TAB)
#define TAB_PRV C(S(KC_TAB))
#define MT_SFSP SFT_T(KC_SPC)
#define LT_FUNC LT(_FUNC, KC_SPC)
#define LT_SYEN LT(_SYSTEM, KC_ENT)
#define LT_REP  LT(_SYSTEM, QK_REP)
#define LT_GALT LT(_GAMING2, KC_LALT)

enum keycodes {
    MAC = QK_USER,
    M_ALT,
    WINDOWS,
    W_ALT,
    LINUX,
#ifdef GAMING_ENABLE
    GAMING,
    G_ALT,
#endif
    RAISE,
#ifdef ART_ENABLE
    ART,
    ART2,
#endif
    FUNC,
    FUNC2,
#ifdef RGBLIGHT_LAYERS
    LIGHTS,
#endif
    ADJUST,
    PR_TLE1,
    PR_TLE2,
    PR_TLE3,
#ifdef CASE_MODES_ENABLE
    KC_MOCK,
    CAP_WRD,
    CAMEL,
    SNAKE,
    KEBAB,
#endif
#ifdef GIT_ENABLE
    GIT_BCK,
    GIT_HRD,
    GIT_RST,
    GIT_SFT,
#endif
    RE_PEAT,
    DBL_EQ,
    TRIP_EQ,
    DBL_CLN,
    OS_ALL,
    OS_COPY,
    OS_FIND,
    OS_NAPP,
    OS_NWIN,
    OS_SPEC,
    OS_URL,
    OS_RFRS,
    OS_SAVE,
    OS_CTAB,
    OS_PSTE,
    OS_CUT,
    OS_REDO,
    OS_SBSP,
    OS_SDEL,
    OS_UNDO,
    OS_SNIP,
    VI_BWRD,
    VI_WORD,
    VI_BSPC,
    VI_DEL,
    NEW_SAFE_RANGE,
};

