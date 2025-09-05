#include<lpc17xx.h>
#include"lcd_full_prog.c"
#include<stdio.h>

#define LED_PIN(x) (1<<x)
//#define ADC_POWER_EN() (1<<1) // power enable for ADC

void T0_MR_delay(unsigned int);

int main()
{
LPC_GPIO1 -> FIODIR |= LED_PIN(19);
LPC_GPIO1 -> FIODIR |= LED_PIN(20);

T0_MR_delay(5000000);
while(1)
{
if(LPC_TIM0 -> IR &(1<<0))//MR0
{
LPC_GPIO1 -> FIOPIN ^= LED_PIN(19); //TOGGLE OF LED
LPC_GPIO1 -> FIOPIN ^= LED_PIN(20);
LPC_TIM0 -> IR =(1<<0);
}
}
}
void T0_MR_delay(unsigned int us)
{ 
LPC_PINCON -> PINSEL0 |= (0X00<<2);	//timer power contol enable
LPC_SC -> PCONP |= (1<<1); //TIMER 0
LPC_TIM0 -> MR0 = 5000000;	//load count value to MR0(for 5 sec)
LPC_TIM0 -> MCR=(1<<0)|(1<<1); //on count reaching match value rai
LPC_TIM0 -> TCR=(1<<1); //initialize PC and TC to zero simultaniously
LPC_TIM0 -> TCR=(1<<0); //start timer counter
}
 
/*
#include<lpc17xx.h>
#include"lcd_full_prog.c"
#include<stdio.h>
#define LED_PIN(x) (1<<x)
//#define ADC_POWER_EN() (1<<1) // power enable for ADC
void T0_MR_delay(unsigned int);
int main()
{
LPC_GPIO1 -> FIODIR |= LED_PIN(19);
LPC_GPIO1 -> FIODIR |= LED_PIN(20);

T0_MR_delay(1000);
while(1)
{
if(LPC_TIM0 -> IR &(1<<0))	// FOR MR0
{
LPC_GPIO1 -> FIOPIN ^= LED_PIN(19); //TOGGLE OF LED
//LPC_GPIO1 -> FIOPIN ^= LED_PIN(20);
LPC_TIM0 -> IR =(1<<0);
}
if(LPC_TIM0 -> IR &(1<<1))	//MR1
{
//LPC_GPIO1 -> FIOPIN ^= LED_PIN(19); //TOGGLE OF LED
LPC_GPIO1 -> FIOPIN ^= LED_PIN(20);
LPC_TIM0 -> IR =(1<<1);
}
}

}
void T0_MR_delay(unsigned int us)
{
 LPC_SC -> PCONP |= (1<<1); //TIMER 0
LPC_SC -> PCLKSEL0 |= (0X00<<2);	//timer power contol enable

LPC_TIM0 -> MR0 = us*1000;	//load count value to MR0(for 1 sec)
LPC_TIM0 -> MR1 = 400000;
LPC_TIM0 -> MCR |= (1<<0);
LPC_TIM0 -> MCR |= (1<<3)|(1<<4); //on count reaching match value rai
LPC_TIM0 -> TCR=(1<<1); //initialize PC and TC to zero simultaniously
LPC_TIM0 -> TCR=(1<<0); //start timer counter
}
  */
