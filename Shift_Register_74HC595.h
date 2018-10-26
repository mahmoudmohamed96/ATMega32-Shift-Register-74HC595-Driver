/*
 * Shift_Register_74HC595.h
 *
 *  Created on: Oct 22, 2018
 *      Author: Mahmoud Mohamed Younis
 */

#ifndef SHIFT_REGISTER_74HC595_H_
#define SHIFT_REGISTER_74HC595_H_

#include <avr/io.h>
#include <util/delay.h>

#define SHR_DDR   DDRC
#define SHR_PORT  PORTC
#define SH_CP     PC1    // Shift Register clock pulse
#define DS        PC2    // Data Serial
#define ST_CP     PC3    // Storage Register clock pulse

void Shift_Register_Init(void);
void Shift_register_Send_data (unsigned char data);

#endif /* SHIFT_REGISTER_74HC595_H_ */
