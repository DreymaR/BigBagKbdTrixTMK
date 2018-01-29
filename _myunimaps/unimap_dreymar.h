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
 * 2016- Øystein "DreymaR" Gadmar: AngleWide ergonomic keyboard mods as keymap types
 * See the Colemak Forum (DreymaR's Big Bag of Keyboard Tricks) for info
 * http://forum.colemak.com/viewtopic.php?id=2158
 */

/*         ,---------------. ,---------------. ,---------------.                UNIMAP w/ QWERTY
 *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 * ,---.   |---------------| |---------------| |---------------| ,-----------.     ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|     |VDn|VUp|Mut|
 * `---'   `---------------' `---------------' `---------------' `-----------'     `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|BSp| |Ins|Hom|PgU| |NLk|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |---------------|
 * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |               |  4|  5|  6|  ,|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * | Sft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|  Sft |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |---------------|
 * | Ctrl|Gui|Alt|MHE|     Space     |HEN|KAN|Alt|Gui|App|Ctrl | |Lft|Dwn|Rgh| |      0|  .|  =|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */

/*         ,---------------. ,---------------. ,---------------.                KEYMAP_ALL w/ QWERTY
 *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
 * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|BSp| |Ins|Hom|PgU| |NLk|  /|  *|  -| |Stp|Agn|
 * |-----------------------------------------------------------| |-----------| |---------------| |-------|
 * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
 * |-----------------------------------------------------------| `-----------' |---------------| |-------|
 * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |               |  4|  5|  6|  ,| |Sel|Cpy|
 * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
 * | Sft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| RO|  Sft |     |Up |     |  1|  2|  3|  =| |Exe|Pst|
 * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
 * | Ctrl|Gui|Alt|MHE|HNJ| Space |H/E|HEN|KAN|Alt|Gui|App|Ctrl | |Lft|Dwn|Rgh| |      0|  .|Ent| |Fnd|Cut|
 * `-----------------------------------------------------------' `-----------' `---------------' `-------'
 */

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.  KEYMAP_ISO 
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|  w/ QWERTY
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  BSpc | |Ins|Hom|PgU| |NLk|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Ent | |Del|End|PgD| |  7|  8|  9|  +|
 * |------------------------------------------------------`    | `-----------' |-----------|   |
 * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|    |               |  4|  5|  6|   |
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * | Sft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|    Shift |     |Up |     |  1|  2|  3|Ent|
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * | Ctrl|LGui|LAlt|        Space         |RAlt|RGui|App |Ctrl | |Lft|Dwn|Rgh| |      0|  .|   |
 * `-----------------------------------------------------------' `-----------' `---------------'
 */


/* ***** CONFIG ******************************************************************************************************** */
/* ***** Extra includes/definitions                                                         ***** */
/* For the FourLvl user function, action_util.h is needed: */
#include "action_util.h"

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
/*           F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                          */
/*  ESC ,     F1 , F2 , F3 , F4 ,    F5 , F6 , F7 , F8 ,    F9 ,F10 ,F11 ,F12 ,   PSCR,SLCK,PAUS,        VOLD,VOLU,MUTE, */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL ,JYEN,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS, */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS, */
/*  CAPS   ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT ,                      P4 , P5 , P6 ,PCMM, */
/*  LSFT ,NUBS,  Z ,  X ,  C ,  V ,  B ,  N ,  M ,COMM,DOT ,SLSH, RO ,    RSFT,         UP ,         P1 , P2 , P3 ,PENT, */
/*  LCTL ,LGUI,LALT,MHEN,         SPC          ,HENK,KANA,RALT,RGUI,APP , RCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL  */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_UNMODDED( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)

/* ------------------------------------------------------------------------------ # ANIZXCVB - Angle-ISO ergo mod # ---- */
/*  ESC ,      F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,        PSCR,SLCK,PAUS,        VOLD,VOLU,MUTE, */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL , -- ,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS, */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS, */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT ,                      P4 , P5 , P6 , -- , */
/*  LSFT ,  Z ,  X ,  C ,  V ,  B ,NUBS,  N ,  M ,COMM,DOT ,SLSH, -- ,    RSFT,         UP ,         P1 , P2 , P3 ,PENT, */
/*  LCTL ,LGUI,LALT, -- ,         SPC          , -- , -- ,RALT,RGUI,APP , RCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT, --   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_ANIZXCVB( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,L1_Z,L2_X,L3_C,L4_V,L5_B,LSGT,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)
/* ------------------------------------------------------------------------------ # ANIZXCBV - Angle-ISO ergo mod # ---- */
/* ------------------------------------------------------------------------------ # for use with Colemak Curl(DH) # ---- */
#define UNIMAP_ANIZXCBV( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,L1_Z,L2_X,L3_C,L5_B,L4_V,LSGT,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)

/* ------------------------------------------------------------------------------ # AWIZXCVB - AngleWide(/) ergo  # ---- */
/*  ESC ,      F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,        PSCR,SLCK,PAUS,        VOLD,VOLU,MUTE, */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,EQL ,  7 ,  8 ,  9 ,  0 ,MINS, -- ,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS, */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,LBRC,  Y ,  U ,  I ,  O ,  P ,SLSH,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS, */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,RBRC,  H ,  J ,  K ,  L ,SCLN,QUOT,  ENT ,                      P4 , P5 , P6 , -- , */
/*  LSFT ,  Z ,  X ,  C ,  V ,  B ,NUBS,NUHS,  N ,  M ,COMM,DOT , -- ,    RSFT,         UP ,         P1 , P2 , P3 ,PENT, */
/*  LCTL ,LGUI,LALT, -- ,         SPC          , -- , -- ,RALT,RGUI,APP , RCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT, --   */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_AWIZXCVB( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,NCEQ,N7_7,N8_8,N9_9,NA_0,NBMN,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,UBLB,U6_Y,U7_U,U8_I,U9_O,UA_P,LASL,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,UCRB,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,L1_Z,L2_X,L3_C,L4_V,L5_B,LSGT,HCHS,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)
/* ------------------------------------------------------------------------------ # AWIZXCBV - AngleWide(/) ergo  # ---- */
/* ------------------------------------------------------------------------------ # for use with Colemak Curl(DH) # ---- */
#define UNIMAP_AWIZXCBV( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,NCEQ,N7_7,N8_8,N9_9,NA_0,NBMN,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,UBLB,U6_Y,U7_U,U8_I,U9_O,UA_P,LASL,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,UCRB,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,L1_Z,L2_X,L3_C,L5_B,L4_V,LSGT,HCHS,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)

/* ------------------------------------------------------------------------------ # ANAXCVBZ - ANSI Angle-Z ergo  # ---- */
/*  ESC ,      F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,        PSCR,SLCK,PAUS,        VOLD,VOLU,MUTE, */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS,EQL , -- ,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS, */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,LBRC,RBRC,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS, */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,QUOT,NUHS,  ENT ,                      P4 , P5 , P6 ,PCMM, */
/*  LSFT ,NUBS,  X ,  C ,  V ,  B ,  Z ,  N ,  M ,COMM,DOT ,SLSH, -- ,    RSFT,         UP ,         P1 , P2 , P3 ,PENT, */
/*  LCTL ,LGUI,LALT, -- ,         SPC          , -- , -- ,RALT,RGUI,APP , RCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL  */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_ANAXCVBZ( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L2_X,L3_C,L4_V,L5_B,L1_Z,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)
/* ------------------------------------------------------------------------------ # ANAXCBVZ - ANSI Angle-Z ergo  # ---- */
/* ------------------------------------------------------------------------------ # for use with Colemak Curl(DH) # ---- */
#define UNIMAP_ANAXCBVZ( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L2_X,L3_C,L5_B,L4_V,L1_Z,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)

/* ------------------------------------------------------------------------------ # AWAXCVBZ - ANSI AngleWide(Z') # ---- */
/*  ESC ,      F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,        PSCR,SLCK,PAUS,        VOLD,VOLU,MUTE, */
/*  GRV ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,EQL ,  7 ,  8 ,  9 ,  0 ,MINS, -- ,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS, */
/*  TAB   ,  Q ,  W ,  E ,  R ,  T ,LBRC,  Y ,  U ,  I ,  O ,  P ,QUOT,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS, */
/*  FN1    ,  A ,  S ,  D ,  F ,  G ,RBRC,  H ,  J ,  K ,  L ,SCLN,NUHS,  ENT ,                      P4 , P5 , P6 ,PCMM, */
/*  LSFT ,NUBS,  X ,  C ,  V ,  B ,  Z ,SLSH,  N ,  M ,COMM,DOT , -- ,    RSFT,         UP ,         P1 , P2 , P3 ,PENT, */
/*  LCTL ,LGUI,LALT, -- ,         SPC          , -- , -- ,RALT,RGUI,APP , RCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL  */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_AWAXCVBZ( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,NCEQ,N7_7,N8_8,N9_9,NA_0,NBMN,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,UBLB,U6_Y,U7_U,U8_I,U9_O,UA_P,HBQU,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,UCRB,H6_H,H7_J,H8_K,H9_L,HASC,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L2_X,L3_C,L4_V,L5_B,L1_Z,LASL,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)
/* ------------------------------------------------------------------------------ # AWAXCBVZ - ANSI AngleWide(Z') # ---- */
/* ------------------------------------------------------------------------------ # for use with Colemak Curl(DH) # ---- */
#define UNIMAP_AWAXCBVZ( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,NCEQ,N7_7,N8_8,N9_9,NA_0,NBMN,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,UBLB,U6_Y,U7_U,U8_I,U9_O,UA_P,HBQU,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,UCRB,H6_H,H7_J,H8_K,H9_L,HASC,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L2_X,L3_C,L5_B,L4_V,L1_Z,LASL,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)

/* ------------------------------------------------------------------------------ # ANAAWING - ANSI A-Wing ergo   # ---- */
/*  ESC ,      F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,        PSCR,SLCK,PAUS,        VOLD,VOLU,MUTE, */
/*  GRV ,EQL ,  1 ,  2 ,  3 ,  4 ,  5 ,  6 ,  7 ,  8 ,  9 ,  0 ,MINS, -- ,BSPC,   INS ,HOME,PGUP,   NLCK,PSLS,PAST,PMNS, */
/*  TAB   ,LBRC,  Q ,  W ,  E ,  R ,  T ,  Y ,  U ,  I ,  O ,  P ,QUOT,   BSLS,   DEL ,END ,PGDN,    P7 , P8 , P9 ,PPLS, */
/*  FN1    ,RBRC,  A ,  S ,  D ,  F ,  G ,  H ,  J ,  K ,  L ,SCLN,NUHS,  ENT ,                      P4 , P5 , P6 ,PCMM, */
/*  LSFT ,NUBS,  Z ,  X ,  C ,  V ,  B ,SLSH,  N ,  M ,COMM,DOT , -- ,    RSFT,         UP ,         P1 , P2 , P3 ,PENT, */
/*  LCTL ,LGUI,LALT, -- ,         SPC          , -- , -- ,RALT,RGUI,APP , RCTL,   LEFT,DOWN,RGHT,    P0      ,PDOT,PEQL  */
/* --------------------------------------------------------------------------------------------------------------------- */
#define UNIMAP_ANAAWING( \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,NCEQ,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,UBLB,UCRB,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HBQU,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,L6_N,L7_M,L8CM,L9DT,LASL,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
) UNIMAP( \
             F13 ,F14 ,F15 ,F16 ,   F17 ,F18 ,F19 ,F20 ,   F21 ,F22 ,F23 ,F24 ,                                           \
    ESC_,    FK01,FK02,FK03,FK04,   FK05,FK06,FK07,FK08,   FK09,FK10,FK11,FK12,   PRSC,SCLK,PAUS,        VOLD,VOLU,MUTE,  \
    TLDE,NCEQ,N1_1,N2_2,N3_3,N4_4,N5_5,N6_6,N7_7,N8_8,N9_9,NA_0,NBMN,JYEN,BKSP,   INS_,HOME,PGUP,   NMLK,KPDV,KPMU,KPMN,  \
    TAB_  ,UBLB,U1_Q,U2_W,U3_E,U4_R,U5_T,U6_Y,U7_U,U8_I,U9_O,UA_P,HBQU,   BKSL,   DEL_,END_,PGDN,   KP_7,KP_8,KP_9,KPAD,  \
    CAPS   ,UCRB,H1_A,H2_S,H3_D,H4_F,H5_G,H6_H,H7_J,H8_K,H9_L,HASC,HCHS,  RTRN,                     KP_4,KP_5,KP_6,KPCM,  \
    LSFT ,LSGT,L1_Z,L2_X,L3_C,L4_V,L5_B,LASL,L6_N,L7_M,L8CM,L9DT,JROM,    RSFT,        _UP_,        KP_1,KP_2,KP_3,KPEN,  \
    LCTL ,LWIN,LALT,JMHE,         SPCE         ,JHEN,JKAN,RALT,RWIN,MENU, RCTL,   LEFT,DOWN,RGHT,   KP_0     ,KPDT,KPEQ   \
)

/* NOTE: I used KEYMAP_ALL before, but have switched to the more universal Unimap.
 *       - To convert from USB-USB KEYMAP_ALL to UNIMAP, remove the rare right-hand block, PWR and HAEN/HANJ.
 *       - Some key tokens are different, but that doesn't matter (unless you mix formats in one macro).
 *       - All rare right-hand block keys [HELP/STOP/AGIN/MENU/UNDO/SLCT/COPY/EXEC/PSTE/FIND/CUT] are gone in Unimap
 *       - [PWR] K66 gone but [PCMM] K85 -> K66; [VOLD/VOLU/MUTE] K81/K80/K7F -> K01/K02/K03
 *       - [LCTL/LSFT/LALT/LGUI/RCTL/RSFT/RALT/RGUI] KE0/KE1/KE2/KE3/KE4/KE5/KE6/KE7 -> K78/K79/K7A/K7B/K7C/K7D/K7E/K7F
 *       - [HAEN/HANJ] K90/K91 (Korean) gone; [RO/KANA/JYEN/HENK/MHEN] K87/K88/K89/K8A/K8B -> K75/K00/K74/K76/K77
 *       - Korean special keys are missing in Unimap. Koreans could redefine, say, two of the Japanese keys to these?
 * DONE: In 2016-10, Hasu switched KP Enter and KP Equals (the equals is now below Enter) for Unimap.
 */

#endif
