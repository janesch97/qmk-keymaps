#include "wide.h"

static bool wide_text_on = false;
static bool first_char = false;

void toggle_wide_text(void) {
    wide_text_on = !wide_text_on;
    first_char = true;
}

void process_wide_text(uint16_t keycode, keyrecord_t *record) {
    if (wide_text_on && record->event.pressed) {
        switch (keycode) {
            case KC_A...KC_0:
            case KC_MINS...KC_SLSH:
            case KC_SPC:
                if (first_char) {
                    first_char = false;
                } else {
                    send_char(' ');
                }
                break;
            case KC_ENT:
                first_char = true;
                break;
            case KC_BSPC:
                send_char('\b');
                break;
        }
    }
}
