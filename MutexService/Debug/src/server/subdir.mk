################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/server/HttpServer.cpp \
../src/server/HttpSession.cpp 

CPP_DEPS += \
./src/server/HttpServer.d \
./src/server/HttpSession.d 

OBJS += \
./src/server/HttpServer.o \
./src/server/HttpSession.o 


# Each subdirectory must supply rules for building sources it contributes
src/server/%.o: ../src/server/%.cpp src/server/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -I/usr/include/boost -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-server

clean-src-2f-server:
	-$(RM) ./src/server/HttpServer.d ./src/server/HttpServer.o ./src/server/HttpSession.d ./src/server/HttpSession.o

.PHONY: clean-src-2f-server

