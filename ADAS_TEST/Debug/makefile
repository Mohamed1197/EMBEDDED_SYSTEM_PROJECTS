################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 05-SAFETY/03-POOL/subdir.mk
-include 05-SAFETY/02-LIMP_HOME/subdir.mk
-include 05-SAFETY/01-FILTERATION/subdir.mk
-include 05-SAFETY/subdir.mk
-include 04-MCAL/MTMR/subdir.mk
-include 04-MCAL/MGIE/subdir.mk
-include 04-MCAL/MEXTI/subdir.mk
-include 04-MCAL/MDIO/subdir.mk
-include 03-WRAPPING/WGIE/subdir.mk
-include 03-WRAPPING/WEXTI/subdir.mk
-include 03-WRAPPING/WDIO/subdir.mk
-include 03-WRAPPING/W8TMR/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ADAS_TEST.exe

# Tool invocations
ADAS_TEST.exe: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cygwin C++ Linker'
	g++ -L"F:\CPPUTEST_ECLIPSE\cpputest/lib" -o "ADAS_TEST.exe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(CPP_DEPS)$(C_DEPS) ADAS_TEST.exe
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
