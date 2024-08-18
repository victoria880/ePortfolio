################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs1250/ccs/tools/compiler/ti-cgt-armllvm_3.2.0.LTS/bin/tiarmclang.exe" -c -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=none -mlittle-endian -mthumb -Oz -I"E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang" -I"E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image" -I"E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/source" -I"E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/kernel/nortos" -I"E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/kernel/nortos/posix" -DDeviceFamily_CC3220 -DNORTOS_SUPPORT -gdwarf-3 -march=armv7e-m -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)" -I"E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1582625247: ../gpiointerrupt.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1_12_0/sysconfig_cli.bat" -s "E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/.metadata/product.json" --script "E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/gpiointerrupt.syscfg" -o "syscfg" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-1582625247 ../gpiointerrupt.syscfg
syscfg/ti_drivers_config.h: build-1582625247
syscfg/ti_utils_build_linker.cmd.genlibs: build-1582625247
syscfg/syscfg_c.rov.xs: build-1582625247
syscfg/ti_utils_runtime_model.gv: build-1582625247
syscfg/ti_utils_runtime_Makefile: build-1582625247
syscfg/: build-1582625247

syscfg/%.o: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs1250/ccs/tools/compiler/ti-cgt-armllvm_3.2.0.LTS/bin/tiarmclang.exe" -c -mcpu=cortex-m4 -mfloat-abi=soft -mfpu=none -mlittle-endian -mthumb -Oz -I"E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang" -I"E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image" -I"E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/source" -I"E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/kernel/nortos" -I"E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/kernel/nortos/posix" -DDeviceFamily_CC3220 -DNORTOS_SUPPORT -gdwarf-3 -march=armv7e-m -MMD -MP -MF"syscfg/$(basename $(<F)).d_raw" -MT"$(@)" -I"E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/MCU+Image/syscfg"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-164008369: ../image.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1_12_0/sysconfig_cli.bat" -s "E:/ti/ccs1250/simplelink_cc32xx_sdk_6_10_00_05/.metadata/product.json" --script "E:/Users/vrock/workspace_v12/gpiointerrupt_CC3220S_LAUNCHXL_nortos_ticlang/image.syscfg" -o "syscfg" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_net_wifi_config.json: build-164008369 ../image.syscfg
syscfg/: build-164008369


