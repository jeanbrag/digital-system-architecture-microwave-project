/*
 * FlipFlop.cpp
 * Jean Cleison Braga Guimaraes
 */

#include "FlipFlop.h"

FlipFlop::FlipFlop() {
	dataa;
	cin = 0;
}
void FlipFlop:: setDataA( uint8_t dt){
	if(cin)
		this->dataa = dt;
}

bool FlipFlop:: flipFlop(){
	if( (this->dataa == 1) and (this->cin == 1)){
		return 1;
	}else{
		return 0;
	}
}
bool FlipFlop:: apagaLed(){
	this->dataa = 0;
	return 0;
}

void FlipFlop::enable(){
	this->cin = 1;
}
void FlipFlop::disable(){
	this->cin = 0;
}
