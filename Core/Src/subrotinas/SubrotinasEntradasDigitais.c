///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasEntradasDigitais
//AUTOR:      Fábio Almeida
//CIRADO:     25/04/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*=============================================================================
LEITURA DAS ENTRADAS DIGITAIS
==============================================================================*/
void entradasDigitais() {
	if(flagWhileIn[0]) {
		if(debounceInverso(IN1_GPIO_Port, IN1_Pin)) {
			flagWhileIn[0] = false;
		}
	}
	else {
		if(debounce(IN1_GPIO_Port, IN1_Pin)) {
			flagWhileIn[0] = true;
		}
	}

	if(flagWhileIn[1]) {
		if(debounceInverso(IN2_GPIO_Port, IN2_Pin)) {
			flagWhileIn[1] = false;
		}
	}
	else {
		if(debounce(IN2_GPIO_Port, IN2_Pin)) {
			flagWhileIn[1] = true;
		}
	}

	if(flagWhileIn[2]) {
		if(debounceInverso(IN3_GPIO_Port, IN3_Pin)) {
			flagWhileIn[2] = false;
		}
	}
	else {
		if(debounce(IN3_GPIO_Port, IN3_Pin)) {
			flagWhileIn[2] = true;
		}
	}

	if(flagWhileIn[3]) {
		if(debounceInverso(IN4_GPIO_Port, IN4_Pin)) {
			flagWhileIn[3] = false;
		}
	}
	else {
		if(debounce(IN4_GPIO_Port, IN4_Pin)) {
			flagWhileIn[3] = true;
		}
	}

	if(flagWhileIn[4]) {
		if(debounceInverso(IN5_GPIO_Port, IN5_Pin)) {
			flagWhileIn[4] = false;
		}
	}
	else {
		if(debounce(IN5_GPIO_Port, IN5_Pin)) {
			flagWhileIn[4] = true;
		}
	}

	if(flagWhileIn[5]) {
		if(debounceInverso(IN6_GPIO_Port, IN6_Pin)) {
			flagWhileIn[5] = false;
		}
	}
	else {
		if(debounce(IN6_GPIO_Port, IN6_Pin)) {
			flagWhileIn[5] = true;
		}
	}
}
/*=============================================================================
FIM DO ARQUIVO
==============================================================================*/
