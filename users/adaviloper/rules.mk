COMBO_ENABLE = yes
LTO_ENABLE = yes

INTROSPECTION_KEYMAP_C = adaviloper.c

SRC += tap_dance.c

VPATH += keyboards/gboards

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += case_modes.c
  SRC += caps_mock.c
endif

ifdef GIT_ENABLE
  SRC += git.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
  SRC += oled.c
endif

SRC += os_commands.c
SRC += vi_commands.c
SRC += repeat_keys.c
