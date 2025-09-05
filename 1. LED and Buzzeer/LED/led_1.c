#include<lpc17xx.h>
#include<stdint.h>

#define p LPC_GPIO1
#define LED (1<<19)

void delay(uint32_t a)
{
 	uint32_t i,j;
	for(i=0;i<1000;i++)
	{
		for(j =0;j<a;j++)	 ;
	}
}
int main()
{
	p->FIODIR |= LED;

	while(1)
	{
		p->FIOSET |= LED;
		delay(100);
		}
}

	







