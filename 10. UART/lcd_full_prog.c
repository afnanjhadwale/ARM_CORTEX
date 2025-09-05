#include<lpc17xx.h>
#include<stdint.h> 
#include"lcd1.h"




void lcd_conf(void)
{
	LPC_GPIO0-> FIODIR |= LCD_DATA_PINS;
	LPC_GPIO0-> FIODIR |= LCD_RS_PINS(10);
	LPC_GPIO0-> FIODIR |= LCD_EN_PINS(11);
	lcd_cmd_write(0X38);
	lcd_cmd_write(0X0E);
	lcd_cmd_write(0X01);
	lcd_cmd_write(0X80);
}

void lcd_cmd_write(char cmd)
{
	LPC_GPIO0-> FIOCLR |= LCD_DATA_PINS;
	LPC_GPIO0-> FIOSET |= cmd<< 15;
	LPC_GPIO0-> FIOCLR |= LCD_RS_PINS(10);

	LPC_GPIO0-> FIOSET |= LCD_EN_PINS(11);
	delay(100);
	LPC_GPIO0-> FIOCLR |= LCD_EN_PINS(11);
}

void lcd_data_write(char dat)
{
	LPC_GPIO0-> FIOCLR |= LCD_DATA_PINS;
	LPC_GPIO0-> FIOSET |= dat<< 15;
	LPC_GPIO0-> FIOSET |= LCD_RS_PINS(10);

	LPC_GPIO0-> FIOSET |= LCD_EN_PINS(11);
	delay(100);
	LPC_GPIO0-> FIOCLR |= LCD_EN_PINS(11);
}


void str_write(char *str)
{
	while(*str != '\0')
	{
	 lcd_data_write(*str);
	 str++;

	}
	return;
}

void lcd_num(unsigned int num)
{
	  if(num)
	  {
	   lcd_num(num/10);
	   	lcd_data_write(num%10+0x30);
	  }
} 

void delay(unsigned int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<1000;j++);
}
