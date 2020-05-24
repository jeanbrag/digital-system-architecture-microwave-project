/*
 * Buzzer.cpp
 *
 *  Created on: 07/11/2019
 *      Author: frank
 */

#include "Buzzer.h"

Buzzer::Buzzer(gpio_Pin pin) : mkl_GPIOPort(pin) {
	setPortMode(gpio_output);
	writeBit(0);
}
void Buzzer:: buzzerTurnOn(){
	writeBit(1);
}
void Buzzer:: buzzerTurnOff(){
	writeBit(0);
}

