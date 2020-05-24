/*
 * PrintService.cpp
 *
 *  Created on: 10/12/2019
 *      Author: Jean
 */

#include <PrintService.h>

PrintService::PrintService() {
	// TODO Auto-generated constructor stub

}

void PrintService::print(	mkl_LCD lcd,
							Contador *ContadorSeg,
							Contador *ContadorSegD,
							Contador *ContadorMin,
							Contador *ContadorMinD,
							cook_t Tipo,
							door_t Porta,
							giro_t Giro,
							Dec2ascii Decoder){
	lcd.setCursor(1,3);
	lcd.putChar(':');
	lcd.setCursor(1,5);
	lcd.putChar(Decoder.decode(ContadorSeg->readQ()));
	lcd.setCursor(1,4);
	lcd.putChar(Decoder.decode(ContadorSegD->readQ()));
	lcd.setCursor(1,2);
	lcd.putChar(Decoder.decode(ContadorMin->readQ()));
	lcd.setCursor(1,1);
	if(ContadorMinD->readQ()==0)
		lcd.putChar(' ');
	else
		lcd.putChar(Decoder.decode(ContadorMinD->readQ()));

	lcd.setCursor(1,8);
	switch(Tipo){

	case edicao:lcd.putString("EDICAO");
				break;
	case inc3:	lcd.putString("INC+3  ");
				break;
	case inc5:	lcd.putString("INC+5  ");
				break;
	case inc7:	lcd.putString("INC+7  ");
				break;
	case pipoca: lcd.putString("PIP   ");
				break;
	case lasanha: lcd.putString("LAS   ");
					break;
	case pizza: lcd.putString("PIZ   ");

	}

	lcd.setCursor(2,6);

	switch(Porta){
		case open: lcd.putString("P-OP ");
					break;
		case closed: lcd.putString("P-CL");
					break;
		}

	lcd.setCursor(2,12);

	switch(Giro){
	case g_on: lcd.putString("G-ON ");
				break;
	case g_off: lcd.putString("G-OFF");
				break;
	}



	}

