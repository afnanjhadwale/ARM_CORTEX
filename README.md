# ARM_CORTEX
# ARM Cortex-M3 (LPC1768) – Embedded Systems Course Repository

This repository contains **hands-on programs** for the NXP LPC1768 microcontroller, developed as part of my learning journey in **ARM Cortex-M3 programming**.  
It covers **GPIO, Timers, UART, SPI, I2C, ADC, PWM, RTC, and Interrupts** with **Keil µVision4** projects.

---

## 📌 Overview

| Folder Name          | Description |
|---------------------|-------------|
| **1. LED and Buzzeer** | GPIO basics – turn LEDs (P1.19–P1.24) and buzzer ON/OFF |
| **2. LCD**          | 16x2 LCD interface using 4-bit/8-bit mode |
| **3. KEKPAD**       | Matrix keypad scanning with GPIO |
| **4. ADC**          | Analog to Digital Conversion example |
| **5. TIMERS**       | Timer configuration, delay generation |
| **6. PWM**          | Generate PWM signal on appropriate pin |
| **7. RTC**          | Real Time Clock example |
| **8. INTERRUPT**    | External interrupts and NVIC usage |
| **9. PLL**          | Configure PLL for system clock |
| **10. UART**        | Serial communication @ 9600 baud (TX=P0.2, RX=P0.3) |
| **11. SPI**         | SPI master/slave communication |
| **13. I2C**         | I2C communication using SCL=P0.27, SDA=P0.28 |

> ⚠️ Some folders contain **only code snippets** (no circuit diagram or wiring).  
> Please refer to pin details below when connecting hardware.

---

## 🛠 Toolchain & Requirements

- **IDE:** [Keil µVision 4](https://www.keil.com/download/product/)
- **Compiler:** ARMCC
- **Microcontroller:** NXP LPC1768 (ARM Cortex-M3)
- **Programmer/Debugger:** LPC-Link / JTAG

---

## 🔌 Pinout Reference (LPC1768)

| Peripheral | Pins Used (Port.Pin) | Notes |
|-----------|--------------------|-------|
| **LEDs** | P1.19 – P1.24 | GPIO Output |
| **UART0** | TXD0 → P0.2 <br> RXD0 → P0.3 | Default UART0 |
| **SPI0** | SCK0 → P0.15 <br> MISO0 → P0.17 <br> MOSI0 → P0.18 <br> SSEL0 → P0.16 | Configure PINSEL0 accordingly |
| **I2C0** | SCL0 → P0.27 <br> SDA0 → P0.28 | Requires pull-up resistors |
| **PWM1** | MAT1.x / PWM1.x pins | Refer to manual for specific channel pins |

For more details, check **LPC1768 User Manual** (Section 8 – Pin Configuration).

---

## 🚀 How to Build & Flash

1. Open the `.uvproj` file for the desired example in **Keil µVision4**.
2. Build the project (`F7`).
3. Connect LPC1768 board via programmer/debugger.
4. Flash to target (`F8`).
5. Observe output (LED blink, UART output, etc.).

---

## 📖 References

- **NXP LPC1768 User Manual:** [UM10360](https://www.nxp.com/docs/en/user-guide/UM10360.pdf)
- ARM Cortex-M3 Technical Reference Manual

---

## 🧑‍💻 Author

**Afnan Jhadwale**  
This repository is part of my embedded systems learning path — contributions, suggestions, and feedback are welcome!

---

## ⚠️ Notes

- This repo is for **learning purposes** – use at your own risk.
- Double-check pin connections before powering hardware.
- Some examples may require additional setup (pull-ups, LCD contrast, etc.).

---
