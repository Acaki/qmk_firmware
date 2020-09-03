RGBLIGHT_ENABLE = no
BOOTLOADER = atmel-dfu
NKRO_ENABLE = yes
EXTRAKEY_ENABLE = yes
EXTRAFLAGS += -flto
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
