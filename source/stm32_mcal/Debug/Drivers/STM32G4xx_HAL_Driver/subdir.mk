################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c \
C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c 

OBJS += \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_cortex.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma_ex.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_exti.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ex.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ramfunc.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_gpio.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr_ex.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc.o \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc_ex.o 

C_DEPS += \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_cortex.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma_ex.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_exti.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ex.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ramfunc.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_gpio.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr_ex.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc.d \
./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_cortex.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_cortex.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma_ex.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_dma_ex.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_exti.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_exti.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ex.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ex.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ramfunc.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_flash_ramfunc.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_gpio.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_gpio.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr_ex.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_pwr_ex.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc_ex.o: C:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Src/stm32g4xx_hal_rcc_ex.c Drivers/STM32G4xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/ebedir01/STM32Cube/Repository/STM32Cube_FW_G4_V1.6.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32G4xx_HAL_Driver

clean-Drivers-2f-STM32G4xx_HAL_Driver:
	-$(RM) ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_cortex.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_cortex.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_cortex.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_cortex.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma_ex.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma_ex.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma_ex.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_dma_ex.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_exti.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_exti.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_exti.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_exti.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ex.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ex.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ex.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ex.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ramfunc.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ramfunc.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ramfunc.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_flash_ramfunc.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_gpio.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_gpio.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_gpio.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_gpio.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr_ex.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr_ex.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr_ex.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_pwr_ex.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc.su ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc_ex.cyclo ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc_ex.d ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc_ex.o ./Drivers/STM32G4xx_HAL_Driver/stm32g4xx_hal_rcc_ex.su

.PHONY: clean-Drivers-2f-STM32G4xx_HAL_Driver

