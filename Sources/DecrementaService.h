/*
 * DecrementaService.h
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#ifndef SOURCES_DECREMENTASERVICE_H_
#define SOURCES_DECREMENTASERVICE_H_

#include "Contador.h"

class DecrementaService {
private:
	bool a;
public:
	DecrementaService();
	void decrementa(Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
};

#endif /* SOURCES_DECREMENTASERVICE_H_ */
