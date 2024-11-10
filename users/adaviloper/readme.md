# Overview

## Description
This contains all of the shared code that is used throughout all of the different keyboards. The majority of the definitions is used for the 3x5 grid of keys around the home row. All of the functionality/features are compartmentalized into their own files and are included on-demand within each keyboard's `rules.mk` and `config.h` files.

### [adaviloper.c](./adaviloper.c)
This is the meat of the operation for every keyboard. Every keyboard will have a `process_record_user` that will first call `process_record_user_adaviloper` which will then fire off a check for every other individual feature file to see if the key needs to be processed. This gives us the flexibility to call our userland files while still providing a mechanism for the keyboard to have its own way of process keyboard-specific keycodes.

For Mac, Windows, and Gaming, we set the default layer in EEPROM. This will be relevant later.

Here is where we'll check if we need to process a [vi_command](./vi_commands.c), an [os_command](./os_commands.c), featured macros or [case modes](./case_modes.c)

### [caps_mock.c](./caps_mock.c)
This was made as a fun little experiment to create a functional that will randomly send a one-shot shift to capitalize the next character that is sent by the keyboard. There are still some edge cases to work out how it determines to shut off, but it still works, more-or-less.

### [case_modes.c](./case_modes.c)
This was created by Andrew Rae (attribution in the source file) for easily being able to create camelCase, snake_case, kebab-case and WORD-constrained caps lock. It's rare to need to enable caps lock for part of a word, so this makes caps lock a bit smarter by automatically turning it off when a word-ending character is detected.

### [combos.c](./combos.c)
Combos are stored. We'll be working under the idea that `KC_COMM` is going to be the combo delimiter. This will help with reducing accidental triggering of combos while typing/rolling and create a consistent location for where combos should be anchored from. These may need to change if I change to a different layout such as Dvorak.

- <,-m>: This is a convenient location for sending Enter.
- <,-.>: Macro for starting a new declarative sentence. Sends a period, space and then a one-shot shift.
- <,-!>: Macro for starting a new exclamatory sentence. Sends an exclamation point, space and then a one-shot shift.
- <,-?>: Macro for starting a new interrogative sentence. Sends a question mark, space and then a one-shot shift.

### [encoders.c](./encoders.c)
Encoder logic is stored here. Nothing super impressive. Left for volume, right for scrolling through tabs. The left encoder on the art layer is used for changing the brush size.

### [git.c](./git.c)
Used for process git keycodes to send common macros for working with the Git CLI.

### [keycodes.h](./keycodes.h)
All keycodes are stored here. Some are feature-lock behind config rules so that we don't needless take up space. The final custom keycode is `PERSONAL_SAFE_RANGE` which is useful for allowing the keyboards to create their own custom keycodes that will be processed in that keyboards `process_record_user` call.

Defined here to be imported around to different features.

### [layers.h](./layers.h)
Just a list of all used layers.

Defined here to be imported around to different features.

### [oled.c](./oled.c)
It's just OLED code.

### [os_commands.c](./os_commands.c) and [vi_commands.c](./vi_commands.c)
These two files contain the processing rules for `OS_*` and `VI_*` keycodes. For each keycode, we check which layer we're on in EEPROM (_MAC, _WINDOWS, _GAMING) and then we'll send over the appropriate key combinations for that command. Most of them are just a matter of swapping GUI and CTRL, but this method allows us to modify each keycode as necessary if they happen to be wildly different or exactly the same.

### [rows.h](./rows.h)
Constant definitions for all 3x5 home-row blocks for each hand are stored here. It should now be at a point, with the pre-processors in the [Lulu keymap](../../keyboards/boardsource/lulu/keymaps/adaviloper/keymap.c) that I'll be able to simply update the `_________________LAYOUT_#$_________________` constants and have a completely different keyboard layout, but with the same home row mods. I'll still need to update the combos, since those are hard-coded to a key, rather than a position.

### [tap_dance.c](./tap_dance.c)
Not used currently. Originally tried doing tap dances with the thumb keys, but the delay between registering a hold and an interrupted tap was too large and made vim navigation more annoying than beneficial.
I'll have to revisit this for non-layer tap functionality. Something like tapping `OS_TAB` once to open a new tab and double tapping to open the recently closed tab. This poses different challenges for how the code is organized across files when features are mixed.
