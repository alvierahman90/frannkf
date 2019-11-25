#ifndef KEYMAP_H
#define KEYMAP_H

#include "util.h"

/* matrix dimensions */
#define rowc 3
#define columnc 3

#define led_pin 6

/* key matrix pins */
int rows[rowc] = {38, 39, 40}; // bottom to top
int columns[columnc] = {45, 44, 43}; // left to right

/* potentiometer pins for analog control */
int analogx = 42;
int analogy = -1;
int analogz = -1;
int analogzrotate = -1;
int analogsliderleft = -1;
int analogsliderright = -1;

/* the keymap itself */
Key keymap[rowc][columnc] = { \
	{ dk(JS, 1),     dk(KB, KEY_W), dk(JS, 3)     }, \
	{ dk(KB, KEY_A), dk(KB, KEY_S), dk(KB, KEY_D) }, \
	{ dk(JS, 7),     dk(JS, 8),     dk(JS, 9)     }
};

#endif
