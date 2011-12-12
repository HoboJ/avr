// PC_Comm.h
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include <compat/deprecated.h>
#include <string.h>

#include <stdlib.h>
#include <avr/pgmspace.h>

#include "demo.h"

#define MAX_STR_LEN 24

void OSCCAL_calibration ( void );

void USARTinit ( void );
char isCharAvailable ( void );
char receiveChar ( void );
void sendChar ( char data ) ;
void sendString ( char *s );

void sendFString ( const char *s );
