################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../04-MCAL/MGIE/MGIE_program.cpp 

OBJS += \
./04-MCAL/MGIE/MGIE_program.o 

CPP_DEPS += \
./04-MCAL/MGIE/MGIE_program.d 


# Each subdirectory must supply rules for building sources it contributes
04-MCAL/MGIE/%.o: ../04-MCAL/MGIE/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"F:\CPPUTEST_ECLIPSE\cpputest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


