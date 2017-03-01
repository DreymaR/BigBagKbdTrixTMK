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
 * 2016 Øystein "DreymaR" Gadmar: Curl/Angle/Wide and Extend layouts
 * See the Colemak Forum (DreymaR's Big Bag of Keyboard Tricks) for info
 * http://forum.colemak.com/viewtopic.php?id=2158
 * 
 * For Angle/Wide, I found no good way to replace the keymap before parsing the resulting macro
 * Instead, manually search/replace the UNIMAP_AWIDEISO text globally before compiling this file
 * 
 * Compiler preprocessor defines select layout and Extend layers
 * - ACTIVELAYOUT # selects basic layout (QWERTY, Colemak, etc)
 * - CURLMOD 1      activates the Curl-DbgHk ergo mod (only affects Colemak/Tarmak layouts)
 * - EXTENDMODE 1   selects Extend mappings (navigation layer, NumPad layer, etc)
 * - CAPSBEHAVIOR # selects CapsLock key behavior when Extend is off (Caps, BSpc, LCtrl)
 */

/* ***** SETTINGS *************************************************************************************************** */

/* Search-replace 'UNIMAP_AWIDEISO' in this file to use ergonomic keyboard mods:
 * _MINIMALL - Default unimap format for all keyboard and converter types (this one is w/o F13-24)
 * _ANGLEISO - ISO/Int Angle ergo mod
 * _AWIDEISO - ISO/Int Angle-Wide(/) ergo mod
 * _ANGZANSI - ANSI/US Angle(Z) ergo mod
 * _ANGZWIDE - ANSI/US Angle(Z)-Wide(') ergo mod
 * _ANGLWING - ANSI/US A-Wing ergo mod
 */

/* Define the ACTIVELAYOUT (and CURLMOD) constant(s) to choose the layer0 layout:
 * 0  : QWERTY
 * 1  : Tarmak1 - transitional Colemak (supports CURLMOD 1; 2 is not relevant)
 * 2  : Tarmak2 - transitional Colemak (supports CURLMOD 1 & 2; see below)
 * 3  : Tarmak3 - transitional Colemak (--"--)
 * 4  : Tarmak4 - transitional Colemak (--"--)
 * 5-0: Colemak
 * 5-1: Colemak-Curl(DbgHk)Angle (requires an Angle-modded keymap; see above)
 * 5-2: Colemak-Curl(DvbgHm)Angle (--"--)
 * 8  : Dvorak
 * 9  : Workman (if you must - I believe Colemak-Curl/DH is a lot better!)
 * 
 * The CURLMOD options for Colemak/Tarmak layouts are:
 * 0: No Curl - vanilla Colemak
 * 1: DreymaR's DbgHk ergo mod, bringing the common DH keys from the middle "trench" to the QWERTY VN keys
 * 2: SteveP99's DvbgHm ergo mod, bringing the DH keys inwards to the CM keys
 */
#define ACTIVELAYOUT 5
#define CURLMOD 1

/* Define the SECONDLAYOUT (and CURLMOD) constant(s) to choose the layer1/switch layout:
 * -  : QWERTY will be the default if ACTIVELAYOUT isn't QWERTY (you may replace it below)
 * -  : The exception to this is choosing Colemak as active and mirrored Colemak as second layout.
 * 1-#: Tarmak1 - transitional Colemak (as above; supports CURLMOD). Copy/Paste in Tarmak2-3-4 as desired.
 * 5-#: Colemak (as above; supports CURLMOD)
 * 6-#: Colemak mirrored (as second layout for one-handed typing; needs an accessible switch key!)
 *      NOTE: The "FPau" key is a layer1 toggle or switch (edit it below), normally used on the Pause key.
 *            You may replace, e.g., the LAlt/"FnLA" or RWin/"RGUI" key with "FPau" in your active layout.
 */
#define SECONDLAYOUT 5

/* The EXTENDMODE constant activates the extra Extend layers:
 * Ext1 - Caps     : Navigation/editing/multimedia
 * Ext2 - Tab      : NumPad/Navigation [NOTE: For now, the Ext2 modifier is Tab but it should be Alt+Caps]
 */
#define EXTENDMODE 1

/* The CAPSBEHAVIOR constant chooses non-Extend Caps key action:
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
 * NOTE: In the .h file, some constants normally set in config.h are (re)set:
 *       - TAPPING_TERM is the max time a key may be held down for it to register as tapped
 *       - ONESHOT_TIMEOUT is the max delay before a oneshot modifier is ignored
 */
#define STICKYMODS 1

/* The SCLKBEHAVIOR constant chooses ScrollLock key action:
 * 0: Normal ScrollLock (default)
 * 1: Win/GUI key (useful for 101/104-key boards that have no GUI key)
 */
#define SLCKBEHAVIOR 0

/* The PAUSBEHAVIOR constant chooses Pause/Break key action:
 * 0: Normal Pause/Break (default)
 * 1: Layer 1 toggle key (toggles the second layout)
 * 2: Layer 1 switch key (layer shift; e.g., for mirrored typing if you can use it as ghetto foot switch)
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
 * KEYMAP_ALL (or similar keymaps); NOTE: For this to work, use my keymap_dreymar_old files (may be outdated)!
 */
#define USEUNIMAP
#ifdef USEUNIMAP
# include "unimap_trans.h"
# include "unimap_dreymar.h"
#else
# include "keymap_common.h"
# include "keymap_dreymar_old.h"
#endif /* ifdef USEUNIMAP */

/* DreymaR's master key! Define it for quick access. It produces compiler warnings; these may be ignored.             */
//#define DREYMASTERKEY
#ifdef DREYMASTERKEY
# define ACTIVELAYOUT 5
# define SECONDLAYOUT 6
# define CURLMOD 1
# define PAUSBEHAVIOR 2
# define DREYMARHACK 1
#endif /* ifdef DREYMASTERKEY */

/* TODO for DreymaR:
 * - Make all Extend definitions and modifiers work (extra layers for Alt+Caps etc)
 */

/* ***** DECLARATIONS *********************************************************************************************** */

/* User function and macro declarations --> */
enum macro_id {
    TYPESTR1,
    TYPESTR2,
};    /* <-- User function and macro declarations */

/* Fn action key definitions (Unimap style) --> */
# if EXTENDMODE == 1
// NOTE: Current FTab/FnLA/FnRA behavior is until I get the fancy way of selecting Extend2-4 to work...
#  define AC_FCap ACTION_LAYER_MOMENTARY(3)          // FCap selects Extend1 (gets priority over CAPSBEHAVIOR)
#  define AC_FnE2 ACTION_LAYER_MOMENTARY(2)          // FnE2 selects Extend2
//#  define AC_FnE3 ACTION_LAYER_MOMENTARY(3)          // FnE3 selects Extend3 (TODO)
//#  define AC_FnE4 ACTION_LAYER_MOMENTARY(4)          // FnE4 selects Extend4 (TODO)
//#  define AC_FnLA ACTION_LAYER_MOMENTARY(5)          // FnLA selects layer5 (TODO; temp-select for Extend2)
//#  define AC_FnRA ACTION_LAYER_MOMENTARY(6)          // FnRA selects layer6 (TODO; temp-select for Extend3)
//#  define AC_FnBA ACTION_LAYER_MOMENTARY(7)          // FnBA selects layer7 (TODO; temp-select for Extend4)
#  define AC_FTab ACTION_LAYER_TAP_KEY(2, KC_TAB)    // FTab (Tab key)  as Ext2 – tap for Tab (for now)
#  define AC_FnLA ACTION_KEY(KC_LALT)                // FnLA (LAlt key) as usual (for now)
#  define AC_FnRA ACTION_KEY(KC_RALT)                // FnRA (RAlt key) as usual (for now)
//#  define AC_FnU1 ACTION_MODS_KEY(MOD_LGUI, KC_T)    // FnU1 (`) as Win+T
#  define AC_FnU1 ACTION_MACRO(TYPESTR1)             // FnU1 as user macro: Type a string
#  define AC_FnU2 ACTION_MACRO(TYPESTR2)             // FnU2 as user macro: Type a string
#  define AC_FSh1 ACTION_MODS_KEY(MOD_LSFT, KC_1)    // FSh1 is Shift+1
#  define AC_FSh2 ACTION_MODS_KEY(MOD_LSFT, KC_2)    // FSh2 is Shift+2
#  define AC_FSh3 ACTION_MODS_KEY(MOD_LSFT, KC_3)    // FSh3 is Shift+3
#  define AC_FSh4 ACTION_MODS_KEY(MOD_LSFT, KC_4)    // FSh4 is Shift+4
#  define AC_FSh5 ACTION_MODS_KEY(MOD_LSFT, KC_5)    // FSh5 is Shift+5
#  define AC_FSh6 ACTION_MODS_KEY(MOD_LSFT, KC_6)    // FSh6 is Shift+6
//#  define AC_FSh7 ACTION_MODS_KEY(MOD_LSFT, KC_7)    // FSh7 is Shift+7
//#  define AC_FSh8 ACTION_MODS_KEY(MOD_LSFT, KC_8)    // FSh8 is Shift+8
#  define AC_FCtZ ACTION_MODS_KEY(MOD_LCTL, KC_Z)    // FCtZ is Ctrl+Z
#  define AC_FCtX ACTION_MODS_KEY(MOD_LCTL, KC_X)    // FCtX is Ctrl+X
#  define AC_FCtC ACTION_MODS_KEY(MOD_LCTL, KC_C)    // FCtC is Ctrl+C
#  define AC_FCtV ACTION_MODS_KEY(MOD_LCTL, KC_V)    // FCtV is Ctrl+V
# else
#  define AC_FTab ACTION_KEY(KC_TAB)                 // FTab (Tab key)  as its usual self
#  define AC_FnLA ACTION_KEY(KC_LALT)                // FnLA (LAlt key) as its usual self
#  define AC_FnRA ACTION_KEY(KC_RALT)                // FnRA (RAlt key) as its usual self
#  if CAPSBEHAVIOR == 1
#   define AC_FCap ACTION_KEY(KC_BSPC)                 // FCap (Caps key) as BackSpace (for Colemak etc)
#  elif CAPSBEHAVIOR == 2
#   define AC_FCap ACTION_KEY(KC_LCTL)                 // FCap (Caps key) as LeftCtrl
#  elif CAPSBEHAVIOR == 3
#   define AC_FCap ACTION_KEY(KC_ESC)                  // FCap (Caps key) as Esc
#  else
#   define AC_FCap ACTION_KEY(KC_CAPS)                 // FCap (Caps key) as its usual self
#  endif /* if CAPSBEHAVIOR */
# endif /* if EXTENDMODE */

#if STICKYMODS == 1
# define AC_FLSh ACTION_MODS_ONESHOT(MOD_LSFT)       // FLSh (Left Shift key) as sticky shift
# define AC_FRSh ACTION_MODS_ONESHOT(MOD_RSFT)       // FRSh (Right Shift key) as sticky shift
# define AC_FRCt ACTION_KEY(KC_RCTL)                 // FRCt (Right Ctrl key) as its usual self
#elif STICKYMODS == 2
# define AC_FLSh ACTION_KEY(KC_LSFT)                 // FLSh (Left Shift key) as its usual self
# define AC_FRSh ACTION_KEY(KC_RSFT)                 // FRSh (Right Shift key) as its usual self
# define AC_FRCt ACTION_MODS_ONESHOT(MOD_RCTL)       // FRCt (Right Ctrl key) as sticky control
#elif STICKYMODS == 3
# define AC_FLSh ACTION_MODS_ONESHOT(MOD_LSFT)       // FLSh (Left Shift key) as sticky shift
# define AC_FRSh ACTION_MODS_ONESHOT(MOD_RSFT)       // FRSh (Right Shift key) as sticky shift
# define AC_FRCt ACTION_MODS_ONESHOT(MOD_RCTL)       // FRCt (Right Ctrl key) as sticky control
#else
# define AC_FLSh ACTION_KEY(KC_LSFT)                 // FLSh (Left Shift key) as its usual self
# define AC_FRSh ACTION_KEY(KC_RSFT)                 // FRSh (Right Shift key) as its usual self
# define AC_FRCt ACTION_KEY(KC_RCTL)                 // FRCt (Right Ctrl key) as its usual self
#endif /* if STICKYMODS */

#if SLCKBEHAVIOR == 1
# define AC_FSLk ACTION_KEY(KC_LGUI)                   // FSLk as GUI/Win (for 101/104-key boards)
#else
# define AC_FSLk ACTION_KEY(KC_SLCK)                   // FSLk (ScrollLock key) as its usual self
#endif /* if SLCKBEHAVIOR */

#if PAUSBEHAVIOR == 1
# define AC_FPau ACTION_LAYER_TOGGLE(1)                // FPau as layer1 toggle
#elif PAUSBEHAVIOR == 2
#  define AC_FPau ACTION_LAYER_MOMENTARY(1)            // FPau as layer1 switch (for mirrored typing)
#else
# define AC_FPau ACTION_KEY(KC_PAUS)                   // FPau (Pause/Break key) as its usual self
#endif /* if PAUSBEHAVIOR */

#if DREYMARHACK == 1
/*    Adaptations for Nor/etc locale (DreymaR's ISO/Nor hack):
 *    MINS <> SLSH    RBRC -> SCLN -> NUBS -> NUHS -> QUOT
 *    FMin    FSls    FRbr    FScl    FLgt    FHsh    FQuo    */
# define AC_FMin ACTION_KEY(KC_SLSH)                   // FMin (MINS key) as SLSH (ISO/Nor hack)
# define AC_FSls ACTION_KEY(KC_MINS)                   // FSls (SLSH key) as MINS (ISO/Nor hack)
# define AC_FRbr ACTION_KEY(KC_QUOT)                   // FRbr (RBRC key) as QUOT (ISO/Nor hack)
# define AC_FScl ACTION_KEY(KC_RBRC)                   // FScl (SCLN key) as RBRC (ISO/Nor hack)
# define AC_FLgt ACTION_KEY(KC_SCLN)                   // FLgt (NUBS key) as SCLN (ISO/Nor hack)
# define AC_FHsh ACTION_KEY(KC_NUBS)                   // FHsh (NUHS key) as NUBS (ISO/Nor hack)
# define AC_FQuo ACTION_KEY(KC_NUHS)                   // FQuo (QUOT key) as NUHS (ISO/Nor hack)
#  define AC_FSh9 ACTION_MODS_KEY(MOD_LSFT, KC_8)    // FSh9 is Shift+8 (left parenthesis, Nor)
#  define AC_FSh0 ACTION_MODS_KEY(MOD_LSFT, KC_9)    // FSh0 is Shift+9 (right parenthesis, Nor)
#  define AC_FSSC ACTION_MODS_KEY(MOD_LSFT, KC_DOT)  // FSSC is Shift+Period (colon, Nor)
#else
# define AC_FMin ACTION_KEY(KC_MINS)                   // FMin (MINS key) as its usual self
# define AC_FSls ACTION_KEY(KC_SLSH)                   // FSls (SLSH key) as its usual self
# define AC_FRbr ACTION_KEY(KC_RBRC)                   // FRbr (RBRC key) as its usual self
# define AC_FScl ACTION_KEY(KC_SCLN)                   // FScl (SCLN key) as its usual self
# define AC_FLgt ACTION_KEY(KC_NUBS)                   // FLgt (NUBS key) as its usual self
# define AC_FHsh ACTION_KEY(KC_NUHS)                   // FHsh (NUHS key) as its usual self
# define AC_FQuo ACTION_KEY(KC_QUOT)                   // FQuo (QUOT key) as its usual self
#  define AC_FSh9 ACTION_MODS_KEY(MOD_LSFT, KC_9)    // FSh9 is Shift+9 (left parenthesis)
#  define AC_FSh0 ACTION_MODS_KEY(MOD_LSFT, KC_0)    // FSh0 is Shift+0 (right parenthesis)
#  define AC_FSSC ACTION_MODS_KEY(MOD_LSFT, KC_SCLN) // FSSC is Shift+Semicolon (colon, US)
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
    [0] = UNIMAP_AWIDEISO(
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
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO| Shft |     |Up |     |  1|  2|  3|Ent|
     * |-----------------------------------------------------------| ,-----------. |---------------|
     * |Ctrl|Gui|Alt|MHEN|     Space     |HENK|KANA|Alt|Gui|App|Ctl| |Lft|Dwn|Rgh| |      0|  .|  =|
     * `-----------------------------------------------------------' `-----------' `---------------'
     */
    /* QWERTY-Wide(') for ANSI boards; use keymap ANGZWIDE for this ergonomic variant (see the INIT section)
     * http://forum.colemak.com/viewtopic.php?id=1438
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  [|  Y|  U|  I|  O|  P|  '|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  S|  D|  F|  G|  ]|  H|  J|  K|  L|  ;|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  /|  N|  M|  ,|  ,|    Shift |
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
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Tarmak1-Curl(Hk) - Transitional Colemak-Curl (E)                  */
    FTab  ,  Q ,  W ,  J ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  K ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
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
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Tarmak2-Curl(DbgHk) - Transitional Colemak-Curl (ET)              */
    FTab  ,  Q ,  W ,  F ,  R ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  T ,  G ,  K ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  J ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Tarmak2-Curl(Dvbg) - Transitional Colemak-Curl (ET)               */
    FTab  ,  Q ,  W ,  F ,  R ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  T ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  J ,  V ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
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
    /* Tarmak3-Curl(DbgHk) - Transitional Colemak-Curl (ETR)             */
    FTab  ,  Q ,  W ,  F ,  J ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Tarmak3-Curl(Dvbg) - Transitional Colemak-Curl (ETR)              */
    FTab  ,  Q ,  W ,  F ,  J ,  B ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
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
    /* Tarmak4-Curl(DbgHk) - Transitional Colemak-Curl (ETRO)            */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  U ,  I ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Tarmak4-Curl(Dvbg) - Transitional Colemak-Curl (ETRO)             */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  U ,  I ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  H ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    FTab  ,  Q ,  W ,  F ,  P ,  G ,  J ,  U ,  I ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  L ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */

#elif ACTIVELAYOUT == 5
    /* Colemak */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Colemak-Curl(DbgHk). Use with an Angle or Angle(Wide) ergo mod; see the INIT section!
     * http://forum.colemak.com/viewtopic.php?id=1438
     * (Shown here with the ANSI Angle(Z) mod; keymap ANGZANSI selects this variant)
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  B|  J|  L|  U|  Y|  ;|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  R|  S|  T|  G|  K|  N|  E|  I|  O|  '|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  X|  C|  V|  D|  Z|  H|  M|  ,|  ,|  /|    Shift |
     * `-----------------------------------------------------------'     */
    /* Colemak-Curl(DbgHk)Angle(Z)Wide(')-ANSI; use keymap ANGZWIDE for this ergonomic variant
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  B|  [|  J|  L|  U|  Y|  ;|  '|   \ |
     * |-----------------------------------------------------------|
     * |*BSpc*|  A|  R|  S|  T|  G|  ]|  K|  N|  E|  I|  O|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  X|  C|  V|  D|  Z|  /|  H|  M|  ,|  ,|    Shift |
     * `-----------------------------------------------------------'     */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Colemak-Curl(DvbgHm - SteveP99's "Mod-DH" variant). Use with an Angle(Wide) ergo mod! */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  M ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
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
     * | Shift  |  Z|  X|  C|  V|  B|  K|  M|  ,|  ,|  /|    Shift |
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
    /* Workman (but consider Colemak-Curl instead, as it performs better!)
     * http://viralintrospection.wordpress.com/2010/09/06/a-different-philosophy-in-designing-keyboard-layouts/
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  D|  R|  W|  B|  J|  F|  U|  P|  ;|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |*Caps*|  A|  S|  H|  T|  G|  Y|  N|  E|  O|  I|  '|  Enter |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  M|  C|  V|  K|  L|  ,|  ,|  /|    Shift |
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,  Q ,  D ,  R ,  W ,  B ,  J ,  F ,  U ,  P ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  H ,  T ,  G ,  Y ,  N ,  E ,  O ,  I ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  M ,  C ,  V ,  K ,  L ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#elif ACTIVELAYOUT == 55
    /* NOTE: This solution is outdated. You can select Colemak-Curl and the DreymaR hack instead. */
    /* Colemak-Curl(DbgHk), adapted for Norwegian locale (DreymaR's ISO/Nor hack solution)
     * (Shown with the AngleWide-ISO ergo mod; keymap AWIDEISO selects that)
     * http://forum.colemak.com/viewtopic.php?id=2158
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  =|  7|  8|  9|  0|  -|  BSpc |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  F|  P|  B|  [|  J|  L|  U|  Y|  ;|  /| Ent |
     * |------------------------------------------------------`    |
     * |*Ext1*|  A|  R|  S|  T|  G|  ]|  K|  N|  E|  I|  O|  '|    |
     * |-----------------------------------------------------------|
     * |Shft|  Z|  X|  C|  V|  D|  <|  #|  H|  M|  ,|  ,|    Shift |
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
     * |Shft|  Z|  X|  C|  V|  D|  Ø|  <|  H|  M|  ,|  ,|    Shift |
     * `-----------------------------------------------------------'     */
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,SLSH,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,RBRC,LBRC,QUOT,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  I ,  O ,NUHS,NUBS,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,SCLN,  Z ,  X ,  C ,  V ,  D ,  H ,  M ,COMM,DOT ,MINS, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,

#endif /* if ACTIVELAYOUT */
    /* The bottom row is layout independent (but you may edit for instance the Fn keys as desired) */
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),    /* <-- Layer 0: Default Layout */

/* Layer 1: Second/Switch Layout [NOTE: Replace all the #if stuff with one of the Layer0 layouts if desired!] --> */
    [1] = UNIMAP_AWIDEISO(
/* REPLACE SECOND LAYOUT BETWEEN THESE LINES AS NEEDED (taking care to include all necessary lines once!) --> */
/*    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
 *    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,LBRC,FRbr,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
 */
#if ACTIVELAYOUT == 5 && SECONDLAYOUT == 6
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
    BSLS,    F12 ,F11 ,F10 , F9 ,    F8 , F7 , F6 , F5 ,    F4 , F3 , F2 , F1 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    BSPC,FMin,  0 ,  9 ,  8 ,  7 ,  6 ,  5 ,  4 ,  3 ,  2 ,  1 ,EQL ,JYEN,GRV ,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
# if CURLMOD == 1
    /* Colemak-Curl(DbgHk). See above. */
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  B ,  P ,  F ,  W ,  Q ,ESC ,FCap,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  K ,  G ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  M ,  H ,  D ,  V ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# elif CURLMOD == 2
    /* Colemak-Curl(DvbgHm - SteveP99's "Mod-DH" variant). See above. */
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  B ,  P ,  F ,  W ,  Q ,ESC ,FCap,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  M ,  G ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  H ,  K ,  V ,  D ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# else
    ENT   ,FScl,  Y ,  U ,  L ,  J ,  G ,  P ,  F ,  W ,  Q ,ESC ,FCap,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FQuo   ,  O ,  I ,  E ,  N ,  H ,  D ,  T ,  S ,  R ,  A ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FRSh ,FLgt,FSls,DOT ,COMM,  M ,  K ,  B ,  V ,  C ,  X ,  Z , RO ,    FLSh,         UP ,         P1 , P2 , P3 ,PENT,
# endif /* if CURLMOD */
#else
    ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,FMin,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,

#if ACTIVELAYOUT == 0
/* If QWERTY is the active layout, set SECONDLAYOUT to 1 for Tarmak1 as switch layout; otherwise it'll be Colemak */
# if SECONDLAYOUT == 1
    /* Tarmak1 - Transitional Colemak (E) – as above                           */
#  if CURLMOD == 1
    /* Tarmak1-Curl(Hk) - Transitional Colemak-Curl (E)                        */
    FTab  ,  Q ,  W ,  J ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  K ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  else
    FTab  ,  Q ,  W ,  J ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  N ,  E ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  endif /* if CURLMOD */
# else
    /* Colemak - as above                                                      */
#  if CURLMOD == 1
    /* Colemak-Curl(DbgHk). Use with an Angle or Angle(Wide) ergo mod; see the INIT section! */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  K ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  D ,  H ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  elif CURLMOD == 2
    /* Colemak-Curl(DvbgHm - SteveP99's "Mod-DH" variant). Use with an Angle(Wide) ergo mod! */
    FTab  ,  Q ,  W ,  F ,  P ,  B ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  G ,  M ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  D ,  V ,  K ,  H ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  else
    /* Standard Colemak                                                        */
    FTab  ,  Q ,  W ,  F ,  P ,  G ,  J ,  L ,  U ,  Y ,FScl,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  R ,  S ,  T ,  D ,  H ,  N ,  E ,  I ,  O ,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  K ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#  endif /* if CURLMOD */
# endif /* if SECONDLAYOUT */
#else
    /* Plain QWERTY - as above                                                 */
    FTab  ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,FRbr,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,FScl,FQuo,FHsh,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,FLgt,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,FSls, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
#endif /* if ACTIVELAYOUT == 0 (QWERTY) */
#endif /* if Colemak+Colemak-Mirrored */
/* <-- REPLACE SECOND LAYOUT BETWEEN THESE LINES AS NEEDED */
    LCTL ,LGUI,FnLA,MHEN,         SPC          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),    /* <-- Layer 1: Second/Switch Layout */

#if EXTENDMODE == 1
/* Layer 3 [for now]: Extend1 (DreymaR)                                        */
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
 * |      |     |Ext1 |           Return            |     |     |     |      |
 * `-------------------------------------------------------------------------' */
/*            ACL0,ACL1,ACL2,BTN4,BTN5, NO , NO ,WAKE, NO , NO , NO , NO , */
    [3] = UNIMAP_AWIDEISO(
    CAPS,    MPLY,MPRV,MNXT,MSTP,   MUTE,VOLD,VOLU,MSEL,   WHOM,WSCH,MYCM,CALC,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    FnU1, F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,JYEN,PAUS,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    TAB   ,ESC ,WH_U,WBAK,WFWD,MS_U,PGUP,HOME, UP ,END ,DEL ,ESC ,INS ,   APP ,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FCap   ,LALT,WH_D,LSFT,LCTL,MS_D,PGDN,LEFT,DOWN,RGHT,BSPC,APP ,WFAV,  PSCR,                      P4 , P5 , P6 ,PCMM,
    FLSh ,WH_L,FCtZ,FCtX,FCtC,FCtV,BTN1,BTN2,BTN3,MS_L,MS_R,WH_R, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
    LCTL ,LGUI,FnLA,MHEN,         ENT          ,HENK,KANA,FnRA,RGUI,APP , FRCt,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL 
    ),    /* <-- Extend1 */

/* Layer 2: Extend2 (DreymaR)                                                  */
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
 * |      |     |     |                             |Ext2 |     |     |      |
 * `-------------------------------------------------------------------------' */
    [2] = UNIMAP_AWIDEISO(
    CAPS,    MPLY,MRWD,MFFD,EJCT,   WREF, NO , NO ,SLEP,   WSTP,MAIL,MYCM,CALC,   PSCR,FSLk,FPau,        VOLD,VOLU,MUTE,
    FnU2,FSh1,FSh2,FSh3,FSh4,FSh5,FSh6, P7 , P8 , P9 ,PAST,PMNS,TRNS,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,
    FTab  ,HOME, UP ,END ,DEL ,ESC ,PGUP, P4 , P5 , P6 ,PPLS,FSh9,FSh0,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS,
    FnE2   ,LEFT,DOWN,RGHT,BSPC,NLCK,PGDN, P1 , P2 , P3 ,PENT,FQuo,COMM,  ENT ,                      P4 , P5 , P6 ,PCMM,
    FLSh ,TRNS,FCtZ,FCtX,FCtC,FCtV,BTN1,FSSC, P0 , P0 ,PDOT,PSLS, RO ,    FRSh,         UP ,         P1 , P2 , P3 ,PENT,
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
    [5] = UNIMAP_AWIDEISO(
    TRNS,    TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,
    TRNS  ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,   TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,
    FnE2   ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,                     TRNS,TRNS,TRNS,TRNS,
    TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,    TRNS,        TRNS,        TRNS,TRNS,TRNS,TRNS,
    TRNS ,TRNS,LALT,TRNS,         TRNS         ,TRNS,TRNS,RALT,TRNS,TRNS, TRNS,   TRNS,TRNS,TRNS,   TRNS     ,TRNS,TRNS 
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
