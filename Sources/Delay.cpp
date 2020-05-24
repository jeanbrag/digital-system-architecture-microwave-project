/*
 * Delay.cpp
 *
 *  Created on: 28/11/2019
 *      Author: frank
 */

#include "Delay.h"

Delay::Delay(tpm_TPMNumberMask pin) : mkl_TPMDelay(pin) {
	setFrequency(tpm_div128);
}
void Delay::delay(){
	waitDelay(16382); // ciclos para 100ms
}
