#include<lpc17xx.h>
#include<stdint.h> 

#define ROW_PINS(X) (0xff<<X)

void row_scan(int b);