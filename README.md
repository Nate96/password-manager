A program that manages passwords on a Microcontroller

# Device Specs
- Microcontroller: (Seeed Studio XIAO RP2040 x1)[https://wiki.seeedstudio.com/XIAO-RP2040-with-Arduino/]
- CPU: Dual-core ARM Cortex M0+ processor, flexible clock running up to 133 MHz
- Storage: 264KB of SRAM, and 2MB of on-board Flash memory
- Interface: XIAO have 11 digital pins, 4 analog pins, 11 PWM Pins,1 I2C interface,
  1 UART interface, 1 SPI interface, 1 SWD Bonding pad interface.
    - 6 Buttons
    - small LED screen

NOTE: This program will have an abstract layer. Thus, having the capabilities 
to run on multiple boards. Program will still expect only 6 inputs and displays
to an OLED display.
