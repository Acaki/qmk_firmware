RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
MOUSEKEY_ENABLE = yes
BOOTLOADER = atmel-dfu
NKRO_ENABLE = yes
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
