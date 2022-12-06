/* Includes ------------------------------------------------------------------*/
#include "p18f4620_lcd.h"
/* Variables -----------------------------------------------------------------*/
unsigned char LCD_buffer[2][16] = {
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
};
int current_row = 1;
int current_col = 0;

/* Function prototypes -------------------------------------------------------*/
void LCD_Delay(unsigned long time);
void LCD_Char(unsigned char data);
void LCD_String(const rom unsigned char *data);
void Add_Buffer(unsigned char data);

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
void Add_Buffer(unsigned char data)
{
  LCD_buffer[current_row][current_col] = data;
  current_col++;
  if(current_col >= 16)
  {
    current_row++;
    current_col = 0;
  }
  if(current_row >= 3)
    current_row = 0;
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
  unsigned int i = 0;
  current_col = 0;
  current_row = 1;
  for(i = 0; i < 32; i++)
    LCD_buffer[i/16][i % 16] = ' ';
  LCD_DDR = 0x00;       //PORT as Output Port
  LCD_PORT = 0x00;
  LCD_Delay(25);        //15ms,16x2 LCD Power on delay
  LCD_Command(0x02);    //send for initialization of LCD for nibble (4-bit) mode
  LCD_Command(0x28);    //use 2 line and initialize 5*8 matrix in (4-bit mode)
  LCD_Command(0x01);    //clear display screen
  LCD_Command(0x0c);    //display on cursor off
  LCD_Command(0x06);    //increment cursor (shift cursor to right)
}
void LCD_Clear()
{
  LCD_Command(0x01);  //clear display screen
  LCD_Delay(3);
}
void LCD_Print_String_x_y(unsigned char row, unsigned char pos, const rom unsigned char *data)
{
  char location = 0;
  if(row == 0)
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
void LCD_Print_Char(unsigned int row, unsigned int col, unsigned char data)
{
  current_row = row % 2;
  current_col = col % 16;
  LCD_buffer[current_row][current_col] = data;
  current_col++;
  if(current_col >= 16)
  {
    current_row++;
    current_col = 0;
  }
  if(current_row >= 3)
    current_row = 0;
}
void LCD_Print_String(unsigned int row, unsigned int col, const rom unsigned char *data)
{
  current_row = row % 2;
  current_col = col % 16;
  while(*data)
  {
    LCD_buffer[current_row][current_col] = *data;
    current_col++;
    if(current_col >= 16)
    {
      current_row++;
      current_col = 0;
    }
    if(current_row >= 2)
      current_row = 0;
    *data++;
  }
}
void LCD_Print_Num(unsigned int row, unsigned int col, long number)
{
  unsigned int i = 0;
  unsigned int diff_zero = 0;
  
  current_row = row % 2;
  current_col = col % 16;
  
  if(number == 0)
    Add_Buffer('0');
  if(number < 0)
  {
    Add_Buffer('-');
    number = number * -1;
  }
  
  for(i = 10000; i > 0; i = i / 10)
  {
    if(number / i != 0)
    {
      Add_Buffer(number / i + '0');
      diff_zero = 1;
    }
    else
    {
      if(diff_zero == 1)
        Add_Buffer('0');
    }
    number = number % i;
  }
}
void LCD_Print_Float(unsigned int row, unsigned int col, long number)
{
  long temp_num = number;
  unsigned int i = 0;
  if(temp_num / 1000 != 0)
  {
    LCD_Print_Num(row, col + i, temp_num / 1000);
    i++;
  }
  temp_num = temp_num % 1000;
  LCD_Print_Num(row, col + i, temp_num / 100);
  i++;
  temp_num = temp_num % 100;
  LCD_Print_Char(row, col + i, '.');
  i++;
  LCD_Print_Num(row, col + i, temp_num / 10);
  i++;
  LCD_Print_Num(row, col + i, temp_num % 10);
  i++;
}
void LCD_Switch_Line(unsigned row_clear)
{
  unsigned char tmp = ' ';
  unsigned int i = 0;
  for(i = 0; i < 16; i++)
  {
    tmp = LCD_buffer[0][i];
    LCD_buffer[0][i] = LCD_buffer[1][i];
    LCD_buffer[1][i] = tmp;
  }
  if(row_clear == 0 || row_clear == 1)
    LCD_Clear_Line(row_clear);
}
void LCD_Clear_Buffer(unsigned int row, unsigned int col)
{
  current_row = row % 2;
  current_col = col % 16;
  LCD_buffer[current_row][current_col] = ' ';
}
void LCD_Clear_Line(unsigned int row)
{
  unsigned int i = 0;
  current_row = row % 2;
  for(i = 0; i < 16; i++)
    LCD_buffer[current_row][i] = ' ';
}
void LCD_Clear_Buffer_All(void)
{
  unsigned int i = 0;
  current_col = 0;
  current_row = 1;
  for(i = 0; i < 32; i++)
    LCD_buffer[i/16][i % 16] = ' ';
}
void LCD_Dislay(void)
{
  unsigned int i = 0;
  LCD_Command(0x80);
  for(i = 0; i < 16; i++)
    LCD_Char(LCD_buffer[0][i]);
  LCD_Command(0xc0);
  for(i = 0; i < 16; i++)
    LCD_Char(LCD_buffer[1][i]);
}