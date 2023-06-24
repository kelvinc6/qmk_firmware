#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

#include "rgb_matrix_map.h"

enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi_blocker( /* Base */
			QK_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,   KC_PGUP,
			TT(2),         KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL,       KC_LGUI,  KC_LALT,                KC_SPC,                KC_RALT,           KC_RCTL,  KC_LEFT,           KC_DOWN,   KC_RIGHT),
		// [_LAYER1] = LAYOUT_65_ansi_blocker( /* FN */
		// 	QK_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,
		//     KC_TRNS,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SCRL,  KC_PAUS, QK_BOOT,  KC_PGUP,
		// 	CTL_T(KC_CAPS),RGB_SPI,  RGB_SPD, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          EE_CLR,   KC_PGDN,
		//     KC_LSFT,       KC_TRNS,  KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_VOLU,  KC_MUTE,
		//     KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_MPRV,          KC_VOLD,  KC_MNXT),
		[_LAYER2] = LAYOUT_65_ansi_blocker( /* Custom Layer */
			QK_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_HOME,
		    KC_TRNS,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, KC_VOLD, KC_UP,   KC_VOLU, KC_PSCR,  KC_SCRL, KC_PAUS, QK_BOOT,  KC_PGUP,
			TG(2),         KC_NO,    KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_NO,    KC_NO,            KC_ENT,   KC_PGDN,
		    KC_LSFT,       KC_NO,    KC_NO,   KC_NO,  KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_MUTE,
		    KC_TRNS,       KC_TRNS,  KC_TRNS,                  KC_TRNS,                   KC_TRNS,          KC_TRNS,  KC_MPRV,          KC_TRNS,  KC_MNXT),
};

#ifdef RGB_MATRIX_ENABLE
    // Capslock, Scroll lock and Numlock indicator
    bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        // led_t led_state = host_keyboard_led_state();
        rgb_matrix_set_color_all(RGB_OFF);

        switch(get_highest_layer(layer_state)){  // special handling per layer
        case _LAYER2:  // on Fn layer select what the encoder does when pressed
                rgb_matrix_set_color(LED_I, RGB_GOLD);
                rgb_matrix_set_color(LED_J, RGB_GOLD);
                rgb_matrix_set_color(LED_K, RGB_GOLD);
                rgb_matrix_set_color(LED_L, RGB_GOLD);         
                rgb_matrix_set_color(LED_U, RGB_RED);                                  
                rgb_matrix_set_color(LED_O, RGB_RED);                                  

            break;
        default:
            break;
        }
    return false;
    }
#endif