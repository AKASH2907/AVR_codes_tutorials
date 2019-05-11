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
int i=0;
void keyscan(void);
void p_check(void);
void id_check(void);
void motor(void);
void card(void);
void usart_init(void);
char a[5];
char id[]="69P9";
void card();
void exit(int __status);
int main()
{
	usart_init();
	init_lcd();
	while (1)
	{
		lcdstring("ENTER PASSWORD");
		_delay_ms(200);
		cmdbreak(0x01);
		keyscan();
		cmdbreak(0x01);
		p_check();
		i=0;
	}
	
	return 0;
}
void usart_init()
{
	UCSRB|=(1<<RXEN); UBRRL=0x33;
}
void init_lcd()
{
	DDRA=0xff; 
	cmdbreak(0x02); cmdbreak(0x28); cmdbreak(0x0e); cmdbreak(0x06);	cmdbreak(0x01);
}
void keyscan()
{
	
	while(i<5)
	{PORTC=0x0f;
		DDRC=0xf0;
		PORTC|=(1<<5)|(1<<6)|(1<<7);
		if(!(PINC&1<<0))
		{
			lcdstring("*");
			e_pass[i]='7';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&2<<0))
		{
			lcdstring("*");
			e_pass[i]='4';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&4<<0))
		{
			lcdstring("*");
			e_pass[i]='1';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&8<<0))
	{	}
		PORTC=0x0f;
		DDRC=0xf0;
		PORTC=PORTC|(1<<4)|(1<<6)|(1<<7);
		if(!(PINC&1<<0))
		{
			lcdstring("*");
			e_pass[i]='8';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&2<<0))
		{
			lcdstring("*");
			e_pass[i]='5';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&4<<0))
		{
			lcdstring("*");
			e_pass[i]='2';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&8<<0))
		{
			lcdstring("*");
			e_pass[i]='0';
			i++;
			_delay_ms(100);
		}
		PORTC=0x0f;
		DDRC=0xf0;
		PORTC=PORTC|(1<<4)|(1<<5)|(1<<7);
		if(!(PINC&1<<0))
		{
			lcdstring("*");
			e_pass[i]='9';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&2<<0))
		{
			lcdstring("*");
			e_pass[i]='6';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&4<<0))
		{
			lcdstring("*");
			e_pass[i]='3';
			i++;
			_delay_ms(100);
		}
		else if(!(PINC&8<<0))
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
void motor()
{
	DDRB|=0x0f;
	PORTB|=0x05;
	_delay_ms(700);
	PORTB|=0x0a;
	_delay_ms(700);
	
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
void p_check()
{
	
	if(strcmp(e_pass,s_pass)==0)
	{
		lcdstring("SHOW YOUR");
		cmdbreak(0xc0);
		lcdstring("ID CARD");
		_delay_ms(100);
		cmdbreak(0x01);
		card();
		
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
void id_check()
{
	if(strcmp(a,id)==0)
	{
		lcdstring("HOME SWEET");
		cmdbreak(0xc0);
		lcdstring("HOME");
	    cmdbreak(0x01);
		motor();
		
	}
	
}
void card()
{
	for(i=0;i<4;i++)
	{
		while((UCSRA&(1<<RXC))==0);
		a[i]=UDR;
	}
	id_check();
}