#include QMK_KEYBOARD_H

#define _BASE 0
#define _NUM  1
#define _FUN  2
#define _CURS 3
#define _BRAC 4

/* Custom keys of layer Base */
#define MY_A MT(MOD_LGUI, KC_A)
#define MY_O MT(MOD_LALT, KC_O)
#define MY_E MT(MOD_LSFT, KC_E)
#define MY_U MT(MOD_LCTL, KC_U)

#define MY_ENT LT(_NUM, KC_ENTER)
#define MY_TAB LT(_FUN, KC_TAB)

#define MY_H MT(MOD_RCTL, KC_H)
#define MY_T MT(MOD_RSFT, KC_T)
#define MY_N MT(MOD_RALT, KC_N)
#define MY_S MT(MOD_RGUI, KC_S)

#define MY_BSPC LT(_BRAC, KC_BSPC)
#define MY_SPC LT(_CURS, KC_SPC)

/* Custom keys of layer Numeric */
#define MY_EQL MT(MOD_LGUI, KC_EQL)
#define MY_SLSH MT(MOD_LALT, KC_SLSH)
#define MY_BSLS MT(MOD_LSFT, KC_BSLS)
#define MY_PAST MT(MOD_LCTL, KC_PAST)

#define MY_4 MT(MOD_RCTL, KC_4)
#define MY_5 MT(MOD_RSFT, KC_5)
#define MY_6 MT(MOD_RALT, KC_6)
#define MY_0 MT(MOD_RGUI, KC_0)

/* Macros */
enum custom_keycodes {
    M_USER = SAFE_RANGE,
    M_MAIL,
    M_GREE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,-----------------------------.           ,-----------------------------.
 * |  ;  |  ,  |  .  |  P  |  Y  |           |  F  |  G  |  C  |  R  |  L  |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |  A  |  O  |  E  |  U  |  I  |           |  D  |  H  |  T  |  N  |  S  |
 * | GUI | Alt |Shift|Ctrl |     |           |     |Ctrl |Shift| Alt | GUI |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |  '  |  Q  |  J  |  K  |  X  |           |  B  |  M  |  W  |  V  |  Z  |
 * `-----------------------------'           `-----------------------------'
 *                ,-----------------.     ,-----------------.
 *                | Esc |Enter| TAB |     |BSPC |Space| Del |
 *                |     |NUMB | FUN |     |BRAC |CURS |     |
 *                `-----------|     |     |     |-----+-----'
 *                            `-----'     `-----'
 */
[_BASE] = LAYOUT_split_3x5_3( \
  KC_SCLN,  KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,    KC_G,   KC_C, KC_R, KC_L, \
  MY_A,     MY_O,    MY_E,    MY_U,    KC_I,         KC_D,    MY_H,   MY_T, MY_N, MY_S, \
  KC_QUOTE, KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,   KC_W, KC_V, KC_Z, \
                     KC_ESC,  MY_ENT,  MY_TAB,       MY_BSPC, MY_SPC, KC_DEL            \
),

/* NUM
 * ,-----------------------------.           ,-----------------------------.
 * |  !  |  @  |  $  |  ?  |  &  |           |  -  |  7  |  8  |  9  |  %  |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |  =  |  /  |  \  |  *  |  _  |           |  +  |  4  |  5  |  6  |  0  |
 * | GUI | Alt |Shift|Ctrl |     |           |     |Ctrl |Shift| Alt | GUI |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |  |  |  ^  |  ~  |  #  |  "  |           |     |  1  |  2  |  3  |     |
 * `-----------------------------'           `-----------------------------'
 *                ,-----------------.     ,-----------------.
 *                |     |     |     |     |     |     |     |
 *                |     |     |     |     |     |     |     |
 *                `-----------|     |     |     |-----+-----'
 *                            `-----'     `-----'
 */
[_NUM] = LAYOUT_split_3x5_3( \
  KC_EXLM, KC_AT,   KC_DLR,  KC_QUES, KC_AMPR,      KC_MINS, KC_7, KC_8, KC_9, KC_PERC, \
  MY_EQL,  MY_SLSH, MY_BSLS, MY_PAST, KC_UNDS,      KC_PPLS, MY_4, MY_5, MY_6, MY_0,    \
  KC_PIPE, KC_CIRC, KC_TILD, KC_HASH, KC_DQUO,      KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, \
                    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS           \
),

/* FUN
 * ,-----------------------------.           ,-----------------------------.
 * |     |     |     |     |     |           |Menu | F5  | F6  | F7  | F8  |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * | GUI | Alt |Shift|Ctrl |CAPS |           |Inser| F1  | F2  | F3  | F4  |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     | F9  | F10 | F11 | F12 |
 * `-----------------------------'           `-----------------------------'
 *                ,-----------------.     ,-----------------.
 *                |     |     |     |     |     |     |     |
 *                |     |     |     |     |     |     |     |
 *                `-----------|     |     |     |-----+-----'
 *                            `-----'     `-----'
 */
[_FUN] = LAYOUT_split_3x5_3( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_APP,  KC_F5, KC_F6,  KC_F7,  KC_F8,  \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_LCAP,      KC_INS,  KC_F1, KC_F2,  KC_F3,  KC_F4,  \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, \
                    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS               \
),

/* CURS
 * ,-----------------------------.           ,-----------------------------.
 * |     |     |     |     |Vol+ |           |PgUp |Home | Up  | End |     |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * | GUI | Alt |Shift|Ctrl |Vol- |           |PgDw |Left |Down |Right|     |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------'           `-----------------------------'
 *                ,-----------------.     ,-----------------.
 *                |     |     |     |     |     |     |     |
 *                |     |     |     |     |     |     |     |
 *                `-----------|     |     |     |-----+-----'
 *                            `-----'     `-----'
 */
[_CURS] = LAYOUT_split_3x5_3( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,      KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_VOLD,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS                    \
),

/* BRACKETS
 * ,-----------------------------.           ,-----------------------------.
 * |     |     |     |     |     |           |     | MP1 | MP2 |     |     |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |     |  {  |  [  | (   |     |           |     |  )  |  ]  |  }  |     |
 * |-----+-----+-----+-----+-----|           |-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     | MR1 | MR2 | MRS |     |
 * `-----------------------------'           `-----------------------------'
 *                ,-----------------.     ,-----------------.
 *                |     |     |     |     |     |     |     |
 *                |     |     |     |     |     |     |     |
 *                `-----------|     |     |     |-----+-----'
 *                            `-----'     `-----'
 */
[_BRAC] = LAYOUT_split_3x5_3( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, DM_PLY1, DM_PLY2, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_LCBR, KC_LBRC, KC_LPRN, KC_TRNS,      KC_TRNS, KC_RPRN, KC_RBRC, KC_RCBR, KC_TRNS, \
  KC_TRNS, M_USER,  M_MAIL,  M_GREE,  KC_TRNS,      KC_TRNS, DM_REC1, DM_REC2, DM_RSTP, KC_TRNS, \
                    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS                    \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_USER:
            if (record->event.pressed) {
                SEND_STRING("emanuelefirmani");
            }
            break;
        case M_MAIL:
            if (record->event.pressed) {
                SEND_STRING("emanuelefirmani@kpmg.com");
            }
            break;
        case M_GREE:
            if (record->event.pressed) {
                SEND_STRING("Thanks\nCiao\nEmanuele");
            }
            break;
    }
    return true;
};