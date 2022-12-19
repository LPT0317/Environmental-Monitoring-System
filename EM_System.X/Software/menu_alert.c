/* Includes ------------------------------------------------------------------*/
#include "menu_alert.h"
#include "timer_software.h"
#include "button.h"

/* Defines -------------------------------------------------------------------*/
#define INIT            0
#define ALERT_TITLE     1
#define ALERT_SENSOR    2

/* Variables -----------------------------------------------------------------*/
unsigned int menu_alert_status = INIT;
rom unsigned char *threshold_warning = "Over threshold!!";
unsigned int sensor_list_index[7] = {2, 2, 3, 4, 3, 3, 4};
unsigned int buzzer_on = 1;

/* Function prototypes -------------------------------------------------------*/
void Display_menu_alert(void)
{
  unsigned int i = 0;
  unsigned int index_col = 0;
  unsigned int index_row = 0;
  LCD_Clear_Buffer_All();
  if(menu_alert_status == ALERT_TITLE)
  {
    LCD_Print_String(0, 0, value_header[2]);
    LCD_Print_String(1, 0, threshold_warning);
  }    
  else {
    for(i = 0; i < 7; i++)
    {
      if(check_Sensor_threshold(i) == 1)
      {
        if(index_col != 0 && index_col + 1 < 16)
        {
          LCD_Print_Char(index_row, index_col, ',');
          index_col++;
          if(index_col >= 16)
          {
            index_row = 1;
            index_col = 0;
          }
        }
        if(index_col + sensor_list_index[i] >= 16)
        {
          index_row = 1;
          index_col = 0;
        }
        LCD_Print_String(index_row, index_col, sensor_list[i]);
        index_col = index_col + sensor_list_index[i];
        if(index_col >= 16)
        {
          index_row = 1;
          index_col = 0;
        }
      }
    }
  }
  LCD_Dislay();
}
void fsm_menu_alert(void)
{
  Display_menu_alert();
  switch(menu_alert_status)
  {
    case INIT:
      menu_alert_status = ALERT_TITLE;
      set_Timer(ALERT_TIMER, 1000);
      buzzer_on = 1;
      break;
    case ALERT_TITLE:
      if (button_Pressed(GPIO_PIN_5)) buzzer_on = 0;
      if(is_Timer_Out(ALERT_TIMER) == 1)
      {
        set_Timer(ALERT_TIMER, 5000);
        menu_alert_status = ALERT_SENSOR;
      }
      break;
    case ALERT_SENSOR:
      if (button_Pressed(GPIO_PIN_5)) buzzer_on = 0;
      if(is_Timer_Out(ALERT_TIMER) == 1)
      {
        set_Timer(ALERT_TIMER, 1000);
        menu_alert_status = ALERT_TITLE;
      }
      break;
  }
}

unsigned int is_alarming() {
    return buzzer_on;
}