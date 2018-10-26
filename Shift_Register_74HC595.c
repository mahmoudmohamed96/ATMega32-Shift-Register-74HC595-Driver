/*
 * Shift_Register_74HC595.c
 *
 *  Created on: Oct 22, 2018
 *      Author: Mahmoud Mohamed Younis
 */
#include "Shift_Register_74HC595.h"

/**
 * 1- Send one bit 
 * 2- send pulse to shift register clock pulse
 * 3- repeat the two previous steps until send one byte 
 * 4- send pulse to Storage register clock input.
*/

/********************************************************
 *          Initialize Shift Register                   *
 ********************************************************
 */
void Shift_Register_Init (void)
{
	SHR_DDR |= (1<<SH_CP) | (1<<DS) | (1<<ST_CP); // PINS >> OUTPUT
	return;
}

/********************************************************
 *      Set pins Value of Shift Register                *
 * ******************************************************
 */

void Shift_register_Send_data (unsigned char data)
{
    SHR_PORT &= ~(1<<ST_CP);
    unsigned char arr[8];
    unsigned char i= 0;
    for (i=0 ; i<8 ; i++)
    {
       arr[i] = ( data & (1<<i))>>i;
    }
    for (i=8 ; i>=1 ; i--)
    {
    	if (arr[i-1] == 0) SHR_PORT &= ~(1<<DS);
   else if (arr[i-1] == 1) SHR_PORT |=  (1<<DS);
    	SHR_PORT |= (1<<SH_CP);
       _delay_ms(2);
       SHR_PORT &= ~(1<<SH_CP);
    }
    SHR_PORT |= (1<<ST_CP);
}

