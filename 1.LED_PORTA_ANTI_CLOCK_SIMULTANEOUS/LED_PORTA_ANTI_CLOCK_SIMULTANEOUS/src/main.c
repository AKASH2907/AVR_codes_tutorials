#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int i,j;
	DDRA=0xff;
	while(1)
	{
		for(i=7,j=0;i>=0&&j<=7;i--,j++)
		{
			PORTA=1<<i&1<<j;
			_delay_ms(100);
		}
	
			
	
		
	}
}