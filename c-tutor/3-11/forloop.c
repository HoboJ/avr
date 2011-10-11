/* forloop.c
 * 
 * T. Hennessy
 *
 * Description: My name printed 10 times with a for loop.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int control;

    for(control = 0; control < 10; control++)
    {
        printf("Trevor Hennessy\n");
    }

    printf("Hit enter to quit");
    getchar();
    return 0;
}
