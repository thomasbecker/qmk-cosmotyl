<<<<<<< HEAD
=======
# Build Options
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio controls and System controls
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
AUDIO_ENABLE = no          # Audio output

SPLIT_KEYBOARD = yes       # Enable split keyboard support
SERIAL_DRIVER = vendor     # Use vendor serial driver for RP2040

# Enable data-driven configuration
KEYBOARD_SHARED_EP = yes   # Needed for data-driven
QUANTUM_LIB_SRC += i2c_master.c
>>>>>>> Snippet

