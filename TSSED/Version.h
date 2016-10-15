/* 	TOSSED OS v 0.0.1 - Copyright (C) 2015-2016  Benoit TANI
	Tiny Scheduler for Small Embedded Devices.

*/

/*
On-dev comments:
31/12/2015
The goal here is to create a simple OS/scheduler from scratch and try to mark the step and errors for personal improvement.
The project might be useful to learn the basics of Embedded Software Architecture.

	Thinking about a simple scheduler for Small Embedded System:
		- Easy to use
		- Easy to comprehend
		- Simple and lightweight
		- Non-preemptive // No need to complex mutex/semaphore lock mechanism / Context switching at first//
		- Easy timing debug capabilities.
		- Aging method for priority and avoiding starvation.
		- Scheduler/Semi-OS will be organized to use a simple Layer encapsulation:
			* HAL: "Hardware Abstraction Layer" ** Self-explanatory **
			* SYS: "System" Will be the facade pattern between OS/API layers and the HAL. It will also contains the KRL.
			* API: "Application" Will contains the Tasks.
			* DRV: "Driver" Will contains the Driver that belongs between the HAL and the Facade pattern
			 (ie. The Init/Open/Close peripheral functions)
			* KRL:  "Kernel" "Operating System" Contains the Scheduler core + Global Debug and Monitoring System.
		- And of course to much comments.

01/01/2016
	Version 0.0.1
	Writing in progress
	Start with Scheduler architecture.
		Definition of the structure of a Task
		Structure and define for timer functions.
		Debug Assert definition 

02/01/2016
	Version 0.0.1
	Writing in progress
	Create the structure for the Scheduler list
	Start the Scheduler subroutine
	
03/01/2016
	Version 0.0.1
	Finishing the first glimpse of Scheduler subroutine
	Start Thinking and create Layer architecture.
	Start the HAL & SYS for timer Tick.
		(First HAL IRQ will be implemented for Atmega32 / ATxmega64D3.
		  SYS layer will be the facade pattern interface)
	Local Git repo creation and first commit.

05/01/2016
	Few modification in time functions
	-- no time to do much --
	
09/01/2016
	Start working with Atmel 7 in order to start the HAL clock system
	Will start with Atxmega64D3
	Start writing a few basics monitor debug function.
	
10/01/2016
	Scheduler modifications.
	
17/01/2015
	Starting creating Task architecture.
	
18/01/2015
	Task_Template creation.
	Start thinking about test function and dynamic dependence injection.
	Start thinking about round-robin implementation via the ISR Tick
	Increment Patch version !!!
	I wanna try to innovate a little:
	A non preemptive OS that will execute the Task based on priority and deadline !
	
13/10/2016
	Still Version 0.0.2
	Put Project on Github
	Waiting for more time to work on this.

*/


//===== GESTION DES VERSIONS ============================================================
	
#define MAJOR_VERSION           (0)
#define MINOR_VERSION           (0)
#define PATCH_VERSION           (2)