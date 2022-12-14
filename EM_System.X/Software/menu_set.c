/* Includes ------------------------------------------------------------------*/
#include "menu_set.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define IDLE 1
#define NEXT 2
#define PREV 3
#define INC 4
#define DEC 5

/* Variables -----------------------------------------------------------------*/
unsigned int setting_sensor_index = 0;
unsigned int menu_setting_status = INIT;

/* Function prototypes -------------------------------------------------------*/
void next_Sensor(void)
{
  setting_sensor_index++;
}
void prev_Sensor(void)
{
  setting_sensor_index--;
}
void Display_menu_setting(void)
{
  long threshold_value = Sensor_Get_Threshold(setting_sensor_index);
  LCD_Clear_Buffer_All();
  LCD_Print_String(0, 0, value_header[1]);
  LCD_Print_String(1, 0, menu[setting_sensor_index]);
  LCD_Print_Float(1, value_index[setting_sensor_index], threshold_value);
  LCD_Dislay();
}
void fsm_menu_setting(void)
{
  Display_menu_setting();
  switch(menu_setting_status) {
    case INIT:
      menu_setting_status = IDLE;
      break;
    case IDLE:
      if(PIC_GPIO_ReadPin(GPIO_PIN_2) == 1)
      {
        if(setting_sensor_index < 6)
          menu_setting_status = NEXT;
      }
      if(PIC_GPIO_ReadPin(GPIO_PIN_1) == 1)
      {
        if(setting_sensor_index > 0)
          menu_setting_status = PREV;
      }
      if(PIC_GPIO_ReadPin(GPIO_PIN_5) == 1)
      {
        menu_setting_status = INC;
      }
      if(PIC_GPIO_ReadPin(GPIO_PIN_4) == 1)
      {
        menu_setting_status = DEC;
      }
      break;
    case NEXT:
      setting_sensor_index++;
      menu_setting_status = IDLE;
      break;
    case PREV:
      setting_sensor_index--;
      menu_setting_status = IDLE;
      break;
    case INC:
      threshold_INC(setting_sensor_index);
      menu_setting_status = IDLE;
      break;
    case DEC:
      threshold_DEC(setting_sensor_index);
      menu_setting_status = IDLE;
      break;
  }
}
