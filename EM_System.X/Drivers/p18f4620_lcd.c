/* Includes ------------------------------------------------------------------*/
#include "p18f4620_lcd.h"

/* Function prototypes -------------------------------------------------------*/
void LCD_Delay(unsigned long time);
void LCD_Char(unsigned char data);
void LCD_String(const rom unsigned char *data);

void LCD_Delay(unsigned long time)
{
  int i = 0;
  int j = 0;
  for(i = 0; i < time; i++)
    for(j = 0; j < 160; j++);
}
void LCD_Char(unsigned char data)
{
  LCD_PORT = (LCD_PORT & 0x0f) | (0xf0 & data); //Send higher nibble of data first to PORT
  RS = 1;                                       //Data Register is selected
  EN = 1;                                       //High-to-low pulse on Enable pin to latch data
  LCD_Delay(1);
  
  EN = 0;
  LCD_Delay(1);
  
  LCD_PORT = (LCD_PORT & 0x0f) | (data << 4);
  EN = 1;                                       //High-to-low pulse on Enable pin to latch data
  LCD_Delay(1);
  
  EN = 0;
  RS = 0;
  LCD_Delay(3);
}
void LCD_String(const rom unsigned char *data)
{
  while((*data) != 0)
  {
    LCD_Char(*data);
    data++;
  }
}
/* Main Function -------------------------------------------------------------*/
void LCD_Command(unsigned char cmd)
{
  LCD_PORT = (LCD_PORT & 0x0f) | (0xf0 & cmd);  //Send higher nibble 
                                                //of command first to PORT Command Register is selected
  RS = 0;                                       //Command Register is selected
  EN = 1;                                       //High-to-low pulse on Enable pin to latch data
  LCD_Delay(1);
  
  EN = 0;
  LCD_Delay(1);
  
  LCD_PORT = (LCD_PORT & 0x0f) | (cmd << 4);    //Send lower nibble of command to PORT
  EN = 1;
  LCD_Delay(1);
  
  EN = 0;
  LCD_Delay(3);
}
void LCD_INIT(void)
{
  LCD_DDR = 0x00;       //PORT as Output Port
  LCD_PORT = 0x00;
  LCD_Delay(25);        //15ms,16x2 LCD Power on delay
  LCD_Command(0x02);    //send for initialization of LCD for nibble (4-bit) mode
  LCD_Command(0x28);    //use 2 line and initialize 5*8 matrix in (4-bit mode)
  LCD_Command(0x01);    //clear display screen
  LCD_Command(0x0c);    //display on cursor off
  LCD_Command(0x06);    //increment cursor (shift cursor to right)
}
void LCD_Print_String_x_y(char row, char pos, unsigned char *data)
{
  char location = 0;
  if(row <= 1)
  {
    location = (0x80) | ((pos) & 0x0f);   //Print message on 1st row and desired location
    LCD_Command(location);
  }
  else
  {
    location = (0xc0) | ((pos) & 0x0f);   //Print message on 2nd row and desired location
    LCD_Command(location);
  }
  LCD_String(data);
}
void LCD_Clear()
{
  LCD_Command(0x01);  //clear display screen
  LCD_Delay(3);
}