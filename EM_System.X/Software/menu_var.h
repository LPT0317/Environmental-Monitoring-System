/* 
 * File:   menu_var.h
 * Author: lephu
 *
 * Created on December 13, 2022, 10:29 PM
 */

#ifndef MENU_VAR_H
#define	MENU_VAR_H

#ifdef	__cplusplus
extern "C"
{
#endif
  
/* Includes ------------------------------------------------------------------*/
#include "../Software/sensor.h"

/* Variables -----------------------------------------------------------------*/
extern rom unsigned char *menu[];
extern unsigned int value_index[];
extern unsigned int SensorName[7];
extern rom unsigned char *value_header[];
extern rom unsigned char *sensor_list[7];

#ifdef	__cplusplus
}
#endif

#endif	/* MENU_VAR_H */

