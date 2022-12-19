/* Includes ------------------------------------------------------------------*/
#include "main_menu.h"
#include "menu_set.h"
#include "p18f4620_led.h"
#include "button.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define MENU_VALUE      1
#define MENU_CALIB_MAX  2
#define MENU_CALIB_MIN  3
#define MENU_THRESHOLD  4
#define MENU_ALERT      5

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
    /*----------------------------------*/
    case MENU_VALUE:
      buzzer_off();
      PIC_LED_ON(GREEN);
      fsm_menu_value();
      if(button_Pressed(GPIO_PIN_B) == 1)
        main_menu_state = MENU_CALIB_MAX;
      if(Error_flag == 1)
        main_menu_state = MENU_ALERT;
      break;
    /*----------------------------------*/
    case MENU_CALIB_MAX:
        buzzer_off();
        PIC_LED_ON(BLUE); 
        fsm_menu_setting(CALIB_MAX);
        if(button_Pressed(GPIO_PIN_B) == 1)
            main_menu_state = MENU_CALIB_MIN;
        break;
    /*----------------------------------*/
    case MENU_CALIB_MIN:
        buzzer_off();
        PIC_LED_ON(BLUE);
        fsm_menu_setting(CALIB_MIN);
        if(button_Pressed(GPIO_PIN_B) == 1) 
            main_menu_state = MENU_THRESHOLD;
        break;
    /*----------------------------------*/
    case MENU_THRESHOLD:
      buzzer_off();
      PIC_LED_ON(BLUE);
      fsm_menu_setting(THRESHOLD);
      if(button_Pressed(GPIO_PIN_B) == 1) {
        main_menu_state = MENU_VALUE;        
        menu_value_reset();
      }
      break;
    /*----------------------------------*/
    case MENU_ALERT:
      led_blink();
      if (is_alarming()) buzzer_blink();
      else buzzer_off();
      fsm_menu_alert();
      if(Error_flag == 0) {
        main_menu_state = MENU_VALUE;
        menu_value_reset();
      }
    /*----------------------------------*/
  }
}
int check_Setting(void)
{
  if(main_menu_state == MENU_VALUE)
    return 0;
  return 1;
}