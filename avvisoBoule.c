//!make
#include "STC15F2K60S2.h"
#include <stdbool.h>
#include <stdint.h>

#define _nop_() __asm nop __endasm
#define BV(x) (1<<(x))

#define FOSC		11059200U
#define ENABLE_IAP  	0x82	//if SYSCLK<20MHz
#define CMD_READ    	1

#define LED		P55
#define SENSOR		P32	//INT0
#define BUTTON		P33	//INT1
#define BUZZER_PLUS	P10
#define BUZZER_MINUS	P11

volatile bool f1ms,stop=false;
unsigned short tVal;
bool firstRun=true;
int nSongs;

void IapIdle() {
    IAP_CONTR = 0;
    IAP_CMD = 0;
    IAP_TRIG = 0;
    IAP_ADDRH = 0x80;
    IAP_ADDRL = 0;
}

uint8_t IapReadByte(uint16_t addr) {
    uint8_t dat;

    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = CMD_READ;
    IAP_ADDRL = addr;
    IAP_ADDRH = addr >> 8;
    IAP_TRIG = 0x5a;
    IAP_TRIG = 0xa5;
    _nop_();
    dat = IAP_DATA;
    IapIdle();
    return dat;
}

uint16_t IapReadWord(uint16_t addr) {
	return IapReadByte(addr)+256*IapReadByte(addr+1);
}

void Timer0Init(void)	{	//1ms@11.0592MHz
	AUXR|=0x80;		//Timer clock is 1T mode
	TMOD&=0xF0;		//Set timer work mode
	TL0=0xCD;		//Initial timer value
	TH0=0xD4;		//Initial timer value
	TF0=0;			//Clear TF0 flag
	TR0=1;			//Timer0 start run
	ET0=1;
}

void Timer2Init(void) {
	AUXR|=0x04;		//timer clock is 1T mode
	IE2|=4;			//enable interrupt for timer 2
}

void tm0(void) __interrupt 1 __using 1 {
	f1ms=true;
	TL0=0xCD;		//Initial timer value
	TH0=0xD4;		//Initial timer value
}

void tm2(void) __interrupt 12 __using 1 {
	T2L=tVal;
	T2H=tVal>>8;
	BUZZER_MINUS^=1;
	BUZZER_PLUS^=1;
}

void int0(void) __interrupt 0 __using 1 {}

void int1(void) __interrupt 2 __using 1 {
	stop=true;
}

void Delay1ms(int n) {
	while (n--) {
		f1ms=false;
		while (!f1ms);
	}
}

bool light() {				//debounce reading from sensor LED
	int i,val=0;
	for (i=0;i<25;i++) {
		val=(8+val*15+SENSOR*16)>>4;
		Delay1ms(1);
	}
	return val>5;
}

void play(int n,bool ignoreStop) {
	int i=IapReadWord(2+2*n);
	while (ignoreStop || !stop) {
		uint16_t t=IapReadWord(i),
			duration=IapReadWord(i+2);
		if (duration==0) break;
		if (t!=0) {
			tVal=t;
			AUXR|=BV(4);
			LED=1;
		}
		Delay1ms(duration);
		AUXR&=~BV(4);
		LED=0;
		Delay1ms(50);
		if (!ignoreStop && light()) break;
		i+=4;
	}
}

void main(void) {
	static int i;
	
	P5M0|=BV(5);			//P5.5 in push-pull mode
	P5M1&=~BV(5);
	LED=0;
	
	P1M0|=BV(0)|BV(1);		//P1.0 and P1.1 in push-pull mode
	P1M1&=~(BV(0)|BV(1));	
	BUZZER_MINUS=0;
	BUZZER_PLUS=1;
	
	P3M0&=~BV(2);			//P3.2/INT0 input only
	P3M1|=BV(2);
	
	Timer0Init();
	Timer2Init();
	
	IT0=0;				//INT0 on both edges
	IT1=1;				//INT1 on falling edge
	EX0=1;				//INT0 enable
	EX1=1;				//INT1 enable
	EA=1;				//enable interrupts
	
	nSongs=IapReadWord(0);
	
	play(0,true);
	
	for (;;) {
		Delay1ms(200);		//wait for signal to stabilize
		if (!light()) {
			if (!firstRun) {
				stop=false;
				LED=1;
				int n=T2L^T2H;
				while (n>=nSongs-1) n-=nSongs-1; //modulo without division (too much code bloat)
				play(n,false);
			}
		}
		else {
			firstRun=false;
			LED=0;
			play(0,true);	//shave and a haircut...
		}
		EX1=0;			//INT1 disable
		LED=0;
		BUZZER_MINUS=0;
		BUZZER_PLUS=0;
		AUXR&=~BV(4);
		PCON=BV(1);		//power down
		_nop_();
		_nop_();
		BUZZER_MINUS=0;
		BUZZER_PLUS=1;
		EX1=1;			//INT1 enable
	}
}

