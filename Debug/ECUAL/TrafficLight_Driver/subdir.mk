################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/TrafficLight_Driver/Traffic_program.c 

OBJS += \
./ECUAL/TrafficLight_Driver/Traffic_program.o 

C_DEPS += \
./ECUAL/TrafficLight_Driver/Traffic_program.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/TrafficLight_Driver/%.o: ../ECUAL/TrafficLight_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


