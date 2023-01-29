#ifndef __STC15F2K60S2_H_
#define __STC15F2K60S2_H_













__sfr __at (0xE0) ACC;
__sfr __at (0xF0) B;
__sfr __at (0xD0) PSW;
__sbit __at (0xD0+7) CY;
__sbit __at (0xD0+6) AC;
__sbit __at (0xD0+5) F0;
__sbit __at (0xD0+4) RS1;
__sbit __at (0xD0+3) RS0;
__sbit __at (0xD0+2) OV;
__sbit __at (0xD0+0) P;
__sfr __at (0x81) SP;
__sfr __at (0x82) DPL;
__sfr __at (0x83) DPH;


__sfr __at (0x80) P0;
__sbit __at (0x80+0) P00;
__sbit __at (0x80+1) P01;
__sbit __at (0x80+2) P02;
__sbit __at (0x80+3) P03;
__sbit __at (0x80+4) P04;
__sbit __at (0x80+5) P05;
__sbit __at (0x80+6) P06;
__sbit __at (0x80+7) P07;
__sfr __at (0x90) P1;
__sbit __at (0x90+0) P10;
__sbit __at (0x90+1) P11;
__sbit __at (0x90+2) P12;
__sbit __at (0x90+3) P13;
__sbit __at (0x90+4) P14;
__sbit __at (0x90+5) P15;
__sbit __at (0x90+6) P16;
__sbit __at (0x90+7) P17;
__sfr __at (0xA0) P2;
__sbit __at (0xA0+0) P20;
__sbit __at (0xA0+1) P21;
__sbit __at (0xA0+2) P22;
__sbit __at (0xA0+3) P23;
__sbit __at (0xA0+4) P24;
__sbit __at (0xA0+5) P25;
__sbit __at (0xA0+6) P26;
__sbit __at (0xA0+7) P27;
__sfr __at (0xB0) P3;
__sbit __at (0xB0+0) P30;
__sbit __at (0xB0+1) P31;
__sbit __at (0xB0+2) P32;
__sbit __at (0xB0+3) P33;
__sbit __at (0xB0+4) P34;
__sbit __at (0xB0+5) P35;
__sbit __at (0xB0+6) P36;
__sbit __at (0xB0+7) P37;
__sfr __at (0xC0) P4;
__sbit __at (0xC0+0) P40;
__sbit __at (0xC0+1) P41;
__sbit __at (0xC0+2) P42;
__sbit __at (0xC0+3) P43;
__sbit __at (0xC0+4) P44;
__sbit __at (0xC0+5) P45;
__sbit __at (0xC0+6) P46;
__sbit __at (0xC0+7) P47;
__sfr __at (0xC8) P5;
__sbit __at (0xC8+0) P50;
__sbit __at (0xC8+1) P51;
__sbit __at (0xC8+2) P52;
__sbit __at (0xC8+3) P53;
__sbit __at (0xC8+4) P54;
__sbit __at (0xC8+5) P55;
__sbit __at (0xC8+6) P56;
__sbit __at (0xC8+7) P57;
__sfr __at (0xE8) P6;
__sbit __at (0xE8+0) P60;
__sbit __at (0xE8+1) P61;
__sbit __at (0xE8+2) P62;
__sbit __at (0xE8+3) P63;
__sbit __at (0xE8+4) P64;
__sbit __at (0xE8+5) P65;
__sbit __at (0xE8+6) P66;
__sbit __at (0xE8+7) P67;
__sfr __at (0xF8) P7;
__sbit __at (0xF8+0) P70;
__sbit __at (0xF8+1) P71;
__sbit __at (0xF8+2) P72;
__sbit __at (0xF8+3) P73;
__sbit __at (0xF8+4) P74;
__sbit __at (0xF8+5) P75;
__sbit __at (0xF8+6) P76;
__sbit __at (0xF8+7) P77;
__sfr __at (0x94) P0M0;
__sfr __at (0x93) P0M1;
__sfr __at (0x92) P1M0;
__sfr __at (0x91) P1M1;
__sfr __at (0x96) P2M0;
__sfr __at (0x95) P2M1;
__sfr __at (0xB2) P3M0;
__sfr __at (0xB1) P3M1;
__sfr __at (0xB4) P4M0;
__sfr __at (0xB3) P4M1;
__sfr __at (0xCA) P5M0;
__sfr __at (0xC9) P5M1;
__sfr __at (0xCC) P6M0;
__sfr __at (0xCB) P6M1;
__sfr __at (0xE2) P7M0;
__sfr __at (0xE1) P7M1;


__sfr __at (0x87) PCON;
__sfr __at (0x8E) AUXR;
__sfr __at (0xA2) AUXR1;
__sfr __at (0xA2) P_SW1;
__sfr __at (0x97) CLK_DIV;
__sfr __at (0xA1) BUS_SPEED;
__sfr __at (0x9D) P1ASF;
__sfr __at (0xBA) P_SW2;


__sfr __at (0xA8) IE;
__sbit __at (0xA8+7) EA;
__sbit __at (0xA8+6) ELVD;
__sbit __at (0xA8+5) EADC;
__sbit __at (0xA8+4) ES;
__sbit __at (0xA8+3) ET1;
__sbit __at (0xA8+2) EX1;
__sbit __at (0xA8+1) ET0;
__sbit __at (0xA8+0) EX0;
__sfr __at (0xB8) IP;
__sbit __at (0xB8+7) PPCA;
__sbit __at (0xB8+6) PLVD;
__sbit __at (0xB8+5) PADC;
__sbit __at (0xB8+4) PS;
__sbit __at (0xB8+3) PT1;
__sbit __at (0xB8+2) PX1;
__sbit __at (0xB8+1) PT0;
__sbit __at (0xB8+0) PX0;
__sfr __at (0xAF) IE2;
__sfr __at (0xB5) IP2;
__sfr __at (0x8F) INT_CLKO;


__sfr __at (0x88) TCON;
__sbit __at (0x88+7) TF1;
__sbit __at (0x88+6) TR1;
__sbit __at (0x88+5) TF0;
__sbit __at (0x88+4) TR0;
__sbit __at (0x88+3) IE1;
__sbit __at (0x88+2) IT1;
__sbit __at (0x88+1) IE0;
__sbit __at (0x88+0) IT0;
__sfr __at (0x89) TMOD;
__sfr __at (0x8A) TL0;
__sfr __at (0x8B) TL1;
__sfr __at (0x8C) TH0;
__sfr __at (0x8D) TH1;
__sfr __at (0xD1) T4T3M;
__sfr __at (0xD1) T3T4M;
__sfr __at (0xD2) T4H;
__sfr __at (0xD3) T4L;
__sfr __at (0xD4) T3H;
__sfr __at (0xD5) T3L;
__sfr __at (0xD6) T2H;
__sfr __at (0xD7) T2L;
__sfr __at (0xAA) WKTCL;
__sfr __at (0xAB) WKTCH;
__sfr __at (0xC1) WDT_CONTR;


__sfr __at (0x98) SCON;
__sbit __at (0x98+7) SM0;
__sbit __at (0x98+6) SM1;
__sbit __at (0x98+5) SM2;
__sbit __at (0x98+4) REN;
__sbit __at (0x98+3) TB8;
__sbit __at (0x98+2) RB8;
__sbit __at (0x98+1) TI;
__sbit __at (0x98+0) RI;
__sfr __at (0x99) SBUF;
__sfr __at (0x9A) S2CON;
__sfr __at (0x9B) S2BUF;
__sfr __at (0xAC) S3CON;
__sfr __at (0xAD) S3BUF;
__sfr __at (0x84) S4CON;
__sfr __at (0x85) S4BUF;
__sfr __at (0xA9) SADDR;
__sfr __at (0xB9) SADEN;


__sfr __at (0xBC) ADC_CONTR;
__sfr __at (0xBD) ADC_RES;
__sfr __at (0xBE) ADC_RESL;


__sfr __at (0xCD) SPSTAT;
__sfr __at (0xCE) SPCTL;
__sfr __at (0xCF) SPDAT;


__sfr __at (0xC2) IAP_DATA;
__sfr __at (0xC3) IAP_ADDRH;
__sfr __at (0xC4) IAP_ADDRL;
__sfr __at (0xC5) IAP_CMD;
__sfr __at (0xC6) IAP_TRIG;
__sfr __at (0xC7) IAP_CONTR;


__sfr __at (0xD8) CCON;
__sbit __at (0xD8+7) CF;
__sbit __at (0xD8+6) CR;
__sbit __at (0xD8+2) CCF2;
__sbit __at (0xD8+1) CCF1;
__sbit __at (0xD8+0) CCF0;
__sfr __at (0xD9) CMOD;
__sfr __at (0xE9) CL;
__sfr __at (0xF9) CH;
__sfr __at (0xDA) CCAPM0;
__sfr __at (0xDB) CCAPM1;
__sfr __at (0xDC) CCAPM2;
__sfr __at (0xEA) CCAP0L;
__sfr __at (0xEB) CCAP1L;
__sfr __at (0xEC) CCAP2L;
__sfr __at (0xF2) PCA_PWM0;
__sfr __at (0xF3) PCA_PWM1;
__sfr __at (0xF4) PCA_PWM2;
__sfr __at (0xFA) CCAP0H;
__sfr __at (0xFB) CCAP1H;
__sfr __at (0xFC) CCAP2H;


__sfr __at (0xE6) CMPCR1;
__sfr __at (0xE7) CMPCR2;


__sfr __at (0xf1) PWMCFG;
__sfr __at (0xf5) PWMCR;
__sfr __at (0xf6) PWMIF;
__sfr __at (0xf7) PWMFDCR;



#define PWMC (*(unsigned int volatile __xdata *)0xfff0)
#define PWMCH (*(unsigned char volatile __xdata *)0xfff0)
#define PWMCL (*(unsigned char volatile __xdata *)0xfff1)
#define PWMCKS (*(unsigned char volatile __xdata *)0xfff2)
#define PWM2T1 (*(unsigned int volatile __xdata *)0xff00)
#define PWM2T1H (*(unsigned char volatile __xdata *)0xff00)
#define PWM2T1L (*(unsigned char volatile __xdata *)0xff01)
#define PWM2T2 (*(unsigned int volatile __xdata *)0xff02)
#define PWM2T2H (*(unsigned char volatile __xdata *)0xff02)
#define PWM2T2L (*(unsigned char volatile __xdata *)0xff03)
#define PWM2CR (*(unsigned char volatile __xdata *)0xff04)
#define PWM3T1 (*(unsigned int volatile __xdata *)0xff10)
#define PWM3T1H (*(unsigned char volatile __xdata *)0xff10)
#define PWM3T1L (*(unsigned char volatile __xdata *)0xff11)
#define PWM3T2 (*(unsigned int volatile __xdata *)0xff12)
#define PWM3T2H (*(unsigned char volatile __xdata *)0xff12)
#define PWM3T2L (*(unsigned char volatile __xdata *)0xff13)
#define PWM3CR (*(unsigned char volatile __xdata *)0xff14)
#define PWM4T1 (*(unsigned int volatile __xdata *)0xff20)
#define PWM4T1H (*(unsigned char volatile __xdata *)0xff20)
#define PWM4T1L (*(unsigned char volatile __xdata *)0xff21)
#define PWM4T2 (*(unsigned int volatile __xdata *)0xff22)
#define PWM4T2H (*(unsigned char volatile __xdata *)0xff22)
#define PWM4T2L (*(unsigned char volatile __xdata *)0xff23)
#define PWM4CR (*(unsigned char volatile __xdata *)0xff24)
#define PWM5T1 (*(unsigned int volatile __xdata *)0xff30)
#define PWM5T1H (*(unsigned char volatile __xdata *)0xff30)
#define PWM5T1L (*(unsigned char volatile __xdata *)0xff31)
#define PWM5T2 (*(unsigned int volatile __xdata *)0xff32)
#define PWM5T2H (*(unsigned char volatile __xdata *)0xff32)
#define PWM5T2L (*(unsigned char volatile __xdata *)0xff33)
#define PWM5CR (*(unsigned char volatile __xdata *)0xff34)
#define PWM6T1 (*(unsigned int volatile __xdata *)0xff40)
#define PWM6T1H (*(unsigned char volatile __xdata *)0xff40)
#define PWM6T1L (*(unsigned char volatile __xdata *)0xff41)
#define PWM6T2 (*(unsigned int volatile __xdata *)0xff42)
#define PWM6T2H (*(unsigned char volatile __xdata *)0xff42)
#define PWM6T2L (*(unsigned char volatile __xdata *)0xff43)
#define PWM6CR (*(unsigned char volatile __xdata *)0xff44)
#define PWM7T1 (*(unsigned int volatile __xdata *)0xff50)
#define PWM7T1H (*(unsigned char volatile __xdata *)0xff50)
#define PWM7T1L (*(unsigned char volatile __xdata *)0xff51)
#define PWM7T2 (*(unsigned int volatile __xdata *)0xff52)
#define PWM7T2H (*(unsigned char volatile __xdata *)0xff52)
#define PWM7T2L (*(unsigned char volatile __xdata *)0xff53)
#define PWM7CR (*(unsigned char volatile __xdata *)0xff54)



#endif

