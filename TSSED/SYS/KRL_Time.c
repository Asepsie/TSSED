/* ============== INCLUDE ============= */

#include "Global.h"
#include "HAL/HAL_Irq.h"
#include "HAL/HAL_Time.h"
#include "SYS/KRL_Time.h"

/* ============== TYPEDEF ============= */

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */


tTime KrlGetTime (tTime* time)
{
	HalGetTime(time);
	return(*time);
}

// Definition of the time_passed function
// This function will return the time passed from a point of origin in time
// Roll-over management is included

tTime KrlTimePassed(tTime origin)
{
	tTime now;
	HalGetTime(&now);
	 
	if(now >= origin)
	{
		return(now-origin);
	}
	// In case of a roll-over
	return(now + (1UL + (UINT32_MAX - origin)));
}