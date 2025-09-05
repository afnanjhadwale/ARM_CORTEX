#include<LPC17XX.h> 
#include"lcd_full_prog.c" // for delay 
 
void SystemInit(void); 
void delay(uint32_t ms);

int main() 
{ 
	int count =0; 
	LPC_GPIO1 -> FIODIR |= (0xFF <<19);  // config p1.19 to p1.26 as op ports 
 
	while(1) 
	{ 
		LPC_GPIO1 -> FIOSET |= (0xFF <<19);   // set all LEDS high 
		delay(100); 
		LPC_GPIO1 -> FIOCLR |= (0xFF <<19);   // set all LEDS low 
		delay(100); 
	 
		if (count == 10) 
				SystemInit(); 
		else  
				count++; 
	} 
}
 
void SystemInit(void) 
{ 
	// initialize the PLL 
	 
	LPC_SC -> SCS =0x000000020;      //ENABLE THE MAIN OSCILLATOR (BIT 5) /* Syscon Miscellaneous Registers (1<<5) 	 //page no 29 (1<<5)
	while(!(LPC_SC -> SCS & 0x000000040)) // WAIT FOR THE MAIN OSCILLATOR    (1<<6)  0X00000040 
	           // TO BE READY (BIT 6) 
	 
	LPC_SC -> CCLKCFG = 0x000000003; // SET THE CPU CLK DIVIDER TO 4 
	          // FOR A 72 MHZ CPU CLK 
	LPC_SC -> CLKSRCSEL = 0x000000001; // SELECT THE MAIN OSCILLATOR AS  
	            // THE PLL CLK SRC 
	LPC_SC -> PLL0CFG  =0x00050063; // M=5 P=2 (MULTIPLY BY 5 AND DIVIDE BY 2) 
	LPC_SC -> PLL0CON =0x01; // ENABLE THE PLL 
	LPC_SC -> PLL0FEED =0xAA; 
	LPC_SC -> PLL0FEED =0x55; 
	while(!(LPC_SC ->PLL0STAT & (1<<26))); // WAIT FOR PLL LOCK 
	//FOR M=6, N=1 
	// LPC_SC -> PLL0CFG = (5<<0)|(0<<16); 
	// FOR M=12, N=2 
	// LPC_SC -> PLL0CFG = (11<<0)|(1<<16); 
	LPC_SC -> PLL0CON =0x03;  // connect the pll (bit 1) 
	LPC_SC -> PLL0FEED =0xAA; 
	LPC_SC -> PLL0FEED =0x55; 
}

/*void delay(uint32_t ms)
{
	unsigned int cycles = 700*ms, i;
	for (i=0;i<cycles;i++);
}
  */
