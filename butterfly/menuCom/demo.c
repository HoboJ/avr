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

    menu ();
}

void menu ( void )
{
    sendChar ( '\r' );
    sendString ( "Menu\r" );
    sendString ( "a. Add\r" );
    sendString ( "b. Sub\r" );
    sendString ( "c. Mult\r" );
    sendString ( "d. Integer division\r" );
    sendString ( "e. Decimal division\r" );
    sendChar ( '\r' );
}

void parseInput ( char *s )
{
    if ( *( s + 0 ) == '\0' )
        s = &*( s + 1 );

    int num1, num2;
    unsigned char i = 0;
    char *ptr, *temp = malloc ( sizeof(*temp) * 18 );
    memset ( temp, 0, ( sizeof(*temp) * 18 ) );

    switch ( *( s + 0 ) )
    {
        case 'a':
            num1 = getNum ();
            num2 = getNum ();
            ptr = itoa ( (num1 + num2), temp, 10 );
            break;
        case 'b':
            num1 = getNum ();
            num2 = getNum ();
            ptr = itoa ( (num1 - num2), temp, 10 );
            break;
        case 'c':
            num1 = getNum ();
            num2 = getNum ();
            ptr = itoa ( (num1 * num2), temp, 10 );
            break;
        case 'd':
            num1 = getNum ();
            num2 = getNum ();
            ptr = itoa ( (num1 / num2), temp, 10 );
            break;
        case 'e':
            num1 = getNum ();
            num2 = getNum ();
            num1 = num1 * 100;
            ptr = itoa ( (num1 / num2), temp, 10 );
                
                while ( 1 )
                {
                    if ( *( ptr + i ) == '\0' )
                    {
                        for ( int j = i; j > ( i - 2 ); j-- )
                        {
                            *( ptr + j ) = *( ptr + (j - 1) );
                        }
                        *( ptr + ( i - 2 ) ) = '.';
                        *( ptr + ( i + 1 ) ) = '\0';
                        break;
                    }
                    i++;
                }

            break;
        default:
            sendString ( "ERROR: YOU SO STUPID\r" );
            break;
    }

    switch ( *( s + 0 ) )
    {
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
            sendString ( "Result: " );
            sendString ( ptr );
            break;
    }
    
    sendChar ( '\r' );

    free ( temp );
}

int getNum ( void )
{
    int num;
    unsigned char i = 0;
    char *s = malloc ( sizeof(*s) * MAX_STR_LEN );
    void *f;
    memset ( s, 0, ( sizeof(*s) * MAX_STR_LEN ) );

    sendString ( "Input a number:\r" );

    getString ( s, f );

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

    num = atoi ( s );

    free ( s );

    return num;
}
