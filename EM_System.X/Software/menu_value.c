/* Includes ------------------------------------------------------------------*/
#include "menu_value.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define FIRST_ROW 1
#define MIDLE_ROW 2
#define LAST_ROW 3

/* Variables -----------------------------------------------------------------*/
unsigned int value_curr_index = 1;
unsigned int menu_value_status = INIT; 

/* Function prototypes -------------------------------------------------------*/
void value_scroll_Up(void)
{
  value_curr_index--;
}
void value_scroll_Down(void)
{
  value_curr_index++;
}
void Display_menu_value(void)
{
  long value_1 = 0;
  long value_2 = 0;
  LCD_Clear_Buffer_All();
  if(value_curr_index == 1)
  {
    value_2 = Sensor_Get_Value(SensorName[value_curr_index - 1]);
    LCD_Print_String(0, 0, value_header[0]);
    LCD_Print_String(1, 0, menu[value_curr_index - 1]);
    LCD_Print_Float(1, value_index[value_curr_index - 1], value_2);
  }
  else
  {
    value_1 = Sensor_Get_Value(SensorName[value_curr_index - 2]);
    value_2 = Sensor_Get_Value(SensorName[value_curr_index - 1]);
    LCD_Print_String(0, 0, menu[value_curr_index - 2]);
    LCD_Print_String(1, 0, menu[value_curr_index - 1]);
    LCD_Print_Float(0, value_index[value_curr_index - 2], value_1);
    LCD_Print_Float(1, value_index[value_curr_index - 1], value_2);
  }
  LCD_Dislay();
}
void fsm_menu_value(void)
{
  Display_menu_value();
  switch(menu_value_status) {
    case INIT:
      menu_value_status = FIRST_ROW;
      value_curr_index = 1;
      break;
    case FIRST_ROW:
      value_curr_index = 1;
      if(button_Pressed(GPIO_PIN_5) == 1)
      {
        value_scroll_Down();
        menu_value_status = MIDLE_ROW;
      }
      break;
    case MIDLE_ROW:
      if(button_Pressed(GPIO_PIN_2) == 1)
      {
        if(value_curr_index - 1 == 1){
          menu_value_status = FIRST_ROW;
        }
        else
        {
          value_scroll_Up();
        }
      }
      if(button_Pressed(GPIO_PIN_5) == 1)
      {
        if(value_curr_index + 1 == 7){
          menu_value_status = LAST_ROW;
        }
        else
        {
          value_scroll_Down();
        }
      }
      break;
    case LAST_ROW:
      value_curr_index = 7;
      if(button_Pressed(GPIO_PIN_2) == 1)
      {
        value_scroll_Up();
        menu_value_status = MIDLE_ROW;
      }
      break;
  }
}