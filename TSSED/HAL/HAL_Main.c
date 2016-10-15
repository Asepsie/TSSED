/*
 * HAL_Main.c
 *
 * Created: 11/01/2016 15:42:25
 *  Author: benoit TANI
 */ 

/* ============== INCLUDE ============= */

#include "Global.h"
#include "Type.h"
#include "HAL/HAL_Time.h"

/* ============== TYPEDEF ============= */

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */

void HAL_Init(void)
{
	// Place here all the HAL init function that are to be run at start-up
	HAL_TimeInit();					// HAL_ClockInit is call within this function
}