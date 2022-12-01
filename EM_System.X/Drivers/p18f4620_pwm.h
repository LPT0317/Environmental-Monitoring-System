/* 
 * File:   p18f4620_pwm.h
 * Author: lephu
 *
 * Created on December 1, 2022, 3:17 PM
 */

#ifndef P18F4620_PWM_H
#define	P18F4620_PWM_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
  
/* Function prototypes -------------------------------------------------------*/
void PIC_PWM_INIT(void);
void PIC_PWM_SET(unsigned char value);


#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_PWM_H */

