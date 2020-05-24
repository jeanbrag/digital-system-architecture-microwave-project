/*
 * Buzzer.h
 *
 *  Created on: 07/11/2019
 *      Author: frank
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include <mkl_GPIOPort.h>

class Buzzer :mkl_GPIOPort {

public:
	Buzzer(gpio_Pin pin);
	void buzzerTurnOn();
	void buzzerTurnOff();
};

#endif /* BUZZER_H_ */
