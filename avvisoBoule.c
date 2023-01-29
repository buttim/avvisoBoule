//!make
#include "STC15F2K60S2.h"
#include <stdbool.h>

#define _nop_() __asm nop __endasm
#define BV(x) (1<<(x))

#define FOSC                11059200UL

volatile bool f1ms,stop=false;
volatile unsigned int t=0xD4CD;

void Timer0Init(void)	{	//1ms@11.0592MHz
	AUXR |= 0x80;		//Timer clock is 1T mode
	TMOD &= 0xF0;		//Set timer work mode
	TL0 = 0xCD;		//Initial timer value
	TH0 = 0xD4;		//Initial timer value
	TF0 = 0;		//Clear TF0 flag
	TR0 = 1;		//Timer0 start run
	ET0=1;
}

void Timer2Init(void) {	//1ms@11.0592MHz
	AUXR |= 0x04;		//imer clock is 1T mode
	T2L = 0xCD;		//Initial timer value
	T2H = 0xD4;		//Initial timer value
	AUXR |= 0x10;		//Timer2 start run
	IE2|=4;//ET2=1;
}

void tm0(void) __interrupt 1 __using 1 {
	f1ms=true;
	TL0 = 0xCD;		//Initial timer value
	TH0 = 0xD4;		//Initial timer value
}

void tm2(void) __interrupt 12 __using 1 {
	T2L = t;		//Initial timer value
	T2H = t>>8;		//Initial timer value
	P10=!P10;
	P11=!P11;
}

void int0(void) __interrupt 0 __using 1 {
	stop=true;
}

void int1(void) __interrupt 2 __using 1 {
	stop=true;
}

void Delay1ms(int n) {
	while (--n) {
		f1ms = false;
		while (!f1ms);
	}
}

void main(void) {
	int i;
	
	P5M0|=BV(5);		//P5.5 in push-pull mode
	P5M1&=~BV(5);
	
	P1M0|=BV(0)|BV(1);	//P1.0 and P1.1 in push-pull mode
	P1M1&=~(BV(0)|BV(1));
	
	P10=0;
	P11=1;
	
	P3M0&=~BV(2);	//P3.2/INT0 input only
	P3M1|=BV(2);
	
	Timer0Init();
	Timer2Init();
	
	IT0 = 0;
	IT1=1;
	EX0 = 1;
	EX1=1;
	EA=1;
	P55=0;

	for (;;) {
		Delay1ms(250);
		stop=false;
		if (P32==0) {
			AUXR |= BV(4);
			for (i=0;i<30 && !stop;i++) {
				P55=1;
				t=0xD4CD;
				Delay1ms(300);
				if (stop) break;
				P55=0;
				t=0x6A66;
				Delay1ms(300);
			}
		}
		else {
			t=0xD4CD;
			for (i=0;i<3 && !stop;i++) {
				P55=1;
				AUXR |= BV(4);
				Delay1ms(100);

				P55=0;
				AUXR &= ~BV(4);
				Delay1ms(100);
			}
		}
		P55=0;
		P10=0;
		P11=0;
		AUXR &= ~BV(4);
		PCON=BV(1);	//power down
		_nop_();
		_nop_();
		P10=0;
		P11=1;
	}
}

