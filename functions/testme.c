/* Fgets() test
 *
 * Trevor Hennessy
 */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#define MAX_NAME_SZ 256

int main ( int argC, char *argV[] )
{
    /* Allocate memory and check if okay. */
    char *name = malloc (MAX_NAME_SZ);

    if (name == NULL) {
        printf ("No memory\n");
        return 1;
    }

    /* Ask user for name. */
    printf("What is your name? ");

    /* Get the name, with size limit. */
    fgets (name, MAX_NAME_SZ, stdin);

    /* Remove trailing newline, if there. */
    if (name[strlen (name) - 1] == '\n')
        name[strlen (name) - 1] = '\0';

    /* Say hello. */
    printf("Hello %s. Nice to meet you.\n", name);

    /* Free memory and exit. */
    free (name);
    return 0;
}
