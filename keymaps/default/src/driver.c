#include QMK_KEYBOARD_H

#define LEFT_THUMB_INSIDE LCTL_T(KC_EQL)
#define LEFT_THUMB_MIDDLE LT(2, KC_BSPC)
#define LEFT_THUMB_OUTSIDE LGUI_T(KC_LPRN)
#define RIGHT_THUMB_INSIDE LALT_T(KC_MINS)
#define RIGHT_THUMB_MIDDLE KC_SPC
#define RIGHT_THUMB_OUTSIDE LT(4, KC_RPRN)
#define CORNER_BL KC_LSFT
#define CORNER_BR SC_SENT
#define SHIFT2_LEFT LT(3, KC_TAB)
#define SHIFT2_RIGHT LT(3, KC_QUOT)

#include "unicode.c"

// Global state of each shift key
bool shift_l_down = false;
bool shift_r_down = false;

// State of the left thumb inside key
bool left_thumb_inside_down = false;
uint32_t left_thumb_inside_timeout;

/**
 * User-level implementation of process_record, where keystrokes can be intercepted.
 * `record` has extra info about the keypress event (down, up, tap, hold, etc.).
 *
 * You will notice frequent use of `LT(<layer>, <keycode>)`, or layer tap. Normally this
 * would temporary turn on the layer when the key is held, but when we are already on that
 * layer, it has no effect. This can be used as a way to create hard-coded macros from scratch.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {

    // Bypass the Get Hold on Other Key Press setting for the ctrl + spacebar.
    // Rarely a use for ctrl + space, and "= " is much more common.
    // This effectively resets to default, single-layer tapping style for this one corner case.
    // Ctrl + space is still possible, by simply waiting the tapping term befre ressing space.
    case LEFT_THUMB_INSIDE:
        // Keep up with the status of left thumb key, save a timeout
        left_thumb_inside_down = record->event.pressed;
        if (record->event.pressed) {
            left_thumb_inside_timeout = timer_read32() + get_tapping_term(keycode, record);
        }
        break;
    case RIGHT_THUMB_MIDDLE:
        // If left thumb inside is pressed, and the right thumb middle is pressed, all within
        // the taping term...
        if (record->event.pressed && left_thumb_inside_down && 
              !timer_expired32(timer_read32(), left_thumb_inside_timeout)) {
            // Unpress LCTRL
            unregister_code(KC_LCTL);
            left_thumb_inside_down = false;
            // Tap the keycode for "= "
            tap_code16(KC_EQL);
            tap_code16(KC_SPC);
            return false;
        }
        break;

    /**
     * Keep up if both shifts are held
     */
    case CORNER_BL:
        shift_l_down = record->event.pressed;
        break;

    case CORNER_BR:
        shift_r_down = record->event.pressed;
        break;

    // CTRL Backspace
    case LT(0, KC_BSPC):
        if (record->event.pressed)
        {
            register_code(KC_LCTL);
            register_code(KC_BSPC);
        }
        else
        {
            unregister_code(KC_BSPC);
            unregister_code(KC_LCTL);
        }
        return false;

    /*
    hotkeys on the MEDIA layer
    */
    case LT(0, KC_F1):
        if (record->event.pressed)
        {
            SEND_STRING(SS_LSFT(SS_LWIN("s")));
        }
        return false;

    case LT(0, KC_F2):
        if (record->event.pressed)
        {
            SEND_STRING(SS_LCTL(SS_LALT("t")));
        }
        return false;

    /*
    parenthese intercept
    */
    case LEFT_THUMB_OUTSIDE:
        if (record->tap.count && record->event.pressed)
        {
            tap_code16(KC_LPRN);
            return false;
        }
        break;

    case RIGHT_THUMB_OUTSIDE:
        if (record->tap.count && record->event.pressed)
        {
            tap_code16(KC_RPRN);
            return false;
        }
        break;

    /*
    DEBUG layer hotkeys
    */
    // undo
    case LT(0, KC_Z):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(C(KC_Z));
            return false;
        }
        break;

    // cut
    case LT(0, KC_X):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(C(KC_X));
            return false;
        }
        break;

    // copy
    case LT(0, KC_C):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(C(KC_C));
            return false;
        }
        break;

    // paste
    case LT(0, KC_V):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(C(KC_V));
            return false;
        }
        break;

    // select all
    case LT(0, KC_A):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(C(KC_A));
            return false;
        }
        break;

    // save
    case LT(0, KC_S):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(C(KC_S));
            return false;
        }
        break;

    // open calculator
    case LT(0, KC_D):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(KC_CALC);
            return false;
        }
        break;

    // search
    case LT(0, KC_F):
        if (!record->tap.count && record->event.pressed)
        {
            tap_code16(C(KC_F));
            return false;
        }
        break;

    // open terminal window
    case LT(0, KC_T):
        if (!record->tap.count && record->event.pressed)
        {
            SEND_STRING(SS_LCTL(SS_LALT("t")));
            return false;
        }
        break;

    // lock the screen
    case LT(0, KC_L):
        if (!record->tap.count && record->event.pressed)
        {
            register_code(KC_LGUI);
            register_code(KC_ESC);
        }
        else if (!record->tap.count)
        {
            unregister_code(KC_ESC);
            unregister_code(KC_LGUI);
        }
        return false;

    // screenshot (linux)
    case LT(0, KC_P):
        if (!record->tap.count && record->event.pressed)
        {
            SEND_STRING(SS_LSFT(SS_LWIN("s")));
            return false;
        }
        break;

    /*
     * toggle GREEK layer.
     * Do this when the layer key is held down.
     */
    // on
    case LT(0, KC_SLSH):
        if (!record->tap.count && record->event.pressed)
        {
            layer_on(1);
            return false;
        }
        else if (!record->tap.count && !record->event.pressed)
        {
            return false;
        }
        break;
    // off
    case LT(1, KC_SLSH):
        if (!record->tap.count && record->event.pressed)
        {
            layer_off(1);
            return false;
        }
        else if (!record->tap.count && !record->event.pressed)
        {
            return false;
        }
        break;

    /*
     * toggle SCRPT layer
     * Do this when the layer key is held down.
     */
    // on
    case LT(0, KC_COMM):
        if (!record->tap.count && record->event.pressed)
        {
            layer_on(6);
            // just an example of chaning a wui setting. In this case, chaning the view (setting 0) to 2 (third screen)
            //set_wui_setting(0, 2);
            return false;
        }
        else if (!record->tap.count && !record->event.pressed)
        {
            return false;
        }
        break;
    // off
    case LT(6, KC_COMM):
        if (!record->tap.count && record->event.pressed)
        {
            layer_off(6);
            return false;
        }
        else if (!record->tap.count && !record->event.pressed)
        {
            return false;
        }
        break;

    /*
     * toggle SYMBL layer
     * Do this when the layer key is held down.
     */
    // on
    case LT(0, KC_DOT):
        if (!record->tap.count && record->event.pressed)
        {
            layer_on(8);
            return false;
        }
        else if (!record->tap.count && !record->event.pressed)
        {
            return false;
        }
        break;
    // off
    case LT(8, KC_DOT):
        if (!record->tap.count && record->event.pressed)
        {
            layer_off(8);
            return false;
        }
        else if (!record->tap.count && !record->event.pressed)
        {
            return false;
        }
        break;

    // Toggle gaming chat layer
    // On - chat
    case KC_T:
        if (record->event.pressed && get_highest_layer(layer_state) == 8)
        {
            layer_off(8);
            layer_on(9);
            return true;
        }
        break;
    // On - command
    case KC_SLSH:
        if (record->event.pressed && get_highest_layer(layer_state) == 8)
        {
            layer_off(8);
            layer_on(9);
            tap_code16(KC_SLSH);
            return false;
        }
        break;
    // Off - cancel
    case KC_ESC:
        if (record->event.pressed && get_highest_layer(layer_state) == 9)
        {
            layer_off(9);
            layer_on(8);
            tap_code16(KC_ESC);
            return false;
        }
        break;
    // Off - send
    case RSFT_T(KC_ENT):
        if (record->tap.count && record->event.pressed && get_highest_layer(layer_state) == 9)
        {
            layer_off(9);
            layer_on(8);
            tap_code16(KC_ENT);
            return false;
        }
    }
    return true;
}

// timings for click vs hold in ms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    // small outer thumb keys
    // - none for now

    // shift2 keys
    case SHIFT2_RIGHT:
        return 125;

    // big thumb keys
    case LEFT_THUMB_INSIDE:
    case RIGHT_THUMB_INSIDE:
    // middle thumb keys
    case LEFT_THUMB_MIDDLE:
        return 150;

    // hotkeys
    case LT(0, KC_Z):
    case LT(0, KC_X):
    case LT(0, KC_C):
    case LT(0, KC_V):
    case LT(0, KC_A):
    case LT(0, KC_S):
    case LT(0, KC_D):
    case LT(0, KC_F):
    case LT(0, KC_T):
    case LT(0, KC_L):
    case LT(0, KC_P):
    // move to layer 1
    case LT(0, KC_SLSH):
    case LT(1, KC_SLSH):
    // move to layer 2
    case LT(0, KC_COMM):
    case LT(0, KC_P2):
    // move to layer 3
    case LT(0, KC_DOT):
    case LT(0, KC_F10):
        return 300;

    default:
        return TAPPING_TERM;
    }
}

// Whether to immediately consider a key to be held down when another key is pressed
// while this key is still down.
// For layer shift keys, this essentially determines whether we are allowing rolling to
// the next layer (`A B ~A ~B` pattern, where A is layer shift and B is on second layer)
// or if we need to require a full keypress on that layer (`A B ~B ~A` pattern).
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case LEFT_THUMB_MIDDLE:
    case SHIFT2_LEFT:
    // case SHIFT2_RIGHT:
    case CORNER_BR:
    case LEFT_THUMB_INSIDE:
    case RSFT_T(KC_ENT):
        // Immediately select the hold action when another key is pressed. (A B ~A ~B roll pattern)
        return true;
    default:
        // default setting of ABBA shift pattern
        return false;
    }
}

// Whether to allow a key to be considered held down when another key is pressed
// and released while this key is still down. (A B ~B ~A pattern).
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(0, KC_SLSH):
    case LT(0, KC_COMM):
    case LT(0, KC_DOT):
      return false;
    default:
      return true;
  }
}

// Whether haptic feedback is enabled for a keypress
bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
#ifdef NO_HAPTIC_MOD
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        if (record->tap.count == 0)
            return false;
        break;
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
        if (record->tap.count != TAPPING_TOGGLE)
            return false;
        break;
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        if (record->tap.count == 0)
            return false;
        break;
    case KC_LEFT_CTRL ... KC_RIGHT_GUI:
    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
    case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
#endif
#ifdef NO_HAPTIC_ALPHA
    case KC_A ... KC_Z:
#endif
#ifdef NO_HAPTIC_PUNCTUATION
    case KC_ENTER:
    case KC_ESCAPE:
    case KC_BACKSPACE:
    case KC_SPACE:
    case KC_MINUS:
    case KC_EQUAL:
    case KC_LEFT_BRACKET:
    case KC_RIGHT_BRACKET:
    case KC_BACKSLASH:
    case KC_NONUS_HASH:
    case KC_SEMICOLON:
    case KC_QUOTE:
    case KC_GRAVE:
    case KC_COMMA:
    case KC_SLASH:
    case KC_DOT:
    case KC_NONUS_BACKSLASH:
#endif
#ifdef NO_HAPTIC_LOCKKEYS
    case KC_CAPS_LOCK:
    case KC_SCROLL_LOCK:
    case KC_NUM_LOCK:
#endif
#ifdef NO_HAPTIC_NAV
    case KC_PRINT_SCREEN:
    case KC_PAUSE:
    case KC_INSERT:
    case KC_DELETE:
    case KC_PAGE_DOWN:
    case KC_PAGE_UP:
    case KC_LEFT:
    case KC_UP:
    case KC_RIGHT:
    case KC_DOWN:
    case KC_END:
    case KC_HOME:
#endif
#ifdef NO_HAPTIC_NUMERIC
    case KC_1 ... KC_0:
#endif
    case 0:
        return false;

    // don't vibrate for keypress, but vibrate for key hold
    case LEFT_THUMB_OUTSIDE:
    case LEFT_THUMB_MIDDLE:
    case LEFT_THUMB_INSIDE:
    case RIGHT_THUMB_INSIDE:
    case RIGHT_THUMB_OUTSIDE:
    case SHIFT2_LEFT:
    case SHIFT2_RIGHT:
    case LT(0, KC_SLSH):
    case LT(0, KC_COMM):
    case LT(0, KC_DOT):
        if (record->tap.count && record->event.pressed)
        {
            return false;
        }
        break;

    // vibrate for caps word
    case CORNER_BL:
        return record->event.pressed && shift_r_down;
    case CORNER_BR:
        return record->event.pressed && shift_l_down;
    }

    return true;
}

