/*
 * analog.h
 *
 * Created: 17.09.2022 15:29:47
 *  Author: JoachimWagner
 */ 


#pragma once
#include <avr/io.h>

void analog_init();
uint16_t analog_read(uint8_t channel);