/*
 * UART_Reg.h
 *
 *  Created on: Dec 18, 2024
 *      Author: hp
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_

#define UDR_REG (*(volatile u8*)0x2C)
#define UCSRA_REG (*(volatile u8*)0x2B)
#define UCSRB_REG (*(volatile u8*)0x2A)
#define UBRRL_REG (*(volatile u8*)0x29)
#define UBRRH_REG (*(volatile u8*)0x40)
#define UCSRC_REG (*(volatile u8*)0x40)


#endif /* MCAL_UART_UART_REG_H_ */
