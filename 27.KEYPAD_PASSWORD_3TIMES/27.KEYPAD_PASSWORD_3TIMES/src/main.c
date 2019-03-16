#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>
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
char s_pass[6]="12345";
char e_pass[6];
int i=0,n=0;
void keyscan(void);
void check(void);
void delay();
int main()
{
	
	init_lcd();
	while (1)
	{
		if(n<=2)
		{
			keyscan();
			cmdbreak(0x01);
			check();
			i=0;
			n++;
		}
		else
	   {
		
			lcdstring("TRY IT AGAIN");
			cmdbreak(0xc0);
			lcdstring("AFTER 30 Seconds.");
			_delay_ms(200);
			cmdbreak(0x01);
			delay();
			n=0;
		}			
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
	
	while(i<5)
	{PORTD=0x0f;
		DDRD=0xf0;
		PORTD=PORTD|(1<<5)|(1<<6)|(1<<7);
		if(!(PIND&1<<0))
		{
			lcdstring("*");
			e_pass[i]='7';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&2<<0))
		{
			lcdstring("*");
			e_pass[i]='4';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&4<<0))
		{
			lcdstring("*");
			e_pass[i]='1';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&8<<0))
	{	}
		PORTD=0x0f;
		DDRD=0xf0;
		PORTD=PORTD|(1<<4)|(1<<6)|(1<<7);
		if(!(PIND&1<<0))
		{
			lcdstring("*");
			e_pass[i]='8';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&2<<0))
		{
			lcdstring("*");
			e_pass[i]='5';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&4<<0))
		{
			lcdstring("*");
			e_pass[i]='2';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&8<<0))
		{
			lcdstring("*");
			e_pass[i]='0';
			i++;
			_delay_ms(100);
		}
		PORTD=0x0f;
		DDRD=0xf0;
		PORTD=PORTD|(1<<4)|(1<<5)|(1<<7);
		if(!(PIND&1<<0))
		{
			lcdstring("*");
			e_pass[i]='9';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&2<<0))
		{
			lcdstring("*");
			e_pass[i]='6';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&4<<0))
		{
			lcdstring("*");
			e_pass[i]='3';
			i++;
			_delay_ms(100);
		}
		else if(!(PIND&8<<0))
	{	}
	}
	e_pass[i]='\0';
	
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
void check()
{
	
	if(strcmp(e_pass,s_pass)==0)
	{
		lcdstring("PASSWORD");
		cmdbreak(0xc0);
		lcdstring("ACCEPTED");
		_delay_ms(100);
		cmdbreak(0x01);
		exit(0);
	}
	else
	{
		lcdstring("INCORRECT");
		cmdbreak(0xc0);
		lcdstring("PASSWORD");
		_delay_ms(200);
		cmdbreak(0x01);
		lcdstring("TYPE AGAIN");
		_delay_ms(100);
		cmdbreak(0x01);
	}
}
void delay()
{
	_delay_ms(5000);
	lcdstring("TYPE AGAIN");
	cmdbreak(0x01);
	
}