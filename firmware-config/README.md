Firmware Configuration
----------------------

This directory contains the firmware configuration for my keyboard . I'm a big
fan of the [QMK firmware][QMKHomepage] which is open source and offers tonnes of
flexibility. Rather than maintaining a fork of QMK I prefer to keep just the
keyboard specific files. QMK is included just as a submodule.

[QMKHomepage]: https://qmk.fm/

### Setup

QMK does not support building keyboard configs from outside of its repository,
however there is a workaround using symlinks using the following method:

```
$ cd qmk_firmware
$ ln -s ../keyboards/ktec/daisy keyboards/ktec/daisy_wlhlm
```

After you ran use the QMK CLI like so:
```
$ qmk compile -kb ktec/daisy_wlhlm -km default
```
