/* 
 * File:   menu_set.h
 * Author: lephu
 *
 * Created on December 14, 2022, 7:36 AM
 */

#ifndef MENU_SET_H
#define	MENU_SET_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Drivers/p18f4620_lcd.h"
#include "../Drivers/p18f4620_gpio.h"
#include "../Software/menu_var.h"
#include "../Software/threshold.h"
#include "../Software/button.h"
  
/* Function prototypes -------------------------------------------------------*/
void fsm_menu_setting(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MENU_SET_H */

