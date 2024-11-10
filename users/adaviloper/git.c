#include "git.h"
#include "keycodes.h"

#include QMK_KEYBOARD_H

bool process_git_adaviloper(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GIT_ACP:
            if (record->event.pressed) {
                SEND_STRING("gaa; gcmsg \"\"; gpsup");
                for (int i = 0; i < 8; i++) {
                    tap_code(KC_LEFT);
                }
            }
            return false;
        case GIT_BCK:
            if (record->event.pressed) {
                SEND_STRING("gco -");
            }
            return false;
        case GIT_GCP:
            if (record->event.pressed) {
                SEND_STRING("gaa; gcmsg \"$(git_commit_prefix) \"; gpsup");
                for (int i = 0; i < 8; i++) {
                    tap_code(KC_LEFT);
                }
            }
            return false;
        case GIT_HRD:
            if (record->event.pressed) {
                SEND_STRING("git reset --hard HEAD~1");
            }
            return false;
        case GIT_RST:
            if (record->event.pressed) {
                SEND_STRING("git reset --hard");
            }
            return false;
        case GIT_SFT:
            if (record->event.pressed) {
                SEND_STRING("git reset --soft HEAD~1");
            }
            return false;
    };
    return true;
}
