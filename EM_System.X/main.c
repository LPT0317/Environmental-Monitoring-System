/* 
 * File:   main.c
 * Author: lephu
 *
 * Created on November 22, 2022, 6:31 PM
 */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "Drivers/p18f4620_tim.h"
#include "Drivers/p18f4620_interrupt.h"
#include "Drivers/p18f4620_gpio.h"
#include "Drivers/p18f4620_lcd.h"
#include "Drivers/p18f4620_uart.h"
#include "Drivers/p18f4620_adc.h"
#include "Drivers/p18f4620_pwm.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Software/timer_software.h"
#include "Software/menu.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void MX_TIM3_INIT(void);
static void MX_GPIO_INIT(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/

/* MCU Configuration--------------------------------------------------------*/


void main(void)
{
  /* USER CODE BEGIN SysInit */
  
  /* USER CODE END SysInit */
  
  /* USER CODE BEGIN Init */
  
  /* USER CODE END Init */
  
  /* Initialize all configured peripherals */
  MX_TIM3_INIT();
  MX_GPIO_INIT();
  
  /* USER CODE BEGIN 2 */
  
  /* USER CODE END 2 */
  /* Infinite loop */
  while(1)
  {
    fsm_menu();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_INIT(void)
{
  PIC_BUTTON_INIT();
  LCD_INIT();
  PIC_UART_INIT();
  PIC_ADC_INIT();
  //PIC_PWM_INIT();
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_INIT(void)
{
  PIC_TIM3 = 10;    //10ms
  
  PIC_INTERRUPT_INIT();
  PIC_TIM3_INIT();
}

void TIM3_CALLBACK(void)
{
  timer_Run();
  PIC_SCAN_BUTTON();
}
/*****************************END OF FILE**************************************/
