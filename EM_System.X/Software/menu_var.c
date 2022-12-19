/* Includes ------------------------------------------------------------------*/
#include "menu_var.h"

/* Variables -----------------------------------------------------------------*/
rom unsigned char *menu[] = { "pH: ",
                              "SS: ",
                              "COD: ",
                              "TEMP: ",
                              "NH4: ",
                              "NO3: ",
                              "FLOW: "};
unsigned int value_index[] = {4, 4, 5, 6, 5, 5, 6};
unsigned int SensorName[7] = {pH_Sensor, SS_Sensor, COD_Sensor, TEMP_Sensor,
                               NH4_Sensor, NO3_Sensor, FLOW_Sensor};
rom unsigned char *value_header[] = {"SENSOR VALUE",
                                     "CALIB - MAX",
                                     "CALIB - MIN",
                                     "SENSOR SETTING",
                                     "SENSOR ALERT"};
rom unsigned char *sensor_list[7] = {"pH", "SS", "COD", "TEMP",
                                     "NH4", "NO3", "FLOW"};