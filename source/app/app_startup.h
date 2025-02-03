/**********************************************************************/
/*                                                                    */
/*  FILE        : app_startup.h                     		      */
/*  DATE        : Tue, Oct 24, 2023                                   */
/*  Last Update : Tue, Oct 24, 2023                            		  */
/*  DESCRIPTION : app_startup config  Header                     			  */
/*  CPU GROUP   : stm32g4                                              */
/*  Author      : Islam Gamal Bedair						          */
/*                          						                  */
/***********************************************************************/
/*********************************************************************/
#ifndef APP_STARTUP_H

#define APP_STARTUP_H

/*********************************************************************/
#include "../utils/utils.h"
#include "../utils/bit_math.h"

/************************************************************/
#include "../os/inc/os.h"

/*******************************************************************************************/

#include "../app/config.h"


void app_startup_init(void);
void app_startupTasks_create(void);
void app_init(void);
#endif
