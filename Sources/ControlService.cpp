/*
 * ControlService.cpp
 * Jean Cleison Braga Guimaraes
 */

#include <ControlService.h>

ControlService::ControlService() {
	// TODO Auto-generated constructor stub
	incr = 0;
	btn = noUse;
	sid = noService;
	led = off;
	cook = edicao;
	buf = '0';

}

void ControlService::readInputs(Botao *play, Botao *inc, Botao *Pizza){
	//bluetooth



	//fim bluetooth
	if(inc->isOn()){
			//Delay1(1300);
			//if(!inc->isOn()){
				this->btn = btnInc7;
				//cook = inc7;


		}
	else if(play->isOn()){
		//Delay1(1300);
		//if(!play->isOn())
			this->btn = btnPlayPauseState;
	}

	else if(this->buf == '1')
		this->btn = btnPlayPauseState;
	else if(this->buf == '2')
		this->btn = btnPlayPauseState;
	else if(this->buf == '3')
		this->btn = btnPip;
	else if(this->buf == '4')
		this->btn = btnPiz;
	else if(this->buf == '5')
		this->btn = btnLas;

	else if(Pizza->isOn()){
		//Delay1(1300);
		//if(!Pizza->isOn()){
			this->btn = btnPiz;
			//cook = pizza;
	}

	else
		this->btn = noUse;
}
void ControlService::selectService(btn_t btn){
		switch(btn){
			case btnInc3:	sid = incrementService;
							break;
			case btnInc5: 	sid = incrementService;
							break;
			case btnInc7:   sid = incrementService;
							break;
			case btnLas: 	sid = setService;
							break;
			case btnPip:	sid = setService;
							break;
			case btnPiz:	sid = setService;
							break;
			case btnPlayPauseState: sid = setService;
									break;

			default: sid = printService;
		}
}

void ControlService::doService(	sid_t sid,
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
								Dec2ascii Decoder){

	switch(sid){
			case incrementService:	Delay1(1000);
									if(this->btn == btnInc3)
										serviceInc.incrementa(3,ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
									else if(this->btn == btnInc5)
										serviceInc.incrementa(5,ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
									else if(this->btn == btnInc7){
										if(!inc->isOn()){
											cook = inc7;
											serviceInc.incrementa(7,ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
										}
										}
									break;

			case decrementService:	if(ContadorSeg->readCin())
									serviceDec.decrementa(ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
									break;

			case setService:	if(this->btn == btnPiz){
									Delay1(1000);
									if(!Pizza->isOn()){
										serviceSet.pizza(ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
										cook = pizza;
									}
								}
								if(this->btn == btnLas){
									Delay1(1000);
									if(!Pizza->isOn()){
										serviceSet.lasanha(ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
										cook = lasanha;
																		}
								}
								if(this->btn == btnPip){
									Delay1(1000);
									if(!Pizza->isOn()){
										serviceSet.pipoca(ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
										cook = pipoca;
																										}
																}
								if(this->btn == noUse)
									serviceSet.loadCounters(ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
								if(this->btn == btnPlayPauseState){
										Delay1(1000);
										if(this->buf == '2'){
											serviceSet.clearCounters(ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD);
										}
										if(!play->isOn()){
										if(ContadorSeg->readCin()){
											this->giro = g_off;
											ContadorSeg->disable();
										}
										else{
											this->giro = g_on;
											ContadorSeg->enable();
										}
										}
									}
									break;


			case printService: 		servicePrint.print(lcd,ContadorSeg,ContadorSegD,ContadorMin,ContadorMinD,Tipo,Porta,Giro,Decoder);
									break;

		}
}

void ControlService::writeOutputs(Led led,Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){

	if((ContadorSeg->readQ()==0) and (ContadorSegD->readQ()==0) and (ContadorMin->readQ()==0) and (ContadorMinD->readQ()==0)){
		led.turnOn();
		this->giro = g_off;
		ContadorSeg->disable();
		ContadorSegD->disable();
		ContadorMin->disable();
		ContadorMinD->disable();
	}

	if(this->btn == btnPlayPauseState)
		led.turnOff();



	}


btn_t ControlService::readBtn(){
	return btn;
}

sid_t ControlService::readSid(){
	return sid;
}

void ControlService::setSid(sid_t a){
	this->sid = a;
}

cook_t ControlService::readCook(){
	return cook;
}

giro_t ControlService::readGiro(){
	return giro;
}

void ControlService::setBuf(uint8_t dt){
	this->buf = dt;
}
