/* Trevor Hennessy
 *
 * sequences.c
 *
 * Display Sequences
 */

#include <avr/io.h>
#include <util/delay.h>

void seq4 ( const int *seq4 );

int main (void)
{
    DDRD = 0xFF;

    int sequence4[] = {129,66,36,24,36,66,129};

    seq4 ( sequence4 );
}

void seq4 ( const int *seq4 )
{
    int count = 0;

    while ( 1 )
    {
        PORTD = *( seq4 + count );
        _delay_ms(2000);

        count++;

        if ( count == 7 )
        {
            count = 0;
        }
    }
    return;
}
