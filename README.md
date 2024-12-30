DreymaR's Big Bag of Keyboard Tricks
====================================

### For keyboard controllers/converters such as the USB-2-USB QUICKIE<sup>[¤](#QICO)</sup>, using [Hasu's TMK][TMKG]

* "Extend" layers using Caps Lock as a modifier for navigation/editing from the home position and more
* Angle/Wide ergo modifications to improve wrist angles, hand spacing and right pinky stretch/load effort
* Curl-DH ergo modifications to encourage natural finger curvature (only for Colemak as of now)
* The 4 Tarmak transitional Colemak layouts for learning Colemak or Colemak-Curl in smaller steps if desired
* Mirrored Colemak that allows one-handed typing (normally used as second layout with a switch key)
* In addition, a few other layouts that may interest users

More info
---------

* Run the enclosed MakeFlash script with `-h` for more help and info.
* The MakeFlash script can install the needed AVR tools for Linux, and Git plus TMK before building/flashing.
* The install switches (`-a` and `-g`) can also update existing tools/TMK.
* If you already have TMK, this dir should be placed within or beside the `tmk_keyboard` dir.
* Alternatively, the contents of this dir could be placed directly in the `tmk_keyboard` dir.
* The hexfile folder holds precompiled .hex binaries, most for the USB-2-USB converter; new backups may also go there.
* The unimaps folder holds universal keymaps suitable for all controllers.

* Hasu's PS/2-USB converter currently uses the ATmega32U2 chip, vs the USB-USB controller's ATmega32U4
* To compile for the PS/2-USB converter: `$> ./makeflash_tmk_dreymar.sh -d converter/ps2_usb/ -m Makefile.unimap.rev2`

* On Windows, Win+r then run `devmgmt.msc` for the Device Manager (to check device drivers etc).


Links & notes
-------------

See the [docs folder README][DOCS] or its predecessor, the [DreymaR's Big Bag (USB-2-USB) topic][DBBU] on the [Colemak Forums][CMKF].
There are plenty of explanations and further links in there.

Also, obviously the [main TMK GitHub repo][TMKG].

There are other tools for flashing that you may prefer (as I've had my share of trouble using Atmel Flip on Windows!):

* [QMK Toolbox](https://github.com/qmk/qmk_toolbox/); "a collection of flashing tools packaged into one app. It supports auto-detection and auto-flashing of firmware to keyboards."
  - On Windows: Asked whether to install drivers. Successfully installed a driver for the Hasu device. It showed up in Device Manager as "Atmel USB Devices -> ATmega32U4".
* [DFU-programmer](https://github.com/dfu-programmer/dfu-programmer); "an implementation of the Device Firmware Upgrade class USB driver that enables (...) Atmel chips."
  - This is a commonly used flashing tool on Linux.
* [kp_boot_32u4](https://github.com/ahtn/kp_boot_32u4); "a simple bootloader for the ATmega32u4 family (...). The code size is <1kB and doesn't need drivers on Windows."
  - Command-line-based. Seems compact enough? Installed w/ a Python script. Apparently, KeyPlus below uses it?
* [KeyPlus](https://github.com/ahtn/keyplus); "an easy to use keyboard firmware (...) in beta". Precompiled, w/ a GUI. 
  - On Windows: Didn't find my Hasu (atmega23u4) device, at least not right away...?

Lately I've been using the QMK Toolbox on Windows. It works great.
<br>

_Happy TMK hacking!_
_~ DreymaR_

___
<a name="QICO" title="QWERTY USB Input, Colemak Key Input Emulated">¤</a>: **Q**WERTY **U**SB **I**nput, **C**olemak **K**ey **I**nput **E**mulated (my pet name for USB converters like [Hasu's][HU2U]).

2FIX:
-----
- 

TODO:
-----
- How hard would it be to port this to QMK? Would that work for the Hasu USB-2-USB device? QMK is so popular these days.
	- Casuanoob on the Colemak Discord told me than yes, Atmega32u4 runs QMK and there's support for the Hasu USB-USB device.
		- https://discord.com/channels/409502982246236160/548799170765389834/1316924223200952330
		- https://github.com/qmk/qmk_firmware/tree/master/keyboards/converter/usb_usb/hasu
	- Could the UNIMAP remaps be used as-is? May need some reordering of the enumeration? It's called a `wrapper`, apparently.
		- https://github.com/drashna/qmk_userspace/blob/custom_drashna/docs/wrappers.md
	- Things are done through userspaces and maybe GitHub workflows?
		- https://github.com/qmk/qmk_userspace
- Are UNICODEHEADER and UNICODEFOOTER superseded now, by the handy TMK `UNI[X|W|M]_()` macro syntax (that I devised)? Rewrite?

DONE:
-----
- Added Sym mod variants, merging them and ISOANSIADAPT (4-level keys, ISO-Nor hack) into a new SYMBOLKEYS setting.
	- Also changed the BSLS key to FBsl; now using that for ANSI and the similar NUHS/FHsh key for ISO (re)mappings.
	- The Sym mods should work for some non-Cmk layouts too, like QWERTY and Canary. Dvorak, however, already has a "Sym mod".
- Uncoupled the "soft" Curl mod from "hard" keymaps, removing the '_CA(W)' maps. Instead, Cmk-DH and Extend respect CURLMOD.
- Converted the Forum docs to Markdown+HTML and added them to this repo in a docs folder.
- Nuked that accursed old Workman entry. The Canary and Gralmak layouts constitute better replacements. Kept Dvorak for nostalgics, though.
- Nuked the old DHk ergo mod, keeping only standard DH(m) now. Sorry, user of DHk, but you'll now have to edit it in yourself.
- TMK repo: Pushed tmk_core ST(), MOD_() and UNI[X|W|M]_() #define functions for macros, simplifying typing and unicode input.
- TMK repo: Made a tmk_core type_code() function, so typing (registering/unregistering) key codes is easy and clear.

HOLD:
-----
- Add Extend3 and Extend4 layers, memory permitting? Not necessary, as I don't use them now.


[TMKG]: https://github.com/tmk/tmk_keyboard (Hasu's TMK repository on GitHub)
[DBBU]: http://forum.colemak.com/viewtopic.php?id=2158 (DreymaR's Big Bag of Keyboard Tricks - USB edition)
[DOCS]: ./docs/README.md (The docs folder README, ported from the BigBag USB-2-USB Forum Topic)
[CMKF]: http://forum.colemak.com (Shai's Colemak forums)
[HU2U]: https://geekhack.org/index.php?topic=69169 (Hasu's USB-USB keyboard converter)
