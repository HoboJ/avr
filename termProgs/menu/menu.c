/* menu.c
 * 
 * T. Hennessy
 *
 * Description: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20

int getNum ( void );
int add ( int num1, int num2 );
int subtract ( int num1, int num2 );
int multiply ( int num1, int num2 );
float divide ( int num1, int num2 );

int main(int argc, char *argv[])
{
    char choice;
    int num1, num2;
    float div;
    int result, dummyRead;

    while ( 1 && choice != 'e' )
    {

        printf("Choose what to do with the numbers input: \n");
        printf("a. Add \n");
        printf("b. Subtract \n");
        printf("c. Multiply \n");
        printf("d. Divide \n");
        printf("e. Quit \n\n");

        choice = getchar();

        dummyRead = getchar();

        if ( choice != 'e' )
        {
            num1 = getNum ();
            num2 = getNum ();
        }

        switch ( choice )
        {
            case 'a':
                result = add ( num1, num2 );
                break;
            case 'b':
                result = subtract ( num1, num2 );
                break;
            case 'c':
                result = multiply ( num1, num2 );
                break;
            case 'd':
                div = divide ( num1, num2 );
                break;
        }

        if ( choice == 'd' )
            printf ( "\n\nThe result is, %f \n\n", div );
        else if ( choice == 'e' )
            printf ( "Goodbye.\n\n" );
        else
            printf ( "The result is, %d \n\n", result );

    }

    //system ( "pause" );

    return 0;
}

int getNum ( void )
{
    char *in;
    in = malloc ( sizeof ( *in ) * MAX_STR_LEN );
    
    if ( in == NULL )
        printf("Error memory could not be allocated for input");

    memset ( in, 0, ( sizeof ( *in ) * MAX_STR_LEN ));

    int num;

    printf("\nInput a number ");
    fgets ( in, MAX_STR_LEN, stdin );

    if ( in [ strlen ( in ) - 1 ] == '\n' )
        in [ strlen ( in ) - 1 ] = '\0';

    num = atoi ( in );

    free ( in );

    return num;
}

int add ( int num1, int num2 )
{
    int result = num1 + num2;

    return result;
}

int subtract ( int num1, int num2 )
{
    int result = num1 - num2;

    return result;
}

int multiply ( int num1, int num2 )
{
    int result = num1 * num2;

    return result;
}

float divide ( int num1, int num2 )
{
    float result = (float) num1 / (float) num2;

    return result;
}
