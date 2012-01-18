/* demo.c
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
    int num = 0, i = 0, *ptr;
    char *temp = malloc ( sizeof(*temp) * 8 );
    memset ( temp, 0, ( sizeof(*temp) * 8 ) );

    DDRD = 0xFF;

    if ( ( strncmp ( "help", s, 4 ) ) == 0 )
    {
        sendChar ( '\r' );
        sendString ( "List of commands:\r" );
        sendChar ( '\r' );
        sendString ( "comma - add 10\r" );
        sendString ( "commb - sub 20\r" );
        sendString ( "commc - mult 2\r" );
        sendString ( "commd - div 2\r" );
    }
    else if ( ( strncmp ( "comm", s, 4 ) ) == 0 )
    {
        ptr = &*( s + 5 );
        while ( 1 )
        {
            if ( *( s + i ) == '\n' )
            {
                *( s + i ) == '\0';
                break;
            }
            else if ( *( s + i ) == '\r' )
            {
                *( s + i ) == '\0';
                break;
            }
            i++;
        }

        num = atoi ( ptr );

        switch ( *( s + 4 ) )
        {
            case 'a':
                num = num + 10;
                break;
            case 'b':
                num = num - 20;
                break;
            case 'c':
                num = num * 2;
                break;
            case 'd':
                num = num / 2;
                break;
            default:
                sendString ( "You done goofed\r" );
        }

        PORTD = num;
    }
    else
        sendString ( "Invalid command try, help\r" );
}
