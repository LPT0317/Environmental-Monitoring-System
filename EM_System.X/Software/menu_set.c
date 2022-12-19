/* Includes ------------------------------------------------------------------*/
#include "menu_set.h"
#include "calib.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define IDLE 1
#define NEXT 2
#define PREV 3
#define INC 4
#define DEC 5

/* Variables -----------------------------------------------------------------*/
unsigned int sensor_index = 0;
unsigned int menu_setting_status = INIT;

/* Function prototypes -------------------------------------------------------*/
void next_Sensor(void)
{
  sensor_index++;
}
void prev_Sensor(void)
{
  sensor_index--;
}
void Display_menu_setting(unsigned int type)
{
  long display_value;
  switch (type) {
    case THRESHOLD:
      display_value = Sensor_Get_Threshold(sensor_index);
      break;
    default:
      display_value = get_calib(type, sensor_index);
      break;
  }
  LCD_Clear_Buffer_All();
  LCD_Print_String(0, 0, value_header[type]);
  LCD_Print_String(1, 0, menu[sensor_index]);
  LCD_Print_Float(1, value_index[sensor_index], display_value);
  LCD_Dislay();
}
void fsm_menu_setting(unsigned int type)
{
  Display_menu_setting(type);
  switch(menu_setting_status) {
    case INIT:
      menu_setting_status = IDLE;
      break;
    ///////////////////////////////////////////////////
    case IDLE:
      if(button_Pressed(GPIO_PIN_2) == 1) //next sensor
      {
        menu_setting_status = NEXT;
      }
      if(button_Pressed(GPIO_PIN_1) == 1) //previous sensor
      {
        menu_setting_status = PREV;
      }
      if(button_Pressed(GPIO_PIN_5) == 1) //increase value
      {
        menu_setting_status = INC;
      }
      if(button_Pressed(GPIO_PIN_4) == 1) //decrease value
      {
        menu_setting_status = DEC;
      }
      break;
    ///////////////////////////////////////////////////
    case NEXT:
      sensor_index++;
      if (sensor_index == 7) sensor_index = 0;
      menu_setting_status = IDLE;
      break;
    ///////////////////////////////////////////////////
    case PREV:
      sensor_index--;
      if (sensor_index < 0) sensor_index = 6;
      menu_setting_status = IDLE;
      break;
    ///////////////////////////////////////////////////
    case INC:
        switch (type) {
            case THRESHOLD:
                threshold_INC(sensor_index);
                break;
            default:
                calib_INC(type, sensor_index);
                break;
        }
      menu_setting_status = IDLE;
      break;
    ///////////////////////////////////////////////////
    case DEC:
        switch (type) {
            case THRESHOLD:
                threshold_DEC(sensor_index);
                break;
            default:
                calib_DEC(type, sensor_index);
                break;
        }
      menu_setting_status = IDLE;
      break;
  }
}
