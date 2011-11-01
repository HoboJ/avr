/* Trevor Hennessy
 *
 * Function for detecting which switches have been pressed
 * using pointer arithmatic.
 */

#include <avr/io.h>
#include <util/delay.h>

void pSw ( int *switchPress )
{

    int readSw, count = 0;
    int binaryToInt[] = { 1,2,4,8,16,32,64,128 };
    
    do
    {
        readSw = ~PINB;
        
        int i = 0;


        /* Check to see if a specific bit has been turned on by a switch.
         * If a specific bit has been switched on make that bits position
         * in the array a 1, otherwise it is a 0.
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
