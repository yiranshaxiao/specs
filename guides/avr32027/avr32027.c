/*
 * avr32027.c
 *
 * Created: 6/11/2012 9:32:22 AM
 *  Author: bill.houghton
 */ 

#include <avr/io.h>


#define clock_val 0x02

enum freq {MHz_8, MHz_4, MHz_2, MHz_1, kHz_500, kHz_250, kHz_125, kHz_63, kHz_32};

// externs are defined in avr32027_asm.S
extern void change_clock (char);
extern char add_two(char, char);

void init_timer_0(void);


int main(void)
{
	volatile unsigned char val_1,val_2, val_3;

	change_clock(MHz_2);						// call assembly to change the clock to divide by 1
	init_timer_0();								// turn on timer & its interrupt

	val_1 = 0x34;
	val_2 = 0x56;
	val_3 = add_two(val_1, val_2);				// call assembly to add two numbers

   	// loop forever
   	while(1);
}

void init_timer_0(void)
{
	DDRD  |= 0x01;									// PD.0 = output
	TCCR0A = 0x00;
	TCCR0B = 0x05;									// clk /1024
	TCNT0  = 0x00;
	TIMSK0 = 0x01;									// enable TOV interrupt
	SREG  |= 0x80;									// global enable interrupts
}

