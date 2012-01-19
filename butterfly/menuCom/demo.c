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
	//sendString ( "PC_Comm.c ready to communicate.\r" );   	 
	// identify yourself specifically
	//sendString ( "You are talking to the PC_Comm demo.\r" );

    sendChar ( '\r' );
    sendString ( "Menu\r" );
    sendString ( "a. Add\r" );
    sendString ( "b. Sub\r" );
    sendString ( "c. Mult\r" );
    sendString ( "d. Div\r" );
    sendChar ( '\r' );
}

void parseInput ( char *s )
{
    if ( *( s + 0 ) == '\0' )
        s = &*( s + 1 );
    int num = 0, i = 0;
    char *ptr, *temp = malloc ( sizeof(*temp) * 8 );
    memset ( temp, 0, ( sizeof(*temp) * 8 ) );

    DDRD = 0xFF;

    switch ( *( s + 0 ) )
    {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
            ptr = &*( s + 1 );
            while ( 1 )
            {
                if ( *( s + i ) == '\n' )
                {
                    *( s + i ) = '\0';
                    break;
                }
                else if ( *( s + i ) == '\r' )
                {
                    *( s + i ) = '\0';
                    break;
                }
                i++;
            }   

            num = atoi ( ptr );
            
            switch ( *( s + 0 ) )
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
                    num = ( float ) num / 2;
                    break;
            }
            
            ptr = itoa ( num, ptr, 10 );

            for ( int j = 0; j <= 8; j++ )
            {
                if ( *( ptr + j ) == '\0' )
                    *( ptr + j ) = '\r';
            }
            sendString ( ptr );

            break;
        default:
            sendString ( "ERROR: YOU SO STUPID\r" );
            break;
    }
    
    sendChar ( '\r' );
    sendString ( "Menu\r" );
    sendString ( "a. Add\r" );
    sendString ( "b. Sub\r" );
    sendString ( "c. Mult\r" );
    sendString ( "d. Div\r" );
    sendChar ( '\r' );

    free ( temp );
}
