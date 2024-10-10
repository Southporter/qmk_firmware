#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names { _ZOOM };

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
};

#define ZOOM_MUTE LALT(KC_A)
#define ZOOM_BLIND LALT(KC_V)
#define ZOOM_END LALT(KC_Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_ZOOM] = LAYOUT_ortho_4x12(ZOOM_END, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, _______, _______, ZOOM_MUTE, _______, ZOOM_BLIND, _______, _______, _______, _______, _______, _______, _______, _______, _______, ZOOM_MUTE, _______, ZOOM_BLIND, _______, _______, _______, _______, _______, _______, KC_ENTER, KC_ENTER, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ZOOM);
            }
            return false;
            break;
    }
    return true;
}
