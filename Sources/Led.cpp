/*
 * Led.cpp
 * Jean Cleison Braga Guimaraes
 */

#include "Led.h"


Led::Led(gpio_Pin pin) : mkl_GPIOPort(pin){
	setPortMode(gpio_output);
	writeBit(0);
}
void Led::turnOn(){
	writeBit(0);
}
void Led::turnOff(){
	writeBit(1);
}


