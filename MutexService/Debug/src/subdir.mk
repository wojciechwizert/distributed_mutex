################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LockService.cpp \
../src/LockServiceDispatcher.cpp \
../src/Main.cpp 

CPP_DEPS += \
./src/LockService.d \
./src/LockServiceDispatcher.d \
./src/Main.d 

OBJS += \
./src/LockService.o \
./src/LockServiceDispatcher.o \
./src/Main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -I/usr/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/LockService.d ./src/LockService.o ./src/LockServiceDispatcher.d ./src/LockServiceDispatcher.o ./src/Main.d ./src/Main.o

.PHONY: clean-src

