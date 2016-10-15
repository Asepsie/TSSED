
/* ============== INCLUDE ============= */

#include "Global.h"

/* ============== TYPEDEF ============= */

typedef void (*Taskcallback)(void);								// type of the callback function // This is the Task, thus should return nothing for now

// To be used only for round robin preemptive Scheduler.
#define SCHEDULER_TIMING		10 								// Minimal timing between Tasks.
// Scheduler generic
#define SCHED_NUMBER_TASKS		10								// Number of Task in the Scheduler list.

// Priority
#define TASK_LOWEST_PRIORITY	0
#define HIGHEST_PRIORITY		10
#define INDEX_TASK_DEFAULT		255
#define NO_EMPTY_SLOT			255

/* ============ PROTOTYPES ============ */

void	KRL_SchedulerRun();											// Main and only interface to runs the scheduler.
void	KRL_SchedulerDeleteTask(uint8_t);							// Delete a Task from the scheduler list
uint8_t	KRL_SchedulerAddTask(tTime, tTime, Taskcallback, uint8_t);	// Adds a Task to the scheduler list.
uint8_t	KRL_SchedulerFindEmptySlot();								// Return the index of the first empty slot.
uint8_t	KRL_SchedulerGetPrioTask();									// Return the index (within the Scheduler List) of the Task to be run.

/* =============== ENUM =============== */

/* ============ STRUCTURES= =========== */

/* Task structure */
typedef	struct sTask	{
	tTime 			RunNextAt;									// Next timer at which to run the task.
	tTime 			TimeBetweenRuns;							// For periodic tasks.
	Taskcallback	Callback;									// Self-explanatory (Function pointer for the Task).
	uint8_t			Priority;									// Priority of the Task.
	bool			Enabled;									// Current status.
}sTask;

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */




