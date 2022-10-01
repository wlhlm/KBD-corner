Firmware Configuration
----------------------

This directory contains the firmware configuration for my keyboard . I'm a big
fan of the [QMK firmware][QMKHomepage] which is open source and offers tonnes of
flexibility. Rather than maintaining a fork of QMK I prefer to keep just the
keyboard specific files. QMK is included just as a submodule.

[QMKHomepage]: https://qmk.fm/

### Setup

QMK does not support building keyboard config from outside of its repository,
and since I have chosen to do just that, the keyboard files have to be symlinked
into the QMK tree:

```
$ cd qmk_firmware
$ ln -s ../keyboards/ktec/daisy keyboards/ktec/daisy-wlhlm
```
