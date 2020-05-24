/*
 * Delay.h
 *
 *  Created on: 28/11/2019
 *      Author: frank
 */

#ifndef DELAY_H_
#define DELAY_H_
#include <mkl_TPMDelay.h>

class Delay : mkl_TPMDelay {
public:
	Delay(tpm_TPMNumberMask pin);
	void delay();
};

#endif /* DELAY_H_ */
