
// single edge pwm // light will glow high to low
/*
#include<lpc17xx.h>
#include"lcd_full_prog.c"
#include<stdio.h> 
 

int main()
{
LPC_GPIO1 -> FIODIR |= (0x7F<<20);
LPC_PINCON -> PINSEL3 &= ~(1<<4); //p1.18 as pwm1
LPC_PINCON -> PINSEL3 |= (1<<5);
LPC_SC -> PCONP |= (1<<6); //PWM1 power / clk control enable	 
LPC_SC -> PCLKSEL0 |= (0X01<<12);

LPC_PWM1 -> PR=3;//(PCLK/PR+1)=1MHZ
LPC_PWM1 -> MR0 = 10000;//TOTAL TIME PEROID OF PWM CYCLE,10ms
LPC_PWM1 -> MCR |= (1<<1); //RESET ON MR0
LPC_PWM1 -> LER |= (1<<0); //ENABLE MR0 LATCH
LPC_PWM1 -> PCR=(1<<9);	   //PWM1 OP ENABLE
LPC_PWM1 -> TCR |= (1<<0)|(1<<3); //ENABLE PWM TIMER AND PWM MODE

while(1)
{
LPC_PWM1 -> MR1 = 2000;//20%duty cycle
LPC_PWM1 -> LER |= (1<<1); //enable MR! latch
delay(100);
LPC_PWM1 -> MR1 = 4000;//20%duty cycle
LPC_PWM1 -> LER |= (1<<1); //enable MR! latch
delay(100);
LPC_PWM1 -> MR1 = 7500;//20%duty cycle
LPC_PWM1 -> LER |= (1<<1); //enable MR! latch
delay(100);
LPC_PWM1 -> MR1 = 10000;//20%duty cycle
LPC_PWM1 -> LER |= (1<<1); //enable MR! latch
delay(100);

}

 }	   */


   
// doubleedge pwm // light will glow high to low
#include<lpc17xx.h>
#include"lcd_full_prog.c"
#include<stdio.h> 

int main()
{
LPC_GPIO1 -> FIODIR |= (0x7F<<20);
LPC_PINCON -> PINSEL4 &= ~(1<<8); //clear bits 9 and 8
LPC_PINCON -> PINSEL4 |= (1<<8);	//p2.4 as pwm5
LPC_SC -> PCONP |= (1<<6); //PWM1 power / clk control enable	 
LPC_SC -> PCLKSEL0 |= (0X01<<12);

LPC_PWM1 -> PR=0;//(PCLK/PR+1)=1MHZ
LPC_PWM1 -> MR0 = 10000;//TOTAL TIME PEROID OF PWM CYCLE,10ms
LPC_PWM1 -> MCR |= (1<<1); //RESET ON MR0
LPC_PWM1 -> LER |= (1<<0); //ENABLE MR0 LATCH
LPC_PWM1 -> PCR=(1<<5);	   //PWM5 double edge ENABLE
LPC_PWM1 -> PCR=(1<<13); //enable PWM5 channel
LPC_PWM1 -> TCR |= (1<<0)|(1<<3); //ENABLE PWM TIMER AND PWM MODE

while(1)
{
LPC_PWM1 -> MR4 = 2000;//20%duty cycle
LPC_PWM1 -> MR5 = 4000;
LPC_PWM1 -> LER |= (1<<5)|(1<<4); //enable MR! latch
delay(100);
LPC_PWM1 -> MR4 = 2000;//40%duty cycle
LPC_PWM1 -> MR5 = 6000;
LPC_PWM1 -> LER |= (1<<5)|(1<<4); //enable MR! latch
delay(100);
LPC_PWM1 -> MR4 = 2000;//60%duty cycle
LPC_PWM1 -> MR5 = 8000;
LPC_PWM1 -> LER |= (1<<5)|(1<<4); //enable MR! latch
delay(100);
LPC_PWM1 -> MR4 = 2000;//80%duty cycle
LPC_PWM1 -> MR5 = 10000;
LPC_PWM1 -> LER |= (1<<5)|(1<<4); //enable MR! latch
delay(100);

LPC_PWM1 -> MR4 = 1000;//90%duty cycle
LPC_PWM1 -> MR5 = 10000;
LPC_PWM1 -> LER |= (1<<5)|(1<<4); //enable MR! latch
delay(100);
}
 }
