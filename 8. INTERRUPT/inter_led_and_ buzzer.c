#include<lpc17xx.h>
//#include"lcd_full_prog.c"
#include<stdio.h>
#include<stdint.h>

#include"uart.h"		 

void NVIC_config(void);
void timer0_config(void);

int main()
{
LPC_GPIO1 -> FIODIR |= (1<<19);
uart_init();	//inintialize uart configuration
timer0_config(); //inintialize timer0 configuration
NVIC_config();	 // inintialize NVIC configuration

while(1)
{
LPC_GPIO1 -> FIOSET |= (1<<19);
delay_ms(100);
LPC_GPIO1 -> FIOCLR |= (1<<19);
delay_ms(100);
}
}

void timer0_config(void)
{
LPC_SC -> PCONP |= (1<<1);
LPC_PINCON -> PINSEL0 |= (0X00<<2);

LPC_TIM0 -> PR = 0;	//setting presclar value
LPC_TIM0 -> MR0 = 6000000;	//set the mtch reg f0r 6sec
LPC_TIM0 -> MCR=(1<<0)|(1<<1); //generate interrupt and reset
LPC_TIM0 -> TCR=(1<<1); //reset
LPC_TIM0 -> TCR=(1<<0); //enable
}

void NVIC_config(void)
{
NVIC_ClearPendingIRQ(TIMER0_IRQn);//clear pending interrupts for timer
NVIC_SetPriority(TIMER0_IRQn,1);//set priority
NVIC_EnableIRQ(TIMER0_IRQn);  //Enablr timer0 interrupt
}

void TIMER0_IRQHandler(void)
{
uart_str("Interrupt Occured ");//send a messgae throgh UART
delay_ms(100);
LPC_TIM0 -> IR =(1<<0);// clear the interrupt flag
NVIC_ClearPendingIRQ(TIMER0_IRQn);
}


