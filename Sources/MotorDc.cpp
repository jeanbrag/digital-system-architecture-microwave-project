/*
 * MotorDc.cpp
 *
 *  Created on: 27/11/2019
 *      Author: frank
 */

#include "MotorDc.h"

MotorDc::MotorDc(gpio_Pin pinA, gpio_Pin pinB, tpm_Pin pinC) {
	this->duty = 1000;
	this->portA = mkl_GPIOPort(pinA);
	portA.setPortMode(gpio_output);
	portA.writeBit(0);

	this->portB = mkl_GPIOPort(pinB);
	portB.setPortMode(gpio_output);
	portB.writeBit(0);

	this->portC = mkl_TPMPulseWidthModulation(pinC);
	portC.disableOperation();
	portC.setFrequency(tpm_div16,999);
	portC.setDutyCycle(duty);
	portC.enableOperation();

}
void MotorDc:: setPortA(bool a){
	this->portA.writeBit(a);
}
void MotorDc:: setPortB(bool b){
	this->portB.writeBit(b);
}
void MotorDc:: setDutyCicle(uint8_t duty){
	this->duty = duty;
}
void MotorDc::enableOperation(){
	portC.enableOperation();
}
void MotorDc::disableOperation(){
	portC.disableOperation();
}
uint8_t MotorDc::getDutyCicle(){
	return this->duty;
}
