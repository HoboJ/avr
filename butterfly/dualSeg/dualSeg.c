/* Trevor Hennessy
 *
 * Program to scroll a word across two seven segment displays.
 *
 */

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

void reDraw ( int index1, int index2, int *hexVals );

int main ( void )
{
    DDRD = 0xFF;
    DDRB = 0xFF;

    int hexVals[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x98,0xA3,0x83,0xA7,0xA1,0x86,0x8E};

    while ( 1 )
    {
        int j = 0;

        for ( int i = 0; i <= 15; i++ )
        {
            j = i + 1;

            if ( j == 16 )
                j = 0;

            reDraw ( i, j, hexVals );
        }
    }
}

void reDraw ( int index1, int index2, int *hexVals )
{
    int count = 0;

    while ( count <= 100 )
    {
        PORTD = 1;
        PORTB = ~*( hexVals + index1 );
        _delay_ms(10);

        PORTD = 2;
        PORTB = ~*( hexVals + index2 );
        _delay_ms(10);

        count++;
    }
}
