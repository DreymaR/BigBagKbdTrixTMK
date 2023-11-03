/*
Copyright 2014 Jun Wako <wakojun@gmail.com>

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
 *  2016- Øystein "DreymaR" Gadmar: AngleWide ergonomic keyboard mods as keymap types
 *  See the Colemak Forum (DreymaR's Big Bag of Keyboard Tricks) for info
 *  http://forum.colemak.com/viewtopic.php?id=2158
 *  
 *  Content:
 *    - UNIMAP_NOMODS   - Null map (keep everything in place)
 *    - UNIMAP_ISO_A_   - Angle-ISO ergo mod
 *    - UNIMAP_ISO_AW   - AngleWide-ISO keymap
 *    - UNIMAP_ANS_A_   - Angle-Z-ANSI ergo mod
 *    - UNIMAP_ANS_AW   - AngleWide-ANSI keymap
 *    - UNIMAP_AWINGA   - A-Wing ANSI Angle mod (rarely used)
 *  
 *  REMOVED (as the ZXCVB -> ZXCBV swap should be done in the .c file instead, so it only affects Colemak and Extend):
 *    - UNIMAP_###_CA[_|W]_     - These 'C' maps were exactly like non-C, except for a V-B swap.
 *    - UNIMAP_ISO_CAWS         - Shouldn't be a keymap. Sym is best handled in the .c file (as a soft mod?).
 */

/* ***** EXAMPLES ****************************************************************************************************** */
/*          ,---------------˛ ,---------------˛ ,---------------˛                UNIMAP w/ QWERTY
 *          |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 *  ,---˛   |---------------| |---------------| |---------------| ,-----------˛     ,-----------˛
 *  |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |VDn|VUp|Mut|
 *  `---´   `---------------´ `---------------´ `---------------´ `-----------´     `-----------´
 *  ,-----------------------------------------------------------˛ ,-----------˛ ,---------------˛
 *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|BSp| |Ins|Hom|PgU| |NLk|  /|  *|  -|
 *  |-----------------------------------------------------------| |-----------| |---------------|
 *  | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 *  |-----------------------------------------------------------| `-----------´ |---------------|
 *  | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |               |  4|  5|  6|  ,|
 *  |-----------------------------------------------------------|     ,---˛     |---------------|
 *  | Sft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|  Sft |     |Up |     |  1|  2|  3|Ent|
 *  |-----------------------------------------------------------| ,-----------˛ |---------------|
 *  | Ctrl|Gui|Alt|MHE|     Space     |HEN|KAN|Alt|Gui|App|Ctrl | |Lft|Dwn|Rgh| |      0|  .|  =|
 *  `-----------------------------------------------------------´ `-----------´ `---------------´
 */

/*          ,---------------˛ ,---------------˛ ,---------------˛                KEYMAP_ALL w/ QWERTY
 *          |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 *  ,---˛   |---------------| |---------------| |---------------| ,-----------˛ ,---------------˛ ,-------˛
 *  |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
 *  `---´   `---------------´ `---------------´ `---------------´ `-----------´ `---------------´ `-------´
 *  ,-----------------------------------------------------------˛ ,-----------˛ ,---------------˛ ,-------˛
 *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|BSp| |Ins|Hom|PgU| |NLk|  /|  *|  -| |Stp|Agn|
 *  |-----------------------------------------------------------| |-----------| |---------------| |-------|
 *  | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
 *  |-----------------------------------------------------------| `-----------´ |---------------| |-------|
 *  | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |               |  4|  5|  6|  ,| |Sel|Cpy|
 *  |-----------------------------------------------------------|     ,---˛     |---------------| |-------|
 *  | Sft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|  Sft |     |Up |     |  1|  2|  3|  =| |Exe|Pst|
 *  |-----------------------------------------------------------| ,-----------˛ |---------------| |-------|
 *  | Ctrl|Gui|Alt|MHE|HNJ| Space |H/E|HEN|KAN|Alt|Gui|App|Ctrl | |Lft|Dwn|Rgh| |      0|  .|Ent| |Fnd|Cut|
 *  `-----------------------------------------------------------´ `-----------´ `---------------´ `-------´
 */

/*  ,---˛   ,---------------˛ ,---------------˛ ,---------------˛ ,-----------˛  KEYMAP_ISO 
 *  |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|  w/ QWERTY
 *  `---´   `---------------´ `---------------´ `---------------´ `-----------´
 *  ,-----------------------------------------------------------˛ ,-----------˛ ,---------------˛
 *  |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc | |Ins|Hom|PgU| |NLk|  /|  *|  -|
 *  |-----------------------------------------------------------| |-----------| |---------------|
 *  | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Ent | |Del|End|PgD| |  7|  8|  9|  +|
 *  |------------------------------------------------------`    | `-----------´ |-----------|   |
 *  | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|    |               |  4|  5|  6|   |
 *  |-----------------------------------------------------------|     ,---˛     |---------------|
 *  | Sft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|    Shift |     |Up |     |  1|  2|  3|Ent|
 *  |-----------------------------------------------------------| ,-----------˛ |-----------|   |
 *  | Ctrl|LGui|LAlt|        Space         |RAlt|RGui|App |Ctrl | |Lft|Dwn|Rgh| |      0|  .|   |
 *  `-----------------------------------------------------------´ `-----------´ `---------------´
 */


/* ***** CONFIG ******************************************************************************************************** */
/* ***** Extra includes/definitions                                                         ***** */
#include "action_util.h"                            /* For the FourLvlU user function */
#include "action_layer.h"                           /* For the Extender user function */

/* NOTE: This section (re)defines parts of the controller/converter's local config.h file. The compiler may complain. */
/* Period of tapping (ms) - the max duration a key may be held down to register as tapped */
#define TAPPING_TERM    300
/* Tap count needed for toggling a feature - used for special multi-tap actions only */
//#define TAPPING_TOGGLE  5
/* Oneshot timeout (ms) - the max delay before a one-shot modifier is reset and ignored */
//#define ONESHOT_TIMEOUT 300
#define ONESHOT_TIMEOUT 600

/* NOTE: Disabling unused features may help reduce firmware size. Don't disable anything necessary! */
#define NO_DEBUG
//#define NO_PRINT
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION


/* ***** MAIN ********************************************************************************************************** */
#ifndef UNIMAP_DREYMAR_H
#define UNIMAP_DREYMAR_H

/* ------------------------------------------------------------------------------ # UNIMAP (with plain QWERTY)    # ---- */
/*  ESC ,      F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,        PSCR,SLCK,PAUS,        VOLD,VOLU,MUTE, */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS, */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS, */
/*  CAPS   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT ,                      P4 , P5 , P6 ,PCMM, */
/*  LSFT ,NUBS,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,SLSH, RO ,    RSFT,         UP ,         P1 , P2 , P3 ,PENT, */
/*  LCTL ,LGUI,LALT,MHEN,         SPC          ,HENK,KANA,RALT,RGUI,APP , RCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL  */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_NOMODS( \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
)

/* ------------------------------------------------------------------------------ #  ISO_A_  - Angle-ISO ergo mod # ---- */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL , -- ,BSPC                                           */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   BSLS                                           */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT                                            */
/*  LSFT ,  Z ,  X ,  C ,  V ,  B ,NUBS,  N ,  M ,COMM,DOT ,SLSH, -- ,    RSFT                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_ISO_A_( \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L1_Z,L2_X,L3_C,L4_V,L5_B,L0LG,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
)

/* ------------------------------------------------------------------------------ #  ISO_AW  - AngleWide(/)-ISO   # ---- */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,EQL ,  7 ,  8 ,  9 ,  0 ,MINS, -- ,BSPC                                           */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,LBRC,  Y ,  U ,  I ,  O ,  P ,SLSH,   BSLS                                           */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,RBRC,  H ,  J ,  K ,  L ,SCLN,QUOT,  ENT                                            */
/*  LSFT ,  Z ,  X ,  C ,  V ,  B ,NUBS,NUHS,  N ,  M ,COMM,DOT , -- ,    RSFT                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_ISO_AW( \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,NcEQ,N7_7,N8_8,N9_9,Na_0,NbMN,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,UbLB,U6_Y,U7_U,U8_I,U9_O,Ua_P,LaSL,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,UcRB,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L1_Z,L2_X,L3_C,L4_V,L5_B,L0LG,HcHS,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
)

/* ------------------------------------------------------------------------------ #  ANS_A_  - ANSI Angle-Z ergo  # ---- */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL , -- ,BSPC                                           */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   BSLS                                           */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT                                            */
/*  LSFT ,NUBS,  X ,  C ,  V ,  B ,  Z ,  N ,  M ,COMM,DOT ,SLSH, -- ,    RSFT                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_ANS_A_( \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L2_X,L3_C,L4_V,L5_B,L1_Z,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
)

/* ------------------------------------------------------------------------------ #  ANS_AW  - AngleWide(Z')-ANSI # ---- */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,EQL ,  7 ,  8 ,  9 ,  0 ,MINS, -- ,BSPC                                           */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,LBRC,  Y ,  U ,  I ,  O ,  P ,QUOT,   BSLS                                           */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,RBRC,  H ,  J ,  K ,  L ,SCLN,NUHS,  ENT                                            */
/*  LSFT ,NUBS,  X ,  C ,  V ,  B ,  Z ,SLSH,  N ,  M ,COMM,DOT , -- ,    RSFT                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_ANS_AW( \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,NcEQ,N7_7,N8_8,N9_9,Na_0,NbMN,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,UbLB,U6_Y,U7_U,U8_I,U9_O,Ua_P,HbQU,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,UcRB,H6_H,H7_J,H8_K,H9_L,HaSC,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L2_X,L3_C,L4_V,L5_B,L1_Z,LaSL,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
)

/* ------------------------------------------------------------------------------ #  AWINGA  - ANSI A-Wing ergo   # ---- */
/*  GRV ,EQL ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS, -- ,BSPC                                           */
/*  TAB   ,LBRC,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,QUOT,   BSLS                                           */
/*  FN1    ,RBRC,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,NUHS,  ENT                                            */
/*  LSFT ,NUBS,  Z ,  X ,  C ,  V ,  B ,SLSH,  N ,  M ,COMM,DOT , -- ,    RSFT                                           */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_AWINGA( \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,NcEQ,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,UbLB,UcRB,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HbQU,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LaSL,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    _F1_,_F2_,_F3_,_F4_,   _F5_,_F6_,_F7_,_F8_,   _F9_,F10_,F11_,F12_,   PSCR,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    GRV_,NcEQ,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,Na_0,NbMN,JYEN,BSPC,   INS_,HOME,PGUP,   NLCK,PSLS,PAST,PMNS,  \
    TAB_  ,UbLB,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,Ua_P,HbQU,   BSLS,   DEL_,END_,PGDN,   _P7_,_P8_,_P9_,PPLS,  \
    CAPS   ,UcRB,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HaSC,HcHS,  ENT_,                     _P4_,_P5_,_P6_,PCMM,  \
    LSFT ,L0LG,L1_Z,L2_X,L3_C,L4_V,L5_B,LaSL,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        _P1_,_P2_,_P3_,PENT,  \
    LCTL ,LGUI,LALT,JMHE,         SPC_         ,JHEN,JKAN,RALT,RGUI,APP_, RCTL,   LEFT,DOWN,RGHT,   _P0_     ,PDOT,PEQL   \
)

/*  NOTE: I used KEYMAP_ALL before, but have switched to the more universal Unimap.
 *      - To convert from USB-USB KEYMAP_ALL to UNIMAP, remove the rare right-hand block, PWR and HAEN/HANJ.
 *      - Some key tokens are different, but that doesn't matter (unless you mix formats in one macro).
 *      - All rare right-hand block keys [HELP/STOP/AGIN/MENU/UNDO/SLCT/COPY/EXEC/PSTE/FIND/CUT] are gone in Unimap
 *      - [PWR] K66 gone but [PCMM] K85 -> K66; [VOLD/VOLU/MUTE] K81/K80/K7F -> K01/K02/K03
 *      - [LCTL/LSFT/LALT/LGUI/RCTL/RSFT/RALT/RGUI] KE0/KE1/KE2/KE3/KE4/KE5/KE6/KE7 -> K78/K79/K7A/K7B/K7C/K7D/K7E/K7F
 *      - [HAEN/HANJ] K90/K91 (Korean) gone; [RO/KANA/JYEN/HENK/MHEN] K87/K88/K89/K8A/K8B -> K75/K00/K74/K76/K77
 *      - Korean special keys are missing in Unimap. Koreans could redefine, say, two of the Japanese keys to these?
 *      - In 2016-10, Hasu switched KP Enter and KP Equals (the equals is now below Enter) for Unimap.
 */

#endif
