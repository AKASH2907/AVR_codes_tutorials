#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void usart_init();
void txstring();
void main()
{
	usart_init();
	while(1)
	{
		txstring("WELCOME\r HOME\r");
	}
	
}
void usart_init()
{
	UCSRA|=(1<<UDRE);
	UCSRB|=(1<<TXEN);
	UBRRL=0x33;
}
void txstring(char *x)
{
	while(*x)
{
		UDR=*x;
		x++; _delay_ms(100);
	
	while((UCSRA&(1<<UDRE))==0);
}	
}