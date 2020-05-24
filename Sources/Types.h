/*
 * Types.h
 *
 *  Created on: 30/11/2019
 *      Author: frank
 */

#ifndef SOURCES_TYPES_H_
#define SOURCES_TYPES_H_


enum sid_t {
	noService,
	startOpServ,
	pauseOpServ,
	cancelOpServ,
	endOpServ,
	incrementService,
	decrementService,
	setService,
	printService
};
enum btn_t{
	noUse,
	btnPlayPauseState,
	btnCancelState,
	btnFimOPState,
	btnEdicao,
	btnInc3,
	btnInc5,
	btnInc7,
	btnLas,
	btnPip,
	btnPiz
};
enum temp_t{
	tempOn,
	tempPause,
	tempCancel,
	tempOff
};
enum door_t {
  	open,
	closed
};
enum lamp_t{
	on,
	off
};
enum beep_t {
	beepOn,
	beepOff
};

enum cook_t{
	edicao,
	inc3,
	inc5,
	inc7,
	lasanha,
	pizza,
	pipoca
};

enum giro_t{
	g_on,
	g_off
};

enum valv_t{
	v_on,
	v_off
};

enum tipo_contador{
	Segundo,
	SegundoDec,
	Minuto,
	MinutoDec
};


#endif /* SOURCES_TYPES_H_ */
