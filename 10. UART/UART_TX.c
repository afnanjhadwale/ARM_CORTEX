/*
#include <LPC17xx.h>
#include <stdint.h>

void uart_Init(void); //uart initialization
void uart_byte_transmit(char ch);
void uart_str_transmit(char *str);
void delay_ms(unsigned int ms);

int main()
{
char ch='K';
char str[] = "CRANES VARSITY";
uart_Init();  //initializing uart

uart_byte_transmit(ch);
uart_byte_transmit(0X0D);//	carriage return
uart_byte_transmit(0X0A); // line feed
delay_ms(100);
uart_str_transmit(str);
}
void uart_Init(void)
{
LPC_SC -> PCONP |= (1<<3); //ENABLE UART0
LPC_SC -> CLKSRCSEL |= (0X00);
LPC_SC -> PCLKSEL0 &= ~((1<<7)|(1<<6));

LPC_PINCON -> PINSEL0 |= (1<<4);  //P0.2 PIN AS UART TX
LPC_PINCON -> PINSEL0 &= ~(1<<5);
LPC_PINCON -> PINSEL0 |= (1<<6);  //P0.3 PIN AS UART RX
LPC_PINCON -> PINSEL0 &= ~(1<<7);

//No parity, 1stop bit and 8 bits of data

LPC_UART0 -> LCR |= (3<<0); //WORD LENGTH 
LPC_UART0 -> LCR |= (1<<7);//DIVISOR LATCH ENABLE 

LPC_UART0 -> DLM = (0X00);
LPC_UART0 -> DLL = (0X06);
//LPC_UART0 -> DLL = 97;
LPC_UART0 -> LCR &= ~(1<<7);//DIVISOR LATCH ENABLE 
}

void uart_byte_transmit(char ch)
{
while((LPC_UART0 -> LSR & (1<<5) == 0)){} //checking for the THR is empty or not
LPC_UART0 -> THR = ch;
delay_ms(100);
}

void uart_str_transmit(char *str)
{
while(*str != '\0')
{
uart_byte_transmit(*str);
str++;
}
uart_byte_transmit(0X0D);//	carriage return
uart_byte_transmit(0X0A); // line feed
}
void delay_ms(unsigned int ms)
{
int i,j;
for(i=0; i<ms; i++)
for(j=0; i<6000; j++) ;
}
*/

// uart tx :-- 
#include <LPC17XX.h> 
#include <stdint.h> 

void uart_Init(void); // uart initialization 
void uart_byte_transmit(char ch); 
void uart_str_transmit(char *str); 
void delay_ms(unsigned int ms); 

int main() 
{ 
char ch='K'; 
char str[]="CRANES VARSITY";  
uart_Init(); //INITIALIZING UART
uart_byte_transmit(ch); //1ST LINE DISPLAY

uart_byte_transmit(0X0D); // carriage return 
uart_byte_transmit(0X0A); // line feed 

delay_ms(100); 
uart_str_transmit(str); 
} 

void uart_Init(void) 
{ 
LPC_SC -> PCONP |= (1<<3); // ENABLE UART0 
//LPC_SC -> CLKSRCSEL |= (0X00);  
LPC_SC -> PCLKSEL0 &= ~((1<<7)|(1<<6));  

LPC_PINCON -> PINSEL0|=(1<<4);// P0.2  PIN AS uart Tx pin 
LPC_PINCON -> PINSEL0&=~(1<<5); 
LPC_PINCON -> PINSEL0|=(1<<6); // P0.3 PIN AS uart Tx pin 
LPC_PINCON -> PINSEL0&=~(1<<7); 

// no parity, 1 stop bit and 8 bit word length 
LPC_UART0 -> LCR |= (0X03);   // OR (3<<0) WORD LENGTH IS 8 BITS
LPC_UART0 -> LCR |= (1<<7);  //DLAB
LPC_UART0 -> DLM = (0X00);  //MSB BYTE 
LPC_UART0 -> DLL = (0X06); 	//LSB BYTE
LPC_UART0 -> FDR  |= (0Xc1); // fractional value 
LPC_UART0 -> FCR  |= (0X07); // FIFO ENABLE 
LPC_UART0 -> LCR &= ~(1<<7); // DISABLE DIVISOR LATCH 
// both 0D and 0A performs enter operation 
// ENABLE DIVISOR LATCH 
} 
void delay_ms(unsigned int ms) 
{ 
int i,j; 
for(i=0; i<ms; i++) 
for(j=0; j<2000; j++); 
} 
void uart_str_transmit(char *str) 
{ 
while(*str != '\0') 
{ 
uart_byte_transmit(*str); 
str++; 
} 
uart_byte_transmit(0X0D); // CARRIAGE RETURN 
uart_byte_transmit(0X0A); // LINE FEED 
} 
void uart_byte_transmit(char ch) 
{ 
while((LPC_UART0-> LSR&(1<<5)==0)){}// checking for the THR is empty or not 
LPC_UART0 -> THR =ch; //LOADING THE CHAR INTO THE thr
delay_ms(100); 
}
