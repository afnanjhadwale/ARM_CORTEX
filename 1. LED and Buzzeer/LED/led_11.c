// increasig and decreasing the leds

#include<lpc17xx.h>
//#define 
void delay(unsigned int a);

int main(void)
{
 int x;
 while(1)
 {
  for(x=19;x<27;x++)
  {
	LPC_GPIO1 -> FIODIR |= (1<<x);

	{
  		LPC_GPIO1 -> FIOSET |= (1<<x);
 		delay(1000); 
 		LPC_GPIO1 -> FIOCLR |= (1<<x);  
  		delay(1000);
	}
  }
 }
}
void delay(unsigned int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<6000;j++);
}
