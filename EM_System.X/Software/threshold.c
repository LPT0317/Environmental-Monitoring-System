/* Includes ------------------------------------------------------------------*/
#include "threshold.h"

/* Variables -----------------------------------------------------------------*/
unsigned int Error_flag = 0;
long threshold[7] = {900, 9000, 9000, 4500, 4000, 9000, 32000};

/* Function prototypes -------------------------------------------------------*/
int check_Threshold(void)
{
  int i = 0;
  for(i = 0; i < 7; i++)
  {
    if(Sensor_Get_Value(i) >= threshold[i])
      return 1;
  }
  return 0;
}
void check_Sensor(void)
{
  Error_flag = check_Threshold();
}
long Sensor_Get_Threshold(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0;
  return threshold[sensor_name];
}
void threshold_INC(unsigned int sensor_name)
{
  if(sensor_name >= 0 && sensor_name < 7)
  {
    if((threshold[sensor_name] + 10) <= Sensor_Get_Max(sensor_name))
      threshold[sensor_name] += 10;
  }
}
void threshold_DEC(unsigned int sensor_name)
{
  if(sensor_name >= 0 && sensor_name < 7)
  {
    if((threshold[sensor_name] - 10) >= Sensor_Get_Min(sensor_name))
      threshold[sensor_name] -= 10;
  }
}
unsigned int check_Sensor_threshold(unsigned int sensor_name)
{
  if(sensor_name >= 0 && sensor_name < 7)
  {
    if(Sensor_Get_Value(sensor_name) >= threshold[sensor_name])
      return 1;
    else
      return 0;
  }
}