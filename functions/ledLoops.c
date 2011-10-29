/* Trevor Hennessy
 * Function declarations for various types of LED blinking
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


/* Loop LED's to the left with a variable delay in ms
 */

void loopLeft (int delay)
{
	//set PORTD for output
	DDRD = 0xFF;
    
		while (1) {
			
			for (int i = 1; i <= 128; i <<= 2) //loop left on the leds
			{
				PORTD = i;
				_delay_ms(delay);
			}
		}

	return;

}


/* Loop LED's to the right with a variable delay in ms
 */

void loopRight (int delay)
{
    DDRD = 0xFF;
        
        while (1) {
            
            for (int i = 128; i >= 1; i >>= 2) //loop right on the leds
            {
                PORTD = i;
                _delay_ms(delay);
            }
        }

    return;

}


/* Loop LED's to the left and then right with a variable delay in ms
 */

void loopLeftRight (int delay)
{
    DDRD = 0xFF;

        while (1) {

            for (int i = 1; i <= 128; i <<= 2)
            {
                PORTD = i;
                _delay_ms(delay);
            }

            for (int i = 128; i >= 1; i >>= 2)
            {
                PORTD = i;
                _delay_ms(delay);
            }

        }

    return;

}


/* Create an X pattern on the LED's by blinking them inwards then outwards
 */

void loopX (int delay)
{
    DDRD = 0xFF;

        while (1) {

            int left = 128;
            int right = 1;
            int i = 1;

            while (left != 1 && right != 128) {

                i = left + right;

                PORTD = i;
                _delay_ms(delay);

                left >>= 1;
                right <<= 1;

            }

        }

    return;

}
