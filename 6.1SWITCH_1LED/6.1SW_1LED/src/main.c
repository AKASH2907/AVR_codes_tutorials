#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRA=DDRA&~1<<0;
	DDRC=DDRC|1<<0;
	while(1)
	{
		if(PINA&1<<0)
		PORTC=PORTC|1<<0;
		else
		PORTC=PORTC&~1<<0;
	}
}