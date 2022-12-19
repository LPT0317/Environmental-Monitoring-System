/* Includes ------------------------------------------------------------------*/
#include "calib.h"
#include "menu_set.h"

/*----------
 Index
 * 0: pH
 * 1: SS
 * 2: COD
 * 3: TEMP
 * 4: NH4
 * 5: NO3
 * 6: FLOW
 -----------*/

unsigned int Sensor_Max[7] = {1000, 10000, 10000, 5000, 5000, 10000, 36000};
unsigned int Sensor_Min[7] = {400, 0, 0, 2500, 1000, 2000, 0};

long get_calib(unsigned int type, unsigned int sensor_name) {
    if(sensor_name < 0 || sensor_name >= 7)
      return -1;
    if (type == CALIB_MAX) return Sensor_Max[sensor_name];
    return Sensor_Min[sensor_name];
}

void calib_INC(unsigned int type, unsigned int sensor_name) {    
    if(sensor_name < 0 || sensor_name >= 7)
      return;
    if (type == CALIB_MAX) {
        Sensor_Max[sensor_name]++;
        if (Sensor_Max[sensor_name] > MAX_CALIB_VAL) {
            Sensor_Max[sensor_name] = Sensor_Min[sensor_name] + 1;
        }
    }
    else {
        Sensor_Min[sensor_name]++;
        if (Sensor_Min[sensor_name] == Sensor_Max[sensor_name]) {
            Sensor_Min[sensor_name] = MIN_CALIB_VAL;
        }
    }
}

void calib_DEC(unsigned int type, unsigned int sensor_name) {
    if(sensor_name < 0 || sensor_name >= 7)
      return;
    
    if (type == CALIB_MAX) {
        Sensor_Max[sensor_name]--;
        if (Sensor_Max[sensor_name] == MIN_CALIB_VAL) {
            Sensor_Max[sensor_name] = MAX_CALIB_VAL;
        }
    }
    else {
        Sensor_Min[sensor_name]--;
        if (Sensor_Min[sensor_name] < MIN_CALIB_VAL) {
            Sensor_Min[sensor_name] = Sensor_Max[sensor_name]-1;
        }
    }
}