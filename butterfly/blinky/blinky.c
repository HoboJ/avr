/* blinky.c
 *
 * Description: Blinks left then right using bitwise operators
 * Trevor Hennessy
 */

#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	//set PORTD for output
	DDRD = 0xFF;
    
		while(1) {
			
			for(int i = 1; i <= 128; i <<= 1) //loop left on the leds
			{
				PORTD = i;
				_delay_loop_2(30000);
			}

			for(int i = 128; i >= 1; i >>= 1) //loop right on the leds
			{
				PORTD = i;
				_delay_loop_2(30000);
			}
		}
		return 1;
}
