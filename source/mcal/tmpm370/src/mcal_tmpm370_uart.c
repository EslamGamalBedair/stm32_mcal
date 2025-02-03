#include "mcal.h"
#include "bsp.h"

void mcal_uart_init(void)
{
    // do nothing
}

void mcal_uart_channel_set(mcal_uart_t x_uart, mcal_uartConfig_t *px_uartConfig)
{
    TSB_SC_TypeDef *uartx;
    UART_InitTypeDef conf;

    if (x_uart == MCAL_UART_UART0)
    {
        uartx = TSB_SC0;
        GPIO_SetOutputEnableReg(MCAL_GPIO_PORTE, MCAL_GPIO_PIN0, ENABLE);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTE, GPIO_FUNC_REG_1, MCAL_GPIO_PIN0);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTE, GPIO_FUNC_REG_1, MCAL_GPIO_PIN1);
        GPIO_SetInputEnableReg(MCAL_GPIO_PORTE, MCAL_GPIO_PIN1, ENABLE);
        if (px_uartConfig->rxInterruptEN == 1)
        {
            NVIC_EnableIRQ(INTRX0_IRQn);
        }
    }
    else if (x_uart == MCAL_UART_UART1)
    {
        uartx = TSB_SC1;
        GPIO_SetOutputEnableReg(MCAL_GPIO_PORTA, MCAL_GPIO_PIN5, ENABLE);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTA, GPIO_FUNC_REG_1, MCAL_GPIO_PIN5);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTA, GPIO_FUNC_REG_1, MCAL_GPIO_PIN6);
        GPIO_SetInputEnableReg(MCAL_GPIO_PORTA, MCAL_GPIO_PIN6, ENABLE);

        if (px_uartConfig->rxInterruptEN == 1)
        {
            NVIC_EnableIRQ(INTRX1_IRQn);
        }
    }
    else if (x_uart == MCAL_UART_UART2)
    {
        uartx = TSB_SC2;
        GPIO_SetOutputEnableReg(MCAL_GPIO_PORTD, MCAL_GPIO_PIN5, ENABLE);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTD, GPIO_FUNC_REG_1, MCAL_GPIO_PIN5);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTD, GPIO_FUNC_REG_1, MCAL_GPIO_PIN6);
        GPIO_SetInputEnableReg(MCAL_GPIO_PORTD, MCAL_GPIO_PIN6, ENABLE);
        if (px_uartConfig->rxInterruptEN == 1)
        {
            NVIC_EnableIRQ(INTRX2_IRQn);
        }
    }
    else if (x_uart == MCAL_UART_UART3)
    {
        uartx = TSB_SC3;
        GPIO_SetOutputEnableReg(MCAL_GPIO_PORTF, MCAL_GPIO_PIN3, ENABLE);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTF, GPIO_FUNC_REG_2, MCAL_GPIO_PIN3);
        GPIO_EnableFuncReg(MCAL_GPIO_PORTF, GPIO_FUNC_REG_2, MCAL_GPIO_PIN4);
        GPIO_SetInputEnableReg(MCAL_GPIO_PORTF, MCAL_GPIO_PIN4, ENABLE);
        if (px_uartConfig->rxInterruptEN == 1)
        {
            NVIC_EnableIRQ(INTRX3_IRQn);
        }
    }
    else
    {
        /*  Do Nothing */
    }

    /* configure SIO0 for reception */
    UART_Enable(uartx);
    conf.BaudRate = px_uartConfig->baudRate;
    conf.DataBits = px_uartConfig->dataBits;
    conf.StopBits = px_uartConfig->stopBits;
    conf.Parity = px_uartConfig->parity;
    conf.Mode = px_uartConfig->mode;
    conf.FlowCtrl = MCAL_UART_FLOW_CTRL_NONE;

    UART_Init(uartx, (UART_InitTypeDef *)&conf);
}

void mcal_uart_data_put(mcal_uart_t x_uart, uint8_t u8_data)
{
    TSB_SC_TypeDef *uartx;

    switch (x_uart)
    {
    case MCAL_UART_UART0:
        uartx = TSB_SC0;
        break;
    case MCAL_UART_UART1:
        uartx = TSB_SC1;
        break;
    case MCAL_UART_UART2:
        uartx = TSB_SC2;
        break;
    case MCAL_UART_UART3:
        uartx = TSB_SC3;
        break;
    default:
        // do nothing
        break;
    }
    UART_SetTxData(uartx, u8_data);
    while ((UART_GetBufState(uartx, MCAL_UART_DIR_TX)) == BUSY)
        ;
}

uint8_t mcal_uart_data_get(mcal_uart_t x_uart)
{
    uint8_t u8_data;
    TSB_SC_TypeDef *uartx;

    switch (x_uart)
    {
    case MCAL_UART_UART0:
        uartx = TSB_SC0;
        break;
    case MCAL_UART_UART1:
        uartx = TSB_SC1;
        break;
    case MCAL_UART_UART2:
        uartx = TSB_SC2;
        break;
    case MCAL_UART_UART3:
        uartx = TSB_SC3;
        break;
    default:
        // do nothing
        break;
    }

    // while ((UART_GetBufState(px_uart, MCAL_UART_DIR_RX)) == BUSY)
    // {
    // }
    u8_data = (uint8_t)UART_GetRxData(uartx);
    return u8_data;
}

void mcal_uart_dma_init(void)
{
    // not available in this mcu
}

uint32_t mcal_uart_dma_set(uint8_t *pu8_txBuffer, uint32_t u32_length, uint32_t u32_channel)
{
    // not available in this mcu
    return 0xffffffff;
}

uint32_t mcal_uart_dma_get(uint8_t *pu8_rxBuffer, uint32_t u32_length, uint32_t u32_channel)
{
    // not available in this mcu
    return 0xffffffff;
}

void mcal_uart_string_put(mcal_uart_t x_uart, uint8_t *pu8_ptr)
{
    static uint8_t u8_i = 0;
    TSB_SC_TypeDef *uartx;

    switch (x_uart)
    {
    case MCAL_UART_UART0:
        uartx = TSB_SC0;
        break;
    case MCAL_UART_UART1:
        uartx = TSB_SC1;
        break;
    case MCAL_UART_UART2:
        uartx = TSB_SC2;
        break;
    case MCAL_UART_UART3:
        uartx = TSB_SC3;
        break;
    default:
        // do nothing
        break;
    }
    while (pu8_ptr[u8_i] != '\0')
    {
        UART_SetTxData(uartx, pu8_ptr[u8_i]);
        u8_i++;
        while ((UART_GetBufState(uartx, UART_TX)) == BUSY)
            ;
    }
    u8_i = 0;
#if 0
	  if(u8_i >= (sizeof(TX_data)/sizeof(TX_data[0]))-1){ i=0;}
#endif
}

void mcal_uart_string_get(mcal_uart_t x_uart, uint8_t *pu8_ptr)
{
    uint8_t u8_u = 0;
    do
    {
        pu8_ptr[u8_u] = mcal_uart_data_get(x_uart);
    } while (pu8_ptr[u8_u++] != '*');
    pu8_ptr[u8_u - 1] = '\0';
    u8_u = 0;
}
