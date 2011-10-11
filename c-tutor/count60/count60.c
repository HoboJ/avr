/* count60.c
 * 
 * T. Hennessy
 *
 * Description: counts from 60 to 0 in 1 second intervals
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //lib containing the sleep() function for unix operating systems
//#include <windows.h> //lib containing the Sleep() function for windows

int main(int argc, char *argv[])
{
    int i;

    for(i = 60; i >= 0; i--)
    {
        printf("count: %i\n",i);

        /* sleep function for unix operating systems */
        sleep(1);

        /* sleep function for windows */
        //Sleep(1000);
    }
    
    printf(" Hit enter to quit ");
    getchar();
    return 0;
}
