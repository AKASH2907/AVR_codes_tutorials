#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define rs 0
#define rw 1
#define en 2
void init_lcd(void);
void cmdbreak(char );
void databreak(char );
void lcdcmd(char );
void lcddata(char );
void lcdstring(char *);
void rx(void);
void usart_init(void);
int i;
int main()
{
	 usart_init();
	 init_lcd();
	while(1)
	{
		rx();
	}
	return 0;
}
void usart_init()
{
	UCSRB|=(1<<RXEN);
	UBRRL=0x33;
}
void rx()
{
	for(i=0;i<13;i++)
	{
		while((UCSRA&(1<<RXC))==0);
		lcdstring(UDR);
	}		
	cmdbreak(0xc0);
	for(i=0;i<13;i++)
	{
		while((UCSRA&(1<<RXC))==0);
		lcdstring(UDR);
	}
	
	cmdbreak(0x01);
}
void init_lcd()
{
	DDRA=0xff; 
	cmdbreak(0x02); cmdbreak(0x28); cmdbreak(0x0e); cmdbreak(0x06);
}

void lcdcmd(char x)
{
	PORTA=x;
	PORTA&=~(1<<rs);  //rs=0 ==>Select Command Register
	PORTA&=~(1<<rw);  //rw=0 ==>To Write
	PORTA|=(1<<en);   //Enable is high
	_delay_ms(1);
	PORTA&=~(1<<en);  //Enable is low
	_delay_ms(2);
}
void lcddata(char x)
{
	PORTA=x;
	PORTA|=(1<<rs);   //rs=1 ==>Select Data register
	PORTA&=~(1<<rw);  //rw=0 ==>To write
	PORTA|=(1<<en);   //Enable is high
	_delay_ms(1);
	PORTA&=~(1<<en);  //Enable is low
	_delay_ms(2);
	
}
void cmdbreak(char x)
{
	lcdcmd(x&(0xf0));
	lcdcmd((x<<4)&(0xf0));
}
void databreak(char x)
{
	lcddata(x&(0xf0));
	lcddata((x<<4)&(0xf0));
}
void lcdstring(char *x)
{
	
	while(*x)
	{
		databreak(*x);
		x++;
		_delay_ms(100);
	}
}