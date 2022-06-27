################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../03-WRAPPING/WDIO/DIO_program.cpp 

OBJS += \
./03-WRAPPING/WDIO/DIO_program.o 

CPP_DEPS += \
./03-WRAPPING/WDIO/DIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
03-WRAPPING/WDIO/%.o: ../03-WRAPPING/WDIO/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"F:\CPPUTEST_ECLIPSE\cpputest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


