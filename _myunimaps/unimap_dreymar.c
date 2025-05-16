/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 *  2016- "DreymaR" (Øystein Bech Gadmar; 2021- Øystein Bech-Aase)
 *  Colemak, Curl/Angle/Wide and Extend layouts, and more
 *  See DreymaR's Big Bag of Keyboard Tricks for info
 *  https://dreymar.colemak.org
 *  
 *  Compiler preprocessor definitions select layout, Extend layers and other options:
 *  - UNIMAPLAYOUT  # selects physical/ergonomic layout: ISO/ANSI, Angle/Wide ergo mods
 *  - ACTIVELAYOUT  # selects first/active layout: QWERTY, Colemak, etc
 *  - SECONDLAYOUT  # selects second/switch layout: QWERTY, Colemak, mirrored Colemak, etc
 *  - CURLMOD       # selects the Curl(DH) ergo mod (only affects Colemak/Tarmak layouts)
 *  - SYMBOLKEYS    # selects the Sym ergo mod and other SymbolKey stuff
 *  - CAPSBEHAVIOR  # selects CapsLock key behavior (Extend, BackSpace etc)
 *  - STICKYMODS    # selects modifier behavior: Shift and/or RCtrl become handy One-Shot Mods
 *  - ...             (see below for more)
 *  
 *  TODO:
 *  - Turn the ScrollLock LED on when the second layout is active? How?
 *  - Make an function for FnLA/FnRA to enable #Alt as Ext# modifiers?
 *      - It could also implement the Alt-as-extend-hold functionality (press #Alt+Extend, then keep either one down)
 *      - Could use EXTENDER with the opt parameter (0-3, bitwise logic) to determine Caps/LAlt/RAlt!?
 *      - Static (global?) "extAlt" variable that's set in EXTENDER if #Alt is down, and unset on #Alt release?
 *      - Or an extBit variable - a bit logic variable detecting Extend/Caps, Ext2/LAlt and Ext3/RAlt states?
 *      - Release the #Alt mod bit either way, but only register/unregister #Alt if Extend isn't down?
 *      - EXTENDER currently detects mod bits, so we'd have to switch to a variable?
 *  
 *  DONE:
 *  - Made a FOURLVLU user function that allows locale letter input with RAlt/AltGr on a few keys.
 *      - It uses an OS specific input method selected by #define.
 *  - Made an EXTENDER user function for the chorded Ext2+Ext3+Extend modifiers, by default on Caps.
 *      - Releasing the Extend key clears all mods & returns to the previously active layer (0 or 1).
 */

/* ***** SETTINGS ***************************************************************************************************** */

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

/* NOTE: These enumerations won't work for precompiler directives? Maybe they aren't needed, but they look nice. ;-)    */
enum mainlayouts    {
    LAY_QWERTY      ,   /* QWERTY mappings                          */
    LAY_TARMAK1     ,   /* Tarmak#, stepping stones to Colemak      */
    LAY_TARMAK2     ,   /* --"--                                    */
    LAY_TARMAK3     ,   /* --"--                                    */
    LAY_TARMAK4     ,   /* --"--                                    */
    LAY_COLEMAK     ,   /* Colemak!                                 */
    LAY_CMKMIRR     ,   /* (Mirrored Colemak; normally 2nd layout!) */
    LAY_DVORAK      ,   /* Dvorak, if you're retro                  */
    LAY_CANARY      ,   /* Canary, if you're avantgarde             */
    LAY_GRALMAK     };  /* Gralmak/Graphite, if you're avantgarder  */
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
 *  9  : Gralmak (A slightly conservative Graphite variant, keeping symbol keys and shift states unchanged)
 */
#define ACTIVELAYOUT    5                       /* LAY_COLEMAK      */

enum secondlayouts   {
    SEC_VANQWERTY    ,   /* QWERTY, vanilla/unmodded                */
    SEC_MODQWERTY    ,   /* QWERTY, ergo mods active                */
    SEC_ENHANCED     ,   /* Colemak (or edit to what you want)      */
    SEC_CMKMIRR      };  /* Mirrored Colemak (use Cmk as 1st)       */
/*  Define the SECONDLAYOUT (and CURLMOD) constant(s) to choose the layer1 switch layout:
 *  0  : Unmodded QWERTY is the default; otherwise:
 *  1  : QWERTY with any active ergo mods (AngleWide etc)
 *  2-#: Colemak (if you want something else, replace it in the code between the 'REPLACE THE SECOND LAYOUT...' lines)
 *  3-#: Colemak Mirrored as second layout for one-handed typing (needs an accessible switch key!)
 *      NOTE: The "FSLk" key is a layer1 toggle or switch (select which below), normally used on the ScrollLock key.
 *            You may swap, e.g., LALT, RGUI or another key with FSLk in your active layout to use that key instead.
 */
#define SECONDLAYOUT    0                       /* SEC_VANQWERTY    */

enum curlmods       {
    CURL_NONE       ,   /* No curl, plain vanilla Colemak/Tarmak    */
    CURL_DH         };  /* The Colemak/Tarmak-DH Curl mod           */
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

enum symbolkeys     {
    SYM_NONE        ,   /* No Sym key changes                       */
    SYM_NONW        ,   /* Sym for non-Wide variants                */
    SYM_WISO        ,   /* Sym for Wide-ISO variants                */
    SYM_WANS        ,   /* Sym for Wide-ANSI variants               */
    SYM_4LVLUNI     ,   /* Some OEM keys give 4-level Unicode input */
    SYM_ISOHACK     };  /* Swap some OEM keys around for ISO-Nor    */
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
#define SYMBOLKEYS      3                       /* SYM_WANS         */

enum capsbehaviors  {
    CAPS_CAPS       ,   /* CapsLock as its plain old self           */
    CAPS_EXTEND     ,   /* CapsLock as Extend modifier              */
    CAPS_BACK       ,   /* CapsLock as Backspace                    */
    CAPS_LCTL       ,   /* CapsLock as LCtrl                        */
    CAPS_ESC        };  /* CapsLock as Escape                       */
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

enum oneshotmods    {
    STICKY_NONE     ,   /* No sticky/oneshot modifiers              */
    STICKY_SHFT     ,   /* Sticky LShift/RShift                     */
    STICKY_LCTL     ,   /* Sticky LCtrl (RCtrl left alone)          */
    STICKY_SHCT     };  /* Sticky Shift & LCtrl                     */
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

enum sclkbehaviors  {
    SLCK_SLCK       ,   /* ScrollLock as its old self               */
    SLCK_L1TOGGLE   ,   /* ScrollLock as Layer 1 toggle             */
    SLCK_L1SWITCH   };  /* ScrollLock as Layer 1 switch             */
/*  The SLCKBEHAVIOR constant chooses ScrollLock key action:
 *  0: Normal ScrollLock (default)
 *  1: Layer 1 toggle key (toggles the second layout)
 *  2: Layer 1 switch key (layer shift; e.g., for mirrored typing if you can use it as "ghetto" foot switch)
 */
#define SLCKBEHAVIOR    1                       /* SLCK_L1TOGGLE    */

enum pausbehaviors  {
    PAUS_PAUS       ,   /* Pause as its old self                    */
    PAUS_LGUI       };  /* Pause as LWin/LGUI                       */
/*  The PAUSBEHAVIOR constant chooses Pause/Break key action:
 *  0: Normal Pause/Break (default)
 *  1: Win/GUI key (useful for 101/104-key boards that have no GUI key)
 */
#define PAUSBEHAVIOR    0                       /* PAUS_PAUS        */

/*  UNICODEHEADER and UNICODEFOOTER handle OS dependency in the FOURLVLU user function, used by SYMBOLKEYS above.       */
/*  TODO: These headers haven't been tested on XOrg and MacOS. Also, TMK now has easy-to-use UNI[X|W|M]_() macros.      */
/*  For XOrg,    Unicode 4-digit hex input uses Ctrl+Shift+u, ####, Enter.                                              */
//#define UNICODEHEADER add_weak_mods( MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT) ); type_code( KC_U    ); /* Ctrl+Shift+U,    */
//#define UNICODEFOOTER del_weak_mods( MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT) ); type_code( KC_ENT  ); /* Del_mods; Enter. */
            /*  <-- FOURLVLU Unicode header/footer for XOrg                                             */
/*  For MacOS,   Unicode 4-digit hex Unicode input uses Alt+#### (as Alt equals Mac Option).                            */
//#define UNICODEHEADER   add_weak_mods( MOD_BIT(KC_LALT) );            /*  Hold Option/LAlt.           */
//#define UNICODEFOOTER   del_weak_mods( MOD_BIT(KC_LALT) );            /*  Release Option/LAlt.        */
            /*  <-- FOURLVLU Unicode header/footer for MacOS                                            */
/*  For Windows, Unicode 4-digit decimal nr. input uses Alt+Keypad(####). It works with RAlt too on the US/ANSI layout. */
#define UNICODEHEADER   set_mods( MOD_BIT(KC_RALT) );                   /*  Keep just the RAlt bit,     */
#define UNICODEFOOTER   ;                                               /*  No footer necessary here.   */
            /*  <-- FOURLVLU Unicode header/footer for Windows                                          */

/* DreymaR's master key! Define it for a quick override. It gets compiler warnings due to redefinition; ignore these.   */
//#define MASTERKEY
#ifdef MASTERKEY
# define UNIMAPLAYOUT(...)  UNIMAP_ISO_AW( __VA_ARGS__ )    /* AngleWide-ISO keymap */
# define ACTIVELAYOUT   9                                   /* LAY_GRALMAK      */
//# define SECONDLAYOUT   0                                   /* SEC_VANQWERTY    */
# define CURLMOD        0                                   /* CURL_DH(m): off  */
# define SYMBOLKEYS     5                                   /* SYM_ISOHACK      */
//# define CAPSBEHAVIOR   1                                   /* CAPS_EXTEND      */
//# define STICKYMODS     1                                   /* STICKY_SHFT      */
//# define SLCKBEHAVIOR   1                                   /* SLCK_L1TOGGLE    */
//# define PAUSBEHAVIOR   0                                   /* PAUS_PAUS        */
#endif      /* ifdef MASTERKEY */

/* ***** DECLARATIONS ************************************************************************************************* */

/* The UNIMAP keymap (new universal 128-key format w/o the Korean and rare rightmost keys) is used for these files:     */
#include "unimap_trans.h"
#include "unimap_dreymar.h"

/* *******  User function and macro declarations/enumerations -->       ******* */
enum function_id {
    FOURLVLU,
    EXTENDER
};

enum macro_id {
    TYPESTR1,
    TYPESTR2
};    /* *******    <-- User function and macro declarations            ******* */

/* *******  Fn action key definitions (Unimap style) -->                ******* */
/*  Some symbol keys are defined as special 'F' codes in this file, facilitating ACTION_KEY mapping:
 *  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql, -- ,BSPC
 *  TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl
 *  FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,FScl,FQuo,FHsh,  ENT 
 *  FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,FSls, -- ,    FRSh
 *  LCTL ,LGUI,FnLA, -- ,         SPC          , -- , -- ,FnRA,RGUI,APP , FRCt  */
/*  NOTE: The BSLS/FBsl (ANSI) and NUHS/FHsh (ISO) key have, to my knowledge, the same scan code (Windows SC02b).       *
 *      - In the US layouts and most others, it's mapped to \ (Backslash) but its Shift-mappings vary. UK has # (Hash). *
 *      - Since TMK uses two names for it, I've used BSLS for ANSI and NUHS for ISO mappings. Shouldn't matter though?  */
#define AC_FnLA ACTION_KEY(KC_LALT)                 // FnLA (LAlt key) unchanged for now
#define AC_FnRA ACTION_KEY(KC_RALT)                 // FnRA (RAlt key) unchanged for now
#if     CAPSBEHAVIOR == 1
# define AC_FCap ACTION_FUNCTION(EXTENDER)          // FCap selects Extend# depending on which Ext# keys are pressed too.
//# define AC_FnU1 ACTION_MODS_KEY(MOD_LGUI,KC_T)      // FnU1 (`) as Win+T
# define AC_FnU1 ACTION_MACRO(TYPESTR1)             // FnU1 as user macro: Type a string
# define AC_FnU2 ACTION_MACRO(TYPESTR2)             // FnU2 as user macro: Type a string
#elif   CAPSBEHAVIOR == 2
# define AC_FCap ACTION_KEY(KC_BSPC)                // FCap (Caps key) as BackSpace (for Colemak etc)
#elif   CAPSBEHAVIOR == 3
# define AC_FCap ACTION_KEY(KC_LCTL)                // FCap (Caps key) as LeftCtrl
#elif   CAPSBEHAVIOR == 4
# define AC_FCap ACTION_KEY(KC_ESC)                 // FCap (Caps key) as Esc
#else
# define AC_FCap ACTION_KEY(KC_CAPS)                // FCap (Caps key) unchanged
#endif      /* if CAPSBEHAVIOR */

#if     STICKYMODS == 1
# define AC_FLSh ACTION_MODS_ONESHOT(MOD_LSFT)      // FLSh (Left Shift key)  as sticky shift
# define AC_FRSh ACTION_MODS_ONESHOT(MOD_RSFT)      // FRSh (Right Shift key) as sticky shift
# define AC_FRCt ACTION_KEY(KC_RCTL)                // FRCt (Right Ctrl key)  unchanged
#elif   STICKYMODS == 2
# define AC_FLSh ACTION_KEY(KC_LSFT)                // FLSh (Left Shift key)  unchanged
# define AC_FRSh ACTION_KEY(KC_RSFT)                // FRSh (Right Shift key) unchanged
# define AC_FRCt ACTION_MODS_ONESHOT(MOD_RCTL)      // FRCt (Right Ctrl key)  as sticky control
#elif   STICKYMODS == 3
# define AC_FLSh ACTION_MODS_ONESHOT(MOD_LSFT)      // FLSh (Left Shift key)  as sticky shift
# define AC_FRSh ACTION_MODS_ONESHOT(MOD_RSFT)      // FRSh (Right Shift key) as sticky shift
# define AC_FRCt ACTION_MODS_ONESHOT(MOD_RCTL)      // FRCt (Right Ctrl key)  as sticky control
#else
# define AC_FLSh ACTION_KEY(KC_LSFT)                // FLSh (Left Shift key)  unchanged
# define AC_FRSh ACTION_KEY(KC_RSFT)                // FRSh (Right Shift key) unchanged
# define AC_FRCt ACTION_KEY(KC_RCTL)                // FRCt (Right Ctrl key)  unchanged
#endif      /* if STICKYMODS */

#if     SLCKBEHAVIOR == 1
# define AC_FSLk ACTION_LAYER_TOGGLE(1)             // FSLk as layer1 (second layout) toggle
#elif   SLCKBEHAVIOR == 2
# define AC_FSLk ACTION_LAYER_MOMENTARY(1)          // FSLk as layer1 switch (e.g., for mirrored typing)
#else
# define AC_FSLk ACTION_KEY(KC_SLCK)                // FSLk (ScrollLock key) unchanged
#endif      /* if SLCKBEHAVIOR */

#if     PAUSBEHAVIOR == 1
# define AC_FPau ACTION_KEY(KC_LGUI)                // Fpau as GUI/Win (for 101/104-key boards)
#else
# define AC_FPau ACTION_KEY(KC_PAUS)                // FPau (Pause/Break key) unchanged
#endif      /* if PAUSBEHAVIOR */

/*  Extend2 uses parentheses and colon - these definitions provide those symbols                                        */
# define AC_FsLP ACTION_MODS_KEY(MOD_LSFT, KC_9)    // FsLP is Shift+9 (left  parenthesis, US)
# define AC_FsRP ACTION_MODS_KEY(MOD_LSFT, KC_0)    // FsRP is Shift+0 (right parenthesis, US)
# define AC_FsSC ACTION_MODS_KEY(MOD_LSFT, KC_SCLN) // FsSC is Shift+Semicolon (colon, US)

/*    Common symbol key definitions - these may get redefined below by mods (gets you a warning, but don't worry!)      */
# define AC_FBsl ACTION_KEY(KC_BSLS)                // FBsl (BSLS \| )  ANSI/US Backslash key
# define AC_FHsh ACTION_KEY(KC_NUHS)                // FHsh (NUHS \| )  ISO/Non-US Hash key "=" Backslash (but UK # )
# define AC_FLgt ACTION_KEY(KC_NUBS)                // FLgt (NUBS <> )  ISO/Non-US extra "102nd" key (often <> or -_ )
#if     SYMBOLKEYS == 1
/*    Sym mod for non-Wide ergo mods                                                                                    */
# define AC_FMin ACTION_KEY(KC_EQL)                 // FMin (MINS -_ ) as EQL   =+  1)  [{  =+  -_  loop
# define AC_FEql ACTION_KEY(KC_LBRC)                // FEql (EQL  =+ ) as LBRC  [{  1)
# define AC_FLBr ACTION_KEY(KC_MINS)                // FLBr (LBRC [{ ) as MINS  -_  1)
# define AC_FRBr ACTION_KEY(KC_RBRC)                // FRBr (RBRC ]} ) --
# define AC_FScl ACTION_KEY(KC_QUOT)                // FScl (SCLN ;: ) as QUOT  '"  2)  '"  ;:  swap
# define AC_FQuo ACTION_KEY(KC_SCLN)                // FQuo (QUOT '" ) as SCLN  ;:  2)
# define AC_FSls ACTION_KEY(KC_SLSH)                // FSls (SLSH /? ) --
#elif   SYMBOLKEYS == 2
/*    Sym mod for Wide mod combos on ISO keyboards                                                                      */
# define AC_FMin ACTION_KEY(KC_EQL)                 // FMin (MINS -_ ) as EQL   =+  1)  \|  =+  -_  /?  loop
# define AC_FEql ACTION_KEY(KC_NUHS)                // FEql (EQL  =+ ) as NUHS  \|  1)
# define AC_FLBr ACTION_KEY(KC_LBRC)                // FLBr (LBRC [{ ) --
# define AC_FRBr ACTION_KEY(KC_RBRC)                // FRBr (RBRC ]} ) --
# define AC_FScl ACTION_KEY(KC_QUOT)                // FScl (SCLN ;: ) as QUOT  '"  2)  '"  ;:  swap
# define AC_FQuo ACTION_KEY(KC_SCLN)                // FQuo (QUOT '" ) as SCLN  ;:  2)
# define AC_FHsh ACTION_KEY(KC_SLSH)                // FHsh (NUHS \| ) as SLSH  /?  1)
# define AC_FSls ACTION_KEY(KC_MINS)                // FSls (SLSH /? ) as MINS  -_  1)
#elif   SYMBOLKEYS == 3
/*    Sym mod for Wide mod combos on ANSI keyboards                                                                     */
# define AC_FMin ACTION_KEY(KC_EQL)                 // FMin (MINS -_ ) as EQL   =+  1)  =+  -_  '"  ;:  \|  loop
# define AC_FEql ACTION_KEY(KC_BSLS)                // FEql (EQL  =+ ) as BSLS  \|  1)
# define AC_FLBr ACTION_KEY(KC_LBRC)                // FLBr (LBRC [{ ) --
# define AC_FRBr ACTION_KEY(KC_RBRC)                // FRBr (RBRC ]} ) --
# define AC_FScl ACTION_KEY(KC_QUOT)                // FScl (SCLN ;: ) as QUOT  '"  1)
# define AC_FQuo ACTION_KEY(KC_MINS)                // FQuo (QUOT '" ) as MINS  -_  1)
# define AC_FBsl ACTION_KEY(KC_SCLN)                // FBsl (BSLS \| ) as SCLN  ;:  1)
# define AC_FSls ACTION_KEY(KC_SLSH)                // FSls (SLSH /? ) --
#elif   SYMBOLKEYS == 4
/*    Define some keys as 4-level (using AltGr/RAlt) to get special letters with the US layout on ISO                   */
# define AC_FMin ACTION_KEY(KC_MINS)                // FMin (MINS -_ ) --
# define AC_FEql ACTION_KEY(KC_EQL)                 // FEql (EQL  =+ ) --
# define AC_FLBr ACTION_FUNCTION_OPT(FOURLVLU,0)    // FLBr (LBRC [{ ) as 4lvl  [{  åÅ
# define AC_FRBr ACTION_FUNCTION_OPT(FOURLVLU,1)    // FRBr (RBRC ]} ) as 4lvl  ]}  æÆ
# define AC_FScl ACTION_KEY(KC_SCLN)                // FScl (SCLN ;: ) --
# define AC_FQuo ACTION_KEY(KC_QUOT)                // FQuo (QUOT '" ) --
# define AC_FHsh ACTION_FUNCTION_OPT(FOURLVLU,3)    // FHsh (NUHS \| ) as 4lvl  \|  •†
# define AC_FLgt ACTION_FUNCTION_OPT(FOURLVLU,2)    // FLgt (NUBS -_ ) as 4lvl  -_  øØ
# define AC_FSls ACTION_KEY(KC_SLSH)                // FSls (SLSH /? ) --
#elif   SYMBOLKEYS == 5
/*    Adaptations for a more US-like Colemak-CAWS on the Nor locale (DreymaR's ISO-Nor hack):       */
/*      For Cmk-CAWS:   MINS    EQL     LBRC    RBRC -> QUOT    SCLN -> NUHS    NUBS    SLSH        */
/*    ( Old Cmk-CAW:    RBRC -> SCLN -> NUBS -> NUHS -> QUOT    LBRC    EQL     MINS -> SLSH )      */
# define AC_FMin ACTION_KEY(KC_MINS)                // FMin (MINS +? ) --       +?
# define AC_FEql ACTION_KEY(KC_EQL)                 // FEql (EQL  \` ) --       \`
# define AC_FLBr ACTION_KEY(KC_LBRC)                // FLBr (LBRC åÅ ) --       åÅ
# define AC_FRBr ACTION_KEY(KC_QUOT)                // FRBr (RBRC ¨^ ) as QUOT  æÆ  1)  '"  ]}  swap
# define AC_FScl ACTION_KEY(KC_NUHS)                // FScl (SCLN øØ ) as NUHS  '*  2)  \|  ;:  swap
# define AC_FQuo ACTION_KEY(KC_RBRC)                // FQuo (QUOT æÆ ) as RBRC  ¨^  1)
# define AC_FHsh ACTION_KEY(KC_SCLN)                // FHsh (NUHS '* ) as SCLN  øØ  2)
//# define AC_FLgt ACTION_KEY(KC_NUBS)              // FLgt (NUBS <> ) --       <>
# define AC_FSls ACTION_KEY(KC_SLSH)                // FSls (SLSH -_ ) --       -_
# define AC_FsLP ACTION_MODS_KEY(MOD_LSFT, KC_8)    // FsLP is Shift+8 (left  parenthesis, Nor)
# define AC_FsRP ACTION_MODS_KEY(MOD_LSFT, KC_9)    // FsRP is Shift+9 (right parenthesis, Nor)
# define AC_FsSC ACTION_MODS_KEY(MOD_LSFT, KC_DOT)  // FsSC is Shift+Period (colon, Nor)
#else                                               // NOTE: BSLS/NUHS ( \| ) and NUBS ( <> ) are defined above
# define AC_FMin ACTION_KEY(KC_MINS)                // FMin (MINS -_ ) --
# define AC_FEql ACTION_KEY(KC_EQL)                 // FEql (EQL  =+ ) --
# define AC_FLBr ACTION_KEY(KC_LBRC)                // FLBr (LBRC [{ ) --
# define AC_FRBr ACTION_KEY(KC_RBRC)                // FRBr (RBRC ]} ) --
# define AC_FScl ACTION_KEY(KC_SCLN)                // FScl (SCLN ;: ) --
# define AC_FQuo ACTION_KEY(KC_QUOT)                // FQuo (QUOT '" ) --
# define AC_FSls ACTION_KEY(KC_SLSH)                // FSls (SLSH /? ) --
#endif      /* if SYMBOLKEYS */
    /* *******  <-- Fn action key definitions (Unimap style)            ******* */

/* ***** LAYOUTS ****************************************************************************************************** */

/* ******* Keymap layer definitions (mini Unimap style used here) -->   ******* */
#ifdef KEYMAP_SECTION_ENABLE
  const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
  const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif

    /* *******  Layer 0: Default Layout -->                             ******* */
    [0] = UNIMAPLAYOUT(
    /* Layout independent top row(s) - except for mirrored Colemak (layout #6) which moves the F# key row               */
#if     ACTIVELAYOUT == 6
#else
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
#endif      /* if ACTIVELAYOUT == 6 */

#if     ACTIVELAYOUT == 0
    /*  Plain QWERTY (shown on a full _UNIMAP_D layout without the top F13-24 row)
     *  ,---˛   ,---------------˛ ,---------------˛ ,---------------˛ ,-----------˛     ,-----------˛
     *  |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |VDn|VUp|Mut|
     *  `---´   `---------------´ `---------------´ `---------------´ `-----------´     `-----------´
     *  ,-----------------------------------------------------------˛ ,-----------˛ ,---------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|BSp| |Ins|Hom|PgU| |NLk|  /|  *|  -|
     *  |-----------------------------------------------------------| |-----------| |---------------|
     *  | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
     *  |-----------------------------------------------------------| `-----------´ |---------------|
     *  | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |               |  4|  5|  6|  ,|
     *  |-----------------------------------------------------------|     ,---˛     |---------------|
     *  |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO| Shft |     |Up |     |  1|  2|  3|Ent|
     *  |-----------------------------------------------------------| ,-----------˛ |---------------|
     *  |Ctrl|Gui|Alt|MHEN|     Space     |HENK|KANA|Alt|Gui|App|Ctl| |Lft|Dwn|Rgh| |      0|  .|  =|
     *  `-----------------------------------------------------------´ `-----------´ `---------------´
     */
    /*  QWERTY-Angle(Z)Wide(') for ANSI boards; use the `_ANS_AW` keymap for this ergonomic variant
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  E|  R|  T|  [|  Y|  U|  I|  O|  P|  '|   \ |
     *  |-----------------------------------------------------------|
     *  |*BSpc*|  A|  S|  D|  F|  G|  ]|  H|  J|  K|  L|  ;|  Enter |
     *  |-----------------------------------------------------------|
     *  | Shift  |  X|  C|  V|  B|  Z|  /|  N|  M|  ,|  .|    Shift |
     *  |-----------------------------------------------------------|
     *  |Ctrl |Gui |Alt |         Space        |Alt |Gui |Menu| Ctrl|
     *  `-----------------------------------------------------------´   */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#elif   ACTIVELAYOUT == 1
    /*  Tarmak1 - Transitional Colemak (E)
     *  ,-----------------------------------------------------------˛
     *  |     |  q|  w| *J|  r|  t|  y|  u|  i|  o|  p|   |   |     |
     *  |-----------------------------------------------------------|
     *  |      |  a|  s|  d|  f|  g|  h|  N|  E|  l|  ;|   |        |
     *  |-----------------------------------------------------------|
     *  |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     *  `-----------------------------------------------------------´   */
    /*  NOTE: The Curl(DH) modder has a choice of swapping HM in this step or not. To do so, edit the lines below.      */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,  Q ,  W ,  J ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#elif   ACTIVELAYOUT == 2
    /*  Tarmak2 - Transitional Colemak (ET)
     *  ,-----------------------------------------------------------˛
     *  |     |  q|  w|  F|  r|  G|  y|  u|  i|  o|  p|   |   |     |
     *  |-----------------------------------------------------------|
     *  |      |  a|  s|  d|  T| *J|  h|  N|  E|  l|  ;|   |        |
     *  |-----------------------------------------------------------|
     *  |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     *  `-----------------------------------------------------------´   */
    /*  Tarmak2-Curl(DH) - Transitional Colemak-Curl-DH (ET)
     *  ,-----------------------------------------------------------˛
     *  |     |  q|  w|  F|  r|  B|  y|  u|  i|  o|  p|   |   |     |
     *  |-----------------------------------------------------------|
     *  |      |  a|  s|  d|  T|  g|  h|  N|  E|  l|  ;|   |        |
     *  |-----------------------------------------------------------|
     *  |    |  z|  x|  c| *J|  v|  _|  K|  m|   |   |   |          |
     *  `-----------------------------------------------------------´   */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if    CURLMOD == 1
    /*  Tarmak2-Curl(Dvbg only) - Transitional Colemak-DH (ET)          */
    TAB   ,  Q ,  W ,  F ,  R ,  B ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  T ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  J ,  V ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    TAB   ,  Q ,  W ,  F ,  R ,  G ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  T ,  J ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */

#elif   ACTIVELAYOUT == 3
    /*  Tarmak3 - Transitional Colemak (ETR)
     *  ,-----------------------------------------------------------˛
     *  |     |  q|  w|  F| *J|  G|  y|  u|  i|  o|  p|   |   |     |
     *  |-----------------------------------------------------------|
     *  |      |  a|  R|  S|  T|  D|  h|  N|  E|  l|  ;|   |        |
     *  |-----------------------------------------------------------|
     *  |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     *  `-----------------------------------------------------------´   */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if    CURLMOD == 1
    /*  Tarmak3-Curl(Dvbg) - Transitional Colemak-DH (ETR)              */
    TAB   ,  Q ,  W ,  F ,  J ,  B ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    TAB   ,  Q ,  W ,  F ,  J ,  G ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */

#elif   ACTIVELAYOUT == 4
    /*  Tarmak4 - Transitional Colemak (ETRO)
     *  ,-----------------------------------------------------------˛
     *  |     |  q|  w|  F|  P|  G|  J|  u|  i|  Y|  ;|   |   |     |
     *  |-----------------------------------------------------------|
     *  |      |  a|  R|  S|  T|  D|  h|  N|  E|  l|  O|   |        |
     *  |-----------------------------------------------------------|
     *  |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     *  `-----------------------------------------------------------´   */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if    CURLMOD == 1
    /*  Tarmak4-Curl(Dvbg) - Transitional Colemak-DH (ETRO)             */
    TAB   ,  Q ,  W ,  F ,  P ,  B ,  J ,  U ,  I ,  Y ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  H ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    TAB   ,  Q ,  W ,  F ,  P ,  G ,  J ,  U ,  I ,  Y ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */

#elif   ACTIVELAYOUT == 5
    /*  Colemak  */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if    CURLMOD == 1
    /*  Colemak-Curl(DH). Use with an Angle(Wide) ergo mod on row-staggered boards; see the INIT section and the BigBag.
     *  (Shown here with the ANSI Angle(Z) mod; keymap ANAXCDVZ selects this variant)
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  F|  P|  B|  J|  L|  U|  Y|  ;|  [|  ]|   \ |
     *  |-----------------------------------------------------------|
     *  |*BSpc*|  A|  R|  S|  T|  G|  M|  N|  E|  I|  O|  '|  Enter |
     *  |-----------------------------------------------------------|
     *  | Shift  |  X|  C|  D|  V|  Z|  K|  H|  ,|  .|  /|    Shift |
     *  `-----------------------------------------------------------´   */
    /*  Colemak-Curl(DH)Angle(Z)Wide(')-ANSI; use keymap AWAXCDVZ for this ergonomic variant
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  F|  P|  B|  [|  J|  L|  U|  Y|  ;|  '|   \ |
     *  |-----------------------------------------------------------|
     *  |*BSpc*|  A|  R|  S|  T|  G|  ]|  M|  N|  E|  I|  O|  Enter |
     *  |-----------------------------------------------------------|
     *  | Shift  |  X|  C|  D|  V|  Z|  /|  K|  H|  ,|  .|    Shift |
     *  `-----------------------------------------------------------´   */
    TAB   ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  M ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    /*  Standard Colemak (created by Shai Coleman, 2006)
     *  http://colemak.com
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  F|  P|  G|  J|  L|  U|  Y|  ;|  [|  ]|   \ |
     *  |-----------------------------------------------------------|
     *  |*BSpc*|  A|  R|  S|  T|  D|  H|  N|  E|  I|  O|  '|  Enter |
     *  |-----------------------------------------------------------|
     *  | Shift  |  Z|  X|  C|  V|  B|  K|  M|  ,|  .|  /|    Shift |
     *  `-----------------------------------------------------------´   */
    TAB   ,  Q ,  W ,  F ,  P ,  G ,  J ,  L ,  U ,  Y ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */

#elif   ACTIVELAYOUT == 6
    /*  Colemak mirrored (designed for one-handed typing using a layer switch) */
    /*  NOTE: Mirrored Colemak is normally used as the second layout (see below) with unmirrored Colemak as active.     */
    /*  Mirrored Colemak (used as switch layout for one-handed typing)
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
     *  `-----------------------------------------------------------´   */
    /*  NOTE: Set an accessible key in your active layout (e.g., LALT or RGUI) as a layer1 switch (see SLCKBEHAVIOR).   */
    [1] = UNIMAPLAYOUT(
    FBsl,    F12 ,F11 ,F10 , F9 ,    F8 , F7 , F6 , F5 ,    F4 , F3 , F2 , F1 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    BSPC,FMin,  0 ,  9 ,  8 ,  7 ,  6 ,  5 ,  4 ,  3 ,  2 ,  1 ,FEql,JYEN,GRV ,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if    CURLMOD == 1
    /*  Colemak-Curl(DHm). See above.                                   */
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  B ,  P ,  F ,  W ,  Q ,ESC ,FCap,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  M ,  G ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  H ,  K ,  V ,  D ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  G ,  P ,  F ,  W ,  Q ,ESC ,FCap,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  H ,  D ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  M ,  K ,  B ,  V ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */
// NOTE: Optionally, the bottom/modifier line may also be mirrored. Comment/uncomment the lines below for this.
//       If using such a modifier as your Mirror switch, beware: The layer switch key should be the same in both layers.
//  FRCt ,RGUI,FnRA,MHEN,         SPC          ,HENK,KANA,FnLA,LGUI,APP , LCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 

#elif   ACTIVELAYOUT == 7
    /*  Dvorak (outdated layout from 1936, but still in use)
     *  http://en.wikipedia.org/wiki/Dvorak_Simplified_Keyboard
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|   \ |
     *  |-----------------------------------------------------------|
     *  |*BSpc*|  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|  Enter |
     *  |-----------------------------------------------------------|
     *  | Shift  |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|    Shift |
     *  `-----------------------------------------------------------´   */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FLBr,FRBr,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,FQuo,COMM,DOT ,  P ,  Y ,  F ,  G ,  C ,  R ,  L ,FSls,FEql,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  O ,  E ,  U ,  I ,  D ,  H ,  T ,  N ,  S ,FMin,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,FScl,  Q ,  J ,  K ,  X ,  B ,  M ,  W ,  V ,  Z , RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#elif   ACTIVELAYOUT == 8
    /*  Canary (newer Colemak alternative from 2022; less implemented)
     *  https://github.com/Apsu/Canary
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  W|  L|  Y|  P|  K|  Z|  X|  O|  U|  ;|  [|  ]|   \ |
     *  |-----------------------------------------------------------|
     *  |*Caps*|  C|  R|  S|  T|  B|  F|  N|  E|  I|  A|  '|  Enter |
     *  |-----------------------------------------------------------|
     *  | Shift  |  Q|  J|  V|  D|  G|  M|  H|  /|  ,|  .|    Shift |
     *  `-----------------------------------------------------------´   */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,  W ,  L ,  Y ,  P ,  K ,  Z ,  X ,  O ,  U ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  C ,  R ,  S ,  T ,  B ,  F ,  N ,  E ,  I ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Q ,  J ,  V ,  D ,  G ,  M ,  H ,FSls,COMM,DOT , RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#elif   ACTIVELAYOUT == 9
    /*  Gralmak (newer variant of the popular Graphite layout from 2023)
     *  https://github.com/DreymaR/BigBagKbdTrixPKL/tree/master/Layouts/Graphite#gralmak
     *  NOTE: The Quote key belongs on the upper row. The Sym mod fixes that for me.
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  B|  L|  D|  W|  Q|  J|  F|  O|  U|  ;|  [|  ]|   \ |
     *  |-----------------------------------------------------------|
     *  |*Caps*|  N|  R|  T|  S|  G|  Y|  H|  A|  E|  I|  '|  Enter |
     *  |-----------------------------------------------------------|
     *  | Shift  |  Z|  X|  M|  C|  V|  K|  P|  ,|  .|  /|    Shift |
     *  `-----------------------------------------------------------´   */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,  B ,  L ,  D ,  W ,  Q ,  J ,  F ,  O ,  U ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  N ,  R ,  T ,  S ,  G ,  Y ,  H ,  A ,  E ,  I ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  M ,  C ,  V ,  K ,  P ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

    /* ******* Extra graphics of some layouts: ************************ */
    /*  Colemak-CurlAngleWide, adapted for Norwegian locale (DreymaR's ISO-Nor hack)
     *  http://forum.colemak.com/viewtopic.php?id=2158 (this describes the old Cmk-CAW hack; it's Cmk-CAWS now)
     *  US:  -_  ->  /?      ]}  ->  ;:  ->  -_  ->  \|  ->  '"      [{
     *  No:  +?  ->  -_      ¨^  ->  øØ  ->  <>  ->  '*  ->  æÆ      åÅ
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  \|  7|  8|  9|  0|  -|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  F|  P|  B|  Å|  J|  L|  U|  Y|  ¨|  +| Ent |
     *  |------------------------------------------------------`    |
     *  |*Ext1*|  A|  R|  S|  T|  G|  Æ|  K|  N|  E|  I|  O|  '|    |
     *  |-----------------------------------------------------------|
     *  |Shft|  Z|  X|  C|  D|  V|  Ø|  <|  M|  H|  ,|  .|    Shift |
     *  `-----------------------------------------------------------´   */
    /*  Colemak-CAW-ISO (standard/US symbols; the # key is \):
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  F|  P|  B|  [|  J|  L|  U|  Y|  ;|  /| Ent |
     *  |------------------------------------------------------`    |
     *  |*Ext1*|  A|  R|  S|  T|  G|  ]|  K|  N|  E|  I|  O|  '|    |
     *  |-----------------------------------------------------------|
     *  |Shft|  Z|  X|  C|  D|  V|  <|  #|  M|  H|  ,|  .|    Shift |
     *  `-----------------------------------------------------------´   */
    /*  Colemak-CAWS-ISO:
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  \|  7|  8|  9|  0|  =|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  F|  P|  B|  [|  J|  L|  U|  Y|  '|  -| Ent |
     *  |------------------------------------------------------`    |
     *  |*Ext1*|  A|  R|  S|  T|  G|  ]|  K|  N|  E|  I|  O|  ;|    |
     *  |-----------------------------------------------------------|
     *  |Shft|  Z|  X|  C|  D|  V|  <|  /|  M|  H|  ,|  .|    Shift |
     *  `-----------------------------------------------------------´   */
    /*  Colemak-CAWS adaptation for ISO-Nor (Nor symbols):
     *  ,-----------------------------------------------------------˛
     *  |  `|  1|  2|  3|  4|  5|  6|  \|  7|  8|  9|  0|  +|  BSpc |
     *  |-----------------------------------------------------------|
     *  | Tab |  Q|  W|  F|  P|  B|  Å|  J|  L|  U|  Y|  '|  -| Ent |
     *  |------------------------------------------------------`    |
     *  |*Ext1*|  A|  R|  S|  T|  G|  Æ|  K|  N|  E|  I|  O|  ¨|    |
     *  |-----------------------------------------------------------|
     *  |Shft|  Z|  X|  C|  D|  V|  <|  Ø|  M|  H|  ,|  .|    Shift |
     *  `-----------------------------------------------------------´   */

#endif      /* if ACTIVELAYOUT */
    /*  The bottom row is layout independent (but you may edit the keys here as desired)                                */
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),      /* *******    <-- Layer 0: Default Layout                     ******* */

/* *******  Layer 1: Second/Switch Layout (see below for replacing it with any layer0 layout or your own) -->   ******* */
#if     SECONDLAYOUT == 3
/*  NOTE: This is the special case of using Colemak(Curl-DH) as the first, and Mirrored Colemak as the second layout.   */
    /*  NOTE: Set an accessible key in your active layout (e.g., LALT or RGUI) as a layer1 switch (see SLCKBEHAVIOR).   */
    [1] = UNIMAPLAYOUT(
    FBsl,    F12 ,F11 ,F10 , F9 ,    F8 , F7 , F6 , F5 ,    F4 , F3 , F2 , F1 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    BSPC,FMin,  0 ,  9 ,  8 ,  7 ,  6 ,  5 ,  4 ,  3 ,  2 ,  1 ,FEql,JYEN,GRV ,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if    CURLMOD == 1
    /*  Colemak-Curl(DHm). See above.                                   */
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  B ,  P ,  F ,  W ,  Q ,ESC ,FCap,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  M ,  G ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  H ,  K ,  V ,  D ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  G ,  P ,  F ,  W ,  Q ,ESC ,FCap,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  H ,  D ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  M ,  K ,  B ,  V ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */
// NOTE: Optionally, the bottom/modifier line may also be mirrored. Comment/uncomment the lines below for this.
//       If using such a modifier as your Mirror switch, beware: The layer switch key should be the same in both layers.
//  FRCt ,RGUI,FnRA,MHEN,         SPC          ,HENK,KANA,FnLA,LGUI,APP , LCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
#else
/* Set SECONDLAYOUT to 1 for QWERTY or 2 for Colemak/custom as switch layout; otherwise it'll be unmodded QWERTY        */
# if    SECONDLAYOUT == 1
    /*  QWERTY – as above                                               */
    [1] = UNIMAPLAYOUT(
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif  SECONDLAYOUT == 2
/* --> REPLACE THE SECOND LAYOUT BETWEEN THESE LINES IF DESIRED - taking care to include all necessary lines once!      */
    /*  Colemak - as above                                              */
    [1] = UNIMAPLAYOUT(
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,FEql,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
#  if   CURLMOD == 1
    /*  Colemak-Curl(DHm). Use w/ CurlAngle or CurlAngleWide ergo mod!  */
    TAB   ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  M ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  else
    /*  Standard Colemak                                                */
    TAB   ,  Q ,  W ,  F ,  P ,  G ,  J ,  L ,  U ,  Y ,FScl,FLBr,FRBr,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  endif    /* * * if CURLMOD */
/* <-- REPLACE THE SECOND LAYOUT BETWEEN THESE LINES IF DESIRED                                                         */
# else
    /*  Plain QWERTY - without CurlAngleWide nor ISO adaptations, to reflect the key caps of a standard keyboard.       */
    [1] = UNIMAP_NOMODS(
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,NUBS,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,SLSH, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if SECONDLAYOUT */
    LCTL ,LGUI,LALT,MHEN,         SPC          ,HENK,KANA,RALT,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
#endif      /* if Colemak-Mirrored */
    ),      /* *******    <-- Layer 1: Second/Switch Layout               ******* */

#if     CAPSBEHAVIOR == 1
/*  Layer 2: Extend1 (DreymaR)                                                  */
/*  ,----˛    ,-------------------˛ ,-------------------˛ ,-------------------˛
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
 *  `-------------------------------------------------------------------------´ */
/*            ACL0,ACL1,ACL2,BTN4,BTN5, NO , NO ,WAKE, NO , NO , NO , NO ,      */
/*  NOTE: For Mirrored Colemak, please tweak this layer to suit your needs.     */
    [2] = UNIMAPLAYOUT(
    CAPS,    MPLY,MPRV,MNXT,MSTP,   MUTE,VOLD,VOLU,MSEL,   WHOM,WSCH,MYCM,CALC,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    FnU1, F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,JYEN,PAUS,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,ESC ,WH_U,WBAK,WFWD,MS_U,PGUP,HOME, UP ,END ,DEL ,ESC ,INS ,   APP ,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,LALT,WH_D,LSFT,LCTL,MS_D,PGDN,LEFT,DOWN,RGHT,BSPC,APP ,WFAV,  PSCR,                      P4 , P5 , P6 ,PCMM,
# if   CURLMOD == 1     /* Swap the V and B/D keys for Curl-DH  */
    FLSh ,WH_L,c(Z),c(X),c(C),BTN1,c(V),BTN2,BTN3,MS_L,MS_R,WH_R, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else                  /* Normal ZXCVB lower row               */
    FLSh ,WH_L,c(Z),c(X),c(C),c(V),BTN1,BTN2,BTN3,MS_L,MS_R,WH_R, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */
    LCTL ,LGUI,FnLA,MHEN,         ENT          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),      /* <-- Extend1 */

/*  Layer 3: Extend2 (DreymaR)                                                  */
/*  ,----˛    ,-------------------˛ ,-------------------˛ ,-------------------˛
 *  |    |    |MPau|MRwd|MFFd|Ejct| |WRef|BriD|BriU|Slep| |www |Mail|App3|App4|
 *  `----´    `-------------------´ `-------------------´ `-------------------´
 *  ,-------------------------------------------------------------------------˛
 *  | ?? | !  | @  | #  | $  | %  | ^  | P7 | P8 | P9 | P- | P* | =  |        |
 *  |-------------------------------------------------------------------------|
 *  |      |Home| Up |End |Del |Esc |PgUp| P4 | P5 | P6 | P+ | (  | )  |      |
 *  |-------------------------------------------------------------------------|
 *  |*Ext2* |Left|Down|Rght|BSpc|NLck|PgDn| P1 | P2 | P3 |PEnt| '  | ,  |     |
 *  |-------------------------------------------------------------------------|
 *  |     |    | ^Z | ^X | ^C | ^V |Btn1| :  | P0 | P0 | P. | P/ |       Ext2 |
 *  |-------------------------------------------------------------------------|
 *  |      |     |     |                             |     |     |     | Ext3 |
 *  `-------------------------------------------------------------------------´ */
    [3] = UNIMAPLAYOUT(
    CAPS,    MPLY,MRWD,MFFD,EJCT,   WREF, NO , NO ,SLEP,   WSTP,MAIL,MYCM,CALC,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    FnU2,s(1),s(2),s(3),s(4),s(5),s(6), P7 , P8 , P9 ,PMNS,PAST,TRNS,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,HOME, UP ,END ,DEL ,ESC ,PGUP, P4 , P5 , P6 ,PPLS,FsLP,FsRP,   FBsl,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,LEFT,DOWN,RGHT,BSPC,NLCK,PGDN, P1 , P2 , P3 ,PENT,FQuo,COMM,  ENT ,                      P4 , P5 , P6 ,PCMM,
# if   CURLMOD == 1     /* Swap the V and B/D keys for Curl-DH  */
    FLSh ,TRNS,c(Z),c(X),c(C),BTN1,c(V),FsSC, P0 , P0 ,PDOT,PSLS, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else                  /* Normal ZXCVB lower row               */
    FLSh ,TRNS,c(Z),c(X),c(C),c(V),BTN1,FsSC, P0 , P0 ,PDOT,PSLS, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif     /* * if CURLMOD */
    LCTL ,LGUI,FnLA,MHEN,         TRNS         ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),      /* <-- Extend2 */

#endif      /* if CAPSBEHAVIOR */
};    /* *******    <-- Keymap layer definitions                        ******* */

/* ***** FUNCTIONS/MACROS ********************************************************************************************* */

/* *******  User function and macro definitions -->                     ******* */

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    /*  Base keycode and 4-digit Windows input codes for several glyphs, for use with 4-level ISO adaptation            */
    static const uint8_t KeyDict[4][2][5] =                 {       /*  [key#][shifted][codes]      */
        {{ KC_LBRC, KC_P0  , KC_P2  , KC_P2  , KC_P9   },           /*  å on Win is Alt+KP(0229)    */
         {       0, KC_P0  , KC_P1  , KC_P9  , KC_P7   }}   ,       /*  Å on Win is Alt+KP(0197)    */
        {{ KC_RBRC, KC_P0  , KC_P2  , KC_P3  , KC_P0   },           /*  æ on Win is Alt+KP(0230)    */
         {       0, KC_P0  , KC_P1  , KC_P9  , KC_P8   }}   ,       /*  Æ on Win is Alt+KP(0198)    */
        {{ KC_NUBS, KC_P0  , KC_P2  , KC_P4  , KC_P8   },           /*  ø on Win is Alt+KP(0248)    */
         {       0, KC_P0  , KC_P2  , KC_P1  , KC_P6   }}   ,       /*  Ø on Win is Alt+KP(0216)    */
        {{ KC_NUHS, KC_P0  , KC_P1  , KC_P4  , KC_P9   },           /*  • on Win is Alt+KP(0149)    */
         {       0, KC_P0  , KC_P1  , KC_P3  , KC_P4   }}   };      /*  † on Win is Alt+KP(0134)    */
    
    uint8_t rmods = get_mods(); // uint8_t wmods = get_weak_mods();
    
    switch (id) {
    case FOURLVLU:  /* Four-level keys, producing OS specific Unicode input with AltGr/RAlt held down                   */
        if  (record->event.pressed) {
            /*  NOTE: Removing the RAlt mod to avoid menu activation means you must re-press RAlt for another go.       */
            /*  NOTE: To save data memory, only real mods are considered. This seems enough for me.                     */
            if ( rmods & MOD_BIT(KC_RALT) ) {                       /*  - If AltGr is pressed:      */
                uint8_t shftd = ( rmods & ( MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT) ) ) ? 1 : 0;
                clear_mods();                                       /*    Temporarily remove mods,  */
                UNICODEHEADER                                       /*    OS specific start,        */
                send_keyboard_report();
                for ( uint8_t i = 1; i < 5; i++ ) {                 /*    Send the 4-digit code,    */
                    type_code( KeyDict[opt][shftd][i] );
                }
                UNICODEFOOTER                                       /*    OS specific finish,       */
                set_mods( rmods & ~MOD_BIT(KC_RALT) );              /*    Restore mods (mostly).    */
            } else {                                                /*  - If AltGr isn't pressed:   */
                type_code( KeyDict[opt][0][0] );                    /*    Send the base key.        */
            }
            send_keyboard_report();
//      } else {                            /*  No need to do anything if our key wasn't pressed.   */
        }
        break;
    case EXTENDER:  /* Multi-Extend modifier, switching to different Extend layers depending on mod state.              */
        if (record->event.pressed) {
            rmods &= ( EXT2BIT | EXT3BIT );                         /*  - Ignore any other mods.    */
            switch ( rmods ) {
            case ( EXT2BIT | EXT3BIT )                          :   /*  - If Ext2+Ext3 are pressed: */
                /*  TODO: Select Extend4 (not implemented yet)      */
            break;
            case ( EXT3BIT )                                    :   /*  - If Ext3 is pressed:       */
                /*  TODO: Select Extend3 (not implemented yet)      */
            break;
            case ( EXT2BIT )                                    :   /*  - If Ext2 is pressed:       */
                layer_on(3);                                        /*    Select Extend2 (layer3)   */
            break;
            default                                             :   /*  - If no Alt is pressed:     */
                layer_on(2);                                        /*    Select Extend1 (layer2)   */
            ;}
        } else {                                                    /*  - If Extend is released:    */
            layer_and(1);                                           /*    Revert to layer 0/1       */
            clear_mods(); clear_weak_mods();                        /*    Release any stuck mods    */
            send_keyboard_report();
        }
        break;
    }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
    case TYPESTR1:
        /*  Type a string (standard email footer) then select the name line.                        */
        return (record->event.pressed ?
            MACRO( I(0), 
                T(ENT), T(ENT), ST(M), T(V), T(H), T(COMM), T(ENT), 
                UNIW_(0,2,1,6), T(Y), T(S), T(T), T(E), T(I), T(N), T(ENT), T(ENT),     /*  Name    */
                SFT_( T(I), T(K), T(K), T(E), T(SPC), 
                    T(S), T(E), T(N), T(S), T(I), T(T), T(I), T(V), T(T) ), 
                T(ENT), T(UP), T(UP), T(UP), T(END), ST(HOME), 
                END ) :
            MACRO_NONE );
    case TYPESTR2:
        /*  Type a string (a smiley; it'll be layout dependent so find one that works for you!).    */
        return (record->event.pressed ?
            MACRO( I(0), 
                T(SPC), ST(SCLN), T(MINS), ST(0), T(ENT),
                END ) :
            MACRO_NONE );
    }
    return MACRO_NONE;
}   /* *******     <-- User function and macro definitions             ******* */
