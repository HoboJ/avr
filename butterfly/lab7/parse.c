/* parse.c
 * 
 * Reuseable code for parsing and manipulating strings for smpte 
 * timecode manipulation
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
	
    menu ();
}

void menu ( void )
{
    sendChar ( '\r' );
    sendString ( "Enter smpte timecodes\r" );
    sendString ( "XX:XX:XX:XX" );
    sendChar ( '\r' );
}

/* convert a smpte format string into the total frames 
 * format being hours:minutes:seconds:frames
 */
long parseInput ( char *s )
{
    if ( *( s + 0 ) == '\0' )
        s = &*( s + 1 );

    long result;
    uint8_t count = 0;
    char *opt;

    while ( opt != NULL )
    {
        opt = strtok ( s, ":" );
        
        if ( count == 0 )
            result = ( atol ( opt ) * 3600 );
        else if ( count == 1 )
            result = result + ( atol ( opt ) * 60 );
        else if ( count == 2 )
            result = result + ( atol ( opt ) );
        else if ( count == 3 )
            result = ( result * 30 ) + ( atol ( opt ) );

        s = NULL;
        count++;
    }

    return result;
}

/* Converts frames back into smpte timecode format
 * XX:XX:XX:XX being the correct format
 */
void revert ( long res, char *buffer )
{
    uint8_t i;
    /* array to contain the complete smpte timecode
     * string
     */
    char *cstring = malloc ( sizeof(*cstring) * 14 );
    memset ( cstring, 0, ( sizeof(*cstring) * 14 ) );

    /* two dimensional array of pointers to pointers 
     * for the "substrings" of the smpte string
     */
    char **tmp = malloc ( sizeof(*tmp) * 4 );
    for ( i = 0; i < 4; i++ )
        *( tmp + i ) = malloc ( sizeof(*tmp) * 4 );

    ltoa ( ( res % 30 ), *( tmp + 3 ), 10 );
    res = res / 30;
    ltoa ( ( res % 60 ), *( tmp + 2 ), 10 );
    res = res / 60;
    ltoa ( ( res % 60 ), *( tmp + 1 ), 10 );
    ltoa ( ( res / 60 ), *( tmp + 0 ), 10 );

    /* Recreate the whole string using the "substrings"
     * and strcat()
     */
    for ( i = 0; i < 4; i++ )
    {
        strcat ( cstring, *( tmp + i ) );
        if ( i != 3 )
            strcat ( cstring, ":" );
    }

    sendString ( "Result\r" );
    sendString ( cstring );
    sendChar ( '\r' );

    for ( i = 0; i < 4; i++ )
        free ( *( tmp + i ) );
    free ( tmp );
    free ( cstring );
}
