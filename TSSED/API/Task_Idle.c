/*
 * Task_Idle.c
 *
 * Created: 10/01/2016 16:15:51
 *  Author: benoit TANI
 */ 

/* ============== INCLUDE ============= */

#include "Type.h"
#include "Global.h"
#include "SYS/KRL_Time.h"
#include "API/Task_Idle.h"

/* ============== TYPEDEF ============= */

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */


/*! \brief Idle Task (p0).
 *  Set the wake up for low consumption.
 *
 *  The Idle Task is run when no other Task need to run.
 *  DO NOT CREATE OTHER 0 PRIORITY TASKS 
 *  
 
 */

void Task_Idle(void)
{
	uint32_t TimeNow;

	/*!< Get the actual system tick timer value */
	KrlGetTime(&TimeNow);
	
	/*!< Shut down all peripheral for consumption */
	
	/*!< Set the Wake up using IRQ/Timer */
}