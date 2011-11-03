/* Trevor Hennessy
 *
 * Decimal to Binary Conversion program with reversing function
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 80
#define MAX_INT_LEN 24

void reverse ( int *binOut, const int i );

int main ( int argc, char *argv[] )
{
    /* Windows is picky on this bit. I have to use calloc over
     * malloc to ensure all elements of the array are initialised
     * to 0. Otherwise weird garbage shows up in random elements when 
     * compiled and ran on windows.
     */
    char *in = calloc (MAX_STR_LEN, sizeof(char));
    int *binOut = calloc (MAX_INT_LEN, sizeof(int));

    int input, dec, i = 0;

    printf("Input a number \n");
    fgets (in, MAX_STR_LEN, stdin);

    /* Ensures string 'in' has been properly terminated */
    if (in[ strlen (in) - 1] == '\n')
        in[ strlen (in) - 1] = '\0';

    /* Convert string 'in' to an integer and assign it to input */
    input = atoi (in);
    
    while ( input != 0 )
    {
        *(binOut + i ) = input % 2;
        i++;

        input = input / 2;
    } 

    /* Reverse binOut so that it will display correctly when printed
     * with incremental 
     */
    reverse ( binOut, i );

    for ( int inc = 0; inc <= i; inc++ )
    {
        printf("%d", *( binOut + inc ) );
    }

    free(in);
    free(binOut);

    return 0;
   
}

/* Function to reverse an array of integers
 */

void reverse ( int *binOut, const int i )
{
    int first, last; 
    int up = 0; 
    int down = i;

    while ( up < down )
    {
        first = *( binOut + up );
        last = *( binOut + down );

        *( binOut + up ) = last;
        *( binOut + down ) = first;

        up++;
        down--;
    }

    return;
}
