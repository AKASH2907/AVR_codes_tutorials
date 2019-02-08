#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRA=DDRA&~3<<5;
	DDRC=DDRC|3<<2;
	while(1)
	{
		
		if(PINA&1<<5)
		PORTC=PORTC|1<<2;
		else if(PINA&2<<5)
		PORTC=PORTC|2<<2;
		else
		PORTC=PORTC&~(3<<2);
		
	}
}