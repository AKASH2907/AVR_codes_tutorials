#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int n=0,arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	DDRA=DDRA&~(1<<0);
	DDRC=0xff;
	while(1)
	{
		if((PINA&(1<<0)))
		
			n++;
			_delay_ms(200);
			if(n<=9)
			{
				PORTC=arr[n];
			}
			else
			{
				PORTC=arr[0];
				n=0;
			}
			
	}
}