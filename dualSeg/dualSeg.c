/* Trevor Hennessy
 *
 * Program to scroll a word across two seven segment displays.
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

int main ( void )
{
    DDRD = 0xFF;
    DDRB = 0xFF;

    int hexVals[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x98,0xA3,0x83,0xA7,0xA1,0x86,0x8E};

    while ( 1 )
    {
        for ( int i = 15; i >= 0; i-- )
        {
            int count = 0;

            while ( count <= 60 )
            {
                PORTB = 2;
                PORTD = ~hexVals[i];
                _delay_ms(8);

                if ( i < 15 )
                {
                    PORTB = 1;
                    PORTD = ~hexVals[i - 1];
                    _delay_ms(8);
                }
                count++;
            }
        }
    }
}
