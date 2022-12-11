# Duck Orion V2

<!-- ![%KEYBOARD%](imgur.com image replace me!) -->

*A short description of the keyboard/project*

* Keyboard Maintainer: [wlhlm](https://github.com/wlhlm)
* Hardware Supported: Orion Ver2.1
* Hardware Availability: group buy

Make example for this keyboard (after setting up your build environment):

    make duck/orion/v2:default

Flashing example for this keyboard:

    make duck/orion/v2:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

If the board is still running the original firmware, you can enter the bootloader in the following way:

* Hold the `Backspace` key while plugging the keyboard in

If you have already flashed QMK, you can enter the bootloader through one of the following ways:

* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available in your layout
* **Bootmagic reset**: Hold down the `Backspace`key and plug in the keyboard
