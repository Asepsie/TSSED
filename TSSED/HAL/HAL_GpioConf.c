/*
 * HAL_GpioConf.c
 *
 * Created: 17/01/2016 22:08:28
 *  Author: benoit TANI
 */ 

/* ============== INCLUDE ============= */

#include "Global.h"
#include "Type.h"
#include "HAL/HAL_Gpio.h"

/* ============== TYPEDEF ============= */

/* ============== DEFINE ============== */

/* ============ PROTOTYPES ============ */

/* ============== ENUM ================ */

/* ============ VARIABLES ============= */

/* =========== SUBROUTINES ============ */
#define PIN_RE			PIN_0
#define PIN_DE			PIN_1
#define PIN_RX			PIN_2
#define PIN_TX			PIN_3
#define PIN_LED_GREEN	PIN_4
#define PIN_LED_RED		PIN_5
#define NONE_B6			PIN_6
#define NONE_B7			PIN_7

void HALGpioConfInit(void)
{
	/* Non used Pin are set as low-level output for consumption optimization */
	
	/* ------------------------- PORT B --------------------------------*/
	/*------------------------------------------------------------------*/
	/*	PIN		| Function		| IN/OUT		|	Mode	|	Initial */
	/*------------------------------------------------------------------*/
	/* PIN 0	|	RE			|	OUT			|	Normal	|	0		*/
	/* PIN 1	|	DE			|	OUT			|	Normal	|	0		*/
	/* PIN 2	|	RX			|	IN			|	Normal	|	0		*/
	/* PIN 3	|	TX			|	OUT			|	Normal	|	0		*/
	/* PIN 4	|	LED_GREEN	|	OUT			|	Normal	|	0		*/
	/* PIN 5	|	LED_RED		|	OUT			|	Normal	|	0		*/
	/* PIN 6	|	NONE		|	OUT			|	Normal	|	0		*/
	/* PIN 7	|	NONE		|	OUT			|	Normal	|	0		*/
	/*------------------------------------------------------------------*/	
	Hal_GpioSetInputs(PORT_RS485, PIN_485_RX);
	Hal_GpioSetOutputs(PORT_RS485, PIN_485_TX | PIN_485_RE | PIN_485_DE);
	Hal_GpioSetOutputs(PORT_LED, PIN_LED_RED | PIN_LED_GREEN);
	
	Hal_GpioPinsSet(PORT_RS485, PIN_485_RE);					/*!< RS-485 Receiver Enable OFF (Active Low) */
	Hal_GpioPinsClear(PORT_RS485, PIN_485_DE);					/*!< RS-485 Transmitter Enable OFF (Active High)*/
	Hal_GpioPinsClear(PORT_LED, PIN_LED_RED | PIN_LED_GREEN);	/*!< LED Off at start-up */
	
}
