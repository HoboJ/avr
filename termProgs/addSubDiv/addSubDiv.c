/* addSubDiv.c
 * 
 * T. Hennessy
 *
 * Description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 40

int getNum ( void );
int add ( int num1, int num2 );
int subtract ( int num1, int num2 );
int multiply ( int num1, int num2 );
float divide ( int num1, int num2 );

int main(int argc, char *argv[])
{
    char *choice = malloc ( sizeof ( char ) * MAX_STR_LEN );
    memset ( choice, 0, ( sizeof ( char ) * MAX_STR_LEN ));

    int num1, num2;
    float div;
    int result;

    num1 = getNum ();

    num2 = getNum ();

    printf("Choose what to do with the numbers input: \n");
    printf("Add \n");
    printf("Subtract \n");
    printf("Multiply \n");
    printf("Divide \n\n");

    fgets ( choice, MAX_STR_LEN, stdin );
    
    if ( *choice == "Add" )
        result = add ( num1, num2 );
    else if ( *choice == "Subtract" )
        result = subtract ( num1, num2 );
    else if ( *choice == "Multiply" )
        result = multiply ( num1, num2 );
    else if ( *choice == "Divide" )
        div = divide ( num1, num2 );
        

    if ( *choice == "Divide" )
        printf( "The result is, %f \n\n", div );
    else
        printf ( "The result is, %d \n\n", result );


    printf("Hit enter to quit");
    getchar();

    free ( choice );

    return 0;
}

int getNum ( void )
{
    char *in = malloc ( sizeof ( char ) * MAX_STR_LEN );
    memset ( in, 0, ( sizeof ( char ) * MAX_STR_LEN ));

    int num;

    printf("Input a number ");
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
