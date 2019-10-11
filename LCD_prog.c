/*
 * LCD_prog.c
 *
 *  Created on: Jun 9, 2018
 *      Author: Sedra Frimware
 */
#include"../lib/std_types.h"
#include"../lib/macros.h"
#include<avr/io.h>
#include<util/delay.h>
#include"DIO_interface.h"
#include"LCD_interface.h"




void LCD_voidWriteCharachter(u8 Charachter){
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);

	DIO_voidSetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Charachter,DIO_PIN_0));
	DIO_voidSetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Charachter,DIO_PIN_1));
	DIO_voidSetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Charachter,DIO_PIN_2));
	DIO_voidSetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Charachter,DIO_PIN_3));
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Charachter,DIO_PIN_4));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Charachter,DIO_PIN_5));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Charachter,DIO_PIN_6));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Charachter,DIO_PIN_7));

	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_LOW);

}

/*	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	PORTD=Charachter;
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(2);*/



void LCD_voidSendCommand(u8 Command){
	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);


	DIO_voidSetPinValue(LCD_D0_PORT,LCD_D0_PIN,GET_BIT(Command,DIO_PIN_0));
	DIO_voidSetPinValue(LCD_D1_PORT,LCD_D1_PIN,GET_BIT(Command,DIO_PIN_1));
	DIO_voidSetPinValue(LCD_D2_PORT,LCD_D2_PIN,GET_BIT(Command,DIO_PIN_2));
	DIO_voidSetPinValue(LCD_D3_PORT,LCD_D3_PIN,GET_BIT(Command,DIO_PIN_3));
	DIO_voidSetPinValue(LCD_D4_PORT,LCD_D4_PIN,GET_BIT(Command,DIO_PIN_4));
	DIO_voidSetPinValue(LCD_D5_PORT,LCD_D5_PIN,GET_BIT(Command,DIO_PIN_5));
	DIO_voidSetPinValue(LCD_D6_PORT,LCD_D6_PIN,GET_BIT(Command,DIO_PIN_6));
	DIO_voidSetPinValue(LCD_D7_PORT,LCD_D7_PIN,GET_BIT(Command,DIO_PIN_7));

	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_LOW);


}
/*	DIO_voidSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_voidSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_LOW);
	PORTD=Command;
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_LOW);
	_delay_ms(2);*/

//***************************************************************************************

void LCD_voidGoto(u8 x, u8 y){
	if(x==1){

		LCD_voidSendCommand(0x80+(y-1));
	}else if(x==2){
		LCD_voidSendCommand(0xc0+(y-1));

	}
	_delay_ms(1);
}

void LCD_voidClearScreen(void){
	LCD_voidSendCommand(Clear_Display_Screen);
	_delay_ms(1);
}
void LCD_voidSetCursor(u8 x, u8 y){
	if(x==1){

		LCD_voidSendCommand(0x80+(y-1));
	}
	else if(x==2){
		LCD_voidSendCommand(0xc0+(y-1));

	}
}
//************************************************************************
void LCD_ShiftLeft(void){
	LCD_voidSendCommand(Shiftentire_displaytoleft);
}
void LCD_ShiftRight(void){
	LCD_voidSendCommand(Shiftentire_displaytoright);
}
void LCD_CursorLeft(void){
	LCD_voidSendCommand(ShiftCursor_positiontoleft);

}
void LCD_CursorRight(void){

	LCD_voidSendCommand(ShiftCursor_positiontoright);
}

//****************************************************************************

void LCD_voidInit(void){

	DIO_voidSetPinDir(LCD_D0_PORT,LCD_D0_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_D1_PORT,LCD_D1_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_D2_PORT,LCD_D2_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_D3_PORT,LCD_D3_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_D4_PORT,LCD_D4_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_D5_PORT,LCD_D5_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_D6_PORT,LCD_D6_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_D7_PORT,LCD_D7_PIN,DIO_OUTPUT);

	DIO_voidSetPinDir(LCD_RS_PORT,LCD_RS_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_RW_PORT,LCD_RW_PIN,DIO_OUTPUT);
	DIO_voidSetPinDir(LCD_EN_PORT,LCD_EN_PIN,DIO_OUTPUT);

	LCD_voidSendCommand(LCD_TwoLine5X7);              //LCD_TWoline_5*7
	_delay_ms(1);
	LCD_voidSendCommand(Displayon_Cursoroff);        // trun on crusor on
	_delay_ms(1);
	LCD_voidClearScreen();


}
