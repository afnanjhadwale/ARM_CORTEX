# ARM Cortex – LPC1768 Programs

This repository contains **hands-on programs for LPC1768** written in C and compiled using **Keil µVision4**.  
It is designed for students and beginners to understand **ARM Cortex-M3 microcontroller programming** through practical examples.

---

## 📁 Folder Structure

| Folder | Description |
|-------|-------------|
| **1. LED and Buzzer** | Basic GPIO programming. Turns ON/OFF LEDs connected to **P1.19–P1.26** in patterns, toggles a buzzer on **P1.27**, and demonstrates switch-based control. |
| **2. LCD** | LCD interfacing programs. Displays text and numbers using an 8-bit interface (P0.15–P0.22 data, P0.10 RS, P0.11 EN). Includes reusable `lcd_full_prog.c` driver. |
| **3. KEYPAD** | 4x4 matrix keypad interfacing. Scans rows (P2.4–P2.7) and columns (P2.0–P2.3), detects which key is pressed, and shows result (`0–F`) on the LCD. |
| **4. ADC** | LM35 temperature sensor interface using ADC0.2 (P0.25). Converts analog voltage to temperature and displays result on LCD. |
| **5. TIMERS** | Timer programming examples. Demonstrates delay generation, square wave generation, and toggling GPIOs using Timer0/Timer1. |
| **6. PWM** | Pulse Width Modulation examples. Configures PWM1 module to control duty cycle for LEDs or motors. |
| **7. RTC** | Real-Time Clock examples. Initializes RTC, sets time/date, and continuously displays real-time clock values on LCD. |
| **8. INTERRUPT** | External interrupt (EINT0/EINT1) examples. Demonstrates interrupt-based LED toggling and switch debouncing. |
| **9. PLL** | Configures Phase Locked Loop to generate system clock frequencies (e.g., CCLK = 72 MHz from FPLL = 144 MHz). |
| **10. UART** | UART0 communication programs. Sends and receives characters via serial terminal (TxD0 – P0.2, RxD0 – P0.3). |
| **11. SPI** | SPI communication examples. Configures SPI0 (P0.15–P0.18) for master mode data transfer. |
| **13. I2C** | I²C master communication examples. Demonstrates start/stop conditions, address transmission, and data transfer over SDA/SCL (P0.27, P0.28). |

---

## 🔌 Pinout Reference (LPC1768)

| Peripheral | Pins Used (Port.Pin) | Notes |
|-----------|---------------------|-------|
| **LEDs** | P1.19 – P1.24 | GPIO Output |
| **Buzzer** | P1.27 | GPIO Output |
| **Switches** | P2.11, P2.12 | Active High |
| **LCD** | Data: P0.15 – P0.22<br>RS: P0.10, EN: P0.11 | 8-bit Mode |
| **UART0** | TXD0 → P0.2<br>RXD0 → P0.3 | Default UART0 |
| **SPI0** | SCK0 → P0.15<br>MISO0 → P0.17<br>MOSI0 → P0.18<br>SSEL0 → P0.16 | Configure PINSEL0 accordingly |
| **I2C0** | SCL0 → P0.27<br>SDA0 → P0.28 | Requires pull-up resistors |
| **PWM1** | MAT1.x / PWM1.x pins | Refer to user manual for specific channel pins |

📖 For more details, check **LPC1768 User Manual (UM10360, Section 8 – Pin Configuration).**

---

## 🚀 How to Build & Flash

1. Open the `.uvproj` file for the desired example in **Keil µVision4**.
2. Build the project (**F7**).
3. Connect LPC1768 board to PC via programmer/debugger.
4. Use **Flash Magic** (or Keil flash tool) to program the microcontroller.
5. Reset board and observe output (LED blink, LCD text, UART output, etc.).

---

## 📖 References

- **NXP LPC1768 User Manual:** UM10360  
- **ARM Cortex-M3 Technical Reference Manual**  
- **Flash Magic User Guide** (for ISP programming)

---

## 🧑‍💻 Author

**Afnan Jhadwale**  
This repository is part of my embedded systems learning path — contributions, suggestions, and feedback are welcome!

---

## ⚠️ Notes

- This repo is for **learning purposes** – use at your own risk.  
- Double-check pin connections before powering hardware.  
- Some examples may require additional setup (e.g., LCD contrast adjustment, pull-ups).  

---

