/*
 * lpmCounter.cpp
 * Jean Cleison Braga Guimaraes
 */

#include "Contador.h"


Contador::Contador(){
	q = 5;
	cin = 1;
	tipo;
}
void Contador::load(uint8_t data) {

	this->q = data;
}
bool Contador::incrementa(uint8_t t){
		if(this->tipo == Segundo){
			if(t == 7){
				if(this->q > 2){
					if(this->q == 3)
						this->q = 0;
					else if(this->q == 4)
						this->q = 1;
					else if(this->q == 5)
						this->q = 2;
					else if(this->q == 6)
						this->q = 3;
					else if(this->q == 7)
						this->q = 4;
					else if(this->q == 8)
						this->q = 5;
					else
						this->q = 6;

					return 1;
				}
				else
					this->q = this->q + t;
					return 0;
			}
			else if(t == 5){
							if(this->q > 4){
								if(this->q == 5)
									this->q = 0;
								else if(this->q == 6)
									this->q = 1;
								else if(this->q == 7)
									this->q = 2;
								else if(this->q == 8)
									this->q = 3;
								else if(this->q == 9)
									this->q = 4;
								return 1;
							}
							else
								this->q = this->q + t;
								return 0;
						}
			else if(t == 3){
							if(this->q > 6){
								if(this->q == 7)
									this->q = 0;
								else if(this->q == 8)
									this->q = 1;
								else if(this->q == 9)
									this->q = 2;
								return 1;
										}
								else
									this->q = this->q + t;
								return 0;
									}


		}

		else{
		if(this->q == 5){
			this->q = 0;
			return 1;
			}
		this->q = this->q + 1;
			return 0;
		}

}

bool Contador::decrementa(){

	if((this->tipo == Segundo) or (this->tipo == Minuto)){
		if(this->q == 0){
			this->q = 9;
			return 1;
		}
		this->q = this->q - 1;
		return 0;
	}

	else{
		if(this->q ==0){
			this->q = 5;
			return 1;
		}
		this->q = this->q - 1;
		return 0;
	}

}
uint8_t Contador::readQ(){
	return this->q;
}

void Contador::aclear(){
	this->q = 0;
}

void Contador::enable(){
	this->cin = 1;
}

void Contador::disable(){
	this->cin = 0;
}

bool Contador::readCin(){
	return this->cin;
}



void Contador::setTipo(tipo_contador tp){
	this->tipo = tp;
}

