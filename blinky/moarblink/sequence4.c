/* sequence4.c
 *
 * Description: Blinks left by 2 shifts 
 * Trevor Hennessy
 */

#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	int left, right, i;

    //set PORTD for output
	DDRD = 0xFF;
    
		while(1) {
                
            left = 128;
            right = 1;
            i = 1;

            while(left != 1 && right != 128) { //loop to light up the leds

                i = left + right;

                PORTD = i;
                _delay_loop_2(50000);

                left >>= 1;
                right <<= 1;

            }
		
        }
		return 1;
}
