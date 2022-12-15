################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ElectricWaterHeater/HAL/Heating\ element/Heatelem.c 

OBJS += \
./ElectricWaterHeater/HAL/Heating\ element/Heatelem.o 

C_DEPS += \
./ElectricWaterHeater/HAL/Heating\ element/Heatelem.d 


# Each subdirectory must supply rules for building sources it contributes
ElectricWaterHeater/HAL/Heating\ element/Heatelem.o: ../ElectricWaterHeater/HAL/Heating\ element/Heatelem.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"ElectricWaterHeater/HAL/Heating element/Heatelem.d" -MT"ElectricWaterHeater/HAL/Heating\ element/Heatelem.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


