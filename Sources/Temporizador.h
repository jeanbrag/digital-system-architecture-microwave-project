/*
 * Temporizador.h
 * Jean Cleison Braga Guimaraes
 */

#ifndef SOURCES_TEMPORIZADOR_H_
#define SOURCES_TEMPORIZADOR_H_
#include "mkl_SystickPeriodicInterrupt.h"


class Temporizador : mkl_SystickPeriodicInterrupt {
	protected:


	public:
		Temporizador(uint32_t time_ms, systick_clockSource clock= clock2Mhz);
		void liga();
		void desliga();

};

#endif /* SOURCES_TEMPORIZADOR_H_ */
