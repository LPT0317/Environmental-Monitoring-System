/* 
 * File:   menu_alert.h
 * Author: lephu
 *
 * Created on December 14, 2022, 12:07 PM
 */

#ifndef MENU_ALERT_H
#define	MENU_ALERT_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Drivers/p18f4620_lcd.h"
#include "../Drivers/p18f4620_gpio.h"
#include "../Software/menu_var.h"
#include "../Software/threshold.h"
#include "../Software/timer_software.h"
  
/* Function prototypes -------------------------------------------------------*/
void fsm_menu_alert(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MENU_ALERT_H */

