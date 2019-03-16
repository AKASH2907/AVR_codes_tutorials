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
void lcdstring(char *);
int i;
//char a[]="GABBAR SINGH"; char b[]="AKASH KUMAR";
int main()
{
	
	init_lcd();
	DDRA&=~(1<<0);
	while (1)
	{
		cmdbreak(0x01);
		display();
	}
	return 0;
}
void init_lcd()
{
	DDRC=0xff; DDRD=7<<0;
	cmdbreak(0x02); cmdbreak(0x28); cmdbreak(0x0e); cmdbreak(0x06);	cmdbreak(0x01);
}
void display()
{
	cmdbreak(0x80); lcdstring("GABBAR SINGH");
	cmdbreak(0xc0); lcdstring("AKASH KUMAR");	
}
void lcdstring(char *p)
{
	while(*p!='\0')
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