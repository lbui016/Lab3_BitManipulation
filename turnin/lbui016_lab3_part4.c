/*	Author: Liam Bui lbui016
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #4
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
	DDRB = 0xFF; PORTB = 0x00; //Configure port B's 8 pins as outputs
	DDRC = 0xFF; PORTC = 0x00; //Configure port C's 8 pins as outputs
    /* Insert your solution below */
	unsigned char tmpA = 0x00; //input
	unsigned char tmpAupper = 0x00; //upper nibble
	unsigned char tmpAlower = 0x00; //upper lower
	unsigned char tmpB = 0x00; //output
	unsigned char tmpC = 0x00; //output
    while (1) {
	tmpA = PINA; //reading PINA into tmpA
	tmpAupper = 0x00;
	tmpAlower = 0x00;
	tmpB = 0x00;
	tmpC = 0x00;

	tmpAupper = (tmpA >> 4);
	tmpAlower = (tmpA << 4);
	
	tmpB = tmpB | tmpAupper;
	tmpC = tmpC | tmpAlower;

	PORTB = tmpB;
	PORTC = tmpC;
    }
    return 1;
}
