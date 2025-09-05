#include<LPC17xx.h>
#include<stdint.h>

#define ALL_LED		(0xFF <<19)
#define BUZZ 		(1<<27)

void delay_ms(uint32_t ms);

int main()
{
	LPC_GPIO1->FIODIR |= ALL_LED | BUZZ;
	LPC_GPIO1->FIOCLR |= ALL_LED | BUZZ;	

	LPC_SC->PCONP |= (1<<1);

	LPC_SC->PCLKSEL0 &= ~(0x03<<2);

	LPC_TIM0->PR = 0;
	LPC_TIM0->MR0 = 5000000;		//5 sec

	LPC_TIM0->MCR = (1<<1)| (1<<0);		//notify and repeeat
	LPC_TIM0->TCR = (1<<1);				//Load PC = 0 and TC = 0
	LPC_TIM0->TCR = (1<<0);				//Start timer count

	NVIC_EnableIRQ(TIMER0_IRQn);
	NVIC_ClearPendingIRQ(TIMER0_IRQn);
	NVIC_SetPriority(TIMER0_IRQn,1);

	while(1)
	{
	 	LPC_GPIO1->FIOSET |= ALL_LED;
		delay_ms(1000);
		LPC_GPIO1->FIOCLR |= ALL_LED;
		delay_ms(1000);
	}
}

void TIMER0_IRQHandler(void)
{
 	LPC_TIM0->IR = (1<<0);
	LPC_GPIO1->FIOSET |= BUZZ;
	delay_ms(100);
	LPC_GPIO1->FIOCLR |= BUZZ;
	//delay_ms(10000);
	NVIC_ClearPendingIRQ(TIMER0_IRQn);
}

void delay_ms(uint32_t ms)
{
	uint32_t i,j;
	for(i = 0;i<ms;i++)
		for(j=0;j<1000;j++);
}
