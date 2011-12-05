/* Trevor Hennessy
 * 
 * Pushbutton counter using modulus 8 to change the state of the bicolourLED and
 * to beep on modulus 8
 * 
 * pushB.c
 *
 */

#include <avr/io.h>
#include <util/delay.h>

#include "readSw.h"

int main ( void )
{
    int switchPress, count = 1, test;
    DDRD = 0xFF;
    DDRB = 0xF0;

    PORTB = 64; //give the bicolour led an initial state

    while ( 1 )
    {
        _delay_ms ( 500 );
        switchPress = readSw();
        
        if ( switchPress == 1 )
        {
            PORTD = count;

            test = count % 8;

            if ( test == 0 && PORTB == 128 )
            {
                PORTB = 64;
            }
            else if ( test == 0 && PORTB == 64 )
            {
                PORTB = 128;
            }

            count ++;
        }

    }
        
    return 1;
}
