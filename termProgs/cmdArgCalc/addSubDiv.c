/* addSubDiv.c
 * 
 * T. Hennessy
 *
 * Description: command line utility for doing simple calculations
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define ERR "h\n"

char *getOpt ( int index, char *argv[] );
int add ( int *num, int argc );
int subtract ( int *num, int argc );
int multiply ( int *num, int argc );
float divide ( int *num, int argc );
void printHelp ( char *argv[] );

int main (int argc, char *argv[])
{
    char *choice;
    int nums[8], i, j = 0, numArgs;
    float div;
    int result;

    if ( argc < 2 )
    {
        printf ( "%s: missing operand\n", argv[0] );
        printf ( "Try '%s -h' for more information.\n", argv[0] );
        choice = &ERR;
    }
    else
    {
            choice = getOpt ( 1, argv );

            switch ( *choice )
            {
                case 'a':
                case 's':
                case 'd':
                case 'm':
                    for ( i = 2; i != argc; i++ )
                    {
                        *( nums + j ) = atoi ( *( argv + i ) );
                        j++;
                    }
                    break;
            }

            numArgs = argc - 2;

            switch ( *choice )
            {
                case 'a':
                    result = add ( nums, numArgs );
                    break;
                case 's':
                    result = subtract ( nums, numArgs );
                    break;
                case 'd':
                    div = divide ( nums, numArgs );
                    break;
                case 'm':
                    result = multiply ( nums, numArgs );
                    break;
                case 'h':
                    printHelp ( argv );
                    break;
            }
    }

    if ( *choice == 'd' )
        printf ( "The result is, %f \n\n", div );
    else if ( *choice == 'h' )
        ;
    else
        printf ( "The result is, %d \n\n", result );

    return 0;
}

char *getOpt ( int index, char *argv[] )
{
    char *opt;
    
    opt = strtok ( argv[index], "-" );

    if ( opt == NULL )
    {
        printf ( "ERROR: INVALID ARGUMENT\n" );
        printf ( "Try '%s -h' for more information.", argv[0] );
        return NULL;
    }
    else
    {
        return opt;
    }
}

int add ( int *num, int argc )
{
    int result = 0;
    
    for ( int i = 0; i < argc; i++ )
    {
        result = result + *(num + i);
    }

    return result;
}

int subtract ( int *num, int argc )
{
    int result = *( num + 0 );

    for ( int i = 1; i < argc; i++ )
        result = result - *( num + i );

    return result;
}

int multiply ( int *num, int argc )
{
    int result = *( num + 0 );
    
    for ( int i = 1; i < argc; i++ )
        result = result * *( num + i );

    return result;
}

float divide ( int *num, int argc )
{
    float result = (float) *( num + 0 );
    
    for ( int i = 1; i < argc; i++ )
        result = result / (float) *( num + i );

    return result;
}

void printHelp ( char *argv[] )
{
    printf ( "-h : Print this help message\n" );
    printf ( "-a : add two numbers together\n" );
    printf ( "-s : subtract two numbers\n" );
    printf ( "-m : multiply two numbers\n" );
    printf ( "-d : divide two numbers\n\n" );
    printf ( " ie. work -a 5 2 7 4\n\n" );
    printf ( "Maximum # of args is 8" );
}
