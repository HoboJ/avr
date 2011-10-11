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
    char key;
    char line[80];
    int count=0;
    int number;
    
    
    printf("Type a damned string\n");
    while ((key=getchar()) != '\n') {
        line[count] = key;
        count++;
    }

    line[count] = '\0';
    printf("You typed in the string:\n%s\n", line);
    number = atoi(line);
    printf("Number in string was: %d\n", number);
    printf("Number * 2 is %d\n", number * 2);

    
    printf("Hit enter to quit\n");
    getchar();
    return 0;
}
