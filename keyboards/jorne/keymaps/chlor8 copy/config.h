/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD // hitting both shift keys will turn on caps word
#define CAPS_WORD_IDLE_TIMEOUT 3000 /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
#define TAPPING_TERM_PER_KEY // tap dance set per key, default below
#define TAPPING_TERM 150
// #define QUICK_TAP_TERM 150
#define FLOW_TAP_TERM 100