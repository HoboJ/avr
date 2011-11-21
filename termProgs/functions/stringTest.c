/* template
 * 
 * T. Hennessy
 *
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>

#include "strings.h"

#define MAX_STR_SIZE 256

int main(int argc, char *argv[])
{
    char in[40], out[40], *ptr;
    int len;
    
    printf("Input a short string\n");
    scanf("%39s", in);

    printf("Input another string\n");
    scanf("%39s", out);

    printf("You typed %s \n", in);
    printf("And %s \n", out);

    len = my_strlen ( in );
    printf("'In' is %d characters long\n", len);

    len = my_strlen ( out );
    printf("'Out' is %d characters long\n", len);

    ptr = my_strcat ( out, in );

    printf("%s\n\n", ptr);

    printf("Hit enter to quit\n");
    getchar();
    return 0;
}
