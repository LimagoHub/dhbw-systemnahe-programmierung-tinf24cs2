/*
 * TimerUndFrequenz.c
 *
 * Created: 31.10.2025 09:13:32
 * Author : JoachimWagner
 */ 



#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER0_COMPA_vect)  // timer0 overflow interrupt b// CTC
{
	PORTB = ~PORTB;
}


int main(void)
{
	DDRB = 0xFF;
	PORTB = 0;

	// Set the Timer Mode to CTC
	TCCR0A |= (1 << WGM01);

	// Set the value that you want to count to
	OCR0A = 70; // Kammerton A
	//OCR0A = 117; // ...und C

	TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vect

	sei();         //enable interrupts

	TCCR0B |= (1 << CS02);
	// set prescaler to 256 and start the timer


	while (1)
	{
		//main loop
	}
}

