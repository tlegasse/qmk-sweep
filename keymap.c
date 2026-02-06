#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    BASE = 0,
    SYM,
    EXT,
    FNC,
    SETTINGS,
    GMOD
};

// Custom keycodes for macros
enum custom_keycodes {
    TMUX_L = SAFE_RANGE,
    TMUX_H,
    TMUX_J,
    TMUX_K,
    TMUX_CMD,
    TMUX_S,
    TMUX_NEW,
    TMUX_SPH,
    TMUX_SPV,
    TMUX_NW,
    TMUX_PW,
    TMUX_XW,
    TMUX_SRCH
};

// Combo definitions
enum combos {
    COMBO_SETTINGS,
    COMBO_ESC,
    COMBO_DEL,
    COMBO_CTRLA,
    COMBO_SAVE,
    COMBO_TAB,
    COMBO_TMUX_SRCH
    COMBO_GMOD
};

const uint16_t PROGMEM combo_settings[] = {LT(2,KC_BSPC), LGUI_T(KC_ENT), COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_ctrla[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_save[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_tmux_srch[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_gmod[] = {LT(EXT,KC_BSPC), LGUI_T(KC_ENT), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_SETTINGS] = COMBO(combo_settings, MO(SETTINGS)),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_DEL] = COMBO(combo_del, KC_DEL),
    [COMBO_CTRLA] = COMBO(combo_ctrla, LCTL(KC_A)),
    [COMBO_SAVE] = COMBO(combo_save, LCTL(KC_SCLN)),
    [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
    [COMBO_TMUX_SRCH] = COMBO(combo_tmux_srch, TMUX_SRCH),
    [COMBO_GMOD] = COMBO(combo_gmod, MO(GMOD))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_2(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,
        LT(FNC,KC_A),   LCTL_T(KC_S),   LALT_T(KC_D),   KC_F,           KC_G,           KC_H,           KC_J,           RALT_T(KC_K),   RCTL_T(KC_L),   KC_SCLN,
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,
                                                        KC_LSFT,        LT(SYM,KC_SPC), LT(EXT,KC_BSPC),LGUI_T(KC_ENT)
    ),

    [SYM] = LAYOUT_split_3x5_2(
        LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_5),     KC_TILD,        KC_GRV,         LSFT(KC_2),     LSFT(KC_3),     KC_MINS,        KC_EQL,
        LSFT(KC_1),     LSFT(KC_7),     KC_QUOT,        LSFT(KC_RBRC),  LSFT(KC_4),     LSFT(KC_6),     LSFT(KC_9),     LSFT(KC_0),     LSFT(KC_MINS),  LSFT(KC_EQL),
        LSFT(KC_Z),     LSFT(KC_8),     LSFT(KC_QUOT),  KC_RBRC,        KC_TRNS,        KC_TRNS,        LSFT(KC_BSLS),  KC_BSLS,        LSFT(KC_LBRC),  KC_LBRC,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    [EXT] = LAYOUT_split_3x5_2(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_1,           KC_2,           KC_3,           LSFT(KC_RBRC),
        KC_LGUI,        KC_LCTL,        KC_LALT,        KC_LSFT,        KC_TRNS,        KC_TRNS,        KC_4,           KC_5,           KC_6,           KC_0,
        KC_MPLY,        KC_MPRV,        KC_VOLD,        KC_VOLU,        KC_MNXT,        KC_TRNS,        KC_7,           KC_8,           KC_9,           KC_QUOT,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    [FNC] = LAYOUT_split_3x5_2(
        KC_TRNS,        KC_HOME,        KC_END,         LCTL(KC_DOT),   LCTL(KC_I),     KC_TRNS,        KC_TRNS,        KC_TRNS,        LCTL(KC_T),     KC_RGHT,
        KC_TRNS,        KC_TRNS,        LCTL(KC_A),     LCTL(KC_SLSH),  KC_TAB,         LCTL(KC_B),     KC_LEFT,        KC_TRNS,        LCTL(KC_PGUP),  LCTL(KC_PGDN),
        KC_TRNS,        KC_TRNS,        KC_DOWN,        KC_UP,          KC_TRNS,        LCTL(KC_LEFT),  KC_TRNS,        LCTL(KC_RGHT),  KC_TRNS,        LCTL(KC_Y),
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
    ),

    [SETTINGS] = LAYOUT_split_3x5_2(
        QK_BOOT,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,        KC_NO,          QK_BOOT,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                        KC_NO,          KC_NO,          KC_NO,          KC_NO
    ),

    [GMOD] = LAYOUT_split_3x5_2(
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        LGUI(KC_4),     LGUI(KC_5),     LGUI(KC_6),     LGUI(KC_0),
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        LGUI(KC_7),     LGUI(KC_8),     LGUI(KC_9),     KC_TRNS,
                                                        KC_LSFT,        KC_TRNS,        KC_TRNS,        KC_TRNS
    )
};

// Macro processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_L:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "l");
            }
            return false;

        case TMUX_H:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "j");
            }
            return false;

        case TMUX_J:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "c");
            }
            return false;

        case TMUX_K:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "v");
            }
            return false;

        case TMUX_CMD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_LSFT("z"));
            }
            return false;

        case TMUX_S:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") ";");
            }
            return false;

        case TMUX_NEW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "i");
            }
            return false;

        case TMUX_SPH:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "\\");
            }
            return false;

        case TMUX_SPV:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_LSFT("'"));
            }
            return false;

        case TMUX_NW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "l");
            }
            return false;

        case TMUX_PW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "r");
            }
            return false;

        case TMUX_XW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_LSFT("z") "vgpp',glhs," SS_TAP(X_ENTER));
            }
            return false;

        case TMUX_SRCH:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") "-");
            }
            return false;
    }
    return true;
}
