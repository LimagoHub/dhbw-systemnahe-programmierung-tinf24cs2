/*
 * Serial.c
 *
 * Created: 31.10.2025 11:58:40
 * Author : JoachimWagner
 */ 

#include <avr/io.h>

#include <stdlib.h>
#include "usart.h"


int main(void)
{
   usart_init();
   usart_sendString("Hallo Putty\r\n");
    while (1) 
    {
		int zahlZumSenden = 4711;
		
		char buffer[10];
		itoa(zahlZumSenden, buffer, 10);
		usart_sendString(buffer);
		usart_sendString("\r\n");
		
    }
}


