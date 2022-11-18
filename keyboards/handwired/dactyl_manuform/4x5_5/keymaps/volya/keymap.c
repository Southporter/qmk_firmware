// Copyright 2022 Shem Sedrick (@ssedrick)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

enum key_layers {
    _QWERTY,
    _COLEMAKDH,
    _RSTHD,
    _MEDIA,
    _NAV,
    _MOUSE,
    _SYM,
    _NUM,
    _FUN,
};

enum layer_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAKDH,
    RSTHD,
};


// Home row mods 
// QWERTY
#define ALT_A   MT(MOD_LALT,  KC_A)
#define GUI_S   MT(MOD_LGUI,  KC_S)
#define SHFT_D  MT(MOD_LSFT,  KC_D)
#define CTRL_F  MT(MOD_LCTL, KC_F)

#define CTRL_J  MT(MOD_RCTL, KC_J)
#define SHFT_K  MT(MOD_RSFT,  KC_K)
#define GUI_L   MT(MOD_RGUI,  KC_L)
#define ALT_CLN MT(MOD_LALT,  KC_SCLN)

// RSTHD
#define ALT_R   MT(MOD_LALT,  KC_R)
#define GUI_S   MT(MOD_LGUI,  KC_S)
#define SHFT_T  MT(MOD_LSFT,  KC_T)
#define CTRL_H  MT(MOD_LCTL, KC_H)

#define CTRL_N  MT(MOD_RCTL, KC_N)
#define SHFT_A  MT(MOD_RSFT,  KC_A)
#define GUI_I   MT(MOD_RGUI,  KC_I)
#define ALT_O   MT(MOD_LALT,  KC_O)

// Layer Toggles
#define E_NUM     LT(_NUM, KC_E)
#define MINS_NUM  LT(_NUM, KC_MINS)

#define BSPC_MS   LT(_MOUSE, KC_BSPC)
#define ESC_MEDIA LT(_MEDIA, KC_ESC)

#define TAB_NAV   LT(_NAV, KC_TAB)
#define SPC_SYM   LT(_SYM, KC_SPC)
#define ENT_FUN   LT(_FUN, KC_ENT)

#define NAV   TT(_NAV)
#define MOUSE TT(_MOUSE)
#define SYM   TT(_SYM)
#define NUM   TT(_NUM)
#define FUN   TT(_FUN)
#define UNDSC  RSFT(KC_MINS)
#define MAC_LOCK C(G(KC_Q))
#define ____   KC_TRANSPARENT
#define xxxx   KC_NO
#define REDO   LCTL(KC_Y)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                  ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                  |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                  |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                  |   n  |   m  |   ,  |   .  |   /  |
     * '------+------+------+-------------'                  '------+------+------+------+------'
     *        |  {   |   }  |                                              |   '  |  `~  |
     *        '-------------+------,                                ,------|-------------'
     *                      |  -   |                                | ENTER|
     *                      |-------------,                  ,------+------|
     *                      |      | BSPC |                  | SPACE|      |
     *                      |------+------|                  |------+------|
     *                      |      |  ESC |                  | TAB  |      |
     *                      '-------------'                  '-------------'
     */
    [_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        ALT_A,   GUI_S,   SHFT_D,  CTRL_F,  KC_G,             KC_H,    CTRL_J,  SHFT_K,  GUI_L,   ALT_CLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                 KC_LCBR, KC_RCBR,                                              KC_QUOT, KC_GRV,
                                ESC_MEDIA,                             ENT_FUN,
                                 MINS_NUM,  TAB_NAV,          BSPC_MS, SPC_SYM,
                                 xxxx,      xxxx,             xxxx,    xxxx
    ),

    /* COLEMAKDH
     * ,----------------------------------,                  ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                  |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                  |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                  |   n  |   m  |   ,  |   .  |   /  |
     * '------+------+------+-------------'                  '------+------+------+------+------'
     *        |  {   |   }  |                                              |   '  |  `~  |
     *        '-------------+------,                                ,------|-------------'
     *                      |  -   |                                | ENTER|
     *                      |-------------,                  ,------+------|
     *                      |      | BSPC |                  | SPACE|      |
     *                      |------+------|                  |------+------|
     *                      |      |  ESC |                  | TAB  |      |
     *                      '-------------'                  '-------------'
     */
    [_COLEMAKDH] = LAYOUT(
        KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_MINS,
        ALT_A,  GUI_S,   SHFT_D,  CTRL_F,  KC_G,             KC_H,    CTRL_J,  SHFT_K,  GUI_L,   ALT_CLN,
        KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                KC_LCBR, KC_RCBR,                                              KC_QUOT, KC_GRV,
                                ESC_MEDIA,                             ENT_FUN,
                                 MINS_NUM,  TAB_NAV,          BSPC_MS, SPC_SYM,
                                 xxxx,      xxxx,             xxxx,    xxxx
    ),


    /* RSTHD 
     * ,----------------------------------,                  ,----------------------------------,
     * |   j  |   c  |   y  |   f  |   k  |                  |   z  |   l  |   ,  |   u  |   q  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   r  |   s  |   t  |   h  |   d  |                  |   m  |   n  |   a  |   i  |   o  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   /  |   v  |   g  |   p  |   b  |                  |   x  |   w  |   .  |   ;  |   -  |
     * '------+------+------+-------------'                  '------+------+------+------+------'
     *        |  {   |   }  |                                              |   '  |  `~  |
     *        '-------------+------,                                ,------|-------------'
     *                      |  e   |                                | ENT  |
     *                      |-------------,                  ,------+------|
     *                      |      | BSPC |                  | SPACE|      |
     *                      |------+------|                  |------+------|
     *                      |      | ESC  |                  | TAB  |      |
     *                      '-------------'                  '-------------'
     */
    [_RSTHD] = LAYOUT(
        KC_J,    KC_C,    KC_Y,    KC_F,    KC_K,             KC_Z,    KC_L,    KC_COMM, KC_U,    KC_Q,
        ALT_R,   GUI_S,   SHFT_T,  CTRL_H,  KC_D,             KC_M,    CTRL_N,  SHFT_A,  GUI_I,   ALT_O,
        KC_SLSH, KC_V,    KC_G,    KC_P,    KC_B,             KC_X,    KC_W,    KC_DOT,  KC_SCLN, KC_MINS,
                 KC_LCBR, KC_RCBR,                                              KC_QUOT, KC_GRV,
                                ESC_MEDIA,                             ENT_FUN,
                                 E_NUM,   TAB_NAV,            BSPC_MS, SPC_SYM,
                                 xxxx,      xxxx,             xxxx,    xxxx
    ),

    /*  NAV
     * ,----------------------------------,                  ,----------------------------------,
     * |      |      |      |      |      |                  | REDO | PASTE| COPY |  CUT | UNDO |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |  ALT | GUI  | SHIFT| CTRL |      |                  |   <  |   v  |   ^  |   >  |CPS_WD|
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |      |      |      |      |      |                  |INSERT| HOME | PG UP|PG DWN| END  |
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |MAC_LC|      |                                              |QWERTY| RSTHD|
     *        '-------------+------,                                ,------|-------------'
     *                      |      |                                |      |
     *                      |-------------,                  ,------+------|
     *                      |      |      |                  |      |      |
     *                      |------+------|                  |------+------|
     *                      |      |      |                  |      |      |
     *                      '-------------'                  '-------------'
     */
    [_NAV] = LAYOUT(
        xxxx,    xxxx,    xxxx,    xxxx,    xxxx,             REDO, KC_PASTE,KC_COPY, KC_CUT,  KC_UNDO,
      KC_LALT, KC_LGUI, KC_LSFT,  KC_LCTRL, xxxx,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,
        xxxx,    xxxx,    xxxx,    xxxx,    xxxx,             KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,
             MAC_LOCK,    ____,                                                 QWERTY,  RSTHD,
                                   ____,                               ____,
                                   ____,    ____,             ____,    ____,
                                   ____,    ____,             ____,    ____
    ),

    /*  NUM
     * ,----------------------------------,                  ,----------------------------------,
     * |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |  ALT | GUI  | SHIFT| CTRL |      |                  |   =  |   4  |   5  |   6  |   ;  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |      |      |      |      |      |                  |   |  |   1  |   2  |   3  |   .  |
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |MAC_LC|      |                                              |   0  |   .  |
     *        '-------------+------,                                ,------|-------------'
     *                      |      |                                |  ]}  |
     *                      |-------------,                  ,------+------|
     *                      |      |      |                  |   0  |      |
     *                      |------+------|                  |------+------|
     *                      |      |      |                  |  [{  |      |
     *                      '-------------'                  '-------------'
     */
    [_NUM] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
       KC_LALT, KC_LGUI, KC_LSFT, KC_LCTRL, xxxx,             KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,
        xxxx,    xxxx,    xxxx,    xxxx,    xxxx,             KC_PIPE, KC_1,    KC_2,    KC_3,    KC_DOT,
             MAC_LOCK,    ____,                                                 KC_0,  KC_DOT,
                                   ____,                               KC_RBRC,
                                   ____,    ____,             KC_LBRC, KC_0,
                                   ____,    ____,             ____,    ____
    ),

    /*  MEDIA
     * ,----------------------------------,                  ,----------------------------------,
     * |      |      |      |      |      |                  |      |      | Mute |      |      |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |  ALT | GUI  | SHIFT| CTRL |      |                  |      |  |<  | VolUp|VolDwn| >|   |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |      |      |      |      |      |                  |      |      |      |      |      |
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |MAC_LC|      |                                              |QWERTY| RSTHD|
     *        '-------------+------,                                ,------|-------------'
     *                      |      |                                | STOP |
     *                      |-------------,                  ,------+------|
     *                      |      |      |                  | Play |      |
     *                      |------+------|                  |------+------|
     *                      |      |      |                  |      |      |
     *                      '-------------'                  '-------------'
     */
    [_MEDIA] = LAYOUT(
        xxxx,    xxxx,    xxxx,    xxxx,    xxxx,             xxxx,    xxxx,    KC_MUTE, xxxx,    xxxx,
        KC_LALT, KC_LGUI, KC_LSFT, KC_LCTRL,xxxx,             xxxx,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        xxxx,    xxxx,    xxxx,    xxxx,    xxxx,             xxxx,    xxxx,    xxxx,    xxxx,    xxxx,
                 ____,    ____,                                                 QWERTY,  RSTHD,
                                   ____,                               KC_MSTP,
                                   ____,    ____,             ____,    KC_MPLY,
                                   ____,    ____,             ____,    ____
    ),


    /*  MOUSE
     * ,----------------------------------,                  ,----------------------------------,
     * |SPEED2|ScrlUp|   ^  |ScrlDn|      |                  | BOOT |      |      |      |      |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |SPEED1|   <  |   v  |   >  |      |                  |      | CTRL | SHIFT|  GUI |  ALT |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |SPEED0|ScrlLf|      |ScrlRt|      |                  | RBT  |      |      |      |      |
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |      |      |                                              |      |      |
     *        '-------------+------,                                ,------|-------------'
     *                      |LftClk|                                |      |
     *                      |-------------,                  ,------+------|
     *                      |      |RgtClk|                  |      |      |
     *                      |------+------|                  |------+------|
     *                      |      |MdlClk|                  |      |      |
     *                      '-------------'                  '-------------'
     */
    [_MOUSE] = LAYOUT(
        KC_ACL2, KC_WH_U, KC_MS_U, KC_WH_D,  xxxx,         QK_BOOT,  xxxx,     xxxx,     xxxx,    xxxx,
        KC_ACL1, KC_MS_L, KC_MS_D, KC_LCTRL, xxxx,            xxxx,  KC_RCTRL, KC_RSFT, KC_RGUI, KC_RALT,
        KC_ACL0, KC_WH_L, xxxx,    KC_WH_R,  xxxx,          QK_RBT,  xxxx,     xxxx,     xxxx,    xxxx,
                 xxxx,    xxxx,                                                xxxx,     xxxx,
                                   KC_BTN1,                               ____,
                                   KC_BTN2,  KC_BTN3,         ____,   ____,
                                   ____,     ____,            ____,   ____
    ),

    /* SYM 
     * ,----------------------------------,                  ,----------------------------------,
     * |   !  |   @  |   #  |   $  |   %  |                  |   ^  |   &  |   *  |   (  |   )  |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |   |  |   _  |   (  |   )  |      |                  |      | CTRL | SHIFT|  GUI |  ALT |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * |      |      |   [  |   ]  |      |                  |      |      |      |      |      |
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |      |      |                                              |      |      |
     *        '-------------+------,                                ,------|-------------'
     *                      |   {  |                                |      |
     *                      |-------------,                  ,------+------|
     *                      |      |   }  |                  |      |      |
     *                      |------+------|                  |------+------|
     *                      |      |      |                  |      |      |
     *                      '-------------'                  '-------------'
     */
    [_SYM] = LAYOUT(
        S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
        KC_BSLS,S(KC_MINS),S(KC_9),S(KC_0), xxxx,             xxxx,  KC_RCTRL, KC_RSFT, KC_RGUI, KC_RALT,
        xxxx,    xxxx,    KC_LBRC, KC_RBRC, xxxx,             xxxx,  xxxx,     xxxx,     xxxx,    xxxx,
                 xxxx,    xxxx,                                                xxxx,     xxxx,
                                   S(KC_LBRC),                        ____,
                                   S(KC_RBRC), ____,          ____,   ____,
                                   ____,    ____,             ____,   ____
    ),

    /* FUN 
     * ,----------------------------------,                  ,----------------------------------,
     * | FN11 |  FN7 |  FN8 |  FN9 | FN14 |                  | BOOT | FN16 | FN17 | FN18 | FN19 |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * | FN10 |  FN4 |  FN5 |  FN6 | FN13 |                  | FN24 | CTRL | SHIFT|  GUI |  ALT |
     * |------+------+------+------+------|                  |------+------+------+------+------|
     * | FN12 |  FN1 |  FN2 |  FN3 | FN15 |                  | RBT  | FN20 | FN21 | FN22 | FN23 |
     * |------+------+------+-------------|                  |------+------+------+------+------,
     *        |      |      |                                              |      |      |
     *        '-------------+------,                                ,------|-------------'
     *                      |      |                                |      |
     *                      |-------------,                  ,------+------|
     *                      |      |      |                  |      |      |
     *                      |------+------|                  |------+------|
     *                      |      |      |                  |      |      |
     *                      '-------------'                  '-------------'
     */
    [_FUN] = LAYOUT(
        KC_F11, KC_F7,  KC_F8,  KC_F9,  KC_F14,              QK_BOOT, KC_F16,   KC_F17,   KC_F18,  KC_F19,
        KC_F10, KC_F4,  KC_F5,  KC_F6,  KC_F13,               KC_F24, KC_RCTRL, KC_RSFT, KC_RGUI, KC_RALT,
        KC_F12, KC_F1,  KC_F2,  KC_F3,  KC_F15,               QK_RBT, KC_F20,   KC_F21,   KC_F22,  KC_F23,
                xxxx,   xxxx,                                                xxxx,     xxxx,
                                   ____,                             ____,
                                   ____,  ____,              ____,   ____,
                                   ____,  ____,              ____,   ____
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("0x%04X\t%u\t%u\t0x%X\t%b\t0x%02X\t0x%02X\t%u\n",
         keycode,
         record->event.key.row,
         record->event.key.col,
         layer_state|default_layer_state,
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
         );
#endif
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case RSTHD:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_RSTHD);
            }
            return false;
            break;
    }
    return true;
}

