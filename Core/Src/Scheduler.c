///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    Scheduler
//AUTOR:      Fábio Almeida
//CRIADO:     04/08/2023
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
# include "main.h"
# include "global.h"
/*==============================================================================
TAREFAS 100us
==============================================================================*/
void tarefas100us() {

}
/*==============================================================================
TAREFAS 1ms
==============================================================================*/
void tarefas1ms() {

}
/*==============================================================================
TAREFAS 10ms
==============================================================================*/
void tarefas10ms() {

}
/*==============================================================================
TAREFAS 100ms
==============================================================================*/
void tarefas100ms() {
	static uint8_t contadorLedCPU = 0;
	reiniciaWatchDog();

	toggle(LED_CPU_GPIO_Port, LED_CPU_Pin);
	toggle(LED_COM_GPIO_Port, LED_COM_Pin);

	flagAtualizaLCD = true;

	if(flagBuzzer) {
		flagBuzzer = false;
		on(BUZZER_GPIO_Port, BUZZER_Pin);
	}
	else {
		off(BUZZER_GPIO_Port, BUZZER_Pin);
	}

	flagLeituraAdc = true;
}
/*==============================================================================
TAREFAS 1s
==============================================================================*/
void tarefas1s() {
	releAcionado ++;
	if(releAcionado > 10) {
		releAcionado = 0;
	}
}
/*==============================================================================
SCHEDULER
==============================================================================*/
void schedulerEngine() {
	static uint8_t conta100us = 0, conta1ms = 0, conta10ms = 0, conta100ms = 0;
	//Essa rotina deve ser chamada através de um timer configurado em 100us

	tarefas100us();
	conta100us ++;

	if(conta100us >= 10) {
		conta100us = 0;
		tarefas1ms();
		conta1ms ++;

		if(conta1ms >= 10) {
			conta1ms = 0;
			tarefas10ms();
			conta10ms ++;

			if(conta10ms >= 10) {
				conta10ms = 0;
				tarefas100ms();
				conta100ms ++;

				if(conta100ms >= 10) {
					conta100ms = 0;
					tarefas1s();
				}
			}
		}
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
