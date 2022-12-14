/* Includes ------------------------------------------------------------------*/
#include "main_menu.h"
#include "menu_set.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define MENU_VALUE 1
#define MENU_SETTING 2
#define MENU_ALERT 3

/* Variables -----------------------------------------------------------------*/
unsigned int main_menu_state = INIT;

/* Function prototypes -------------------------------------------------------*/
void fsm_main_menu(void)
{
  switch(main_menu_state)
  {
    case INIT:
      main_menu_state = MENU_VALUE;
      break;
    case MENU_VALUE:
      fsm_menu_value();
      if(PIC_GPIO_ReadPin(GPIO_PIN_B) == 1)
        main_menu_state = MENU_SETTING;
      break;
    case MENU_SETTING:
      fsm_menu_setting();
      if(PIC_GPIO_ReadPin(GPIO_PIN_B) == 1)
        main_menu_state = MENU_VALUE;
      break;
  }
}