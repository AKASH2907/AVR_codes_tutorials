# define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	int i,j,k,arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x5f,0x7c,0x39,0x5e,0x7b,0x79};
	DDRA=DDRC=DDRB=0xff;
	while(1)
	{
		for(i=0;i<=9;i++)
		{
			PORTA=arr[i];
			for(j=0;j<=9;j++)
			{
				PORTB=arr[j];
				for(k=0;k<=9;k++)
				{
					PORTC=arr[k];
					_delay_ms(200);
				}
			}
		}
	}
	
}