# AVR_codes_tutorials
AVR Codes for basic LED patterns contol to specialized functions such as Timer controls, Mulitple Interrupts, LCD, Edge Avoiding Bots, Vending Machines, etc.

ATmega 8/16 is a 8/16 bit microcontroller. The detailed datasheet of ATmega 8/16 can be read from [here](https://www.gme.cz/data/attachments/dsh.958-112.1.pdf) to know more about the specialized PIN functions. The codes were written in ATmel studio and for the designing of circuits [Proteus](https://proteus.soft112.com/) software is used. You can find the design files(.dsn) inside each folder of the code. Proteus software is very easy touse and it contains all the types of microcontrollers alongwith various objects required such as LED, LCD, Motor modules, Seven-segment display, etc.

The details of the codes are as follows:

[1] [LED_BLINK_SW](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/1.LED_BLINK_SW): The first code is just to inittialize ATmega8 board and does nothing.

[2] [LED_PORTA_ANTI_CLOCK_SIMULTANEOUS](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/1.LED_PORTA_ANTI_CLOCK_SIMULTANEOUS): It is the starting of the tutorials for ATmega8 microcontroller codes. In this program, the LED blinks simultaneously in clockwise and anticlockwise direction with a delay of 100ms.

[3] [LED_PORTA_C_A_ARRAY](https://github.com/AKASH2907/AVR_codes_tutorials/tree/master/2.LED_PORTA_C_A_ARRAY): In this code, microcontroller port A displays the values from the array on the LED such as A(0) = 0x81 will turn the LEDs at output PortA0 and PortA7. C_A denotes Clockwise CounterClockwise Simultaneously using Array values. Array A[] = {0x81,0x42,0x24,0x18,0x24,0x42,0x81}.

[4] [LED_PORTA_C_A_LEFT_RIGHT_OPERATOR]() - 
