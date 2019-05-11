# AVR_codes_tutorials
AVR Codes for basic LED patterns contol to specialized functions such as Timer controls, Mulitple Interrupts, LCD, Edge Avoiding Bots, Vending Machines, etc.

ATmega 8/16 is a 8/16 bit microcontroller. The detailed datasheet of ATmega 8/16 can be read from [here](https://www.gme.cz/data/attachments/dsh.958-112.1.pdf) to know more about the specialized PIN functions. Some facts about the Atmega16 microcontorller is as follows:

* It is a 40-pin low power microcontroller developed using CMOS technology based on AVR architecture. CMOS technology mainly used as it comes with lowpower consumption and high noise immunity.
* ATmega16, an 8-bit controller based on AVR advanced RISC (Reduced Instruction Set) architecture.
* It is a single chip computer that comes with CPU, ROM, RAM, EEPROM, Timers, Counters, ADC and four 8-bit ports called PORTA, PORTB, PORTC, PORTD where each port consists of 8 I/O pins.
* Atmega16 has built-in registers that are used to make a connection between CPU and external peripherals devices.
* Atmega16 comes with two 8-bit timers and one 16-bit timer. All these timers can be used as counters when they are optimized to count the external signal.

Pin Layout Diagram of **ATmega16** is as follows:
![introduction-to-atmega16-5-1](https://user-images.githubusercontent.com/22872200/52076803-7c865f00-25b5-11e9-88e8-8cb1a8cc4fe9.png)


# Codes

   The codes were written in ATmel studio and for the designing of circuits [Proteus](https://proteus.soft112.com/) software is used. You can find the design files(.dsn) inside each folder of the code. Proteus software is very easy to use and it contains all the types of microcontrollers alongwith various objects required such as LED, LCD, Motor modules, Seven-segment display, etc.
   
   I have used Port A for most of my work. Don't ask why. (My name starts with A :bowtie: ). Pretty much folder titles displays what is happening in the code, but still I'm plotting out any extra details required.


The details of the codes are as follows:

[0] [LED_BLINK_SW](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/1.LED_BLINK_SW): The first code is just to inittialize ATmega8 board and does nothing.

[1] [LED_PORTA_ANTI_CLOCK_SIMULTANEOUS](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/1.LED_PORTA_ANTI_CLOCK_SIMULTANEOUS): It is the starting of the tutorials for ATmega8 microcontroller codes. In this program, the LED blinks simultaneously in clockwise and anticlockwise direction with a delay of 100ms.

[2] [LED_PORTA_C_A_ARRAY](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/2.LED_PORTA_C_A_ARRAY): In this code, microcontroller port A displays the values from the array on the LED such as A(0) = 0x81 will turn the LEDs at output PortA0 and PortA7. C_A denotes Clockwise CounterClockwise Simultaneously using Array values. Array A[ ] = {0x81,0x42,0x24,0x18,0x24,0x42,0x81}.

[3] [LED_PORTA_C_A_LEFT_RIGHT_OPERATOR](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/3.LED_PORTA_C_A_LEFT_RIGHT_OPERATOR) - The LEDs on Port A from A0 to A7 turns ON from both left and right sides simultaneously. Then, again the pattern of clockwise and counterclockwise is happening simultaneously. But, here the difference is that it is done using ***LEFT(<<)*** and ***RIGHT(>>) SHIFT*** operators.

[4] [LED_PORTA_D6_D7_BLINK](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/4.LED_PORTA_D6_D7_BLINK) - D6 and D7 blinking with 100ms delay.  

[5] [LED_PORTA_SELECTED_BLINK](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/5.LED_PORTA_SELECTED_BLINK) - Selected Blinking of LEDs on Port A.

[6] [1SWITCH_1LED](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/6.1SWITCH_1LED) - This program uses 1 switch and 1 LED. This is the beginning for **writing instruction** to the port. Till now, in LEDs we were writing code from port to output device.

[7] [TWO_SW_TWO_LED](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/7.TWO_SW_TWO_LED) - 2 switches and 2 LEDs. Likewise, it can be extended for multiple switches.

[8] [SW_CW_CCW_SIMULT](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/8.SW_CW_CCW_SIMULT) - If the switch is pressed, then there is a simultaneous clockwise and anti-clockwise blinking of LEDs on Port A.

[9] [SW_PRESS2TIMES_LED_GLOW_OFF_3RDTIME](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/9.SW_PRESS2TIMES_LED_GLOW_OFF_3RDTIME) - If the switch is pressed 2 timesthen lED goes on, for third time, it will go OFF.

[10] [7SEG_000_999](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/10.7SEG_000_999) - Seven segment display counting starts from 000 and goes up till 999.

[11] [NTIMES_SW_PRESS_NTIMES_LED_BLINK](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/11.NTIMES_SW_PRESS_NTIMES_LED_BLINK) -  

***Updating regularly....***
