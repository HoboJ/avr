/* cyloneyes.c
 *
 * Trevor Hennessy
 * Description: Blinks back and forth
 */

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <compat/deprecated.h>

int main (void)
{
    //declare and initialize the scroll delay_count
    unsigned long delay_count = 10000;

    //declare speed increase variable
    unsigned long increase = 0;

    //declare polarity variable
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

        delay_count = 5000 + (increase * 400); //delay_count cannot exceed 65535

        //scroll the LEDs
        for(int i = 1; i <=128; i = i*2)
        {
            if(polarity) PORTD = ~i;
            else PORTD = i;
            _delay_loop_2(delay_count);
        }

        for(int i = 128; i > 1; i -= i/2)
        {
            if(polarity) PORTD = ~i;
            else PORTD = i;
            _delay_loop_2(delay_count);
        }
    }
}
