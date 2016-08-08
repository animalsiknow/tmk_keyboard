#define PCBDOWN

#include "keymap_common.h"

//    !     @     {     }     "       ||       _     7     8     9    *
//    #     $     (     )     '       ||       -     4     5     6    +
//    %     ^     [     ]     ~       ||       &     1     2     3  backsl
//    |     `   super shift bksp ctrl || alt space         .     0    =

// L2 has the arrows:

//  insert home    ↑    end  pgup     ||       ↑     F7    F8    F9   F10
//    del   ←     ↓     →  pgdn     ||       ↓     F4    F5    F6   F11
//                                    ||             F1    F2    F3   F12
//  reset       super shift bksp ctrl || alt space   L0             reset

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP(
    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,               \
    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,            \
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,       \
    KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,              \
    KC_SPC, KC_FN0, KC_FN1, KC_NO, KC_ENT),                                   \
  KEYMAP(
    SHIFT(KC_1), SHIFT(KC_2), SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_QUOT), \
    SHIFT(KC_MINS), KC_7, KC_8, KC_9, SHIFT(KC_8),                            \
    SHIFT(KC_3), SHIFT(KC_4), SHIFT(KC_9), SHIFT(KC_0), KC_QUOT,              \
    KC_MINS, KC_4, KC_5, KC_6, SHIFT(KC_EQUAL),                               \
    SHIFT(KC_5), SHIFT(KC_6), KC_LBRC, KC_RBRC, SHIFT(KC_GRAVE),              \
    SHIFT(KC_7), KC_1, KC_2, KC_3, KC_BSLS,                                   \
    SHIFT(KC_BSLS), KC_GRAVE, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT,    \
    KC_SPC, KC_FN0, KC_FN1, KC_0, KC_EQUAL),
  KEYMAP(
    KC_INS, KC_HOME, KC_UP, KC_END, KC_PGUP,                                  \
    KC_UP, KC_F7, KC_F8, KC_F9, KC_F10,                                       \
    KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,                              \
    KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11,                                     \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                            \
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,                                       \
    KC_FN2, KC__VOLDOWN, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL,                  \
    KC_LALT, KC_SPC, KC_FN0, KC_FN1, KC_0, KC_PAUSE)
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),
  [1] = ACTION_LAYER_MOMENTARY(2),
  [2] = ACTION_FUNCTION(BOOTLOADER),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
