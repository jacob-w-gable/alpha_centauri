BOOTLOADER=rp2040
CONVERT_TO=elite_pi
MOUSEKEY_ENABLE = yes     # Mouse keys
VIA_ENABLE      = no      # Disable VIA
LTO_ENABLE      = no
CAPS_WORD_ENABLE = yes
WPM_ENABLE = yes
AUTOCORRECT_ENABLE = yes
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
HAPTIC_ENABLE = yes
HAPTIC_DRIVER = solenoid
CONSOLE_ENABLE = yes
UNICODEMAP_ENABLE = yes

# saving space (more for AVR controllers)
SPACE_CADET_ENABLE = yes
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

# for my makefile
# this is the name of the json and c files that
# containing the actual keymap
KEYMAP_NAME = keymap/jacob-w-gable
