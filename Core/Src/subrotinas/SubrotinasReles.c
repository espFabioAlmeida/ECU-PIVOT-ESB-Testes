///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasReles
//AUTOR:      Fábio Almeida
//CIRADO:     25/04/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
DESLIGA TODOS OS RELES
==============================================================================*/
void desligaTodosReles() {
	off(RELE1_GPIO_Port, RELE1_Pin);
	off(RELE2_GPIO_Port, RELE2_Pin);
	off(RELE3_GPIO_Port, RELE3_Pin);
	off(RELE4_GPIO_Port, RELE4_Pin);
	off(RELE5_GPIO_Port, RELE5_Pin);
	off(RELE6_GPIO_Port, RELE6_Pin);
	off(RELE7_GPIO_Port, RELE7_Pin);
	off(RELE8_GPIO_Port, RELE8_Pin);
	off(RELE9_GPIO_Port, RELE9_Pin);
	off(RELE10_GPIO_Port, RELE10_Pin);
}
/*=============================================================================
ACIONAMENTO DOS RELES
==============================================================================*/
void acionamentoReles() {
	static uint8_t ultimoAcionamento = 0;

	if(ultimoAcionamento == releAcionado) {
		return;
	}

	ultimoAcionamento = releAcionado;
	desligaTodosReles();

	switch(releAcionado) {
		case 1: on(RELE1_GPIO_Port, RELE1_Pin); break;
		case 2: on(RELE2_GPIO_Port, RELE2_Pin); break;
		case 3: on(RELE3_GPIO_Port, RELE3_Pin); break;
		case 4: on(RELE4_GPIO_Port, RELE4_Pin); break;
		case 5: on(RELE5_GPIO_Port, RELE5_Pin); break;
		case 6: on(RELE6_GPIO_Port, RELE6_Pin); break;
		case 7: on(RELE7_GPIO_Port, RELE7_Pin); break;
		case 8: on(RELE8_GPIO_Port, RELE8_Pin); break;
		case 9: on(RELE9_GPIO_Port, RELE9_Pin); break;
		case 10: on(RELE10_GPIO_Port, RELE10_Pin); break;
	}
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
