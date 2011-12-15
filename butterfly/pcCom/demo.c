// demon.c CommDemo version

#include "comm.h"

void initializer ( void )
{
	// Calibrate the oscillator:
    OSCCAL_calibration ();   
	// Initialize the USART
	USARTinit ();
	
	// say hello
	sendString ( "PC_Comm.c ready to communicate.\n" );   	 
	// identify yourself specifically
	sendString ( "You are talking to the PC_Comm demo.\n" );
}

void parseInput ( char *s )
{
    if ( *( s + 0 ) == '\0' )
        s = &*( s + 1 );

    DDRD = 0xFF;

    unsigned char seq[] = {129,66,36,24,36,66,129};

    if ( ( strncmp ( "help\n", s, 6 ) ) == 0 )
    {
        sendChar ( '\n' );
        sendString ( "List of commands:\n" );
        sendChar ( '\n' );
        sendString ( "light\n" );
        sendString ( "beep\n" );
        sendString ( "seq\n" );
    }
    else if ( ( strncmp ( "light\n", s, 6 ) ) == 0 )
    {
        sendString ( "Turning on leds for approx 2 seconds\n" );

        PORTD = 0xFF;
        _delay_ms(4000);
        PORTD = 0x00;
    }
    else if ( ( strncmp ( "beep\n", s, 6 ) ) == 0 )
    {
        DDRB = 0xFF;

        for ( unsigned char i = 500; i > 0; i-- )
        {
            sbi ( PORTB, 5 );
            _delay_ms ( 1 );
            cbi ( PORTB, 5 );
            _delay_ms ( 1 );
        }
    }
    else if ( ( strncmp ( "seq\n", s, 5 ) ) == 0 )
    {
        sendString ( "Rotating leds on PORTD\n" );

        for ( unsigned char i = 0; i < 7; i++ )
        {
            PORTD = *( seq + i );
            _delay_ms ( 1000 );
        }
        
        PORTD = 0;
    }
    else
        sendString ( "Invalid command try, help\n" );
}
