/*
 * usart.h
 *
 * Created: 21.11.2025 15:10:26
 *  Author: JoachimWagner
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>

//#include <stdlib.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL                       // Clock Speed
#define BAUD 9600
#define MYUBRR (((F_CPU/(BAUD*16UL)))-1)

void usart_init() ;
void usart_sendChar(char value);
uint8_t uart_receiveChar();
void usart_sendString(char * message);


#endif /* USART_H_ */