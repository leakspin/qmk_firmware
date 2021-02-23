#include QMK_KEYBOARD_H

enum layer_names {
    _4L,
    _3L,
    _2L,
    _1L
    // ,
    // _BL
};

// Config for layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_4L] = LAYOUT_ortho_6x4(
        TO(_1L), TO(_2L), TO(_3L), TO(_4L),
        RCS(KC_9),  RCS(KC_0),  RCS(KC_A),  RCS(KC_B),
        RCS(KC_C),  RCS(KC_D),  RCS(KC_E),  RCS(KC_F),
        RCS(KC_G),  RCS(KC_H),  RCS(KC_I),  RCS(KC_J),
        RCS(KC_K),  RCS(KC_L),  RCS(KC_M),  RCS(KC_N),
        RCS(KC_O),  RCS(KC_P),  RCS(KC_Q),  RCS(KC_R)
    ),

    [_3L] = LAYOUT_ortho_6x4(
        TO(_1L), TO(_2L), TO(_3L), TO(_4L),
        RSA(KC_F21),  RSA(KC_F22),  RSA(KC_F23),  RSA(KC_F24),
        RCS(KC_F13),  RCS(KC_F14),  RCS(KC_F15),  RCS(KC_F16),
        RCS(KC_F21),  RCS(KC_F22),  RCS(KC_F23),  RCS(KC_F24),
        RCS(KC_1),  RCS(KC_2),  RCS(KC_3),  RCS(KC_4),
        RCS(KC_5),  RCS(KC_6),  RCS(KC_7),  RCS(KC_8)
    ),

    [_2L] = LAYOUT_ortho_6x4(
        TO(_1L), TO(_2L), TO(_3L), TO(_4L),
        RSA(KC_K),  RSA(KC_L),  RSA(KC_M),  RSA(KC_N),
        RSA(KC_O),  RSA(KC_P),  RSA(KC_Q),  RSA(KC_R),
        RSA(KC_S),  RSA(KC_T),  RSA(KC_U),  RSA(KC_V),
        RSA(KC_W),  RSA(KC_X),  RSA(KC_Y),  RCS(KC_S),
        RSA(KC_F13),  RSA(KC_F14),  RSA(KC_F15),  RSA(KC_F16)
    ),

    [_1L] = LAYOUT_ortho_6x4(
        TO(_1L), TO(_2L), TO(_3L), TO(_4L),
        RSA(KC_1),  RSA(KC_2),  RSA(KC_3),  RSA(KC_4),
        RSA(KC_5),  RSA(KC_6),  RSA(KC_7),  RSA(KC_8),
        RSA(KC_9),  RSA(KC_0),  RSA(KC_A),  RSA(KC_B),
        RSA(KC_C),  RSA(KC_D),  RSA(KC_E),  RSA(KC_F),
        RSA(KC_G),  RSA(KC_H),  RSA(KC_I),  RSA(KC_J)
    )
    // ,
    // [_BL] = LAYOUT_ortho_6x4(
    //     TO(_1L), TO(_2L), TO(_3L), TO(_4L),
    //     _______, _______, _______, _______,
    //     _______, BL_ON,   _______, BL_INC,
    //     _______, BL_TOGG, _______, _______,
    //     _______, BL_OFF,  _______, BL_DEC,
    //     BL_BRTG, _______, _______, _______
    // )
};

void keyboard_post_init_user(void) {
    backlight_disable();
    layer_move(_1L);
}

bool led_update_user(led_t led_state) {
    writePin(D0, 0);
    return false;
}

layer_state_t common_layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case _2L:
            rgblight_sethsv(HSV_SPRINGGREEN);
            break;
        case _3L:
            rgblight_sethsv(HSV_CORAL);
            break;
        case _4L:
            rgblight_sethsv(HSV_PURPLE);
            break;
        case _1L:
        default:
            rgblight_sethsv(HSV_GOLDENROD);
    }
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return common_layer_state_set_user(state);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    return common_layer_state_set_user(state);
}