################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ADTLL.cpp \
../src/Stack.cpp \
../src/adtll.cpp 

OBJS += \
./src/ADTLL.o \
./src/Stack.o \
./src/adtll.o 

CPP_DEPS += \
./src/ADTLL.d \
./src/Stack.d \
./src/adtll.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


