/*
 * ADC.c
 *
 * Created: 15.05.2026 08:56:05
 * Author : JoachimWagner
 */ 

/*
 * main.c
 *
 * Liest analoge Werte von mehreren ADC-Kanaelen des ATmega328P
 * und gibt sie mit Kanalbeschriftung ueber UART aus.
 *
 * Beispielausgabe:
 *   Kanal 0:  512 (2500 mV)
 *   Kanal 1:  102 ( 496 mV)
 *   ...
 *   --------------------
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>       // sprintf

#include "usart.h"
#include "analog.h"

/* Anzahl der zu lesenden ADC-Kanaele (0 bis NUM_CHANNELS-1) */
#define NUM_CHANNELS    2

/* Pause zwischen zwei kompletten Messrunden in ms */
#define POLL_DELAY_MS   500

/* Referenzspannung in mV (AVCC = 5000 mV beim Arduino/ATmega328P mit 5V) */
#define VREF_MV         5000UL

int main(void)
{
    char buf[40];   // Puffer fuer sprintf

    usart_init();
    analog_init();

    usart_sendString("ATmega328P ADC-Monitor gestartet\r\n");
    usart_sendString("==================================\r\n");

    while (1)
    {
        for (uint8_t ch = 0; ch < NUM_CHANNELS; ch++)
        {
            uint16_t raw = analog_read(ch);

            /* Spannung berechnen: U = raw * VREF / 1023  (10-Bit ADC) */
            uint16_t mv = (uint16_t)((uint32_t)raw * VREF_MV / 1023UL);

            sprintf(buf, "Kanal %u: %4u (%4u mV)\r\n", ch, raw, mv);
            usart_sendString(buf);
        }

        usart_sendString("--------------------\r\n");
        _delay_ms(POLL_DELAY_MS);
    }

    return 0;   // wird nie erreicht
}