///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasEntradasAnalogicas
//AUTOR:      Fábio Almeida
//CIRADO:     25/04/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
/*=============================================================================
LEITURA TRANSDUTOR DE PRESSAO
==============================================================================*/
void leituraTransdutorPressao() {
	static uint16_t bufferPressao[4];
	uint32_t calculo = 0;

	for(uint8_t i = 0; i < 3; i ++) {
		bufferPressao[i] = bufferPressao[i + 1];
	}
	bufferPressao[3] = leituraAdc[1];

	for(uint8_t i = 0; i < 4; i ++) {
		calculo += bufferPressao[i];
	}
	calculo /= 4;

	calculo *= 200;
	calculo /= 4095;

	valorCorrente = calculo;
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
