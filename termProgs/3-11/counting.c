/* counting.c
 * 
 * T. Hennessy
 *
 * Description: Program counts to 10 and outputs the numbers
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int count;

    for(count = 1; count <= 10; count++)
    {
        if(count == 3)
            printf("Oh look we're at %d\n", count);
        if(count == 7)
            printf("Hurray we're at %d\n", count);
        else
            printf("%d\n", count);
    }
    
    printf("Hit enter to quit");
    getchar();
    return 0;
}
