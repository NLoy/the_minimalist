#include QMK_KEYBOARD_H
//#include "rgblight.h"
    /*
    *          A   B   C      D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R      S   T   U      V   W   X   Y  
    *        ┌───┬───┬───┬──┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬──┬───┬───┬───┬──┬───┬───┬───┬───┐
    * 1      │1A │ B │ C │  │ D │ E │ F │ G │ H │ I │ J │ K │ L │ M │ N │ O │ P │ Q │ R │  │ S │ T │ U │  │ V │ W │ X │ Y │
    *        ├───┼───┼───┤  ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┼───┤
    * 2      │2A │ B │ C │  │ D │ E │ F │ G │ H │ I │ J │ K │ L │ M │ N │ O │ P │ Q │ R │  │ S │ T │ U │  │ V │ W │ X │ Y │
    *        ├───┼───┼───┤  ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤  ├───┼───┼───┤  ├───┼───┼───┼───┤
    * 3      │3A │ B │ C │  │ D │ E │ F │ G │ H │ I │ J │ K │ L │ M │ N │ O │ P │ Q │ R │  │ S │ T │ U │  │ V │ W │ X │ Y │
    *        ├───┴───┴───┘  └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┴───┤
    *        ├───┬───┬───┐  ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐  ┌───┬───┬───┐  ┌───┬───┬───┬───┤
    * 4      │4A │ B │ C │  │DEL│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Q │ R │  │PRT│SLK│PAU│  │ V │ W │ X │ Y │
    *        ├───┴───┴───┘  └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘  └───┴───┴───┘  └───┴───┴───┴───┤
    *        │  68─67──66──65─64──63──62─61──60──59─58──57──56─55──54──53─52──51──50─49──48──47─46──45──44─43──42──41─40  │    === (29) WS12B LEDS INSET
    *        └────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
    *        ┌───┬───┬───┬──┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬──┬───┬───┬───┬──┬───┬───┬───┬───┐
    * 5   0  │5A │ B │ C │  │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │  BSPC │  │INS│HOM│PGU│  │NLK│ / │ * │ - │ 38
    *     |  ├───┼───┼───┤  ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤  ├───┼───┼───┤  ├───┼───┼───┼───┤ |
    * 6   1  │6A │ B │ C │  │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │  │DEL│END│PGD│  │ 7 │ 8 │ 9 │   │ 37
    *     |  ├───┼───┼───┤  ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤  ├───┼───┼───┤  ├───┼───┼───┤ + │ |
    * 7   2  │7A │ B │ C │  │ CAPS │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  ENTER │  │ S │ T │ U │  │ 4 │ 5 │ 6 │   │ 36
    *     |  ├───┼───┼───┤  ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤  ├───┼───┼───┤  ├───┼───┼───┼───┤ |
    * 8   3  │8A │ B │ C │  │ LSHFT  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   RSHFT  │  │ S │UP │ U │  │ 1 │ 2 │ 3 │   │ 35
    *     |  ├───┼───┼───┤  ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤  ├───┼───┼───┤  ├───┴───┼───┤ENT│ |
    * 9   4  │9A │ B │ C │  │CTRL│WIN │ALT │          SPACE         │ALT │WIN │MENU│CTRL│  │LT │DN │RT │  │   0   │ . │   │ 34
    *      \ └───┴───┴───┴──┴────┴────┴────┴────────────────────────┴────┴────┴────┴────┴──┴───┴───┴───┴──┴───────┴───┴───┘ /
    *        5───6──7──8──9──10──11──12──13──14──15──16──17──18──19──20──21──22──23──24──25──26──27──28──29──30──31──32───33   === (38) WS12B LEDS UNDER
    */


enum custom_keycodes {
    _ISOOBJ = SAFE_RANGE,
    _HIDOBJ,
    _UNIOBJ,
    _SENFRO,
    _SENBAC,
    _TXTFRO,
    _PSEL,
    _M2PPNT,
    _ENDPNT,
    _MIDPNT,
    _CENPNT,
    _GCENPT,
    _TANPNT,
    _PERPNT,
    _ACADFT,
    _3DMU,
    _3DMD,
    _3DML,
    _3DMR  //MARKER FOR END OF CUSTOM KEYCODES ENUM
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case _ISOOBJ:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\e\eISOLATEOBJECTS\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _HIDOBJ:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\e\eHIDEOBJECTS\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _UNIOBJ:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\e\eUNISOLATEOBJECTS\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _SENFRO:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\e\eAI_DRAWORDER\nFRONT\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _SENBAC:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\e\eAI_DRAWORDER\nBACK\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _TXTFRO:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\e\eTEXTTOFRONT\nA\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _PSEL:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\e\ePSEL\nP\n\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _M2PPNT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("M2P\n", 20);
        } else {
            // when keycode is released
        }
        break;
        
    case _ENDPNT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("END\n", 20);
        } else {
            // when keycode is released
        }
        break;
        
    case _MIDPNT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("MID\n", 20);
        } else {
            // when keycode is released
        }
        break;
        
    case _CENPNT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("CEN\n", 20);
        } else {
            // when keycode is released
        }
        break;
        
    case _GCENPT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("GCEN\n", 20);
        } else {
            // when keycode is released
        }
        break;

    case _TANPNT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("TAN\n", 20);
        } else {
            // when keycode is released
        }
        break;
        
    case _PERPNT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("PER\n", 20);
        } else {
            // when keycode is released
        }
        break;
               
    case _ACADFT:
        if (record->event.pressed) {
            SEND_STRING_DELAY("\'-", 20);
        } else {
            // when keycode is released
        }
        break; 
                       
    case _3DMU:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_BTN3);
            register_code(KC_MS_U);
        } else {
            // when keycode is released
            unregister_code(KC_MS_U);
            unregister_code(KC_BTN3);
            unregister_code(KC_LSFT);
        }
        break; 
        
    case _3DMD:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_BTN3);
            register_code(KC_MS_D);
        } else {
            // when keycode is released
            unregister_code(KC_MS_D);
            unregister_code(KC_BTN3);
            unregister_code(KC_LSFT);
        }
        break;
        
    case _3DML:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_BTN3);
            register_code(KC_MS_L);
        } else {
            // when keycode is released
            unregister_code(KC_MS_L);
            unregister_code(KC_BTN3);
            unregister_code(KC_LSFT);
        }
        break;
        
    case _3DMR:
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_BTN3);
            register_code(KC_MS_R);
        } else {
            // when keycode is released
            unregister_code(KC_MS_R);
            unregister_code(KC_BTN3);
            unregister_code(KC_LSFT);
        }
        break;  //MARKER FOR END OF CUSTOM KEYCODES DEFINITIONS

    }
    return true;
};

//SHORTENING LONGER KEYCODES INTO 8 CHARACTER ONES TO ALLOW FOR A CLEANER KEYMAP
#define B_ISOOBJ LT(_BLU,_ISOOBJ)
#define B_ENT LT(_BLU, KC_ENT)
#define ACAD_QUO RSFT(KC_QUOT)

enum layer_names {
    _BASE, // Base Layer
    _BLU, // Blue Layer
    _RED, // Red Layer
    _GRN, // Green Layer
    _YEL, // Yellow Layer
    _WHI // White Layer
};  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT( /* Base Layer */
    KC_1,    KC_B,    KC_C,            KC_D,    KC_E,    KC_F,    KC_G,    KC_H,    KC_I,    KC_J,    KC_K,    KC_L,    KC_M,    KC_N,    KC_O,    KC_P,    KC_Q,    KC_R,            KC_S,    KC_T,    KC_U,            KC_V,    KC_W,    KC_X,    KC_Y,
    KC_2,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   RESET,
    KC_3,   KC_NO,   KC_NO,         _M2PPNT, _ENDPNT, _MIDPNT, _CENPNT, _GCENPT, _TANPNT, _PERPNT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   MO(1),
    KC_4,   KC_NO,   KC_NO,          KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   KC_NO,   KC_NO,         KC_PSCR, KC_SLCK, KC_PAUS,           KC_NO,   KC_NO,   KC_NO,   KC_NO,

    KC_5,   KC_NO,   KC_NO,         KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,          KC_BSPC,          KC_INS, KC_HOME, KC_PGUP,         KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_6,   KC_NO,   KC_NO,          KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,          KC_BSLS,          KC_DEL,  KC_END, KC_PGDN,           KC_P7,   KC_P8,   KC_P9, KC_PPLS,
   _PSEL,   KC_NO,   KC_NO,         KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,                          MO(_YEL),MO(_GRN),MO(_RED),           KC_P4,   KC_P5,   KC_P6,
 _SENFRO, _SENBAC, _TXTFRO,         KC_LSFT,             KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,                          MO(_WHI),   KC_UP,MO(_BLU),           KC_P1,   KC_P2,   KC_P3,   B_ENT,
B_ISOOBJ, _HIDOBJ, _UNIOBJ,         KC_LCTL, KC_LGUI, KC_LALT,                             KC_SPC,                            KC_RALT, KC_RGUI,  KC_APP,          KC_RCTL,         KC_LEFT, KC_DOWN, KC_RGHT,           KC_P0,          KC_PDOT),

[_BLU] = LAYOUT( /* Blue Layer */
 QK_BOOT, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         RGB_TOG,RGB_RMOD, RGB_MOD, RGB_M_P,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_R,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         RGB_HUD, RGB_SAD, RGB_VAD,RGB_M_SW,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______, 

 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, KC_MS_U, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         KC_MS_L, KC_BTN3, KC_MS_R,
 _______, _______, _______,         _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, KC_VOLU, _______,         KC_BTN1, KC_MS_D, KC_BTN2, _______,
 _______, _______, _______,         _______, _______, _______,                            _______,                            _______, _______, _______,          _______,         KC_MPLY, KC_VOLD, KC_MNXT,         _ACADFT,         ACAD_QUO,

[_RED] = LAYOUT( /* Red Layer */
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______,   _3DMU, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,           _3DML,  KC_ESC,   _3DMR,
 _______, _______, _______,         _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         _______,   _3DMD, _______, _______,
 _______, _______, _______,         _______, _______, _______,                            _______,                            _______, _______, _______,          _______,         _______, _______, _______,         _______,          _______),

[_GRN] = LAYOUT( /* Green Layer */
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         _______, _______, _______,
 _______, _______, _______,         _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______,                            _______,                            _______, _______, _______,          _______,         _______, _______, _______,         _______,          _______),

[_YEL] = LAYOUT( /* Yellow Layer */
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         _______, _______, _______,
 _______, _______, _______,         _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______,                            _______,                            _______, _______, _______,          _______,         _______, _______, _______,         _______,          _______),

[_WHI] = LAYOUT( /* White Layer */
  QK_RBT, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______,
 
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,         _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         _______, _______, _______,
 _______, _______, _______,         _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,         _______, _______, _______, _______,
 _______, _______, _______,         _______, _______, _______,                            _______,                            _______, _______, _______,          _______,         _______, _______, _______,         _______,          _______)};



//Light up LEDS 50 to 68 in corresponding color when respective layer is active
const rgblight_segment_t PROGMEM _RGB_BASE[] = RGBLIGHT_LAYER_SEGMENTS({40, 29, HSV_OFF});
const rgblight_segment_t PROGMEM _RGB_BLUE[] = RGBLIGHT_LAYER_SEGMENTS({40, 29, HSV_BLUE});
const rgblight_segment_t PROGMEM _RGB_RED[] = RGBLIGHT_LAYER_SEGMENTS({40, 29, HSV_RED});
const rgblight_segment_t PROGMEM _RGB_GREEN[] = RGBLIGHT_LAYER_SEGMENTS({40, 29, HSV_GREEN});
const rgblight_segment_t PROGMEM _RGB_YELLOW[] = RGBLIGHT_LAYER_SEGMENTS({40, 29, HSV_YELLOW});
const rgblight_segment_t PROGMEM _RGB_WHITE[] = RGBLIGHT_LAYER_SEGMENTS({40, 29, HSV_WHITE});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    _RGB_BASE,     // 0 - Base layer
    _RGB_BLUE,     // 1 - Overrides base layer
    _RGB_RED,      // 2 - Overrides other layers
    _RGB_GREEN,    // 3 - Overrides other layers
    _RGB_YELLOW,   // 4 - Overrides other layers
    _RGB_WHITE     // 5 - Overrides other layers
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;     // Enable the LED layers
    rgblight_enable(); //Enables RGB on boot
//    rgblight_sethsv(HSV_OFF); //Turns off LEDS on boot
}
/* Disabled to prevent blocking RGBLIGHT effects when on base layer
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));    // Activate the _RGB_BASE layer on active base layer
    return state;
}
*/
// Activate the respective rgb layer according to the active keyboard layer+
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _BLU));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RED));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GRN));
    rgblight_set_layer_state(4, layer_state_cmp(state, _YEL));
    rgblight_set_layer_state(5, layer_state_cmp(state, _WHI));
return state;
}
