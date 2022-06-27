################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../05-SAFETY/SAFETY_PROGRAM.c 

OBJS += \
./05-SAFETY/SAFETY_PROGRAM.o 

C_DEPS += \
./05-SAFETY/SAFETY_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
05-SAFETY/%.o: ../05-SAFETY/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"F:\CPPUTEST_ECLIPSE\cpputest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


