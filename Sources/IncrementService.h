/*
 * IncrementService.h
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#ifndef SOURCES_INCREMENTSERVICE_H_
#define SOURCES_INCREMENTSERVICE_H_

#include "Contador.h"
#include "stdint.h"

class IncrementService {
private:
	bool a;
public:
	IncrementService();
	void incrementa(uint8_t t, Contador *ContadorSeg, Contador *ContadorSegD, Contador *ContadorMin, Contador *ContadorMinD);
};

#endif /* SOURCES_INCREMENTSERVICE_H_ */
