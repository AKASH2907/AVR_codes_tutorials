#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define rs 0
#define rw 1
#define en 2
void init_lcd(void);
void lcdcmd(char);
void display(void);
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
		lcdcmd(0x01);	
		display();
	}
	return 0;
}
void init_lcd()
{
	DDRC=0xff; DDRD=7<<0;
	lcdcmd(0x38); lcdcmd(0x0e); lcdcmd(0x06);
	lcdcmd(0x01);
}
void display()
{
	lcdcmd(0x80); lcdstring("GABBAR SINGH");
	lcdcmd(0xc0); lcdstring("AKASH KUMAR");	
	
}
void lcdstring(char *p)
{
	while(*p!='\0')
	{
		lcddata(*p);
		p++;
		_delay_ms(100);
	}
	
}
void lcdcmd(char x)
{
	PORTC=x;
	PORTD&=~(1<<rs);  //rs=0 ==>Select Command Register
	PORTD&=~(1<<rw);  //rw=0 ==>To Write
	PORTD|=(1<<en);   //Enable is high
	_delay_ms(1);
	PORTD&=~(1<<en);  //Enable is low
	_delay_ms(2);
}
void lcddata(char x)
{
	PORTC=x;
	PORTD|=(1<<rs);   //rs=1 ==>Select Data register
	PORTD&=~(1<<rw);  //rw=0 ==>To write
	PORTD|=(1<<en);   //Enable is high
	_delay_ms(1);
	PORTD&=~(1<<en);  //Enable is low
	_delay_ms(2);
	
}