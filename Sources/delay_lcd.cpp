/*
 * delay.cpp
 *
 *  Created on: 09/10/2019
 *      Author: Jean
 */

#include "delay_lcd.h"

void Delay1(volatile uint32_t nof) {
  while(nof!=0) {
    __asm("NOP");
    nof--;
  }
}
