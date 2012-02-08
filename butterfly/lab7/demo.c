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
    sendString ( "Add\r" );
    sendString ( "Sub\r" );
    sendString ( "Mult\r" );
    sendString ( "idiv (Integer division)\r" );
    sendString ( "ddiv (Decimal division)\r" );
    sendChar ( '\r' );
}

void parseInput ( char *s )
{
    if ( *( s + 0 ) == '\0' )
        s = &*( s + 1 );

    long num1, num2;
    unsigned char i = 0;
    char *ptr, *temp = malloc ( sizeof(*temp) * 18 );
    memset ( temp, 0, ( sizeof(*temp) * 18 ) );

    if ( ( strncmp ( "add", s, 3 ) ) == 0 )
    {
        num1 = getNum ();
        num2 = getNum ();
        ptr = ltoa ( (num1 + num2), temp, 10 );
    }
    else if ( ( strncmp ( "sub", s, 3 ) ) == 0 )
    {
        num1 = getNum ();
        num2 = getNum ();
        ptr = ltoa ( (num1 - num2), temp, 10 );
    }
    else if ( ( strncmp ( "mult", s, 4 ) ) == 0 )
    {
        num1 = getNum ();
        num2 = getNum ();
        ptr = ltoa ( (num1 * num2), temp, 10 );
    }
    else if ( ( strncmp ( "idiv", s, 4 ) ) == 0 )
    {
        num1 = getNum ();
        num2 = getNum ();
        ptr = ltoa ( (num1 / num2), temp, 10 );
    }
    else if ( ( strncmp ( "ddiv", s, 4 ) ) == 0 )
    {
        num1 = getNum ();
        num2 = getNum ();
        num1 = num1 * 1000;
        ptr = ltoa ( (num1 / num2), temp, 10 );

        while ( i < 18 )
        {
            if ( *( ptr + i ) == '\0' )
            {
                for ( int j = i; j > ( i - 3 ); j-- )
                {
                    *( ptr + j ) = *( ptr + (j - 1) );
                }
                *( ptr + ( i - 3 ) ) = '.';
                *( ptr + ( i + 1 ) ) = '\0';
                break;
            }
            i++;
        }
    }
    else
        sendString ( "ERROR: YOU SO STUPID\7\r" );

    switch ( *( s + 0 ) )
    {
        case 'a':
        case 's':
        case 'm':
        case 'i':
        case 'd':
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
