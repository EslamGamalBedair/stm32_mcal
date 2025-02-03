


#include "../hal/wdt/wdt.h"



void app_startup_init(void)
{

}

void app_startupTasks_create(void)
{
	// os_scheduler_task_add(communication_task,   NULL, 0  , COMM_TASK_UPDATE_PERIOD         );
    // os_scheduler_task_add(os_timer_update   ,   NULL, 0  , OS_TIMER_UPDATE_PERIOD_MS       );
    //  os_scheduler_task_add(sys_helth ,   NULL, 0  , USER_INTERFACE_UPDATE_PERIOD    );
    //  os_scheduler_task_add(wdt_update        ,   NULL, 0  , WDT_UPDATE_PERIOD_MS        );
}


void app_init(void)
{
    app_startup_init();
    app_startupTasks_create();
}

/********************************************************************************/
