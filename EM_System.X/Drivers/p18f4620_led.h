/* 
 * File:   p18f4620_led.h
 * Author: lephu
 *
 * Created on December 15, 2022, 9:01 AM
 */

#ifndef P18F4620_LED_H
#define	P18F4620_LED_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
  
/* Defines GPIO --------------------------------------------------------------*/
#define OFF 0
#define RED 1
#define GREEN 2
#define BLUE 3
  
/* Function prototypes -------------------------------------------------------*/
void PIC_LED_INIT(void);
void PIC_LED_ON(unsigned int color);
void PIC_LED_OFF(void);

#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_LED_H */

