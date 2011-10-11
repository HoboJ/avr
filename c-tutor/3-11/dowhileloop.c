/* dowhileloop.c
 * 
 * T. Hennessy
 *
 * Description: My name printed 10 times with a do while loop.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count = 0;

    do
    {
        printf("Trevor Hennessy\n");
        count++;
    }
    while(count < 10);

    printf("Hit enter to quit");
    getchar();
    return 0;
}
