

#include "../os/inc/os.h"
#include "stm32f0xx_hal.h"
#include <stdint.h>

 uint32_t gu32_os_tick_timestamp;

void os_tick_init(void)
{
	HAL_SetTickFreq( (HAL_TickFreqTypeDef)OS_TICK_PERIOD_MS);
	HAL_Init();
}

void os_tick_update(void (*updateFn)(void))
{
    gu32_os_tick_timestamp += OS_TICK_PERIOD_MS;
    updateFn();
}

uint32_t os_tick_millis_get(void)
{
    return gu32_os_tick_timestamp;
}
