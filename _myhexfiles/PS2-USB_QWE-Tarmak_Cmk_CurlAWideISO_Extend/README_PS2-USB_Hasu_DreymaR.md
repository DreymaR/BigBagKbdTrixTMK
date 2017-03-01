NOTE:
* Hasu's PS/2-USB converter currently uses the ATmega32U2 chip (vs ATmega32U4 for the USB-USB controller)
* To compile DreymaR's TMK Unimap files for this controller, use these switches:
    $> ./makeflash_tmk_dreymar.sh -d converter/ps2_usb/ -m Makefile.unimap.rev2
    (...if the MakeFlash script is in the tmk_keyboard folder)

Happy PS/2-USB hacking!
DreymaR, 2017-01