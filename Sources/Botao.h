/*
 * Botao.h
 * Jean Cleison Braga Guimaraes
 */

#ifndef BOTAO_H_
#define BOTAO_H_
#include "mkl_GPIOPort.h"

class Botao : mkl_GPIOPort {

	public:
		Botao(gpio_Pin pin);
		bool isOn();
};

#endif /* BOTAO_H_ */
