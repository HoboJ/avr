// portio.c
#include <avr/io.h>

int main (void)
{
    //int port pins
    DDRB = 0x00;
    DDRD = 0xFF;

    while(1)
    {
        PORTD = PINB;
    }
}
