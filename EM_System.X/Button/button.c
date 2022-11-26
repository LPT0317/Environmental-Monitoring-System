/* Includes ------------------------------------------------------------------*/
#include "button.h"

/* Defines -------------------------------------------------------------------*/
#define PRESSED_STATE 0
#define NORMAL_STATE 1

/* Variables -----------------------------------------------------------------*/
unsigned int BUTTON[NO_BUTTON] = {GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3,
                                  GPIO_PIN_A, GPIO_PIN_4, GPIO_PIN_5,
                                  GPIO_PIN_6, GPIO_PIN_B};
unsigned int KeyReg0[NO_BUTTON] = {NORMAL_STATE};
unsigned int KeyReg1[NO_BUTTON] = {NORMAL_STATE};
unsigned int KeyReg2[NO_BUTTON] = {NORMAL_STATE};
/* Save last state of button */
unsigned int KeyReg3[NO_BUTTON] = {NORMAL_STATE};
/* Set time for debounce */
unsigned int TimeOutForKeyPress[NO_BUTTON] = {200};

unsigned int button_flag[NO_BUTTON] = {0};

/* Function prototypes -------------------------------------------------------*/
void getKeyInput(void)
{
  int i = 0;
  for(i = 0; i < NO_BUTTON; i++) {
    KeyReg2[i] = KeyReg1[i];
    KeyReg1[i] = KeyReg0[i];
    KeyReg0[i] = PIC_GPIO_ReadPin(BUTTON[i]);
    if((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
      if(KeyReg3[i] != KeyReg2[i]) {
    	KeyReg3[i] = KeyReg2[i];
    	if(KeyReg3[i] == PRESSED_STATE) {
    	  TimeOutForKeyPress[i] = 200;
    	  button_flag[i] = 1;
    	}
      }
      else {
        TimeOutForKeyPress[i]--;
        if(TimeOutForKeyPress[i] == 0) {
          if(KeyReg3[i] == PRESSED_STATE) {
            TimeOutForKeyPress[i] = 50;
            button_flag[i] = 1;
          }
        }
      }
    }
  }
}
int is_Button_Pressed(unsigned int button_index)
{
  if(button_index < 0 || button_index >= NO_BUTTON)
    return 0;
  if(button_flag[button_index] == 1) {
    button_flag[button_index] = 0;
    return 1;
  }
  return 0;
}