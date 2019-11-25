#ifndef UTIL_H
#define UTIL_H

/* structs and enums */

enum KeyType{KB, JS}; // KB -> keyboard; JS -> joystick

typedef struct Key {
	enum KeyType key_type;
	int key;
	int is_pressed;
} Key;

/* dk -> donkey kong/define key */
Key dk(enum KeyType key_type, int key) { 
	Key r;
	r.key_type = key_type;
	r.key = key;
	r.is_pressed = 0;

	return r;
};

#endif
