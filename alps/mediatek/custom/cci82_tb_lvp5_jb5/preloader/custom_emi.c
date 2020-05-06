/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_emi.c
 *
 * Project:
 * --------
 *   Android
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 *  EMI auto generator V0.01
 *
 *   Memory Device database last modified on 2013/9/11
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * WARNING!!!  WARNING!!!   WARNING!!!  WARNING!!!  WARNING!!!  WARNING!!! 
 * This file is generated by EMI Auto-gen Tool.
 * Please do not modify the content directly!
 * It could be overwritten!
 *============================================================================
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "emi.h"

#define NUM_EMI_RECORD (4)

int num_of_emi_records = NUM_EMI_RECORD ;

EMI_SETTINGS emi_settings[] =
{
     
	//H9TP32A8JDACPR_KGM
	{
		0x0,		/* sub_version */
		0x0202,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x90,0x01,0x4A,0x48,0x34,0x47,0x31,0x64,0x04,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x0002A3AE,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048683,		/* DRAMC_CONF1_VAL */
		0xA00632D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x0340633F,		/* DRAMC_CONF2_VAL */
		0x51642342,		/* DRAMC_PD_CTRL_VAL */
		0x00008888,		/* DRAMC_PADCTL3_VAL */
		0x88888888,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x01000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR2_MODE_REG1 */
		0x00060002,		/* LPDDR2_MODE_REG2 */
		0x00020003,		/* LPDDR2_MODE_REG3 */
		0x00000006,		/* LPDDR2_MODE_REG5 */
		0x00FF000A,		/* LPDDR2_MODE_REG10 */
		0x0000003F,		/* LPDDR2_MODE_REG63 */
	} ,
	//H9TP32A8JDMCPR_KGM
	{
		0x0,		/* sub_version */
		0x0202,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x90,0x01,0x4A,0x20,0x58,0x49,0x4E,0x59,0x48,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x0002A3AE,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048683,		/* DRAMC_CONF1_VAL */
		0xA00632D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x0340633F,		/* DRAMC_CONF2_VAL */
		0x51642342,		/* DRAMC_PD_CTRL_VAL */
		0x00008888,		/* DRAMC_PADCTL3_VAL */
		0x88888888,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x01000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR2_MODE_REG1 */
		0x00060002,		/* LPDDR2_MODE_REG2 */
		0x00020003,		/* LPDDR2_MODE_REG3 */
		0x00000006,		/* LPDDR2_MODE_REG5 */
		0x00FF000A,		/* LPDDR2_MODE_REG10 */
		0x0000003F,		/* LPDDR2_MODE_REG63 */
	} ,
	//KMK7U000VM_B309
	{
		0x0,		/* sub_version */
		0x0202,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		1,		/* FW length */
		{0x15,0x01,0x00,0x4B,0x37,0x55,0x30,0x30,0x4D,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x05,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x0002A3AE,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048683,		/* DRAMC_CONF1_VAL */
		0xA00632D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x0340633F,		/* DRAMC_CONF2_VAL */
		0x51642342,		/* DRAMC_PD_CTRL_VAL */
		0x00000000,		/* DRAMC_PADCTL3_VAL */
		0xEEEEEEEE,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x01000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR2_MODE_REG1 */
		0x00060002,		/* LPDDR2_MODE_REG2 */
		0x00020003,		/* LPDDR2_MODE_REG3 */
		0x00000001,		/* LPDDR2_MODE_REG5 */
		0x00FF000A,		/* LPDDR2_MODE_REG10 */
		0x0000003F,		/* LPDDR2_MODE_REG63 */
	} ,
	//KMK8U000VM_B410
	{
		0x0,		/* sub_version */
		0x0202,		/* TYPE */
		9,		/* EMMC ID/FW ID checking length */
		0,		/* FW length */
		{0x15,0x01,0x00,0x4B,0x38,0x55,0x30,0x30,0x4d,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* NAND_EMMC_ID */
		{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0},		/* FW_ID */
		0x0002A36E,		/* EMI_CONA_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL0_VAL */
		0xAA00AA00,		/* DRAMC_DRVCTL1_VAL */
		0x44584493,		/* DRAMC_ACTIM_VAL */
		0x01000000,		/* DRAMC_GDDR3CTL1_VAL */
		0xF0048683,		/* DRAMC_CONF1_VAL */
		0xA00632D1,		/* DRAMC_DDR2CTL_VAL */
		0xBF080401,		/* DRAMC_TEST2_3_VAL */
		0x0340633F,		/* DRAMC_CONF2_VAL */
		0x51642342,		/* DRAMC_PD_CTRL_VAL */
		0x00008888,		/* DRAMC_PADCTL3_VAL */
		0x88888888,		/* DRAMC_DQODLY_VAL */
		0x00000000,		/* DRAMC_ADDR_OUTPUT_DLY */
		0x00000000,		/* DRAMC_CLK_OUTPUT_DLY */
		0x01000510,		/* DRAMC_ACTIM1_VAL*/
		0x07800000,		/* DRAMC_MISCTL0_VAL*/
		0x04002600,		/* DRAMC_ACTIM05T_VAL*/
		{0x20000000,0x20000000,0,0},		/* DRAM RANK SIZE */
		{0,0,0,0,0,0,0,0,0,0},		/* reserved 10 */
		0x00C30001,		/* LPDDR2_MODE_REG1 */
		0x00060002,		/* LPDDR2_MODE_REG2 */
		0x00020003,		/* LPDDR2_MODE_REG3 */
		0x00000001,		/* LPDDR2_MODE_REG5 */
		0x00FF000A,		/* LPDDR2_MODE_REG10 */
		0x0000003F,		/* LPDDR2_MODE_REG63 */
	} ,
};
