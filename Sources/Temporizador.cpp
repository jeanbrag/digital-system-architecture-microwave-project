/*
 * Temporizador.cpp
 * Jean Cleison Braga Guimaraes
 */

#include <Temporizador.h>

Temporizador::Temporizador(uint32_t time_ms, systick_clockSource clock) : mkl_SystickPeriodicInterrupt(time_ms,clock) {

}
void Temporizador::liga(){
	clearCounter();
	enableCounter();
	enableInterruptRequest();
}
void Temporizador::desliga(){
	disableInterruptRequest();
	disableCounter();
}
