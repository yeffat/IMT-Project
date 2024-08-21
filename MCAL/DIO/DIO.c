/*
 * DIO.c
 *
 *  Created on: Sep 16, 2023
 *      Author: hp
 */

#ifndef MCAL_DIO_DIO_C_
#define MCAL_DIO_DIO_C_

#include "DIO_Interface.h"
#include "DIO_Reg.h"
#include "../../LIB/BIT_MATH.h"

/*takes group number which is the A or B or C or D, and the value which is 0xff (output) or 0x00 (input)*/
/*sets the direction of the whole DDR pins according to the value */
void DIO_set_port_dir(u8 Groupnumber, u8 value) {
	switch (Groupnumber) {
	case GROUPA:
		DDRA_REG = value;
		break;
	case GROUPB:
		DDRB_REG = value;
		break;
	case GROUPC:
		DDRC_REG = value;
		break;
	case GROUPD:
		DDRD_REG = value;
		break;
	}
}
/* if the direction was output, this function will be used to set the port to high or low*/
void DIO_set_port(u8 Groupnumber, u8 value) {
	switch (Groupnumber) {
	case GROUPA:
		PORTA_REG = value;
		break;
	case GROUPB:
		PORTB_REG = value;
		break;
	case GROUPC:
		PORTC_REG = value;
		break;
	case GROUPD:
		PORTD_REG = value;
		break;
	}
}
/* if the direction was input, this function will be used to know if the pin is high or low*/
u8 DIO_get_port(u8 Groupnumber) {
	u8 status = 0;
	switch (Groupnumber) {
	case GROUPA:
		status = PINA_REG;
		break;
	case GROUPB:
		status = PINB_REG;
		break;
	case GROUPC:
		status = PINC_REG;
		break;
	case GROUPD:
		status = PIND_REG;
		break;
	}
	return status;
}

// group number is for choosing A, B,C or D8//
//pin number is to choose which pin from 1 to 9//
//status is to decide the direction of DDR//

void DIO_set_pin_dir(u8 Groupnumber, u8 pinNumber, u8 status) {
	if (status == OUTPUT) {
		switch (Groupnumber) {
		case GROUPA:
			SET_BIT(DDRA_REG, pinNumber);
			break;
		case GROUPB:
			SET_BIT(DDRB_REG, pinNumber);
			break;
		case GROUPC:
			SET_BIT(DDRC_REG, pinNumber);
			break;
		case GROUPD:
			SET_BIT(DDRD_REG, pinNumber);
			break;
		}
	} else if (status == INPUT) {
		switch (Groupnumber) {
		case GROUPA:
			CLR_BIT(DDRA_REG, pinNumber);
			break;
		case GROUPB:
			CLR_BIT(DDRB_REG, pinNumber);
			break;
		case GROUPC:
			CLR_BIT(DDRC_REG, pinNumber);
			break;
		case GROUPD:
			CLR_BIT(DDRD_REG, pinNumber);
			break;
		}
	}
}
//if the DDR direction was output this function will be used//
//out_status is if the status is high or low//
//group number is choosing port A, B,C,D//
//pin number is choosing 1  to 8//
void DIO_set_pin(u8 Groupnumber, u8 pinNumber, u8 Out_status) {
	if (Out_status == HIGH) {
		switch (Groupnumber) {
		case GROUPA:
			SET_BIT(PORTA_REG, pinNumber);
			break;
		case GROUPB:
			SET_BIT(PORTB_REG, pinNumber);
			break;
		case GROUPC:
			SET_BIT(PORTC_REG, pinNumber);
			break;
		case GROUPD:
			SET_BIT(PORTD_REG, pinNumber);
			break;
		}
	} else if (Out_status == LOW) {
		switch (Groupnumber) {
		case GROUPA:
			CLR_BIT(PORTA_REG, pinNumber);
			break;
		case GROUPB:
			CLR_BIT(PORTB_REG, pinNumber);
			break;
		case GROUPC:
			CLR_BIT(PORTC_REG, pinNumber);
			break;
		case GROUPD:
			CLR_BIT(PORTD_REG, pinNumber);
			break;
		}
	}
}
//if the DDR direction is input this function will be used//
// group number is A or B or C or D//
//pin number from 0 to 7//
//this function uses GET_BIT to get the status of the input pin if its high or low//
u8 DIO_get_pin(u8 Groupnumber, u8 pinNumber) {
	u8 status = 0;
	switch (Groupnumber) {
	case GROUPA:
		status = GET_BIT(PINA_REG, pinNumber);
		break;
	case GROUPB:
		status = GET_BIT(PINB_REG, pinNumber);
		break;
	case GROUPC:
		status = GET_BIT(PINC_REG, pinNumber);
		break;
	case GROUPD:
		status = GET_BIT(PIND_REG, pinNumber);
		break;
	}
	return status;
}

//u8 DIO_tog_pin(u8 Groupnumber ,u8 pinNumber)
//{
//
//}

#endif /* MCAL_DIO_DIO_C_ */
