/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _ONEHAND,
  _LOWER,
  _RAISE,
  _UTIL,
  _UTIL2,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  ONEHAND,
  EISU,
  KANA,
  SFTLINE
};

#define KC_APSC LALT(KC_PSCR)
#define KC_SINS LSFT(KC_INS)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define UTIL MO(_UTIL)
#define UTIL2 MO(_UTIL2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  :   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Onehnd| GUI  | Alt  |UTIL2 |LOWER |Space | UTIL |RAISE | Bksp | Del  |Enter |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_MINS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, JP_COLN,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, JP_BSLS,
    ONEHAND, KC_LGUI, KC_LALT, UTIL2,   LOWER,   KC_SPC,  UTIL,    RAISE,   KC_BSPC, KC_DEL,  KC_ENT,  XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  ^   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  |  @   |  [   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Del  |      |      |  \   |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    JP_CIRC,
    KC_LCTL, KC_EXLM, JP_DQT,  KC_HASH, KC_DLR,  KC_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_AT,   JP_LBRC,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  _______, _______, JP_YEN,  JP_RBRC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |  Up  |      |      |      |  7   |  8   |  9   |      |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down |Right |      | Bksp |  4   |  5   |  6   |      |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Enter |  1   |  2   |  3   |      |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  0   |  0   |  .   |      |  +   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_ESC,  XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_SLSH,
    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_BSPC, KC_BSPC, KC_4,    KC_5,    KC_6,    JP_ASTR,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  KC_1,    KC_2,    KC_3,    JP_MINS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, KC_0,    KC_0,    KC_DOT,  JP_PLUS
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |      |  Up  |      |  F4  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F2  | Left | Down |Right |  F5  | SLCK | Ins  | Home |PageUp|Pause |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F3  |      |      |      |  F6  | PSCR | Del  | End  |PageDn|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, KC_F1,   XXXXXXX, KC_UP,   XXXXXXX, KC_F4,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_F2,   KC_LEFT, KC_DOWN, KC_RGHT, KC_F5,   KC_SLCK, KC_INS,  KC_HOME, KC_PGUP, KC_PAUS, XXXXXXX,
    _______, KC_F3,   XXXXXXX, XXXXXXX, XXXXXXX, KC_F6,   KC_PSCR, KC_DEL,  KC_END,  KC_PGDN, XXXXXXX, XXXXXXX,
    _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* UTIL
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Cut  | Copy |Paste |      |s(ins)|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | EISU | KANA |      |SFTLIN|Apscr |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |Kanji |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |Enter |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UTIL] =  LAYOUT_planck_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, KC_SINS, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EISU,    KANA,    XXXXXXX, SFTLINE, KC_APSC, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_ZHTG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* UTIL2
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_UTIL2] =  LAYOUT_planck_grid(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Aviutil
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      | Bksp |      | Home |PageUp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Enter | Del  | End  |PageDn|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |RShift| Num1 |  Up  | Num2 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty|      |      |      |      |Space |Space |      |RCtrl | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_ONEHAND] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, KC_HOME, KC_PGUP,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  KC_DEL,  KC_END,  KC_PGDN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, KC_KP_1, KC_UP,   KC_KP_2,
    QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_SPC,  XXXXXXX, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case ONEHAND:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_ONEHAND);
      }
      return false;
      break;
    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LANG1);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG1);
      }
      return false;
      break;
    case SFTLINE:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME)SS_DOWN(X_LSHIFT)SS_TAP(X_END)SS_UP(X_LSHIFT));
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
