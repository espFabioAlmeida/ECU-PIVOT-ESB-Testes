///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    Subrotinas LCD
//AUTOR:      Fábio Almeida
//CIRADO:     05/02/2021
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
#define TEMPO_TELA_INICIAL 2000
/*=============================================================================
TELA INICIAL
==============================================================================*/
void telaInicial() {
	on(LCD_BKL_GPIO_Port, LCD_BKL_Pin);
	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("AUTOMASENSOR");
	lcdPosLc(2, 1);
	lcdEscreve("FeA");
	HAL_Delay(TEMPO_TELA_INICIAL);
	flagBuzzer = true;

	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("Pivot ESB Testes");
	lcdPosLc(2, 1);
	lcdEscreve("V");
	escreveDado(VERSAO_FIRMWARE, 0, 0, 2);
	lcdEscreve(".");
	escreveDado(SUBVERSAO_FIRMWARE, 0, 0, 1);
	lcdEscreve(" DEZ/26");
	HAL_Delay(TEMPO_TELA_INICIAL);
	flagBuzzer = true;
	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("Iniciando");
	lcdPosLc(2, 1);
	lcdEscreve("Sistema");
}
/*=============================================================================
TELA OPERACAO
==============================================================================*/
void telaOperacao() {
	lcdPosLc(1, 1);
	lcdEscreve("IN: ");
	for(uint8_t i = 0; i < 6; i ++) {
		if(flagWhileIn[i]) {
			escreveDado(i + 1, 0, 0, 1);
		}
		else {
			lcdEscreve(" ");
		}
	}
	lcdEscreve(" SW:");

	switch(botaoPressionado) {
		case SEM_BOTAO: lcdEscreve("  "); break;
		case BOTAO_LEFT: lcdEscreve("LF"); break;
		case BOTAO_RIGHT: lcdEscreve("RG"); break;
		case BOTAO_UP: lcdEscreve("UP"); break;
		case BOTAO_DOWN: lcdEscreve("DW"); break;
		case BOTAO_OK: lcdEscreve("OK"); break;
	}

	escreveDado(sTime.Hours, 2, 1, 2);
	lcdEscreve(":");
	escreveDado(sTime.Minutes, 0, 0, 2);
	lcdEscreve("     ");

	escreveDado(valorCorrente / 10, 0, 0, 2);
	lcdEscreve(".");
	escreveDado(valorCorrente % 10, 0, 0, 1);
	lcdEscreve("mA");
}
/*=============================================================================
TELA TESTANDO MEMORIA
==============================================================================*/
void telaTestandoMemoria() {
	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("Testando");
	lcdPosLc(2, 1);
	lcdEscreve("EEPROM ...");
}
/*=============================================================================
TELA RESULTADO TESTE MEMORIA
==============================================================================*/
void telaResultadoTesteMemoria(uint8_t memoria1, uint8_t memoria2) {
	limpaLcd();
	lcdPosLc(1, 1);
	if(memoria1) {
		lcdEscreve("Memoria 1: OK");
	}
	else {
		lcdEscreve("Memoria 1: Erro");
	}
	lcdPosLc(2, 1);
	if(memoria2) {
		lcdEscreve("Memoria 2: OK");
	}
	else {
		lcdEscreve("Memoria 2: Erro");
	}

	flagBuzzer = true;
	HAL_Delay(2000);
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
