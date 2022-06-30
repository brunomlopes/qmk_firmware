SRC += oled.c encoder.c transport.c

BOOTLOADER = caterina

OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # ENables the use of one or more encoders
# do not enable rgb until I fix the led solder jobs
EXTRAKEY_ENABLE = yes
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

# LTO: Link Time Optimizations.
# Reduce compiled size, but will automatically disable the legacy TMK Macros and Functions features.
# This does not affect QMK Macros and Layers
LTO_ENABLE = yes

MOUSEKEY_ENABLE = yes

CAPS_WORD_ENABLE = yes

USER_NAME := brunomlopes
