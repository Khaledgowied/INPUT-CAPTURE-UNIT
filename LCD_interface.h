/*
 * LCD_interface.h
 *
 *  Created on: Jun 9, 2018
 *      Author: Sedra Frimware
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_voidWriteCharachter(u8 Charachter);
void LCD_voidSendCommand(u8 command);
void LCD_voidInit(void);
void LCD_voidGoto(u8 x, u8 y);
void LCD_voidClearScreen(void);
void LCD_voidSetCursor(u8 x, u8 y);
void LCD_ShiftLeft(void);
void LCD_ShiftRight(void);
void LCD_CursorLeft(void);
void LCD_CursorRight(void);



#define LCD_RS_PORT   DIO_PORTA
#define LCD_RS_PIN    DIO_PIN_0

#define LCD_RW_PORT   DIO_PORTA
#define LCD_RW_PIN    DIO_PIN_1

#define LCD_EN_PORT   DIO_PORTA
#define LCD_EN_PIN    DIO_PIN_2


#define LCD_D0_PORT   DIO_PORTC
#define LCD_D0_PIN    DIO_PIN_0

#define LCD_D1_PORT   DIO_PORTC
#define LCD_D1_PIN    DIO_PIN_1

#define LCD_D2_PORT   DIO_PORTC
#define LCD_D2_PIN    DIO_PIN_2


#define LCD_D3_PORT   DIO_PORTC
#define LCD_D3_PIN    DIO_PIN_3


#define LCD_D4_PORT   DIO_PORTC
#define LCD_D4_PIN    DIO_PIN_4

#define LCD_D5_PORT   DIO_PORTC
#define LCD_D5_PIN    DIO_PIN_5


#define LCD_D6_PORT   DIO_PORTC
#define LCD_D6_PIN    DIO_PIN_6


#define LCD_D7_PORT   DIO_PORTC
#define LCD_D7_PIN    DIO_PIN_7



#define LCD_TwoLine5X7                0x38
#define Clear_Display_Screen          0x01
#define Return_Home                   0x02
#define Decrement_Cursor              0x04
#define Increment_Cursor              0x06
#define Shift_Display_Right           0x05
#define Shift_Display_Left            0x07
#define Displayoff_Cursoroff          0x08
#define Displayon_Cursoroff           0x0c
#define Displayon_Cursoron            0x0e
#define Displayon_CursorBlinking      0x0f
#define ShiftCursor_positiontoleft    0x10
#define ShiftCursor_positiontoright   0x14
#define Shiftentire_displaytoleft     0x18
#define Shiftentire_displaytoright    0x1c
#define Cursor_firtLine               0x80
#define Cursor_secondLine             0xc0










#endif /* LCD_INTERFACE_H_ */
