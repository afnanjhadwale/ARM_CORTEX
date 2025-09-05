#include<lpc17xx.h>
#include"lcd_full_prog.c"
#include"lcd1.h"
#include<stdio.h>
#include<stdint.h>

#define RTC_PWR (1<<9)
//#define BUZ(1<<27)

int main()
{
char stime[20];
char sdate[20];

LPC_SC -> PCONP |= RTC_PWR; //power on RTC

LPC_RTC -> CIIR = 0; //disable all counter increament interrupts
LPC_RTC -> CCR = 1 ; //clock enable

LPC_RTC -> YEAR = 2025;
LPC_RTC -> MONTH = 9;
LPC_RTC -> DOM = 1;
LPC_RTC -> HOUR = 10;
LPC_RTC -> MIN = 25;
LPC_RTC -> SEC = 12;

lcd_conf();

while(1)
{
uint8_t current_sec = LPC_RTC -> SEC;
sprintf(sdate,"DATE:%02d-%02d-%04d",LPC_RTC -> DOM,LPC_RTC -> MONTH,LPC_RTC -> YEAR);
sprintf(stime,"TIME:%02d-%02d-%02d",LPC_RTC -> HOUR,LPC_RTC -> MIN,LPC_RTC -> SEC);

str_write(sdate);
lcd_cmd_write(0xC0);
lcd_str_write(stime);
lcd_cmd_write(0x80);

}
}