#include QMK_KEYBOARD_H

#define _BASE 0
#define _SPCH 1
#define _NUM  2
#define _FUN  3
#define _CURS 4
#define _BRAC 5

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

/* Custom keys of layer Special Chars */
#define MY_EQL MT(MOD_LGUI, KC_EQL)
#define MY_COMM MT(MOD_LALT, KC_SLSH)
#define MY_SCLN MT(MOD_LSFT, KC_BSLS)
#define MY_DOT MT(MOD_LCTL, KC_PAST)

#define MY_Q MT(MOD_RCTL, KC_4)
#define MY_J MT(MOD_RSFT, KC_5)
#define MY_SLSH MT(MOD_RALT, KC_6)
#define MY_BSLS MT(MOD_RGUI, KC_0)

/* Custom keys of layer Numeric */
#define MY_F1 MT(MOD_LGUI, KC_EQL)
#define MY_F2 MT(MOD_LALT, KC_SLSH)
#define MY_F3 MT(MOD_LSFT, KC_BSLS)
#define MY_F4 MT(MOD_LCTL, KC_PAST)

#define MY_4 MT(MOD_RCTL, KC_4)
#define MY_5 MT(MOD_RSFT, KC_5)
#define MY_6 MT(MOD_RALT, KC_6)
#define MY_0 MT(MOD_RGUI, KC_0)

/* Custom keys of layer Cursor */
#define MY_LEFT MT(MOD_RCTL, KC_4)
#define MY_DOWN MT(MOD_RSFT, KC_5)
#define MY_RGHT MT(MOD_RALT, KC_6)
#define MY_PGDN MT(MOD_RGUI, KC_0)


/* Macros */
enum custom_keycodes {
    M_USER = SAFE_RANGE,
    M_MAIL,
    M_GREE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ,-------------------------.     ,-------------------------.
 * |  F  |  D  |  I  |  P  | |     | |  G  |  C  |  R  |  L  |
 * |-----+-----+-----+-----+-|     |-+-----+-----+-----+-----|
 * |  A  |  O  |  E  |  U  | |     | |  H  |  T  |  N  |  S  |
 * | GUI | Alt |Shift|Ctrl | |     | |Ctrl |Shift| Alt | GUI |
 * |-----+-----+-----+-----+-|     |-+-----+-----+-----+-----|
 * |  B  |  Y  |  K  |  X  | |     | |  M  |  W  |  V  |  Z  |
 * `-------------------------'     `-------------------------'
 *         ,-----------------.     ,-----------------.
 *         |     |Enter| TAB |     |BSPC |Space|     |
 *         |     |NUMB | FUN |     |BRAC |CURS |     |
 *         `-----------|     |     |     |-----+-----'
 *                     `-----'     `-----'
 */
[_BASE] = LAYOUT_split_3x5_3( \
  KC_F, KC_D, KC_I, KC_P, KC_TRNS,      KC_TRNS, KC_G, KC_C, KC_R, KC_L, \
  MY_A, MY_O, MY_E, MY_U, KC_TRNS,      KC_TRNS, MY_H, MY_T, MY_N, MY_S, \
  KC_B, KC_Y, KC_K, KC_X, KC_TRNS,      KC_TRNS, KC_M, KC_W, KC_V, KC_Z, \
          KC_TRNS, MY_ENT, MY_TAB,      MY_BSPC, MY_SPC, KC_TRNS         \
),

/* _SPCH
 * ,-------------------------.           ,-------------------------.
 * |  !  |  @  |  $  |  ?  | |           | |  *  |  |  |  _  |  %  |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * |  =  |  ,  |  ;  |  .  | |           | |  Q  |  J  |  /  |  \  |
 * | GUI | Alt |Shift|Ctrl | |           | |Ctrl |Shift| Alt | GUI |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * |  '  |  "  |  `  |  #  | |           | |  &  |  ^  |  ~  |     |
 * `-------------------------'           `-------------------------'
 */
[_SPCH] = LAYOUT_split_3x5_3( 
  KC_EXLM,  KC_AT,   KC_DLR,   KC_QUES, KC_TRNS,      KC_TRNS, KC_PAST, KC_PIPE, KC_UNDS, KC_PERC, \
  MY_EQL,   MY_COMM, MY_SCLN,  MY_DOT,  KC_TRNS,      KC_TRNS, MY_Q,    MY_J,    MY_SLSH, MY_BSLS, \
  KC_QUOTE, KC_DQUO, KC_GRAVE, KC_HASH, KC_TRNS,      KC_TRNS, KC_AMPR, KC_CIRC, KC_TILD, KC_TRNS,  \
                     KC_TRNS,  KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS                    \
),


/* NUM
 * ,-------------------------.           ,-------------------------.
 * | F5  | F6  | F7  | F8  | |           | |  7  |  8  |  9  |  +  |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * | F1  | F2  | F3  | F4  | |           | |  4  |  5  |  6  |  0  |
 * | GUI | Alt |Shift|Ctrl | |           | |Ctrl |Shift| Alt | GUI |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * | F9  | F10 | F11 | F12 | |           | |  1  |  2  |  3  |  -  |
 * `-------------------------'           `-------------------------'
 */
[_NUM] = LAYOUT_split_3x5_3( \
  KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_TRNS,      KC_TRNS, KC_7, KC_8, KC_9, KC_PPLS, \
  MY_F1, MY_F2,  MY_F3,  MY_F4,  KC_TRNS,      KC_TRNS, MY_4, MY_5, MY_6, MY_0,    \
  KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,      KC_TRNS, KC_1, KC_2, KC_3, KC_MINS, \
               KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS           \
),

/* CURS
 * ,-------------------------.           ,-------------------------.
 * |Vol+ |     | Esc | Del | |           | |Home | Up  | End |PgUp |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * | GUI | Alt |Shift|Ctrl | |           | |Left |Down |Right|PgDw |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * |Vol- |     |Inser|Menu | |           | |     |     |     |     |
 * `-------------------------'           `-------------------------'
 */
[_CURS] = LAYOUT_split_3x5_3( \
  KC_VOLU, KC_TRNS, KC_ESC,  KC_DEL,  KC_TRNS,      KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, \
  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS,      KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, \
  KC_VOLD, KC_TRNS, KC_INS,  KC_APP,  KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                    KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS                    \
),

/* BRACKETS
 * ,-------------------------.           ,-------------------------.
 * |     |     |     |     | |           | | MP1 | MP2 |     |     |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * |  <  |  {  |  [  | (   | |           | |  )  |  ]  |  }  |  >  |
 * |-----+-----+-----+-----+-|           |-+-----+-----+-----+-----|
 * |     |User |Email|Greet| |           | | MR1 | MR2 | MRS |     |
 * `-------------------------'           `-------------------------'
 */
[_BRAC] = LAYOUT_split_3x5_3( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, DM_PLY1, DM_PLY2, KC_TRNS, KC_TRNS, \
  KC_LT,   KC_LCBR, KC_LBRC, KC_LPRN, KC_TRNS,      KC_TRNS, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT,   \
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