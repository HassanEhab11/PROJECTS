################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Src_APP/Utility/Utility_Delay/DELAY_UNIT.c 

OBJS += \
./Src/Src_APP/Utility/Utility_Delay/DELAY_UNIT.o 

C_DEPS += \
./Src/Src_APP/Utility/Utility_Delay/DELAY_UNIT.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Src_APP/Utility/Utility_Delay/%.o Src/Src_APP/Utility/Utility_Delay/%.su: ../Src/Src_APP/Utility/Utility_Delay/%.c Src/Src_APP/Utility/Utility_Delay/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Src_APP-2f-Utility-2f-Utility_Delay

clean-Src-2f-Src_APP-2f-Utility-2f-Utility_Delay:
	-$(RM) ./Src/Src_APP/Utility/Utility_Delay/DELAY_UNIT.d ./Src/Src_APP/Utility/Utility_Delay/DELAY_UNIT.o ./Src/Src_APP/Utility/Utility_Delay/DELAY_UNIT.su

.PHONY: clean-Src-2f-Src_APP-2f-Utility-2f-Utility_Delay

