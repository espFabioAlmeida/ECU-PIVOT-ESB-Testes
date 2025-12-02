///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityEeprom
//AUTOR:      Fábio Almeida
//CRIADO:     03/01/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES
==============================================================================*/
#define	EEPROM_ADDR_0	0x50
#define EEPROM_ADDR_1   0x51
#define EEPROM_ADDR_2   0x52
#define EEPROM_ADDR_3   0x53
#define EEPROM_ADDR_4   0x54
#define EEPROM_ADDR_5   0x55
#define EEPROM_ADDR_6   0x56
#define EEPROM_ADDR_7   0x57

#define	EEPROM_INICIALIZADA		0x0A
#define TAMANHO_EEPROM 0x7D00 //24lc256 -> 256000/8 = 32kbytes
/*==============================================================================
WRITE EXTERNAL EEPROM
==============================================================================*/
void writeExternalEeprom(uint8_t device, uint16_t address, uint8_t data) {
	uint8_t pData[3];
	uint8_t deviceHex = 0x00;
	pData[0] = make8(address, 1);
	pData[1] = make8(address, 0);
	pData[2] = data;

	switch(device) {
		case 0:	deviceHex = EEPROM_ADDR_0; break;
		case 1:	deviceHex = EEPROM_ADDR_1; break;
		case 2:	deviceHex = EEPROM_ADDR_2; break;
		case 3:	deviceHex = EEPROM_ADDR_3; break;
		case 4:	deviceHex = EEPROM_ADDR_4; break;
		case 5:	deviceHex = EEPROM_ADDR_5; break;
		case 6:	deviceHex = EEPROM_ADDR_6; break;
		case 7:	deviceHex = EEPROM_ADDR_7; break;
		default: return;
	}

	deviceHex <<= 1;

	HAL_I2C_Master_Transmit(&hi2c1, deviceHex, &pData, 3, 100);
	HAL_Delay(10);
}
/*==============================================================================
READ EXTERNAL EEPROM
==============================================================================*/
uint8_t readExternalEeprom(uint8_t device, uint16_t address) {
	uint8_t data = 0;
	uint8_t pData[2];
	uint8_t deviceHex = 0x00;
	pData[0] = make8(address, 1);
	pData[1] = make8(address, 0);

	switch(device) {
		case 0:	deviceHex = EEPROM_ADDR_0; break;
		case 1:	deviceHex = EEPROM_ADDR_1; break;
		case 2:	deviceHex = EEPROM_ADDR_2; break;
		case 3:	deviceHex = EEPROM_ADDR_3; break;
		case 4:	deviceHex = EEPROM_ADDR_4; break;
		case 5:	deviceHex = EEPROM_ADDR_5; break;
		case 6:	deviceHex = EEPROM_ADDR_6; break;
		case 7:	deviceHex = EEPROM_ADDR_7; break;
		default: return 0x00;
	}
	deviceHex <<= 1;

	HAL_I2C_Master_Transmit(&hi2c1, deviceHex, &pData, 2, 100);
	HAL_Delay(10);
	deviceHex ++;
	HAL_I2C_Master_Receive(&hi2c1, deviceHex, &data, 1, 100);
	HAL_Delay(10);

	return data;
}
/*==============================================================================
VERIFICA EEPROM
==============================================================================*/
void verificaEeprom() {
	uint8_t flagMemoria1 = false, flagMemoria2 = false;

	telaTestandoMemoria();

	if(HAL_I2C_IsDeviceReady(&hi2c1, EEPROM_ADDR_0 + 1, 10, 100)) {
		writeExternalEeprom(0, 0, 0x0A);
		HAL_Delay(1000);
		if(readExternalEeprom(0, 0) == 0x0A) {
			flagMemoria1 = true;
		}
	}

	if(HAL_I2C_IsDeviceReady(&hi2c1, EEPROM_ADDR_1 + 1, 10, 100)) {
		writeExternalEeprom(1, 0, 0x0B);
		HAL_Delay(1000);
		if(readExternalEeprom(1, 0) == 0x0B) {
			flagMemoria2 = true;
		}
	}

	telaResultadoTesteMemoria(flagMemoria1, flagMemoria2);
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
