#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
int main()
{
	int i=0;
	DDRA=DDRA&~(1<<0);
	DDRC=DDRC|(1<<0);
	while(1)
	{
		if((PINA&(1<<0)))
		{
			
			i++;
		_delay_ms(200);
			switch (i)
			{
				case 2:
				PORTC=PORTC|1<<0;
				break;
				case 3:
				PORTC=0;
			}
			
		}			
			
		
		
	}
	return 0;
}