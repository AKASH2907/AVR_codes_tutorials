#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#define rs 0
#define rw 1
#define en 2
void init_lcd(void);
void usart_init(void);
void lcdcmd(char );
void lcddata(char );
void databreak(char );
void cmdbreak(char );
void lcdstring(char *);
void check();
int i;
char arr[13];
void rx();
struct person 
{
	char p_name[10];
	char p_roll[5];
	char p_age[3];
	}p[3]={
		{"RAM","3831","17"},
		{"AKASH","3832","18"},
		{"NAVDEEP","3833","16"}
		};
int main()
{
	init_lcd();
	usart_init();
	while(1)
	{
		rx();
		check();
	}
	return 0;
}
void rx()
{
	for(i=0;i<13;i++)
	{
		while((UCSRA&(1<<RXC))==0);
		arr[i]=UDR;
	}
	arr[i]='\0';

}
void init_lcd()
{
	DDRA=0xff;
	cmdbreak(0x02); cmdbreak(0x28); cmdbreak(0x0e); cmdbreak(0x06);
}
void lcdcmd(char x)
{
	PORTA=x;
	PORTA&=~(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
	_delay_ms(2);
	
}
void lcddata(char x)
{
	PORTA=x;
	PORTA|=(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
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
void usart_init()
{
	UCSRB|=(1<<RXEN);	UBRRL=0X33;
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
void check()
{
	for(i=0;i<5;i++)
	{
		if(strcmp(arr,p[i].p_roll)==0)
		{
			lcdstring("WELCOME:");
			lcdstring(p[i].p_name);
			cmdbreak(0xc0);
			lcdstring("ROLLNO:");
			lcdstring(p[i].p_roll);
			lcdstring("AGE");
			lcdstring(p[i].p_age);
			_delay_ms(200);
			cmdbreak(0x01);
		}
	}
	for(i=0;i<5;i++)
	{
		if(strcmp(arr,p[i].p_roll)!=0)
		{
			lcdstring("INVALID USER");
			_delay_ms(200);
			cmdbreak(0x01);
		}
		break;
	}	
}