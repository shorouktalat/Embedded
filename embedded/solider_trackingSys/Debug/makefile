################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include UART/subdir.mk
-include TIMER/subdir.mk
-include TEMP_SENSOR/subdir.mk
-include SWITCH/subdir.mk
-include SCHEDULER/subdir.mk
-include LCD/subdir.mk
-include GSM/subdir.mk
-include GPS/subdir.mk
-include DIO/subdir.mk
-include APP/subdir.mk
-include ADC/subdir.mk
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
FinalProjectBACKUP.lss \
FinalProjectBACKUP.lss \

FLASH_IMAGE += \
FinalProjectBACKUP.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: FinalProjectBACKUP.elf secondary-outputs

# Tool invocations
FinalProjectBACKUP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FinalProjectBACKUP.map -mmcu=atmega32 -o "FinalProjectBACKUP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FinalProjectBACKUP.lss: FinalProjectBACKUP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FinalProjectBACKUP.elf  >"FinalProjectBACKUP.lss"
	@echo 'Finished building: $@'
	@echo ' '

FinalProjectBACKUP.hex: FinalProjectBACKUP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FinalProjectBACKUP.elf  "FinalProjectBACKUP.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FinalProjectBACKUP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FinalProjectBACKUP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FinalProjectBACKUP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
