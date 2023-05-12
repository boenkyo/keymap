SRC += features/achordion.c \
	   features/repeat_key.c \
	   features/custom_shift_keys.c
VPATH += keyboards/gboards
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
STENO_ENABLE = yes
STENO_PROTOCOL = geminipr
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = yes
CONVERT_TO=promicro_rp2040
