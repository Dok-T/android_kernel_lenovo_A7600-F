/*
 * Generated by MTK SP DrvGen Version 03.13.0 for MT6582. Copyright MediaTek Inc. (C) 2013.
 * Tue Dec 10 18:18:33 2013
 * Do Not Modify the File.
 */

#ifndef __CUST_GPIO_USAGE_H__
#define __CUST_GPIO_USAGE_H__


#define GPIO_HWID_1         (GPIO0 | 0x80000000)
#define GPIO_HWID_1_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_1_M_PWM   GPIO_MODE_01

#define GPIO_HWID_2         (GPIO1 | 0x80000000)
#define GPIO_HWID_2_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_2_M_MDEINT   GPIO_MODE_03
#define GPIO_HWID_2_M_PWM   GPIO_MODE_01
#define GPIO_HWID_2_M_DPI_D   GPIO_MODE_02

#define GPIO_SIM1_HOT_PLUG         (GPIO2 | 0x80000000)
#define GPIO_SIM1_HOT_PLUG_M_GPIO   GPIO_MODE_00
#define GPIO_SIM1_HOT_PLUG_M_CLK   GPIO_MODE_01
#define GPIO_SIM1_HOT_PLUG_M_MDEINT   GPIO_MODE_03
#define GPIO_SIM1_HOT_PLUG_M_KCOL   GPIO_MODE_06
#define GPIO_SIM1_HOT_PLUG_M_DPI_D   GPIO_MODE_02
#define GPIO_SIM1_HOT_PLUG_CLK     CLK_OUT0
#define GPIO_SIM1_HOT_PLUG_FREQ    GPIO_CLKSRC_NONE

#define GPIO_HWID_4         (GPIO3 | 0x80000000)
#define GPIO_HWID_4_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_4_M_CLK   GPIO_MODE_01
#define GPIO_HWID_4_M_MDEINT   GPIO_MODE_04
#define GPIO_HWID_4_M_KCOL   GPIO_MODE_06
#define GPIO_HWID_4_CLK     CLK_OUT1
#define GPIO_HWID_4_FREQ    GPIO_CLKSRC_NONE

#define GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN         (GPIO3 | 0x80000000)
#define GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN_M_CLK   GPIO_MODE_01
#define GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN_M_MDEINT   GPIO_MODE_04
#define GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN_M_KCOL   GPIO_MODE_06
#define GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN_CLK     CLK_OUT1
#define GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_HWID_5         (GPIO4 | 0x80000000)
#define GPIO_HWID_5_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_5_M_CLK   GPIO_MODE_01
#define GPIO_HWID_5_M_DPI_D   GPIO_MODE_02
#define GPIO_HWID_5_CLK     CLK_OUT2
#define GPIO_HWID_5_FREQ    GPIO_CLKSRC_NONE

#define GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN         (GPIO4 | 0x80000000)
#define GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN_M_CLK   GPIO_MODE_01
#define GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN_M_DPI_D   GPIO_MODE_02
#define GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN_CLK     CLK_OUT2
#define GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN_FREQ    GPIO_CLKSRC_NONE

#define EINT5_BAT         (GPIO5 | 0x80000000)
#define EINT5_BAT_M_GPIO   GPIO_MODE_00
#define EINT5_BAT_M_KCOL   GPIO_MODE_06
#define EINT5_BAT_M_EINT   EINT5_BAT_M_GPIO

#define EINT6_CAP2         (GPIO6 | 0x80000000)
#define EINT6_CAP2_M_GPIO   GPIO_MODE_00
#define EINT6_CAP2_M_KCOL   GPIO_MODE_06
#define EINT6_CAP2_M_EINT   EINT6_CAP2_M_GPIO

#define EINT7_CAP1         (GPIO7 | 0x80000000)
#define EINT7_CAP1_M_GPIO   GPIO_MODE_00
#define EINT7_CAP1_M_EINT   EINT7_CAP1_M_GPIO

#define EINT8_HALL         (GPIO8 | 0x80000000)
#define EINT8_HALL_M_GPIO   GPIO_MODE_00
#define EINT8_HALL_M_CLK   GPIO_MODE_02
#define EINT8_HALL_M_MDEINT   GPIO_MODE_05
#define EINT8_HALL_M_EINT   EINT8_HALL_M_GPIO
#define EINT8_HALL_CLK     CLK_OUT3
#define EINT8_HALL_FREQ    GPIO_CLKSRC_NONE

#define GPIO_EINT_CHG_STAT_PIN         (GPIO9 | 0x80000000)
#define GPIO_EINT_CHG_STAT_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_EINT_CHG_STAT_PIN_M_CLK   GPIO_MODE_01
#define GPIO_EINT_CHG_STAT_PIN_M_MDEINT   GPIO_MODE_05
#define GPIO_EINT_CHG_STAT_PIN_M_EINT   GPIO_EINT_CHG_STAT_PIN_M_GPIO
#define GPIO_EINT_CHG_STAT_PIN_CLK     CLK_OUT4
#define GPIO_EINT_CHG_STAT_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_CTP_EINT_PIN         (GPIO10 | 0x80000000)
#define GPIO_CTP_EINT_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_CTP_EINT_PIN_M_CLK   GPIO_MODE_01
#define GPIO_CTP_EINT_PIN_M_MDEINT   GPIO_MODE_05
#define GPIO_CTP_EINT_PIN_M_EINT   GPIO_CTP_EINT_PIN_M_GPIO
#define GPIO_CTP_EINT_PIN_CLK     CLK_OUT5
#define GPIO_CTP_EINT_PIN_FREQ    GPIO_CLKSRC_NONE
#define GPIO_CTP_EINT_PIN_NCE     0

#define GPIO_LCMID         (GPIO12 | 0x80000000)
#define GPIO_LCMID_M_GPIO   GPIO_MODE_00
#define GPIO_LCMID_M_CLK   GPIO_MODE_01
#define GPIO_LCMID_M_KCOL   GPIO_MODE_03
#define GPIO_LCMID_M_PWM   GPIO_MODE_02
#define GPIO_LCMID_CLK     CLK_OUT5
#define GPIO_LCMID_FREQ    GPIO_CLKSRC_NONE

#define GPIO_CTP_RST_PIN         (GPIO13 | 0x80000000)
#define GPIO_CTP_RST_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_CTP_RST_PIN_M_MDEINT   GPIO_MODE_04

#define GPIO_ACCDET_EINT_PIN         (GPIO15 | 0x80000000)
#define GPIO_ACCDET_EINT_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_ACCDET_EINT_PIN_M_MDEINT   GPIO_MODE_04
#define GPIO_ACCDET_EINT_PIN_M_EINT   GPIO_ACCDET_EINT_PIN_M_GPIO

#define GPIO_OTG_IDDIG_EINT_PIN         (GPIO17 | 0x80000000)
#define GPIO_OTG_IDDIG_EINT_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_OTG_IDDIG_EINT_PIN_M_CLK   GPIO_MODE_02
#define GPIO_OTG_IDDIG_EINT_PIN_M_IDDIG   GPIO_MODE_04
#define GPIO_OTG_IDDIG_EINT_PIN_CLK     CLK_OUT0
#define GPIO_OTG_IDDIG_EINT_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_BL_CTRL         (GPIO18 | 0x80000000)
#define GPIO_BL_CTRL_M_GPIO   GPIO_MODE_00

#define GPIO_SWCHARGER_EN_PIN         (GPIO19 | 0x80000000)
#define GPIO_SWCHARGER_EN_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_SWCHARGER_EN_PIN_M_CLK   GPIO_MODE_04
#define GPIO_SWCHARGER_EN_PIN_CLK     CLK_OUT1
#define GPIO_SWCHARGER_EN_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_HWID_9         (GPIO20 | 0x80000000)
#define GPIO_HWID_9_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_9_M_CLK   GPIO_MODE_04
#define GPIO_HWID_9_CLK     CLK_OUT2
#define GPIO_HWID_9_FREQ    GPIO_CLKSRC_NONE

#define GPIO_PMIC_EINT_PIN         (GPIO25 | 0x80000000)
#define GPIO_PMIC_EINT_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_PMIC_EINT_PIN_M_EINT   GPIO_PMIC_EINT_PIN_M_GPIO

#define GPIO_SIM1_SCLK         (GPIO29 | 0x80000000)
#define GPIO_SIM1_SCLK_M_GPIO   GPIO_MODE_00
#define GPIO_SIM1_SCLK_M_CLK   GPIO_MODE_01
#define GPIO_SIM1_SCLK_M_MD1_SIM2_SCLK   GPIO_MODE_02

#define GPIO_SIM1_SRST         (GPIO30 | 0x80000000)
#define GPIO_SIM1_SRST_M_GPIO   GPIO_MODE_00
#define GPIO_SIM1_SRST_M_PWM   GPIO_MODE_03
#define GPIO_SIM1_SRST_M_MD1_SIM1_SRST   GPIO_MODE_01
#define GPIO_SIM1_SRST_M_MD1_SIM2_SRST   GPIO_MODE_02

#define GPIO_SIM1_SIO         (GPIO31 | 0x80000000)
#define GPIO_SIM1_SIO_M_GPIO   GPIO_MODE_00
#define GPIO_SIM1_SIO_M_MD1_SIM1_SDAT   GPIO_MODE_01
#define GPIO_SIM1_SIO_M_MD1_SIM2_SDAT   GPIO_MODE_02

#define GPIO_SIM2_SCLK         (GPIO32 | 0x80000000)
#define GPIO_SIM2_SCLK_M_GPIO   GPIO_MODE_00
#define GPIO_SIM2_SCLK_M_CLK   GPIO_MODE_01
#define GPIO_SIM2_SCLK_M_MD1_SIM1_SCLK   GPIO_MODE_02

#define GPIO_SIM2_SRST         (GPIO33 | 0x80000000)
#define GPIO_SIM2_SRST_M_GPIO   GPIO_MODE_00
#define GPIO_SIM2_SRST_M_PWM   GPIO_MODE_03
#define GPIO_SIM2_SRST_M_MD1_SIM2_SRST   GPIO_MODE_01
#define GPIO_SIM2_SRST_M_MD1_SIM1_SRST   GPIO_MODE_02

#define GPIO_SIM2_SIO         (GPIO34 | 0x80000000)
#define GPIO_SIM2_SIO_M_GPIO   GPIO_MODE_00
#define GPIO_SIM2_SIO_M_MD1_SIM2_SDAT   GPIO_MODE_01
#define GPIO_SIM2_SIO_M_MD1_SIM1_SDAT   GPIO_MODE_02
#define GPIO_SIM2_SIO_M_DBG_MON_B   GPIO_MODE_07

#define GPIO_NFC_OSC_EN_PIN         (GPIO38 | 0x80000000)
#define GPIO_NFC_OSC_EN_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_NFC_OSC_EN_PIN_M_CLK   GPIO_MODE_01

#define GPIO_ALS_EINT_PIN         (GPIO40 | 0x80000000)
#define GPIO_ALS_EINT_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_ALS_EINT_PIN_M_KROW   GPIO_MODE_06
#define GPIO_ALS_EINT_PIN_M_EINT   GPIO_ALS_EINT_PIN_M_GPIO

#define GPIO_GPS_LNA_PIN         (GPIO47 | 0x80000000)
#define GPIO_GPS_LNA_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_GPS_LNA_PIN_M_PWM   GPIO_MODE_02
#define GPIO_GPS_LNA_PIN_M_ANT_SEL   GPIO_MODE_01
#define GPIO_GPS_LNA_PIN_M_CONN_MCU_DBGACK_N   GPIO_MODE_03
#define GPIO_GPS_LNA_PIN_M_DBG_MON_A   GPIO_MODE_07

#define GPIO_SPEAKER_EN_PIN         (GPIO57 | 0x80000000)
#define GPIO_SPEAKER_EN_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_SPEAKER_EN_PIN_M_CLK   GPIO_MODE_02
#define GPIO_SPEAKER_EN_PIN_CLK     CLK_OUT1
#define GPIO_SPEAKER_EN_PIN_FREQ    GPIO_CLKSRC_NONE

#define GPIO_SPEAKER_EARPIECE_SWITCH_PIN         (GPIO58 | 0x80000000)
#define GPIO_SPEAKER_EARPIECE_SWITCH_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_HWID_10         (GPIO63 | 0x80000000)
#define GPIO_HWID_10_M_GPIO   GPIO_MODE_00

#define GPIO_HWID_3         (GPIO64 | 0x80000000)
#define GPIO_HWID_3_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_3_M_CLK   GPIO_MODE_02

#define GPIO_EXTERNAL_AMPLIFIER_PIN         (GPIO65 | 0x80000000)
#define GPIO_EXTERNAL_AMPLIFIER_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_KPD_KROW0_PIN         (GPIO74 | 0x80000000)
#define GPIO_KPD_KROW0_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_KPD_KROW0_PIN_M_KROW   GPIO_MODE_01

#define GPIO_KPD_KCOL0_PIN         (GPIO75 | 0x80000000)
#define GPIO_KPD_KCOL0_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_KPD_KCOL0_PIN_M_KCOL   GPIO_MODE_01

#define GPIO_CAMERA_CMRST_PIN         (GPIO80 | 0x80000000)
#define GPIO_CAMERA_CMRST_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_CAMERA_CMPDN1_PIN         (GPIO81 | 0x80000000)
#define GPIO_CAMERA_CMPDN1_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_CAMERA_CMRST1_PIN         (GPIO82 | 0x80000000)
#define GPIO_CAMERA_CMRST1_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_CAMERA_CMPDN_PIN         (GPIO83 | 0x80000000)
#define GPIO_CAMERA_CMPDN_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_I2C0_SDA_PIN         (GPIO84 | 0x80000000)
#define GPIO_I2C0_SDA_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_I2C0_SDA_PIN_M_SDA   GPIO_MODE_01

#define GPIO_I2C0_SCA_PIN         (GPIO85 | 0x80000000)
#define GPIO_I2C0_SCA_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_I2C0_SCA_PIN_M_SCL   GPIO_MODE_01

#define GPIO_I2C1_SDA_PIN         (GPIO86 | 0x80000000)
#define GPIO_I2C1_SDA_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_I2C1_SDA_PIN_M_SDA   GPIO_MODE_01

#define GPIO_I2C1_SCA_PIN         (GPIO87 | 0x80000000)
#define GPIO_I2C1_SCA_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_I2C1_SCA_PIN_M_SCL   GPIO_MODE_01

#define GPIO_HWID_8         (GPIO92 | 0x80000000)
#define GPIO_HWID_8_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_8_M_KROW   GPIO_MODE_01

#define GPIO_HWID_7         (GPIO93 | 0x80000000)
#define GPIO_HWID_7_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_7_M_KROW   GPIO_MODE_01
#define GPIO_HWID_7_M_DRV_VBUS   GPIO_MODE_02

#define GPIO_UART_URXD1_PIN         (GPIO108 | 0x80000000)
#define GPIO_UART_URXD1_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_UART_URXD1_PIN_M_URXD   GPIO_MODE_01
#define GPIO_UART_URXD1_PIN_M_UTXD   GPIO_MODE_02
#define GPIO_UART_URXD1_PIN_M_MD_URXD   GPIO_MODE_03
#define GPIO_UART_URXD1_PIN_M_DBG_MON_B   GPIO_MODE_07

#define GPIO_UART_UTXD1_PIN         (GPIO109 | 0x80000000)
#define GPIO_UART_UTXD1_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_UART_UTXD1_PIN_M_UTXD   GPIO_MODE_01
#define GPIO_UART_UTXD1_PIN_M_URXD   GPIO_MODE_02
#define GPIO_UART_UTXD1_PIN_M_MD_UTXD   GPIO_MODE_03
#define GPIO_UART_UTXD1_PIN_M_TDD_TXD   GPIO_MODE_04
#define GPIO_UART_UTXD1_PIN_M_DBG_MON_B   GPIO_MODE_07

#define GPIO_UART_URXD2_PIN         (GPIO110 | 0x80000000)
#define GPIO_UART_URXD2_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_UART_URXD2_PIN_M_URXD   GPIO_MODE_01
#define GPIO_UART_URXD2_PIN_M_UTXD   GPIO_MODE_02
#define GPIO_UART_URXD2_PIN_M_MD_URXD   GPIO_MODE_03
#define GPIO_UART_URXD2_PIN_M_DBG_MON_B   GPIO_MODE_07

#define GPIO_UART_UTXD2_PIN         (GPIO111 | 0x80000000)
#define GPIO_UART_UTXD2_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_UART_UTXD2_PIN_M_UTXD   GPIO_MODE_01
#define GPIO_UART_UTXD2_PIN_M_URXD   GPIO_MODE_02
#define GPIO_UART_UTXD2_PIN_M_MD_UTXD   GPIO_MODE_03
#define GPIO_UART_UTXD2_PIN_M_TDD_TXD   GPIO_MODE_04
#define GPIO_UART_UTXD2_PIN_M_DBG_MON_B   GPIO_MODE_07

#define GPIO_NFC_RST_PIN         (GPIO112 | 0x80000000)
#define GPIO_NFC_RST_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_LCM_PWR         (GPIO118 | 0x80000000)
#define GPIO_LCM_PWR_M_GPIO   GPIO_MODE_00

#define GPIO_HEADSET_INSERT_PIN         (GPIO119 | 0x80000000)
#define GPIO_HEADSET_INSERT_PIN_M_GPIO   GPIO_MODE_00

#define GPIO_MSDC1_CMD         (GPIO124 | 0x80000000)
#define GPIO_MSDC1_CMD_M_GPIO   GPIO_MODE_00
#define GPIO_MSDC1_CMD_M_MSDC1_CMD   GPIO_MODE_01

#define GPIO_MSDC1_CLK         (GPIO125 | 0x80000000)
#define GPIO_MSDC1_CLK_M_GPIO   GPIO_MODE_00
#define GPIO_MSDC1_CLK_M_CLK   GPIO_MODE_01

#define GPIO_MSDC1_DAT0         (GPIO126 | 0x80000000)
#define GPIO_MSDC1_DAT0_M_GPIO   GPIO_MODE_00
#define GPIO_MSDC1_DAT0_M_MSDC1_DAT   GPIO_MODE_01

#define GPIO_MSDC1_DAT1         (GPIO127 | 0x80000000)
#define GPIO_MSDC1_DAT1_M_GPIO   GPIO_MODE_00
#define GPIO_MSDC1_DAT1_M_MSDC1_DAT   GPIO_MODE_01

#define GPIO_MSDC1_DAT2         (GPIO128 | 0x80000000)
#define GPIO_MSDC1_DAT2_M_GPIO   GPIO_MODE_00
#define GPIO_MSDC1_DAT2_M_MSDC1_DAT   GPIO_MODE_01

#define GPIO_MSDC1_DAT3         (GPIO129 | 0x80000000)
#define GPIO_MSDC1_DAT3_M_GPIO   GPIO_MODE_00
#define GPIO_MSDC1_DAT3_M_MSDC1_DAT   GPIO_MODE_01

#define GPIO_KPD_KCOL1_PIN         (GPIO167 | 0x80000000)
#define GPIO_KPD_KCOL1_PIN_M_GPIO   GPIO_MODE_00
#define GPIO_KPD_KCOL1_PIN_M_KCOL   GPIO_MODE_01

#define GPIO_HWID_6         (GPIO168 | 0x80000000)
#define GPIO_HWID_6_M_GPIO   GPIO_MODE_00
#define GPIO_HWID_6_M_KCOL   GPIO_MODE_01


/*Output for default variable names*/
/*@XXX_XX_PIN in gpio.cmp          */



#endif /* __CUST_GPIO_USAGE_H__ */


