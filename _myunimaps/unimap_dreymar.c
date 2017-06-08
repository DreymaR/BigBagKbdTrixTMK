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
 * 2016- Øystein "DreymaR" Gadmar: Colemak, Curl/Angle/Wide and Extend layouts
 * See the Colemak Forum (DreymaR's Big Bag of Keyboard Tricks) for info
 * http://forum.colemak.com/viewtopic.php?id=2158
 * 
 * Compiler preprocessor definitions select layout and Extend layers:
 * - ACTIVELAYOUT # selects first/active layout (QWERTY, Colemak etc)
 * - SECONDLAYOUT # selects second/switch layout (QWERTY, Colemak, Colemak-mirrored etc)
 * - CURLMOD      # activates the Curl(DH) ergo mod; only affects Colemak/Tarmak layouts
 * - EXTENDMODE   # selects Extend mappings (navigation layer, NumPad layer etc)
 * - CAPSBEHAVIOR # selects CapsLock key behavior if Extend is off (Caps, BckSpc, LCtrl, Esc)
 * - etc            (see below for more)
 * 
 * For the Angle/Wide ergo mods, I couldn't use #define to replace the keymap before parsing the resulting macro
 * Instead, manually search/replace the text UNIMAP_AWIZXCBV globally before compiling this file; see below
 */

/* ***** SETTINGS *************************************************************************************************** */

/* Search/replace 'UNIMAP_AWIZXCBV' (CurlAngleWide-ISO) in this file to choose ergonomic Curl/Angle/Wide keyboard mods:
 * _MINIMALL - Default unimap format for all keyboard and converter types (w/o F13-24; this one is unmodded)
 * _ANIZXCVB (w/ Curl-DH: _ANIZXCBV) - ISO/Int Angle ergo mod (the simple ZXCVB_ half-row shift)
 * _AWIZXCVB (w/ Curl-DH: _AWIZXCBV) - ISO/Int Angle-Wide(/) ergo mod
 * _ANAXCVBZ (w/ Curl-DH: _ANAXCBVZ) - ANSI/US Angle(Z) ergo mod
 * _AWAXCVBZ (w/ Curl-DH: _AWAXCBVZ) - ANSI/US Angle(Z)-Wide(') ergo mod
 * _ANAAWING (w/ Curl-DH: N/A)       - ANSI/US A-Wing ergo mod
 *
 * NOTE: Select a Curl(DH) or non-Curl ergo model, or plain MINIMALL. For Curl(DH), you also need to set CURLMOD.
 */

/* Define the ACTIVELAYOUT (and CURLMOD) constant(s) to choose the layer0 layout:
 * 0  : QWERTY
 * 1-#: Tarmak1 - transitional Colemak (supports CURLMOD; see below)
 * 2-#: Tarmak2 - transitional Colemak (--"--)
 * 3-#: Tarmak3 - transitional Colemak (--"--)
 * 4-#: Tarmak4 - transitional Colemak (--"--)
 * 5-0: Colemak
 * 5-1: Colemak Curl-DH (requires a CurlAngle keymap; see above)
 * 8  : Dvorak
 * 9  : Workman (if you must - I believe Colemak Curl-DH is a lot better!)
 */
#define ACTIVELAYOUT 5

/* Define the SECONDLAYOUT (and CURLMOD) constant(s) to choose the layer1 switch layout:
 * 0  : Unmodded QWERTY is the default; otherwise:
 * 1  : QWERTY with any ergo mods (AngleWide etc)
 * 2-#: Colemak (if you want something else, replace it in the code between the 'REPLACE THE SECOND LAYOUT...' lines)
 * 3-#: Colemak Mirrored as second layout for one-handed typing (needs an accessible switch key!)
 *      NOTE: The "FPau" key is a layer1 toggle or switch (edit it below), normally used on the Pause key.
 *            You may replace, e.g., the LAlt/"FnLA" or RWin/"RGUI" key with "FPau" in your active layout.
 */
#define SECONDLAYOUT 0

/* The CURLMOD options for Colemak and Tarmak layouts are:
 * 0: No Curl - vanilla Colemak/Tarmak
 * 1: The Curl(DH) ergo mod, bringing the D and H keys down to comfortable bottom-row positions (QWERTY C/M)
 * 2: SteveP99's old Curl(DHm or DvbgHm) ergo mod, bringing D/H down but M to the home row.
 *    Some matrix board users may prefer this mod, but several prefer the default even on matrix boards.
 * N/A: DreymaR's old Curl(DbgHk) mod, bringing DH "down-and-out" to the QWERTY V/N keys (edit the layouts for this)
 *
 * NOTE: On the first Tarmak step, CURLMOD 1 will include the HMK swaps whereas CURLMOD 2 won't. So you can choose.
 *       For a baby Tarmak1 step, use CURLMOD 2 and then 1. The K will be misplaced at first, but it's rare.
 *       (For the other steps, CURLMOD 2 still doesn't move HM so Curl(DHm) users generally do HM in the last step.)
 * NOTE: Another baby step after Tarmak1 could be transitioning to a CurlAngle(Wide) keymap model before Tarmak2.
 * NOTE: You could use a non-Curl UNIMAP_# for a Curl(DH) mod, to keep ZXCV together as in my old Curl(DbgHk) mod.
 *       To get my complete old Curl mod though, you would have to swap H/M manually in this file for your layout(s).
 */
#define CURLMOD 1

/* The EXTENDMODE constant activates the powerful Extend layers:
 * 0: No Extend (saves a little memory)
 * 1: Ext1 on Caps    : Navigation/editing/multimedia
 * 2: Ext1 on LAlt      (Caps used as LAlt instead)
 * 3: Ext1 on RAlt      (Caps used as RAlt instead)
 * *: Ext2 on Tab     : NumPad/Navigation [NOTE: For now, the Ext2 modifier is Tab but it "should" be Alt+Caps]
 * NOTE: Depending on your keyboard's scan matrix(?), chorded Extend modifiers such as Ext1+S+T+N for Shift+Ctrl+Left
 *       may not work. With Caps=Ext1, I've had trouble with Ext1+S+T+N; with LAlt=Ext1 even Ext1+S+N didn't work!
 */
#define EXTENDMODE 1

/* The CAPSBEHAVIOR constant chooses Caps key action if EXTENDMODE is 0:
 * 0: CapsLock (default)
 * 1: BackSpace (for Colemak or otherwise)
 * 2: LCtrl
 * 3: Esc
 */
#define CAPSBEHAVIOR 1

/* The STICKYMODS constant chooses LShift, RShift and RCtrl key behavior (I chose to leave LCtrl alone):
 * 0: Normal Shift/Ctrl (default)
 * 1: Sticky Shift only
 * 2: Sticky Ctrl only
 * 3: Sticky Shift & Ctrl
 * NOTE: In the unimap_dreymar.h file, some relevant constants normally set in config.h are (re)set:
 *       - TAPPING_TERM is the max time a key may be held down for it to register as tapped
 *       - ONESHOT_TIMEOUT is the max delay before a oneshot modifier is ignored
 */
#define STICKYMODS 1

/* The SCLKBEHAVIOR constant chooses ScrollLock key action:
 * 0: Normal ScrollLock (default)
 * 1: Layer 1 toggle key (toggles the second layout)
 * 2: Layer 1 switch key (layer shift; e.g., for mirrored typing if you can use it as ghetto foot switch)
 */
#define SLCKBEHAVIOR 1

/* The PAUSBEHAVIOR constant chooses Pause/Break key action:
 * 0: Normal Pause/Break (default)
 * 1: Win/GUI key (useful for 101/104-key boards that have no GUI key)
 */
#define PAUSBEHAVIOR 0

/* The DREYMARHACK constant chooses DreymaR's adaptations for Norwegian locale (ISO/Nor hack):
 * 0  : Normal behavior is the default
 * 1  : DreymaR's ISO/Nor hack active, swapping some keys around to make it more like the US/[eD] layout
 *
 * Keys swapped by the hack, with their Fn aliases in this file shown below:
 *      -   <>  /       ]   ->  ;   ->  <   ->  #   ->  '   ->  ]  
 *     MINS <> SLSH    RBRC -> SCLN -> NUBS -> NUHS -> QUOT
 *     FMin    FSls    FRbr    FScl    FLgt    FHsh    FQuo
 */
#define DREYMARHACK 0

/* Define the keymap type used in the header file (affects includes, map array format and Fn key definitions):
 * UNIMAP (new universal 128-key format w/o the Korean and rare rightmost keys)
 * KEYMAP_ALL (or similar keymaps); NOTE: For this to work, you must use my now outdated keymap_dreymar_old files!
 */
#define USEUNIMAP
#ifdef USEUNIMAP
# include "unimap_trans.h"
# include "unimap_dreymar.h"
#else
# include "keymap_common.h"
# include "keymap_dreymar_old.h"
#endif /* ifdef USEUNIMAP */

/* DreymaR's master key! Define it for a quick override. It gets compiler warnings due to redefinition; ignore these. */
//#define DREYMASTERKEY
#ifdef DREYMASTERKEY
# define ACTIVELAYOUT 5
# define SECONDLAYOUT 0
# define CURLMOD 1
# define EXTENDMODE 1
# define CAPSBEHAVIOR 1
# define STICKYMODS 1
# define SLCKBEHAVIOR 1
# define PAUSBEHAVIOR 0
# define DREYMARHACK 1
#endif /* ifdef DREYMASTERKEY */

/* TODO for DreymaR:
 * - Make the advanced LAlt/RAlt/Caps Extend modifiers work as planned
 * - One or two more Extend layers?
 * - Turn the ScrollLock LED on when the second layout is active?
 */

/* ***** DECLARATIONS *********************************************************************************************** */

/* User function and macro declarations --> */
enum macro_id {
    TYPESTR1,
    TYPESTR2,
};    /* <-- User function and macro declarations */

/* Fn action key definitions (Unimap style) --> */
// NOTE: Current FTab/FnLA/FnRA behavior is only until I get the fancy way of selecting Extend2-4 to work (I hope?!).
#if EXTENDMODE == 1
# define AC_FCap ACTION_LAYER_MOMENTARY(2)           // FCap selects Extend1 (gets priority over CAPSBEHAVIOR)
# define AC_FnLA ACTION_KEY(KC_LALT)                 // FnLA (LAlt key) unchanged
# define AC_FnRA ACTION_KEY(KC_RALT)                 // FnRA (RAlt key) unchanged
# define AC_FTab ACTION_LAYER_TAP_KEY(3, KC_TAB)     // FTab (Tab key)  selects Ext2 – tap for Tab (for now)
#elif EXTENDMODE == 2
# define AC_FCap ACTION_KEY(KC_LALT)                 // FCap as LAlt (gets priority over CAPSBEHAVIOR)
# define AC_FnLA ACTION_LAYER_MOMENTARY(2)           // FnLA selects Extend1
# define AC_FnRA ACTION_KEY(KC_RALT)                 // FnRA (RAlt key) unchanged
# define AC_FTab ACTION_LAYER_TAP_KEY(3, KC_TAB)     // FTab (Tab key)  selects Ext2 – tap for Tab (for now)
#elif EXTENDMODE == 3
# define AC_FCap ACTION_KEY(KC_RALT)                 // FCap as RAlt (gets priority over CAPSBEHAVIOR)
# define AC_FnLA ACTION_KEY(KC_LALT)                 // FnLA (LAlt key) unchanged
# define AC_FnRA ACTION_LAYER_MOMENTARY(2)           // FnRA selects Extend1
# define AC_FTab ACTION_LAYER_TAP_KEY(3, KC_TAB)     // FTab (Tab key)  selects Ext2 – tap for Tab (for now)
#else
# if CAPSBEHAVIOR == 1
#  define AC_FCap ACTION_KEY(KC_BSPC)                // FCap (Caps key) as BackSpace (for Colemak etc)
# elif CAPSBEHAVIOR == 2
#  define AC_FCap ACTION_KEY(KC_LCTL)                // FCap (Caps key) as LeftCtrl
# elif CAPSBEHAVIOR == 3
#  define AC_FCap ACTION_KEY(KC_ESC)                 // FCap (Caps key) as Esc
# else
#  define AC_FCap ACTION_KEY(KC_CAPS)                // FCap (Caps key) unchanged
# endif /* if CAPSBEHAVIOR */
# define AC_FnLA ACTION_KEY(KC_LALT)                 // FnLA (LAlt key) unchanged
# define AC_FnRA ACTION_KEY(KC_RALT)                 // FnRA (RAlt key) unchanged
# define AC_FTab ACTION_KEY(KC_TAB)                  // FTab (Tab key)  unchanged
#endif /* if EXTENDMODE */

#if EXTENDMODE > 0
//# define AC_FnE2 ACTION_LAYER_MOMENTARY(3)           // FnE2 selects Extend2 layer (TODO)
//# define AC_FnE3 ACTION_LAYER_MOMENTARY(4)           // FnE3 selects Extend3 layer (TODO)
//# define AC_FnE4 ACTION_LAYER_MOMENTARY(5)           // FnE4 selects Extend4 layer (TODO)
//# define AC_FnLA ACTION_LAYER_MOMENTARY(6)           // FnLA selects a temp-select layer for Extend2 (TODO)
//# define AC_FnRA ACTION_LAYER_MOMENTARY(7)           // FnRA selects a temp-select layer for Extend3 (TODO)
//# define AC_FnBA ACTION_LAYER_MOMENTARY(8)           // FnBA selects a temp-select layer for Extend4 (TODO)
//# define AC_FnU1 ACTION_MODS_KEY(MOD_LGUI,KC_T)      // FnU1 (`) as Win+T
# define AC_FnU1 ACTION_MACRO(TYPESTR1)              // FnU1 as user macro: Type a string
# define AC_FnU2 ACTION_MACRO(TYPESTR2)              // FnU2 as user macro: Type a string
#endif /* if EXTENDMODE > 0 */

#if STICKYMODS == 1
# define AC_FLSh ACTION_MODS_ONESHOT(MOD_LSFT)       // FLSh (Left Shift key)  as sticky shift
# define AC_FRSh ACTION_MODS_ONESHOT(MOD_RSFT)       // FRSh (Right Shift key) as sticky shift
# define AC_FRCt ACTION_KEY(KC_RCTL)                 // FRCt (Right Ctrl key)  unchanged
#elif STICKYMODS == 2
# define AC_FLSh ACTION_KEY(KC_LSFT)                 // FLSh (Left Shift key)  unchanged
# define AC_FRSh ACTION_KEY(KC_RSFT)                 // FRSh (Right Shift key) unchanged
# define AC_FRCt ACTION_MODS_ONESHOT(MOD_RCTL)       // FRCt (Right Ctrl key)  as sticky control
#elif STICKYMODS == 3
# define AC_FLSh ACTION_MODS_ONESHOT(MOD_LSFT)       // FLSh (Left Shift key)  as sticky shift
# define AC_FRSh ACTION_MODS_ONESHOT(MOD_RSFT)       // FRSh (Right Shift key) as sticky shift
# define AC_FRCt ACTION_MODS_ONESHOT(MOD_RCTL)       // FRCt (Right Ctrl key)  as sticky control
#else
# define AC_FLSh ACTION_KEY(KC_LSFT)                 // FLSh (Left Shift key)  unchanged
# define AC_FRSh ACTION_KEY(KC_RSFT)                 // FRSh (Right Shift key) unchanged
# define AC_FRCt ACTION_KEY(KC_RCTL)                 // FRCt (Right Ctrl key)  unchanged
#endif /* if STICKYMODS */

#if SLCKBEHAVIOR == 1
# define AC_FSLk ACTION_LAYER_TOGGLE(1)              // FSLk as layer1 toggle
#elif SLCKBEHAVIOR == 2
# define AC_FSLk ACTION_LAYER_MOMENTARY(1)           // FSLk as layer1 switch (e.g., for mirrored typing)
#else
# define AC_FSLk ACTION_KEY(KC_SLCK)                 // FSLk (ScrollLock key) unchanged
#endif /* if SLCKBEHAVIOR */

#if PAUSBEHAVIOR == 1
# define AC_FPau ACTION_KEY(KC_LGUI)                 // Fpau as GUI/Win (for 101/104-key boards)
#else
# define AC_FPau ACTION_KEY(KC_PAUS)                 // FPau (Pause/Break key) unchanged
#endif /* if PAUSBEHAVIOR */

#if DREYMARHACK == 1
/*    Adaptations for Nor/etc locale (DreymaR's ISO/Nor hack):
 *    MINS <> SLSH    RBRC -> SCLN -> NUBS -> NUHS -> QUOT
 *    FMin    FSls    FRbr    FScl    FLgt    FHsh    FQuo    */
# define AC_FMin ACTION_KEY(KC_SLSH)                 // FMin (MINS key) as SLSH (ISO/Nor hack)
# define AC_FSls ACTION_KEY(KC_MINS)                 // FSls (SLSH key) as MINS (ISO/Nor hack)
# define AC_FRbr ACTION_KEY(KC_QUOT)                 // FRbr (RBRC key) as QUOT (ISO/Nor hack)
# define AC_FScl ACTION_KEY(KC_RBRC)                 // FScl (SCLN key) as RBRC (ISO/Nor hack)
# define AC_FLgt ACTION_KEY(KC_SCLN)                 // FLgt (NUBS key) as SCLN (ISO/Nor hack)
# define AC_FHsh ACTION_KEY(KC_NUBS)                 // FHsh (NUHS key) as NUBS (ISO/Nor hack)
# define AC_FQuo ACTION_KEY(KC_NUHS)                 // FQuo (QUOT key) as NUHS (ISO/Nor hack)
# define AC_FSh9 ACTION_MODS_KEY(MOD_LSFT, KC_8)     // FSh9 is Shift+8 (left parenthesis, Nor)
# define AC_FSh0 ACTION_MODS_KEY(MOD_LSFT, KC_9)     // FSh0 is Shift+9 (right parenthesis, Nor)
# define AC_FSSC ACTION_MODS_KEY(MOD_LSFT, KC_DOT)   // FSSC is Shift+Period (colon, Nor)
#else
# define AC_FMin ACTION_KEY(KC_MINS)                 // FMin (MINS key) unchanged
# define AC_FSls ACTION_KEY(KC_SLSH)                 // FSls (SLSH key) unchanged
# define AC_FRbr ACTION_KEY(KC_RBRC)                 // FRbr (RBRC key) unchanged
# define AC_FScl ACTION_KEY(KC_SCLN)                 // FScl (SCLN key) unchanged
# define AC_FLgt ACTION_KEY(KC_NUBS)                 // FLgt (NUBS key) unchanged
# define AC_FHsh ACTION_KEY(KC_NUHS)                 // FHsh (NUHS key) unchanged
# define AC_FQuo ACTION_KEY(KC_QUOT)                 // FQuo (QUOT key) unchanged
# define AC_FSh9 ACTION_MODS_KEY(MOD_LSFT, KC_9)     // FSh9 is Shift+9 (left parenthesis)
# define AC_FSh0 ACTION_MODS_KEY(MOD_LSFT, KC_0)     // FSh0 is Shift+0 (right parenthesis)
# define AC_FSSC ACTION_MODS_KEY(MOD_LSFT, KC_SCLN)  // FSSC is Shift+Semicolon (colon, US)
#endif /* if DREYMARHACK */
    /* <-- Fn action key definitions (Unimap style) */

/* ***** LAYOUTS **************************************************************************************************** */

/* Keymap layer definitions (mini Unimap style in this file) --> */
#ifdef USEUNIMAP
# ifdef KEYMAP_SECTION_ENABLE
  const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
# else
  const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
# endif
#else
  const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif /* if USEUNIMAP */

    /* Layer 0: Default Layout --> */
    [0] = UNIMAP_AWIZXCBV(
    /* Layout independent top row(s) - except for mirrored Colemak (layout #6) which moves the F# key row */
#if ACTIVELAYOUT == 6
#else
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
#endif /* if ACTIVELAYOUT == 6 */

#if ACTIVELAYOUT == 0
    /* Plain QWERTY (shown on a full _UNIMAP_D layout without the top F13-24 row)
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.     ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |VDn|VUp|Mut|
     * `---'   `---------------' `---------------' `---------------' `-----------'     `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|BSp| |Ins|Hom|PgU| |NLk|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
     * |-----------------------------------------------------------| `-----------' |---------------|
     * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |               |  4|  5|  6|  ,|
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO| Shft |     |Up |     |  1|  2|  3|Ent|
     * |-----------------------------------------------------------| ,-----------. |---------------|
     * |Ctrl|Gui|Alt|MHEN|     Space     |HENK|KANA|Alt|Gui|App|Ctl| |Lft|Dwn|Rgh| |      0|  .|  =|
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
    /* QWERTY-Angle(Z)Wide(') for ANSI boards; use keymap AWAXCVBZ for this ergonomic variant (see the INIT section)
     * http://forum.colemak.com/viewtopic.php?id=1438
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  [|  Y|  U|  I|  O|  P|  '|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  S|  D|  F|  G|  ]|  H|  J|  K|  L|  ;|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  X|  C|  V|  B|  Z|  /|  N|  M|  ,|  .|    Shift |
     * |-----------------------------------------------------------|
     * |Ctrl |Gui |Alt |         Space        |Alt |Gui |Menu| Ctrl|
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#elif ACTIVELAYOUT == 1
    /* Tarmak1 - Transitional Colemak (E)
     * http://forum.colemak.com/viewtopic.php?id=1858
     * ,-----------------------------------------------------------.
     * |     |  q|  w| *J|  r|  t|  y|  u|  i|  o|  p|   |   |     |
     * |-----------------------------------------------------------|
     * |      |  a|  s|  d|  f|  g|  h|  N|  E|  l|  ;|   |        |
     * |-----------------------------------------------------------|
     * |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     * `-----------------------------------------------------------'     */
    /* NOTE: The Curl(DH) modder has a choice of swapping HMK in this step or not. Set CURLMOD 1/2 for yes/no.        */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Tarmak1-Curl(Hmk) - Transitional Colemak-Curl (E)                 */
    FTab  ,  Q ,  W ,  J ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  K ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  M ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    FTab  ,  Q ,  W ,  J ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */

#elif ACTIVELAYOUT == 2
    /* Tarmak2 - Transitional Colemak (ET)
     * http://forum.colemak.com/viewtopic.php?id=1858
     * ,-----------------------------------------------------------.
     * |     |  q|  w|  F|  r|  G|  y|  u|  i|  o|  p|   |   |     |
     * |-----------------------------------------------------------|
     * |      |  a|  s|  d|  T| *J|  h|  N|  E|  l|  ;|   |        |
     * |-----------------------------------------------------------|
     * |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     * `-----------------------------------------------------------'     */
    /* Tarmak2-Curl(DH) - Transitional Colemak-Curl-DH (ET)
     * ,-----------------------------------------------------------.
     * |     |  q|  w|  F|  r|  B|  y|  u|  i|  o|  p|   |   |     |
     * |-----------------------------------------------------------|
     * |      |  a|  s|  d|  T|  g|  K|  N|  E|  l|  ;|   |        |
     * |-----------------------------------------------------------|
     * |    |  z|  x|  c| *J|  v|  _|  M|  H|   |   |   |          |
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Tarmak2-Curl(DH) - Transitional Colemak-Curl (ET)                 */
    FTab  ,  Q ,  W ,  F ,  R ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  T ,  G ,  K ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  J ,  M ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Tarmak2-Curl(Dvbg only) - Transitional Colemak-Curl (ET)          */
    FTab  ,  Q ,  W ,  F ,  R ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  T ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  J ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    FTab  ,  Q ,  W ,  F ,  R ,  G ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  T ,  J ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */

#elif ACTIVELAYOUT == 3
    /* Tarmak3 - Transitional Colemak (ETR)
     * http://forum.colemak.com/viewtopic.php?id=1858
     * ,-----------------------------------------------------------.
     * |     |  q|  w|  F| *J|  G|  y|  u|  i|  o|  p|   |   |     |
     * |-----------------------------------------------------------|
     * |      |  a|  R|  S|  T|  D|  h|  N|  E|  l|  ;|   |        |
     * |-----------------------------------------------------------|
     * |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Tarmak3-Curl(DH) - Transitional Colemak-Curl (ETR)                */
    FTab  ,  Q ,  W ,  F ,  J ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  M ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Tarmak3-Curl(Dvbg) - Transitional Colemak-Curl (ETR)              */
    FTab  ,  Q ,  W ,  F ,  J ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    FTab  ,  Q ,  W ,  F ,  J ,  G ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */

#elif ACTIVELAYOUT == 4
    /* Tarmak4 - Transitional Colemak (ETRO)
     * http://forum.colemak.com/viewtopic.php?id=1858
     * ,-----------------------------------------------------------.
     * |     |  q|  w|  F|  P|  G|  J|  u|  i|  Y|  ;|   |   |     |
     * |-----------------------------------------------------------|
     * |      |  a|  R|  S|  T|  D|  h|  N|  E|  l|  O|   |        |
     * |-----------------------------------------------------------|
     * |        |  z|  x|  c|  v|  b|  K|  m|   |   |   |          |
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Tarmak4-Curl(DH) - Transitional Colemak-Curl (ETRO)               */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  U ,  I ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  M ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Tarmak4-Curl(Dvbg) - Transitional Colemak-Curl (ETRO)             */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  U ,  I ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  H ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    FTab  ,  Q ,  W ,  F ,  P ,  G ,  J ,  U ,  I ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */

#elif ACTIVELAYOUT == 5
    /* Colemak */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Colemak-Curl(DH). Use with an CurlAngle or CurlAngleWide ergo mod; see the INIT section!
     * http://forum.colemak.com/viewtopic.php?id=1438
     * (Shown here with the ANSI Angle(Z) mod; keymap ANAXCDVZ selects this variant)
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  B|  J|  L|  U|  Y|  ;|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  R|  S|  T|  G|  K|  N|  E|  I|  O|  '|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  X|  C|  D|  V|  Z|  M|  H|  ,|  .|  /|    Shift |
     * `-----------------------------------------------------------'     */
    /* Colemak-Curl(DH)Angle(Z)Wide(')-ANSI; use keymap AWAXCDVZ for this ergonomic variant
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  B|  [|  J|  L|  U|  Y|  ;|  '|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  R|  S|  T|  G|  ]|  K|  N|  E|  I|  O|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  X|  C|  D|  V|  Z|  /|  M|  H|  ,|  .|    Shift |
     * `-----------------------------------------------------------'     */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  M ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Colemak-Curl(old DHm variant). Use with a CurlAngle(Wide) ergo mod!     */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  M ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  K ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    /* Standard Colemak
     * http://colemak.com
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  G|  J|  L|  U|  Y|  ;|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  R|  S|  T|  D|  H|  N|  E|  I|  O|  '|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  K|  M|  ,|  .|  /|    Shift |
     * `-----------------------------------------------------------'     */
    FTab  ,  Q ,  W ,  F ,  P ,  G ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */

#elif ACTIVELAYOUT == 8
    /* Dvorak
     * http://en.wikipedia.org/wiki/Dvorak_Simplified_Keyboard
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|    Shift |
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,LBRC,FRbr,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,FQuo,COMM,DOT ,  P ,  Y ,  F ,  G ,  C ,  R ,  L ,FSls,EQL ,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  O ,  E ,  U ,  I ,  D ,  H ,  T ,  N ,  S ,FMin,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,FScl,  Q ,  J ,  K ,  X ,  B ,  M ,  W ,  V ,  Z , RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#elif ACTIVELAYOUT == 9
    /* Workman (but consider Colemak Curl(DH) instead, as it performs much better!)
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  D|  R|  W|  B|  J|  F|  U|  P|  ;|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |*Caps*|  A|  S|  H|  T|  G|  Y|  N|  E|  O|  I|  '|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  M|  C|  V|  K|  L|  ,|  .|  /|    Shift |
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,  Q ,  D ,  R ,  W ,  B ,  J ,  F ,  U ,  P ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  H ,  T ,  G ,  Y ,  N ,  E ,  O ,  I ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  M ,  C ,  V ,  K ,  L ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

    /* ****** Extra graphics of some of my layouts: ******************** */
    /* Colemak-CurlAngleWide, adapted for Norwegian locale (DreymaR's ISO/Nor hack solution)
     * (Shown with the AngleWide-ISO-ZXCDV ergo mod; keymap AWIZXCDV selects that)
     * http://forum.colemak.com/viewtopic.php?id=2158
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  B|  [|  J|  L|  U|  Y|  ;|  /| Ent |
     * |------------------------------------------------------`    |
     * |*Ext1*|  A|  R|  S|  T|  G|  ]|  K|  N|  E|  I|  O|  '|    |
     * |-----------------------------------------------------------|
     * |Shft|  Z|  X|  C|  D|  V|  <|  #|  M|  H|  ,|  .|    Shift |
     * `-----------------------------------------------------------' 
     * Modifications from the untweaked Colemak-CAW shown above:
     *      -   <>  /       ]   ->  ;   ->  <   ->  #   ->  '   ->  ]  
     *     MINS <> SLSH    RBRC -> SCLN -> NUBS -> NUHS -> QUOT -> RBRC
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  \|  7|  8|  9|  0|  -|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  B|  Å|  J|  L|  U|  Y|  ¨|  +| Ent |
     * |------------------------------------------------------`    |
     * |*Ext1*|  A|  R|  S|  T|  G|  Æ|  K|  N|  E|  I|  O|  '|    |
     * |-----------------------------------------------------------|
     * |Shft|  Z|  X|  C|  D|  V|  Ø|  <|  M|  H|  ,|  .|    Shift |
     * `-----------------------------------------------------------'     */

#endif /* if ACTIVELAYOUT */
    /* The bottom row is layout independent (but you may edit for instance the Fn keys as desired) */
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),    /* <-- Layer 0: Default Layout */

/* Layer 1: Second/Switch Layout (see below for replacing it with your any layer0 layout or your own) */
#if SECONDLAYOUT == 3
/* NOTE: This is the special case of using Colemak(Curl-DH) as the first, and Mirrored Colemak as the second layout. */
    /* Mirrored Colemak (used as switch layout for one-handed typing)
     * http://forum.colemak.com/viewtopic.php?id=1438
     * ,---.   ,---------------. ,---------------. ,---------------.
     * |  \|   |F12|F11|F10|F9 | |F8 |F7 |F6 |F5 | |F4 |F3 |F2 |F1 |
     * `---'   `---------------' `---------------' `---------------'
     * ,-----------------------------------------------------------.
     * |BSp|  -|  0|  9|  8|  7|  6|  5|  4|  3|  2|  1|  =|     ` |
     * |-----------------------------------------------------------|
     * | Ent |  ;|  Y|  U|  L|  J|  G|  P|  F|  W|  Q|Esc|Cps|   \ |
     * |-----------------------------------------------------------|
     * |    ' |  O|  I|  E|  N|  H|  D|  T|  S|  R|  A|  '|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  /|  .|  ,|  M|  K|  B|  V|  C|  X|  Z|    Shift |
     * `-----------------------------------------------------------'     */
    /* NOTE: Set an accessible key in your active layout (e.g., FnLA or RGUI) as a layer1 switch (FPau does this) */
    [1] = UNIMAP_AWIZXCBV(
    BSLS,    F12 ,F11 ,F10 , F9 ,    F8 , F7 , F6 , F5 ,    F4 , F3 , F2 , F1 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    BSPC,FMin,  0 ,  9 ,  8 ,  7 ,  6 ,  5 ,  4 ,  3 ,  2 ,  1 ,EQL ,JYEN,GRV ,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Colemak-Curl(DH). See above. */
    /* NOTE: Using a CurlAngle mod, the DV keys are swapped. The mirrored layout has to counteract that. */
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  B ,  P ,  F ,  W ,  Q ,ESC ,FCap,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  K ,  G ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  M ,  H ,  V ,  D ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Colemak-Curl(DHm for matrix boards). See above. */
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  B ,  P ,  F ,  W ,  Q ,ESC ,FCap,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  M ,  G ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  K ,  H ,  V ,  D ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  G ,  P ,  F ,  W ,  Q ,ESC ,FCap,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  H ,  D ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  M ,  K ,  B ,  V ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */
// NOTE: Optionally, the bottom/modifier line may also be mirrored. Comment/uncomment the lines below for this.
//       If using such a modifier as your Mirror switch, beware: The layer switch key should be the same in both layers.
//    FRCt ,RGUI,FnRA,MHEN,         SPC          ,HENK,KANA,FnLA,LGUI,APP , LCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
#else
/* Set SECONDLAYOUT to 1 for QWERTY or 2 for Colemak/custom as switch layout; otherwise it'll be unmodded QWERTY */
# if SECONDLAYOUT == 1
    /* QWERTY – as above                                                       */
    [1] = UNIMAP_AWIZXCBV(
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif SECONDLAYOUT == 2
/* --> REPLACE THE SECOND LAYOUT BETWEEN THESE LINES IF DESIRED - taking care to include all necessary lines once!    */
    /* Colemak - as above                                                      */
    [1] = UNIMAP_AWIZXCBV(
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
#  if CURLMOD == 1
    /* Colemak-Curl(DH). Use with an CurlAngle or CurlAngleWide ergo mod!      */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  elif CURLMOD == 2
    /* Colemak-Curl(old DHm variant). Use with a CurlAngle(Wide) ergo mod!     */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  M ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  else
    /* Standard Colemak                                                        */
    FTab  ,  Q ,  W ,  F ,  P ,  G ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  endif /* if CURLMOD */
/* <-- REPLACE THE SECOND LAYOUT BETWEEN THESE LINES IF DESIRED                                                       */
# else
    /* Plain QWERTY - without CurlAngleWide or DreymarHack, to reflect the key caps of a standard keyboard. */
//    [1] = UNIMAP_AWIZXCBV(
    [1] = UNIMAP_MINIMALL(
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,NUBS,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,SLSH, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if SECONDLAYOUT */
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
#endif /* if Colemak-Mirrored */
    ),    /* <-- Layer 1: Second/Switch Layout */

#if EXTENDMODE > 0
/* Layer 2: Extend1 (DreymaR)                                        */
/* ,----.    ,-------------------. ,-------------------. ,-------------------.
 * |Caps|    |MPly|MPrv|MNxt|MStp| |Mute|VolD|VolU|MSel| |WHom|WSch|MyCm|Calc|
 * `----'    `-------------------' `-------------------' `-------------------'
 * ,-------------------------------------------------------------------------.
 * | ?? | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|  Pause |
 * |-------------------------------------------------------------------------|
 * |      |Esc |Wh_U|WBak|WFwd|Ms_U|PgUp|Home| Up |End |Del |Esc |Ins |  App |
 * |-------------------------------------------------------------------------|
 * |*Ext1* |Alt |Wh_D|Shft|Ctrl|Ms_D|PgDn|Left|Down|Rght|BSpc|App |WFav|PScr |
 * |-------------------------------------------------------------------------|
 * |     |Wh_L| ^Z | ^X | ^C | ^V |Btn1|Btn2|Btn3|Ms_L|Ms_R|Wh_R|            |
 * |-------------------------------------------------------------------------|
 * |      |     |     |           Return            |Ext3 |     |     |      |
 * `-------------------------------------------------------------------------' */
/*            ACL0,ACL1,ACL2,BTN4,BTN5, NO , NO ,WAKE, NO , NO , NO , NO ,     */
/* NOTE: For Mirrored Colemak, please tweak this layer to suit your needs.     */
    [2] = UNIMAP_AWIZXCBV(
    CAPS,    MPLY,MPRV,MNXT,MSTP,   MUTE,VOLD,VOLU,MSEL,   WHOM,WSCH,MYCM,CALC,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    FnU1, F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,JYEN,PAUS,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,ESC ,WH_U,WBAK,WFWD,MS_U,PGUP,HOME, UP ,END ,DEL ,ESC ,INS ,   APP ,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,LALT,WH_D,LSFT,LCTL,MS_D,PGDN,LEFT,DOWN,RGHT,BSPC,APP ,WFAV,  PSCR,                      P4 , P5 , P6 ,PCMM,
    FLSh ,WH_L,c(Z),c(X),c(C),c(V),BTN1,BTN2,BTN3,MS_L,MS_R,WH_R, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
    LCTL ,LGUI,FnLA,MHEN,         ENT          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),    /* <-- Extend1 */

/* Layer 3: Extend2 (DreymaR)                                                  */
/* ,----.    ,-------------------. ,-------------------. ,-------------------.
 * |    |    |MPau|MRwd|MFFd|Ejct| |WRef|BriD|BriU|Slep| |www |Mail|App3|App4|
 * `----'    `-------------------' `-------------------' `-------------------'
 * ,-------------------------------------------------------------------------.
 * |    | !  | @  | #  | $  | %  | ^  | P7 | P8 | P9 | P* | P- | =  |        |
 * |-------------------------------------------------------------------------|
 * |      |Home| Up |End |Del |Esc |PgUp| P4 | P5 | P6 | P+ | (  | )  |      |
 * |-------------------------------------------------------------------------|
 * |*Ext2* |Left|Down|Rght|BSpc|NLck|PgDn| P1 | P2 | P3 |PEnt| '  | ,  |     |
 * |-------------------------------------------------------------------------|
 * |     |    | ^Z | ^X | ^C | ^V |Btn1| :  | P0 | P0 | P. | P/ |            |
 * |-------------------------------------------------------------------------|
 * |      |     |Ext2 |                             |Ext4 |     |     |      |
 * `-------------------------------------------------------------------------' */
    [3] = UNIMAP_AWIZXCBV(
    CAPS,    MPLY,MRWD,MFFD,EJCT,   WREF, NO , NO ,SLEP,   WSTP,MAIL,MYCM,CALC,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    FnU2,s(1),s(2),s(3),s(4),s(5),s(6), P7 , P8 , P9 ,PAST,PMNS,TRNS,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,HOME, UP ,END ,DEL ,ESC ,PGUP, P4 , P5 , P6 ,PPLS,FSh9,FSh0,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,LEFT,DOWN,RGHT,BSPC,NLCK,PGDN, P1 , P2 , P3 ,PENT,FQuo,COMM,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,TRNS,c(Z),c(X),c(C),c(V),BTN1,FSSC, P0 , P0 ,PDOT,PSLS, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
    LCTL ,LGUI,FnLA,MHEN,         TRNS         ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),    /* <-- Extend2 */

/* TODO: The advanced Extend layer selection using Ext/LAlt+Ext/RAlt+Ext isn't working yet! */
/* Proposed Extend modifier functionality for up to 4 Extend layers:
 * +------------++------+------+------+------++------+------+------+------+
 * |  Mod       ||  L0  | SEL2 | SEL3 | SEL4 || Ext1 | Ext2 | Ext3 | Ext4 |
 * +------------++------+------+------+------++------+------+------+------+
 * | Caps       || Ext1 | Ext2 | Ext3 | Ext4 || Ext1 | Ext2 | Ext3 | Ext4 |
 * | LAlt       || SEL2 | LAlt | SEL4 | SEL4 || LAlt | Ext2 | Ext3 | Ext4 |
 * | RAlt       || SEL3 | SEL4 | RAlt | SEL4 || RAlt | RAlt | RAlt | RAlt |
 * | Shift+Caps || E1Lk | E2Lk | E3Lk | E4Lk || E1Rl | E2Rl | E3Rl | E4Rl |
 * +------------++------+------+------+------++------+------+------+------+
 * This proposal uses SEL2-4 as auxiliary switching layers, modifying Caps function.
 * Shift awareness for layer locking would be great. Possible?
 * Also, tapping Caps alone should release locked layers.
 */
# if 0
    /* Layer 5: Select layer for Extend2 (DreymaR)                                     */
    /* ,-------------------------------------------------------------------------.
     * | Caps=Ext2  |LAlt |                             |Sel3 |     |     |      |
     * `-------------------------------------------------------------------------'     */
    /* TODO: LAlt should work as LAlt, but also maintain the layer! RAlt should activate the SelExt3 layer. */
    /*       If LAlt can't both hold the layer and be LAlt, make it a tap-modifier? No, tapping Alt is already in Win.*/
    [5] = UNIMAP_AWIZXCBV(
    TRNS,    TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,
    TRNS  ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,   TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,
    FnE2   ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,                     TRNS,TRNS,TRNS,TRNS,
    TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,        TRNS,        TRNS,TRNS,TRNS,TRNS,
    TRNS ,TRNS,LALT,TRNS,         TRNS         ,TRNS,TRNS,FnRA,TRNS,TRNS, TRNS,   TRNS,TRNS,TRNS,   TRNS     ,TRNS,TRNS 
    ),    /* <-- Layer 5: Selects Extend2 */
# endif /* TODO */

#endif /* if EXTENDMODE */
};    /* <-- Keymap layer definitions */

/* ***** FUNCTIONS/MACROS ******************************************************************************************* */

/* User function and macro definitions --> */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case TYPESTR1:
        /* Type a string (standard email boilerplate text; replace with your own) and select the name line */
            return (record->event.pressed ?
                MACRO( I(2), 
                    T(ENT), T(ENT), T(M), T(V), T(H), T(COMM), T(ENT), 
                    D(LSHIFT), T(SCLN), U(LSHIFT), T(Y), T(S), T(T), T(E), T(I), T(N), T(ENT), T(ENT),
                    D(LSHIFT), T(I), T(K), T(K), T(E), T(SPC), 
                    T(S), T(E), T(N), T(S), T(I), T(T), T(I), T(V), T(T), U(LSHIFT), T(ENT), 
                    T(UP), T(UP), T(UP), T(END), D(LSHIFT), T(HOME), U(LSHIFT),
                    END ) :
                MACRO_NONE );
        case TYPESTR2:
        /* Type a string (smiley; this one works on the Norwegian layout and some other ISO ones) */
        // Smiley macro for ANSI: T(SPC), T(SCLN), T(MINS), D(LSHIFT), T(0), U(LSHIFT), T(ENT),
            return (record->event.pressed ?
                MACRO( I(2), 
                    T(SPC), D(LSHIFT), T(DOT), U(LSHIFT), T(SLSH), D(LSHIFT), T(9), U(LSHIFT), T(ENT), 
                    END ) :
                MACRO_NONE );
    }
    return MACRO_NONE;
}    /* <-- User function and macro definitions */
