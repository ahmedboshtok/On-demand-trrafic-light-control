################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/LED/LED_config.c \
../HALL/LED/LED_program.c 

OBJS += \
./HALL/LED/LED_config.o \
./HALL/LED/LED_program.o 

C_DEPS += \
./HALL/LED/LED_config.d \
./HALL/LED/LED_program.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/LED/%.o: ../HALL/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


