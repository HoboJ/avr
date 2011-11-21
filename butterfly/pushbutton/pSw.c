/* Trevor Hennessy
 *
 * Function for detecting which of eight switches have been engaged
 * using pointers.
 */

#include <avr/io.h>
#include <util/delay.h>

void pSw ( int *switchPress )
{

    int readSw, count = 0;
    int binaryToInt[] = { 1,2,4,8,16,32,64,128 };
    
    do
    {
        /* PINB has to be inverted in order for us to see a 1
         * on the appropriate bit. This is because the inputs
         * pull down the pins when engaged with a switch.
         *
         * Alternatively PINB is normally high so any switch presses
         * will show up as lows. So inverting PINB is required if
         * you expect a switch press to show up as a 1 in the code.
         */

        readSw = ~PINB;
        
        int i = 0;


        /* Check to see if a specific bit has been turned on by a switch.
         * If a specific bit has been switched on make that bits position
         * in the array switchPress[] a 1, otherwise set it to a 0.
         */

        while ( i <= 7 )
        {
            
            if ( *( binaryToInt + i ) == ( *( binaryToInt + i) & readSw )  )
                *( switchPress + i ) = 1;
            else
                *( switchPress + i ) = 0;

            i++;

        } 

        _delay_ms ( 10 );
        count++;
    }
    while ( count <= 4 );

}
