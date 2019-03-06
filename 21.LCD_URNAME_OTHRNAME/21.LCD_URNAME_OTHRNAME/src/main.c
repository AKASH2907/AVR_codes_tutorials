#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define rs 0
#define rw 1
#define en 2
void init_lcd(void);
void lcdcmd(char);
void display1(void);
void display2(void);
void lcddata(char);
int i;
char arr1[]="GABBAR SINGH";
char arr2[]="AKASH KUMAR";
int main()
{
	int x;
	init_lcd();
	DDRA&=~(1<<0);
	while (1)
	{
		x=PINA;
		x=x&(1<<0);
		switch (x)
		{
			case 1:
			display1(); lcdcmd(0x01);	break;
			default:
			display2(); lcdcmd(0x01);
		}
	}
	return 0;
}
void init_lcd()
{
	DDRC=0xff; DDRD=7<<0;
	lcdcmd(0x38); lcdcmd(0x0e); lcdcmd(0x06);
	lcdcmd(0x01);
}
void display1()
{
	
	for(i=0;i<=15;i++)
	{
		lcddata(arr1[i]);
		_delay_ms(100);
	}		
	
}
void display2()
{
	
	for(i=0;i<=15;i++)
	{
		lcddata(arr2[i]);
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