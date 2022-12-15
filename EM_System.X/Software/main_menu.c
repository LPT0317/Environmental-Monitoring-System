/* Includes ------------------------------------------------------------------*/
#include "main_menu.h"
#include "menu_set.h"
#include "p18f4620_led.h"

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
      buzzer_off();
      PIC_LED_ON(GREEN);
      fsm_menu_value();
      if(PIC_GPIO_ReadPin(GPIO_PIN_B) == 1)
        main_menu_state = MENU_SETTING;
      if(Error_flag == 1)
        main_menu_state = MENU_ALERT;
      break;
    case MENU_SETTING:
      buzzer_off();
      PIC_LED_ON(BLUE);
      fsm_menu_setting();
      if(PIC_GPIO_ReadPin(GPIO_PIN_B) == 1)
        main_menu_state = MENU_VALUE;
      break;
    case MENU_ALERT:
      led_blink();
      buzzer_blink();
      fsm_menu_alert();
      if(Error_flag == 0)
        main_menu_state = MENU_VALUE;
  }
}