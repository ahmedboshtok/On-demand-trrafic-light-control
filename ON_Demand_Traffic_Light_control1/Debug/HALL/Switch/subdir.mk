################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/Switch/switch_config.c \
../HALL/Switch/switch_prog.c 

OBJS += \
./HALL/Switch/switch_config.o \
./HALL/Switch/switch_prog.o 

C_DEPS += \
./HALL/Switch/switch_config.d \
./HALL/Switch/switch_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/Switch/%.o: ../HALL/Switch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


