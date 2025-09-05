#include <LPC17xx.h>
#include "lcd_fun_1.c"

#define ROWS (0x0F<<4)
#define COLS (0x0F<<0)

void row_scan(void);
void col_scan1(void);
void col_scan2(void);
void col_scan3(void);
void col_scan4(void);

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
LPC_GPIO2-> FIODIR |= COLS;
LPC_GPIO2-> FIODIR &= ~ROWS;

val = LPC_GPIO2-> FIODIR & ROWS;
val= val>>4;

switch(val)
{
case 0x0E: col_scan1();
			delay(100);
			break;
case 0x0D: col_scan2();
			delay(100);
			break;
case 0x0B: col_scan3();
			delay(100);
			break;
case 0x07: col_scan4();
			delay(100);
			break;
}
}
void col_scan1(void)
{
int val;

LPC_GPIO2-> FIODIR |= ROWS;
LPC_GPIO2-> FIODIR &= ~COLS;
val = LPC_GPIO2-> FIODIR & COLS;
val= val>>0;

switch(val)
{
case 0x0E: str_write("0");
			delay(100);
			break;
case 0x0D: str_write("1");
			delay(100);
			break;
case 0x0B: str_write("2");
			delay(100);
			break;
case 0x07: str_write("3");
			delay(100);
			break;
}
}

void col_scan2(void)
{
int val;

LPC_GPIO2-> FIODIR |= ROWS;
LPC_GPIO2-> FIODIR &= ~COLS;
val = LPC_GPIO2-> FIODIR & COLS;
val= val>>0;

switch(val)
{
case 0x0E: str_write("4");
			delay(100);
			break;
case 0x0D: str_write("5");
			delay(100);
			break;
case 0x0B: str_write("6");
			delay(100);
			break;
case 0x07: str_write("7");
			delay(100);
			break;
}
}

void col_scan3(void)
{
int val;

LPC_GPIO2-> FIODIR |= ROWS;
LPC_GPIO2-> FIODIR &= ~COLS;
val = LPC_GPIO2-> FIODIR & COLS;
val= val>>0;

switch(val)
{
case 0x0E: str_write("8");
			delay(100);
			break;
case 0x0D: str_write("9");
			delay(100);
			break;
case 0x0B: str_write("A");
			delay(100);
			break;
case 0x07: str_write("B");
			delay(100);
			break;
}
}

void col_scan4(void)
{
int val;

LPC_GPIO2-> FIODIR |= ROWS;
LPC_GPIO2-> FIODIR &= ~COLS;
val = LPC_GPIO2-> FIODIR & COLS;
val= val>>0;

switch(val)
{
case 0x0E: str_write("C");
			delay(100);
			break;
case 0x0D: str_write("D");
			delay(100);
			break;
case 0x0B: str_write("E");
			delay(100);
			break;
case 0x07: str_write("F");
			delay(100);
			break;
}
}


