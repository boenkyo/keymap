#pragma once

enum unicode_names {
  U_AE_LOWER,
  U_AE_UPPER,
  U_OE_LOWER,
  U_OE_UPPER,
  U_AO_LOWER,
  U_AO_UPPER,
};

#define U_AE XP(U_AE_LOWER, U_AE_UPPER)
#define U_OE XP(U_OE_LOWER, U_OE_UPPER)
#define U_AO XP(U_AO_LOWER, U_AO_UPPER)

// Code lookup tool
// https://unicode.emnudge.dev/
const uint32_t unicode_map[] PROGMEM = {
    [U_AE_LOWER] = 0x00e4, // ä
    [U_AE_UPPER] = 0x00c4, // Ä
    [U_OE_LOWER] = 0x00f6, // ö
    [U_OE_UPPER] = 0x00d6, // Ö
    [U_AO_LOWER] = 0x00e5, // å
    [U_AO_UPPER] = 0x00c5, // Å
};
