################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ElectricWaterHeater/HAL/TempSensADC/subdir.mk
-include ElectricWaterHeater/HAL/Heating\ element/subdir.mk
-include ElectricWaterHeater/HAL/7seg/subdir.mk
-include ElectricWaterHeater/Debug/HAL/Heating\ element/subdir.mk
-include ElectricWaterHeater/Debug/HAL/7seg/subdir.mk
-include ElectricWaterHeater/Debug/App/subdir.mk
-include ElectricWaterHeater/Debug/subdir.mk
-include ElectricWaterHeater/App/subdir.mk
-include ElectricWaterHeater/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ElectricHeater.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ElectricHeater.elf secondary-outputs

# Tool invocations
ElectricHeater.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ElectricHeater.map -mmcu=atmega16 -o "ElectricHeater.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ElectricHeater.lss: ElectricHeater.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ElectricHeater.elf  >"ElectricHeater.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ElectricHeater.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 ElectricHeater.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ElectricHeater.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
