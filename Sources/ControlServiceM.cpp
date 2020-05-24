/*
 * ControlServiceM.cpp
 *
 *  Created on: 19/12/2019
 *      Author: Jean
 */

#include <ControlServiceM.h>

#include "ControlServiceM.h"

ControlServiceM::ControlServiceM(OperationService *servOP, Botao *btnFimOP, Botao *btnPlayPause, Botao *btnCancel,Key *keyDoor, SignalingService *servSin) {
	this->servOP = servOP;
	this->servSin = servSin;
	this->btnFimOP = btnFimOP;
	this->btnPlayPause = btnPlayPause;
	this->btnCancel = btnCancel;
	this->keyDoor = keyDoor;

	this->typeService = noService;
	this->timingMode = tempOff;
	this->lampState = off;
	this->btnState = noUse;
	this->doorState = closed;
	this->beepState = beepOff;

}
void ControlServiceM:: readInputs(){
  if(!keyDoor->isOn()){
    this->doorState = open;

  }else{
    this->doorState = closed;

    if(btnPlayPause->isOn()){
    	this->btnState = btnPlayPauseState;
    	//this->servSin->delayServ();
    	//this->servSin->delayServ();
    	//this->servSin->delayServ();
    	//this->servSin->delayServ();


    }else if(btnCancel->isOn()){
      this->btnState = btnCancelState;

    }else if(btnFimOP->isOn()){
      this->btnState =  btnFimOPState;
    }
  }
}

void ControlServiceM:: selectService(){
  if(doorState == open){
    if(typeService == startOpServ){
        this->typeService = pauseOpServ;
        this->lampState = on;

    }else if(typeService == endOpServ){
    	this->typeService = noService;
    	this->lampState = on;
    }else{
      this->lampState = on;
    }

  }else{
	  if(this->typeService == endOpServ){
		  this->lampState = on;

	  }else{
		  this->lampState = off;
	  }


    if(btnState == btnPlayPauseState){
      if(this->typeService != startOpServ){
        this->typeService = startOpServ;
        this->timingMode = tempOn;
        this->btnState = noUse;
      }else{
        this->typeService = pauseOpServ;
        this->timingMode = tempPause;
        this->btnState = noUse;
      }
    }
    if(btnState == btnCancelState){
    	this->typeService = cancelOpServ;
    	this->timingMode = tempCancel;
    }
    if(btnState == btnFimOPState){
    	this->btnState = noUse;
    	this->typeService = endOpServ;
    	this->timingMode = tempOff;
    	this->beepState = beepOn;
    	this->lampState = on;

    }

  }

}

void ControlServiceM:: doService(){

}

void ControlServiceM:: writeOutputs(){
  if(lampState == on or doorState == open){
    this->servOP->openDoor();
  }else{
    this->servOP->closedDoor();
  }
  if(typeService == startOpServ){
    this->servOP->startOP();
  }
  if(typeService == pauseOpServ){
    this->servOP->pauseOP();
  }
  if(typeService == cancelOpServ){
    this->servOP->cancelOP();
  }
  if((typeService == endOpServ) and (beepState == beepOn)){
	this->beepState = beepOff;
    this->servOP->endOP();
  }else if(typeService == endOpServ){
	  this->servOP->openDoor();
  }

}

door_t ControlServiceM::readDoor(){
	return doorState;
}
