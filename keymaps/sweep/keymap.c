#include "boenkyo.h"

#include "definitions/layout.h"

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
