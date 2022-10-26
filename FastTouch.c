#include "FastTouch.h"


int fastTouchRead(str pin)
{
    int i;
    pinMode(pin, OUTPUT_OPENDRAIN);
    digitalWrite(pin, LOW);
    delayMicroseconds(1);
    /* disable interrupts */
    noInterrupts();
	pinMode(pin, INPUT_PULLUP);
    i=0;
    for (int i = 0; i < 64; i++) {
		if (digitalRead(pin) != 0) {
			goto out;
		}

out:
    interrupts();
    return i;
}