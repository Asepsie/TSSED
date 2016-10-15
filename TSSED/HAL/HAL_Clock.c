/*
 * HAL_Clock.c
 *
 * Created: 12/01/2016 20:15:58
 *  Author: benoit TANI
 */ 

/* ============== INCLUDE ============= */

#include "Global.h"
#include "Type.h"
#include "HAL/HAL_Clock.h"
#include "HAL/HAL_Irq.h"
#include "src/ASF/xmega/drivers/cpu/ccp.h"

/* ============== TYPEDEF ============= */

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */

void HAL_ClockInit(void) /* Critical section ? M<*/ /* Might want to check the need of getting protected from IRQ here !<*/  
{

	
	/* Enable the Internal 32 MHz Oscillator */
	OSC.CTRL = INTERNAL_32MHZ_OSC_ENABLE | PLL_ENABLE;		/* Enable the 32MHZ internal Osc and enable the PLL */

	//CLK.RTCCTRL = CLK_RTCEN_bm | 

	/* Might be usefull to think about letting the oscillator oscillate here !!<*/
	while (!(OSC.STATUS & OSC_RC32MEN_bm));									// No clean at all !!!
	
	/* Set the internal 32 MHz internal oscillator as PLL source and set the PLL to one */
	OSC.PLLCTRL = OSC_PLLSRC_RC32M_gc | PLL_PRESCALER;
		
	/* Give access to the Clock Register*/
	ccp_write_io((uint8_t *)&CCP, CCP_SignatureIO);
	
	/* Select 32MHz internal Oscillator */
	ccp_write_io((uint8_t *)&CLK.CTRL, CLK_SCLKSEL_RC32M_gc);
	
	/* No more 2MHz internal osc needed !<*/
//	OSC.CTRL &= ~(INTERNAL_2MHZ_OSC_ENABLE);				
	
 	/* We might want to prohibit further modification of the clock system*/
	// CLK.LOCK |= CLOCK_LOCK_bm;
}


/***************************************************************************************/
/*! \brief Enable clock of specified module
 *
 *  \return none
 */
/***************************************************************************************/
void Hal_ClockEnableModule( eHAL_ClockPortId port, uint8_t id)
{
	irqflags_t flags = HalIrqSave();

	*((uint8_t*)&PR.PRGEN + port) &= ~id;

	HalIrqRestore(flags);
}

/***************************************************************************************/
/*! \brief Disable clock of specified module
 *
 *  \return none
 */
/***************************************************************************************/
void Hal_ClockDisableModule( eHAL_ClockPortId port, uint8_t id)
{
	irqflags_t flags = HalIrqSave();

	*((uint8_t *)&PR.PRGEN + port) |= id;

	HalIrqRestore(flags);
}


/*	To verify: Need to be done directly within the function.
	Or the call from the stack will use to much cycles.
*/
 
void HAL_CpuLockDisableClockCtrl(void)
{
	/*	Warning this is quite critical
		IRQ are disable 4 CPU after write the CCP
	*/
	CCP = CCP_SignatureIO;				// Give access to the Clock Register
}