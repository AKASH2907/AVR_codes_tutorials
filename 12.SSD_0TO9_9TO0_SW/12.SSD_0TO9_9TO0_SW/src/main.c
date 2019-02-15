#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int n,i,arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x5f,0x7c,0x39,0x5e,0x7b,0x79};
	DDRA=DDRA&~1<<0;
	DDRC=0xff;
	while(1)
	{
		if(PINA&1<<0)
		{
			for(i=0;i<=9;i++)
			{
				PORTC=arr[i];
				_delay_ms(1000);
				
			}
			for(i=9;i>=0;i--)
			{
				PORTC=arr[i];
				_delay_ms(1000);
				
			}
		}
		else
		PORTC=0;
	}
}