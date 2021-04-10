/*	Author: Liam Bui lbui016
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0x00; PORTD = 0xFF; //Configure port D's 8 pins as inputs, intialize to 1s
	DDRB = 0xFE; PORTB = 0x01; //Configure port B0 as input, B2, B1 as outputs
    /* Insert your solution below */
	unsigned char tmpD = 0x00; //input
	unsigned char tmpB0 = 0x00; //input
	unsigned char airbagEnabled = 0x00;
	unsigned char airbagDisabled = 0x00;
	unsigned char tmpB = 0x00; //output
    while (1) {
	tmpD = PIND; //reading PIND into tmpD
	//tmpD = tmpD << 1; //don't need most significant bit bc only checking above 70, also need to make room for B0
	tmpB0 = PINB; //input B0
	tmpB = 0x00; //output PB7...PB1
	airbagEnabled = 0x00;
	airbagDisabled = 0x00;

	if (tmpD > 127) {
		airbagEnabled = airbagEnabled | 0x02;
	}
	else if ((tmpD <= 127)) {
		tmpD = tmpD << 1;
		tmpB0 = tmpB0 & 0x01; //isolate B0
		tmpD = tmpD | tmpB0; //"9-bit" value
	
		if (tmpD >= 70) {
			airbagEnabled = airbagEnabled | 0x02;
		}
		else if (tmpD < 70) {
               		if (tmpD <= 5) { //no passenger
                        	airbagEnabled = airbagEnabled & 0x00;
                        	airbagDisabled = airbagDisabled & 0x00;
                	}
                	else if (tmpD > 5) {
                        	airbagEnabled = airbagEnabled & 0x00;
                        	airbagDisabled = airbagDisabled | 0x04;
                	}
		}
	
	}
	
	tmpB0 = 0x00; //clears tmpB0 for output
	tmpB = tmpB0 | airbagEnabled | airbagDisabled;
	PORTB = tmpB;
    }
    return 1;
}
