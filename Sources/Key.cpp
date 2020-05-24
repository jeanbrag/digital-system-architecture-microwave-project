/*
 * Key.cpp
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#include <Key.h>

Key::Key(gpio_Pin pin) : mkl_GPIOPort(pin) {
	setPortMode(gpio_input);
	setPullResistor(gpio_pullUpResistor);
}
bool Key::isOn(){
	if(readBit() == 0){
		return 1;
	}else{
		return 0;
	}
}
