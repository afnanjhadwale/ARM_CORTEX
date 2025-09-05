#include<lpc17xx.h>
#define  ALL_LED_PINS (0xFF << 19)
#define  SWATCH_1(X) (1<<X)
#define  SWATCH_2(X) (1<<X)
#define  BUZZER (1 << 27)

void delay(unsigned int a);

int main(void)
{
LPC_GPIO1 -> FIODIR |= ALL_LED_PINS;
LPC_GPIO1 -> FIOCLR |= ALL_LED_PINS;
LPC_GPIO1 -> FIODIR |= BUZZER;
LPC_GPIO1 -> FIOCLR |= BUZZER;
LPC_GPIO2 -> FIODIR &= ~(SWATCH_1(11));
LPC_GPIO2 -> FIODIR &= ~(SWATCH_1(12));
while(1)
{
if((LPC_GPIO2 -> FIOPIN &(SWATCH_2(12)))!=0)  // polling statement ,switch status is monitered
{
  LPC_GPIO1 -> FIOSET |= ALL_LED_PINS;
  delay(100);
  LPC_GPIO1 -> FIOCLR |= ALL_LED_PINS;
  delay(100);
}
else if((LPC_GPIO2 -> FIOPIN &(SWATCH_1(11)))!=0)
//while(1)
{
  LPC_GPIO1 -> FIOSET |= BUZZER;
  delay(100);
  LPC_GPIO1 -> FIOCLR |= BUZZER;
  delay(100);
}
}
}
void delay(unsigned int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<6000;j++);
}
