#include<lpc17xx.h>
#define ALL_LED_PINS (0xFF<<19)
#define LED_ODD(X) (0x81<<X)
#define LED_EVEN(X) (0x42<<X)
#define LED_ODD1(X) (0x24<<X)
#define LED_EVEN1(X) (0x18<<X)
void delay(unsigned int a);

int main(void)
{
int arr[] = {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};

LPC_GPIO1 -> FIODIR |=ALL_LED_PINS;
LPC_GPIO1 -> FIOCLR |=ALL_LED_PINS;

while(1)
{	 int i;
for(i=0;i<8;i++)
{
  LPC_GPIO1 -> FIOSET |= (arr[i]<<19);
  delay(1000) ;
  LPC_GPIO1 -> FIOCLR |=(arr[i]<<19);
  delay(1000) ;
  /*LPC_GPIO1 -> FIOSET |=LED_ODD(19);
  LPC_GPIO1 -> FIOCLR |=LED_EVEN(19);
  delay(1000);
  LPC_GPIO1 -> FIOSET |= LED_EVEN1(19);
  LPC_GPIO1 -> FIOCLR |=LED_ODD1(19);
  delay(1000) ;
  LPC_GPIO1 -> FIOSET |=LED_ODD1(19);
  LPC_GPIO1 -> FIOCLR |=LED_EVEN1(19);
  delay(1000);
  */
}
}
}
void delay(unsigned int a)
{
int i,j;
for(i=0;i<a;i++)
++for(j=0;j<6000;j++);
}
