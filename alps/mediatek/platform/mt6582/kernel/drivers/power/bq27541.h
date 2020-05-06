/*****************************************************************************
*
* Filename:
* ---------
*   bq27541.h
*
* Project:
* --------
*   Android
*
* Description:
* ------------
*   bq27541 header file
*
* Author:
* -------
*
****************************************************************************/

#ifndef _bq27541_SW_H_
#define _bq27541_SW_H_

/**********************************************************
  *
  *   [MASK/SHIFT] 
  *
  *********************************************************/
#define BQ27541_CMD_AtRate  					0x02
#define BQ27541_CMD_AtRateTimeToEmpty  			0x04
#define BQ27541_CMD_Temperature  				0x06
#define BQ27541_CMD_Voltage  					0x08
#define BQ27541_CMD_Flags  						0x0A
#define BQ27541_CMD_NominalAvailableCapacity  	0x0C
#define BQ27541_CMD_FullAvailableCapacity  		0x0E
#define BQ27541_CMD_RemainingCapacity  			0x10
#define BQ27541_CMD_FullChargeCapacity  		0x12
#define BQ27541_CMD_AverageCurrent				0x14
#define BQ27541_CMD_TimeToEmpty					0x16
#define BQ27541_CMD_TimeToFull 					0x18
#define BQ27541_CMD_StandbyCurrent				0x1A
#define BQ27541_CMD_StandbyTimeToEmpty			0x1C
#define BQ27541_CMD_MaxLoadCurrent				0x1E
#define BQ27541_CMD_MaxLoadTimeToEmpty			0x20
#define BQ27541_CMD_AvailableEnergy				0x22
#define BQ27541_CMD_AveragePower				0x24
#define BQ27541_CMD_TimeToEmptyAtConstantPower	0x26
#define BQ27541_CMD_Internal_Temp				0x28
#define BQ27541_CMD_CycleCount					0x2A
#define BQ27541_CMD_StateOfCharge				0x2C
#define BQ27541_CMD_StateOfHealth				0x2E
#define BQ27541_CMD_PassedCharge				0x34
#define BQ27541_CMD_DOD0						0x36

#define BQ27541_CMD_Control  					0x00
/* Control subcommands */
#define BQ27541_SUBCMD_CTNL_STATUS  0x0000
#define BQ27541_SUBCMD_DEVCIE_TYPE  0x0001
#define BQ27541_SUBCMD_FW_VER  0x0002
#define BQ27541_SUBCMD_HW_VER  0x0003
#define BQ27541_SUBCMD_DF_CSUM  0x0004
#define BQ27541_SUBCMD_PREV_MACW   0x0007
#define BQ27541_SUBCMD_CHEM_ID   0x0008
#define BQ27541_SUBCMD_BD_OFFSET   0x0009
#define BQ27541_SUBCMD_INT_OFFSET  0x000a
#define BQ27541_SUBCMD_CC_VER   0x000b
#define BQ27541_SUBCMD_OCV  0x000c
#define BQ27541_SUBCMD_BAT_INS   0x000d
#define BQ27541_SUBCMD_BAT_REM   0x000e
#define BQ27541_SUBCMD_SET_HIB   0x0011
#define BQ27541_SUBCMD_CLR_HIB   0x0012
#define BQ27541_SUBCMD_SET_SLP   0x0013
#define BQ27541_SUBCMD_CLR_SLP   0x0014
#define BQ27541_SUBCMD_FCT_RES   0x0015
#define BQ27541_SUBCMD_ENABLE_DLOG  0x0018
#define BQ27541_SUBCMD_DISABLE_DLOG 0x0019
#define BQ27541_SUBCMD_SEALED   0x0020
#define BQ27541_SUBCMD_ENABLE_IT    0x0021
#define BQ27541_SUBCMD_DISABLE_IT   0x0023
#define BQ27541_SUBCMD_CAL_MODE  0x0040
#define BQ27541_SUBCMD_RESET   0x0041

#define BQ27541_EXTCMD_DEVICE_NAME 0x0063

/**********************************************************
  *
  *   [Extern Function] 
  *
  *********************************************************/
extern int bq27541_set_cmd_read(kal_uint8 cmd, int *returnData);
extern int bq27541_set_cmd_write(kal_uint8 cmd, int WriteData);
extern void bq27541_parameter_dump(void);
extern kal_bool ext_fg_init_done;
#endif // _bq27541_SW_H_

