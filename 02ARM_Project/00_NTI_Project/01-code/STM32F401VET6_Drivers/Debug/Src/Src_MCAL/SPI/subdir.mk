################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Src_MCAL/SPI/MCAL_SPI.c 

OBJS += \
./Src/Src_MCAL/SPI/MCAL_SPI.o 

C_DEPS += \
./Src/Src_MCAL/SPI/MCAL_SPI.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Src_MCAL/SPI/%.o Src/Src_MCAL/SPI/%.su: ../Src/Src_MCAL/SPI/%.c Src/Src_MCAL/SPI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_APP" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_APP/Utility" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/RCC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/GPIO" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/NVIC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Src/Src_MCAL/EXTIx" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/RCC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/GPIO" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/NVIC" -I"E:/WorkShops ECE Knowledge/GitHup WorkShop/STM32_ARM_Drivers/STM32F401VET6_Drivers/Inc/Inc_MCAL/EXTIx" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Src_MCAL-2f-SPI

clean-Src-2f-Src_MCAL-2f-SPI:
	-$(RM) ./Src/Src_MCAL/SPI/MCAL_SPI.d ./Src/Src_MCAL/SPI/MCAL_SPI.o ./Src/Src_MCAL/SPI/MCAL_SPI.su

.PHONY: clean-Src-2f-Src_MCAL-2f-SPI

