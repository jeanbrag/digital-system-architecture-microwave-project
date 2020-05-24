/*
 * MotorDc.h
 *
 *  Created on: 27/11/2019
 *      Author: frank
 */

#ifndef MOTORDC_H_
#define MOTORDC_H_
#include "mkl_GPIOPort.h"
#include "mkl_TPMPulseWidthModulation.h"
#include "stdint.h"

class MotorDc  {
	mkl_GPIOPort portA;
	mkl_GPIOPort portB;
	mkl_TPMPulseWidthModulation portC;
	uint8_t duty;

public:
	MotorDc(gpio_Pin pinA,gpio_Pin pinB, tpm_Pin pinC);
	void setPortA(bool a);
	void setPortB(bool b);
	void setDutyCicle(uint8_t duty);
	void enableOperation();
	void disableOperation();
	uint8_t getDutyCicle();
	void motorTurnSpeed();

};

#endif /* MOTORDC_H_ */
