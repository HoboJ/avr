/* Trevor Hennessy
 *
 * Various self written string related functions
 * so I can properly learn pointers
 */

#include <stdlib.h>

int my_strlen ( const char *s )
{
    int len = 0;

    while ( *( s + len ) != '\0' )
    {
        len++;
    }

    return len;
}


char *my_strcat ( char *dest, const char *src )
{
    int len, i;

    len = my_strlen ( dest );

    for ( i = 0; *( src + i ) != '\0'; i++ )
    {
        *( dest + len + i ) = *( src + i );
    }

    return dest;
}


char *my_strchr ( const char *s, int c )
{
    int match, i = 0;
    void *ptr;

    while ( *( s + i ) != '\0' || match == 1 )
    {
        if ( *( s + i ) == c )
        {
            match = 1;
            ptr = & s + i;
        }
        else
            i++;
    }

    if ( match == 1 )
        return ptr;
    else
        return NULL;
}
