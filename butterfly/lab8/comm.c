/* comm.c
 *
 * Trevor Hennessy
 *
 * Description: Performs calculations with smpte clock
 */

#include "comm.h"
#include "parse.h"
#include "joystick.h"

int main ( void )
{
    DDRD = 0xFF;

	char *string = malloc ( sizeof(*string) * MAX_STR_LEN );
    memset ( string, 0, ( sizeof(*string) * MAX_STR_LEN ) );
    uint8_t test, count = 127;

    JoyInit();

	// run the initialization routines
	initializer();

   	//Begin forever chatting with the PC
    while ( 1 )
    {
        DIDR0 = 0;
        DIDR1 = 0;

        for ( ;; )
        {
            test = JoyGet ();

            if ( (test & 8) == 8 )
            {
                count = count + 15;
                milliSecInit ( count );
            }
            else if ( (test & 4) == 4 )
            {
                count = count - 15;
                milliSecInit ( count );
            }
        }

        /* get smpte start time 
        sendString ( "Set-Speed: 1-254\r" );
        getString ( string );
        parseInput ( string );
        memset ( string, 0, ( sizeof(*string) * MAX_STR_LEN ) );

        menu (); */
    }

    free ( string );
	return 0;
}

void getString ( char *string )
{
    uint8_t count = 0;

    while ( 1 )
    {
        if ( isCharAvailable() == 1 )
        {
            *( string + count ) = receiveChar ();

            if ( *( string + count ) == '\r' || *( string + count ) == '\n' )
                break;
            else if ( count > 14 )
            {
                sendString ( "Error 14\r" );
                break;
            }

            count++;
        }
    }
}

/*
void getString ( char *string, unsigned int *count )
{
    *( string + *count ) = receiveChar ();

    if ( *( string + *count ) == '\r' || *( string + *count ) == '\n' )
    {
        sendString ( "derp\r" );
        *count = 99;
        return; 
    }
    else if ( *count == 24 )
    {
        sendString ( "Error - received > 24 characters \r" );
        *count = 0;
        return;
    }
    else if ( isCharAvailable() == 1 )
         return getString ( string, count + 1 );
}*/

char isCharAvailable ( void )
{	
	// Does the RX0 bit of the USART Status and Control Register
	// indicate a char has been received?
	if ( ( UCSRA & ( 0x80 ) ) ) 
        return 1;
	else 
        return 0;
}

char receiveChar ( void )
{
	// Return the char in the UDR0 register
	return UDR;
}

void sendChar ( char data )
{
    unsigned char i = 0;

    // To send data with the USART put the data in the USART data register 
    UDR = data;

    // Check to see if the global interrupts are enabled
    if ( SREG & 0x80 )
    {
	// Wait until the byte is sent or we count out
		while ( !( UCSRA & 0x40 ) && ( i < 10000 ) )
		{
			i++;
		}
    }
    else  // Wait until the byte is sent
        while( !( UCSRA & 0x40 ) );
        
    	// Clear the TXCflag        
	UCSRA = UCSRA | 0x40;          

    //data = '\0';
}

void sendString ( char *s )
{
	unsigned char i = 0;
	
    if ( *( s + i ) == '\0' )
        s = &*( s + 1 );

	while ( i < 64 ) // don't get stuck if it is a bad string
	{
        sendChar ( *( s + i ) );

        if ( *( s + i ) == '\n' )
            break;
        else if ( *( s + i ) == '\r' )
            break;
        else if ( *( s + i ) == '\0' )
            break;

        i++;
	}
}

// Send a string located in Flash ROM
void sendFString ( const char *pFlashStr )
{
	uint8_t i;

	// The 'for' logic terminates if the byte is '\0' or if i = 60.
	// '\0' is 'null' and terminates C strings
	// The 60 prevents too much overrun if we get a bad pointer
	// and it limits the string size
	for ( i = 0; ( pgm_read_byte ( &pFlashStr[i] ) ) != '\0' && i < 60; i++ )
    {
		sendChar ( pgm_read_byte ( &pFlashStr[i] ) );
	}
}


void USARTinit ( void )
{
    // Increase the oscillator to 2 Mhz for the 19200 baudrate:  
    CLKPR = ( 1 << CLKPCE );        // set Clock Prescaler Change Enable
    // set prescaler = 4, Inter RC 8Mhz / 4 = 2Mhz
    CLKPR = ( 1 << CLKPS1 );    

    // Set the USART baudrate registers for 19200
    UBRRH = 0;//(unsigned char)(baudrate>>8);
    UBRRL = 12;//(unsigned char)baudrate;

    // Enable 2x speed change
    UCSRA = ( 1 << U2X );

    // Enable receiver and transmitter
    UCSRB = ( 1 << RXEN ) | ( 1 << TXEN ) | ( 0 << RXCIE ) | ( 0 << UDRIE );

    // Set the USART to asynchronous at 8 bits no parity and 1 stop bit
    UCSRC = ( 0 << UMSEL ) | ( 0 << UPM0 ) | ( 0 << USBS ) | ( 3 << UCSZ0 ) | ( 0 << UCPOL );
        
    // Enable interrupts
    sei ();
    
    // Setup the interrupt mask and flags
	PCMSK1 = ( 1 << PINB6 ) | ( 1 << PINB4 );       // set pin-change interrupt mask
  	EIFR = ( 1 << PCIF1 );                    // clear external intterupt flag 1
	EIMSK = ( 1 << PCIE1 );                // enable external interrupt 1    
}


//Calibrate the internal OSCCAL byte, using the external 
//32,768 kHz crystal as reference
void OSCCAL_calibration ( void )
{
    unsigned char calibrate = 0;//FALSE;
    int temp;
    unsigned char tempL;

    CLKPR = ( 1 << CLKPCE );        // set Clock Prescaler Change Enable
    // set prescaler = 8, Inter RC 8Mhz / 8 = 1Mhz
    CLKPR = ( 1 << CLKPS1 ) | ( 1 << CLKPS0 );
    
    TIMSK2 = 0;             //disable OCIE2A and TOIE2

    ASSR = ( 1 << AS2 );        //select asynchronous operation of timer2 (32,768kHz)
    
    OCR2A = 200;            // set timer2 compare value 

    TIMSK0 = 0;             // delete any interrupt sources
        
    TCCR1B = ( 1 << CS10 );     // start timer1 with no prescaling
    TCCR2A = ( 1 << CS20 );     // start timer2 with no prescaling

    while ( ( ASSR & 0x01 ) | ( ASSR & 0x04 ) );       //wait for TCN2UB and TCR2UB to be cleared

    // wait for external crystal to stabilise
	for ( int i = 0; i < 10; i++ )
			_delay_loop_2 ( 30000 );   
			
    while ( !calibrate )
    {
        cli (); // mt __disable_interrupt();  // disable global interrupt
        
        TIFR1 = 0xFF;   // delete TIFR1 flags
        TIFR2 = 0xFF;   // delete TIFR2 flags
        
        TCNT1H = 0;     // clear timer1 counter
        TCNT1L = 0;
        TCNT2 = 0;      // clear timer2 counter
           
        while ( !( TIFR2 && ( 1 << OCF2A ) ) );   // wait for timer2 compareflag
    
        TCCR1B = 0; // stop timer1

        sei (); // __enable_interrupt();  // enable global interrupt
    
        if ( ( TIFR1 && ( 1 << TOV1 ) ) )
        {
            temp = 0xFFFF;      // if timer1 overflows, set the temp to 0xFFFF
        }
        else
        {   // read out the timer1 counter value
            tempL = TCNT1L;
            temp = TCNT1H;
            temp = ( temp << 8 );
            temp += tempL;
        }
    
        if ( temp > 6250 )
        {
            OSCCAL--;   // the internRC oscillator runs to fast, decrease the OSCCAL
        }
        else if ( temp < 6120 )
        {
            OSCCAL++;   // the internRC oscillator runs to slow, increase the OSCCAL
        }
        else
            calibrate = 1;//TRUE;   // the interRC is correct
        
        TCCR1B = ( 1 << CS10 ); // start timer1
    }
}
