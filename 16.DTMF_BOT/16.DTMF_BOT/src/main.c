#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int x;
	DDRB&=~(0x0f);
	DDRA|=0x0f;
	
	while(1)
	{
		x=PINB;
		x=x&(0x0f);
		switch (x)
		{
			case 2:
			PORTA=0x05;
			_delay_ms(5000);
				break;
			case 4:
			PORTA=1<<2;	break;
			case 6:
			PORTA=1<<0; break;
			case 8:
			PORTA=0x0a; break;
			default:
			PORTA=0;
			
		}
	}
}