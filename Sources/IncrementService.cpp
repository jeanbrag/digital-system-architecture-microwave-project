/*
 * IncrementService.cpp
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#include <IncrementService.h>

IncrementService::IncrementService() {
	// TODO Auto-generated constructor stub
	a = 0;
}

void IncrementService::incrementa(uint8_t t,Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){
	this->a = ContadorSeg->incrementa(t);
	if(this->a){
		this->a = ContadorSegD->incrementa(1);
		if(this->a)
			this->a = ContadorMin->incrementa(1);
		if(this->a)
			ContadorMinD->incrementa(1);
	}

}
