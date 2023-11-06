SRC += features/achordion.c \
	   features/custom_shift_keys.c \
	   #unicode.c
VPATH += keyboards/gboards
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
NKRO_ENABLE = yes
UNICODEMAP_ENABLE = yes
RGBLIGHT_ENABLE = yes
CONVERT_TO=promicro_rp2040
