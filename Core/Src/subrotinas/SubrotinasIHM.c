///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasIHM.c
//AUTOR:      Fábio Almeida
//CIRADO:     01/12/2025
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
LEITURA DAS ENTRADAS DIGITAIS
==============================================================================*/
void subrotinasIHM() {
	uint8_t algumBotaopressionado = false;

	if(botaoUp()) {
		botaoPressionado = BOTAO_UP;
		algumBotaopressionado = true;
	}

	if(botaoDown()) {
		botaoPressionado = BOTAO_DOWN;
		algumBotaopressionado = true;
	}

	if(botaoLeft()) {
		botaoPressionado = BOTAO_LEFT;
		algumBotaopressionado = true;
	}

	if(botaoRight()) {
		botaoPressionado = BOTAO_RIGHT;
		algumBotaopressionado = true;
	}

	if(botaoOk()) {
		botaoPressionado = BOTAO_OK;
		algumBotaopressionado = true;
	}

	if(!algumBotaopressionado) {
		botaoPressionado = SEM_BOTAO;
	}
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
