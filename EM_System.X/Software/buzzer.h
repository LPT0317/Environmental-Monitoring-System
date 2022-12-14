/* 
 * File:   buzzer.h
 * Author: lephu
 *
 * Created on December 14, 2022, 10:45 AM
 */

#ifndef BUZZER_H
#define	BUZZER_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Drivers/p18f4620_pwm.h"
#include "../Software/timer_software.h"
  
/* Function prototypes -------------------------------------------------------*/
void buzzer_blink(void);
void buzzer_off(void);


#ifdef	__cplusplus
}
#endif

#endif	/* BUZZER_H */

