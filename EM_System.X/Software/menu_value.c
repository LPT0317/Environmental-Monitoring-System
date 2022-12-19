/* Includes ------------------------------------------------------------------*/
#include "menu_value.h"
#include "timer_software.h"

/* Defines -------------------------------------------------------------------*/
#define INIT        0
#define DISPLAY     1
#define DOWN 2
#define UP   3

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
        menu_value_status = DISPLAY;
        value_curr_index = 1;
        set_Timer(MENU_TIMER, 3000);
        break;
    case DISPLAY:
        Display_menu_value();
        if(button_Pressed(GPIO_PIN_5) == 1 || is_Timer_Out(MENU_TIMER)) 
        {
            menu_value_status = DOWN;
            clear_Timer(MENU_TIMER);
            set_Timer(MENU_TIMER, 3000);            
        }
        else if (button_Pressed(GPIO_PIN_2) == 1) {
            menu_value_status = UP;
            clear_Timer(MENU_TIMER);
            set_Timer(MENU_TIMER, 3000);      
        }
        break;
    case DOWN:
        value_scroll_Down();
        menu_value_status = DISPLAY;
        break;
    case UP:
        value_scroll_Up();
        menu_value_status = DISPLAY;
        break;
  }
}