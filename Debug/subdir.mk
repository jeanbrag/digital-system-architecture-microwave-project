################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Button.cpp \
../Buzzer.cpp \
../ControlService.cpp \
../Delay.cpp \
../Key.cpp \
../Led.cpp \
../MotorDc.cpp \
../OperationService.cpp \
../Pwm.cpp \
../RotatingService.cpp \
../SignalingService.cpp \
../main.cpp 

OBJS += \
./Button.o \
./Buzzer.o \
./ControlService.o \
./Delay.o \
./Key.o \
./Led.o \
./MotorDc.o \
./OperationService.o \
./Pwm.o \
./RotatingService.o \
./SignalingService.o \
./main.o 

CPP_DEPS += \
./Button.d \
./Buzzer.d \
./ControlService.d \
./Delay.d \
./Key.d \
./Led.d \
./MotorDc.d \
./OperationService.d \
./Pwm.d \
./RotatingService.d \
./SignalingService.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=gnu++11 -fabi-version=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


