#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int x;
	DDRA&=~(0x0f);
	DDRC|=0x1f;
	while(1)
	{
		x=PINA;
		x=x&0x0f;
		switch(x)
		{
			case 1:	PORTC=1; break;
			case 2: PORTC=2; break;
			case 3: PORTC=1<<2; break;
			case 4: PORTC=1<<3; break;
			case 5: PORTC=1<<4; break;
			default: PORTC=0;
		}
	}
}