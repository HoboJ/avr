/* array.c
 * 
 * T. Hennessy
 *
 * Description: Driving a 7 segment display with PORTD while using
 * PORTB as input
 */

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL


int decode (void);


int main (void)
{
    int digits[10];
    int rotate, value;

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
    
    DDRD = 0xFF; //set PORTD for output

    while(1) {
        
        /*rotate = 0;

        while(rotate < 10) {

            PORTD = ~digits[rotate];
            _delay_ms(1000);
            rotate++;
        }*/
        value = decode(); //figure out which number to display on the leds
        
        PORTD = value;
        
    }

    return 0;
}

int decode (void)
{
    DDRB = 0x00; //accept input from PORTB

    int input, value;

    input = PINB; //take input from PORTB

    switch (input) {
        case 1:
            value = 0;
            break;
        case 2:
            value = 1;
            break;
        case 4:
            value = 2;
            break;
        case 8:
            value = 3;
            break;
        case 16:
            value = 4;
            break;
        case 32:
            value = 5;
            break;
        case 64:
            value = 6;
            break;
        case 128:
            value = 7;
            break;
        default:
            value = 10;
    }

    return value;

}       

