								 // lcd.c - Function definitions for LCD operations using LPC1768

#include "lcd.h"  // Include the header for declarations and macros

// Send command byte to LCD (RS = 0)
void lcd_cmd_write(char cmd)
{
    LPC_GPIO0->FIOCLR = LCD_DATA_PINS;          // Clear previous data bits
    LPC_GPIO0->FIOSET = (cmd << 15);            // Set new command bits on P0.15–P0.22
    LPC_GPIO0->FIOCLR = LCD_RS_PIN(10);         // RS = 0 (command mode)
    LPC_GPIO0->FIOSET = LCD_EN_PIN(11);         // EN = 1 (start transmission)
    delay(10);                                  // Wait for data to latch
    LPC_GPIO0->FIOCLR = LCD_EN_PIN(11);         // EN = 0 (end transmission)
}

// Send a single data character to LCD (RS = 1)
void lcd_data_write(char dat)
{
    LPC_GPIO0->FIOCLR = LCD_DATA_PINS;          // Clear previous data bits
    LPC_GPIO0->FIOSET = (dat << 15);            // Set new character bits on P0.15–P0.22
    LPC_GPIO0->FIOSET = LCD_RS_PIN(10);         // RS = 1 (data mode)
    LPC_GPIO0->FIOSET = LCD_EN_PIN(11);         // EN = 1 (start transmission)
    delay(10);                                  // Wait for data to latch
    LPC_GPIO0->FIOCLR = LCD_EN_PIN(11);         // EN = 0 (end transmission)
}

// Send a null-terminated string to LCD
void lcd_str_write(char *str)
{
    while (*str != '\0')             // Loop until null terminator
    {
        lcd_data_write(*str);        // Send character to LCD
        str++;                       // Move to next character
    }
}

// Initialize LCD: configure pins, set display mode
void lcd_init(void)
{
    // Set P0.15–P0.22, P0.10 (RS), P0.11 (EN) as output
    LPC_GPIO0->FIODIR |= LCD_DATA_PINS;
    LPC_GPIO0->FIODIR |= LCD_RS_PIN(10);
    LPC_GPIO0->FIODIR |= LCD_EN_PIN(11);

    // LCD Initialization sequence
    lcd_cmd_write(0x38);   // Function set: 8-bit, 2-line, 5x8 dots
    lcd_cmd_write(0x0E);   // Display ON, cursor ON
    lcd_cmd_write(0x01);   // Clear display
    delay(2);              // Short delay after clear
}

// Simple software delay function (blocking)
void delay(uint32_t ms)
{
    uint32_t i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 6000; j++) { }   // Approx 1ms delay loop
    }
}
