
#pragma once
#define RGBLIGHT_LAYERS
#ifdef RGB_DI_PIN
    // /*== all animations enable ==*/
    //#define RGBLIGHT_ANIMATIONS
    // /*== or choose animations ==*/
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif

#define UNICODE_SELECTED_MODES UC_MAC, UC_LNX, UC_WINC

#define MOUSEKEY_DELAY 10
#define MOUSEKEY_TIME_TO_MAX 20
#define MOUSEKEY_MAX_SPEED 20
#define MOUSEKEY_WHEEL_DELAY 10
#define USB_MAX_POWER_CONSUMPTION 50

//#define IGNORE_MOD_TAP_INTERRUPT
//#define TAP_HOLD_DELAY 120
