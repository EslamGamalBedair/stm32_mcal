


#ifndef OS_TICK_H
#define OS_TICK_H

#include <stdint.h>


void os_tick_init(void);
void os_tick_update(void (*updateFn)(void));
uint32_t os_tick_millis_get(void);

#endif

