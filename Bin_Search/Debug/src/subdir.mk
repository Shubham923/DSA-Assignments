################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BST.cpp \
../src/Bin_Search.cpp \
../src/Queue.cpp 

OBJS += \
./src/BST.o \
./src/Bin_Search.o \
./src/Queue.o 

CPP_DEPS += \
./src/BST.d \
./src/Bin_Search.d \
./src/Queue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


