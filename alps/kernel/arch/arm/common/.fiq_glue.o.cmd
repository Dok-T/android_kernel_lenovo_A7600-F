cmd_arch/arm/common/fiq_glue.o := arm-linux-androideabi-gcc -Wp,-MD,arch/arm/common/.fiq_glue.o.d  -nostdinc -isystem /media/src2/LVP5/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.6/bin/../lib/gcc/arm-linux-androideabi/4.6.x-google/include -I/media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/include/linux/kconfig.h  -I../mediatek/platform/mt6582/kernel/core/include/ -I../mediatek/kernel/include/ -I../mediatek/custom/cci82_tb_lvp5_jb5/common/ -I../mediatek/platform/mt6582/kernel/drivers/dispsys -I../mediatek/platform/mt6582/kernel/drivers/video -I../mediatek/platform/mt6582/kernel/drivers/uart/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/accelerometer/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/imgsensor/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/leds/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/headset/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/kpd/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/camera/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/touchpanel/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/flashlight/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/alsps/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/core/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/vibrator/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/dct/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/battery/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/rtc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/barometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/accelerometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/jogball/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/imgsensor/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/sound/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/sound/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/eeprom/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/eeprom/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/leds/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/headset/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/hdmi/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/./ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/gyroscope/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ssw/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ssw/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/flashlight/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ccci/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/magnetometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/alsps/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lcm/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lcm/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lens/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lens/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/cam_cal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/cam_cal/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/imgsensor/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/sensors/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/lens/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/audioflinger/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/camera/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/camera/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/aal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/matv/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/eeprom/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/fmradio/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/bluetooth/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/combo/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/ant/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/flashlight/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/vt/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/cam_cal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/common -D__KERNEL__   -mlittle-endian -Imediatek/platform/mt6582/kernel/core/include -D__ASSEMBLY__   -mabi=aapcs-linux -mno-thumb-interwork  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float -gdwarf-2        -c -o arch/arm/common/fiq_glue.o arch/arm/common/fiq_glue.S

source_arch/arm/common/fiq_glue.o := arch/arm/common/fiq_glue.S

deps_arch/arm/common/fiq_glue.o := \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/linkage.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/mt/sched/monitor.h) \
    $(wildcard include/config/smp.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/hwcap.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \

arch/arm/common/fiq_glue.o: $(deps_arch/arm/common/fiq_glue.o)

$(deps_arch/arm/common/fiq_glue.o):
