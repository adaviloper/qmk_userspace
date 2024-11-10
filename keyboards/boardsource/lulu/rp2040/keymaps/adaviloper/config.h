#define MASTER_LEFT

#define ART_ENABLE
#define CAPS_WORD_IDLE_TIMEOUT 5000
#define GAMING_ENABLE
#define GIT_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_WPM_ENABLE
#define TAPPING_TERM 200
#define RGBLED_NUM 70

#ifndef NO_DEBUG
#    define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT
