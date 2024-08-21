/*
 * main.c
 *
 *  Created on: Mar 16, 2024
 *      Author: hp
 */
#include "MCAL/UART/UART.h"
#include "avr/delay.h"
#include <string.h>
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "HAL/Smart_Home/Smart_Home.h"

u8 trials = 0;    // Counter for login trials

void main(void){
    UART_init(); // Initialize UART communication and smart home system
    Smart_Home_Init();// Initialize solenoid and buzzer and lights
    UART_SendString("Welcome to Smart Home\n");  // Send welcome message to the user
    _delay_ms(500);

    while(1){
    	// Check if login attempts are less than 3
        if(trials < 3){
            UART_SendString("Enter Username: ");
            u8 username = UART_ReceiveData();
            // Check username and provide access accordingly
            switch(username){
                case 'y':
                    UART_SendString("Welcome youssef\n");
                    break;
                case 'm':
                    UART_SendString("Welcome mohamed\n");
                    break;
                case 'a':
                    UART_SendString("Welcome ahmed\n");
                    break;
                case 'i':
    				UART_SendString("Welcome islam\n");
                    break;
                case 'e':
    				UART_SendString("Welcome emad\n");
                    break;
                case 'n':
    				UART_SendString("Welcome nour\n");
                    break;
                case 'k':
    				UART_SendString("Welcome karim\n");
                    break;
                case 'o':
    				UART_SendString("Welcome omar\n");
                    break;
                case 't':
    				UART_SendString("Welcome tamer\n");
                    break;
                case 'z':
    				UART_SendString("Welcome ziad\n");
                    break;
                // Add cases for other usernames here
                default:
                    UART_SendString("Try Again\n");
                    trials++;
                    continue;
            }
            break;
        }
        else{
        	// If login attempts exceed 3, notify the user
            Buzzer_On();
            UART_SendString("Sorry You Failed 3 Times\n");
            _delay_ms(1500);
            Buzzer_Off();
            trials = 0; // Reset login trials counter
        }
    }

    while(1){
        UART_SendString("Welcome to your Mobile Controlled Home!!!\n\n");
        _delay_ms(10);
        UART_SendString("Pick One of the Following Options:\n");
        _delay_ms(10);
        UART_SendString("1. Turn On Lights\n");
        UART_SendString("2. Open Door\n");
        UART_SendString("3. Turn Off Lights\n");
        UART_SendString("4. Close Door\n");
        UART_SendString("5. Exit\n");
        UART_SendString("\n");
        // Receive user input and execute corresponding action
        u8 option = UART_ReceiveData();
        switch(option){
            case '1':
                UART_SendString("Lights On\n");
                Lights_On();
                break;
            case '2':
                UART_SendString("Door is Open\n");
                Door_Open();
                break;
            case '3':
                UART_SendString("Lights Off\n");
                Lights_Off();
                break;
            case '4':
                UART_SendString("Door is Closed\n");
                Door_Close();
                break;
            case '5':
                UART_SendString("Exit\n");
                return;
            default:
                UART_SendString("Invalid option\n");
                break;
        }
    }
}
