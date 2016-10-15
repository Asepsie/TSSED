/*
 * DEBUG_MONITORING.h
 *
 * Created: 10/01/2016 19:43:56
 *  Author: benoit
 */ 

#ifdef DEBUG_MONITORING

#include "Global.h"

/* =========== Structures =========== */

/* Task structure */
typedef	struct sDebugMonitor	{
	uint8_t		IndexOfTasksTerminated;									// Task Index
	tTime		CompletionTime;
}sDebugMonitor;


/* =========== Prototypes ========== */

void DebugMonitor(uint8_t index, tTime* time);


#endif /* DEBUG_MONITORING */