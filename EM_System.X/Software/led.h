/* 
 * File:   led.h
 * Author: lephu
 *
 * Created on December 15, 2022, 9:14 AM
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Software/timer_software.h"
#include "../Drivers/p18f4620_led.h"
  
/* Function prototypes -------------------------------------------------------*/
void led_blink(void);
void led_off(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

