#include <lpc17xx.h>
#include <stdint.h>

void ssp_spi_config(void);
void spi_data_write(uint16_t data);
void delay(uint32_t millis);
int main()
{
 ssp_spi_config();
 spi_data_write(0x0C01);    //XC: is to select shutdown register; write X1 to shutdown reg to make display units operational
 spi_data_write(0x0A0F);    //XA: is to select intensity register; write 15(max val) to intensity register for maximum brightness
 spi_data_write(0x0B03); //XB: select scan-limit register; write X3 to scan-limit register for scanning DIG-0,1,2,3 display
 spi_data_write(0x090F); //decode mode on

 while(1)
 {
 spi_data_write(0x0101);
 spi_data_write(0x0207);
 spi_data_write(0x0306);
 spi_data_write(0x0408);

 delay(200);

 spi_data_write(0x010C);
 spi_data_write(0x020B);
 spi_data_write(0x030D);
 spi_data_write(0x040E);
  
 delay(200);

 }

}

void ssp_spi_config(void)
{
LPC_SC->PCONP|=(1<<10);	//PCONP=PCONP | (1<<10)
LPC_SC->PCLKSEL0=(3<<20); //PCLK=CCLK/8// clock division

LPC_PINCON->PINSEL0|=(1<<15);     //P0.7 pin as SCK1
LPC_PINCON->PINSEL0|=(1<<17);    //P0.8 pin as MISO1
LPC_PINCON->PINSEL0|=(1<<19);    //P0.9 pin as MOSI1

LPC_GPIO0->FIODIR|=(1<<6);  //P0.6 pin as GPIO output pin: SSEL1

LPC_SSP1->CR0= 0xB;  //(3<<0)|(1<<3);
LPC_SSP1->CR0&=~(0x3<<4); 

LPC_SSP1->CPSR= 20; 
LPC_SSP1->CR0&=~(0xFF<<8);	  //SCR=0
LPC_SSP1->CR0&=~(0x3<<6);

LPC_SSP1->CR1&=~(1<<0);    //no loop back mode  i.e normal operation
LPC_SSP1->CR1&=~(1<<2);    //master mode or slave mode: Master mode is default
LPC_SSP1->CR1|=(1<<1);       //enable SSP Controller
}

void spi_data_write(uint16_t data)
{
LPC_GPIO0->FIOCLR=(1<<6); 	 //slave selected
while(!(LPC_SSP1->SR & (1<<1)));
LPC_SSP1->DR=data;
while((LPC_SSP1->SR & (1<<4)));
LPC_GPIO0->FIOSET=(1<<6); 
}

void delay(uint32_t millis)
{
uint32_t i,j;
for(i=0;i<millis;i++)
{
for(j=0;j<6000;j++);
}
}
