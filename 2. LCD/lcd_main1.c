#include"lcd_full_prog.c"
int main(void)
{
	char letter[20] = "Afnan_Jhadwale_"; 	
	unsigned int nu=1234;
	lcd_conf();
	str_write(letter);
	delay(100);
	//lcd_conf();
	lcd_cmd_write(0XC0);
	lcd_num(nu);
	delay(100);
}
