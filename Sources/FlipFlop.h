/*
 * FlipFlop.h
 * Jean Cleison Braga Guimaraes
 */

#ifndef FLIPFLOP_H_
#define FLIPFLOP_H_
#include <stdint.h>

class FlipFlop {
	protected:
		uint32_t dataa;
		bool cin;
	public:
		FlipFlop();
		void setDataA(uint8_t dt);
		void enable();
		void disable();
		bool flipFlop();
		bool apagaLed();
};

#endif /* FLIPFLOP_H_ */
