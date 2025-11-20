/*
 * Serial.c
 *
 * Created: 31.10.2025 11:58:40
 * Author : JoachimWagner
 */ 

#include <avr/io.h>

//#include <stdlib.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL                       // Clock Speed
#define BAUD 9600
#define MYUBRR (((F_CPU/(BAUD*16UL)))-1)

inline void usart_sendChar(char value) {
	while ( !(UCSR0A & (1 << UDRE0)) ) ;
	UDR0 = value;
}

uint8_t uart_receiveChar() {
	// wait until a byte is ready to read
	while( ( UCSR0A & ( 1 << RXC0 ) ) == 0 ){}
	// grab the byte from the serial port
	return UDR0;
}


int main(void)
{
    /*Set baud rate */
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;

	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);


    sei();
    while (1) 
    {
		
		uint8_t receivedByte = uart_receiveChar();
		
		 
		
	
		usart_sendChar(receivedByte);
    }
}

