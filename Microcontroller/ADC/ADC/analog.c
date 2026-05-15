/*
 * analog.c
 *
 * Created: 17.09.2022 15:32:33
 *  Author: JoachimWagner
 */ 

#define F_CPU 16000000UL
#include "analog.h"
#include <util/delay.h>

void analog_init(){
	ADCSRA = (1 << ADEN);			/* Enable ADC */
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);			/* Set Prescaler */
	ADMUX = (1 << REFS0)	/*| (1 << ADLAR)* 8-bit Variante*/;		/* Vref: Avcc, ADC channel: 0 */
}

uint16_t analog_read(uint8_t channel) {
	ADMUX &= 0xf0;  //  Reset channels
	
	
	ADMUX |= (channel & 0x0f);	/* Set input channel to read */

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	
	_delay_us(10);
	// return ADCH; // 8 Bit Variante
	uint8_t low  = ADCL;
	uint8_t high = ADCH;
	return (uint16_t)low | ((uint16_t)high << 8);
	
	
}




