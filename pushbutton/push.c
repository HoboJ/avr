/* Trevor Hennessy
 * 
 * Test program to check if debounce works
 *
 */

#include <avr/io.h>
#include <util/delay.h>

#include "pSw.h"

int main ( void )
{
    int switchPress[] = { 0,0,0,0,0,0,0,0 };
    //int count = 0;
    
    DDRD = 0xFF;

    while ( 1 )
    {

        _delay_ms ( 500 );
        pSw ( switchPress );

        if ( *( switchPress + 4) == 1 )
            PORTD = 24;
        else if ( *( switchPress + 2 ) == 1 )
            PORTD = 64;
        else
            PORTD = 129;

    }
    return 1;
}
