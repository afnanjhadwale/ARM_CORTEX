//external interrupt

#include<lpc17xx.h>

#define ALL_LED (0xFF << 19)
#define BUZ (0x01 << 27)

void delay(uint32_t ms);

int main()
{
	LPC_GPIO1->FIODIR |= ALL_LED;
	LPC_GPIO1->FIOCLR |= ALL_LED;

	LPC_GPIO1->FIODIR |= BUZ;
	LPC_GPIO1->FIOCLR |= BUZ;



	LPC_PINCON->PINSEL4 |=(1 << 22);
	LPC_PINCON->PINSEL4 &= ~(1 << 23);

	LPC_SC->EXTINT |= (1 << 1);		 //clear EINT1 interrupt
	LPC_SC->EXTMODE |= (1 << 1);	 //edge sensitive
	LPC_SC->EXTPOLAR |= (1 << 1);	 //rising edge sensitive




	NVIC_EnableIRQ(EINT1_IRQn);
	NVIC_ClearPendingIRQ(EINT1_IRQn);
	NVIC_SetPriority(EINT1_IRQn,1); //we can give any priority num if it is only one priority


	while(1)
	{
		LPC_GPIO1->FIOSET |= ALL_LED;	
		delay(1000);
		LPC_GPIO1->FIOCLR |= ALL_LED;
		delay(1000);	
	}

}

void EINT1_IRQHandler(void)
{
	LPC_SC->EXTINT |= (1 << 1);
	LPC_GPIO1->FIOSET = BUZ;
	delay(200);
	LPC_GPIO1->FIOCLR = BUZ;
	NVIC_ClearPendingIRQ(EINT1_IRQn);

}

void delay(uint32_t ms)
{
	uint32_t i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<1000;j++);
}
