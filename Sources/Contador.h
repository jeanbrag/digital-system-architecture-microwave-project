/*
 * lpmCounter.h
 * Jean Cleison Braga Guimaraes
 */

#ifndef CONTADOR_H_
#define CONTADOR_H_
#include <stdint.h>
#include "Types.h"

class Contador{
protected:
	volatile uint8_t q;
	bool cin;
	tipo_contador tipo;
public:
	Contador();
	void load(uint8_t data);
	bool incrementa(uint8_t t);
	bool decrementa();
	uint8_t readQ();
	void aclear();
	void enable();
	void disable();
	bool readCin();
	void setTipo(tipo_contador tp);
};

#endif /* CONTADOR_H_ */
