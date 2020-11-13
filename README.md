DreymaR's Big Bag of Keyboard Tricks
====================================

### For keyboard controllers/converters such as the USB-2-USB QUICKIE<sup>[¤](#QICO)</sup>, using [Hasu's TMK][TMKG]

* "Extend" layers using Caps Lock as a modifier for navigation/editing from the home position and more
* Angle/Wide ergo modifications to improve wrist angles, hand spacing and right pinky stretch/load effort
* Curl-DH ergo modifications to encourage natural finger curvature (only for Colemak as of now)
* The 4 Tarmak transitional Colemak layouts for learning Colemak or Colemak-Curl in smaller steps if desired
* Mirrored Colemak that allows one-handed typing (normally used as second layout with a switch key)

More info
---------

* Run the enclosed MakeFlash script with -h for more help and info.
* The MakeFlash script can install the needed AVR tools for Linux, and Git plus TMK before building/flashing.
* The install switches (-a and -g) can also update existing tools/TMK.
* If you already have TMK, my dir should be placed within or beside the tmk_keyboard dir.
* Alternatively, the contents of my dir could be placed directly in the tmk_keyboard dir.
* The hexfile folder holds precompiled .hex binaries, most for the USB-2-USB converter; new backups may also go there.
* The unimaps folder holds universal keymaps suitable for all controllers.

* Hasu's PS/2-USB converter currently uses the ATmega32U2 chip, vs the USB-USB controller's ATmega32U4
* To compile for the PS/2-USB converter: $> ./makeflash_tmk_dreymar.sh -d converter/ps2_usb/ -m Makefile.unimap.rev2


Links & notes
-------------

See the [DreymaR's Big Bag (USB-2-USB) topic][DBBU] on the [Colemak Forums][CMKF].
There are plenty of explanations and further links in there.

Also, obviously the [main TMK GitHub repo][TMKG].


_Happy TMK hacking!_
_DreymaR, 2020-11_

___
<a name="QICO" title="QWERTY USB Input, Colemak Key Input Emulated">¤</a>: **Q**WERTY **U**SB **I**nput, **C**olemak **K**ey **I**nput **E**mulated (my pet name for USB converters like [Hasu's][HU2U]).

[TMKG]: https://github.com/tmk/tmk_keyboard (Hasu's TMK repository on GitHub)
[DBBU]: http://forum.colemak.com/viewtopic.php?id=2158 (DreymaR's Big Bag of Keyboard Tricks - USB edition)
[CMKF]: http://forum.colemak.com (Shai's Colemak forums)
[HU2U]: https://geekhack.org/index.php?topic=69169 (Hasu's USB-USB keyboard converter)
