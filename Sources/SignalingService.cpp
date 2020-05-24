/*
 * SignalingService.cpp
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#include "SignalingService.h"

SignalingService::SignalingService(Led *ledTemp, Led *lamp, Buzzer *buzina, Delay *delay) {
	this->ledTemp = ledTemp;
	this->lampada = lamp;
	this->buzina = buzina;
	this->delay = delay;
	this->i = 0;

}
void SignalingService::beep(){
	this->buzina->buzzerTurnOn();
	int a = 0;
	while(a < 9){
		a = a + 1;
		this->delay->delay();
	}

	this->buzina->buzzerTurnOff();
}
void SignalingService::beepOn(){
	this->buzina->buzzerTurnOn();
}
void SignalingService::beepOff(){
	this->buzina->buzzerTurnOff();
}
void SignalingService::lampadaTurnOn(){
	this->lampada->turnOn();
}
void SignalingService::lampadaTurnOff(){
	this->lampada->turnOff();
}
void SignalingService::tempTurnOn(){
	this->ledTemp->turnOn();
}
void SignalingService::tempTurnOff(){
	this->ledTemp->turnOff();
}
void SignalingService::delayServ(){
	this->delay->delay();
}
