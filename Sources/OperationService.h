/*
 * OperationService.h
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#ifndef OPERATIONSERVICE_H_
#define OPERATIONSERVICE_H_
#include "RotatingService.h"
#include "SignalingService.h"
#include "Delay.h"

class OperationService {
	RotatingService *servGiro;
	SignalingService *servSin;
	Delay *delay;

public:
	OperationService(RotatingService *servGiro,SignalingService *servSin, Delay *delay);
	void startOP();
	void pauseOP();
	void cancelOP();
	void endOP();
	void openDoor();
	void closedDoor();
};

#endif /* OPERATIONSERVICE_H_ */
