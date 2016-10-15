/*
 * HAL_Gpio.c
 *
 * Created: 16/01/2016 22:33:01
 *  Author: benoit TANI
 */ 

/* ============== INCLUDE ============= */

#include "Global.h"
#include "Type.h"
#include "HAL/HAL_Gpio.h"

/* ============== TYPEDEF ============= */

/* =============== ENUM =============== */

/* ============ PROTOTYPES ============ */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */

/*! \brief For Gpio configuration.
 *
 *  Different configuration for Gpio are listed 
 *  on the enum eHAL_GpioMode. (Cf. HAL_Gpio.h)
 */
void HalGpioPinsConfigMode( PORT_t* port, uint8_t pin_mask, eHAL_GpioMode mode)
{
	volatile uint8_t* reg = &port->PIN0CTRL;
	while( pin_mask!=0)
	{
		if ( pin_mask&1)
		{
			*reg |= mode;
		}
		reg++;
		pin_mask >>= 1;
	}
}
