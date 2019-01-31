#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRA=0xff;
	int i,j;
	while(1)
	{
		for(i=0,j=0;i<=7,j<=7;i++,j++)
		{
			PORTA=(1<<i)|(128>>j);
			_delay_ms(100);
		}
	}
	
}