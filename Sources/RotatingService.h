/*
 * RotatingService.h
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#ifndef SOURCES_ROTATINGSERVICE_H_
#define SOURCES_ROTATINGSERVICE_H_
#include "MotorDc.h"


class RotatingService {
	MotorDc *motorA;

public:
	RotatingService(MotorDc *motor);
	void motorTurnOn();
	void motorTurnOff();
	void motorPause();
};

#endif /* SOURCES_ROTATINGSERVICE_H_ */
