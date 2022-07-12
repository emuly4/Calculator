#include "Task_Management.h"

#include "Timing.h"

/** Function Initialize_Task initializes the task to a default state that is inactive. 
 *  Note that a negative run_period indicates the task should only be performed once, while
 *  a run_period of 0 indicates the task should be run every time.
 */ 
void Initialize_Task(Task_t * task, float run_period, void (*task_fcn_ptr)(void) ) //struct added
{
    task->is_active = false;
    task->run_period = run_period;
    task->time_last_ran.microsec = 0;
    task->time_last_ran.millisec = 0;
    task->task_fcn_ptr = task_fcn_ptr;
}

/** Function Task_Activate changes the internal state to enable the task **/
void Task_Activate( Task_t* task )
{
    task->is_active = true;
}

/** Function Task_Cancel changes the internal state to disable the task **/
void Task_Cancel( Task_t* task )
{
    task->is_active = false;
}

/** Function Task_Is_Ready indicates if the task should be run. It checks both
 * the active status and the timing.
 */
bool Task_Is_Ready( Task_t* task )
{
    if(task->is_active && task->run_period < Timing_Seconds_Since(&task->time_last_ran)){ //___ > task->run_period
        return true;
        
    }else{
        return false;
    }
     // MEGN540 Update to set the return statement based on is_active and time_last_ran. 
}

/** Function Task_Run_If_Ready Function Task_Run_If_Ready checks to see if the given task is ready for execution, executes the task, 
 *  and resets the time_last_ran appropriately. If the task function pointer is NULL then it just 
 *  returns if the task is ready and resets the time_last_ran.
 */ 
bool Task_Run_If_Ready( Task_t* task )
{
    // Check to see if the task is ready to run.
    if( Task_Is_Ready(task)) 
    {        
        if(task->run_period == -1)
            task->is_active = false;
                
        (*task->task_fcn_ptr)();

        task->time_last_ran = Timing_Get_Time();
        return true;
    }
    // Note that a negative run_period indicates the task should only be performed once, while
    // a run_period of 0 indicates the task should be run every time.
    //
    // Run it if it is ready
    // Update time_last_ran and is_active as appropriate. 
    // To call a void functor (function pointer):  (*functor_variable)(); 

    return false; // true if it ran, false if it did not run
}

