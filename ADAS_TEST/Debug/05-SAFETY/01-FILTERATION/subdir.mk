################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../05-SAFETY/01-FILTERATION/FILTER_PROGGRAM.c 

OBJS += \
./05-SAFETY/01-FILTERATION/FILTER_PROGGRAM.o 

C_DEPS += \
./05-SAFETY/01-FILTERATION/FILTER_PROGGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
05-SAFETY/01-FILTERATION/%.o: ../05-SAFETY/01-FILTERATION/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"F:\CPPUTEST_ECLIPSE\cpputest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


