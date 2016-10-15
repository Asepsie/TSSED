/*
 * TSSED.c
 *
 * Created: 09/01/2016 14:51:03
 * Author : benoit TANI
 */ 

/* ============== INCLUDE ============= */

#include <avr/io.h>
#include "SYS/KRL_Scheduler.h"
#include "API/API_Main.h"
#include "HAL/HAL_Main.h"
#include "TEST/TEST_MACROS.h"

/* ============ SUBROUTINES =========== */

int main(void)
{
	
	// Main Init
	HAL_Init();				// Should call the init functions for timer
//	SYS_Init();				// Init the Facade Pattern
	API_Init();				// Init the task

	// Run the scheduler after initialization
	KRL_SchedulerRun();		// Call the Scheduler
}