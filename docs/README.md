DreymaR's Big Bag of Keyboard Tricks for TMK/USB
================================================

For general info on the Big Bag of Keyboard Tricks, consult the [**Big Bag of Tricks**][BBoT] pages. <br>
Select the controller platform icon to make the purple info boxes show relevant info for controllers and USB-2-USB devices.

This README is based on the now outdated [Colemak Forum BigBag for TMK topic][BBTU].
<br><br>

---

<br><br>

<h2>DREYMAR'S BIG BAG OF TRICKS for QUICKIE USB-2-USB devices</h2>

Chapters 1–3 correspond to BigBag chapters with links in the table below, while chapter 4 is on this page only.

<i>WARNING - Some Assembly May Be Required (if you want a specific locale variant for instance)</i>

<b>[1]    <ins>Character/Key Mapping Layers</ins></b><br>
<b>[1.1]</b> (My <b><a href="https://dreymar.colemak.org/layers-colemaked.html?platform=tmk">Colemak[eD]</a> AltGr mappings</b>)<br>
<b>[1.2]</b> <b><a href="https://dreymar.colemak.org/layers-extend.html?platform=tmk">Extend layers</a></b> using Caps Lock (and Tab) as switch modifier(s) for navigation/editing/browsing/etc from near the home position<br>

<b>[2]    <ins>Ergonomic Key Remappings</ins></b><br>
<b>[2.1]</b> <a href="https://dreymar.colemak.org/ergo-mods.html?platform=tmk#angle-wide"><b>Angle/Wide ergo modifications</b></a> to improve wrist angles, hand spacing and right pinky stretch/load effort<br>
<b>[2.2]</b> <a href="https://dreymar.colemak.org/ergo-mods.html?platform=tmk#curl-dh"><b>Colemak-DH</b></a> alias the <b>Curl(DH)</b> ergo mod (deprioritize middle columns without keys changing fingers)<br>
<b>[2.3]</b> <a href="https://dreymar.colemak.org/ergo-mods.html?platform=tmk#symbols"><b>Symbol key mods</b></a> for the adventurous (better apostrophe and/or hyphen positions)<br>
<b>[2.4]</b> <a href="https://dreymar.colemak.org/ergo-mods.html?platform=tmk#modifiers"><b>Modifier modness</b></a> for the adventurous (Sticky, One-shot etc; Work-In-Progress)<br>

<b>[3]    <ins>Layout Variants</ins></b><br>
<b>[3.1]</b> <b><a href="https://dreymar.colemak.org/tarmak-intro.html?platform=tmk">Tarmak</a> transitional Colemak</b> layouts for learning Colemak in smaller steps if so desired<br>
<b>[3.2]</b> (<b><a href="https://dreymar.colemak.org/variants.html?platform=tmk#locales">Locale</a></b> and phonetic layout variants)<br>
<b>[3.3]</b> <a href="https://dreymar.colemak.org/variants.html?platform=tmk#mirror"><b>Mirrored Colemak</b></a> that allows one-handed typing without extra learning<br>

<b>[4]    <ins>Download and Setup</ins></b><br>
<b>[4.1]</b> <b>[Download and Install](#download-and-install)</b><br>
<b>[4.2]</b> <b>[Keymap Configuration](#keymap-configuration)</a></b><br>
<b>[4.3]</b> <b>[Device Flashing](#device-flashing)</b><br>
<b>[4.4]</b> <b>[Hardware Implementations](#hardware-implementations)</b><br>

<b>[–]    <ins>Links/Done/Todo</ins></b>

<br><br>

---

<br><br>

<h2>[-]    <ins>Introduction</ins></h2>

This page explains what a <b>QUICKIE USB-2-USB device</b> is, and what I've managed to implement on <b><a href="https://geekhack.org/index.php?topic=69169.0">Hasu's USB to USB keyboard converter</a></b> using his <b><a href="https://github.com/tmk/tmk_keyboard">TMK Keyboard Firmware Collection</a></b> toolkit. If you're eager to get started before reading the details, you may jump directly to the Download and Setup sections below.

<br>
<img src="img/USB2USB-x3_YangDigi_GeekHack-Topic80421_GadOE.jpg">
<i><a href="https://geekhack.org/index.php?topic=80421">GeekHack user yangdigi</a>'s comparison of USB-2-USB devices: Arduino Leonardo-type, Hasu's device and his own Pro Micro device. Scale: Hasu's device is about 6 cm (2") long.</i><br>
<br>

Look at those beauties, heh. I've decided to call this kind of device a <b>QUICKIE</b> (QWERTY USB In, Colemak Key Input Emulated)! Hehe. More proper names are "<b>USB-2-USB</b>" or "<b>USB to USB converter</b>" device, as you may of course use it for non-Colemak layouts (and as my name is silly).

This non-OS-specific solution doesn't have the full power of layout installs, but it's very interesting. A USB-to-USB device that plugs between the keyboard and whatever you're connecting your keyboard to, provides an XKB/Win/Mac/what-have-you independent solution that can accommodate many of my tricks! For people having to deal with zealous IT security rules, this may be the only solution short of getting an expensive remappable keyboard. It could let you type Colemak+Extend to, say, a PlayStation or other device where you can't control the layout directly. It could let you pair code using Colemak+Extend while your mate uses QWERTY (poor thing!) on the same computer. And it could be fun to make one yourself if you're adventurous and DIY oriented!

The common solution is a microcontroller (such as Atmel's AtMega32 chips; Arduino Teensy 2+ or Pro Micro are good choices) with USB, coupled with a USB Host "shield" (separate little PCB) that lets you plug your keyboard into it. It'll mount itself as a HID keyboard, that is, a run-of-the-mill USB keyboard that almost any device accepts.

There are other options, too: You could have a <b><a href="https://geekhack.org/index.php?topic=14618.0">PS/2-USB converter</a></b> instead, or various <b><a href="https://geekhack.org/index.php?topic=72052.0">keyboard controllers</a></b> attached to or built into the keyboard itself! Most of these can use the same "Unimap" layout code, so if you're interested in one of those variants then check it out.

There are several possible ways of programming a USB-2-USB device. Essentially you have to:
1) Connect the device in <b>Bootloader</b> mode which means it can be programmed
2) Get some code and compile it for the device, or use a pre-compiled <b>HEX</b> file. There's even an online layout designer for a less techy option.
3) <b>Flash</b> the .hex file to the device's static memory
4) <b>Reset</b> the device (or just unplug and replug it) to reactivate application mode so it works

An advantage of my TMK-based implementation is that you can pick and choose most of the enhancements as modules:
* The AngleWide mods are keymap types so they work with any layout you choose, including QWERTY or Dvorak
* The Extend layers and switch keys are options that should work with nearly any existing layout
* The Curl(DH) mod for Colemak layouts and SymbolKey modifications use separate modular switches
* Mirrored Colemak and Tarmak (transitional Colemak) are separate layouts.
Freedom of choice through <b>modularity</b> is an ideal in the DreymaR world, as it is in Linux.

<br><br>

---

<br><br>

<h2>[1]    <ins>Character/Key Mapping Layers</ins></h2>

<br><h3>[1.1]    <s>COLEMAK[eD] - EDITION DREYMAR</s></h3>

A USB-2-USB device remaps only key strokes, not character input events. So key mods like layout and ergo remappings are possible, but not mods that send glyphs. Your dead keys and AltGr mappings will work as they do without the device, and you may only move their keys around as they are.

Sorry, but AltGr/DeadKey glyph mappings such as the powerful Colemak[eD] below are for the most part up to the active layout on the machine you're typing to.

In all honesty though, <a href="https://github.com/tmk/tmk_keyboard/wiki/FAQ-Keymap">it is possible to send Unicode</a> with methods such as Windows' Alt+NumPad(####) defined for instance as TMK macros. But since it's platform dependent, memory consuming and clunky, I couldn't do this to create the full Colemak[eD]. Dead key tables and functions would've been even more byte-gobbling, so no.

However, I have made a `FOURLVLU` user function that lets you define a few keys as four-level giving OS specific Unicode input using the RAlt key as AltGr for these keys only. I used this to get the Norwegian special letters åæø and their shifted counterparts (on the bracket and ISO LSGT keys) as in Colemak[eD], and it works fine for me. I even added the bullet and dagger glyphs (on the ISO \| key) for good measure. You can find various lists of alt codes to use, such as <a href="https://fsymbols.com/keyboard/windows/alt-codes/list/">this one</a>. Remember that you need to use "KC_P#" where # is the digit. For Mac or Unix you need to change the method, see the unimap_dreymar.c file and ask me if you need help.

<br>
<img src="https://dreymar.colemak.org/res/cmk/ergomods/Cmk-ISO-CurlAWide_90d-FShui.png">
<i>Fig.: Colemak-CAW[eD], showing an ISO board with the Curl(DH)Angle and Wide ergonomic mods (see below).</i><br>
<br>


<br><h3>[1.2]    EXTEND LAYERS</h3>

This is <b><a href="https://dreymar.colemak.org/layers-extend.html?platform=tmk">My Favorite Mod</a></b> next to Colemak itself! The ability to navigate and edit from the home position and its immediate surroundings is extremely powerful. It's like having part of the power of advanced editors like Vim ready in all situations. Plus a fully functional multimedia keyboard without sacrificing compactness. And much more.

<br>
<img src="https://dreymar.colemak.org/res/div/Extend/Extend-ISO-NoMod-Win_96d.png">
<i>My Extend Nav/Edit mappings. Green, navigation; blue, mousing; orange, multimedia; gray, system/misc.</i><br>
<br>

<img src="https://dreymar.colemak.org/res/div/Extend/Extend2-ISO-NoMod_96d.png">
<i>My Extend NumPad mappings. Green, navigation; purple, NumPad; sepia, symbols; gray, system/misc.</i><br>
<br>

The USB-2-USB implementation is almost the same as the Linux/XKB and Windows/PKL ones. Some advanced media key codes such as Brightness controls are missing for now (as their key codes aren't in TMK). How some of the advanced keys like MouseWheel Left/Right are interpreted is still up to the OS.

Here's the Extend1 and Extend2 layer charts from my TMK source file:
<pre><code>
   DreymaR's Extend1 layer:
 *  ,----˛    ,-------------------˛ ,-------------------˛ ,-------------------˛
 *  |Caps|    |MPly|MPrv|MNxt|MStp| |Mute|VolD|VolU|MSel| |WHom|WSch|MyCm|Calc|
 *  `----´    `-------------------´ `-------------------´ `-------------------´
 *  ,-------------------------------------------------------------------------˛
 *  | ?? | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|  Pause |
 *  |-------------------------------------------------------------------------|
 *  |      |Esc |Wh_U|WBak|WFwd|Ms_U|PgUp|Home| Up |End |Del |Esc |Ins |  App |
 *  |-------------------------------------------------------------------------|
 *  |*Ext1* |Alt |Wh_D|Shft|Ctrl|Ms_D|PgDn|Left|Down|Rght|BSpc|App |WFav|PScr |
 *  |-------------------------------------------------------------------------|
 *  |     |Wh_L| ^Z | ^X | ^C | ^V |Btn1|Btn2|Btn3|Ms_L|Ms_R|Wh_R|       Ext2 |
 *  |-------------------------------------------------------------------------|
 *  |      |     |     |           Return            |     |     |     | Ext3 |
 *  `-------------------------------------------------------------------------´
</code></pre><br>

<pre><code>
   DreymaR's Extend2 layer:
 *  ,----˛    ,-------------------˛ ,-------------------˛ ,-------------------˛
 *  |    |    |MPau|MRwd|MFFd|Ejct| |WRef|BriD|BriU|Slep| |www |Mail|App3|App4|
 *  `----´    `-------------------´ `-------------------´ `-------------------´
 *  ,-------------------------------------------------------------------------˛
 *  | ?? | !  | @  | #  | $  | %  | ^  | P7 | P8 | P9 | P* | P- | =  |        |
 *  |-------------------------------------------------------------------------|
 *  |      |Home| Up |End |Del |Esc |PgUp| P4 | P5 | P6 | P+ | (  | )  |      |
 *  |-------------------------------------------------------------------------|
 *  |*Ext2* |Left|Down|Rght|BSpc|NLck|PgDn| P1 | P2 | P3 |PEnt| '  | ,  |     |
 *  |-------------------------------------------------------------------------|
 *  |     |    | ^Z | ^X | ^C | ^V |Btn1| :  | P0 | P0 | P. | P/ |       Ext2 |
 *  |-------------------------------------------------------------------------|
 *  |      |     |     |                             |     |     |     | Ext3 |
 *  `-------------------------------------------------------------------------´
</code></pre><br>
<br>

To use the Extend layers, define the `CAPSBEHAVIOR` constant to 1. This'll make CapsLock the Extend modifier. You may change it to another key by editing the active layout or keymap; see the <b>[Keymap Configuration](#keymap-configuration)</b> section below.

There's a couple of `EXT#BIT` constants that determine how Extend2 is selected: If `EXT2BIT` is defined as `MOD_BIT(KC_RSFT)` for instance, holding Right Shift down while pressing the Extend key will activate Extend2. Once selected, holding down Extend alone maintains that layer. The `EXT3BIT` and the combination of the two could select Extend3 and Extend4, but I haven't yet implemented these layers as I haven't yet decided on what to put in them. You could add your own if you want to.

For the NumPad layer, remember that the NumLock state influences what you get. There's a NumLock key easily accessible in the layer.

<b>NOTE: Superstacking Extend modifiers</b> doesn't always work for me. Instead of Ctrl+Shift+Left, pressing Caps+S+T+N gave me ST key strokes. Oddly enough, it works with either Phys-Shift + Extend-Ctrl as well as Phys-RCtrl + Extend-Shift (Shift+Caps+T+N or RCtrl+Caps+S+N work) but not with physical LCtrl. This leads me to believe that the limitation is my keyboards' scan matrix, but it happened on all my boards. Other users with fancier keyboards didn't have this problem.

<br><br>

---

<br><br>

<h2>[2]    <ins>Ergonomic Key Remappings</ins></h2>

<br><h3>[2.1]    THE ANGLE/WIDE ERGONOMIC KEYBOARD MODEL MODS</h3>

These are ergonomic mods, moving some keys around to achieve straight wrists (the Angle mods), as well as better hand separation and right pinky load (the Wide mods). The Angle part is almost a no-brainer to me as it allows the left hand to keep a straight wrist without changing the fingering on ZXCV, and makes B easier to reach. <a href="https://forum.colemak.com/profile.php?id=2">Shai Coleman</a> himself has given his "blessing" to this mod! The Wide mod is more optional, but it does put some load off the right-hand pinky, widen the arm distance (useful for small keyboards in particular, but nice regardless), and provide easier access to AltGr/Enter/Backspace/RShift.

<br>
<img src="https://dreymar.colemak.org/res/cmk/ergomods/Cmk-ISO-AWide-35_60d-FShui.png">
<i>The AngleWide ergo mod for ISO keyboards.</i><br>
<br>

I've implemented the ZXCVB_ "Angle-ISO" shift for ISO keyboards both separately and as part of the AngleWide-ISO mod that I use myself. For ANSI boards I've made an implementation of the "Angle(Z)" shift (moving the Z key to the middle) and a Wide mod as well as <a href="https://dreymar.colemak.org/ergo-mods.html#angle-wide">the AngleWide combination</a> of these. Also the rarely used 'A-Wing' mod to get the Angle and right pinky benefits without messing with the Z position (but at other costs).

<br>
<img src="https://dreymar.colemak.org/res/cmk/ergomods/Cmk-ANSI-AWide-ZQu_60d-FShui.png">
<i>The Angle(Z)Wide ergo mod for US/ANSI keyboards</i><br>
<br>

To use one of these, define the Unimap layout constant in my keymap (.c) file:
<pre><code>
 *  Edit '_########' in the UNIMAPLAYOUT definiton below to choose ergonomic Curl/Angle/Wide keyboard mods:
 *  _NOMODS - Standard Unimap format for all keyboard and converter types (w/o F13-24; this one is without ergo mods)
 *  _ISO_A_ - ISO/Int Angle (the simple lower left half-row shift)
 *  _ISO_AW - ISO/Int Angle-Wide(/)
 *  _ANS_A_ - ANSI/US Angle(Z)
 *  _ANS_AW - ANSI/US Angle(Z)-Wide(')
 *  _AWINGA - ANSI/US A-Wing Angle (rarely used)
 *  
 *  Select an ergo modded keymap, or the plain unmodded Unimap. Note that these maps affect all layouts and layers.
 *  For Curl(DH), you also need to set CURLMOD. For Sym mods, set SYMBOLKEYS according to keymap.
 *  To get, say, the Colemak-CAWS (CurlAngleWideSym) layout on ISO/ANSI, use the _###_AW keymap with
 *      ACTIVELAYOUT 5, CURLMOD 1 and SYMBOLKEYS 2/3 settings below. And CAPSBEHAVIOR 1 for Extend, of course!
</code></pre><br>

The actual keymap types are defined in the header (.h) file as compiler macros. These are harder to edit manually.


<br><h3>[2.2]    COLEMAK-DH ALIAS THE CURL ERGO MOD</h3>

The <b><a href="https://colemakmods.github.io/mod-dh/">Colemak-DH</a></b> ergo mod makes the home "row" curl like a relaxed hand does instead of forcing it to a straight line as was commonly thought best some years ago. This is achieved by moving the common D and H from their debated "middle trench" positions to the more comfortable lower-row V/M positions, while preserving the key-to-finger mappings of vanilla Colemak. Since Oct 2020, standard Colemak-DH is the original DH mod a.k.a. DHm.

<br>
<img src="https://dreymar.colemak.org/res/cmk/ergomods/Cmk-ISO-CurlAWide_90d-FShui.png">
<i>The Colemak Curl(DH)AngleWide, a.k.a. Colemak-CAW, ergo modded layout.</i><br>
<br>

On row-staggered boards, DH should be paired with an Angle (or AngleWide) ergo mod which is easier on an "102/105-key" ISO keyboard but as seen above there are decent options for US/ANSI boards too.

To use Colemak-DH with my TMK files, there's a preprocessor switch named `CURLMOD`:
<pre><code>
 *  The CURLMOD options for Colemak and Tarmak layouts are:
 *  0: No Curl - "vanilla" Colemak/Tarmak
 *  1: SteveP99's original Curl(DHm) ergo mod, bringing D/H down but M to the home row. DH standard since Oct 2020.
 * 
 *  N/A: The 2017 Curl(DHk) ergo mod, bringing the D and H keys down to comfortable bottom-row positions (QWERTY C/M)
 *      (Some row-staggered board users may like the DHk variant, but the DHm standard is good for all board types.)
 *  N/A: DreymaR's old Curl(DvH) mod, bringing DH center-down to the QWERTY V/N keys.
 *      (If you somehow wish to keep ZXCV together as in my old Curl(DvH) mod, edit the maps manually.)
 * 
 *  NOTE: On the first Tarmak step, the CURLMOD setting doesn't matter. If you want to swap H and M early, edit it in.
 *        For the other steps, CURLMOD still doesn't move H-M so Curl(DH) users by default will do H-M in the last step.
 *        An extra baby step after Tarmak1 could be transitioning to an Angle(Wide) keymap/model before Tarmak2.

# define CURLMOD        1   /* CURL_DH          */
</code></pre><br>

This switch only affects Colemak layouts, including the four Tarmak layouts and Mirrored Colemak. As mentioned, use an 'A' keymap with it (optional for Tarmak1).


<br><h3>[2.3]    PLAYING WITH THE SYMS</h3>

The Symbol key mods are selected with the `SYMBOLKEYS` setting. The Sym mod depends on your keymap, so select the right one depending on your Wide mod and board type.
<pre><code>
 *  The SYMBOLKEYS options for layouts are:
 *  0: No Symbol key changes - "vanilla" Colemak or whatever
 *  1: Sym mod for non-Wide ergo mods
 *  2: Sym mod for Wide mod combos on ISO keyboards
 *  3: Sym mod for Wide mod combos on ANSI keyboards
 *  
 *  Adaptations for ANSI-ISO and locale key differences (more info below):
 *  4  : Some keys are made four-level: AltGr+<key> sends Unicode glyphs (by OS specific input method)
 *  5  : DreymaR's ISO-Nor hack, moving some keys to make the Norwegian layout more like ANSI/US

# define SYMBOLKEYS     0   /* SYM_NONE         */
</code></pre><br>

Note that `SYMBOLKEYS` affects Extend layers and other layouts too!

<pre><code>
  \   7   8   9   0   =
[   j   l   u   y   '   -
 ]   m   n   e   i   o   ;
   /   k   h   ,   .   _____
</code></pre>
<i>The "Sym" symbol rotation mod together with the Curl-DH and AngleWide(ISO) mods is <b>Colemak-CAWS</b>.</i><br>
<br>


<br><h3>[2.4]    MODIFIER MODNESS</h3>

I've implemented Sticky Shift but not much else for TMK. Moving modifiers around manually shouldn't be hard to do if you're interested.
<pre><code>
 *  The STICKYMODS constant chooses LShift, RShift and RCtrl key behavior (I chose to leave LCtrl alone):
 *  0: Normal Shift/Ctrl (default)
 *  1: Sticky Shift only
 *  2: Sticky Ctrl only
 *  3: Sticky Shift & Ctrl
 *  NOTE: In the unimap_dreymar.h file, some relevant constants normally set in config.h are (re)set:
 *      - TAPPING_TERM is the max time a key may be held down for it to register as tapped
 *      - ONESHOT_TIMEOUT is the max delay before a oneshot modifier is ignored

#define STICKYMODS      1   /* STICKY_SHFT      */
</code></pre><br>

Note that I've given most symbol keys special 'F' names (like `FLSh` for `LSFT`) in the layout maps. These are defined by `ACTION_` definitions.
<br><br>

---

<br><br>

<h2>[3]    <ins>Layout Variants</ins></h2>

<br><h3>[3.1]    THE TARMAK TRANSITIONAL COLEMAK LAYOUTS</h3>

There's <a href="https://dreymar.colemak.org/tarmak-intro.html?platform=tmk">a Tarmak BigBag page</a> that you may want to read. Basically, I've added four Tarmak layouts that provide stepping stones from the standard (US) English QWERTY layout to the Colemak[eD] layout by moving only 3-4 keys per step. Each step brings at least one important key to the home row (notably, E-T-R-O-I) and only the uncommon J is misplaced in the process.

<br>
<img src="https://dreymar.colemak.org/res/cmk/tarmak/Tarmak-ETROI_Spectral_ANSI.png">
<i>The 5-step Tarmak(ETROI) transitional Colemak layouts, spectrally color-coded from red (Tarmak1) to violet (Colemak).</i><br>
<br>

The Tarmak progressions work modularly with the AngleWide ergo mods.

If you want to learn the brilliant Colemak-DH variant using a Tarmak progression, that's possible too! You just have to learn a CurlAngle mod before or with the 2nd Tarmak step which also gets tweaked a little so it moves B instead of G. The right-hand swaps (Hmk) should ideally be learnt in conjunction with Tarmak1-Curl because that moves K, but for SteveP's old variant I've deferred the HM swap to the last step. It could go wherever you like as it's separate, so feel free to edit the layout file if you desire.

<pre><code>
 *  Tarmak2 - Transitional Colemak (ET)
 *  ,-----------------------------------------------------------˛
 *  |     |  q|  w|  F|  r|  G|  y|  u|  i|  o|  p|   |   |     |
 *  |-----------------------------------------------------------|
 *  |      |  a|  s|  d|  T| *J|  h|  N|  E|  l|  ;|   |        |
 *  |-----------------------------------------------------------|
 *  |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
 *  `-----------------------------------------------------------´

 *  Tarmak2-Curl(DH) - Transitional Colemak-Curl-DH (ET)
 *  ,-----------------------------------------------------------˛
 *  |     |  q|  w|  F|  r|  B|  y|  u|  i|  o|  p|   |   |     |
 *  |-----------------------------------------------------------|
 *  |      |  a|  s|  d|  T|  g|  h|  N|  E|  l|  ;|   |        |
 *  |-----------------------------------------------------------|
 *  |    |  z|  x|  c| *J|  v|  _|  K|  m|   |   |   |          |
 *  `-----------------------------------------------------------´
</code></pre><br>


<br><h3>[3.2]    LOCALE AND PHONETIC VARIANTS</h3>

The QUICKIE device only partially supports locales <i>per se</i>, as it only sends key strokes that are then re-coded by your computer's layout settings. My four-level Unicode function remedies this somewhat by allowing some keys to have their AltGr/RAlt states remapped to an OS dependent Unicode input method. So I can set a standard US QWERTY layout on my computer and still have, e.g., the locale ÆæØøÅå letters where I'm used to.

Before I made that function however, I used the locale layout installed on Windows. But I found that the default symbol key mappings are non-intuitive since they are quite different from the US ones which I'm used to now. So I've made an `ISOHACK` layout specifically for the Nor locale that moves several symbol keys to where I feel they are better placed for me. If you want something like that, you'll probably have to determine your own remaps based on your locale.

For instance, instead of a [=+] key as on US keyboards, the Norwegian locale has [+?], [0=] etc. I can't sort that out to get the symbol placements I'm used to as a Colemak[eD] typist unless I choose a US locale layout on the computer I'm on – but I still need the Norwegian ÆØÅ letters so that won't work! I had to settle for, e.g., moving the +? key to the US /? key position so at least the question mark is in the right place. Not perfect, but the best I could do.

Phonetic layouts for non-latin scripts require a layout with that script installed on the computer or whatever you're typing to. If you select a QWERTY phonetic layout for a script and have a USB-2-USB Colemak keymap active, your resulting layout will be Colemak phonetic. If, however, you want to swap some key positions (for Rulemak/Bulmak for instance), a suitable new keymap must be made and compiled.


<br><h3>[3.3]    MIRRORED COLEMAK</h3>

Advanced typing with only one hand is possible given a modicum of familiarity with the mirroring method. In fact, this paragraph was written entirely using the left hand with the exception of the mirroring key itself, with hardly any training! The brain is inherently good at mirroring things.

Mirrored layouts are easily implementable for the USB-2-USB device. I've provided a mirrored Colemak that obeys the Curl mod setting. This will usually be your second layout (layer 1) on top of Colemak, so in my map file it's set by using `ACTIVELAYOUT 5` (Colemak) and `SECONDLAYOUT 6` (mirrored Colemak).

If you want a non-Colemak mirrored layout, you're on your own writing one. If you do, please share it so others can benefit!

<pre><code>
 *  Mirrored Colemak (used as switch layout for one-handed typing)
 *  ,---˛   ,---------------˛ ,---------------˛ ,---------------˛
 *  |  \|   |F12|F11|F10|F9 | |F8 |F7 |F6 |F5 | |F4 |F3 |F2 |F1 |
 *  `---´   `---------------´ `---------------´ `---------------´
 *  ,-----------------------------------------------------------˛
 *  |BSp|  -|  0|  9|  8|  7|  6|  5|  4|  3|  2|  1|  =|     ` |
 *  |-----------------------------------------------------------|
 *  | Ent |  ;|  Y|  U|  L|  J|  G|  P|  F|  W|  Q|Esc|Cps|   \ |
 *  |-----------------------------------------------------------|
 *  |    ' |  O|  I|  E|  N|  H|  D|  T|  S|  R|  A|  '|  Enter |
 *  |-----------------------------------------------------------|
 *  | Shift  |  /|  .|  ,|  M|  K|  B|  V|  C|  X|  Z|    Shift |
 *  `-----------------------------------------------------------´

 *  NOTE: Set an accessible key in your active layout (e.g., LALT or RGUI) as a layer1 switch (see SLCKBEHAVIOR).
</code></pre><br>

You'll want an easily accessible key (such as a thumb key) to switch between normal and mirrored typing. One suggestion is using LAlt for left-handed typing, and RAlt or RWin for right-handed typing. But you may instead use a foot switch set to any other key, or a "ghetto foot switch" made by stripping most keys off a keyboard and placing it on the floor, for instance. A more fancy but still cheap foot switch could be made by soldering the wires from a foot pedal switch (if you have something useable) to the contacts of a key on a cheap keyboard. By default, the layer switch key in my files is Pause/Break which could be cannibalized this way.

Then, you may choose whether the switch key should be a normal Shift-type (switch) or a Caps-type (toggle) modifier. See how I've defined the "FSLk" Fn key in my file; it's used as my definition for the ScrollLock key but you can copy that to any other key as well. The normal way would be to set it to a Shift/switch-type with `ACTION_LAYER_MOMENTARY(1)` (`SLCKBEHAVIOR 2`), and then replace the desired key in your active (layer0) layout with `FSLk` if you wish to move it. If you go with a toggle modifier, you need to make that key transparent (TRNS) on the mirrored layout, or provide a similar toggle somewhere else or you won't be able to get back!

Tip: Sticky Shift and Ctrl could be useful for one-handed typing! See the `STICKYMODS` setting.

<br><br>

---

<br><br>

<h2>[4]    <ins>Download and Setup</ins></h2>

<b>[4.1]</b> The <b>[Download and Install](#download-and-install)</b> section shows how to get and install my files, and also how to prepare the device in bootloader mode.<br>
<b>[4.2]</b> The <b>[Keymap Configuration](#keymap-configuration)</a></b> section shows how to get or tweak/make a HEX file that suits your layout needs.<br>
<b>[4.3]</b> The <b>[Device Flashing](#device-flashing)</b> section shows how to load a HEX file into your USB-2-USB device and get it ready for typing.<br>
<b>[4.4]</b> The <b>[Hardware Implementations](#hardware-implementations)</b> section shows some of the devices you can use my code on.<br>

<br><br>

---

<br><br>

<a name="download-and-install"></a><h3>[4.1]    DOWNLOAD AND INSTALL</h3>

<b>First off: <a href="https://github.com/DreymaR/BigBagKbdTrix_TMK">These are my TMK-based files</a></b> on GitHub! There's:

* A <b>BigBagKbdTrix_TMK</b> dir with my files; it can go into or beside the tmk_keyboard/ dir of <a href="https://github.com/tmk/tmk_keyboard/">Hasu's TMK repo</a>
* A <b>MakeFlash shell script</b> (see below) that'll install and run TMK with my files under Linux
* A <b>_myhexfiles</b> dir with some ready-made HEX files that you can flash directly onto a Hasu device (or any other ATmega32U4 chip)

In addition to providing my additional files for use with <a href="https://github.com/tmk/tmk_keyboard/tree/master/converter/usb_usb/">Hasu's TMK code for his USB to USB converter</a>, this section shows how to prepare your device and get ready to make and flash (install) a HEX file to it. If you have another device or just wish to learn more, I recommend looking at the <a href="https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/build.md">TMK help files</a> and <a href="https://github.com/njbair/keyboard_firmware#building--flashing-the-firmware">NJBair's instructive firmware building/flashing guide</a>.

The <b>[Keymap Configuration](#keymap-configuration)</b> section will show you how to get or generate a keymap/layout that suits you, and the <b>[Device Flashing](#device-flashing)</b> section shows how to program a USB2USB or other TMK device with that file.


<h4>Device preparation:</h4>

<b>1.</b> <b>For flashing on Windows: <a href="http://www.atmel.com/tools/FLIP.aspx">Install Atmel's FLIP application</a></b> for device drivers ++

* Note that it says 'Buy now' on a button but the links below don't cost anything!
* I've had trouble with FLIP not finding a Java Virtual Machine after a Java update; you may have to <b><a href="https://www.java.com/en/download/manual.jsp">reinstall your Java Runtime Environment</a></b>.

<b>2.</b> <b>Insert the device and press its Bootloader mode button (fig. 1–4)</b>.

* You don't need a keyboard plugged into the device yet. In fact, to be on the safe side, I recommend not plugging in a keyboard yet!
* When in Application/Keyboard mode, the yellow App LED should be lit; when in Bootloader/Flash mode it goes out.

<br>
<img src="img/USB2USB_Hasu-physical.png">
<i>Fig. 1: Hasu's USB-2-USB device. 1) USB host – plug keyboard here; 2) USB client – plug into computer or whatever; 3) App LED; 4) Bootloader button</i><br>
<br>

<b>3.</b> <b>For flashing on Windows: Install/update the device drivers for your ATmega32U4 (or other) chip</b>.

* The Windows Device Manager shows your device first as a HID keyboard and then, in Bootloader mode, as an Atmel or ATMega USB device
* Point the driver update to the <b>C:\Program Files (x86)\Atmel\Flip 3.4.7\usb</b> or similar directory if necessary
* Now, using the Windows Device Manager you can check that the device is mounted:

<br>
<img src="img/USB2USB_WinDevMgr_Hasu-ApplicationVsBootloaderMode.png">
<i>Fig. 2: Windows Device Manager showing the Hasu USB-2-USB device in Application/Keyboard (left) and Bootloader (right) mode.</i><br>
<br>

<b>4.</b> <b>For flashing on Linux: Ensure that your device is seen by the OS, in DFU (bootloader) mode</b>.

* The <b>lsusb</b> command lists attached USB devices; hopefully there's an entry with Atmel and "AVR DFU Bootloader" in it.
* If you're using a Linux virtual machine, make sure the device is <b>captured</b> in Bootloader mode, using your VM app's device listings.
* Every time you enter or leave bootloader mode, you may have to recapture the device for your VM.
* It should be ticked off in the Devices>USB menu on VirtualBox for instance; similarly for VMWare and others:

<br>
<img src="img/USB2USB_VBox-DevicesMenu_Hasu-BootloaderMode.png">
<i>Fig. 4: The Devices (pop-up) menu of VirtualBox, showing a properly captured Atmel USB device.</i><br>
<br>

<h4>Getting and installing my TMK files, TMK itself and AVR tools for Linux:</h4>

My files are extensions of Hasu's TMK code. You'll need to compile them within a copy of his repo, and I'll describe how to do this on a Linux machine. You can use a real or virtual Linux machine; I've used an Ubuntu VM. If you have an updated 64-bit Windows 10, you can even use the Linux Subsystem BASH command line to do it without leaving Windows – see below! I guess you could also use for instance <a href="https://www.cygwin.com/">CygWin</a> or <a href="http://www.mingw.org/">MinGW</a>, but I haven't tried those possibilities.

Included in my files is the shell script <b><i>[makeflash_dreymar_tmk.sh](../makeflash_dreymar_tmk.sh)</i></b> that does several things on a Linux machine. Run it with the -h option for more help:

<br>
<img src="img/USB2USB_Linux-MakeFlash-help.png">
<i>Fig. 3: The help text for my MakeFlash script, showing options and default values. This image may be outdated; run the script yourself.</i><br>
<br>

<h4>Step-by-step instructions for installing on Linux:</h4>

Here's a set of <b>step-by-step download/install instructions</b>:
1) <b><a href="https://github.com/DreymaR/BigBagKbdTrix_TMK">Download or clone my repo</a></b> and...
    * if installing TMK, put its directory with at least the <b>MakeFlash</b> script in the dir in which you want TMK.
    * My files/dirs can actually go either a) in a dir beside TMK's <b>tmk_keyboard</b>, b) directly inside it, or c) in a dir inside it
    * (On my virtual machine, I use a shared folder so both Linux and Windows can see the HEX files I've built directly.)
2) <b>Install the AVR Tools</b> needed for compiling for and flashing to the chip with <b><i>bash makeflash_tmk_dreymar.sh -a</i></b>
3) <b>Install Git & Hasu's GitHub TMK repository</b> with <b><i>bash makeflash_dreymar_tmk.sh -g</i></b> (if you have Git/TMK already, it'll update them)
4) Make sure my repo is in place relative to the TMK one as described above, and open a terminal there
5) Now you're ready to <b>Build and flash HEX files</b> from TMK code. To simply build the default keymap as set in keymap_dreymar.c, use:
<pre><code>
$> ./makeflash_dreymar_tmk.sh
</code></pre><br>

See the <b>[Keymap Configuration](#keymap-configuration)</b> section below for more info on getting a HEX file that suits you, and the <b>[Device Flashing](#device-flashing)</b> section for how to program your device with the HEX file.


<h4>Addendum: Using BASH on Windows through the Linux Subsystem</h4>

The Windows 10 Anniversary Edition (64-bit) has an exciting addition that's nominally still in beta but already quite operational (command-line only): A <a href="http://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/">Ubuntu GNU/Linux "Subsystem" running a BASH command line terminal</a>! This is capable of compiling the TMK code just like a Linux machine. I've heard you cannot flash to a device with it, as dfu-programmer isn't working (yet) – but that's no biggie as you can just use Windows-based flashing tools. Anyway, just try and see if it works now; let me know if it does!

Hasu has <a href="https://github.com/tmk/tmk_keyboard/wiki/Bash-On-Ubuntu-On-Windows10">instructions on how to use BASH on Windows 10 for TMK compiling</a>, but here's a little run-through:

* Make sure you have the <b>Windows 10(64bit) Anniversary Update</b> or newer; if you don't then <a href="https://support.microsoft.com/en-us/help/12387/windows-10-update-history">get it from Microsoft's pages</a>.
    - <b><i>Settings → System → About</i></b>; your WIndows version should be >1607.
* Activate <b>Developer Mode</b>
    - <b><i>Settings → Update & Security → For developers → Developer mode</i></b>
* Activate <b>Windows Subsystem for Linux</b>
    - <b><i>Control Panel → Programs → Turn Windows features on or off → Windows Subsystem for Linux (beta)</i></b> (requires a restart)
* Start the <b>BASH terminal</b>
    - <b><i>Start Menu → Bash on Ubuntu on Windows</i></b>; you'll have to finish the Ubuntu install and choose a username/pwd the first time.
* Navigate to a suitable folder and follow the step-by-step procedure above to install AVR tools, make, git and TMK and get going!
    - At <b><i>/mnt/c/</i></b> you'll find the C:\ drive; you have access to the same file system as Windows does.
* If you have my files in a different location from the main tmk ones, you can use a symbolic link to make my script see the tmk dir.


<h4>Addendum: Using other keyboard converters/controllers</h4>

The above should work directly for any ATmega32U4-based controllers. TMK works for several types of keyboard controllers and converters; look inside the TMK dirs for more info. The map files I use now are in the Unimap format, which should work with all TMK compatible controllers.

I've tested Hasu's PS/2-USB converter. For that device, be aware of the following:
* This converter uses the ATmega32U2 chip (for now). If flashing with FLIP, set its device selection accordingly.
* To compile for the PS/2-USB converter with my script, use the following switches:
<pre><code>
$> ./makeflash_dreymar_tmk.sh -d converter/ps2_usb/ -m Makefile.unimap.rev2
</code></pre><br>

<br><br>

---

<br><br>

<a name="keymap-configuration"></a><h3>[4.2]    KEYMAP CONFIGURATION</h3>

This section shows how to get the keymap HEX file you want. How to compile TMK or other code is described here.

If you wish to delve deeply into keymap editing, make sure you've read at least Hasu's <b><a href="https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md">Keymap and Layers</a></b> ReadMe. It and other docs are found in the <b><a href="https://github.com/tmk/tmk_keyboard/tree/master/tmk_core/doc">tmk_keyboard/tmk_core/doc</a></b> dir of his GitHub repo.


<h4>Using a precompiled HEX file:</h4>

I've provided some .hex files with my download, but I can't make every combination of options as that'd take a lot of my time. If you're lucky, you'll find what you need and then you don't have to build your own HEX file. There may be other such files available from other sources, too.

My provided pre-compiled HEX files are:
* <b>QWE-Tarmak-Cmk_All_Extend:</b> A full progression from QWERTY via Tarmak 1–4 to Colemak, with Extend, without any ergonomic mods ("vanilla").
* <b>QWE-Tarmak-Cmk_CurlAWideISO_Extend:</b> A full Tarmak progression as above, with Extend and the Curl(DH)AngleWide-ISO ergo mods.

So you could use these files to:
* Learn Colemak or Colemak-CAW with as many Tarmak steps as you like (0–4),
* Type Tarmak#, Colemak or Colemak-CAW with Extend, or just
* Type QWERTY with Extend and optionally the AngleWide-ISO ergo mod (the Curl mod does not apply to QWERTY)

If you find a ready-made HEX file, make sure it's built for the right chip. The Hasu USB-2-USB device currently uses <b>Atmel ATmega32U4</b>.


<h4>Using Hasu's online editor to generate a HEX file:</h4>

<b><a href="http://www.tmk-kbd.com/tmk_keyboard/editor/unimap/?usb_usb">Hasu's Online TMK Keymap Editor for the USB to USB converter</a></b> will let you make .hex files you can save and use for flashing your ATmega32U4 device. If you need a simple keymap that I haven't made already, this may be the easiest way of getting it.

<br>
<img src="img/USB2USB_Hasu-TMK-WebEditor_L0-L1_70pc.png">
<i>Fig.: Hasu's Online keymap editor, showing two different layers and key panels.</i><br>
<br>

You can make up to 7 layers with this, only by clicking the keys you want into place. The NO code deactivates a key, and the TRNS code lets whatever is in active lower layers "shine through". There's a tab of layer switching functions too. Just mess around with it, it's fun.

To make modified key strokes and other fancy stuff, there's a Code Edit tab. To understand it, read <a href="https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md">Hasu's TMK Keymap guide</a>.

You can also output C/JSON/etc code that you may compile manually for other devices, but you can't easily use that code for tweaking layouts, since it'll only give you hex codes for all the keys so unless you happen to know the right numbers you'll get a big headache trying to figure that out.

Here's an online editor example if you want a quick Big Bag starting point: <a href="https://goo.gl/GNfui5">My Colemak-CAW layout with two Extend layers</a>. You can also import one of the precompiled HEX files into it if you want.

<s>Note: There's also an <a href="http://www.tmk-kbd.com/tmk_keyboard/editor/usb_usb/index.html">older version of the online editor</a>, but that didn't support modified keys.</s>


<h4>Building a HEX file from TMK files on Linux:</h4>

If you've followed the <b>[Download and Install](#download-and-install)</b> section above, by now you should have a copy of Hasu's TMK repo with my usb_usb files inside its converter/usb_usb directory and a terminal open to that directory.

In addition to installing, my shell script <b><i>makeflash_dreymar_tmk.sh</i></b> run in Linux can:

* <b>Build a HEX file</b> (default name is <b><i>usb_usb_unimap.hex</i></b>) for flashing to your device, using Hasu's Makefile
* <b>Flash a HEX file to a device in Bootloader mode</b> (or you may take the file to Windows and do it with Atmel FLIP instead)
* <b>Clean up</b> all the files from a build/compilation; note that this also removes the .hex file unless you've renamed or moved it

Run it with a keymap file's name (unimap_<name>.c) to optionally choose a non-default keymap file (the default is 'dreymar'):
<pre><code>
$> bash makeflash_dreymar_tmk.sh [<name>]
</code></pre><br>

If you run the script with <b>-h</b>, you'll see the default values for which directory to use and what the file will be called etc. For an example, see the Install section above.


<h4>Editing my (or other) TMK keymap files:</h4>

I've provided a <b><i>unimap_dreymar.c</i></b> file with several keymaps/layouts in, and a <b><i>unimap_dreymar.h</i></b> file that mostly holds keymap types for the Angle/Wide ergo mods. For normal purposes, the <b>unimap_dreymar.c</b> file will be the one you want to edit to get the layout(s) you want. Use any editor (as long as it preserves character encoding) to edit the file in your local <b><a href="https://github.com/tmk/tmk_keyboard/tree/master/converter/usb_usb">tmk_keyboard/converter/usb_usb</a></b> directory before building the HEX file as described above.

The default layer is layer0; this will always be active when the device is activated. I've used layer1 for a second layout and added a layer-toggle key (ScrollLock by default) to go back and forth between two layouts. Layer2+ are intended for Extend layers but only layers 2–3 are in use for now.

The layout options are chosen with preprocessor directives; you can edit the values of the #define <OPTION> <value> lines before compiling to produce different .hex files as you like.

<h4>"Physical" keymap type settings (Angle/Wide ergo mods) in unimap_dreymar.c; see below if you want to edit these in unimap_dreymar.h:</h4>
<pre><code>
/*  Edit '_########' in the UNIMAPLAYOUT definiton below to choose ergonomic Curl/Angle/Wide keyboard mods:
 *  _NOMODS - Standard Unimap format for all keyboard and converter types (w/o F13-24; this one is without ergo mods)
 *  _ISO_A_ - ISO/Int Angle (the simple lower left half-row shift)
 *  _ISO_AW - ISO/Int Angle-Wide(/)
 *  _ANS_A_ - ANSI/US Angle(Z)
 *  _ANS_AW - ANSI/US Angle(Z)-Wide(')
 *  _AWINGA - ANSI/US A-Wing Angle (rarely used)
 *  
 *  Select an ergo modded keymap, or the plain unmodded Unimap. Note that these maps affect all layouts and layers.
 *  For Curl(DH), you also need to set CURLMOD. For Sym mods, set SYMBOLKEYS according to keymap.
 *  To get, say, the Colemak-CAWS (CurlAngleWideSym) layout on ISO/ANSI, use the _###_AW keymap with
 *      ACTIVELAYOUT 5, CURLMOD 1 and SYMBOLKEYS 2/3 settings below. And CAPSBEHAVIOR 1 for Extend, of course!
 */
#define UNIMAPLAYOUT(...)   UNIMAP_ANS_AW( __VA_ARGS__ )    /* AngleWide-ANSI keymap */
</code></pre><br>

For layouts and layout options, the directives will select which pieces of code below to actually compile so you get what you want.
<br>

<h4>Active/default layout settings:</h4>
<pre><code>
/*  Define the ACTIVELAYOUT (and CURLMOD) constant(s) to choose the layer0 layout:
 *  0  : QWERTY
 *  1-#: Tarmak1 - transitional Colemak (supports CURLMOD; see below)
 *  2-#: Tarmak2 - transitional Colemak (--"--)
 *  3-#: Tarmak3 - transitional Colemak (--"--)
 *  4-#: Tarmak4 - transitional Colemak (--"--)
 *  5-0: Colemak
 *  5-1: Colemak Curl-DH (requires a CurlAngle keymap; see above)
 *  6-#: Mirrored Colemak (normally used as second layout with a layer switch)
 *  7  : Dvorak (only recommended if you already use it)
 *  8  : Canary (Colemak-like layout; changes more keys, less implemented)
 */
#define ACTIVELAYOUT    5                       /* LAY_COLEMAK      */
</code></pre><br>

<h4>Second/switch layout settings:</h4>
<pre><code>
/*  Define the SECONDLAYOUT (and CURLMOD) constant(s) to choose the layer1 switch layout:
 *  0  : Unmodded QWERTY is the default; otherwise:
 *  1  : QWERTY with any active ergo mods (AngleWide etc)
 *  2-#: Colemak (if you want something else, replace it in the code between the 'REPLACE THE SECOND LAYOUT...' lines)
 *  3-#: Colemak Mirrored as second layout for one-handed typing (needs an accessible switch key!)
 *      NOTE: The "FSLk" key is a layer1 toggle or switch (select which below), normally used on the ScrollLock key.
 *            You may swap, e.g., LALT, RGUI or another key with FSLk in your active layout to use that key instead.
 */
#define SECONDLAYOUT    0                       /* SEC_VANQWERTY    */
</code></pre><br>

<h4>Curl(DH)-mod settings:</h4>
<pre><code>
/*  The CURLMOD options for Colemak and Tarmak layouts are:
 *  0: No Curl - "vanilla" Colemak/Tarmak
 *  1: SteveP99's original Curl(DHm) ergo mod, bringing D/H down but M to the home row. DH standard since Oct 2020.
 * 
 *  N/A: The 2017 Curl(DHk) ergo mod, bringing the D and H keys down to comfortable bottom-row positions (QWERTY C/M)
 *      (Some row-staggered board users may like the DHk variant, but the DHm standard is good for all board types.)
 *  N/A: DreymaR's old Curl(DvH) mod, bringing DH center-down to the QWERTY V/N keys.
 *      (If you somehow wish to keep ZXCV together as in my old Curl(DvH) mod, edit the maps manually.)
 * 
 *  NOTE: On the first Tarmak step, the CURLMOD setting doesn't matter. If you want to swap H and M early, edit it in.
 *        For the other steps, CURLMOD still doesn't move H-M so Curl(DH) users by default will do H-M in the last step.
 *        An extra baby step after Tarmak1 could be transitioning to an Angle(Wide) keymap/model before Tarmak2.
 */
#define CURLMOD         1                       /* CURL_DH          */
</code></pre><br>

<h4>Symbol key behavior settings:</h4>
<pre><code>
/*  The SYMBOLKEYS options for layouts are:
 *  0: No Symbol key changes - "vanilla" Colemak or whatever
 *  1: Sym mod for non-Wide ergo mods
 *  2: Sym mod for Wide mod combos on ISO keyboards
 *  3: Sym mod for Wide mod combos on ANSI keyboards
 *  
 *  Adaptations for ANSI-ISO and locale key differences (more info below):
 *  4  : Some keys are made four-level: AltGr+<key> sends Unicode glyphs (by OS specific input method)
 *  5  : DreymaR's ISO-Nor hack, moving some keys to make the Norwegian layout more like ANSI/US
 */
#define SYMBOLKEYS      0                       /* SYM_NONE         */
</code></pre><br>

<h4>CapsLock behavior settings, including Extend mode:</h4>
<pre><code>
/*  The CAPSBEHAVIOR constant chooses Caps key action, including the powerful Extend layer switch:
 *  0: CapsLock (unchanged)
 *  1: Extend modifier (uses a little more layout memory, but it's by far the most powerful option IMNSHO!)
 *  2: BackSpace (for vanilla Colemak or otherwise; a decent choice but Extend is better!)
 *  3: LCtrl
 *  4: Esc
 *  NOTE: To move modifiers, edit the layouts or the appropriate UNIMAP_### in my .h file (e.g., swapping CAPS and #ALT).
 *  NOTE: Depending on your keyboard's scan matrix(?), chorded Extend modifiers such as Ext1+S+T+N for Shift+Ctrl+Left
 *        may not work. With Caps=Ext1, I've had trouble with Ext1+S+T+N; with LAlt=Ext1 even Ext1+S+N didn't work!
 */
#define CAPSBEHAVIOR    1                       /* CAPS_EXTEND      */
/*  The CAPSBEHAVIOR constant chooses Caps key action, including the powerful Extend layer switch:
 *  0: CapsLock (unchanged)
 *  1: Extend modifier (uses a little more layout memory, but it's by far the most powerful option IMNSHO!)
 *  2: BackSpace (for vanilla Colemak or otherwise; a decent choice but Extend is better!)
 *  3: LCtrl
 *  4: Esc
 *  NOTE: To move modifiers, edit the layouts or the appropriate UNIMAP_### in my .h file (e.g., swapping CAPS and #ALT).
 *  NOTE: Depending on your keyboard's scan matrix(?), chorded Extend modifiers such as Ext1+S+T+N for Shift+Ctrl+Left
 *        may not work. With Caps=Ext1, I've had trouble with Ext1+S+T+N; with LAlt=Ext1 even Ext1+S+N didn't work!
 */
#define CAPSBEHAVIOR    1                       /* CAPS_EXTEND      */

/*  The EXT#BIT constants with the main Extend key (Caps by default) select Extend# layers in the EXTENDER user function:
 *  Ext1 on Caps alone       : Navigation/editing/multimedia
 *  Ext2 on Ext2+Caps        : NumPad/Navigation
 *  Ext3 on Ext3+Caps        : TODO
 *  Ext4 on Ext2+Ext3+Caps   : TODO
 *  NOTE: Alt keys as Extend# selectors failed, as AltUp activates Win menus even when the mod is turned off?!
 *      - It should be possible to write an Alt user function that doesn't release Alt when Ext has been pressed.
 */
#define EXT2BIT MOD_BIT(KC_RSFT)                /*  Ext2+Ext selects Extend2    */
#define EXT3BIT MOD_BIT(KC_RCTL)                /*  Ext3+Ext selects Extend3    */
</code></pre><br>

<h4>Sticky mods (Shift and/or Ctrl) settings:</h4>
<pre><code>
/*  The STICKYMODS constant chooses LShift, RShift and RCtrl key behavior (I chose to leave LCtrl alone):
 *  0: Normal Shift/Ctrl (default)
 *  1: Sticky Shift only
 *  2: Sticky Ctrl only
 *  3: Sticky Shift & Ctrl
 *  NOTE: In the unimap_dreymar.h file, some relevant constants normally set in config.h are (re)set:
 *      - ONESHOT_TIMEOUT   max delay (in ms) before a oneshot/sticky modifier is ignored
 *      - TAPPING_TERM      max time a key may be held down for it to register as tapped, not held
 */
#define STICKYMODS      1                       /* STICKY_SHFT      */
</code></pre><br>

<h4>ScrollLock and Pause/Break behavior settings:</h4>
<pre><code>
/*  The SLCKBEHAVIOR constant chooses ScrollLock key action:
 *  0: Normal ScrollLock (default)
 *  1: Layer 1 toggle key (toggles the second layout)
 *  2: Layer 1 switch key (layer shift; e.g., for mirrored typing if you can use it as "ghetto" foot switch)
 */
#define SLCKBEHAVIOR    1                       /* SLCK_L1TOGGLE    */

/*  The PAUSBEHAVIOR constant chooses Pause/Break key action:
 *  0: Normal Pause/Break (default)
 *  1: Win/GUI key (useful for 101/104-key boards that have no GUI key)
 */
#define PAUSBEHAVIOR    0                       /* PAUS_PAUS        */
</code></pre><br>


<h4>Editing maps and headers manually:</h4>
It is of course entirely possible to edit the layouts themselves directly. It should be fairly intuitive how to do that. See the <a href="https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keycode.txt">TMK keycode.txt</a> file for a list of all key codes (layouts use the 3–4 letter versions).

CapsLock, LAlt, RAlt and some other keys are defined as Fn## keys in the layouts. At the start of the file there's a bunch of action definitions for these.

Below are some examples from an unimap file:
<pre><code>
#  define AC_FTab ACTION_LAYER_TAP_KEY(2, KC_TAB)    // FTab (Tab key)  as Ext2 – tap for Tab (for now)
#  define AC_FnLA ACTION_KEY(KC_LALT)                // FnLA (LAlt key) as usual (for now)
#  define AC_FnRA ACTION_KEY(KC_RALT)                // FnRA (RAlt key) as usual (for now)
//#  define AC_FnU1 ACTION_MODS_KEY(MOD_LGUI, KC_T)    // FnU1 (`) as Win+T
#  define AC_FnU1 ACTION_MACRO(TYPESTR1)             // FnU1 as user macro: Type a string
</code></pre><br>

In the above:

* FTab, mapped to the Tab key (TAB) in my layouts, activates layer 2 (Ext2) while held down, and sends the TAB key code if tapped.
    – The Tab key is quite handy as a dual-role modifier, but unfortunately it loses its repeat functionality this way.
    – ISO keyboard users might want to use the <LSGT> key instead; its code is NUBS ("Non-US Backslash").
* FnLA and FnRA, similarly, are my versions of the LAlt and RAlt keys. But for now, their defined actions are mostly to be their normal selves!
* AC_FnU1 is a user macro key that I put on Extend+Tilde/Grave. It's macro is defined at the end of the file; in this case it types out a boilerplate text (my email footer).
* Commented out above, is an alternative definition for FnU1: Sending a LWin+T keystroke instead (in Windows, this brings you to the menu line).

Here's an ergo remapping from the <b>unimap_dreymar.h</b> file; this one's (the lower part of) the `UNIMAP_ISO_A` Angle-ISO mod. Note how ZXCVB have moved:
<pre><code>
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L1_Z,L2_X,L3_C,L4_V,L5_B,L0LG,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
</code></pre><br>

<br><br>

---

<br><br>

<a name="device-flashing"></a><h3>[4.3]    DEVICE FLASHING</h3>

This section shows how to flash your HEX file to a USB-2-USB device and get it ready for typing. See the above sections for how to <b>[prepare the device](#download-and-install)"</b> and <b>[get the HEX file you want](#keymap-configuration)</b>.

<b>NOTE:</b> Flashing with a keyboard plugged into the device may be safe in most cases. But I got trouble with one keyboard (IBM/Unicomp Model M) after using FLIP for flashing with it inserted; it seems like the drivers or registry entry got corrupted somehow because now it won't mount on that PC anymore even though it's quite okay on other machines. Be warned.


<h4>Flashing the device on Linux:</h4>

My script run with the <b>-f</b> option flashes the generated HEX file to a connected device using DFU-Programmer; if you've already made the .hex file use <b>-b</b> to skip rebuilding it. If you want to flash without using my script, you could use the 'make dfu' command inside the usb_usb directory, or look inside the script to see how I did it.

According to the <a href="https://github.com/tmk/tmk_keyboard/wiki/FAQ-Build">TMK wiki build FAQ</a>, you'll need admin/sudo rights for the 'dfu-programmer' command (there's <a href="https://github.com/tmk/tmk_keyboard/wiki/FAQ-Build#linux-udev-rules">a workaround using udev rules</a>, but it's a bit techy). I've tried flashing without sudo and it worked for me in one case but not another. If you do need sudo, run makeflash like this:
<pre><code>
$> sudo ./makeflash_dreymar_tmk.sh -bf
</code></pre><br>

<b>NOTE:</b> You do <i>not</i> generally want to build your files as root! Then you'll be in trouble if you try to clean up as non-root afterwards. 
So run MakeFlash twice, once with normal privileges to build your .hex file and the other time with -b (to not build again) and -f (to flash) with sudo/root privileges.

If you're using BASH on Windows 10 (beta), <a href="https://github.com/tmk/tmk_keyboard/wiki/Bash-On-Ubuntu-On-Windows10">dfu-programmer won't work yet</a>, due to a problem with mounting USB devices in general (libusb). Use Windows native tools instead, such as FLIP or dfu-programmer for Windows. 
For updated WSL installs, this probably isn't a problem anymore.

If you have another device, you may need some other method and more tools. As mentioned at the start of this page, there are help files you may consult for this.


<h4>Flashing the device on Windows:</h4>

I used to flash with Atmel FLIP on Windows instead of under Linux: It gives you more feedback and intuitive control with the process. 
If you compiled your HEX file on Linux you must make it available for the Windows file system to use Windows FLIP. Using newer WSL, this is easy.
Earlier, I put the whole TMK repository in a shared folder that both Windows and my virtual Linux machine can see; 
you could also move it on a USB drive or copy-paste from a Virtual Machine if your VM settings allow this.

NOTE: Atmel FLIP has been difficult for me lately, as it doesn't seem to find an updated Java version on my system. 
You may try other flashing tools. Lately I've used the <a href="https://github.com/qmk/qmk_toolbox/"><b>QMK Toolbox</b></a> on Windows. It works great.
Some of the other tools work in a way quite similar to FLIP, so the instructions below may prove instructive to you no matter what.

1) Select the right chip (fig 5–1)</b>. For the Hasu device, it's <b>ATmega32U4</b>. Verify the chip type <b><i>(fig 5–a)</i></b>.
2) <b>Connect to the device</b> in Bootloader mode. Select <b>USB connection (fig 5–2)</b> then <b>Open</b>. Verify the connection <b><i>(fig 5–c)</i></b>.
3) <b>Load a HEX file (fig 5–3)</b>. Use shared folders, a USB disk or some other way of accessing the file with Windows.
    - Verify for ATmega32U4 which only has 32kB memory minus 4 kB bootloader, that the file size is below <b>28480 bytes</b> <b><i>(fig 5–b)</i></b>.
4) <b>Flash the device (fig 5–4)</b>. Make sure all options are on as shown, then press "<b>Run</b>".
5) <b>Activate the device (fig 5–5)</b>. Press "<b>Start Application</b>". Reset should be checked.
6) <b>Test the device</b>. You may have to plug it out and in again first. Then, plug a keyboard to the device and type away.

<br>
<img src="img/USB2USB_AtmelFlip_Hasu.png">
<i>Fig. 5: Atmel FLIP for Windows. 1) Select chip (a); 2) Connect (c); 3) Load HEX file (b); 4) Flash device; 5) Start device</i><br>
<br>

<br><br>

---

<br><br>

<a name="hardware-implementations"></a><h3>[4.4]    HARDWARE IMPLEMENTATIONS</h3>

I won't cover all possibilities here. I use Hasu's converters myself and haven't got any experience with others, but the possibilities are many.

One little note: I've experienced that my Hasu device doesn't provide enough power to drive all keyboards, such as some fancy ones with RGB LEDs. 
I'm guessing there isn't much to be done about it? Mostly, I use my device with ordinary keyboards and it works perfectly.

A <a href="https://geekhack.org/index.php?topic=80421">Pro Micro (such as the one seen above by GeekHack user Yangdigi)</a> may be cheapest, but it also seems to be the most techy option?

Colemak forum user <a href="https://forum.colemak.com/user/2108-darkness/">Darkness</a> made a device and <a href="https://github.com/darkytoothpaste/keymapper">his own code for it</a>, see <a href="https://forum.colemak.com/viewtopic.php?id=1561">his "Arduino-based hardware keyboard remapper" topic</a> for more info. Scroll down that page for pictures and a nice <a href="https://forum.colemak.com/viewtopic.php?pid=11494#p11494">how-to sum-up post</a>. He started off with an Arduino Leonardo like the one to the left in Yangdigi's image above; this can be a good development platform if you have one. But for a more useful implementation, he uses an Arduino Teensy 2.0 as seen below. Hasu has tried his TMK code on this device and it seems to be working fine.

<br>
<img src="img/USB2USB_DarkyToothpaste_Teensy.jpg">
<i>Darkness's Teensy-based USB-2-USB Converter (see <a href="https://forum.colemak.com/viewtopic.php?id=1561">his topic</a>)</i><br>
<br>

I'm really hoping that <b><a href="https://www.kickstarter.com/projects/paulstoffregen/teensy-35-and-36/description">the upcoming Teensy 3.5/3.6</a></b> can be used for TMK! These devices are fast, have a <i>lot</i> more Flash/RAM (512/192 kB for 3.5; 1024/256 kB for 3.6) and most importantly, come with a second USB intended for Host mode so it won't need a separate USB host! That may make it a cheap and powerful option; someone will hopefully test this soon.

The safest and easiest option may be to order the brilliant <b><a href="https://geekhack.org/index.php?topic=69169.0">USB to USB Converter from GeekHack user Hasu</a></b>, who has also developed the TMK software for converting keyboards to more awesome keyboards. (Hasu's device is also available from <a href="https://www.1upkeyboards.com/shop/controllers/usb-to-usb-converter/">1UpKeyboards</a> which has a web shop but at a higher price from what I can see.) I've got a few of these beauties, and my code, instructions and .hex definition files below are based on Hasu's device although they may be used for other devices too (may need some geeky tweaking).

<br>
<img src="img/USB2USB_Hasu-NJBair_GeekHack-topic74708_GadOE.jpg">
<i>Hasu's <a href="https://geekhack.org/index.php?topic=69169.0">USB to USB Converter for TMK Key mapping</a> (original photo by <a href="https://geekhack.org/index.php?topic=74708.0">Nick J Bair</a>)</i><br>
<br>

<img src="img/PS2USB_Hasu_GadOE.png">
<i>Oh look, Hasu has other converters and keyboard controllers too! <br>
Here's a <b>PS/2-to-USB converter</b> making my friend's vintage IBM Model M board awesome.</i><br>
<br>

This topic won't show you any more about how to get your own QUICKIE USB-2-USB device. From my own experience I can heartily recommend Hasu's products, but find out what works for you. Best of luck, either way!

<br><br>

---

<br><br>

<h2>[-]    <ins>Links/Done/Todo</ins></h2>

<br><h3>LINKS:</h3>

<ins><i>@GeekHack:</i></ins>
* <b><a href="https://geekhack.org/index.php?topic=69169">Hasu's USB to USB converter topic</a></b>, and 
* <a href="https://geekhack.org/index.php?topic=72052.0">Hasu's converter buying topic</a>
* <a href="https://geekhack.org/index.php?topic=41989.0">Hasu's TMK topic</a> (code basis for keyboard controllers/converters in general)
* <a href="https://geekhack.org/index.php?topic=74708.0">NJBair's review of Hasu's USB-2-USB converter</a>, with 
* <a href="https://geekhack.org/index.php?topic=74708.msg2149453#msg2149453">a nice FLIP guide</a>
* <a href="https://geekhack.org/index.php?topic=80421">YangDigi's Pro Micro DIY converter topic</a> (some Teensy info too)

<ins><i>@GitHub:</i></ins>
* <b><a href="https://github.com/tmk/tmk_keyboard">Hasu's GitHub TMK repository</a></b>, and its 
* <a href="https://github.com/tmk/tmk_keyboard/tree/master/converter/usb_usb/">USB-2-USB section</a>
* <a href="https://github.com/tmk/tmk_keyboard/wiki/FAQ-Build">Hasu's Build FAQ</a>, 
* <a href="https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/build.md">Build README</a>, and 
* <a href="https://github.com/tmk/tmk_keyboard/blob/master/tmk_core/doc/keymap.md">keymap README</a>
* <a href="https://github.com/njbair/keyboard_firmware#building--flashing-the-firmware">NJBair's repository</a> including some build/flash info
* <a href="https://github.com/tmk/tmk_keyboard/wiki">Hasu's TMK Keyboard Wiki</a> with much useful info

<ins><i>@TMK_site:</i></ins>
* <b><a href="http://www.tmk-kbd.com/tmk_keyboard/editor/usb_usb/index.html">Hasu's Online TMK Keymap Editor for the USB to USB converter</a></b>

<ins><i>@Colemak:</i></ins>
* <a href="https://forum.colemak.com/topic/1561-arduinobased-hardware-keyboard-remapper/">Darkness' Arduino-based hardware keyboard remapper topic</a>

<ins><i>@QMK:</i></ins>
* <b><a href="http://qmk.fm/">QMK (Quantum Mechanical Keyboard)</a></b> is a TMK-fork-gone-solo that deserves honorable mention
* <a href="https://github.com/jackhumbert/qmk_firmware">The GitHub QMK repository</a>  (I don't use QMK myself, but it has a lot of documentation and more)

<ins><i>Flashing tools:</i></ins>
* [QMK Toolbox](https://github.com/qmk/qmk_toolbox/); "a collection of flashing tools packaged into one app. It supports auto-detection and auto-flashing of firmware to keyboards."
  - On Windows: Asked whether to install drivers. Successfully installed a driver for the Hasu device. It showed up in Device Manager as "Atmel USB Devices -> ATmega32U4".
* [DFU-programmer](https://github.com/dfu-programmer/dfu-programmer); "an implementation of the Device Firmware Upgrade class USB driver that enables (...) Atmel chips."
  - This is a commonly used flashing tool on Linux.
* [kp_boot_32u4](https://github.com/ahtn/kp_boot_32u4); "a simple bootloader for the ATmega32u4 family (...). The code size is <1kB and doesn't need drivers on Windows."
  - Command-line-based. Seems compact enough? Installed w/ a Python script. Apparently, KeyPlus below uses it?
* [KeyPlus](https://github.com/ahtn/keyplus); "an easy to use keyboard firmware (...) in beta". Precompiled, w/ a GUI. 
  - On Windows: Didn't find my Hasu (atmega23u4) device, at least not right away...?


<br><h3>DONE:</h3>
* 2016-07: Now witness the typing power of this fully operational USB-2-USB device! Happy hacking, brave and adventurous souls!
* 2018-01: Added a user function that allows for input of Unicode glyphs not in the layout using the AltGr(RAlt) modifier.
* 2018-02: More advanced modifiers for Extend2+. Hold down, e.g., RShift then Caps (then release RShift) for Extend2. Can't use Alt keys (yet) on Win.
* 2023-11: Added Sym mods. Some other rework: Removed Workman, DHk and Curl keymaps; added the Canary layout and made Extend respect CURLMOD instead.


<br><h3>TODO:</h3>
* Extend modifiers don't always stack? Caps+S+T+N didn't produce Ctrl+Shift+Left but ST keystrokes for me once; others have had no such problems.
* Use the ScrollLock LED to show whether the second layout is active?
* Port the BigBag4USB to the more popular QMK code platform? Does it support Hasu's USB-2-USB device?


<br>
<img src="https://dreymar.colemak.org/res/cmk/hardware/Cmk-CAW_Unicomp_DreymaR_TN-Ninja.png">
<i>My Unicomp SpaceSaver Buckling Spring (IBM Model M ISO type) keyboard with "American/Ninja" caps, splendidly sporting the Colemak-CAW layout.</i><br>
<br>

[BBoT]: https://dreymar.colemak.org (DreymaR's Big Bag of Keyboard Tricks)
[BBTU]: http://forum.colemak.com/viewtopic.php?id=2158 (DreymaR's Big Bag of Keyboard Tricks - TMK/USB edition)
[TMKG]: https://github.com/tmk/tmk_keyboard (Hasu's TMK repository on GitHub)
[CMKF]: http://forum.colemak.com (Shai's Colemak forums)
[HU2U]: https://geekhack.org/index.php?topic=69169 (Hasu's USB-USB keyboard converter)
