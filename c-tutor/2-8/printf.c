/* printf.c
 * 
 * T. Hennessy
 *
 * Description: Prints my name and then quits when return is pressed.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Trevor Hennessy\n\n");
    
    printf("Hit enter to quit");
    getchar();
    return 0;
}
