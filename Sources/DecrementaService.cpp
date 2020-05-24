/*
 * DecrementaService.cpp
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#include <DecrementaService.h>

DecrementaService::DecrementaService() {
	// TODO Auto-generated constructor stub
	a = 0;
}

void DecrementaService::decrementa(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){
		this->a = ContadorSeg->decrementa();
	if(this->a){
		this->a = ContadorSegD->decrementa();
		if(this->a)
			this->a = ContadorMin->decrementa();
		if(this->a)
			ContadorMinD->decrementa();
	}

}
