/*
 * usart.c
 *
 * Created: 21.11.2025 15:14:41
 *  Author: JoachimWagner
 */ 

#include "usart.h"

ISR (USART_RX_vect)
{
	uint8_t receivedChar = UDR0;
	usart_sendChar(receivedChar);
	
}

void usart_init() {
	/*Set baud rate */
	UBRR0H = (MYUBRR >> 8);
	UBRR0L = MYUBRR;

	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);      // Enable receiver and transmitter
	UCSR0B |= (1 << RXCIE0);                    // Enable reciever interrupt
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // ( Daten bits, 1 Stopbit, Keine Paritaet

	sei();
}
void usart_sendChar(char value) {
	while ( !(UCSR0A & (1 << UDRE0)) ) ;
	UDR0 = value;
}

uint8_t uart_receiveChar() {
	// wait until a byte is ready to read
	while( ( UCSR0A & ( 1 << RXC0 ) ) == 0 ){}
	// grab the byte from the serial port
	return UDR0;
}

void usart_sendString(char * message){
	while( * message)
		usart_sendChar(*message ++);
}

