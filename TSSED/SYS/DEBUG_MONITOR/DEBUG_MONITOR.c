/*
 * DEBUG_MONITORING.c
 *
 * Created: 10/01/2016 19:43:31
 *  Author: benoit TANI
 */ 

#ifdef DEBUG_MONITORING





/* ============== INCLUDE ============= */

#include "Type.h"
#include "Global.h"
#include "HAL/HAL_Irq.h"
#include "SYS/DEBUG_MONITOR/DEBUG_MONITOR.h"

/* ============== TYPEDEF ============= */

#define NUMBER_OF_TASKS_TO_LOG	100							// Will depends on memory that we can spare for debugging the scheduler.

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */

void DebugMonitor(uint8_t index, tTime* time)
{
	static sDebugMonitor DebugLog[NUMBER_OF_TASKS_TO_LOG];
	static uint8_t DebugCounter = 1;
	
	DebugLog[DebugCounter].IndexOfTasksTerminated = index;
	DebugLog[DebugCounter].CompletionTime = *time;
	
	DebugCounter++;											// Counter to stop the Scheduler and debug when the number of Task to be Log is obtained.
	if (DebugCounter >= NUMBER_OF_TASKS_TO_LOG)
	{
		DebugAssert(true);
	}
	
}

#endif