// demon.c CommDemo version

#include "comm.h"

void initializer()
{
	// Calibrate the oscillator:
    OSCCAL_calibration();   
	// Initialize the USART
	USARTinit();
	
	// say hello
	sendString("PC_Comm.c ready to communicate.\n");   	 
	// identify yourself specifically
	sendString("You are talking to the PC_Comm demo.\n");
}

void parseInput(char *s)
{
    if ( ( strcmp ( "help\n", s ) ) == 0 )
    {
        sendString ( "derpderp\n" );
    }
    else if ( ( strcmp ( "light\n", s ) ) == 0 )
    {
        DDRD = 0xFF;
        PORTD = 0xFF;
        _delay_ms(8000);
        PORTD = 0x00;
    }
    else
        sendString ( "welp\n" );
}
