// Copyright 2022 Noah (@Noah)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */

//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT




#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xFADE
#define DEVICE_VER      0x0001
#define MANUFACTURER    qmkbuilder
#define PRODUCT         keyboard


/*
#define CAP_PINS                      \
    {                                 \
            LINE_PIN11, /* CAP_BLU */ \
            LINE_PIN12, /* CAP_RED */ \
            LINE_PIN24, /* CAP_GRN */ \
            LINE_PIN25, /* CAP_YEL */ \
            LINE_PIN26 /* CAP_WHI */ \
    }
*/

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 25

#define MATRIX_ROW_PINS             \
    {                               \
            LINE_PIN1, /* ROW_1 */  \
            LINE_PIN2, /* ROW_2 */  \
            LINE_PIN3, /* ROW_3 */  \
            LINE_PIN4, /* ROW_4 */  \
            LINE_PIN5, /* ROW_5 */  \
            LINE_PIN6, /* ROW_6 */  \
            LINE_PIN7, /* ROW_7 */  \
            LINE_PIN8, /* ROW_8 */  \
            LINE_PIN9, /* ROW_9 */  \
			LINE_PIN51 /* ROW_10*/  \
    }

#define MATRIX_COL_PINS             \
    {                               \
            LINE_PIN27, /* COL_A */ \
            LINE_PIN28, /* COL_B */ \
            LINE_PIN29, /* COL_C */ \
            LINE_PIN30, /* COL_D */ \
            LINE_PIN31, /* COL_E */ \
            LINE_PIN32, /* COL_F */ \
            LINE_PIN33, /* COL_G */ \
            LINE_PIN34, /* COL_H */ \
            LINE_PIN35, /* COL_I */ \
            LINE_PIN36, /* COL_J */ \
            LINE_PIN37, /* COL_K */ \
            LINE_PIN38, /* COL_L */ \
            LINE_PIN39, /* COL_M */ \
            LINE_PIN40, /* COL_N */ \
            LINE_PIN41, /* COL_O */ \
            LINE_PIN14, /* COL_P */ \
            LINE_PIN15, /* COL_Q */ \
            LINE_PIN16, /* COL_R */ \
            LINE_PIN17, /* COL_S */ \
            LINE_PIN18, /* COL_T */ \
            LINE_PIN19, /* COL_U */ \
            LINE_PIN20, /* COL_V */ \
            LINE_PIN21, /* COL_W */ \
            LINE_PIN22, /* COL_X */ \
            LINE_PIN23  /* COL_Y */ \
    }


/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
/* Well-worn Cherry MX key switches can bounce for up to 20ms, despite the
 * Cherry data sheet specifying 5ms. Because we use the sym_eager_pk debounce
 * algorithm, this debounce latency only affects key releases (not key
 * presses). */
#undef DEBOUNCE
#define DEBOUNCE 20


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define TAPPING_TERM 150
#define MOUSEKEY_MOVE_DELTA 2
#define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_INITIAL_SPEED 20

#define RGB_DI_PIN LINE_PIN0
#define RGBLED_NUM 69
#define NOP_FUDGE 1 //Doesn't need a fudge factor, but is required to compile, so just keep at 1
#define RGBLIGHT_SLEEP //If defined, the RGB lighting will be switched off when the host goes to sleep

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING //Default is RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_DEFAULT_HUE 21 //Orange
#define RGBLIGHT_DEFAULT_VAL 100 //100 of 255 default
#define RGBLIGHT_DEFAULT_SAT 0 //100 of 255 default
#define RGBLIGHT_DEFAULT_SPD 200 //100 of 255 default
#define RGBLIGHT_HUE_STEP 36
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
//#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_BREATHING
//#define RGBLIGHT_EFFECT_CHRISTMAS
//#define RGBLIGHT_EFFECT_KNIGHT
//#define RGBLIGHT_EFFECT_RAINBOW_MOODR
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#define RGBLIGHT_EFFECT_RGB TEST
//#define RGBLIGHT_EFFECT_SNAKE
//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#define RGBLIGHT_EFFECT_TWINKLE

#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 8
//#define RGBLIGHT_LAYERS_RETAIN_VAL //Allows RGB Layer brightness  to be bound to regular RGB brightness
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF //Allows RGB Layers to work even when the RGB lighting is otherwise off

#endif
