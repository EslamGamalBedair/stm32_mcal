/***********************************************************************/
/*                                                                     */
/*  FILE        :bit_math.h                                            */
/*  DATE        :Mon, July 14, 2021                                    */
/*  DESCRIPTION :define the bit math operations                        */
/*  CPU GROUP   :  Generic                                             */
/*  AUTHOR      :Islam Gamal Bedair                                        */
/***********************************************************************/



#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#include <stdbool.h>

#define HIGH			0x1
#define LOW				0x0
#define INPUT			0x0
#define OUTPUT			0x1
#define INPUT_PULLUP	0x2
#define PI				3.141592653
#define HALF_PI			1.570796326
#define TWO_PI			6.283185307
#define DEG_TO_RAD		0.017453292
#define RAD_TO_DEG		57.29577951
#define EULER		 	2.718281828
#define BIT(n)          (1 << (n))

/* To get bit at position n in _r, _b should be BIT(n) or (1UL << n) */
#define GET_BIT(_r, _b) ((_r) & (_b))

/* To clear bit at position n in _r, _b should be BIT(n) or (1UL << n) */
#define CLR_BIT(_r, _b) ((_r) = (_r) & (~(_b)))

/* Get all bits set in mask shifted by _shift */
#define GET_BITS(_r, _shift, _mask) (((_r) & ((_mask) << (_shift))) >> (_shift))

/* Set all bits set in mask shifted by _shift */
#define SET_BITS(_r, _shift, _mask) ((_r) = (_r) | ((_mask) << (_shift)))

/* Clear all bits set in mask shifted by _shift */
#define CLR_BITS(_r, _shift, _mask) ((_r) = (_r) & (~((_mask) << (_shift))))

/* Set bits in _r in position _shift to equal _v.
    *Bits included from _v are those set in _mask */
#define WRITE_BITS(_r, _shift, _mask, _v) ((_r) = (((_r) & (~((_mask) << (_shift)))) | \
                                          ((_v & _mask) << (_shift))))
#define REG_GET_BIT(_r, _b)     GET_BIT(_r, _b)
#define REG_SET_BIT(_r, _b)     SET_BIT(_r, _b)
#define REG_CLR_BIT(_r, _b)     CLR_BIT(_r, _b)

#define REG_GET_BITS(_r, _shift, _mask)     GET_BITS(_r, _shift, _mask)
#define REG_SET_BITS(_r, _shift, _mask)     SET_BITS(_r, _shift, _mask)
#define REG_CLR_BITS(_r, _shift, _mask)     CLR_BITS(_r, _shift, _mask)
#define REG_WRITE_BITS(_r, _shift, _mask, _v)   WRITE_BITS(_r, _shift, _mask, _v)

#define BIT_CTRL(reg, index, command) ((command) == (0) ? (BIT_CLR(reg, index)) : (BIT_SET(reg, index)))





#define BIT_SET(reg, index) ((reg) |= (1 << (index)))
#define BIT_CLR(reg, index) ((reg) &= (~(1 << (index))))
#define BIT_TOG(reg, index) ((reg) ^= (1 << (index)))
#define BIT_GET(reg, index) (((reg) >> (index)) & 0x01)










#define REG_CONFIG(reg, value) ((reg) |= (value))
#define REG_SET(reg, value) ((reg) = (value))


#define CONTROL_BIT(reg, index, command) ((command) == (0) ? (CLR_BIT(reg, index)) : (SET_BIT(reg, index)))
#define WCONTROL_BIT(wreg, index, command) ((command) == (0) ? (WCLR_BIT(wreg, index)) : (WSET_BIT(wreg, index)))


#define WGET_BIT BIT_GET
#define WSET_BIT BIT_SET
#define WCLR_BIT BIT_CLR

#define MOD8(dividend, divisor) ((uint8_t)(dividend - (divisor * (uint8_t)(dividend / divisor))))
#define MOD16(dividend, divisor) ((uint16_t)(dividend - (divisor * (uint16_t)(dividend / divisor))))
#define MOD32(dividend, divisor) ((uint32_t)(dividend - (divisor * (uint32_t)(dividend / divisor))))

#define D2A(decDigit) ((decDigit) | 0x30)
#define A2D(ascDigit) ((ascDigit)&0x0f)
#define H2A(hexDigit) (((hexDigit) > 0x09) ? ((hexDigit) + 0x37) : ((hexDigit) | 0x30))
#define A2H(ascDigit) (((ascDigit) > '9') ? ((ascDigit)-0x37) : ((ascDigit)-0x30))

#define radians(deg)					((deg)*DEG_TO_RAD)
#define degrees(rad)					((rad)*RAD_TO_DEG)
#define sq(x)							((x)*(x))
#define constrain(amt,low,high)			((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define clockCyclesPerMicrosecond()		( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a)	( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a)	( (a) * clockCyclesPerMicrosecond() )
#define lowByte(w)						((uint8_t) ((w) & 0xff))
#define highByte(w)						((uint8_t) ((w) >> 8))
	
#define MAX(num1, num2) (((num1) > (num2)) ? (num1) : (num2))
#define MINIMUM(num1, num2) (((num1) < (num2)) ? (num1) : (num2))
#define SWAP(x, y) ((x) ^= (y) ^= (x) ^= (y))
#define ABS(x)     (((x) < 0) ? -(x) : (x))   /* Get absolute value */

#define UPDATE_COUNTER_CHECK(counter, interval) \
    do                                          \
    {                                           \
        counter += OS_TICK_PERIOD_MS;           \
        if ((counter) < (interval))             \
            return;                             \
        counter = 0;                            \
    } while (0)



#endif
/*_BIT_MATH_H_*/
