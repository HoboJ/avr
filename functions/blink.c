/* Test program for headers and functions
 */

#include <avr/io.h>
#include <util/delay.h>

#include "./ledLoops.h"

int main (void)
{
   
    //loopLeft(2000);

    //loopRight(2000);

    //loopLeftRight(2000);

    loopX (2000);

    return 1;
}
