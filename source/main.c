/*	Author: lbui016
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #pre-lab
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
	DDRB = 0xFF; PORTB = 0x00; //Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; //You are UNABLE to read from output pins. Instead you should use a temp variable for all bit manipulation
    /* Insert your solution below */
	unsigned char button = 0x00;
    while (1) {
	// 1) Read input 
	button = PINA & 0x01;
	// 2) Perform computation
	// if PA0 is 1, set PB1PB0 = 01, else = 10
	if (button == 0x01) { // True if PA0 is 1
		tmpB = (tmpB & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
					     // (clear rightmost 2 bits, then set to 01)
	}
	else {
		tmpB = (tmpB & 0xFC) | 0x02; // Sets tmpB to bbbbbb10
					     // (clear rightmost 2 bits, then set to 10)
	}
	// 3) Write output
	PORTB = tmpB; // Sets output on PORTB to valueof tmpB
    }
    return 1;
}
