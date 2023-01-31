//!gcc -Wall -o "%name%.exe" "%file%"
//!genEeprom | srec_cat - -binary  -output eeprom.hex -Intel
#include <stdio.h>
#include "pitches.h"
#include "furElise.h"

#define FOSC                11059200U

unsigned short timerVal(int freq) {
	return 0x10000-(FOSC/2/freq);
}

int main(int argc,char *argv[]) {
	for (int i=0;i<sizeof furElise/sizeof(*furElise);i+=2) {
		unsigned short t=0;
		if (furElise[i]!=0) 
			t=timerVal(furElise[i]);
		fwrite(&t,sizeof t,1,stdout);
		fwrite(furElise+i+1,sizeof(*furElise),1,stdout);
	}
	return 0;
}
