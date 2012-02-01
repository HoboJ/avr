/* joystick.h
 * 
 * Trevor Hennessy
 * 
 */

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#define BUTTON_B ( 7 )  //DOWN
#define BUTTON_A ( 6 )  //UP
#define BUTTON_O ( 4 )  //PUSH
#define BUTTON_D ( 3 )  //RIGHT
#define BUTTON C ( 2 )  //LEFT

#define PINB_MASK ( ( 1 << PINB7 ) | ( 1 << PINB6 ) | ( 1 << PINB4 ) )
#define PINE_MASK ( ( 1 << PINE3 ) | ( 1 << PINE2 ) )

void JoyInit ( void );
char JoyGet ( void );
