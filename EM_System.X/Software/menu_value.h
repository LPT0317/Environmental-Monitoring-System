/* 
 * File:   menu_value.h
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
#include "../Software/menu_var.h"
#include "../Software/button.h"
  
/* Function prototypes -------------------------------------------------------*/
void fsm_menu_value(void);
void menu_value_reset();

#ifdef	__cplusplus
}
#endif

#endif	/* MENU_VALUE_H */

