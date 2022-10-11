MCU_FAMILY = MIMXRT1062
MCU_SERIES = MIMXRT1062
MCU_LDSCRIPT = MIMXRT1062
MCU_STARTUP = MIMXRT1062
BOARD = IC_TEENSY_4_1
MCU = cortex-m4
ARMV = 7

# Debounce eagerly (report change immediately), keep per-key timers. We can use
# this because the Cherry MX keyswitches only produce noise while pressed.
DEBOUNCE_TYPE = sym_eager_pk

FIRMWARE_FORMAT = hex

# Bootloader selection
BOOTLOADER = halfkay

# Build Options
# change yes to no to disable
#
RGBLIGHT_ENABLE = no       # Enable LED strips
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
