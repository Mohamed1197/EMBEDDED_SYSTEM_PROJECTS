################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../04-MCAL/MDIO/MDIO_Program.cpp 

OBJS += \
./04-MCAL/MDIO/MDIO_Program.o 

CPP_DEPS += \
./04-MCAL/MDIO/MDIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
04-MCAL/MDIO/%.o: ../04-MCAL/MDIO/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"F:\CPPUTEST_ECLIPSE\cpputest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


