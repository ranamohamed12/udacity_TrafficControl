################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GIE_Driver/GIE_program.c 

OBJS += \
./MCAL/GIE_Driver/GIE_program.o 

C_DEPS += \
./MCAL/GIE_Driver/GIE_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GIE_Driver/%.o: ../MCAL/GIE_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


