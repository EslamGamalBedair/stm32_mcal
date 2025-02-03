/******************************************************************************* * 
 * Header: config.h
 *  Author: Islam Gamal Bedair 
 * Description: configuration of os task aperiodicity and OS tick time  header file
 * Latest Version: 1.0 * Last Updated: 2023-10-22 * 
 * Copyright (C) 20xx  d.d. *
 * <licensing terms> (if any) * 
 *  History: * 
 * DATE AUTHOR REMARK 
 *  2023-10-22 Islam Gamal Bedair  Initial Version of the config.h 
 * *******************************************************************************/
#ifndef CONFIG_H_
#define CONFIG_H_

/******************************************************************************/
/*                               INCLUDES                                     */
/******************************************************************************/


#include "stm32f0xx_hal.h"
#include "../app/timer.h"

/******************************************************************************/
/*                                MACROS                                      */
/******************************************************************************/

/* Features To be added To the System */
//t for test and p for production 24 year 32 week number 0 is version number in the same week

#define		FIRMWARE_VERSION			          "T24360" //six digit version number
#define XC_GP4_PCB_V1                          0
#define XC_GP4_PCB_V2                          1

#define XC_GP4_HARDWARE_VERSION                 XC_GP4_PCB_V1

#define MCAL_GLOBAL_INTERRUPTS_ENABLE 	        __enable_irq
#define MCAL_GLOBAL_INTERRUPTS_DISABLE 			__disable_irq

#define APP_USE_WDT                             (0)
#define OS_SCHEDULER_USER_TASKS_NUM             (10)
#define OS_SCHEDULER_SYSTEM_TASKS_NUM           (1)
/*****************************************************************/
#define OS_TICK_PERIOD_MS                       (10)
#define WDT_UPDATE_PERIOD_MS                    (OS_TICK_PERIOD_MS)
#define OS_TIMER_UPDATE_PERIOD_MS               (10)
#define LED_UPDATE_PERIOD                       (100)
#define XC_GP4_UPDATE_PERIOD                    (100)
#define LANDING_CALL_UPDATE_PERIOD			      (20)
#define COMM_TASK_UPDATE_PERIOD                 (20)
/*****************************************************************/
#define WDT_RESET_MSEC                          (WDT_DETECT_TIME_EXP_21)   //reset time according to datasheet and clock setting = 26msec
/*****************************************************************/
#define OS_TIMERS_NUMBERS                       (OS_TIMERS_NUM)
/*****************************************************************/

#define STM32G4 1



#endif   // CONFIG_H_
