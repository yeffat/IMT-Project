################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../New\ folder/07\ -\ SPI/SPI_prog.c 

OBJS += \
./New\ folder/07\ -\ SPI/SPI_prog.o 

C_DEPS += \
./New\ folder/07\ -\ SPI/SPI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
New\ folder/07\ -\ SPI/SPI_prog.o: ../New\ folder/07\ -\ SPI/SPI_prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"New folder/07 - SPI/SPI_prog.d" -MT"New\ folder/07\ -\ SPI/SPI_prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


