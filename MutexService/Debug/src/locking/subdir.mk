################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/locking/LockEntry.cpp \
../src/locking/SynchronizedLockMap.cpp 

CPP_DEPS += \
./src/locking/LockEntry.d \
./src/locking/SynchronizedLockMap.d 

OBJS += \
./src/locking/LockEntry.o \
./src/locking/SynchronizedLockMap.o 


# Each subdirectory must supply rules for building sources it contributes
src/locking/%.o: ../src/locking/%.cpp src/locking/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -I/usr/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-locking

clean-src-2f-locking:
	-$(RM) ./src/locking/LockEntry.d ./src/locking/LockEntry.o ./src/locking/SynchronizedLockMap.d ./src/locking/SynchronizedLockMap.o

.PHONY: clean-src-2f-locking

