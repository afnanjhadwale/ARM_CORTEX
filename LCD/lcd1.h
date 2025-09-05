#include<lpc17xx.h>
#include<stdint.h> 

#define LCD_DATA_PINS (0XFF<<15)
#define LCD_RS_PINS(X) (1<<X)
#define LCD_EN_PINS(X) (1<<X)

void lcd_conf(void);
void lcd_cmd_write(char cmd);
void lcd_data_write(char dat);
void str_write(char *str);
void lcd_num(unsigned int num);
void delay(unsigned int a);
