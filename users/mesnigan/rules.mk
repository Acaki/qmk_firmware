SRC += mesnigan.c \
       process_records.c

RGBLIGHT_ENABLE = no
BOOTLOADER = atmel-dfu
# KVM shortcuts compatibility
NKRO_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = yes
KEY_LOCK_ENABLE = yes
ifneq ($(PLATFORM),CHIBIOS)
    ifneq ($(strip $(LTO_SUPPORTED)), no)
        LTO_ENABLE = yes
    endif
endif