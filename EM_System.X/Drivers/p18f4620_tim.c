/* Includes ------------------------------------------------------------------*/
#include "p18f4620_tim.h"

/* Variables -----------------------------------------------------------------*/
unsigned int PIC_TIM0 = 0;
unsigned int PIC_TIM1 = 0;
unsigned int PIC_TIM3 = 0;

unsigned int TIM0 = 0;
unsigned int TIM1 = 0;
unsigned int TIM3 = 0;

/* Function prototypes -------------------------------------------------------*/
//Timer 0
void PIC_TIM0_INIT(void)
{
  T0CONbits.TMR0ON = 0;			// turn off timer0
  T0CONbits.T08BIT = 0;			// set mode 16bit timer0
  TIM0 = PIC_TIM0 * COUNT;
  TMR0L = (65535 - PIC_TIM0) % 256;     // count PIC_TIM0 times
  TMR0H = (65535 - PIC_TIM0) / 256;
  T0CONbits.T0CS = 0;                   // select internal clock include crystal
  T0CONbits.PSA = 1;			// no prescaler
  INTCONbits.T0IE = 1;			// enable timer0 interrupt
  INTCONbits.T0IF = 0;			// clear interrupt timer0 flag
  INTCON2bits.TMR0IP = 1;	        // timer0 interrupt high priority 	
  T0CONbits.TMR0ON = 1;                 // start timer 0
}
void PIC_TIM0_START(void)
{
  TMR0L = (65535 - TIM0) % 256;
  TMR0H = (65535 - TIM0) / 256;
  T0CONbits.TMR0ON = 1;
}
void PIC_TIM0_STOP(void)
{
  T0CONbits.TMR0ON = 0;
}
void TIM0_CALLBACK(void)
{
  
}

//Timer 1
void PIC_TIM1_INIT(void)
{
  T1CONbits.TMR1ON = 0;			// turn off timer 1
  TIM1 = PIC_TIM1 * COUNT;
  TMR1H = (65535- TIM1) / 256;	
  TMR1L = (65535- TIM1) % 256;	
  PIE1bits.TMR1IE = 1;			// enable timer1 interrupt
  PIR1bits.TMR1IF = 0;			// clear timer1 interrupt flag
  IPR1bits.TMR1IP = 0;			// timer1 interrupt low priority 	
  //T1CON
  T1CONbits.RD16 = 1;			// select timer1 16 bits mode
  T1CONbits.T1RUN = 1;			 
  T1CONbits.T1CKPS0 = 0;		
  T1CONbits.T1CKPS1 = 0;		// prescaler 1:1
  T1CONbits.T1OSCEN = 0;  		// oscillator invert and feedback for 
                                        // external oscillator
  //T1CONbits.T1SYNC = 0;		// this bit ignore when TMR1CS = 0
  T1CONbits.TMR1CS = 0;			// select internal clock source
  T1CONbits.TMR1ON = 1;
}
void PIC_TIM1_START(void)
{
  TMR1H = (65535 - TIM1) / 256;
  TMR1L = (65535 - TIM1) % 256;
  T1CONbits.TMR1ON = 1;
}
void PIC_TIM1_STOP(void)
{
  T1CONbits.TMR1ON = 0;
}
void TIM1_CALLBACK(void)
{
  
}

//Timer 3
void PIC_TIM3_INIT(void)
{
  T3CONbits.TMR3ON = 0;			// turn off timer 3
  TIM3 = PIC_TIM3 * COUNT;
  TMR3H = (65535 - TIM3) / 256;	// count timer3_value times
  TMR3L = (65535 - TIM3) % 256;	
  PIE2bits.TMR3IE = 1;			// enable timer3 interrupt
  PIR2bits.TMR3IF = 0;			// clear timer3 interrupt flag

  IPR2bits.TMR3IP = 0;			// timer3 interrupt low priority 	

  //T1CON
  T3CONbits.RD16 = 1;			// select timer3 16 bits mode
  T3CONbits.T3CKPS0 = 0;		
  T3CONbits.T3CKPS1 = 0;		// prescaler 1:1
  //T3CONbits.T3SYNC = 0;		// this bit ignore when TMR3CS = 0
  T3CONbits.TMR3CS = 0;			// select internal clock source
  T3CONbits.TMR3ON = 1;
}
void PIC_TIM3_START(void)
{
  TMR3L = (65535 - TIM3) % 256;
  TMR3H = (65535 - TIM3) / 256;
  T3CONbits.TMR3ON = 1;
}
void PIC_TIM3_STOP(void)
{
  T3CONbits.TMR3ON = 0;
}