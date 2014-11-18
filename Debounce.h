#ifndef Debounce_H
#define Debounce_H

#include <Arduino.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h" 

class Debounce {
public:
	Debounce(int pin, long delay);
	int getPin();
	void setPin(int pin);
	int state();
	void setDebounceDelay(long d);
	long getDebounceDelay();
private:
	int _state;
	int _pin;
	int _lastButtonState;
	long _lastDebounceTime;
	long _debounceDelay;
};

#endif