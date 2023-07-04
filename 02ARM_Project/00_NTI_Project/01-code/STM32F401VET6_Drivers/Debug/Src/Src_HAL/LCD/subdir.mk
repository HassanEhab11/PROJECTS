################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Src_HAL/LCD/HAL_LCD.c 

OBJS += \
./Src/Src_HAL/LCD/HAL_LCD.o 

C_DEPS += \
./Src/Src_HAL/LCD/HAL_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Src_HAL/LCD/%.o Src/Src_HAL/LCD/%.su: ../Src/Src_HAL/LCD/%.c Src/Src_HAL/LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_APP" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_APP/Utility" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/RCC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/GPIO" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/NVIC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/EXTIx" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/RCC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/GPIO" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/NVIC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/EXTIx" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Src_HAL-2f-LCD

clean-Src-2f-Src_HAL-2f-LCD:
	-$(RM) ./Src/Src_HAL/LCD/HAL_LCD.d ./Src/Src_HAL/LCD/HAL_LCD.o ./Src/Src_HAL/LCD/HAL_LCD.su

.PHONY: clean-Src-2f-Src_HAL-2f-LCD

