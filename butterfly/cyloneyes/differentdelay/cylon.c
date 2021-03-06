/* cylon.c
 *
 * Trevor Hennessy
 * Description: Blinks back and forth
 */

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main (void)
{
    unsigned long delay_count = 10000;

    unsigned long increase = 0;

    unsigned char polarity = 0;
    
    //init port pins
    DDRB = 0x00; //set port B pins for input
    DDRD = 0xFF; //set port D pins for output

    while(1)
    {
        // read the switches
        increase = PINB;
        
        //set the polarity
        if(increase > 127) //aka pin 1 is set on
        {
            increase -= 127;
            polarity = 1;
        }
        else polarity = 0;

        delay_count = 50 + (increase * 10); //delay_count is in ms

        //scroll the LEDs
        for(int i = 1; i <=128; i = i*2)
        {
            if(polarity) PORTD = ~i;
            else PORTD = i;
            _delay_ms(delay_count);
        }

        for(int i = 128; i > 1; i -= i/2)
        {
            if(polarity) PORTD = ~i;
            else PORTD = i;
            _delay_ms(delay_count);
        }
    }
}
