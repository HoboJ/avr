/* Trevor Hennessy
 *
 * Function for detecting if the pushbutton has
 * been pressed.
 */

#include <avr/io.h>
#include <util/delay.h>

int readSw ( void )
{
    int readSw, count = 0;
    int switchPress, stillPressed = 1;

    DDRB = 0x00;

    do
    {
        readSw = ~PINB & 0x01;
        
        if ( readSw == 1 )
        {
            count++;
            switchPress = 1;
        }
        else
            switchPress = 0;

        _delay_ms ( 10 );
        
    }
    while ( count <= 4 );

    return switchPress;

}
