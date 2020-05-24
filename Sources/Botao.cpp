/*
 * Botao.cpp
 * Jean Cleison Braga Guimaraes
 */

#include "Botao.h"

Botao::Botao(gpio_Pin pin) : mkl_GPIOPort(pin) {
	setPortMode(gpio_input);
	setPullResistor(gpio_pullUpResistor);
}
bool Botao::isOn(){
	if(readBit() == 0){

			return 1;
		}else{
			return 0;
		}
}

