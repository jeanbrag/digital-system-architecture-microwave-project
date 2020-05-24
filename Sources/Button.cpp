/*
 * Botao.cpp
 *
 *  Created on: 22/09/2019
 *      Author: frank
 */

#include "Button.h"

Button::Button(gpio_Pin pin) : mkl_GPIOPort(pin) {
	setPortMode(gpio_input);
	setPullResistor(gpio_pullUpResistor);
}
bool Button::isPressed(){
	if(readBit() == 0){

		return 1;
	}else{
		return 0;
	}
}

