/*
 * PrintService.h
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#ifndef SOURCES_PRINTSERVICE_H_
#define SOURCES_PRINTSERVICE_H_
#include "Contador.h"
#include "Types.h"
#include "dec2ascii.h"
#include "mkl_LCD.h"

class PrintService {
public:
	PrintService();
	void print(	mkl_LCD lcd,
				Contador *ContadorSeg,
				Contador *ContadorSegD,
				Contador *ContadorMin,
				Contador *ContadorMinD,
				cook_t Tipo,
				door_t Porta,
				giro_t Giro,
				Dec2ascii Decoder);
};

#endif /* SOURCES_PRINTSERVICE_H_ */
