#include<lpc17xx.h>
#include"lcd_full_prog.c"
#include<stdio.h> 
#define VREF 3.3 //reference voltage  @VREFp PIN, VREFn=0
#define ADC_POWER_EN() (1<<12) // power enable for ADC
#define SEL_AD0_2 (1<<2)// 2nd channel selected AD0.2
#define CLK_DIV (3<<8) //ADC CLKDIV (ADC_CLCK=PCLK/CLKDIV+1)=1MHz
#define PWR_UP (1<<21) //setting it to operating mode 
#define START_CONV (1<<24) // start convertion (001)
#define ADC_Done (1U<<31) //U mean it as unsigned value	 bucz 31 bit give us as singned vale (- & +)
#define T_coeff 100.0f 

int main(void)
{
int result=0;
float volts=0;
char svolts[20];
float temp=0;
char stemp[20];

LPC_PINCON -> PINSEL1 |= (1<<18); //SELECT AD0.2 FOR P0.25 
LPC_SC -> PCONP |= ADC_POWER_EN(); //sys config
LPC_ADC -> ADCR = PWR_UP|CLK_DIV|SEL_AD0_2;

lcd_conf();
   while(1)
   {
	 LPC_ADC -> ADCR |= START_CONV; //start new conversion 
	 while((LPC_ADC->ADDR2 & ADC_Done)==0){} // WAIT UNTIL CONVERSION IS DONE 
	 result = (LPC_ADC -> ADDR2>>4)& 0XFFF;//ASTRACTING THE 12BITS
	 volts=(result*VREF)/4096.0;
	 sprintf(svolts,"voltage=%2fv",volts);
	 str_write(svolts);// to display on lcd
	 lcd_cmd_write(0xC0);//force courser to second row
	
	 temp=volts *T_coeff;
	 sprintf(stemp,"temp=%2f'c",temp);
	 str_write(stemp);
	 delay(500);
	 lcd_cmd_write(0x01);//clear the screen

   }
} 
