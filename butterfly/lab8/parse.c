/* parse.c
 * 
 * 
 *
 * Trevor Hennessy
 */

#include "comm.h"

void initializer ( void )
{
	// Calibrate the oscillator:
    OSCCAL_calibration ();   
	// Initialize the USART
	USARTinit ();

    // Set for pin change on PINB0
    DDRB = (1 << PINB0); // set pin 0 to output
    PORTB = (1 << PINB0); // set pin 0 to enable pullup
    PCMSK0 = (1 << PINB0); // 
    EIFR = (1 << 7); // flag for PCINT15-8
    EIMSK = (1 << 7); // mask for PCINT15-8
    DDRB = 0X00; // set PORTB for input 
    PORTB = 0xFF; // enable pullup on for input
    // set PORTD for output
    DDRD = (1 << PIND0); // set pin 0 to output
    PORTD = (1 << PIND0); // set pin 0 to enable pullup
    milliSecInit(127); // 50% duty cycle 1kHz signal
	
    menu ();
}

void menu ( void )
{
    sendChar ( '\r' );
    sendString ( "Motor Speed Control\r" );
    sendString ( "Speed is between 1-254\r" );
    sendChar ( '\r' );
}

/* convert a smpte format string into the total frames 
 * format being hours:minutes:seconds:frames
 */
void parseInput ( char *s )
{
    if ( *( s + 0 ) == '\0' )
        s = &*( s + 1 );

    uint8_t count = 0;

    count = atoi ( s );

    sendString ( "Setting speed to: " );
    sendString ( s );
    sendChar ( '\r' );

    milliSecInit ( count );
}

/*
 * The USART init set the system oscillator to 2 mHz. We set the Timer0 prescaler
 * to clk/8 which gives a 250 kHz input to the timer/counter. A compare of 250 throws
 * an interrupt every millisecond.
 * */
void milliSecInit(unsigned char count)
{
    // Enable timer0 compare interrupt
    TIMSK0 = (1<<OCIE0A);
    // Sets the compare value
    setOCR0A(count);
    // Set PWM Phase Correct mode, CLK/8 prescaler
    TCCR0A = (0<<FOC0A)|(0<<WGM01)|(1<<WGM00)|(1<<CS01);
}

void setOCR0A(unsigned char count)
{    
    // Sets the compare value
    OCR0A = count;
}

// Interrupt occurs twice per Millisec, timed for PWM
ISR(TIMER0_COMP_vect)
{
    // Toggle PORtD pin 0
    if(PORTD &= 1) cbi(PORTD, 0);
    else sbi(PORTD, 0);
}
