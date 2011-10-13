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
    int count = 0;

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

    while(count <= 4) {

        int value = decode(); //figure out which number to display on the leds
        
        if(value != 10) {
            PORTD = digits[value];
            _delay_ms(1000);
        }
        else {
            PORTD = 0xFF;
            _delay_ms(4000);
        }
        count++;
        
    }

    return 0;
}

int decode(void)
{

    int input, value;

    PORTB = input;
    
    switch (input) {
        case 0x01:
            value = 0;
            break;
        case 0x02:
            value = 1;
            break;
        case 0x04:
            value = 2;
            break;
        case 0x08:
            value = 3;
            break;
        case 0x10:
            value = 4;
            break;
        case 0x20:
            value = 5;
            break;
        case 0x40:
            value = 6;
            break;
        case 0x80:
            value = 7;
            break;
        default:
            value = 10;
    }

    return value;

}       
