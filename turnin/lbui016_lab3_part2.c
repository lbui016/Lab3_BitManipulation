/*	Author: Liam Bui lbui016
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #2
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
	DDRA = 0x00; PORTA = 0xFF; //Configure port A's 8 pins as inputs, intialize to 1s
	DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as outputs
    /* Insert your solution below */
	unsigned char low = 0x00; //low fuel
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
    while (1) {
	tmpA = PINA; //reading PINA into tmpA
	tmpC = 0x00; //initialize to 0x00 construct
	low = 0x00; //used for PC6

	tmpA = tmpA & 0x0F; //isolate PA3...PA0
	
	//ORs w/ tmpC based on conditions for fuels lights
	if (tmpA == 0) {
		tmpC = 0;
	}
	else if ((tmpA >= 1) && (tmpA <= 2)){
		tmpC = tmpC | 0x20;
	}
	else if ((tmpA >= 3) && (tmpA <= 4)) {
		tmpC = tmpC | 0x30;
	}
	else if ((tmpA >= 5) && (tmpA <= 6)) {
		tmpC = tmpC | 0x38;
	}
	else if ((tmpA >= 7) && (tmpA <= 9)) {
		tmpC = tmpC | 0x3C;
	}
	else if ((tmpA >= 10) && (tmpA <= 12)) {
		tmpC = tmpC | 0x3E;
	}
	else if ((tmpA >= 13) && (tmpA <= 15)) {
		tmpC = tmpC | 0x3F;
	}
	
	// low fuel light (PC6) on if tmpA <= 4
	if (tmpA <= 4) {
		low = low | 0x40;
	}

	tmpC = low | tmpC;
	PORTC = tmpC;
    }
    return 1;
}
