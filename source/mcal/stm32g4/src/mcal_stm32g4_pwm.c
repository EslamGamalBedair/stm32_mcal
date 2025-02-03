// NOTE:
//when Freq is 10 mega
//minimum freq -> (10mega/65535) = 153HZ   , maximum freq -> 10mega
//maximum time -> 6 milli                  , minimum time -> 0.1 micro

#include "mcal.h"

void mcal_pwm_init(void)
{
    // do nothing
}

void mcal_pwm_channel_set(mcal_pwm_t *x_pwmInerface, mcal_pwmConfig_t *x_pwmConfig)
{
    uint32_t u32_periodUs;
    u32_periodUs = (1000000UL / x_pwmConfig->freq);
    unsigned int reg_one = (u32_periodUs * 10);
    unsigned long val = ((x_pwmConfig->duty * reg_one) / 100);
    unsigned int value = val;
    TMRB_InitTypeDef m_tmrb;
    TMRB_FFOutputTypeDef PPGFFInital;

    GPIO_SetOutput(x_pwmConfig->port, x_pwmConfig->pin);
    if (x_pwmInerface == MCAL_PWM_5 || x_pwmInerface == MCAL_PWM_6)
    {
        GPIO_EnableFuncReg(x_pwmConfig->port, GPIO_FUNC_REG_2, x_pwmConfig->pin);
    }
    else
    {
        GPIO_EnableFuncReg(x_pwmConfig->port, GPIO_FUNC_REG_1, x_pwmConfig->pin);
    }

    m_tmrb.Mode = TMRB_INTERVAL_TIMER;
    m_tmrb.ClkDiv = TMRB_CLK_DIV_8;
    m_tmrb.UpCntCtrl = TMRB_AUTO_CLEAR;
    m_tmrb.TrailingTiming = reg_one; /* T = 250us */
    m_tmrb.LeadingTiming = reg_one - value;
    PPGFFInital.FlipflopCtrl = TMRB_FLIPFLOP_CLEAR;
    PPGFFInital.FlipflopReverseTrg = TMRB_FLIPFLOP_MATCH_TRAILINGTIMING | TMRB_FLIPFLOP_MATCH_LEADINGTIMING;

    TMRB_Enable(x_pwmInerface);
    TMRB_Init(x_pwmInerface, &m_tmrb);
    TMRB_SetFlipFlop(x_pwmInerface, &PPGFFInital);
    TMRB_SetDoubleBuf(x_pwmInerface, ENABLE, TMRB_WRITE_REG_SEPARATE); /* enable double buffer */
}

void mcal_pwm_channelState_set(mcal_pwm_t *x_pwmInerface, mcal_pwm_state_t x_state)
{
    TMRB_SetRunState(x_pwmInerface, x_state);
}

void mcal_pwm_channel_enable(mcal_pwm_t *x_pwmInerface)
{
    TMRB_SetRunState(x_pwmInerface, TMRB_RUN);
}

void mcal_pwm_channel_disable(mcal_pwm_t *x_pwmInerface)
{
    TMRB_SetRunState(x_pwmInerface, TMRB_STOP);
}
