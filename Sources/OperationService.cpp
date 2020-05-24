/*
 * OperationService.cpp
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#include "OperationService.h"

OperationService::OperationService(RotatingService *servGiro,SignalingService *servSin, Delay *delay) {
	this->servGiro = servGiro;
	this->servSin = servSin;
	this->delay = delay;
}
void OperationService:: startOP(){
	this->servSin->lampadaTurnOff();
	this->servGiro->motorTurnOn();
	this->servSin->tempTurnOn();

}
void OperationService:: pauseOP(){
	this->servGiro->motorTurnOff();
	this->servSin->tempTurnOff();
}

void OperationService:: cancelOP(){
	this->servGiro->motorTurnOff();
	this->servSin->tempTurnOff();
}

void OperationService:: endOP(){
	this->servGiro->motorTurnOff();
	this->servSin->lampadaTurnOn();
	this->servSin->tempTurnOff();
	//this->servSin->beep();
	this->servSin->beepOn();
	int i = 0;
	while(i < 9){
		this->delay->delay();
		i++;
	}
	this->servSin->beepOff();
}
void OperationService:: openDoor(){
	this->servSin->lampadaTurnOn();
}
void OperationService:: closedDoor(){
	this->servSin->lampadaTurnOff();
}
