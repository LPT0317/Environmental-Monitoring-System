/* 
 * File:   main_menu.h
 * Author: lephu
 *
 * Created on December 14, 2022, 7:24 AM
 */

#ifndef MAIN_MENU_H
#define	MAIN_MENU_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Drivers/p18f4620_gpio.h"
#include "../Software/menu_var.h"
#include "../Software/menu_value.h"
#include "../Software/buzzer.h"
  
/* Function prototypes -------------------------------------------------------*/
void fsm_main_menu(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_MENU_H */

