#ifndef OS_H
#define OS_H        1

#include "os_tick.h"
#include "os_timer.h"
#include "os_runtime.h"
#include "os_log.h"
#include "os_scheduler.h"
#include "../app/config.h"
#include <stdint.h>

#define OS_POR_RESET_FLAG       MCAL_POR_REST_FLAG
#define OS_EXT_RESET_FLAG       MCAL_EXT_RESET_FLAG
#define OS_WDT_RESET_FLAG       MCAL_WDT_RESET_FLAG
#define OS_VLTD_RESET_FLAG      MCAL_VLTD_RESET_FLAG
#define OS_DEBUG_RESET_FLAG     MCAL_DEBUG_RESET_FLAG
#define OS_OFD_RESET_FLAG       MCAL_OFD_RESET_FLAG

#endif
