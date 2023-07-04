################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Src_MCAL/GPIO/MCAL_GPIO.c 

OBJS += \
./Src/Src_MCAL/GPIO/MCAL_GPIO.o 

C_DEPS += \
./Src/Src_MCAL/GPIO/MCAL_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Src_MCAL/GPIO/%.o Src/Src_MCAL/GPIO/%.su: ../Src/Src_MCAL/GPIO/%.c Src/Src_MCAL/GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Src_MCAL-2f-GPIO

clean-Src-2f-Src_MCAL-2f-GPIO:
	-$(RM) ./Src/Src_MCAL/GPIO/MCAL_GPIO.d ./Src/Src_MCAL/GPIO/MCAL_GPIO.o ./Src/Src_MCAL/GPIO/MCAL_GPIO.su

.PHONY: clean-Src-2f-Src_MCAL-2f-GPIO

