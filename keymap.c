#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "action_code.h"

#define BASE    0 // default layer
#define SHELL   1 // shell layer
#define RESTORE 2 // restore thumb clusters as they are overwritten by shell layer
#define KEY_NAV 3 // key navigation layer
#define KEY_SEL 4 // key selection layer
#define NUMBER  5  // number layer
#define SYMBOL  6
#define BRACKET 7
#define MOUSE   8
#define SHORTCUTS 9

// macros
#define MC_COPY_LINE  0
#define MC_CUT_LINE   1
#define MC_PASTE_LINE 2
#define MC_NEW_SEARCH_TAB 3
#define SCREEN_TAB_LEFT 4
#define SCREEN_TAB_RIGHT 5
#define SCREEN_NEW_TAB 6
#define SWITCH_NDS 7




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base layer
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_F1,          KC_F2,       KC_F3,        KC_F4,       KC_F5,       KC_F6,
        KC_TAB,         KC_QUOT,        KC_COMM,     KC_DOT,       KC_P,        KC_Y,        MO(KEY_SEL),
        KC_CAPSLOCK,    KC_A,           KC_O,        KC_E,         KC_U,        KC_I,
        KC_LSFT,        KC_SCLN,        KC_Q,        KC_J,         KC_K,        KC_X,        MO(KEY_NAV),
                   KC_LCTL,KC_LALT,MO(BRACKET),MO(SYMBOL),MO(NUMBER),  
                                              // thumb cluster
                                                       MO(MOUSE),    TG(SHELL),
                                                                     RCTL(KC_DEL),
                                               KC_BSPC,RCTL(KC_BSPC),KC_DEL,
        // right hand
             KC_F7,       KC_F8,       KC_F9,       KC_F10,        KC_F11,       KC_F12,       KC_BSLS,
             KC_PGUP,     KC_F,        KC_G,        KC_C,          KC_R,         KC_L,         KC_SLSH,
                          KC_D,        KC_H,        KC_T,          KC_N,         KC_S,         KC_MINS,
             KC_PGDN,     KC_B,        KC_M,        KC_W,          KC_V,         KC_Z,         KC_RSFT,
                                  // lower keys - tab control
                                  TG(SYMBOL), MO(SHORTCUTS), KC_LGUI, KC_LALT, KC_LCTL,
             // thumb cluster
             LSFT(RCTL(KC_TAB)), RCTL(KC_TAB),
             RCTL(KC_W),
             RCTL(KC_T),KC_ENT, KC_SPC
    ),
     

// shell layer - command line
[SHELL] = KEYMAP( 
        // left hand
        KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                              // thumb cluster
                                                      KC_TRNS, KC_TRNS,
                                                                  LALT(KC_D),
                                               KC_BSPC,RCTL(KC_W),KC_DEL,
        // right hand
             RCTL(KC_R),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_END,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_HOME,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                  // lower keys - command line control
                                   LALT(KC_B),  LALT(KC_F), LALT(KC_DOT), KC_TRNS, KC_TRNS,
             // thumb cluster
             M(SCREEN_TAB_LEFT), M(SCREEN_TAB_RIGHT),
             KC_HOME,
             M(SCREEN_NEW_TAB),     KC_ENT,  KC_SPC
    ),
    
// restore layer
[RESTORE] = KEYMAP( 
        // left hand
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                              // thumb cluster (restore)
                                                       KC_TRNS,     KC_TRNS,
                                                                     RCTL(KC_DEL),
                                               KC_BSPC,RCTL(KC_BSPC),KC_DEL,
        // right hand
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
             // thumb cluster (restore)
             LSFT(RCTL(KC_TAB)), RCTL(KC_TAB),
             RCTL(KC_W),
             RCTL(KC_T),KC_ENT, KC_SPC
    ),
    
// key navigation layer
[KEY_NAV] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
       KC_TRNS, KC_PGDN,        KC_HOME,    KC_UP,      KC_END,     KC_PGUP,        M(MC_COPY_LINE),
                RCTL(KC_LEFT),  KC_LEFT,    KC_DOWN,    KC_RIGHT,   RCTL(KC_RIGHT), M(MC_CUT_LINE),
       KC_TRNS, KC_TRNS,        RCTL(KC_C), RCTL(KC_X), RCTL(KC_V), KC_TRNS,        M(MC_PASTE_LINE),
                // bottom row
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// key selection layer
[KEY_SEL] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,       KC_TRNS,             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,              KC_TRNS,
       KC_TRNS,       RSFT(KC_PGDN),       RSFT(KC_HOME), RSFT(KC_UP),   RSFT(KC_END),   RSFT(KC_PGUP),        M(MC_COPY_LINE),
                      RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)), M(MC_CUT_LINE),
       KC_TRNS,       KC_TRNS,             RCTL(KC_C),    RCTL(KC_X),    RCTL(KC_V),     KC_TRNS,              M(MC_PASTE_LINE),
                // bottom row
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// number layer
[NUMBER] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_PLUS,  KC_7,    KC_8,    KC_9,     KC_ASTR, KC_TRNS,
                KC_MINS,  KC_4,    KC_5,    KC_6,     KC_SLSH, KC_TRNS,
       KC_TRNS, KC_EQUAL, KC_1,    KC_2,    KC_3,     KC_COLN, KC_TRNS,
                               // bottom row
                                KC_0, KC_DOT, KC_COMMA, KC_TRNS,  KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


[SYMBOL] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_AMPR, KC_ASTR, KC_EQUAL,KC_PLUS, KC_TRNS,
                KC_TRNS, KC_DLR,  KC_PERC, KC_CIRC, KC_PIPE, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),



[BRACKET] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[MOUSE] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN1, KC_BTN2
),

[SHORTCUTS] = KEYMAP(
       // left hand
       HYPR(KC_ESC),         HYPR(KC_F1),    HYPR(KC_F2), HYPR(KC_F3),  HYPR(KC_F4), HYPR(KC_F5), HYPR(KC_F6),
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       HYPR(KC_F7), HYPR(KC_F8), HYPR(KC_F9), HYPR(KC_F10),  HYPR(KC_F11), HYPR(KC_F12),  M(SWITCH_NDS),
       KC_TRNS, KC_TRNS, HYPR(KC_7),    HYPR(KC_8),    HYPR(KC_9),    KC_TRNS, KC_TRNS,
                KC_TRNS, HYPR(KC_4),    HYPR(KC_5),    HYPR(KC_6),    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, HYPR(KC_1),    HYPR(KC_2),    HYPR(KC_3),    KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


};

const uint16_t PROGMEM fn_actions[] = {
/*
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
*/    
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case MC_COPY_LINE:
            if (record->event.pressed) {
                return MACRO( T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(C), U(LCTL), END);
            }
            break;
        case MC_CUT_LINE:
            if (record->event.pressed) {
                return MACRO( T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(X), U(LCTL), END);
            }        
            break;
        case MC_PASTE_LINE:
            if (record->event.pressed) {
                return MACRO( T(END), T(ENTER), D(LCTL), T(V), U(LCTL), END);
            }                
            break;
        case MC_NEW_SEARCH_TAB:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(T), T(K), U(LCTL), END);
            }
            break;
        case SCREEN_TAB_LEFT:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(P), END);
            }        
            break;
        case SCREEN_TAB_RIGHT:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(N), END);
            }                    
            break;
        case SCREEN_NEW_TAB:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(C), END);
            }                                
        break;
        case SWITCH_NDS:
             if (record->event.pressed) {
                return MACRO( D(LSFT), T(F11), U(LSFT), D(LALT), T(TAB), U(LALT), END); 
            }                                
        break;        
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

    return;
};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SHELL:
            ergodox_right_led_1_on();
            break;
        case NUMBER:
        case SYMBOL:
        case BRACKET:
            ergodox_right_led_2_on();
            break;
        case KEY_NAV:
        case KEY_SEL:
            ergodox_right_led_3_on();
            break;        
        case SHORTCUTS:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

    return;
};
