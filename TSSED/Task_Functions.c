// Disable a Task
//---------------
void DisableTask(struct Task *t){
	t->Enabled = false;		// Disable Flag
}
// Disable a Task
//---------------
void EnableTask(struct Task *t){
DebugAssert(( (t == NULL) || (CallBackFunction == NULL) ))
	t->Enabled = true;		// Enable Flag
}
// Create a Task
//--------------
void CreateTask(struct Task *t, *CallBackFunction){
	DebugAssert(( (t == NULL) || (CallBackFunction == NULL) ))
	t->TaskCallBack = &CallBackFunction;
}


/*-----------
// Two ways of doing:
// - Use directly the Scheduler array
// - Create a variable for each Task and put the pointer on it in the Scheluder array
-----------*/

 void createTask(a_RunNextAt, a_TimeBetweenRuns, a_Callback, a_Priority, a_Enabled )
 {

 	static TaskCounter = 0;				
 	// this is a static in order to extend the lifetime of the variable.
 	// TaskCounter will be init once.


	//Init runNextat
	ListOfTasks.task[TaskCounter].RunNextAt = a_RunNextat;

	// Init task period
	ListOfTasks.task[TaskCounter].TimeBetweenRuns = a_TimeBetweenRuns;

	// Init task callback
	ListOfTasks.task[TaskCounter].Callback = a_Callback;

	// Init task priority
	ListOfTasks.task[TaskCounter].Priority = a_Priority;

 	// Enable The Tasks
	ListOfTasks.task[TaskCounter].Enabled = true;

	//Increment Taskcounter
	//Taskcounter++;		// Might want to have a TaskCounter in order not to check all the empty slot in the Scheduler list
 
 	// Return the # of the Task in the list
 	//return(TaskCounter-1);
 }

void DisableTask(a_TaskIndex)
 {
 	// Enable The Tasks
	ListOfTasks.task[TaskIndex].Enabled = FALSE;
 }

void EnableTask(a_TaskIndex)
{
	// Enable The Tasks
ListOfTasks.task[TaskIndex].Enabled = TRUE;
}
