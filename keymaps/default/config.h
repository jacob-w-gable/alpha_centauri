
#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 250U

#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61

// Solenoid config
#define SOLENOID_PIN GP8
#define SOLENOID_MAX_DWELL 250
#define SOLENOID_MIN_DWELL 4
#define SOLENOID_DEFAULT_DWELL 30
#define SOLENOID_DWELL_STEP_SIZE 10
#define NO_HAPTIC_ALPHA
#define NO_HAPTIC_PUNCTUATION
#define NO_HAPTIC_NAV
#define NO_HAPTIC_NUMERIC

// Data syncing
#define SPLIT_HAPTIC_ENABLE
#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE

// #define SWAP_HANDS_ENABLE

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

/* Hand configuration */
// If `MASTER_LEFT` and `MASTER_RIGHT` are both undefined, define `EE_HANDS`.
#ifndef MASTER_LEFT
#ifndef MASTER_RIGHT
#define EE_HANDS
#endif
#endif

// Split configuration
#define SERIAL_USART_TX_PIN GP9
#define SPLIT_CONNECTION_CHECK_TIMEOUT 100

#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 120

#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define OLED_TIMEOUT 120000
#define OLED_BRIGHTNESS 120

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// mouse keys
#define MK_COMBINED
#define MOUSEKEY_DELAY 2
#define MOUSEKEY_INTERVAL 5
#define MOUSEKEY_MOVE_DELTA 2
#define MOUSEKEY_MAX_SPEED 7
#define MK_C_OFFSET_1 3

// Space management
#define DYNAMIC_KEYMAP_LAYER_COUNT 16

// RGB Effects and Settings

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_HUE_STEP 4
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define ENABLE_RGB_MATRIX_ALPHAS_MODS                // Static dual hue, speed is hue for secondary hue
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN           // Static gradient top to bottom, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT        // Static gradient left to right, speed controls how much gradient changes
#define ENABLE_RGB_MATRIX_BREATHING                  // Single hue brightness cycling animation
#define ENABLE_RGB_MATRIX_BAND_SAT                   // Single hue band fading saturation scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_VAL                   // Single hue band fading brightness scrolling left to right
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT          // Single hue 3 blade spinning pinwheel fades saturation
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL          // Single hue 3 blade spinning pinwheel fades brightness
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT            // Single hue spinning spiral fades saturation
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL            // Single hue spinning spiral fades brightness
#define ENABLE_RGB_MATRIX_CYCLE_ALL                  // Full keyboard solid hue cycling through full gradient
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT           // Full gradient scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN              // Full gradient scrolling top to bottom
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN               // Full gradient scrolling out to in
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL          // Full dual gradients scrolling out to in
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON     // Full gradient Chevron shapped scrolling left to right
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL             // Full gradient spinning pinwheel around center of keyboard
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL               // Full gradient spinning spiral around center of keyboard
#define ENABLE_RGB_MATRIX_DUAL_BEACON                // Full gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON             // Full tighter gradient spinning around center of keyboard
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS          // Full dual gradients spinning two halfs of keyboard
#define ENABLE_RGB_MATRIX_FLOWER_BLOOMING            // Full tighter gradient of first half scrolling left to right and second half scrolling right to left
#define ENABLE_RGB_MATRIX_RAINDROPS                  // Randomly changes a single key's hue
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS        // Randomly changes a single key's hue and saturation
#define ENABLE_RGB_MATRIX_HUE_BREATHING              // Hue shifts up a slight ammount at the same time, then shifts back
#define ENABLE_RGB_MATRIX_HUE_PENDULUM               // Hue shifts up a slight ammount in a wave to the right, then back to the left
#define ENABLE_RGB_MATRIX_HUE_WAVE                   // Hue shifts up a slight ammount and then back down in a wave to the right
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL              // Single hue fractal filled keys pulsing horizontally out to edges
#define ENABLE_RGB_MATRIX_PIXEL_FLOW                 // Pulsing RGB flow along LED wiring with random hues
#define ENABLE_RGB_MATRIX_PIXEL_RAIN                 // Randomly light keys with random hues
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP             // How hot is your WPM!
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN               // That famous computer simulation
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE      // Pulses keys hit to hue & value then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE             // Static single hue, pulses keys hit to shifted hue then fades to current hue
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE        // Hue & value pulse near a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE   // Hue & value pulse near multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS       // Hue & value pulse the same column and row of a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS  // Hue & value pulse the same column and row of multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS       // Hue & value pulse away on the same column and row of a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS  // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SPLASH                     // Full gradient & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_MULTISPLASH                // Full gradient & value pulse away from multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_SOLID_SPLASH               // Hue & value pulse away from a single key hit then fades value out
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH          // Hue & value pulse away from multiple key hits then fades value out
#define ENABLE_RGB_MATRIX_STARLIGHT                  // LEDs turn on and off at random at varying brightness, maintaining user set color
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE         // LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT         // LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
#define ENABLE_RGB_MATRIX_RIVERFLOW                  // Modification to breathing animation, offset's animation depending on key location to simulate a river flowing
#endif

