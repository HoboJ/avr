/* Trevor Hennessy
 *
 * Driving a HPDL-1414 display
 */

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

int main ( void )
{
    DDRD = 0xFF;
    DDRB = 0xFF;

    char stringMe[] = "BROADCAST ENGINEERING 2011";

    int i = 0;
    char out = '\0';

    while ( stringMe[i] )
    {
        switch ( stringMe[i] )
        {
            case '@'...'_':
                out = stringMe[i] - 0x20;
                break;
            case ' '...'?':
                out = stringMe[i] + 0x20;
                break;
        }

        PORTD = out;

        PORTB = 0x00;
        PORTB = 0xFF;
                
        i++; 
        _delay_ms(2000);
    }
    return 0;
}
