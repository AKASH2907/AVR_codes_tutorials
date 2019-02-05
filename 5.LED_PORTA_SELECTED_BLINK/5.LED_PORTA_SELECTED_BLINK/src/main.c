#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRA=DDRA|7<<2;
	while (1)
	{
		PORTA=PORTA|7<<2;
		_delay_ms(100);
		PORTA=(PORTA)&~7<<2;
		_delay_ms(100);
	}
}