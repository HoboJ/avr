/* addSubDiv.c
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

    while ( 1 && choice != '5' )
    {

    printf("Choose what to do with the numbers input: \n");
    printf("1. Add \n");
    printf("2. Subtract \n");
    printf("3. Multiply \n");
    printf("4. Divide \n");
    printf("5. Quit \n\n");

    choice = getchar();

    dummyRead = getchar();

    if ( choice != '5' )
    {
        num1 = getNum ();
        num2 = getNum ();
    }

    switch ( choice )
    {
        case '1':
            result = add ( num1, num2 );
            break;
        case '2':
            result = subtract ( num1, num2 );
            break;
        case '3':
            result = multiply ( num1, num2 );
            break;
        case '4':
            div = divide ( num1, num2 );
            break;
    }

    if ( choice == '4' )
        printf ( "\n\nThe result is, %f \n\n", div );
    else if ( choice == '5' )
        printf ( "Goodbye.\n\n" );
    else
        printf ( "The result is, %d \n\n", result );

    }

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
