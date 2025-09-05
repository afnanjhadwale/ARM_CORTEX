#include<lpc17xx.h>
//#define
void delay(unsigned int a);

int main(void)
{
int y=19;
LPC_GPIO1 -> FIODIR |= (0XFF<<y);
while(1)
{
  LPC_GPIO1 -> FIOSET |= (0X55<<y);
  delay(1000);
 // LPC_GPIO1 -> FIOCLR |= (x<<y);
 // 
  LPC_GPIO1 -> FIOCLR |= (0XFF<<y);
  delay(1000);
  LPC_GPIO1 -> FIOSET |= (0xAA<<y);
  delay(1000);
   LPC_GPIO1 -> FIOCLR |= (0XFF<<y);
  delay(1000);
}
}
void delay(unsigned int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<6000;j++);
}
