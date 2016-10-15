
/* ============== INCLUDE ============= */

#include "Global.h"
#include "SYS/KRL_Scheduler.h"
#include "SYS/KRL_Time.h"
#include "SYS/DEBUG_MONITOR/DEBUG_MONITOR.h"

/* ============== TYPEDEF ============= */

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

sTask ArrayOfTasks[SCHED_NUMBER_TASKS];		// Will contains the list of Tasks to be run via the Scheduler

/* ============ SUBROUTINES =========== */

void KRL_SchedulerRun()
{
	Taskcallback 	TaskToBeRun;
	tTime			TimeNow;
	uint8_t			IndexOfTaskToRun;

	KrlGetTime(&TimeNow);
	
	for(;;)
		{
			IndexOfTaskToRun = KRL_SchedulerGetPrioTask();
			if(IndexOfTaskToRun != INDEX_TASK_DEFAULT)
			{
				// Launch the Task
				TaskToBeRun = ArrayOfTasks[IndexOfTaskToRun].Callback;
				TaskToBeRun();
				
				// Update the Timer for the next Call to the Task.
				KrlGetTime(&TimeNow);
				ArrayOfTasks[IndexOfTaskToRun].RunNextAt = TimeNow + ArrayOfTasks[IndexOfTaskToRun].TimeBetweenRuns;

#ifdef DEBUG_MONITORING
				DebugMonitor(IndexOfTaskToRun, &TimeNow);
#endif
			}
		}
}

/* Return the Index (within the Scheduler List) of the Task to be run */
// Think about using aging, so Task of low priority will increase their priority with time.
inline uint8_t KRL_SchedulerGetPrioTask()
{																				// Inline might be used to reduce overhead and Latency within the Scheduler.

	uint8_t i = 0;
	uint8_t HighestPriority = 0;												// Value of the highest task priority till now.
	uint8_t IndexTask = INDEX_TASK_DEFAULT;										// Index of the last Highest priority task. (0xFF is the default value, meaning that no Task has to be run)
	tTime TimeNow;
	
	KrlGetTime(&TimeNow);

	// First of all check for priority in the list
	for(i=0 ; i<SCHED_NUMBER_TASKS; i++)										//!< For every Task in the Scheduler List
		{
			if(ArrayOfTasks[i].Enabled == false) 								//!< Pass the disable Task that are still in the Lists
			{
				continue;
			}
			
			if(ArrayOfTasks[i].RunNextAt >= TimeNow) 							//!< Pass the Task which are not due
			{
				continue;
			}
						
			if( (i == 0) && (HighestPriority >= TASK_LOWEST_PRIORITY) )			//!< Manage the case where only one Task is in the List
			{
				IndexTask = i;													//!< Store the Index of the last Highest priority task.
			}

			if ( (i != 0) && (ArrayOfTasks[i].Priority > HighestPriority) )
				 //&& (ArrayOfTasks.task[i].TimeBetweenRuns >= Time_Now())		//!< For periodic Tasks ** To be implemented **
			{			
				IndexTask = i;													//!< Store the Index of the last Highest priority task.
				HighestPriority = ArrayOfTasks[i].Priority;						//!< Store the actual value of the highest priority seen
			}
		}
	return(IndexTask);														//!< If IndexTask has not been written, the function will return INDEX_TASK_DEFAULT
}


/* Adds a Task to the scheduler list */

uint8_t KRL_SchedulerAddTask(tTime a_RunNextAt, tTime a_TimeBetweenRuns, Taskcallback a_Callback, uint8_t a_Priority)
{
	
	uint8_t IndexOfEmptySlot;

	IndexOfEmptySlot = KRL_SchedulerFindEmptySlot();
	if(IndexOfEmptySlot == NO_EMPTY_SLOT)
	{
		return(NO_EMPTY_SLOT);
	}

	//Init runNextat
	ArrayOfTasks[IndexOfEmptySlot].RunNextAt = a_RunNextAt;

	// Init task period
	ArrayOfTasks[IndexOfEmptySlot].TimeBetweenRuns = a_TimeBetweenRuns;

	// Init task callback
	ArrayOfTasks[IndexOfEmptySlot].Callback = a_Callback;

	// Init task priority
	ArrayOfTasks[IndexOfEmptySlot].Priority = a_Priority;

	// Enable The Tasks
	ArrayOfTasks[IndexOfEmptySlot].Enabled = true;

	// Return the index of the newly created Task
	return(IndexOfEmptySlot);
	
}

void KRL_SchedulerDeleteTask(uint8_t a_index_slot)
{
	ArrayOfTasks[a_index_slot].Callback == NULL;
}

// Return the index of the first Empty slot in the Task array.
// Return 0xFF if no slot found.
uint8_t KRL_SchedulerFindEmptySlot(void)						
{
	uint8_t index;

	for (index=0; index < SCHED_NUMBER_TASKS; index++)		// Want to use sizeof(ArrayOfTasks) ???
	{
		if(ArrayOfTasks[index].Callback == NULL)
		{
			return(index);
		}
	}
	return(NO_EMPTY_SLOT);
}

