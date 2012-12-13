/* idct.c
 * 
 * T. Hennessy
 *
 * Description: command line utility for reversing
 * a DCT result
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265f

float idctCalc ( double nums[8][8], int x, int y );

int main (int argc, char *argv[])
{
    int i, j = 0, k = 0, x = 0, y = 0;
    double nums[8][8];
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
            nums[j][k] = atof ( *( argv + i ) );
            k++;

            if ( k == 8 )
            {
                k = 0;
                j++;
            }
        }

        //final = idctCalc ( nums, x, y );
        //printf ( "%f\n", final );

        printf ( "Input values:\n" );

        for ( j = 0; j < 8; j++ )
        {
            for ( k = 0; k < 8; k++ )
            {
                if ( k == 7 )
                    printf ( "%f\n", nums[j][k] );
                else
                    printf ( "%f ", nums[j][k] );
            }
        }

        printf ( "\n" );
        printf ( "Results:\n" );
        
        for ( x = 0; x < 8; x++ )
        {
            for ( y = 0; y < 8; y++ )
            {
                final = idctCalc ( nums, x, y );
                
                if ( y == 7 )
                    printf ( "%f\n", final );
                else
                    printf ( "%f ", final );
            }
        }
    }

    return 0;
}


float idctCalc ( double nums[8][8], int x, int y )
{
    float results[8][8], final = 0, cu, cv;        
    int u, v;

    /* Calculate new array values based upon u and v coordinate 
     */
    for ( u = 0; u < 8; u++ )
    {
        for ( v = 0; v < 8; v++ )
        {
            /* Decide if u or v are greater than 0 and perform proper
             * calculation. Store the value in cu and cv respectively.
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

            results[u][v] = nums[u][v] * cu * cv * cosf ( ( ( 2 * x + 1 ) * u * PI ) / 16 ) * cosf ( ( ( 2 * y + 1 ) * v * PI ) / 16 );
        }
    }

    /* Perform summation on array of calculated values
     */
    for ( u = 0; u < 8; u++ )
    {
        for ( v = 0; v < 8; v++ )
        {
            final = final + results[u][v];
        }
    }
    //printf ( "%f\n", final );
    
    /* Calculate the final value at coordinate based upon u and v
     */
    //final = cu * cv * final;

    return final;
}
