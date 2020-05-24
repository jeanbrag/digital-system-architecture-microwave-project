#include "Buzzer.h"
#include "Button.h"
#include "Led.h"
#include "MotorDc.h"
#include "Delay.h"
#include "RotatingService.h"
#include "SignalingService.h"
#include "OperationService.h"
#include "ControlServiceM.h"
#include "mkl_LCD.h"
#include "MKL25Z4.h"
#include "ControlService.h"
#include "mkl_GPIOPort.h"
#include "mkl_HC06BluetoothSlave.h"
#include "Types.h"




/*!
 *   Endereço do módulo I2C utilizado
 */
uint8_t deviceAddress = 0x27;

/*!
 *   Configura o formato do display e os parametros do modulo I2C
 */
mkl_LCD lcd(mode4Lines, mode20Cols, mode5x8Dots, i2c_PTE1, i2c_PTE0,
  deviceAddress);

/*!
 *   @brief      Pausa o programa
 *
 *   Interrompe o programa para o periodo de tempo (em milissegundos) especificado
 *   como parametro.
 *
 *   @param[in]  milliSeconds - o número de milissegundos para fazer uma pausa
 */
void delay(uint32_t milliSeconds) {
uint32_t i;
uint32_t j;

for (i = 0; i < milliSeconds; i++) {
for (j = 0; j < 1500; j++) {}
}
}

int i = 0x0;

/*!
 *   @brief      Imprime texto no display LCD.
 *
 *   Este programa realiza o teste da classe do periferico LCD. A palavra
 *   "Arquitetura" é impressa em uma linha.
 */


//BLUETOOTH
mkl_HC06BluetoothSlave bt(uart0_PTA2, uart0_PTA1);  //! Bluetooth na UART 0
uint8_t bf = '0';                                        //! Armazenar dado recebido
uart_Exception_t exc;                               //! Armazenar exceção

void setupBluetooth() { //Realiza a configuração do periférico Bluetooth.
	bt.setInterruptMode(uart_Rx);
	bt.setPriority(uart_Priority0);
	bt.enableInterrupt();
}






//FIM BLUETOOTH



//CLASSES DE DISPOSITIVOS
Led led(gpio_PTB19);
Temporizador temporizador(500);
Botao *playB;
Botao *incB;
Botao *pizzaB;
Key *keyDoor;
Botao *btnCancel;
Botao *btnFimOP;

//CLASSES DE DIGITAIS
Contador *ContadorSeg;
Contador *ContadorSegD;
Contador *ContadorMin;
Contador *ContadorMinD;
Dec2ascii Decoder;


//CLASSES DE SERVI�OS DE COMUNICA��O

IncrementService serviceInc;
DecrementaService serviceDec;
SetService serviceSet;
PrintService servicePrint;
RotatingService *servicoGiro;
SignalingService *servicoSinal;
OperationService *servOP;

//CLASSE DO CONTROLADOR
ControlService serviceControl;


extern "C" {
void UART0_IRQHandler() {
	serviceControl.setBuf(bt.receive8Bits());
}
}

extern "C"{
	void SysTick_Handler(){
		//teste(tipo,porta,giro);
		serviceControl.doService(	decrementService,
									lcd,
									incB,
									playB,
									pizzaB,
									ContadorSeg,
									ContadorSegD,
									ContadorMin,
									ContadorMinD,
									serviceInc,
									serviceDec,
									serviceSet,
									servicePrint,
									serviceControl.readCook(),
									closed,
									serviceControl.readGiro(),
									Decoder);

	}
}


int main(){
  
	//TEMPORARIOS
		//Entrada


			btnFimOP = new Botao(gpio_PTC1); // botao de sinaliza��o de fim de opera��o

		//SAIDA
 			Led *ledTemp;
 			ledTemp = new Led(gpio_PTC2); // LED QUE INDICA TEMPORIZA��O ATIVA


	//PERMANTENTE
		//Delay
 			Delay *tmp;
 			tmp = new Delay(tpm_TPM0);

		//Entrada
 			//Button *btnPlayPause;
 			//btnPlayPause = new Button(gpio_PTA4);


 			btnCancel = new Botao(gpio_PTC0);


 			keyDoor = new Key(gpio_PTC3);

		//Sa�da
			Led *lampada;
			lampada = new Led(gpio_PTB1);

			Buzzer *buzina;
			buzina = new Buzzer(gpio_PTB0);

			MotorDc *motorA;
			motorA = new MotorDc(gpio_PTD5,gpio_PTD0,tpm_PTA13);


		//Classes de Servi�o

			servicoGiro = new RotatingService(motorA);


			servicoSinal = new SignalingService(ledTemp,lampada,buzina,tmp);


			servOP = new OperationService(servicoGiro, servicoSinal, tmp);

		//CLASSE DE CONTROLE
			ControlServiceM servControl(servOP, btnFimOP, playB, btnCancel, keyDoor, servicoSinal);

			//BLUETOOTH

					__disable_irq();
					setupBluetooth();  //! Configura o periférico bluetooth
					__enable_irq();

					//FIM BLUETOOTH

					ContadorSeg = new Contador;
					ContadorSegD = new Contador;
					ContadorMin = new Contador;
					ContadorMinD = new Contador;

					ContadorSeg->setTipo(Segundo);
					ContadorSegD->setTipo(SegundoDec);
					ContadorMin->setTipo(Minuto);
					ContadorMinD->setTipo(MinutoDec);

					playB = new Botao(gpio_PTA4);
					incB = new Botao(gpio_PTA5);
					pizzaB = new Botao(gpio_PTC8);

					led.turnOff();

					serviceControl.doService(	setService,
												lcd,
												incB,
												playB,
												pizzaB,
												ContadorSeg,
												ContadorSegD,
												ContadorMin,
												ContadorMinD,
												serviceInc,
												serviceDec,
												serviceSet,
												servicePrint,
												serviceControl.readCook(),
												servControl.readDoor(),
												serviceControl.readGiro(),
												Decoder);


	while(1){
		servControl.readInputs();
		servControl.selectService();
		servControl.doService();
		servControl.writeOutputs();
		serviceControl.readInputs(playB, incB, pizzaB);
		serviceControl.selectService(serviceControl.readBtn());
		serviceControl.doService(serviceControl.readSid(),
										lcd,
										incB,
										playB,
										pizzaB,
										ContadorSeg,
										ContadorSegD,
										ContadorMin,
										ContadorMinD,
										serviceInc,
										serviceDec,
										serviceSet,
										servicePrint,
										serviceControl.readCook(),
										servControl.readDoor(),
										serviceControl.readGiro(),
										Decoder);
		serviceControl.writeOutputs(led,ContadorSeg,
												ContadorSegD,
												ContadorMin,
												ContadorMinD);
	}
	return 0;
}
