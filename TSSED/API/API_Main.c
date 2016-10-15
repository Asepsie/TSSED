/*
 * API_Main.c
 *
 * Created: 10/01/2016 16:18:12
 *  Author: benoit TANI
 */ 

/* ============== INCLUDE ============= */

#include "API/Task_Idle.h"
#include "API/Task_Template.h"
#include "SYS/KRL_Scheduler.h"

/* ============== TYPEDEF ============= */

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */



void API_Init(void)
{
	KRL_SchedulerAddTask(1, 100, &Task_Idle, 3);						// Add a task within the scheduler
	KRL_SchedulerAddTask(1, 200, &Task_Template, 2);						// Add an other task within the scheduler
	KRL_SchedulerAddTask(1, 150, &Task_Idle, 3);						// Add a task within the scheduler
	KRL_SchedulerAddTask(1, 50, &Task_Template, 2);							// Add an other task within the scheduler
}