#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void main()
{
	DDRA=0xff;
	int i;
	unsigned char arr[]={0x81,0x42,0x24,0x18,0x24,0x42,0x81};
	while(1)
	{
		for(i=0;i<=6;i++)
		{
			PORTA=arr[i];
			_delay_ms(100);
		}
	}
	
}