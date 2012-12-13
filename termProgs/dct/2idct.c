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

static double coefficients [8 * 8];

void ff_ref_idct ( double *block );
void ff_ref_dct_init ( void );

int main (int argc, char *argv[])
{
    int i = 1, j = 0;
    double nums[8 * 8];

    ff_ref_dct_init;

    if ( argc < 2 )
    {
        printf ( "%s: missing operand\n", argv[0] );
    }
    else
    {
        for ( i = 1; i < argc; i++ )
        {
            nums[j] = atof ( ( *( argv + i ) ) );
            j++;
        }

        printf ( "Input values:\n" );

        j = 0;
        i = 0;

        while ( i < 64 )
        {
            if ( j % 8 == 1 )
            {
                printf ( "%f\n", nums[i] );
            }
            else
                printf ( "%f ", nums[i] );

            i++;
            j++;
        }

        printf ( "\n" );
        printf ( "Results:\n" );

        ff_ref_idct ( nums );

        j = 0;
        i = 0;
        printf ( "%f\n", nums[0] );
        while ( i < 64 )
        {
            if ( j % 8 == 1 )
            {
                printf ( "%f\n", nums[i] );
            }
            else
                printf ( "%f", nums[i] );

            i++;
            j++;
        }
        
    }

    return 0;
}

void ff_ref_dct_init ( void )
{
    unsigned int i, j;

    for ( j = 0; j < 8; j++ )
    {
        coefficients[j] = sqrt(0.125);
        for ( i = 8; i < 64; i += 8 )
        {
            coefficients[i + j] = 0.5 * cosf ( i * ( j + 0.5 ) * PI / 64.0 );
        }
    }
}

void ff_ref_idct ( double *block )
{
    unsigned int i, j, k;
    double out[8 * 8];

    for ( i = 0; i < 64; i += 8 )
    {
        for ( j = 0; j < 8; j++ )
        {
            double tmp = 0;
            for ( k = 0; k < 8; k++ )
            {
                tmp += block[i + k] * coefficients[k * 8 + j];
            }
            out[i + j] = tmp;
        }
    }

    for ( i = 0; i < 8; i++ )
    {
        for ( j = 0; j < 8; j++ )
        {
            double tmp = 0;
            for ( k = 0; k < 64; k += 8 )
            {
                tmp += coefficients[k + i] * out[k + j];
            }
            block[i * 8 + j] = floor ( tmp + 0.5 );
        }
    }
}
