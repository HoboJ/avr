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

    PORTD = 0;

    while ( 1 )
    {
        if ( PINB == 0 )
        {
            for ( uint8_t i = 0; i < 100; i++ )
            {
                PORTD = 1;
                PORTD = 0;
                _delay_ms ( 50 );
            }
        }
    }

    return 0;
}
