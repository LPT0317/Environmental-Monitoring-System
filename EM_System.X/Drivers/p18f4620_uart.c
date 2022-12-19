/* Includes ------------------------------------------------------------------*/
#include "p18f4620_uart.h"

/* Variables -----------------------------------------------------------------*/
char data_receive = ' ';

/* Function prototypes -------------------------------------------------------*/
void PIC_UART_INIT(void)
{
  SPBRGH = 0;
  SPBRG = 129;
  TXSTAbits.TXEN = 1;     //Transmit enabled
  TXSTAbits.BRGH = 0;     //Low Speed
  BAUDCONbits.BRG16 = 1;  //16-bit Baud Rate Generator

  TXSTAbits.SYNC = 0;     //Asynchronous mode
  RCSTAbits.SPEN = 1;     //Enables
  RCSTAbits.CREN = 1;     //Enables receive

  PIR1bits.RCIF = 0;      // clear interrupt flag uart
  PIE1bits.RCIE = 1;      //enable interrupt uart
  IPR1bits.RCIP = 0;      // Priority: low
  TRISCbits.RC6 = 0;      // RC6 output
  TRISCbits.RC7 = 1;      // RC7 input
}
char PIC_UART_RECEIVE(void)
{
  return data_receive;
}
void PIC_UART_TRANSMIT_CHAR(char data)
{
  while(PIR1bits.TXIF == 0);
  TXREG = data;
  PIR1bits.TXIF = 0;
}
void PIC_UART_TRANSMIT_STRING(const rom char *data)
{
  while(*data)
  {
    PIC_UART_TRANSMIT_CHAR(*data);
    *data++;
  }
}
void PIC_UART_TRANSMIT_NUM(long number)
{
  unsigned int i = 0;
  unsigned int diff_zero = 0;
  
  if(number == 0)
    PIC_UART_TRANSMIT_CHAR('0');
  if(number < 0)
  {
    PIC_UART_TRANSMIT_CHAR('-');
    number = number * -1;
  }
  
  for(i = 10000; i > 0; i = i / 10)
  {
    if(number / i != 0)
    {
      PIC_UART_TRANSMIT_CHAR(number / i + '0');
      diff_zero = 1;
    }
    else
    {
      if(diff_zero == 1)
        PIC_UART_TRANSMIT_CHAR('0');
    }
    number = number % i;
  }
}
void PIC_UART_TRANSMIT_FLOAT(long number)
{
  long temp_num = number;
  if(temp_num / 1000 != 0)
    PIC_UART_TRANSMIT_NUM(temp_num / 1000);
  temp_num = temp_num % 1000;
  PIC_UART_TRANSMIT_NUM(temp_num / 100);
  temp_num = temp_num % 100;
  PIC_UART_TRANSMIT_CHAR('.');
  PIC_UART_TRANSMIT_NUM(temp_num / 10);
  PIC_UART_TRANSMIT_NUM(temp_num % 10);
}
void PIC_UART_ISR(void)
{
  //data_receive = RCREG;
  //TXREG = data_receive;
  uart_communication();
}
