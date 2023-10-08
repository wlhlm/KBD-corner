# Daisy

![Daisy PCB](https://cdn.shopify.com/s/files/1/2711/4238/products/HTB1Pj1UggMPMeJjy1Xcq6xpppXa7_1024x1024.jpg)

A 40% keyboard kit sold by KPrepublic.

* Keyboard Maintainer: [westfoxtrot](https://github.com/westfoxtrot)
* Hardware Supported: Daisy PCB Rev.1, Daisy PCB Rev.2
* Hardware Availability: [KPrepublic](https://kprepublic.com/products/daisy-40-custom-keyboard-pcb)
* PCB Source: https://github.com/ktec-hq/Daisy

Make example for this keyboard (after setting up your build environment):

    make ktec/daisy:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Flashing the firmware onto the keyboard

The Daisy comes with a HID bootloader from the factory but with custom VID and PID rather than the well supported Teensy IDs. It doesn't need an OS driver, but instead a HID flashing tool that understands the custom IDs. If you have access to an AVR programmer, consider replacing the factory bootloader with one of the more standard ones.

1. To enter flash mode, disconnect the keyboard first. Then, hold the leftmost key in the top row (Escape key) while reconnecting the keyboard.
2. To flash the .hex file, use one of the following tools:
   - `hid_bootloader_cli` utlity from the [TKG Toolkit](https://github.com/kairyu/tkg-toolkit) (as of 2017-10-03, only [this old version](https://github.com/kairyu/tkg-toolkit/blob/b14c67ca8bc84c07e5fc6b2e01ae4002b808243a/windows/bin/hid_bootloader_cli.exe) works under Windows):

         hid_bootloader_cli -mmcu=atmega32u4 ktec_daisy_default.hex

   - alternatively, a manually modified version of `hid_bootloader_cli` that supports the `1209:2327` ID of the Daisy bootloader
   - [YDKB reflash tool](https://ydkb.io/?daisy) (proprietary)

## Additional features

The Daisy has a controllable indicator under the Esc key in addition to Capslock. This LED is connected to the `D1` pin of the MCU but unused in the default configuration.
