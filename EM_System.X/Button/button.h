/* 
 * File:   button.h
 * Author: lephu
 *
 * Created on November 26, 2022, 10:15 AM
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
void getKeyInput(void);
int is_Button_Pressed(unsigned int button);


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTON_H */

