#ifndef _GLOBAL_ 
#define _GLOBAL_

/* ============== INCLUDE ============= */

#include "Type.h"
#include "stdbool.h"										// also contains "true" and "false" definition
#include "avr/interrupt.h"

/* ============== TYPEDEF ============= */

#define BIT(num)                (1<<num)
#define HIGH_BYTE( word)        ((UVAR_8)(((word)&0xFF00)>>8))
#define LOW_BYTE( word)         ((UVAR_8)((word)&0xFF))

// Think about protect the use of those macro depending on the type of the variable !!!
#define MAX(A,B)                ((A) > (B) ? (A) : (B))
#define MIN(A,B)                ((A) < (B) ? (A) : (B))
#define ABS(A)                  ((A) >=  0  ? (A) : -(A))
#define ABS_DIFF(A,B)           ((A) > (B) ? (A-B) : (B-A))
// Those are needed for the Time_Passed function.
#define VALUE_TYPE_MAX(type)	( (1UL << (sizeof(type) << 3)) -1)		// Max value of the input type // Not working with 32 bits value !!!

#define NULL    		        ((void *)0)

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */

/* =============== DEBUG ============== */


// Do not forget to check that the DEBUG symbol is present in the project options
// for the DEBUG configuration


// DebugAssert will be active only in debug mode
#ifdef DEBUG
#define DebugAssert(cond)  while(cond) {HalIrqSave();}	// DEBUG In case of a Debug Assert being TRUE, save the context and stop the IRQ in order to facilitate debug.
#else
#define DebugAssert(cond) ((void) 0)					// ((void) 0) Do nothing
#endif


// Assert is active whatever the current configuration
#ifdef DEBUG
#define TSSED_Assert(cond)  while(!(cond))
#else
#define TSSED_Assert(cond)  if (!(cond)) { Reset();}
#endif

//#define DEBUG_MONITORING									// This is used to monitor the Task Scheduler.



#endif