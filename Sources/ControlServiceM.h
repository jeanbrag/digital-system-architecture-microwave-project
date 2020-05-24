/*
 * ControlServiceM.h
 *
 *  Created on: 19/12/2019
 *      Author: Jean
 */

#ifndef SOURCES_CONTROLSERVICEM_H_
#define SOURCES_CONTROLSERVICEM_H_

#include "OperationService.h"
#include "SignalingService.h"
#include "Delay.h"
#include "Buzzer.h"
#include "Botao.h"
#include "Key.h"
#include "Types.h"


class ControlServiceM {
	//TEMPORIRIO
		Botao *btnFimOP;
	//PERMANENTE
		OperationService *servOP;
		SignalingService *servSin;
		Botao *btnPlayPause;
		Botao *btnCancel;
		Key *keyDoor;

	//Estados
		sid_t typeService;
		temp_t timingMode;
		lamp_t lampState;
		btn_t btnState;
		door_t doorState;
		volatile beep_t beepState;

public:
	ControlServiceM(OperationService *servOP, Botao *btnFimOP, Botao *btnPlayPause, Botao *btnCancel, Key *keyDoor, SignalingService *servSin);
	void readInputs();
	void selectService();
	void doService();
	void writeOutputs();
	door_t readDoor();
};
#endif /* SOURCES_CONTROLSERVICEM_H_ */
