/*
 * UART.c
 *
 *  Created on: Dec 18, 2023
 *      Author: hp
 */

#include "UART.h"
#include "UART_Reg.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void UART_init(void){
	u8 UART_UCSRC_Value = 0;
	u8 Baud_Rate = 51;

	SET_BIT(UCSRB_REG,UCSRB_RXEN); // Enable UART Receiving
	SET_BIT(UCSRB_REG,UCSRB_TXEN); // Enable UART Transmission
	CLR_BIT(UCSRB_REG,UCSRB_UCSZ2); // To Select data size as 8 bit Data
	CLR_BIT(UCSRB_REG,UCSRB_UDRIE); // To Select data size as 8 bit Data
	CLR_BIT(UCSRB_REG,UCSRB_TXCIE);
	CLR_BIT(UCSRB_REG,UCSRB_RXCIE);
	SET_BIT(UART_UCSRC_Value,UCSRC_URSEL); //To Select UCSRC Register
	SET_BIT(UART_UCSRC_Value,UCSRC_UCSZ1); // To Select data size as 8 bit Data
	SET_BIT(UART_UCSRC_Value,UCSRC_UCSZ0); // To Select data size as 8 bit Data
	CLR_BIT(UART_UCSRC_Value,UCSRC_USBS);
	CLR_BIT(UART_UCSRC_Value,UCSRC_UPM0);
	CLR_BIT(UART_UCSRC_Value,UCSRC_UPM1);
	CLR_BIT(UART_UCSRC_Value,UCSRC_UMSEL);


	UCSRC_REG = UART_UCSRC_Value; // Update UCSRC Register value with UART_UCSRC_Value value

	// Baud Rate 9600
//	UBRRH_REG = (u8) Baud_Rate;
//	UBRRL_REG = (u8) (Baud_Rate >> 8);
	UBRRL_REG = 51;


}
void UART_SendData(u8 Data){

	while(GET_BIT(UCSRA_REG,UCSRA_UDRE) == 0); //Polling till Data Register is empty
	UDR_REG = Data;


}
u8 UART_ReceiveData(void){

	while(GET_BIT(UCSRA_REG,UCSRA_RXC) == 0); // Polling till all data is received
	return UDR_REG;
}
void UART_SendString(u8 String[]){
	u8 i = 0;
	while (String[i] != 0 ){
		UART_SendData(String[i]);
		i++;
	}
}
/*void UART_receiveString(u8 *buffer, u16 maxLength) {
    u8 i = 0;
    u16 receivedChar;
    while (i < (maxLength - 1)) {
        receivedChar = UART_ReceiveData(); // Receive a single character
        if (receivedChar == '\n' || receivedChar == '\r') {
            break;
        }
        buffer[i] = receivedChar;
        i++;
    }
    buffer[i] = '\0';
}*/
