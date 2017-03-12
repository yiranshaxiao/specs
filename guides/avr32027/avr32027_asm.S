/*
 * avr32027.S
 *
 * Created: 6/11/2012 9:33:07 AM
 *  Author: bill.houghton
 */ 

 #include <avr/io.h>


 .global change_clock

	change_clock:			
		LDI	R25,0x80	;
		STS	CLKPR,R25	;enable updating of CLKPR						
		STS	CLKPR,R24	;write the new value
		ret				;

.global add_two

	add_two:
		ADD R24,R22		;val_1 = val_1 + val_2
		CLR	R25			;return val_1
		ret				;

 .global TIMER0_OVF_vect

	TIMER0_OVF_vect:
		sbi		 _SFR_IO_ADDR(PIND),0				;toggle PD.0
        reti										;and done




