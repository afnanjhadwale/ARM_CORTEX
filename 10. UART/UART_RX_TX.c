//uart Tx Rx

#include <lpc17xx.h>
#include <stdio.h>
#include "lcd_full_prog.c"

void uart_Init(void);
void uart_byte_transmit(char ch);
void uart_str_transmit(char *str);
char uart_byte_receive(void);
void delay(unsigned int ms);

int main()
{
 char ch;
 uart_Init();
 lcd_conf();
 do
 {
 ch = uart_byte_receive();
 lcd_data_write(ch);
 uart_byte_transmit(ch);
 }while(ch != '.');
}

void uart_Init(void)
{
 LPC_PINCON -> PINSEL0 |= (0X50); //SELECT P0.2 PIN AS UART0 TXD
                                  //& P0.3 PIN AS UART0 RXD //THT IS PINSEL0[7:4]=4b0101        //PIN 4 5 6 7
 
 LPC_SC -> PCONP |= (1<<3); //PG.64 //UART0 PER ENABLE
 LPC_SC -> CLKSRCSEL = (0X00); //SELECT IRC OSCILLATOR AS PLL0 CLK SOURCE //4MHZ
 LPC_SC -> PCLKSEL0 &= ~((1<<7)|(1<<6));         //PG 57

 LPC_UART0 -> LCR |= (0X03); //NO PARITY,1 STOP BIT, 8 BIT WORD LENGTH
 LPC_UART0 -> LCR |= (1<<7); //ENABLE DIVISOR LATCH

 LPC_UART0 -> DLM = (0X00);
 LPC_UART0 -> DLL = (0X06);

 LPC_UART0 -> FDR |= 0XC1; //FRACTIONAL DIVIDER REG
 LPC_UART0 -> FCR |= 0X07; //FIFO ENABLE
 LPC_UART0 -> LCR &= ~(1<<7); //DISABLE DIVISOR LATCH           //PG 314
}


void uart_str_transmit(char *str)
{
 while(*str != '\0')
 {
  uart_byte_transmit(*str);
  str++;
 }
 uart_byte_transmit(0X0D);    //CARRIAGE RETURN
 uart_byte_transmit(0X0A);    //LINE FEED   //BOTH 0D AND 0A PERFORMS ENTER OPERATION
}

void uart_byte_transmit(char ch)
{
 while((LPC_UART0->LSR&(1<<5)==0)){}     //checking for thr is empty or not //pg 316
 LPC_UART0->THR= ch;
 delay(100);
}

char uart_byte_receive(void)
{
    char ch;
    while ((LPC_UART0->LSR & (1 << 0))== 0){ } // check if Rx FIFO is empty or Check RBR holds an uread char or not
    return LPC_UART0->RBR;
    return ch;
}
