#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _QWERTY_SLIM,
    _LOWER,
    _RAISE,
    _BOTH,
    _DEBUG,
};

enum sofle_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_QWERTY_SLIM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY SLIM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |      |      |      |      |      |                    |      |      |      |      |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTR | LAlt |LOWER | /Enter  /       \Space \  |RAISE | RAlt | RCTR | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY_SLIM] = LAYOUT(
  KC_GRV,    XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   KC_BSPC,
  KC_TAB,       KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,   KC_BSLS,
  CTL_T(KC_ESC),KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,  KC_J,  KC_K,   KC_L,   KC_SCLN,KC_QUOT,
  KC_LSFT,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_HOME,KC_N,  KC_M,  KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                  KC_LGUI,  KC_LCTRL,KC_LALT,MO(_LOWER), KC_ENT,      KC_SPC,  MO(_RAISE), KC_RALT,  KC_RCTRL, KC_RGUI
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LCTR | LAlt |LOWER | /Enter  /       \Space \  |RAISE | RAlt | RCTR | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,       KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,  KC_7,  KC_8,   KC_9,   KC_0,   KC_BSPC,
  KC_TAB,       KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,   KC_BSLS,
  CTL_T(KC_ESC),KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,  KC_J,  KC_K,   KC_L,   KC_SCLN,KC_QUOT,
  KC_LSFT,      KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_HOME,KC_N,  KC_M,  KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                  KC_LGUI,  KC_LCTRL,KC_LALT,MO(_LOWER), KC_ENT,      KC_SPC,  MO(_RAISE), KC_RALT,  KC_RCTRL, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  [   |  ]   |      |-------.    ,-------|  +   |  (   |  )   |  =   |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  _   |  -   |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  _______, _______, _______, KC_LBRC, KC_RBRC, _______,                         KC_PLUS, KC_LPRN, KC_RPRN, KC_EQL,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______,       _______, KC_UNDS, KC_MINS, _______, _______, _______, _______,
                   _______, _______, _______, _______, MO(_DEBUG),     _______, MO(_BOTH), _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |                    |      |Insert| Print| Pause|      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | Caps |-------.    ,-------| Left | Down | Up   | Right|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |-------|    |-------| Home | PgUp | PgDn | End  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                           _______, KC_INS,  KC_PSCR, KC_PAUS, _______, KC_DEL,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_CAPS,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______,        _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
                   _______, _______, _______, MO(_BOTH), _______,      _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Click|  Up  | Click|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Left | Down | Right|WheelU|-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |WheelL|      |WheelR|WheelD|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_BOTH] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U,                       XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  KC_ACL2, XXXXXXX, KC_WH_L, XXXXXXX, KC_WH_R, KC_WH_D, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_ACL0,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
/* DEBUG
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |QWERTY| SLIM |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_DEBUG] = LAYOUT(
  XXXXXXX, KC_QWERTY, KC_QWERTY_SLIM, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef OLED_DRIVER_ENABLE

void suspend_power_down_user(void) {
    oled_off();
}

#ifndef MASTER_RIGHT
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}
#endif

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE\n"), false);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _QWERTY_SLIM:
            oled_write_ln_P(PSTR("Slim"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _QWERTY_SLIM:
            oled_write_P(PSTR("Slim\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _DEBUG:
            oled_write_P(PSTR("Debug"), false);
            break;
        case _BOTH:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
#ifndef MASTER_RIGHT
    } else {
        render_logo();
#endif
    }
}

#endif

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        switch(biton32(layer_state)){
        case _LOWER:
            if (clockwise) {
                tap_code16(LALT(KC_RIGHT));
            } else {
                tap_code16(LALT(KC_LEFT));
            }
            break;
        default:
            if (clockwise) {
                tap_code16(LSFT(KC_RIGHT));
            } else {
                tap_code16(LSFT(KC_LEFT));
            }
            break;
        }
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
    case KC_QWERTY_SLIM:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY_SLIM);
        }
        return false;
    }
    return true;
}

void matrix_init_user(void) {
    set_single_persistent_default_layer(_QWERTY_SLIM);
}
