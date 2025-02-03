#ifndef _MCAL_H_
#define _MCAL_H_

#include "../TMPM370F/TMPM370.h"
#include "../mcu_core/inc/tx03_common.h"
#include "../mcu_core/inc/tmpm370_cg.h"
#include "../mcu_core/inc/tmpm370_enc.h"
#include "../mcu_core/inc/tmpm370_fc.h"
#include "../mcu_core/inc/tmpm370_gpio.h"
#include "../mcu_core/inc/tmpm370_ofd.h"
#include "../mcu_core/inc/tmpm370_pmd.h"
#include "../mcu_core/inc/tmpm370_adc.h"
#include "../mcu_core/inc/tmpm370_tmrb.h"
#include "../mcu_core/inc/tmpm370_uart.h"
#include "../mcu_core/inc/tmpm370_vltd.h"
#include "../mcu_core/inc/tmpm370_wdt.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "inttypes.h"

#define MCAL_GLOBAL_INTERRUPTS_DISABLE() __disable_irq()
#define MCAL_GLOBAL_INTERRUPTS_ENABLE() __enable_irq()

//typedef unsigned char uint8_t;
//typedef unsigned short uint16_t;
//typedef unsigned int uint32_t;

/******************************************************************************/
// gpio

typedef GPIO_Port mcal_gpio_portEnum_t;
#define MCAL_GPIO_PORTA GPIO_PA
#define MCAL_GPIO_PORTB GPIO_PB
#define MCAL_GPIO_PORTC GPIO_PC
#define MCAL_GPIO_PORTD GPIO_PD
#define MCAL_GPIO_PORTE GPIO_PE
#define MCAL_GPIO_PORTF GPIO_PF
#define MCAL_GPIO_PORTG GPIO_PG
#define MCAL_GPIO_PORTH GPIO_PH
#define MCAL_GPIO_PORTI GPIO_PI
#define MCAL_GPIO_PORTJ GPIO_PJ
#define MCAL_GPIO_PORTK GPIO_PK
#define MCAL_GPIO_PORTL GPIO_PL

typedef uint8_t mcal_gpio_pinEnum_t;
#define MCAL_GPIO_PIN0 GPIO_BIT_0
#define MCAL_GPIO_PIN1 GPIO_BIT_1
#define MCAL_GPIO_PIN2 GPIO_BIT_2
#define MCAL_GPIO_PIN3 GPIO_BIT_3
#define MCAL_GPIO_PIN4 GPIO_BIT_4
#define MCAL_GPIO_PIN5 GPIO_BIT_5
#define MCAL_GPIO_PIN6 GPIO_BIT_6
#define MCAL_GPIO_PIN7 GPIO_BIT_7
#define MCAL_GPIO_PIN_ALL GPIO_BIT_ALL

typedef uint8_t mcal_gpio_ioStateEnum_t;
#define MCAL_GPIO_INPUT GPIO_INPUT_MODE
#define MCAL_GPIO_OUTPUT GPIO_OUTPUT_MODE
#define MCAL_GPIO_NONE GPIO_IO_MODE_NONE

typedef uint8_t mcal_gpio_stateEnum_t;
#define MCAL_GPIO_LOW GPIO_BIT_VALUE_0
#define MCAL_GPIO_HIGH GPIO_BIT_VALUE_1

typedef uint8_t mcal_gpio_extIntPolarityEnum_t;
#define MCAL_GPIO_EXTINT_RISING_EDGE (RISING_EDGE)
#define MCAL_GPIO_EXTINT_FALLING_EDGE (FALLING_EDGE)
#define MCAL_GPIO_EXTINT_BOTH_EDGES (BOTH_EDGES)
#define MCAL_GPIO_EXTINT_NONE (0U)

typedef uint8_t mcal_gpio_extIntStateEnum_t;
#define MCAL_GPIO_EXTINT_ENABLE (EXT_INT_ENABLE)
#define MCAL_GPIO_EXTINT_DISABLE (EXT_INT_DISABLE)

typedef enum
{
    MCAL_GPIO_NORMAL,
    MCAL_GPIO_ALT_FUNC_1,
    MCAL_GPIO_ALT_FUNC_2,
    MCAL_GPIO_ALT_FUNC_3
} mcal_gpio_alternateFnEnum_t;

typedef enum
{
    EXT_INT_RISING_EDGE,
    EXT_INT_FALLING_EDGE,
    EXT_INT_LEVEL_TOGGLE,
    EXT_INT_LEVEL_LOW
} mcal_extIntPolarityEnum_t;

typedef struct
{
    mcal_gpio_portEnum_t port;
    mcal_gpio_pinEnum_t pin;
    mcal_gpio_ioStateEnum_t ioState;
    mcal_gpio_stateEnum_t pinState;
    mcal_gpio_extIntStateEnum_t extIntState;
    mcal_gpio_extIntPolarityEnum_t extIntPolarity;
} mcal_gpio_t;

void mcal_gpio_init(void);
void mcal_gpio_pin_init(mcal_gpio_t *px_gpio);
void mcal_gpio_pinState_set(mcal_gpio_t *px_gpio, mcal_gpio_stateEnum_t u8_state);
void mcal_gpio_portState_set(mcal_gpio_t *px_gpio, mcal_gpio_stateEnum_t x_state);
void mcal_gpio_pinIOState_set(mcal_gpio_t *px_gpio, mcal_gpio_ioStateEnum_t x_ioState);
void mcal_gpio_pinState_toggle(mcal_gpio_t *px_gpio);
uint8_t mcal_gpio_pinState_get(mcal_gpio_t *px_gpio);
uint8_t mcal_gpio_portState_get(mcal_gpio_t *px_gpio);
void mcal_gpio_altFunction_set(mcal_gpio_t *px_gpio, mcal_gpio_alternateFnEnum_t x_func);

/********************************************************************************/
// clock generator

void mcal_cg_init(void);
void mcal_cg_system_set(void);
void mcal_cg_WDTSystem_set(CG_DivideLevel DivideFgearFromFc);
void mcal_cg_normalToStopMode_set(void);

/********************************************************************************/
// wdt

#define MCAL_WDT_RESET_TIME_L0 WDT_DETECT_TIME_EXP_15
#define MCAL_WDT_RESET_TIME_L1 WDT_DETECT_TIME_EXP_17
#define MCAL_WDT_RESET_TIME_L2 WDT_DETECT_TIME_EXP_19
#define MCAL_WDT_RESET_TIME_L3 WDT_DETECT_TIME_EXP_21
#define MCAL_WDT_RESET_TIME_L4 WDT_DETECT_TIME_EXP_23
#define MCAL_WDT_RESET_TIME_L5 WDT_DETECT_TIME_EXP_25

void mcal_wdt_init(void);
void mcal_wdt_set(uint32_t resetTime);
void mcal_wdt_feed(void);
void mcal_wdt_disable(void);
void mcal_wdt_enable(void);
void mcal_wdt_clockConfig_set(CG_DivideLevel DivideFgearFromFc, uint32_t resetTime);

/********************************************************************************/
// systick

void mcal_sysTick_init(void);
void mcal_sysTick_set(uint32_t u32_tickms);
void mcal_sysTick_resume(void);

/********************************************************************************/
// uart

typedef uint8_t mcal_uart_t;
#define MCAL_UART_UART0 (0)
#define MCAL_UART_UART1 (1)
#define MCAL_UART_UART2 (2)
#define MCAL_UART_UART3 (3)

typedef uint32_t mcal_uartDataBitsEnum_t;
#define MCAL_UART_DATA_BITS_7 (UART_DATA_BITS_7)
#define MCAL_UART_DATA_BITS_8 (UART_DATA_BITS_8)
#define MCAL_UART_DATA_BITS_9 (UART_DATA_BITS_9)

typedef uint32_t mcal_uartStopBitsEnum_t;
#define MCAL_UART_STOP_BITS_1 (UART_STOP_BITS_1)
#define MCAL_UART_STOP_BITS_2 (UART_STOP_BITS_2)

typedef uint32_t mcal_uartParityEnum_t;
#define MCAL_UART_PARITY_NO (UART_NO_PARITY)
#define MCAL_UART_PARITY_EVEN (UART_EVEN_PARITY)
#define MCAL_UART_PARITY_ODD (UART_ODD_PARITY)

typedef uint32_t mcal_uartModeEnum_t;
#define MCAL_UART_MODE_RX (UART_ENABLE_RX)
#define MCAL_UART_MODE_TX (UART_ENABLE_TX)
#define MCAL_UART_MODE_TXRX (MCAL_UART_MODE_RX | MCAL_UART_MODE_TX)

typedef uint32_t mcal_uartFlowControlEnum_t;
#define MCAL_UART_FLOW_CTRL_NONE (UART_NONE_FLOW_CTRL)

typedef uint32_t mcal_uartDirectionEnum_t;
#define MCAL_UART_DIR_RX (UART_RX)
#define MCAL_UART_DIR_TX (UART_TX)

typedef struct
{
    mcal_gpio_t txPin;
    mcal_gpio_t rxPin;
    uint32_t baudRate;
    mcal_uartDataBitsEnum_t dataBits;
    mcal_uartStopBitsEnum_t stopBits;
    mcal_uartParityEnum_t parity;
    mcal_uartModeEnum_t mode;
    mcal_uartFlowControlEnum_t flowControl;
    uint8_t rxInterruptEN;
    uint8_t chainInterval;
} mcal_uartConfig_t;

void mcal_uart_init(void);
void mcal_uart_channel_set(mcal_uart_t x_uart, mcal_uartConfig_t *px_uartConfig);
void mcal_uart_data_put(mcal_uart_t x_uart, uint8_t u8_data);
uint8_t mcal_uart_data_get(mcal_uart_t x_uart);
void mcal_uart_dma_init(void);
uint32_t mcal_uart_dma_set(uint8_t *pu8_txBuffer, uint32_t u32_length, uint32_t u32_channel);
uint32_t mcal_uart_dma_get(uint8_t *pu8_rxBuffer, uint32_t u32_length, uint32_t u32_channel);
void mcal_uart_string_put(mcal_uart_t x_uart, uint8_t *pu8_ptr);
void mcal_uart_string_get(mcal_uart_t x_uart, uint8_t *pu8_ptr);

/********************************************************************************/
// timer

typedef TSB_TB_TypeDef mcal_timer_t;
#define MCAL_TIMER_0 TSB_TB0
#define MCAL_TIMER_1 TSB_TB1
#define MCAL_TIMER_2 TSB_TB2
#define MCAL_TIMER_3 TSB_TB3
#define MCAL_TIMER_4 TSB_TB4
#define MCAL_TIMER_5 TSB_TB5
#define MCAL_TIMER_6 TSB_TB6
#define MCAL_TIMER_7 TSB_TB7

typedef uint32_t mcal_timer_timerState_t;
#define MCAL_TIMER_START TMRB_RUN
#define MCAL_TIMER_STOP TMRB_STOP

typedef uint8_t mcal_timer_eventEdgeConfig_t;
#define MCAL_TIMER_EDGE_RISING TMRB_TRG_EDGE_RISING
#define MCAL_TIMER_EDGE_FALLING TMRB_TRG_EDGE_FALLING

typedef enum
{
    MCAL_TIMER_INT_ENABLE = 1,
    MCAL_TIMER_INT_DISABLE = 0
} mcal_timer_intModeEnum_t;

void mcal_timer_init(void);
void mcal_timer_timerModeMS_init(mcal_timer_t *px_tb, uint32_t u32_timeMS);
void mcal_timer_timerModeUS_init(mcal_timer_t *px_tb, uint32_t u32_timeUS);
void mcal_timer_eventMode_init(mcal_timer_t *px_tb, mcal_gpio_t *px_portConfig, mcal_timer_eventEdgeConfig_t x_edge);
void mcal_timer_timerInterruptState_set(mcal_timer_t *px_tb, mcal_timer_intModeEnum_t x_intState);
void mcal_timer_timerChannel_enable(mcal_timer_t *px_tb);
void mcal_timer_timerChannel_disable(mcal_timer_t *px_tb);
void mcal_timer_timerState_set(mcal_timer_t *px_tb, mcal_timer_timerState_t x_state);
void mcal_timer_timerFlag_clear(mcal_timer_t *px_tb);
uint32_t mcal_timer_timerFlag_get(mcal_timer_t *px_tb);
void mcal_timer_timerCounter_reset(mcal_timer_t *px_tb);
uint32_t mcal_timer_timerCounter_get(mcal_timer_t *px_tb);
void mcal_timer_softWareCap(mcal_timer_t *px_tb);

/********************************************************************************/
// pwm
typedef struct
{
    mcal_gpio_portEnum_t port;
    mcal_gpio_pinEnum_t pin;
    uint32_t freq;
    uint32_t duty;
    uint8_t type;
} mcal_pwmConfig_t;

typedef TSB_TB_TypeDef mcal_pwm_t;
#define MCAL_PWM_0 TSB_TB0
#define MCAL_PWM_1 TSB_TB1
#define MCAL_PWM_2 TSB_TB2
#define MCAL_PWM_3 TSB_TB3
#define MCAL_PWM_4 TSB_TB4
#define MCAL_PWM_5 TSB_TB5
#define MCAL_PWM_6 TSB_TB6
#define MCAL_PWM_7 TSB_TB7

typedef uint32_t mcal_pwm_state_t;
#define MCAL_PWM_START TMRB_RUN
#define MCAL_PWM_STOP TMRB_STOP

void mcal_pwm_init(void);
void mcal_pwm_channel_set(mcal_pwm_t *x_pwmInerface, mcal_pwmConfig_t *x_pwmConfig);
void mcal_pwm_channelState_set(mcal_pwm_t *x_pwmInerface, mcal_pwm_state_t x_state);
void mcal_pwm_channel_enable(mcal_pwm_t *x_pwmInerface);
void mcal_pwm_channel_disable(mcal_pwm_t *x_pwmInerface);

/********************************************************************************/
// adc
typedef enum
{
    MCAL_ADC_CH0 = 0U,
    MCAL_ADC_CH1 = 1U,
    MCAL_ADC_CH2 = 2U,
    MCAL_ADC_CH3 = 3U,
    MCAL_ADC_CH4 = 4U,
    MCAL_ADC_CH5 = 5U,
    MCAL_ADC_CH6,
    MCAL_ADC_CH7,
    MCAL_ADC_CH8,
    MCAL_ADC_CH9,
    MCAL_ADC_CH10,
    MCAL_ADC_CH11,
    MCAL_ADC_CH12,
    MCAL_ADC_CH13,
    MCAL_ADC_CH14,
    MCAL_ADC_CH15,
    MCAL_ADC_CH16,
    MCAL_ADC_CH17,
    MCAL_ADC_CH18,
    MCAL_ADC_CH19,
    MCAL_ADC_CH20
} mcal_adc_chEnum_t;

typedef uint8_t mcal_adc_blkEnum_t;
#define MCAL_ADC_BLK_A 0
#define MCAL_ADC_BLK_B 1

void mcal_adc_init(void);
void mcal_adc_set(mcal_adc_blkEnum_t x_adcBlock);
void mcal_adc_channel_set(mcal_adc_blkEnum_t x_adcBlock, mcal_adc_chEnum_t x_adcCh);
void mcal_adc_conversion_start(mcal_adc_blkEnum_t x_adcBlock, mcal_adc_chEnum_t x_adcCh);
uint32_t mcal_adc_conversionResult_get(mcal_adc_blkEnum_t x_adcBlock, mcal_adc_chEnum_t x_adcCh);
uint32_t mcal_adc_conversionStatus_get(mcal_adc_blkEnum_t x_adcBlock, mcal_adc_chEnum_t x_adcCh);
void mcal_adc_flag_clear(mcal_adc_blkEnum_t x_adcBlock, mcal_adc_chEnum_t x_adcCh);

#endif
