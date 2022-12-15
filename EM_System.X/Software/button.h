/* 
 * File:   button.h
 * Author: lephu
 *
 * Created on December 15, 2022, 7:28 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Drivers/p18f4620_gpio.h"
  
/* Function prototypes -------------------------------------------------------*/
void button_Input(void);
unsigned int button_Pressed(unsigned int button_name);


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTON_H */

