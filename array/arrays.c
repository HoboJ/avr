/* array.c
 * 
 * T. Hennessy
 *
 * Description: Driving a 7 segment display with PORTD while using
 * PORTB as input
 */

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define F_CPU 1000000UL


int decode (int *test);


int main (void)
{
    int digits[10];
    int balls = 0; 
    int strikes = 0;
    int *test;

    digits[0] = 0xC0;
    digits[1] = 0xF9;
    digits[2] = 0xA4;
    digits[3] = 0xB0;
    digits[4] = 0x99;
    digits[5] = 0x92;
    digits[6] = 0x82;
    digits[7] = 0xF8;
    digits[8] = 0x80;
    digits[9] = 0x98;
    digits[10] = 0xC1;
    
    DDRD = 0x7F; //set PORTD for output
    DDRB = 0x7F; //set PORTB for output

    while(1) {

        *test = decode(test); //test to see which button gets pressed

        if(*test == 1) {
            balls ++;
            PORTB = digits[balls];
        }
        else if(*test == 2) {
            strikes ++;
            PORTD = digits[strikes];
        }

        if(balls == 4 || strikes == 3) {
            balls = 0;
            PORTB = digits[balls];

            strikes = 0;
            PORTD = digits[strikes];
        }
        
        //_delay_ms(2000);

        /*       
        rotate = 0;

        while(rotate < 10) {

            PORTD = digits[rotate];
            _delay_ms(2000);
            rotate++;
        }

        rotate = 0;

        while(rotate < 10) {
            PORTB = digits[rotate];
            _delay_ms(2000);
            rotate++;
        }
        */
        
    }

    return 0;
}

int decode (int *test)
{
    int strikeButton;
    int ballButton;

    while(1) {
        
        ballButton = PINB & 0x80;
        strikeButton = PIND & 0x80;

        if(ballButton == 128) {
            *test = 1;
            break;
        }
        else if(strikeButton == 128) {
            *test = 2;
            break;
        }
    }

    return *test;

}
