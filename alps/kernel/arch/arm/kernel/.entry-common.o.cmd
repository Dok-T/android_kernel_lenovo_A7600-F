cmd_arch/arm/kernel/entry-common.o := arm-linux-androideabi-gcc -Wp,-MD,arch/arm/kernel/.entry-common.o.d  -nostdinc -isystem /media/src2/LVP5/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.6/bin/../lib/gcc/arm-linux-androideabi/4.6.x-google/include -I/media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/include/linux/kconfig.h  -I../mediatek/platform/mt6582/kernel/core/include/ -I../mediatek/kernel/include/ -I../mediatek/custom/cci82_tb_lvp5_jb5/common/ -I../mediatek/platform/mt6582/kernel/drivers/dispsys -I../mediatek/platform/mt6582/kernel/drivers/video -I../mediatek/platform/mt6582/kernel/drivers/uart/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/accelerometer/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/imgsensor/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/leds/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/headset/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/kpd/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/camera/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/touchpanel/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/flashlight/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/alsps/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/core/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/vibrator/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/dct/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/battery/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/rtc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/barometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/accelerometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/jogball/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/imgsensor/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/sound/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/sound/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/eeprom/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/eeprom/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/leds/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/headset/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/hdmi/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/./ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/gyroscope/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ssw/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ssw/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/flashlight/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ccci/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/magnetometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/alsps/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lcm/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lcm/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lens/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lens/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/cam_cal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/cam_cal/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/imgsensor/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/sensors/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/lens/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/audioflinger/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/camera/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/camera/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/aal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/matv/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/eeprom/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/fmradio/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/bluetooth/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/combo/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/ant/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/flashlight/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/vt/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/cam_cal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/common -D__KERNEL__   -mlittle-endian -Imediatek/platform/mt6582/kernel/core/include -D__ASSEMBLY__   -mabi=aapcs-linux -mno-thumb-interwork  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float -gdwarf-2        -c -o arch/arm/kernel/entry-common.o arch/arm/kernel/entry-common.S

source_arch/arm/kernel/entry-common.o := arch/arm/kernel/entry-common.S

deps_arch/arm/kernel/entry-common.o := \
    $(wildcard include/config/need/ret/to/user.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/function/tracer.h) \
    $(wildcard include/config/old/mcount.h) \
    $(wildcard include/config/frame/pointer.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/dynamic/ftrace.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/oabi/compat.h) \
    $(wildcard include/config/arm/thumb.h) \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/aeabi.h) \
    $(wildcard include/config/alignment/trap.h) \
    $(wildcard include/config/seccomp.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/unistd.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/ftrace.h \
    $(wildcard include/config/arm/unwind.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/unwind.h \
  arch/arm/kernel/entry-header.S \
    $(wildcard include/config/cpu/v6.h) \
    $(wildcard include/config/cpu/32v6k.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  arch/arm/include/generated/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/linkage.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/linkage.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/mt/sched/monitor.h) \
    $(wildcard include/config/smp.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/ptrace.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/hwcap.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/asm-offsets.h \
  include/generated/asm-offsets.h \
  arch/arm/include/generated/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/fpstate.h \
    $(wildcard include/config/vfpv3.h) \
    $(wildcard include/config/iwmmxt.h) \
  arch/arm/kernel/calls.S \

arch/arm/kernel/entry-common.o: $(deps_arch/arm/kernel/entry-common.o)

$(deps_arch/arm/kernel/entry-common.o):
