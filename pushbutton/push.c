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
    int switchPress;
    int count = 0;
    
    DDRD = 0xFF;

    while ( 1 )
    {

        _delay_ms ( 500 );
        switchPress = readSw();

        if ( switchPress == 1 )
        {
            count++;
            PORTD = count;
        }
        
    }
    return 1;
}
