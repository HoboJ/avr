/* template
 * 
 * T. Hennessy
 *
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c;

    printf("Type something shithead\n");
    c = getchar();

    if (c == '?')
        printf("Congrats you're a dick\n");
    else
        printf("1000000 internets to you %c\n" , c);


    printf("Hit enter to quit\n");
    getchar();
    return 0;
}
