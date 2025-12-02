/*
 * global.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define VERSAO_FIRMWARE 1
#define SUBVERSAO_FIRMWARE 0

enum BOOL {
	false,
	true
};

enum BOTAO {
	SEM_BOTAO,
	BOTAO_LEFT,
	BOTAO_RIGHT,
	BOTAO_UP,
	BOTAO_DOWN,
	BOTAO_OK
};

enum SIMBOLOS_DISPLAYS {
    LCD_DOT_TODO_ACESO,
    LCD_SETA_DIREITA,
    LCD_SETA_ESQUERDA,
    LCD_GRAUS,
    LCD_MICRO,
    LCD_RAIZ_QUADRADA,
    LCD_OHM,
    LCD_SIMBOLO_PI,
    LCD_DIVISAO
};

extern I2C_HandleTypeDef hi2c1;
extern RTC_HandleTypeDef hrtc;

extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;

extern ADC_HandleTypeDef hadc1;

extern uint8_t
	flagAtualizaLCD,
	flagBuzzer,
	flagLeituraAdc;

extern uint8_t
	botaoPressionado,
	releAcionado;

extern uint16_t
	valorCorrente;

extern uint8_t
	flagWhileIn[6];

extern uint16_t
	leituraAdc[2];
#endif /* INC_GLOBAL_H_ */
