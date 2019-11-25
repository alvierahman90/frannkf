/*

Written by Alvie Rahman (alvierahman90)

TODO: add license
*/

#include "keymap.h"
#include "util.h"

int analogxval = -1;
int analogyval = -1;
int analogzval = -1;
int analogzrotateval = -1;
int analogsliderleftval = -1;
int analogsliderrightval = -1;

// handle key state change
void hkschange(int row, int column, int current_state) {
	if (current_state != keymap[row][column].is_pressed) {
		keymap[row][column].is_pressed = current_state;
		if (keymap[row][column].key_type == KB) {
			hkbschange(row, column, current_state);
		} else if (keymap[row][column].key_type == JS) {
			hjsschange(row, column, current_state);
		}
	}
}

// handle keyboard state change
void hkbschange(int row, int column, int current_state) {
	if (current_state == HIGH) {
		Keyboard.press(keymap[row][column].key);
	} else {
		Keyboard.release(keymap[row][column].key);
	}
}

// handle joystick state change
void hjsschange(int row, int column, int current_state) {
	Joystick.button(keymap[row][column].key, current_state);
}

void setup() {
	// set up pins for matrix

	int i;
	for (i = 0; i < rowc; i++) {
		pinMode(rows[i], OUTPUT);
		digitalWrite(rows[i], LOW);
	}
 
	for (i = 0; i < columnc; i++) {
		pinMode(columns[i], INPUT);
	}

	// light led pin
	pinMode(led_pin, OUTPUT);
	digitalWrite(led_pin, HIGH);

	Serial.begin(9600);
}

void update_joysticks(){
	// temp variable to hold potentiometer values to compare to current
	// values
	int njsval = -1;

	if (analogx != -1) {
		njsval = analogRead(analogx);
		// only send update if value changed 
		if (njsval != analogxval) {
			analogxval = njsval;
			Joystick.X(analogRead(analogx));
		}
	}
	if (analogy != -1) {
		njsval = analogRead(analogy);
		if (njsval != analogyval) {
			analogyval = njsval;
			Joystick.Y(analogRead(analogy));
		}
	}
	if (analogz != -1) {
		njsval = analogRead(analogz);
		if (njsval != analogzval) {
			analogzval = njsval;
			Joystick.Z(analogRead(analogz));
		}
	}
	if (analogzrotate != -1) {
		njsval = analogRead(analogzrotate);
		if (njsval != analogzrotateval) {
			analogzrotateval = njsval;
			Joystick.Zrotate(analogRead(analogzrotate));
		}
	}
	if (analogsliderleft != -1) {
		njsval = analogRead(analogsliderleft);
		if (njsval != analogsliderleftval) {
			analogsliderleftval = njsval;
			Joystick.sliderLeft(analogRead(analogsliderleft));
		}
	}
	if (analogsliderright != -1) {
		njsval = analogRead(analogsliderright);
		if (njsval != analogsliderrightval) {
			analogsliderrightval = njsval;
			Joystick.sliderLeft(analogRead(analogsliderright));
		}
	}
}

void loop() {
	// put your main code here, to run repeatedly:
	for (int i = 0; i < rowc; i++ ) {
		digitalWrite(rows[i], HIGH);
		for (int ii = 0; ii < columnc; ii++) {
			hkschange(i, ii,
				digitalRead(columns[ii])
			);
		}
		digitalWrite(rows[i], LOW);
	}

	update_joysticks();

	delay(2);
}
