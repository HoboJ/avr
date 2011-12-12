/* joystick.c
 *
 * Trevor Hennessy
 *
 * Description: displays one of three sequences based upon which way you hit the joystick
 */

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#define BUTTON_B ( 7 )  //DOWN
#define BUTTON_A ( 6 )  //UP
#define BUTTON_O ( 4 )  //PUSH
#define BUTTON_D ( 3 )  //RIGHT
#define BUTTON C ( 2 )  //LEFT

#define PINB_MASK ( ( 1 << PINB7 ) | ( 1 << PINB6 ) | ( 1 << PINB4 ) )
#define PINE_MASK ( ( 1 << PINE3 ) | ( 1 << PINE2 ) )

void up ( void );
void down ( void );
void pDown ( void );

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

int main ( void )
{
    unsigned char test;

    DDRD = 0xFF;

    PORTD = 254;

    JoyInit ();

    PORTD = 255;

    for ( ;; )
    {
        test = JoyGet ();

        if ( (test & 128) == 128 )
            up ();
        else if ( (test & 64) == 64 )
            down ();
        else if ( (test & 16) == 16 )
            pDown ();
    }

    return 0;
}

void up ( void )
{
    int up [] = {161, 171};

    for ( int i = 0; i < 2; i++ )
    {
        PORTD = *( up + i );
        _delay_ms ( 2000 );
    }
    PORTD = 255;
}

void down ( void )
{
    int down [] = {227, 140};

    for ( int i = 0; i < 2; i++ )
    {
        PORTD = *( down + i );
        _delay_ms ( 2000 );
    }
    PORTD = 255;
}

void pDown ( void )
{
    int pDown [] = {140, 161, 171};

    for ( int i = 0; i < 3; i++ )
    {
        PORTD = *( pDown + i );
        _delay_ms ( 2000 );
    }
    PORTD = 255;
}
