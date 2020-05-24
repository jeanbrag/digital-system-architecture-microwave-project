/*
 * Botao.h
 *
 *  Created on: 22/09/2019
 *      Author: frank
 */

#ifndef BUTTON_H_
#define BUTTON_H_
#include <mkl_GPIOPort.h>

class Button : mkl_GPIOPort {

	public:
		Button(gpio_Pin pin);
		bool isPressed();
};

#endif /* BUTTON_H_ */
