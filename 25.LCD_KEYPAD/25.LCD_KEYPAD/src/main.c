#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define rs 0
#define rw 1
#define en 2
void init_lcd(void);
void cmdbreak(char);
void display(void);
void databreak(char);
void lcdcmd(char);
void lcddata(char);
void lcdstring(char*);
int i;
void keyscan();
int main()
{
	
	init_lcd();
	DDRA&=~(1<<0);
	while (1)
	{
		cmdbreak(0x01);
		keyscan();
	}
	return 0;
}
void init_lcd()
{
	DDRC=0xff; DDRD=7<<0;
	cmdbreak(0x02); cmdbreak(0x28); cmdbreak(0x0e); cmdbreak(0x06);	cmdbreak(0x01);
}
void keyscan()
{
	PORTD=0x0f;
	DDRD=0xf0;
	PORTD=PORTD|(1<<5)|(1<<6)|(1<<7);
	if(!(PIND&1<<0))
	lcdstring("Key 7 is pressed");
	if(!(PIND&2<<0))
	lcdstring("Key 4 is pressed");
	if(!(PIND&4<<0))
	lcdstring("Key 1 is pressed");
	if(!(PIND&8<<0))
	lcdstring("Key ON is pressed");
	PORTD=0x0f;
	DDRD=0xf0;
	PORTD=PORTD|(1<<4)|(1<<6)|(1<<7);
	if(!(PIND&1<<0))
	lcdstring("Key 8 is pressed");
	if(!(PIND&2<<0))
	lcdstring("Key 5 is pressed");
	if(!(PIND&4<<0))
	lcdstring("Key 2 is pressed");
	if(!(PIND&8<<0))
	lcdstring("Key 0 is pressed");
	PORTD=0x0f;
	DDRD=0xf0;
	PORTD=PORTD|(1<<4)|(1<<5)|(1<<7);
	if(!(PIND&1<<0))
	lcdstring("Key 9 is pressed");
	if(!(PIND&2<<0))
	lcdstring("Key 6 is pressed");
	if(!(PIND&4<<0))
	lcdstring("Key 3 is pressed");
	if(!(PIND&8<<0))
	lcdstring("Key = is pressed");
	PORTD=0x0f;
	DDRD=0xf0;
	PORTD=PORTD|(1<<4)|(1<<5)|(1<<6);
	if(!(PIND&1<<0))
	lcdstring("Key / is pressed");
	if(!(PIND&2<<0))
	lcdstring("Key x is pressed");
	if(!(PIND&4<<0))
	lcdstring("Key - is pressed");
	if(!(PIND&8<<0))
	lcdstring("Key + is pressed");
	
	
}
void lcdstring(char *p)
{
	while(*p!=0)
	{
		databreak(*p);
		p++;
		_delay_ms(100);
	}
}
void lcdcmd(char x)
{
	PORTC=x;
	PORTC&=~(1<<rs);  //rs=0 ==>Select Command Register
	PORTC&=~(1<<rw);  //rw=0 ==>To Write
	PORTC|=(1<<en);   //Enable is high
	_delay_ms(1);
	PORTC&=~(1<<en);  //Enable is low
	_delay_ms(2);
}
void lcddata(char x)
{
	PORTC=x;
	PORTC|=(1<<rs);   //rs=1 ==>Select Data register
	PORTC&=~(1<<rw);  //rw=0 ==>To write
	PORTC|=(1<<en);   //Enable is high
	_delay_ms(1);
	PORTC&=~(1<<en);  //Enable is low
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