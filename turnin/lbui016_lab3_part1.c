/*	Author: Liam Bui lbui016
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #1
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
	DDRB = 0x00; PORTB = 0xFF; //Configure port B's 8 pins as inputs, initialize to 1s
	DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as outputs
    /* Insert your solution below */
	unsigned char count = 0x00; //ones counter
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
    while (1) {
	count = 0x00;
	tmpA = PINA; //reading PINA into tmpA
	tmpB = PINB; //reading PINB into tmpB

	unsigned char i = 0; //to iterate
	for (i = 0; i < 8; ++i) {
		if ((tmpA & 0x01) == 0x01) { 
			count += 1;
		}

		if ((tmpB & 0x01) == 0x01) {
			count += 1;
		}
		tmpA = tmpA >> 1; //shift right by one to get to next pin
		tmpB = tmpB >> 1;
	}

	PORTC = count;
    }
    return 1;
}
