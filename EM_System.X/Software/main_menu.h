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
#include "../Drivers/p18f4620_led.h"
#include "../Software/menu_var.h"
#include "../Software/menu_value.h"
#include "../Software/menu_set.h"
#include "../Software/menu_alert.h"
#include "../Software/buzzer.h"
#include "../Software/led.h"
#include "../Software/button.h"
  
/* Function prototypes -------------------------------------------------------*/
void fsm_main_menu(void);
int check_Setting(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_MENU_H */

