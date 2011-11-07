/* Trevor Hennessy
 *
 * Program to output four separate sequences to a 7 segment display.
 *
 * Uncomment the function call of the sequence you want to see on the display
 * under int main.
 */

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

void hexInc ( const int *hexVals );
void hexDec ( const int *hexVals );
void ringClock ( const int *wheel );
void ringCounter ( const int *wheel );

int main ( void )
{
    DDRD = 0xFF;
    int hexVals[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xf8,0x80,0x98,0xA3,0x83,0xA7,0xA1,0x86,0x8E};
    int wheel[] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF};

    /* Sequence #1 */
    //hexInc ( hexVals );
    
    /* Sequence #2 */
    //hexDec ( hexVals );

    /* Sequence #3 */
    //ringClock ( wheel );
    
    /* Sequence #4 */
    //ringCounter ( wheel );

    return 0;
}

/* Sequence #1 */
void hexInc ( const int *hexVals )
{
    int increment = 0;

    while ( 1 )
    {
        PORTD = *( hexVals + increment );
        _delay_ms(2000);

        increment ++;

        if ( increment == 16 )
            increment = 0;
    }
    return;
}

/* Sequence #2 */
void hexDec ( const int *hexVals ) 
{
    int decrement = 15;

    while ( 1 )
    {
        PORTD = *( hexVals + decrement );
        _delay_ms(2000);

        decrement--;

        if ( decrement == -1 )
            decrement = 15;
    }
    return;
}

/* Sequence #3 */
void ringClock ( const int *wheel )
{
    int inc = 0;

    while ( 1 )
    {
        PORTD = *( wheel + inc );
        _delay_ms(2000);

        inc++;

        if ( inc == 6 )
            inc = 0;
    }
    return;
}

/* Sequence #4 */
void ringCounter ( const int *wheel )
{
    int dec = 5;

    PORTD = *( wheel + 0 );
    _delay_ms(2000);

    while ( 1 )
    {
        PORTD = *( wheel + dec );
        _delay_ms(2000);

        dec--;

        if ( dec == -1 )
            dec = 5;
    }
    return;
}
