/* Trevor Hennessy
 *
 * step.c
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

int main ( void )
{
    DDRD = 0xFF;
    DDRB = 0x00;

    //int step[] = {0x03, 0x06, 0x0C, 0x09};
    int step[] = {0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09, 0x01};

    while ( 1 )
    {
        if ( PINB == 0x00 )
        {
            for ( int i = 0; i < 7; i++ )
            {
                PORTD = step[i];
                _delay_ms ( 100 );
            }
        }
        else if ( PINB == 0x01 )
        {
            for ( int i = 7; i > -1; i-- )
            {
                PORTD = step[i];
                _delay_ms ( 100 );
            }
        }
    }

    return 0;
}
