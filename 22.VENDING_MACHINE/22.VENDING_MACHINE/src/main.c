#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define rs 0
#define rw 1
#define en 2
void init_lcd(void);
void lcdcmd(char);
void lcddata(char);
void lcdstring(char*);
void motor();
void motor1();
void motor2();
void exit(int __status);
int main()
{
	int x;
	init_lcd();
	DDRA&=~(0x1f);
	DDRB=0xff;
	while (1)
	{
		x=PINA;
		
		
		if((x&(0x10)))
		{
			lcdstring("SELECT OPTIONS");
			lcdcmd(0x01);
			_delay_ms(3000);
			x=x&(0x0f);
			switch (x)
		{
			case 1:
			lcdstring("Serving Coffee"); lcdcmd(0x01);	motor();  break;
			case 2:
			lcdstring("Serving Tea"); lcdcmd(0x01);  motor();  break;
			case 3:
			lcdstring("Serving Soup"); lcdcmd(0x01);  motor();  break;
			case 4:
			lcdstring("Serving Dip Tea"); lcdcmd(0x01);  motor();  break;
		}
		}
		else if(x&(0x0f))
		{
			lcdstring("NO COIN INSERTD");
			lcdcmd(0x01);
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
void lcdstring(char *p)
{
	while(*p!=0)
	{
		lcddata(*p);
		p++;
		_delay_ms(100);
	}
}
void motor()
{
	motor1();	motor2();
	motor1();	motor2();
	motor1();   motor2();
	lcdstring("ITEM SERVED.");
	lcdcmd(0x01);
    
}
void motor1()
{
	PORTB=0x05;
	_delay_ms(700);
	PORTB=0x0a;
	_delay_ms(700);
}
void motor2()
{
	PORTB=0x50;
	_delay_ms(500);
	PORTB=0;
}	