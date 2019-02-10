#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int i,j;
	DDRC=DDRC&~(1<<0);
	DDRA=0xff;
	while(1)
	{
		if(PINC&1<<0)
		{
		for(i=0,j=0;i<=7,j<=7;i++,j++)
		{
			PORTA=1<<i|128>>j;
			_delay_ms(100);
			
		}
		}	
		else
		PORTA=0;
	}
}