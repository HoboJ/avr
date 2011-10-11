/* whileloop.c
 * 
 * T. Hennessy
 *
 * Description: My name printed 10 times with a while loop.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count = 0;
    
    while(count < 10)
    {
        printf("Trevor Hennessy\n");
        count++;
    }

    printf("Hit enter to quit");
    getchar();
    return 0;
}
