/* array.c
 * 
 * T. Hennessy
 *
 * Description: Driving a 7 segment display with PORTD while using
 * PORTB as input
 */

#include <avr/io.h>
#include <util/delay.h>


int decode (void);


int main (void)
{
    int digits[10];

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
    
    DDRD = 0xFF; //set PORTD for output
    DDRB = 0x00; //set PORTB for input

    while(1) {

        int value = decode(); //figure out which number to display on the leds
        
        if(value != 10) {
            PORTD = digits[value];
            _delay_ms(1000);
        }
        else {
            PORTD = 0xFF;
            _delay_ms(4000);
        }
    }

    return 0;
}

int decode(void)
{
        
        if(PORTB == 0x01)
           return 0;
        else if(PORTB == 0x02)
            return 1;
        else if(PORTB == 0x04)
            return 2;
        else if(PORTB == 0x08)
            return 3;
        else if(PORTB == 0x10)
            return 4;
        else if(PORTB == 0x20)
            return 5;
        else if(PORTB == 0x40)
            return 6;
        else if(PORTB == 0x80)
            return 7;
        else
            return 10;
}

