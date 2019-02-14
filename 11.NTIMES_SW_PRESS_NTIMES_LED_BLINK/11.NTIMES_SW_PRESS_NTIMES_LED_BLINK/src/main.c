#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int n=0,i;
	DDRA=DDRA&~(1<<0);
	DDRC=DDRC|1<<0;
	while(1)
	{
		if((PINA&(1<<0)))
		{
			n++;
			_delay_ms(200);
			for(i=0;i<n;i++)
			{
				PORTC=PORTC|1<<0;
				_delay_ms(300);
				PORTC=PORTC&~1<<0;
				_delay_ms(300);
			}
			
		}
		
	}
}