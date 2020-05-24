/*
 * RotatingService.cpp
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#include "RotatingService.h"


RotatingService::RotatingService(MotorDc *motor) {
	this->motorA = motor;

}
void RotatingService::motorTurnOn(){
	this->motorA->setPortA(1);
	this->motorA->setPortB(0);
	this->motorA->setDutyCicle(this->motorA->getDutyCicle());
	this->motorA->enableOperation();
}
void RotatingService::motorTurnOff(){
	this->motorA->setPortA(0);
	this->motorA->setPortB(0);
	this->motorA->disableOperation();
	this->motorA->setDutyCicle(0);
}

void RotatingService::motorPause(){
	this->motorA->setPortA(0); // desligado pq o cooler nao freia.
	this->motorA->setPortB(0);
}
