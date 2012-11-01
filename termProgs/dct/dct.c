/* dct.c
 * 
 * T. Hennessy
 *
 * Description: command line utility for calculating the
 * DCT values of a 8x8 block
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 20
#define ERR "h\n"
#define PI 3.14159265

float dctCalc ( int nums[8][8], int u, int v );

int main (int argc, char *argv[])
{
    int nums[8][8], i, j = 0, k = 0, u = 0, v = 0;
    float final;

    if ( argc < 2 )
    {
        printf ( "%s: missing operand\n", argv[0] );
    }
    else
    {
        /* Take cmdline values and put them into a 2d array
         * of 8 x 8
         */
        for ( i = 1; i != argc; i++ )
        {
            nums[j][k] = atoi ( *( argv + i ) );
            k++;

            if ( k == 8 )
            {
                k = 0;
                j++;
            }
        }

        for ( u = 0; u < 8; u++ )
        {
            for ( v = 0; v < 8; v++ )
            {
                final = dctCalc ( nums, u, v );
                if ( v == 7 )
                    printf ( "%f\n", final );
                else
                    printf ( "%f ", final );
            }
        }
    }

    return 0;
}

float dctCalc ( int nums[8][8], int u, int v )
{
    float results[8][8], final, cu, cv;        
    int x, y;

    /* Calculate new array values based upon u and v coordinate 
     */
    for ( x = 0; x < 8; x++ )
    {
        for ( y = 0; y < 8; y++ )
        {
            results[x][y] = nums[x][y] * cosf ( ( ( 2 * x + 1 ) * u * PI ) /16 ) * cosf ( ( ( 2 * y + 1 ) * v * PI ) / 16 );
        }
    }

    /* Perform summation on array of calculated values
     */
    for ( x = 0; x < 8; x++ )
    {
        for ( y = 0; y < 8; y++ )
        {
            final = final + results[x][y];
        }
    }

    /* Decide if u or v are greater than 0 and perform proper caluclation
     * store value in cu and cv respectively
     */
    if ( u > 0 )
    {
        cu = .5;
    }
    else
    {
        cu = ( 1/sqrtf ( 2 ) ) / 2;
    }

    if ( v > 0 )
    {
        cv = .5;
    }
    else
    {
        cv = ( 1/sqrtf ( 2 ) ) / 2;
    }

    /* Calculate the final value at coordinate based upon u and v
     */
    final = cu * cv * final;

    return final;
}
