# TIGER80

A customizable 80% HOTSWAP keyboard.

* Keyboard Maintainer: [moyi4681](https://github.com/moyi4681)
* Hardware Supported: KBDFANS
* Hardware Availability: [kbdfans](https://kbdfans.myshopify.com/)

Make example for this keyboard (after setting up your build environment):

    make kbdfans/tiger80:default

If you have the Lite model use the following to enable RGB underglow:

    make kbdfans/tiger80/lite:default

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Esc key)
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
