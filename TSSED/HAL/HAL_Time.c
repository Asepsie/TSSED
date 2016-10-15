// HAL_Time.c
// 05/01/2016
// Author: Benoit TANI
// Comments:
/*
Will contain the HAL time functions.
*/
/*=============INCLUDE==================*/

#include "Global.h"
#include "Type.h"
#include "HAL_Irq.h"
#include "HAL_Time.h"
#include "HAL_Clock.h"

/* ============== TYPEDEF ============= */

#define TC_WGMODE_NORMAL	(0x00<<0)
#define SYSCLK_HIRES		PR_HIRES_bm		// Hi-Res Extension
#define SYSCLK_TC0			PR_TC0_bm		// Timer/Counter 0
#define	CPU_FREQUENCY		10e6			// Hz

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

enum TC_INT_LEVEL_t {
	TC_INT_LVL_OFF = 0x00,
	TC_INT_LVL_LO = 0x01,
	TC_INT_LVL_MED = 0x02,
	TC_INT_LVL_HI = 0x03,
};

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */

//! TC interrupt levels


/* This is a little tricky:
As the ISR should be in the HAL, and the GetTime function within the KRL
However, it's simpler to just put it here for now.
Just in case you don't remember why the variable's name is KrlBaseTime !!!/
*/

/*=============VARIABLES==================*/

static volatile tTime KrlBaseTime;			// System Tick variable.

void HalGetTime( tTime* time)
{
    DebugAssert( time == NULL);
	
	uint8_t flag = HalIrqSave();			// Save the state of SREG and disable IRQ
	*time = KrlBaseTime;
	HalIrqRestore(flag);					// Restore the state of SREG (Enable IRQ if needed)
}

/***************************************************************************************/
/*! \brief Setup system timer to 1ms
 *
 *	\return none
 */
/***************************************************************************************/
void HAL_TimeInit(void)
{
	KrlBaseTime = 0;													// System Tick variable initialization
	HAL_ClockInit();
	Hal_IrqInit();
	

	Hal_ClockEnableModule(SYSCLK_PORT_C, SYSCLK_TC0);					// Enable counter clock
	Hal_ClockEnableModule(SYSCLK_PORT_C, SYSCLK_HIRES);
	TCC0.CTRLB = (TCC0.CTRLB & ~TC0_WGMODE_gm)|TC_WGMODE_NORMAL;		// Incrementing up to counter then reset counter
	TCC0.PER = 300;													//period 1 ms
	TCC0.INTCTRLA = ( TCC0.INTCTRLA & ~TC0_OVFINTLVL_gm ) | (TC_INT_LVL_HI << TC0_OVFINTLVL_gp); // Use High priority interrupt
	cpu_irq_enable(); 
	TCC0.CTRLA = (TCC0.CTRLA & ~TC0_CLKSEL_gm) | TC_CLKSEL_DIV1_gc;		//Timer clock = CLKper clock
}

/*================IRQ=====================*/
// IRQ handler
// Warning, defining the system Tick depends on the platform.
ISR(TCC0_OVF_vect)		// Will depend on the Counter/Timer we wish to use.
{
	++KrlBaseTime;
}
