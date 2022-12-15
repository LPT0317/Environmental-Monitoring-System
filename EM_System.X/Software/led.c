/* Includes ------------------------------------------------------------------*/
#include "led.h"
#include "p18f4620_led.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define LED_OFF 1
#define BLINK_RED 2

/* Variables -----------------------------------------------------------------*/
unsigned int led_state = INIT;
unsigned int led_time = 500;

/* Function prototypes -------------------------------------------------------*/
void led_blink(void)
{
  switch(led_state)
  {
    case INIT:
      led_off();
      led_state = BLINK_RED;
      set_Timer(LED_TIMER, led_time);
      break;
    case LED_OFF:
      led_off();
      if(is_Timer_Out(LED_TIMER) == 1)
      {
        led_state = BLINK_RED;
        set_Timer(LED_TIMER, led_time);
      }
      break;
    case BLINK_RED:
      PIC_LED_ON(RED);
      if(is_Timer_Out(LED_TIMER) == 1)
      {
        led_state = LED_OFF;
        set_Timer(LED_TIMER, led_time);
      }
      break;
  }
}
void led_off(void)
{
  PIC_LED_OFF();
}