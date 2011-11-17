/* Trevor Hennessy
 *
 * Driving a HPDL-1414 display
 */

#include <avr/io.h>
#include <util/delay.h>

int main ( void )
{
    DDRD = 0xFF;
    DDRB = 0xFF;

    char stringMe[] = "BROADCAST ENGINEERING 2011 ";

    int i = 0, j, k;
    char out = '\0';

    while ( 1 )
    {
        i = 0;
        while ( stringMe[i + k] )
        {
            j = 3;
            k = 0;

            while ( j > -1 && stringMe[i + k] )
            {
                switch ( stringMe[i + k] )
                {
                    case '@'...'_':
                        out = stringMe[i + k] - 0x20;
                        break;
                    case ' '...'?':
                        out = stringMe[i + k] + 0x20;
                        break;
                }

                PORTD = out;

                PORTB = 0x00 + j;
                PORTB = 0xFF;
 
                j--;
                k++;
            }
        _delay_ms(2000);
        i++;
        }
    }
    return 0;
}
