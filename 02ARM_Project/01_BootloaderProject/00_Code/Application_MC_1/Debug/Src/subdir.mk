################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/EXTI_program.c \
../Src/MGPIO_Program.c \
../Src/MRCC_Program.c \
../Src/MSTK_Program.c \
../Src/MUSART_Program.c \
../Src/NVIC_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/EXTI_program.o \
./Src/MGPIO_Program.o \
./Src/MRCC_Program.o \
./Src/MSTK_Program.o \
./Src/MUSART_Program.o \
./Src/NVIC_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/EXTI_program.d \
./Src/MGPIO_Program.d \
./Src/MRCC_Program.d \
./Src/MSTK_Program.d \
./Src/MUSART_Program.d \
./Src/NVIC_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CCFx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/MGPIO_Program.d ./Src/MGPIO_Program.o ./Src/MGPIO_Program.su ./Src/MRCC_Program.d ./Src/MRCC_Program.o ./Src/MRCC_Program.su ./Src/MSTK_Program.d ./Src/MSTK_Program.o ./Src/MSTK_Program.su ./Src/MUSART_Program.d ./Src/MUSART_Program.o ./Src/MUSART_Program.su ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

