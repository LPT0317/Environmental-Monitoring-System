/* Includes ------------------------------------------------------------------*/
#include "menu.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define FIRST_ROW 1
#define MIDLE_ROW 2
#define LAST_ROW 3

/* Variables -----------------------------------------------------------------*/
const rom unsigned char *menu[] = {"SENSOR VALUE",
                              "pH: ",
                              "SS: ",
                              "COD: ",
                              "TEMP: ",
                              "NH4: ",
                              "NO3: ",
                              "FLOW: "};
unsigned int value_index[] = {4, 4, 5, 6, 5, 5, 6};
unsigned int curr_index = 1;
unsigned int menu_status = INIT;
unsigned int SensorName[7] = {pH_Sensor, SS_Sensor, COD_Sensor, TEMP_Sensor,
                               NH4_Sensor, NO3_Sensor, FLOW_Sensor};

/* Function prototypes -------------------------------------------------------*/
void scroll_Up(void)
{
  curr_index--;
}
void scroll_Down(void)
{
  curr_index++;
}
void Display_menu(void)
{
  float value_1 = 0;
  float value_2 = 0;
  if(curr_index != 1)
    value_1 = Sensor_Get_Value(SensorName[0]);
  value_2 = Sensor_Get_Value(SensorName[0]);
  LCD_Clear_Buffer_All();
  LCD_Print_String(0, 0, menu[curr_index - 1]);
  LCD_Print_String(1, 0, menu[curr_index]);
  if(curr_index != 1) 
    LCD_Print_Float(0, value_index[curr_index - 2], value_1);
  LCD_Print_Float(1, value_index[curr_index - 1], value_2);
  LCD_Dislay();
}
void fsm_menu(void)
{
  Display_menu();
  switch(menu_status) {
    case INIT:
      menu_status = FIRST_ROW;
      curr_index = 1;
      break;
    case FIRST_ROW:
      curr_index = 1;
      if(PIC_GPIO_ReadPin(GPIO_PIN_5) == 1)
      {
        scroll_Down();
        menu_status = MIDLE_ROW;
      }
      break;
    case MIDLE_ROW:
      if(PIC_GPIO_ReadPin(GPIO_PIN_2) == 1)
      {
        if(curr_index - 1 == 1){
          menu_status = FIRST_ROW;
        }
        else
        {
          scroll_Up();
        }
      }
      if(PIC_GPIO_ReadPin(GPIO_PIN_5) == 1)
      {
        if(curr_index + 1 == 7){
          menu_status = LAST_ROW;
        }
        else
        {
          scroll_Down();
        }
      }
      break;
    case LAST_ROW:
      curr_index = 7;
      if(PIC_GPIO_ReadPin(GPIO_PIN_2) == 1)
      {
        scroll_Up();
        menu_status = MIDLE_ROW;
      }
      break;
  }
}