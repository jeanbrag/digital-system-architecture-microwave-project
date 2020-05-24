/*
 * SetService.h
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#ifndef SOURCES_SETSERVICE_H_
#define SOURCES_SETSERVICE_H_

#include "Contador.h"

class SetService {
public:
	SetService();
	void loadCounters(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
	void clearCounters(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
	void pipoca(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
	void lasanha(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
	void pizza(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
};

#endif /* SOURCES_SETSERVICE_H_ */
