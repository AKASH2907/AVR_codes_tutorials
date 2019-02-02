#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRA=DDRA|3<<6; //Two LEDs to be blink so change the lowest bits position to lowest led position
	while(1)
	{
		PORTA=PORTA|3<<6;
		_delay_ms(100);
		PORTA=PORTA&~(3<<6);
		_delay_ms(100);
	}
}