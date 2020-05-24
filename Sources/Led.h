/*
 * Led.h
 * Jean Cleison Braga Guimaraes
 */

#ifndef LED_H_
#define LED_H_
#include "mkl_GPIOPort.h"

class Led :mkl_GPIOPort{

	public:
		Led(gpio_Pin pin);
		void turnOn();
		void turnOff();
};

#endif /* LED_H_ */
