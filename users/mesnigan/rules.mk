SRC += mesnigan.c \
       process_records.c

RGBLIGHT_ENABLE = no
BOOTLOADER = atmel-dfu
# KVM shortcuts compatibility
NKRO_ENABLE = no
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes