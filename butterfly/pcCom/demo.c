/* demon.c
 * 
 * Trevor Hennessy
 */

#include "comm.h"

void initializer ( void )
{
	// Calibrate the oscillator:
    OSCCAL_calibration ();   
	// Initialize the USART
	USARTinit ();
	
	// say hello
	sendString ( "PC_Comm.c ready to communicate.\r" );   	 
	// identify yourself specifically
	sendString ( "You are talking to the PC_Comm demo.\r" );
}

void parseInput ( char *s )
{
    if ( *( s + 0 ) == '\0' )
        s = &*( s + 1 );
    
    DDRD = 0xFF;

    unsigned char seq[] = {129,66,36,24,36,66,129};

    if ( ( strncmp ( "help", s, 4 ) ) == 0 )
    {
        sendChar ( '\r' );
        sendString ( "List of commands:\r" );
        sendChar ( '\r' );
        sendString ( "light\r" );
        sendString ( "beep\r" );
        sendString ( "seq\r" );
        sendString ( "bret\r" );
    }
    else if ( ( strncmp ( "light", s, 5 ) ) == 0 )
    {
        sendString ( "Turning on leds for approx 2 seconds\r" );

        PORTD = 0xFF;
        _delay_ms(4000);
        PORTD = 0x00;
    }
    else if ( ( strncmp ( "beep", s, 4 ) ) == 0 )
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
    else if ( ( strncmp ( "seq", s, 3 ) ) == 0 )
    {
        sendString ( "Rotating leds on PORTD\r" );

        for ( unsigned char i = 0; i < 7; i++ )
        {
            PORTD = *( seq + i );
            _delay_ms ( 1000 );
        }
        
        PORTD = 0;
    }
    else if ( ( strncmp ( "bret", s, 4 ) ) == 0 )
    {
        sendString ( "Broadcast Engineering Year 2 Microcontroller, Trevor\r" );
    }
    else
        sendString ( "Invalid command try, help\r" );
}
