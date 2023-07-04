################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Src_HAL/Keypad/HAL_Keypad.c 

OBJS += \
./Src/Src_HAL/Keypad/HAL_Keypad.o 

C_DEPS += \
./Src/Src_HAL/Keypad/HAL_Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Src_HAL/Keypad/%.o Src/Src_HAL/Keypad/%.su: ../Src/Src_HAL/Keypad/%.c Src/Src_HAL/Keypad/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Src_HAL-2f-Keypad

clean-Src-2f-Src_HAL-2f-Keypad:
	-$(RM) ./Src/Src_HAL/Keypad/HAL_Keypad.d ./Src/Src_HAL/Keypad/HAL_Keypad.o ./Src/Src_HAL/Keypad/HAL_Keypad.su

.PHONY: clean-Src-2f-Src_HAL-2f-Keypad

