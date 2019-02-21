#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRC=DDRC&~(3<<0);
	DDRA=DDRA|0x02;
	while(1)
	{
		if((PINC&(3<<0)))
		PORTA=PORTA|0x05;
		else 
		PORTA=0;
	}
}