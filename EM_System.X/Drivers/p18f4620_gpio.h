/* 
 * File:   p18f4620_gpio.h
 * Author: lephu
 *
 * Created on November 26, 2022, 9:23 AM
 */

#ifndef P18F4620_GPIO_H
#define	P18F4620_GPIO_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
  
/* Defines GPIO --------------------------------------------------------------*/
#define GPIO_PIN_1 0
#define GPIO_PIN_2 1
#define GPIO_PIN_A 3
#define GPIO_PIN_4 4      
#define GPIO_PIN_5 5
#define GPIO_PIN_B 7

#define MAX_ROW 2
#define MAX_COL 3
  
#define NO_BUTTON 6
/* Function prototypes -------------------------------------------------------*/
void PIC_BUTTON_INIT(void);
void PIC_SCAN_BUTTON(void);
unsigned int PIC_GPIO_ReadPin(unsigned int button);

#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_GPIO_H */

