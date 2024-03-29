# yacobo Model M Replacement PCB (SSK configuration)

Model M controller based on the Bluepill MCU board developed by sje-mse.

[Main project page](https://github.com/sje-mse/yacobo)

* Keyboard Maintainer: [wlhlm](https://github.com/wlhlm)
* Hardware Supported: yacobo v1
* Hardware Availability: orderable through PCB fab houses using provided gerber files

Make example for this keyboard (after setting up your build environment):

    make modelm/yacobo:default

## Bootloader

As the Blupill boards do not come with a suitable bootloader from the factory,
follow the instructions on the yacobo page for installing the stm32duino loader.

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the Escape key and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (Fn+Esc)

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide)
for more information. Brand new to QMK? Start with our
[Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Details

This QMK configuration was made with the help of the following matrix chart:

![IBM Model M SSK matrix](https://geekhack.org/index.php?action=dlattach;topic=59027.0;attach=66730;image)
([Source](https://geekhack.org/index.php?topic=59027.0))
