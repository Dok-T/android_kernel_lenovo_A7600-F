cmd_kernel/bounds.s := arm-linux-androideabi-gcc -Wp,-MD,kernel/.bounds.s.d  -nostdinc -isystem /media/src2/LVP5/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.6/bin/../lib/gcc/arm-linux-androideabi/4.6.x-google/include -I/media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/include/linux/kconfig.h  -I../mediatek/platform/mt6582/kernel/core/include/ -I../mediatek/kernel/include/ -I../mediatek/custom/cci82_tb_lvp5_jb5/common/ -I../mediatek/platform/mt6582/kernel/drivers/dispsys -I../mediatek/platform/mt6582/kernel/drivers/video -I../mediatek/platform/mt6582/kernel/drivers/uart/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/accelerometer/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/imgsensor/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/leds/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/headset/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/kpd/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/camera/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/touchpanel/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/flashlight/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/alsps/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/core/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/vibrator/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/dct/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/battery/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/rtc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/barometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/accelerometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/jogball/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/imgsensor/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/sound/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/sound/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/eeprom/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/eeprom/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/leds/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/headset/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/hdmi/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/./ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/gyroscope/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ssw/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ssw/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/flashlight/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/ccci/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/magnetometer/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/alsps/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lcm/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lcm/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lens/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/lens/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/cam_cal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/kernel/cam_cal/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/imgsensor/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/sensors/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/lens/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/audioflinger/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/camera/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/camera/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/inc/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/aal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/matv/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/eeprom/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/fmradio/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/bluetooth/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/combo/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/ant/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/flashlight/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/vt/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/hal/cam_cal/ -I../mediatek/custom/out/cci82_tb_lvp5_jb5/common -D__KERNEL__ -mlittle-endian -Imediatek/platform/mt6582/kernel/core/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -fno-pic -marm -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -fstack-protector -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -DMTK_BT_PROFILE_AVRCP -DMTK_GPS_SUPPORT -DMTK_WFD_SUPPORT -DMTK_FM_SUPPORT -DMTK_USES_HD_VIDEO -DMTK_AUDIO_ADPCM_SUPPORT -DMTK_GEMINI_SMART_3G_SWITCH -DMTK_BT_PROFILE_MANAGER -DMTK_FM_RECORDING_SUPPORT -DMTK_NFC_SE_NUM -DMTK_IPV6_SUPPORT -DMTK_BT_PROFILE_PBAP -DMTK_BT_PROFILE_PAN -DMTK_BT_PROFILE_A2DP -DMTK_BT_PROFILE_HFP -DMTK_VOICE_UI_SUPPORT -DMTK_MASS_STORAGE -DMTK_BICR_SUPPORT -DMTK_THEMEMANAGER_APP -DMTK_HDR_SUPPORT -DMTK_TABLET_DRAM -DHAVE_AACENCODE_FEATURE -DMTK_WIFI_HOTSPOT_SUPPORT -DMTK_COMBO_SUPPORT -DMTK_BT_PROFILE_OPP -DMTK_FLIGHT_MODE_POWER_OFF_MD -DMTK_MULTI_STORAGE_SUPPORT -DMTK_ENABLE_VIDEO_EDITOR -DMTK_EAP_SIM_AKA -DMTK_AUDIO_RAW_SUPPORT -DMTK_WAPI_SUPPORT -DHAVE_ADPCMENCODE_FEATURE -DMTK_WFD_VIDEO_FORMAT -DMTK_FACEBEAUTY_SUPPORT -DMTK_AAL_SUPPORT -DMTK_YAML_SCATTER_FILE_SUPPORT -DMTK_ASF_PLAYBACK_SUPPORT -DMTK_CAMERA_BSP_SUPPORT -DMTK_HIGH_QUALITY_THUMBNAIL -DMTK_FM_RX_SUPPORT -DMTK_ENABLE_MD1 -DHAVE_XLOG_FEATURE -DMTK_VOICE_UNLOCK_SUPPORT -DMTK_MATV_ANALOG_SUPPORT -DMTK_AUTORAMA_SUPPORT -DCUSTOM_KERNEL_ACCELEROMETER -DMTK_BT_SUPPORT -DMTK_VT3G324M_SUPPORT -DMTK_KERNEL_POWER_OFF_CHARGING -DMTK_BT_PROFILE_HIDH -DMTK_ION_SUPPORT -DMTK_PRODUCT_INFO_SUPPORT -DMTK_CAMERA_APP_3DHW_SUPPORT -DMTK_WLAN_SUPPORT -DMTK_PQ_SUPPORT -DMTK_TETHERINGIPV6_SUPPORT -DMTK_UART_USB_SWITCH -DMTK_USES_VR_DYNAMIC_QUALITY_MECHANISM -DMTK_PLATFORM_OPTIMIZE -DMTK_SW_BTCVSD -DMTK_BT_PROFILE_SPP -DMTK_BT_30_SUPPORT -DMTK_HW_ENHANCE -DMTK_LCEEFT_SUPPORT -DMTK_AUDIO_CHANGE_SUPPORT -DMTK_BT_21_SUPPORT -DMTK_DHCPV6C_WIFI -DHAVE_AWBENCODE_FEATURE -DMTK_BQ24196_SUPPORT -DMTK_WEB_NOTIFICATION_SUPPORT -DMTK_MD_SHUT_DOWN_NT -DMTK_SPH_EHN_CTRL_SUPPORT -DMTK_WB_SPEECH_SUPPORT -DCUSTOM_KERNEL_ALSPS -DMTK_SENSOR_SUPPORT -DMTK_M4U_SUPPORT -DMTK_EMMC_SUPPORT -DMTK_VOIP_ENHANCEMENT_SUPPORT -DMT6582 -DFM50AF -DSENSORDRIVE -DDUMMY_LENS -DSENSORDRIVE -DXGA -DAUO_S6D7AA0X04_DSI_VDO -DA5142_MIPI_RAW -DMTK_CONSYS_MT6582 -DCONSTANT_FLASHLIGHT -DOV2659_YUV -DDUMMY_LENS -DMTK_AUDIO_BLOUD_CUSTOMPARAMETER_V4 -DA5142_MIPI_RAW -DOV2659_YUV -DFM_DIGITAL_INPUT -DCONSYS_6582 -DMTK_GPS_MT6582 -DFM50AF -DFM_DIGITAL_OUTPUT -DMT6627_FM -DMTK_SIM1_SOCKET_TYPE=\"1\" -DMTK_TOUCH_PHYSICAL_ROTATION_RELATIVE_TO_LCM=\"0\" -DMTK_LCM_PHYSICAL_ROTATION=\"0\" -DMTK_NEON_SUPPORT=\"yes\" -DMTK_SHARE_MODEM_SUPPORT=\"2\" -DCUSTOM_KERNEL_SSW=\"ssw_single\" -DLCM_HEIGHT=\"1280\" -DMTK_SHARE_MODEM_CURRENT=\"2\" -DLCM_WIDTH=\"800\" -DMTK_SIM2_SOCKET_TYPE=\"1\" -Wframe-larger-than=1400 -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(bounds)"  -D"KBUILD_MODNAME=KBUILD_STR(bounds)" -fverbose-asm -S -o kernel/bounds.s kernel/bounds.c

source_kernel/bounds.s := kernel/bounds.c

deps_kernel/bounds.s := \
  include/linux/page-flags.h \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/s390.h) \
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
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/posix_types.h \
  include/asm-generic/posix_types.h \
  include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/debug/bugverbose.h) \
    $(wildcard include/config/arm/lpae.h) \
  include/linux/linkage.h \
  /media/src2/LVP9-GPL/LVP59-GPL/alps/kernel/arch/arm/include/asm/linkage.h \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/smp.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/cgroup/mem/res/ctlr.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/have/memblock/node.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/kbuild.h \
  include/linux/page_cgroup.h \
    $(wildcard include/config/cgroup/mem/res/ctlr/swap.h) \

kernel/bounds.s: $(deps_kernel/bounds.s)

$(deps_kernel/bounds.s):
