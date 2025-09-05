#include <LPC17xx.h>
#include "lcd_fun_1.c"

#define ROWS (0x0F<<4)
#define COLS (0x0F<<0)

void row_scan(void);

int main()
{
lcd_conf();
while(1)
{
row_scan();
}
}

void row_scan(void)
{
int val;

LPC_GPIO2-> FIODIR &= ~ROWS;
LPC_GPIO2-> FIODIR |= COLS;
val = LPC_GPIO2-> FIODIR & ROWS;
val= val>>4;

switch(val)
{
case 0x0E: str_write("Row1");
			delay(100);
			break;
case 0x0D: str_write("Row2");
			delay(100);
			break;
case 0x0B: str_write("Row3");
			delay(100);
			break;
case 0x07: str_write("Row4");
			delay(100);
			break;
}
}

