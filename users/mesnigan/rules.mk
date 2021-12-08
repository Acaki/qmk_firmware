SRC += mesnigan.c \
       process_records.c \
       features/caps_word.c

RGBLIGHT_ENABLE = no
BOOTLOADER = atmel-dfu
NKRO_ENABLE = yes
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = yes
KEY_LOCK_ENABLE = yes
SWAP_HANDS_ENABLE = yes
ifneq ($(PLATFORM),CHIBIOS)
    ifneq ($(strip $(LTO_SUPPORTED)), no)
        LTO_ENABLE = yes
    endif
endif