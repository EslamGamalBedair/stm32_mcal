#ifndef MCAL_H
#define MCAL_H 1

#include "inttypes.h"
#include "../app/config.h"
#if defined(TMPM370)
#include "mcal_tmpm370.h"
#elif defined(STM32G4)
#include "mcal_stm32g4.h"
#elif defined(ATMEGA32)
#include "mcal_atmega32.h"
#elif defined(HT66F489)
#include "mcal_ht66f489.h"
#elif defined(C17M24)
#include "mcal_c17m24.h"
#endif

typedef enum
{
    MCAL_ENABLE = 1,
    MCAL_DISABLE = 0
} mcal_functionalStateEnum_t;

typedef enum
{
    MCAL_SUCCESS = 0,
    MCAL_ERROR = 1
} mcal_resultStateEnum_t;

typedef enum
{
    MCAL_BUSY = 0,
    MCAL_DONE = 1
} mcal_workStateEnum_t;

#if defined(TMPM370)
#define MCAL_POR_REST_FLAG (TSB_CG_RSTFLG_PONRSTF)
#define MCAL_EXT_RESET_FLAG (TSB_CG_RSTFLG_PINRSTF)
#define MCAL_WDT_RESET_FLAG (TSB_CG_RSTFLG_WDTRSTF)
#define MCAL_VLTD_RESET_FLAG (TSB_CG_RSTFLG_VLTDRSTF)
#define MCAL_DEBUG_RESET_FLAG (TSB_CG_RSTFLG_DBGRSTF)
#define MCAL_OFD_RESET_FLAG (TSB_CG_RSTFLG_OFDRSTF)

#define MCAL_RESET_FLAGS_CLEAR() (TSB_CG->RSTFLG = 0)
#else
#define MCAL_POR_REST_FLAG 0
#define MCAL_EXT_RESET_FLAG 0
#define MCAL_WDT_RESET_FLAG 0
#define MCAL_VLTD_RESET_FLAG 0
#define MCAL_DEBUG_RESET_FLAG 0
#define MCAL_OFD_RESET_FLAG 0

#define MCAL_RESET_FLAGS_CLEAR() 0
#endif

#define sysTick_update() void sysTick_handler(void)

#endif
