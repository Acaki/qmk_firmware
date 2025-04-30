SRC += process_records.c \
       features/caps_word.c
INTROSPECTION_KEYMAP_C = mesnigan.c

RGBLIGHT_ENABLE = no
BOOTLOADER = atmel-dfu
EXTRAKEY_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = yes
KEY_LOCK_ENABLE = yes
MAGIC_ENABLE = no
ifneq ($(PLATFORM),CHIBIOS)
    ifneq ($(strip $(LTO_SUPPORTED)), no)
        LTO_ENABLE = yes
    endif
endif