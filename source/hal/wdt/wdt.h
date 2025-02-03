/**********************************************************************/
/*                                                                    */
/*  FILE        :                      		      */
/*  DATE        : Tue, Oct 24, 2023                                   */
/*  Last Update : Tue, Oct 24, 2023                            		  */
/*  DESCRIPTION : ADC config  Header                     			  */
/*  CPU GROUP   : R5F10W                                              */
/*  Author      : Islam Gamal Bedair						          */
/*                          						                  */
/***********************************************************************/
#ifndef WDT_H
#define WDT_H

// Used to indicate if WDT is running
#define WDT_RUNNING       (0xAAAAAAAAU)
#define WDT_NOT_RUNNING   (0x55555555U)
#define WDT_UNKNOWN_STATE (0x55AA55AAU)

#define wdt_enable() mcal_wdt_enable()
#define wdt_disable() mcal_wdt_disable()

void wdt_init(void);
void wdt_update(void *arg);

#endif
