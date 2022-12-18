/* 
 * File:   calib.h
 * Author: Guest_demo
 *
 * Created on Ngày 18 tháng 12 n?m 2022, 15:10
 */

#ifndef CALIB_H
#define	CALIB_H

#ifdef	__cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Software/sensor.h"
    
/* Define max and min general calibration */
#define MAX_CALIB_VAL   10000
#define MIN_CALIB_VAL   0
  
/* Function prototypes -------------------------------------------------------*/
long get_calib(unsigned int type, unsigned int sensor_name);
void calib_INC(unsigned int type, unsigned int sensor_name);
void calib_DEC(unsigned int type, unsigned int sensor_name);

#ifdef	__cplusplus
}
#endif

#endif	/* CALIB_H */

