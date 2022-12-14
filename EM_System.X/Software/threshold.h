/* 
 * File:   threshold.h
 * Author: lephu
 *
 * Created on December 13, 2022, 10:50 PM
 */

#ifndef THRESHOLD_H
#define	THRESHOLD_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Software/sensor.h"
  
/* Variables -----------------------------------------------------------------*/
extern unsigned int Error_flag;

/* Function prototypes -------------------------------------------------------*/
void check_Sensor(void);
long Sensor_Get_Threshold(unsigned int sensor_name);
void threshold_INC(unsigned int sensor_name);
void threshold_DEC(unsigned int sensor_name);
unsigned int check_Sensor_threshold(unsigned int sensor_name);

#ifdef	__cplusplus
}
#endif

#endif	/* THRESHOLD_H */

