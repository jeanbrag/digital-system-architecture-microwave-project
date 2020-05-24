/*
 * SetService.cpp
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#include <SetService.h>


SetService::SetService() {
	// TODO Auto-generated constructor stub

}

void SetService::loadCounters(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){
	ContadorSeg->load(5);
	ContadorSegD->load(2);
	ContadorMin->load(1);
	ContadorMinD->load(0);
}

void SetService::clearCounters(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){
	ContadorSeg->aclear();
	ContadorSegD->aclear();
	ContadorMin->aclear();
	ContadorMinD->aclear();
}

void SetService::pipoca(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){
	ContadorSeg->load(0);
	ContadorSegD->load(3);
	ContadorMin->load(0);
	ContadorMinD->load(0);
}
void SetService::lasanha(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){
	ContadorSeg->load(2);
	ContadorSegD->load(0);
	ContadorMin->load(2);
	ContadorMinD->load(0);
}
void SetService::pizza(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD){
	ContadorSeg->load(1);
	ContadorSegD->load(0);
	ContadorMin->load(1);
	ContadorMinD->load(0);
}
