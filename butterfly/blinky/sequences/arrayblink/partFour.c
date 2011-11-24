/* Trevor Hennessy
 *
 * sequences.c
 *
 * Display Sequences
 */

#include <avr/io.h>
#include <util/delay.h>

void seq1 ( const int *seq1 );
void seq2 ( const int *seq2 );
void seq3 ( const int *seq3 );
void seq4 ( const int *seq4 );

int main (void)
{
    DDRD = 0xFF;

    int sequence1[] = {1,4,16,64};
    int sequence2[] = {128,32,8,2};
    int sequence3[] = {1,4,16,64,128,32,8,2};
    int sequence4[] = {129,66,36,24,36,66,129};

    seq1 ( sequence1 );

    //seq2 ( sequence2 );

    //seq3 ( sequence3 );

    //seq4 ( sequence4 );

        
}

void seq1 ( const int *seq1 )
{
    int count = 0;

    while ( 1 )
    {
        PORTD = *( seq1 + count );
        _delay_ms(2000);

        count++;

        if ( count == 4 )
            count = 0;
    }
    return;
}

void seq2 ( const int *seq2 )
{
    int count = 0;

    while ( 1 )
    {
        PORTD = *( seq2 + count );
        _delay_ms(2000);

        count++;

        if ( count == 4 )
            count = 0;
    }
    return;
}

void seq3 ( const int *seq3 )
{
    int count = 0;

    while ( 1 )
    {

        PORTD = *( seq3 + count );
        _delay_ms(2000);

        count++;

        if ( count == 8 )
        {
            count = 0;
        }
    }
    return;
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
