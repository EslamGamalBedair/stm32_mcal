
/******************************************************************************* * 
 * Header: bsp_stm32g4.h
 *  Author: Islam Gamal Bedair 
 * Description: hardware and pin assignation  header file 
 * Latest Version: 1.0 * Last Updated: 2023-10-22 * 
 * Copyright (C) 2024 islam bedair * 
 * <licensing terms> (if any) * 
 *  History: * 
 * DATE AUTHOR REMARK 
 *  2023-10-22 Islam Gamal Bedair  Initial Version of the bsp_stm32f030.h
 * *******************************************************************************/

#ifndef BSP_STM32G4_H
#define BSP_STM32G4_H

/******************************************************************************/
/*                               INCLUDES                                     */
/******************************************************************************/
#include "../app/config.h"
#include "../mcal/mcal.h"

/************************************************************/

/******************************************************************************/
/*                                MACROS                                      */
/******************************************************************************/


#if   (XC_GP4_HARDWARE_VERSION==XC_GP4_PCB_V1)
/**
 * @brief port / pin - STATUS LED3
 */
#define ELEVATOR0_LED_PORT          GPIOB
#define ELEVATOR0_LED_PIN           GPIO_PIN_14


#elif   (XC_GP4_HARDWARE_VERSION==XC_GP4_PCB_V2)

/**
 * @brief port / pin - STATUS LED3
 */
#define ELEVATOR0_LED_PORT          GPIOB
#define ELEVATOR0_LED_PIN           GPIO_PIN_14

#endif

#endif   //bsp_RL78L13


