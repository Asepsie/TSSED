/*
 * Task_Template.c
 *
 * Created: 10/01/2016 19:35:04
 *  Author: benoit TANI
 *  This is design to guide Task creation with a simple template.
 */ 

/* ============== INCLUDE ============= */

#include "Global.h"
#include "API/Task_Template.h"
#include "HAL/HAL_Irq.h"

/* ============== TYPEDEF ============= */

typedef void (*tFunctionToRun)(void);

/* ============ PROTOTYPES ============ */

#define NUMBER_OF_SUB_TASKS

/* ============ PROTOTYPES ============ */

void Task_StatusStart(void);
void Task_StatusInProgress(void);
void Task_StatusFailure(void);
void Task_StatusIdle(void);

/* ================ ENUM ============== */

typedef enum
{
	STATUS_START=0
	, STATUS_IN_PROGRESS
	, STATUS_FAILURE
	, STATUS_IDLE
}STATUS;

/* ============== ARRAYS ============== */

void (*aArrayPointer[NUMBER_OF_SUB_TASKS])(void) = {	&Task_StatusStart,
														&Task_StatusInProgress,
														&Task_StatusIdle,
														&Task_StatusFailure
													};

/* ============= VARIABLES ============ */

static STATUS eStatus;

/* ============ SUBROUTINES =========== */

/*! \brief Task Template init.
 *         Init the function pointer array of the Task.
 *
 */
/*
void Task_TemplateInit(void)
{
	uint8_t i;
	
	for (i=0; i<sizeof(aArrayPointer); i++)
	{
		aArrayPointer[i] = NULL;
	}
	
}
*/


/*! \brief Task Template.
 *         Simple Task management system.
 *
 */
void Task_Template(void)
{

	/*!< Call the right function depending on the state */	
	(*aArrayPointer[eStatus])();
	
	// If you prefer :
	
	///* WARNING: Look out for multiple definition for NULL */
	//tFunctionToRun	pFunctionToRun = NULL;
	
	//
	///* The task will be a state machine using function pointer*/
	//
	//switch (eStatus)
	//{
		//case(STATUS_START):
			//pFunctionToRun = &Task_StatusStart;
			//break;
			//
		//case(STATUS_IN_PROGRESS):
			//pFunctionToRun = &Task_StatusInProgress;
			//break;
			//
		//case(STATUS_IDLE):
			//pFunctionToRun = &Task_StatusIdle;
			//break;
			//
		//case(STATUS_FAILURE):
			//pFunctionToRun = &Task_StatusFailure;
			//break;
		//
		//default:
			///* WTF */
			//DebugAssert(true);							
			//break;
	//}
	///* Call the function that will deal with the current state */
	//pFunctionToRun();																		

}

/*! \brief Manage step 1.
 *         Simple Task management system.
 *
 */
void Task_StatusStart(void)
{
	uint8_t i;
	
	for(i=0; i<3; i++)
	{
		/* do nothing*/
	}
	eStatus = STATUS_IN_PROGRESS;
}

/*! \brief Manage step 2.
 *         Simple Task management system.
 *
 */
void Task_StatusInProgress(void)
{
	uint8_t i;
	
	for(i=0; i<3; i++)
	{
		/* do nothing*/
	}
	eStatus = STATUS_IDLE;
}

/*! \brief Manage step 2.
 *         Simple Task management system.
 *		   Manage error.
 */
void Task_StatusFailure(void)
{
	/* WTF !!! Chuck Norris never fail !!! */
}

/*! \brief Manage step 2.
 *         Simple Task management system.
 *			Should return to the scheduler.
 */
void Task_StatusIdle(void)
{
	/* WTF !!! Chuck Norris is always busy !!! Even when he sleeps */
}