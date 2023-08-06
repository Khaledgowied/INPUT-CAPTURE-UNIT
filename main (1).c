/*
 * main.c
 *
 *  Created on: Jul 13, 2018
 *     
 */
#include"../lib/std_types.h"    /*noting to try*/
#include"../lib/macros.h"
#include"LCD_interface.h"
#include"DIO_interface.h"
#include"TIMER_1_interface.h"
#include<util/delay.h>
#include<avr/interrupt.h>
#include<avr/io.h>
#define F_CPU 12000000

f32 Ton;
f32 Toff;
f32 Ttot;
u8  Duty;
u8 FirstReading;
u8 Freq;
u32 Nov;
u8 State;

int main(void){  // JUMP TO ISR BY ICP PIN 6 PORTD
	LCD_voidInit();
	TIMER_1_Inits();

	DIO_voidSetPinDir(DIO_PORTD, DIO_PIN_6, DIO_INPUT);

    FirstReading=1;
    while(1){

    	Ttot=Ton+Toff;
    	Freq=(u8)((f32)1/Ttot);
        Duty=(u8)((f32)Ton*100/Ttot);

    	LCD_voidGoto(1,1);
    	LCD_voidWriteCharachter('F');
    	LCD_voidWriteCharachter('R');
    	LCD_voidWriteCharachter('E');
    	LCD_voidWriteCharachter('Q');
    	LCD_voidWriteCharachter('=');
    	LCD_voidWriteCharachter(' ');
    	LCD_voidWriteCharachter(' ');

    	LCD_voidWriteCharachter(((u8)(Freq/100))+0x30);   //  100????????s
    	LCD_voidWriteCharachter(((u8)(Freq%100)/10)+0x30);
    	LCD_voidWriteCharachter(((u8)(Freq%100)%10)+0x30);


    		LCD_voidWriteCharachter('H');
    		LCD_voidWriteCharachter('Z');

    		LCD_voidGoto(2,1);
    			LCD_voidWriteCharachter('D');
    			LCD_voidWriteCharachter('U');
    			LCD_voidWriteCharachter('T');
    			LCD_voidWriteCharachter('Y');
    			LCD_voidWriteCharachter('=');
    			LCD_voidWriteCharachter(' ');
    			LCD_voidWriteCharachter(' ');

    			LCD_voidWriteCharachter(((u8)(Duty/10))+0x30);
    		    LCD_voidWriteCharachter(((u8)(Duty%10))+0x30);



    			LCD_voidWriteCharachter('%');


    }




}
ISR(TIMER1_CAPT_vect){

	if(FirstReading==1)  // flag to neglect first reading
	{
	FirstReading=0;       // when enter again don`t entre this region
	CLEAR_BIT(TCCR1B,6);  // meaure falling edge change edge
	TCNT1=0;              // make counter zero
	Nov=0;
	State=1;
	}
	else
	{
		if(State==1){
			SET_BIT(TCCR1B,6);   // will meaure rising edge  change edge capture on
			State=0;            // to know which state
			TCNT1=0;            // make counter zero
			Ton= (f32)(ICR1+(Nov*65536))*(f32)((f32)1/12000000);   // (f32) casting to avoid zero
			Nov=0;                                                   // to avoid undefined value (1/0) if this occured will explode
		}
		else{
			CLEAR_BIT(TCCR1B,6);  // meaure fallin edge
			State=1;              //to know which state
			TCNT1=0;             // make counter zero
			Toff=(f32)(ICR1+(Nov*65536))*(f32)((f32)1/12000000);
			Nov=0;

		}
	}
}
ISR(TIMER1_OVF_vect){
	Nov++;
}




