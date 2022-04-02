#include "sarcasm.h"

static bool sarcasm_text_on = false;

void toggle_sarcasm_text(void) {
    sarcasm_text_on = !sarcasm_text_on;
    if (sarcasm_text_on) {
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
    }
}

void process_sarcasm_text(uint16_t keycode, keyrecord_t *record) {
    if (
        sarcasm_text_on
        && record->event.pressed
        && keycode != KC_SPC
    ) {
        register_code(KC_CAPS);
        unregister_code(KC_CAPS);
    }
}
