/* Trevor Hennessy
 * 
 * Test program to check if debounce works
 *
 */

#include <avr/io.h>
#include <util/delay.h>

#include "readSw.h"

int main ( void )
{
    int switchPress, count = 0, test;
    DDRD = 0xFF;
    DDRB = 0xF0;

    while ( 1 )
    {
        _delay_ms ( 500 );
        switchPress = readSw();
        
        if ( switchPress == 1 )
        {
            PORTD = count;

            test = count % 8;

            if ( test == 0 )
            {
                PORTB = 64;
            }
            else
                PORTB = 128;

            count ++;
        }

    }
        
    return 1;
}
