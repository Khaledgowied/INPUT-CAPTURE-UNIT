/*
 * TIMER_1_prog.c
 *
 *  Created on: Jul 13, 2018
 *    
 */
#include<avr/io.h>
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include"TIMER_1_interface.h"
#include"DIO_interface.h"


void TIMER_1_Inits(void){

	CLEAR_BIT(TCCR1A,0);
    CLEAR_BIT(TCCR1A,1);
    CLEAR_BIT(TCCR1B,3);   // to make pwm normal operation tabel 47
    CLEAR_BIT(TCCR1B,4);

    SET_BIT(TCCR1B,0);
    CLEAR_BIT(TCCR1B,1);   // no prescaling
    CLEAR_BIT(TCCR1B,2);

    SET_BIT(TCCR1B,6);    // input capture edge select

    SET_BIT(TIMSK,2);    //PIE-> CAPTUE
    SET_BIT(TIMSK,5);    //PIE-> OVERFLOW

    SET_BIT(SREG,7);     //GIE-> enable


}



