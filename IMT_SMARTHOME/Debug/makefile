################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTIMER/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HSWITCH/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HCLCD/subdir.mk
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
IMT_SMARTHOME.lss \

FLASH_IMAGE += \
IMT_SMARTHOME.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: IMT_SMARTHOME.elf secondary-outputs

# Tool invocations
IMT_SMARTHOME.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,IMT_SMARTHOME.map -mmcu=atmega32 -o "IMT_SMARTHOME.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

IMT_SMARTHOME.lss: IMT_SMARTHOME.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S IMT_SMARTHOME.elf  >"IMT_SMARTHOME.lss"
	@echo 'Finished building: $@'
	@echo ' '

IMT_SMARTHOME.hex: IMT_SMARTHOME.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex IMT_SMARTHOME.elf  "IMT_SMARTHOME.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: IMT_SMARTHOME.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 IMT_SMARTHOME.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) IMT_SMARTHOME.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
