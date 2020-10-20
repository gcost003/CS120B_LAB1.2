/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A0
    unsigned char tmpA1 = 0x00; // Temporary variable to hold the value of A1
    unsigned char tmpB = 0x00;
while(1) {
        // 1) Read input
        tmpA0 = PINA & 0x01;  
	tmpA1 = PINA & 0x02;  
        // 2) Perform computation   
        if ((tmpA0 == 0x01) && (tmpA1 == 0x02)) { // True if both sensor is on
            tmpB = 0x00; 			 // LED is off
        }
       	else if ((tmpA0 == 0x00) && (tmpA1 == 0x02)) {  //if light is detected while garage is closed
		tmpB = 0x00;                             //then LED is off  
        }
    	else if ((tmpA0 == 0x01) && (tmpA1 == 0x00)){   //if Garage door is open while no light
		tmpB = 0x00;				//then LED is off
	}	
	else{ //else if both are off then LED is off
		tmpB = 0x00;  
	}	
    	// 3) Write output
	PORTB = tmpB;    
    }
    return 0;
}
