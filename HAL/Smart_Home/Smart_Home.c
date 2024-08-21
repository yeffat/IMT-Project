/*
 * Smart_Home.c
 *
 *  Created on: Mar 16, 2024
 *      Author: hp
 */
#include "Smart_Home.h"

#include "../../MCAL/DIO/DIO_Interface.h"
void Smart_Home_Init(void)
{
		DIO_set_pin_dir(GROUPA,PIN_0,OUTPUT);
		DIO_set_pin_dir(GROUPA,PIN_1,OUTPUT);
		DIO_set_pin_dir(GROUPA,PIN_2,OUTPUT);
		DIO_set_pin_dir(GROUPA,PIN_3,OUTPUT);
		DIO_set_pin_dir(GROUPA,PIN_4,OUTPUT);
		DIO_set_pin(GROUPA,PIN_4,HIGH);
}
void Lights_On(void)
{
		DIO_set_pin(GROUPA,PIN_0,HIGH);
		DIO_set_pin(GROUPA,PIN_1,HIGH);
		DIO_set_pin(GROUPA,PIN_2,HIGH);
}
void Lights_Off(void)
{
		DIO_set_pin(GROUPA,PIN_0,LOW);
		DIO_set_pin(GROUPA,PIN_1,LOW);
		DIO_set_pin(GROUPA,PIN_2,LOW);
}
void Buzzer_On(void)
{
		DIO_set_pin(GROUPA,PIN_3,HIGH);
}
void Buzzer_Off(void)
{
		DIO_set_pin(GROUPA,PIN_3,LOW);
}
void Door_Open(void)
{
		DIO_set_pin(GROUPA,PIN_4,LOW);
}
void Door_Close(void)
{
		DIO_set_pin(GROUPA,PIN_4,HIGH);
}
