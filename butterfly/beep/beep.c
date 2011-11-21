#include <avr/io.h>
#include <util/delay.h>
#include <compat/deprecated.h>

#define F_CPU 1000000UL

int main ( void )
{
    char i;

    sbi(DDRB, 5);

    for ( i = 255; i > 0; i-- )
    {
        sbi(PORTB, 5);

        _delay_ms(20);

        cbi(PORTB, 5);

        _delay_ms(20);
    }

    for ( i = 255; i > 0; i-- )
    {
        sbi(PORTB, 5);

        _delay_ms(20);

        cbi(PORTB, 5);

        _delay_ms(20);
    }
    return 1;
}
