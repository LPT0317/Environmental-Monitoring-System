/* 
 * File:   menu.h
 * Author: lephu
 *
 * Created on December 1, 2022, 7:07 PM
 */

#ifndef MENU_H
#define	MENU_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Drivers/p18f4620_lcd.h"
#include "../Drivers/p18f4620_gpio.h"
#include "../Software/sensor.h"
  
/* Function prototypes -------------------------------------------------------*/
void fsm_menu(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */

