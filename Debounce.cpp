
#include <Arduino.h>
#include "Debounce.h"

Debounce::Debounce(int pin, long delay)
{
	this->setPin(pin);
	this->_debounceDelay = delay;
	this->_lastDebounceTime = 0;
	this->_lastButtonState = 0;
	this->_state = 0;
}

void Debounce::setDebounceDelay(long d)
{
	this->_debounceDelay = d;
}

long Debounce::getDebounceDelay()
{
	return this->_debounceDelay;
}

void Debounce::setPin(int pin)
{
	pinMode(pin, INPUT);
	this->_pin = pin;
}

int Debounce::getPin()
{
	return this->_pin;
}

int Debounce::state()
{
	int reading = digitalRead(this->_pin);
	// If the switch changed, due to noise or pressing:
	if (reading != this->_lastButtonState) {
    // reset the debouncing timer
		this->_lastDebounceTime = millis();
	}
	this->_lastButtonState = reading;
	
	if ((millis() - this->_lastDebounceTime) > this->_debounceDelay) {
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:
		// if the button state has changed:
		if (reading != this->_state) {
			this->_state = reading;      
		}
	}
	
	return this->_state;
}