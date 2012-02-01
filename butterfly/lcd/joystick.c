#include "joystick.h"

void JoyInit ( void )
{
    DDRB &= ( ~PINB_MASK );
    PORTB |= PINB_MASK;

    DDRE &= ( ~PINE_MASK );
    PORTE |= PINE_MASK;
}

char JoyGet ( void )
{
    char b = ( ( ~PINB ) & PINB_MASK );
    return b | ( ( ~PINE ) & PINE_MASK );
}
