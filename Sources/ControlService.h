/*
 * ControlService.h
 * Jean Cleison Braga Guimaraes
 */

#ifndef SOURCES_CONTROLSERVICE_H_
#define SOURCES_CONTROLSERVICE_H_

#include <stdlib.h>
#include "Types.h"
#include "Led.h"
#include "Contador.h"
#include "Temporizador.h"
#include "IncrementService.h"
#include "DecrementaService.h"
#include "SetService.h"
#include "PrintService.h"
#include "mkl_LCD.h"
#include "delay_lcd.h"
#include "Botao.h"

class ControlService {
	private:
		btn_t btn;
		sid_t sid;
		lamp_t led;
		door_t door;
		cook_t cook;
		valv_t valv;
		giro_t giro;
		int incr;
		uint8_t buf;

	public:
		ControlService();
		void readInputs(Botao *play, Botao *inc, Botao *Pizza);
		void selectService(btn_t btn);
		void doService(	sid_t sid,
						mkl_LCD lcd,
						Botao *inc,
						Botao *play,
						Botao *Pizza,
						Contador *ContadorSeg,
						Contador *ContadorSegD,
						Contador *ContadorMin,
						Contador *ContadorMinD,
						IncrementService serviceInc,
						DecrementaService serviceDec,
						SetService serviceSet,
						PrintService servicePrint,
						cook_t Tipo,
						door_t Porta,
						giro_t Giro,
						Dec2ascii Decoder);
		void writeOutputs(Led led, Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
		btn_t readBtn();
		sid_t readSid();
		void setSid(sid_t a);
		cook_t readCook();
		giro_t readGiro();
		void setBuf(uint8_t);

};

#endif /* SOURCES_CONTROLSERVICE_H_ */
