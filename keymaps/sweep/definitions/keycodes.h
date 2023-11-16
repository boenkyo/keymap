#pragma once

#include QMK_KEYBOARD_H
#include "layers.h"
#include "quantum.h"

enum custom_keycodes {
  DIRUP = SAFE_RANGE,
  NEQ,
  COLNEQ,
};

// Home row mods
#define HRM_A LGUI_T(KC_A)
#define HRM_R LALT_T(KC_R)
#define HRM_S LT(NUM, KC_S)
#define HRM_T LSFT_T(KC_T)

#define HRM_N RSFT_T(KC_N)
#define HRM_E LT(OPS, KC_E)
#define HRM_I RALT_T(KC_I)
#define HRM_O RGUI_T(KC_O)
#define MY_D LT(MED, KC_D)

// Thumb cluster
#define TMB_TAB LCTL_T(KC_TAB)
#define TMB_ENT RCTL_T(KC_ENT)
#define TMB_SPC LT(SYM, KC_SPC)
#define NAV_REP LT(NAV, KC_BSPC)

// Nav
#define TAB_NXT LCTL(KC_TAB)
#define TAB_PRV LCTL(LSFT(KC_TAB))
#define HST_BCK LGUI(KC_LBRC)
#define HST_FWD LGUI(KC_RBRC)