/*
 * dec2ascii.h
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#ifndef SOURCES_DEC2ASCII_H_
#define SOURCES_DEC2ASCII_H_
#include <stdint.h>

class Dec2ascii {
public:
	Dec2ascii();
	char decode(uint8_t data);
};

#endif /* SOURCES_DEC2ASCII_H_ */
