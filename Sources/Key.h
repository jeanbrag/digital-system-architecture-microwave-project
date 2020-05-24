/*
 * Key.h
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#ifndef SOURCES_KEY_H_
#define SOURCES_KEY_H_
#include <mkl_GPIOPort.h>

class Key : mkl_GPIOPort{

public:
	Key(gpio_Pin pin);
	bool isOn();
};

#endif /* SOURCES_KEY_H_ */
