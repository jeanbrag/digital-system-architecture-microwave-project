/*
 * SignalingService.h
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#ifndef SIGNALINGSERVICE_H_
#define SIGNALINGSERVICE_H_
#include "Led.h"
#include "Buzzer.h"
#include "Delay.h"

class SignalingService {
	//TEMPORARIO
		Led *ledTemp;
	//PERMANENTE
		Led *lampada;
		Buzzer *buzina;
		Delay *delay;
		int i;
public:
	SignalingService(Led *ledTemp, Led *lamp, Buzzer *buzina, Delay *delay);
	void lampadaTurnOn();
	void lampadaTurnOff();
	void tempTurnOn();
	void tempTurnOff();
	void beep();
	void beepOn();
	void beepOff();
	void delayServ();
};

#endif /* SIGNALINGSERVICE_H_ */
