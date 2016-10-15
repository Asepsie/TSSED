/*
 * TEST_MACROS.c
 *
 * Created: 11/01/2016 13:21:56
 *  Author: benoit TANI
 */ 


/* ============== INCLUDE ============= */

#include "Global.h"
#include "Type.h"

/* ============== TYPEDEF ============= */

/* ============ PROTOTYPES ============ */

/* =============== ENUM =============== */

/* ============= VARIABLES ============ */

/* ============ SUBROUTINES =========== */

void TEST_Macros_ValueTypeMax()
{
	uint8_t ValueMaxTest = 0;
	uint8_t NumberOfIntTest = 0;
	

	NumberOfIntTest = sizeof(uint8_t);
		
	ValueMaxTest = VALUE_TYPE_MAX(uint8_t);
	
	
}