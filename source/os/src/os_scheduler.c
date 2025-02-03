
#include "../os/inc/os.h"
#include <stdint.h>

#define OS_SCHEDULER_MAX_NUM_OF_TASKS (OS_SCHEDULER_USER_TASKS_NUM + OS_SCHEDULER_SYSTEM_TASKS_NUM)

static os_sch_taskHandle_t  gx_os_scheduler_inetrnalUserTaskHandler[OS_SCHEDULER_MAX_NUM_OF_TASKS];
volatile uint32_t           gu32_os_scheduler_tasksTimeline[OS_SCHEDULER_MAX_NUM_OF_TASKS] ;
volatile uint32_t           gu32_os_scheduler_wcettasksTimeline[OS_SCHEDULER_MAX_NUM_OF_TASKS] ;
volatile uint8_t            gu8_os_scheduler_taskOverRun_flag ;
static os_sch_fault_t       gu8_os_scheduler_fault = OS_SCH_NO_FAULT;
void os_scheduler_init(void)
{
	//MCAL_GLOBAL_INTERRUPTS_DISABLE();
    for (uint8_t i = 0; i < OS_SCHEDULER_MAX_NUM_OF_TASKS; i++)
    {
        gx_os_scheduler_inetrnalUserTaskHandler[i].delay = 0;
        gx_os_scheduler_inetrnalUserTaskHandler[i].period = 0;
        gx_os_scheduler_inetrnalUserTaskHandler[i].run = 0;
        gx_os_scheduler_inetrnalUserTaskHandler[i].task = NULL;
        gx_os_scheduler_inetrnalUserTaskHandler[i].args = NULL;
    }
}
void ImportantFunction1(void) {
    /* Important function 1 */
    uint32_t prim;
    
    /* Do some stuff here which can be interrupted */
    
    /* Read PRIMASK register, check interrupt status before you disable them */
    /* Returns 0 if they are enabled, or non-zero if disabled */
    prim = __get_PRIMASK();
    
    /* Disable interrupts */
    __disable_irq();
    
    /* Do some stuff here which can not be interrupted */
    
    /* Call subfunction */
   // ImportantFunction2();
    
    /* Do some stuff here which can not be interrupted */
    /* This part is still interrupt safe because ImportantFunction2 will not enable interrupts */
    
    /* Enable interrupts back */
    if (!prim) {
        __enable_irq();
    }
    
    /* Do some stuff here which can be interrupted */
}

void os_scheduler_start(void)
{
    os_tick_init();
    for (;;)
    {
        os_scheduler_dispatch();
    }
}
uint32_t *os_scheduler_tasksTimeline_get(void)
{
    return (uint32_t *)gu32_os_scheduler_tasksTimeline;
}
uint32_t *os_scheduler_wcetTasksTimeline_get(void)
{
    return (uint32_t *)gu32_os_scheduler_wcettasksTimeline;
}
uint8_t os_scheduler_taskOverRunFlag_get(void)
{
    return gu8_os_scheduler_taskOverRun_flag;
}
os_sch_fault_t os_scheduler_fault_get(void)
{
    return gu8_os_scheduler_fault;
}
void os_scheduler_fault_set(os_sch_fault_t fault)
{
    gu8_os_scheduler_fault = fault;
}
void os_scheduler_task_add(void (*task)(void *), void *args, uint32_t u32_delay, uint32_t u32_period)
{
    uint8_t i = 0;
    for (i = 0; i < OS_SCHEDULER_MAX_NUM_OF_TASKS; i++)
    {
    	if (gx_os_scheduler_inetrnalUserTaskHandler[i].period == 0)
		{
			gx_os_scheduler_inetrnalUserTaskHandler[i].task = NULL;
		}
        if (gx_os_scheduler_inetrnalUserTaskHandler[i].task == NULL)
        {
            gx_os_scheduler_inetrnalUserTaskHandler[i].delay = u32_delay;
            gx_os_scheduler_inetrnalUserTaskHandler[i].period = u32_period;
            gx_os_scheduler_inetrnalUserTaskHandler[i].run = 0;
            gx_os_scheduler_inetrnalUserTaskHandler[i].task = task;
            gx_os_scheduler_inetrnalUserTaskHandler[i].args = args;
            return;
        }

    }

    gu8_os_scheduler_fault = OS_SCH_TASK_OVERFLOW_FAULT;
}
void os_scheduler_task_delete(void (*task)(void *), void *args)
{
    uint8_t i = 0;
    for (i = 0; i < OS_SCHEDULER_MAX_NUM_OF_TASKS; i++)
    {
        if ((gx_os_scheduler_inetrnalUserTaskHandler[i].task == task) && (gx_os_scheduler_inetrnalUserTaskHandler[i].args == args))
        {
            gx_os_scheduler_inetrnalUserTaskHandler[i].task = NULL;
            break;
        }
    }
}

void os_scheduler_dispatch(void)
{
    for (uint8_t i = 0; i < OS_SCHEDULER_MAX_NUM_OF_TASKS; i++)
    {
        if (gx_os_scheduler_inetrnalUserTaskHandler[i].task != NULL && gx_os_scheduler_inetrnalUserTaskHandler[i].run > 0)
        {
            gx_os_scheduler_inetrnalUserTaskHandler[i].run--;
            gx_os_scheduler_inetrnalUserTaskHandler[i].task(gx_os_scheduler_inetrnalUserTaskHandler[i].args);
        }
    }
}

void os_scheduler_update(void)
{
    for (uint8_t i = 0; i < OS_SCHEDULER_MAX_NUM_OF_TASKS; i++)
    {
        if (gx_os_scheduler_inetrnalUserTaskHandler[i].task != NULL)
        {
            if (gx_os_scheduler_inetrnalUserTaskHandler[i].delay > 0)
                gx_os_scheduler_inetrnalUserTaskHandler[i].delay -= OS_TICK_PERIOD_MS;
            if (gx_os_scheduler_inetrnalUserTaskHandler[i].delay <= 0)
            {
                gx_os_scheduler_inetrnalUserTaskHandler[i].delay = gx_os_scheduler_inetrnalUserTaskHandler[i].period;
                gx_os_scheduler_inetrnalUserTaskHandler[i].run++;
            }
        }
    }
}
