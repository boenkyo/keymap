#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "features/achordion.h"
#include "features/custom_shift_keys.h"
#include "features/repeat_key.h"
#include "keycodes.h"
#include "quantum.h"

enum layers {
  DEF,
  SWE,
  SYM,
  NUM,
  NAV,
  OPS,
  MED,
  GAM,
};

enum custom_keycodes {
  DIRUP = SAFE_RANGE,
  NEQ,
  COLNEQ,
  REPEAT,
  ALT_REP,
};

// Home row mods
#define HRM_A LCTL_T(KC_A)
#define HRM_R LALT_T(KC_R)
#define HRM_S LT(NUM, KC_S)
#define HRM_T LSFT_T(KC_T)

#define HRM_N RSFT_T(KC_N)
#define HRM_E LT(OPS, KC_E)
#define HRM_I RALT_T(KC_I)
#define HRM_O RCTL_T(KC_O)

#define MY_D LT(MED, KC_D)

// Thumb cluster
#define TMB_TAB LGUI_T(KC_TAB)
#define TMB_ENT RGUI_T(KC_ENT)
#define TMB_SPC LT(SYM, KC_SPC)
#define NAV_REP LT(NAV, REPEAT)

// Nav
#define TAB_NXT LCTL(KC_TAB)
#define TAB_PRV LCTL(LSFT(KC_TAB))
#define HST_BCK LGUI(KC_LBRC)
#define HST_FWD LGUI(KC_RBRC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *      q w f p b    j l u y '
     *      a r s t g    m n e i o
     *      z x c d v    k h , . :
     */
  
    [DEF] = LAYOUT(
        KC_Q,       KC_W,    KC_F,    KC_P,     KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        HRM_A,     HRM_R,   HRM_S,   HRM_T,     KC_G,       KC_M,    HRM_N,   HRM_E,   HRM_I,   HRM_O,
        KC_Z,       KC_X,    KC_C,    MY_D,     KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_COLN,
                                   NAV_REP,  TMB_TAB,      TMB_ENT,  TMB_SPC
    ),
    
    [SWE] = LAYOUT(
        _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
                                   _______,  _______,       _______, _______
    ),
    
    /*
     *      ` $ { }  
     *      # _ ( ) 
     *      ~ @ [ ] 
     */
    [SYM] = LAYOUT(
        KC_GRV,  KC_DLR,  KC_LCBR, KC_RCBR,  _______,       _______, _______, _______, _______, _______,
        KC_HASH, KC_UNDS, KC_LPRN, KC_RPRN,  _______,       _______, _______, _______, _______, _______,
        KC_TILD, KC_AT,   KC_LBRC, KC_RBRC,  _______,       _______, _______, _______, _______, _______,
                                   _______,  _______,       _______, _______
    ),

    /*
     *      % < > != ^
     *      | - + = :=
     *      & / * \ ../
     */

    [OPS] = LAYOUT(
        KC_PERC, KC_LABK, KC_RABK, NEQ,      KC_CIRC,       _______, _______, _______, _______, _______,
        KC_PIPE, KC_MINS, KC_PLUS, KC_EQL,   COLNEQ,        _______, _______, _______, _______, _______,
        KC_AMPR, KC_SLSH, KC_ASTR, KC_BSLS,  DIRUP,         _______, _______, _______, _______, _______,
                                   _______,  _______,       _______, _______
    ),

    [NUM] = LAYOUT(
        _______, _______, _______, _______,  _______,       _______,    KC_7,    KC_8,    KC_9, _______,
        _______, _______, _______, _______,  _______,       _______,    KC_1,    KC_2,    KC_3,  KC_DOT,
        _______, _______, _______, _______,  _______,       _______,    KC_4,    KC_5,    KC_6, _______,
                                   _______,  _______,       _______, KC_0
    ),

    [NAV] = LAYOUT(
        _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______,       _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,
        _______, _______, _______, _______,  _______,       _______, TAB_PRV, HST_BCK, HST_FWD, TAB_NXT,
                                   _______,  _______,       _______, KC_BSPC
    ),

    [MED] = LAYOUT(
        _______, _______, _______, _______,  _______,       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______,
        _______, _______, _______, _______,  _______,       _______, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD,
        _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
                                   _______,  _______,       _______, KC_MPLY
    ),

    [GAM] = LAYOUT(
         KC_ESC,    KC_Q,    KC_X,    KC_E,  _______,       _______, _______, _______, _______, _______,
        KC_LSFT,    KC_A,    KC_W,    KC_D,  _______,       _______, _______, _______, _______, _______,
        KC_LCTL,    KC_Z,    KC_S,    KC_C,  _______,       _______, _______, _______, _______, _______,
                                    KC_SPC,   KC_TAB,       _______, _______
    ),

    // [] = LAYOUT(
    //     _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______,  _______,       _______, _______, _______, _______, _______,
    //                                _______,  _______,       _______, _______
    // ),
};
// clang-format on

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_QUES},
    {KC_COMM, KC_EXLM},
    {KC_COLN, KC_SCLN},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

#include "g/keymap_combo.h"

bool combo_should_trigger(uint16_t combo_index, combo_t *combo,
                          uint16_t keycode, keyrecord_t *record) {
  return true;
}

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record))
    return false;
  if (!process_custom_shift_keys(keycode, record))
    return false;
  if (keycode == NAV_REP && !record->tap.count) {
    return true;
  }
  if (!process_repeat_key_with_alt(keycode, record, NAV_REP, ALT_REP)) {
    return false;
  }

  switch (keycode) {
  case DIRUP:
    if (record->event.pressed) {
      SEND_STRING("../");
      return false;
    }
    break;
  case NEQ:
    if (record->event.pressed) {
      SEND_STRING("!=");
      return false;
    }
    break;
  case COLNEQ:
    if (record->event.pressed) {
      SEND_STRING(":=");
      return false;
    }
    break;
  }

  return true;
}

void matrix_scan_user(void) { achordion_task(); }

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
  switch (tap_hold_keycode) {
  // Allow same hand shortcuts with thumbs
  case TMB_TAB:
  case TMB_ENT:
    return true;

  // Allow ctrl + tab
  case HRM_A:
    if (other_keycode == TMB_TAB)
      return true;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
  case MOD_LSFT:
  case MOD_RSFT:
  case MOD_LGUI:
  case MOD_RGUI:
    return true;
  default:
    return false;
  }
}
