#include <lpc17xx.h>
#include <stdint.h>
#include "lcd.h"

// Initialize I2C0 for EEPROM Communication
void i2c_config(void)
{
    // OPTIONAL: Power up I2C0 peripheral (bit 7 of PCONP)
    LPC_SC->PCONP |= (1 << 7);

    // Configure SDA0 (P0.27) and SCL0 (P0.28) pins for I2C function
    LPC_PINCON->PINSEL1 |= (1 << 22);      // P0.27 as SDA0
    LPC_PINCON->PINSEL1 |= (1 << 24);     // P0.28 as SCL0

    // Set I2C clock rate for 50kHz, assuming PCLK = 1MHz
    // Formula: I2C_Clock = PCLK / (SCLH + SCLL)
    // => 1MHz / (10 + 10) = 50kHz
	LPC_SC ->PCLKSEL0 |= ~((1<<15)|(1<<14));
    LPC_I2C0->I2SCLH = 10;  // High period of clock
    LPC_I2C0->I2SCLL = 10;  // Low period of clock

    // Enable I2C block (I2EN = bit 6)
    LPC_I2C0->I2CONSET = (1 << 6);
}

// Send START condition to I2C bus
void i2c_start(void)
{
    LPC_I2C0->I2CONSET = (1 << 5); // Set STA bit to send START condition

    while ((LPC_I2C0->I2CONSET & (1 << 3)) == 0); // Wait until SI (bit 3) is set

    LPC_I2C0->I2CONCLR = (1 << 5); // Clear STA bit
    LPC_I2C0->I2CONCLR = (1 << 3); // Clear SI (acknowledge the event)
}

// Write a byte to I2C bus
void i2c_mem_write(uint8_t d)
{
    LPC_I2C0->I2DAT = d; // Load data byte into I2C Data Register

    while ((LPC_I2C0->I2CONSET & (1 << 3)) == 0); // Wait until transmission completes (SI set)

    LPC_I2C0->I2CONCLR = (1 << 3); // Clear SI
}

// Send STOP condition to I2C bus
void i2c_stop(void)
{
    LPC_I2C0->I2CONSET = (1 << 4); // Set STO bit

    while ((LPC_I2C0->I2CONSET & (1 << 4)) == 1); // Wait until STOP is completed
}

// Read a byte from I2C EEPROM with ACK or NACK
char i2c_mem_read(uint8_t ack)
{
    uint8_t val;

    if (ack)
        LPC_I2C0->I2CONSET = (1 << 2); // Set AA (Assert ACK after data is received)
    else
        LPC_I2C0->I2CONCLR = (1 << 2); // Clear AA (Send NACK after data is received)

    while ((LPC_I2C0->I2CONSET & (1 << 3)) == 0); // Wait for SI (data ready)

    val = LPC_I2C0->I2DAT; // Read received byte

    LPC_I2C0->I2CONCLR = (1 << 3); // Clear SI

    return val;
}

int main()
{
    char dat;  // Variable to hold data read from EEPROM

    i2c_config(); // Initialize I2C0
    lcd_init();   // Initialize LCD

    // Display message
    lcd_str_write("Writing EEPROM..");
    delay(20);

    // --------------------- WRITE TO EEPROM ---------------------
    i2c_start();                      // Send START condition
    i2c_mem_write(0xA0);             // Slave address + Write bit (A0 = 1010 0000)
    i2c_mem_write(0x81);             // Memory address inside EEPROM
    i2c_mem_write('A');              // Actual data byte to write
    i2c_stop();                      // Send STOP condition

    // Show message on LCD
    lcd_cmd_write(0xC0);             // Move to 2nd line
    lcd_str_write("Write-DONE");
    delay(20);

    // --------------------- READ FROM EEPROM ---------------------
    lcd_cmd_write(0x01);             // Clear display
    lcd_str_write("Reading EEPROM..");
    delay(20);

    i2c_start();                     // Send START condition
    i2c_mem_write(0xA0);             // Send slave address with write bit (to send address)
    i2c_mem_write(0x81);             // Send memory address to read from

    i2c_start();                     // Send repeated START
    i2c_mem_write(0xA1);             // Send slave address with READ bit

    dat = i2c_mem_read(0);           // Read byte with NACK (as it is last byte)
    i2c_stop();                      // Send STOP condition

    lcd_cmd_write(0xC0);             // Move to second line
    lcd_str_write("Data is:");
    lcd_data_write(dat);            // Show read character on LCD
    delay(20);
}
