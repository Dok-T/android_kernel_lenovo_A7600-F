/*****************************************************************************
 *
 * Filename:
 * ---------
 *    linear_charging.c
 *
 * Project:
 * --------
 *   ALPS_Software
 *
 * Description:
 * ------------
 *   This file implements the interface between BMT and ADC scheduler.
 *
 * Author:
 * -------
 *  Oscar Liu
 *
 *============================================================================
  * $Revision:   1.0  $
 * $Modtime:   11 Aug 2005 10:28:16  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/hal/peripheral/inc/bmt_chr_setting.h-arc  $
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <linux/xlog.h>
#include <linux/kernel.h>
#include <mach/battery_common.h>
#include <mach/charging.h>
#include "cust_charging.h"
#include <mach/mt_boot.h>
#include <mach/battery_meter.h>

 // ============================================================ //
 //define
 // ============================================================ //
 //cut off to full
#define POST_CHARGING_TIME	 30 * 60 // 30mins


 // ============================================================ //
 //global variable
 // ============================================================ //
 kal_uint32 g_bcct_flag=0;
 kal_uint32 g_bcct_value=0;

 CHR_CURRENT_ENUM g_temp_CC_value = CHARGE_CURRENT_0_00_MA;
 CHR_CURRENT_ENUM g_temp_input_CC_value = CHARGE_CURRENT_0_00_MA;
 kal_uint32 g_usb_state = USB_UNCONFIGURED;
 
  ///////////////////////////////////////////////////////////////////////////////////////////
  //// JEITA
  ///////////////////////////////////////////////////////////////////////////////////////////
#if defined(MTK_JEITA_STANDARD_SUPPORT)
  int g_temp_status=TEMP_POS_10_TO_POS_45;
  kal_bool temp_error_recovery_chr_flag =KAL_TRUE;
  int CCI_recovery_time_high;
  int CCI_recovery_time_cool;
  int CCI_recovery_time_cold;
#endif

extern int cci_charger_switch;
 
 // ============================================================ //
 // function prototype
 // ============================================================ //
 
 
 // ============================================================ //
 //extern variable
 // ============================================================ //
 extern int g_platform_boot_mode;
 extern int cci_mtktspmic_get_hw_temp();
 // ============================================================ //
 //extern function
 // ============================================================ //
 

 // ============================================================ //
void BATTERY_SetUSBState(int usb_state_value)
{
#if defined(CONFIG_POWER_EXT)
	battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY_SetUSBState] in FPGA/EVB, no service\r\n");
#else
    if ( (usb_state_value < USB_SUSPEND) || ((usb_state_value > USB_CONFIGURED))){
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] BAT_SetUSBState Fail! Restore to default value\r\n");    
        usb_state_value = USB_UNCONFIGURED;
    } else {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] BAT_SetUSBState Success! Set %d\r\n", usb_state_value);    
        g_usb_state = usb_state_value;    
    }
#endif	
}


kal_uint32 get_charging_setting_current()
{
    return g_temp_CC_value;	
}


#if defined(MTK_JEITA_STANDARD_SUPPORT)

static BATTERY_VOLTAGE_ENUM select_jeita_cv(void)
{
    BATTERY_VOLTAGE_ENUM cv_voltage;
#ifdef HIGH_BATTERY_VOLTAGE_SUPPORT // For LVP5
    if(g_temp_status == TEMP_POS_45_TO_POS_60)
    {
	cv_voltage = 4112000; // CV = 4.112V
    }	
    else
    {
	cv_voltage = 4304000; // CV = 4.304V
    }
#else
    if(g_temp_status == TEMP_POS_45_TO_POS_60)
    {
	cv_voltage = 4000000; // CV = 4.0V
    }
    else
    {
	cv_voltage = 4208000; // CV = 4.2V
    }
#endif

    return cv_voltage;
}

PMU_STATUS do_jeita_state_machine(void)
{
	int previous_g_temp_status;
	BATTERY_VOLTAGE_ENUM cv_voltage;
	
    //JEITA battery temp Standard 
	previous_g_temp_status = g_temp_status;

#ifdef HIGH_BATTERY_VOLTAGE_SUPPORT	
    if (BMT_status.temperature >= 50) // T > 50 
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Over high Temperature(50) !!\n\r");
	CCI_recovery_time_high = 30;  
        g_temp_status = TEMP_ABOVE_POS_60;
        return PMU_STATUS_FAIL; 
    }
    else if(BMT_status.temperature > 45)  // 50 > T > 45
    {
        if((g_temp_status == TEMP_ABOVE_POS_60) && (CCI_recovery_time_high > 0))
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 45 and 50, but could not recovery charging !!\n\r"); 
		CCI_recovery_time_high--;
		g_temp_status = TEMP_ABOVE_POS_60;
	        return PMU_STATUS_FAIL;
	}
	else
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 45 and 50 !!\n\r");     
        	g_temp_status = TEMP_POS_45_TO_POS_60;
	}
    }
    else if(BMT_status.temperature >= 20) // 45 > T > 20
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Normal Temperature between 20 and 45 !!\n\r"); 
        g_temp_status = TEMP_POS_10_TO_POS_45;
    }
    else if(BMT_status.temperature >= 0) // 20 > T > 0
    {
        if((g_temp_status == TEMP_NEG_10_TO_POS_0) && (CCI_recovery_time_cool > 0))
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 0 and 15, but could not recovery charging !!\n\r");
		CCI_recovery_time_cool--;    
        	g_temp_status = TEMP_NEG_10_TO_POS_0;
		return PMU_STATUS_FAIL;
	}
	else if((g_temp_status == TEMP_BELOW_NEG_10) && (CCI_recovery_time_cold > 0))
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 0 and 15, but could not recovery charging !!\n\r");
		CCI_recovery_time_cold--;
	        g_temp_status = TEMP_BELOW_NEG_10;
        	return PMU_STATUS_FAIL; 
	}
	else
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 0 and 15 !!\n\r"); 
        	g_temp_status = TEMP_POS_0_TO_POS_10;
	}
    }
#else // For LVP9
    if (BMT_status.temperature >= 55) // T > 55  
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Over high Temperature(55) !!\n\r");
	CCI_recovery_time_high = 30;          
        g_temp_status = TEMP_ABOVE_POS_60;    
        return PMU_STATUS_FAIL; 
    }
    else if(BMT_status.temperature > 45)  // 55 > T > 45
    {
        if((g_temp_status == TEMP_ABOVE_POS_60) && (CCI_recovery_time_high > 0))
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 45 and 55, but could not recovery charging !!\n\r");
		CCI_recovery_time_high--;
		g_temp_status = TEMP_ABOVE_POS_60;
	        return PMU_STATUS_FAIL;
	}
	else
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 45 and 55 !!\n\r");             
        	g_temp_status = TEMP_POS_45_TO_POS_60;
	}
    }
    else if(BMT_status.temperature >= 10) // 45 > T > 10
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Normal Temperature between 10 and 45 !!\n\r"); 
        g_temp_status = TEMP_POS_10_TO_POS_45;
    }
    else if(BMT_status.temperature >= 0) // 10 > T > 0
    {
        if((g_temp_status == TEMP_NEG_10_TO_POS_0) && (CCI_recovery_time_cool > 0))
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 0 and 10, but could not recovery charging !!\n\r");
		CCI_recovery_time_cool--;    
        	g_temp_status = TEMP_NEG_10_TO_POS_0;
		return PMU_STATUS_FAIL;
	}
	else if((g_temp_status == TEMP_BELOW_NEG_10) && (CCI_recovery_time_cold > 0))
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 0 and 10, but could not recovery charging !!\n\r");
		CCI_recovery_time_cold--;
	        g_temp_status = TEMP_BELOW_NEG_10;
        	return PMU_STATUS_FAIL; 
	}
	else
	{
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between 0 and 10 !!\n\r");             
        	g_temp_status = TEMP_POS_0_TO_POS_10;
	}
    }
#endif
    else if(BMT_status.temperature >= -10) // 0 > T > -10
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Temperature between -10 and 0 !!\n\r"); 
        CCI_recovery_time_cool = 30;    
        g_temp_status = TEMP_NEG_10_TO_POS_0;
	return PMU_STATUS_FAIL;
    }
    else
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery below low Temperature(-10) !!\n\r");
	CCI_recovery_time_cold = 60;  
        g_temp_status = TEMP_BELOW_NEG_10;
        return PMU_STATUS_FAIL; 
    }

    //set CV after temperature changed
    if (g_temp_status != previous_g_temp_status) 
    {
	cv_voltage = select_jeita_cv();
	battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] CV changed to %d !!\n\r",cv_voltage);
	battery_charging_control(CHARGING_CMD_SET_CV_VOLTAGE,&cv_voltage);
    }
	
    return PMU_STATUS_OK;
}


static void set_jeita_charging_current(void)
{
#ifdef CONFIG_USB_IF
	if(BMT_status.charger_type == STANDARD_HOST)
		return;
#endif
	
#ifdef HIGH_BATTERY_VOLTAGE_SUPPORT // For LVP5
	if(g_temp_status == TEMP_POS_10_TO_POS_45) // 20 < T <45
	{
		g_temp_CC_value = 153600; // 0.35C (4200 * 0.35)
	}
	if(g_temp_status == TEMP_POS_0_TO_POS_10) // 0 < T < 20
	{
		if(BMT_status.bat_vol < 4100) // V < 4.1V , CC = 0.15C
		{
			g_temp_CC_value = 57600; // (4200 * 0.15)
		}
		else // 4.1V < V < 4.3V , CC = 0.1C
		{
			g_temp_CC_value = 42000; // (4200 * 0.1)
		}
	}
	if(g_temp_status ==TEMP_POS_45_TO_POS_60 ) // 45 < T < 50
	{
		g_temp_CC_value = 121600; // (4200 * 0.3)
	}
#else // For LVP9
	if(g_temp_status == TEMP_POS_10_TO_POS_45) // 10 < T <45
	{
		if(BMT_status.bat_vol < 4000)
		{
			g_temp_CC_value = 153600; // 0.5C, but max 1500mA
		}
		else
		{
			g_temp_CC_value = 128000; // 0.2C (6340 * 0.2)
		}
	}
	if(g_temp_status == TEMP_POS_0_TO_POS_10) // 0 < T < 10
	{
		g_temp_CC_value = 64000; // 0.1C (6340 * 0.1)
	}
	if(g_temp_status ==TEMP_POS_45_TO_POS_60 ) // 45 < T < 55
	{
		g_temp_CC_value = 153600; // 0.5C, but max 1500mA
	}

#endif
}
#endif


void select_charging_curret_bcct(void)
{
     if ( (BMT_status.charger_type == STANDARD_HOST) || 
         (BMT_status.charger_type == NONSTANDARD_CHARGER) )
    {
        if(g_bcct_value < 100)        g_temp_input_CC_value = CHARGE_CURRENT_0_00_MA ;
        else if(g_bcct_value < 500)   g_temp_input_CC_value = CHARGE_CURRENT_100_00_MA;
        else if(g_bcct_value < 800)   g_temp_input_CC_value = CHARGE_CURRENT_500_00_MA;
        else if(g_bcct_value == 800)  g_temp_input_CC_value = CHARGE_CURRENT_800_00_MA;
        else                          g_temp_input_CC_value = CHARGE_CURRENT_500_00_MA;     
    }
    else if( (BMT_status.charger_type == STANDARD_CHARGER) ||
             (BMT_status.charger_type == CHARGING_HOST) )
    {
    	g_temp_input_CC_value = CHARGE_CURRENT_MAX;
		
        //---------------------------------------------------
        //set IOCHARGE
        if(g_bcct_value < 550)        g_temp_CC_value = CHARGE_CURRENT_0_00_MA;
        else if(g_bcct_value < 650)   g_temp_CC_value = CHARGE_CURRENT_550_00_MA;
        else if(g_bcct_value < 750)   g_temp_CC_value = CHARGE_CURRENT_650_00_MA;
        else if(g_bcct_value < 850)   g_temp_CC_value = CHARGE_CURRENT_750_00_MA;
        else if(g_bcct_value < 950)   g_temp_CC_value = CHARGE_CURRENT_850_00_MA;
        else if(g_bcct_value < 1050)  g_temp_CC_value = CHARGE_CURRENT_950_00_MA;
        else if(g_bcct_value < 1150)  g_temp_CC_value = CHARGE_CURRENT_1050_00_MA;
        else if(g_bcct_value < 1250)  g_temp_CC_value = CHARGE_CURRENT_1150_00_MA;
        else if(g_bcct_value == 1250) g_temp_CC_value = CHARGE_CURRENT_1250_00_MA;
        else                          g_temp_CC_value = CHARGE_CURRENT_650_00_MA;
        //---------------------------------------------------
        
    }
    else
    {
        g_temp_input_CC_value = CHARGE_CURRENT_500_00_MA;           
    } 
}


kal_uint32 set_bat_charging_current_limit(int current_limit)
{
    battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] set_bat_charging_current_limit (%d)\r\n", current_limit);

    if(current_limit != -1)
    {
        g_bcct_flag=1;
        
        if(current_limit < 70)         g_temp_CC_value=CHARGE_CURRENT_0_00_MA;
        else if(current_limit < 200)   g_temp_CC_value=CHARGE_CURRENT_70_00_MA;
        else if(current_limit < 300)   g_temp_CC_value=CHARGE_CURRENT_200_00_MA;
        else if(current_limit < 400)   g_temp_CC_value=CHARGE_CURRENT_300_00_MA;
        else if(current_limit < 450)   g_temp_CC_value=CHARGE_CURRENT_400_00_MA;
        else if(current_limit < 550)   g_temp_CC_value=CHARGE_CURRENT_450_00_MA;
        else if(current_limit < 650)   g_temp_CC_value=CHARGE_CURRENT_550_00_MA;
        else if(current_limit < 700)   g_temp_CC_value=CHARGE_CURRENT_650_00_MA;
        else if(current_limit < 800)   g_temp_CC_value=CHARGE_CURRENT_700_00_MA;
        else if(current_limit < 900)   g_temp_CC_value=CHARGE_CURRENT_800_00_MA;
        else if(current_limit < 1000)  g_temp_CC_value=CHARGE_CURRENT_900_00_MA;
        else if(current_limit < 1100)  g_temp_CC_value=CHARGE_CURRENT_1000_00_MA;
        else if(current_limit < 1200)  g_temp_CC_value=CHARGE_CURRENT_1100_00_MA;
        else if(current_limit < 1300)  g_temp_CC_value=CHARGE_CURRENT_1200_00_MA;
        else if(current_limit < 1400)  g_temp_CC_value=CHARGE_CURRENT_1300_00_MA;
        else if(current_limit < 1500)  g_temp_CC_value=CHARGE_CURRENT_1400_00_MA;
        else if(current_limit < 1600)  g_temp_CC_value=CHARGE_CURRENT_1500_00_MA;
        else if(current_limit == 1600) g_temp_CC_value=CHARGE_CURRENT_1600_00_MA;
        else                           g_temp_CC_value=CHARGE_CURRENT_450_00_MA;
    }
    else
    {
        //change to default current setting
        g_bcct_flag=0;
    }
    
    wake_up_bat();

    return g_bcct_flag;
}    


void select_charging_curret(void)
{
    if (g_ftm_battery_flag) 
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] FTM charging : %d\r\n", charging_level_data[0]);    
        g_temp_CC_value = charging_level_data[0];

        if(g_temp_CC_value == CHARGE_CURRENT_450_00_MA)
        { 
			g_temp_input_CC_value = CHARGE_CURRENT_500_00_MA;	
        }
        else
        {            
			g_temp_input_CC_value = CHARGE_CURRENT_MAX;
			g_temp_CC_value = AC_CHARGER_CURRENT;

            battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] set_ac_current \r\n");    
        }        
    }
    else 
    {    
        if ( BMT_status.charger_type == STANDARD_HOST ) 
        {
           #ifdef CONFIG_USB_IF
            {
            	g_temp_input_CC_value = CHARGE_CURRENT_MAX;
                if (g_usb_state == USB_SUSPEND)
                {
                    g_temp_CC_value = USB_CHARGER_CURRENT_SUSPEND;
                }
                else if (g_usb_state == USB_UNCONFIGURED)
                {
                    g_temp_CC_value = USB_CHARGER_CURRENT_UNCONFIGURED;
                }
                else if (g_usb_state == USB_CONFIGURED)
                {
                    g_temp_CC_value = USB_CHARGER_CURRENT_CONFIGURED;
                }
                else
                {
                    g_temp_CC_value = USB_CHARGER_CURRENT_UNCONFIGURED;
                }
                
                 battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] STANDARD_HOST CC mode charging : %d on %d state\r\n", g_temp_CC_value, g_usb_state);
            }
			#else
            {    
 				g_temp_input_CC_value = USB_CHARGER_CURRENT;
                g_temp_CC_value = USB_CHARGER_CURRENT;
            }
			#endif
        } 
        else if (BMT_status.charger_type == NONSTANDARD_CHARGER) 
        {   
        	g_temp_input_CC_value = NON_STD_AC_CHARGER_CURRENT;	
            g_temp_CC_value = NON_STD_AC_CHARGER_CURRENT;

        } 
        else if (BMT_status.charger_type == STANDARD_CHARGER) 
        {
        	g_temp_input_CC_value = AC_CHARGER_CURRENT;
			g_temp_CC_value = AC_CHARGER_CURRENT;
#ifdef MTK_BQ27541_SUPPORT
        	if(BMT_status.cci_NTC_temperature>=38)
        	{
        		g_temp_input_CC_value = 120000; 	
        	}
			battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] cci_NTC_temperature = %d",BMT_status.cci_NTC_temperature);
#endif
        }
        else if (BMT_status.charger_type == CHARGING_HOST) 
        {
        	g_temp_input_CC_value = CHARGING_HOST_CHARGER_CURRENT;
			g_temp_CC_value = CHARGING_HOST_CHARGER_CURRENT;
        }
		else if (BMT_status.charger_type == APPLE_2_1A_CHARGER) 
        {
        	g_temp_input_CC_value = APPLE_2_1A_CHARGER_CURRENT;
            g_temp_CC_value = APPLE_2_1A_CHARGER_CURRENT;
        }
		else if (BMT_status.charger_type == APPLE_1_0A_CHARGER) 
        {
        	g_temp_input_CC_value = APPLE_1_0A_CHARGER_CURRENT;
            g_temp_CC_value = APPLE_1_0A_CHARGER_CURRENT;
        }
		else if (BMT_status.charger_type == APPLE_0_5A_CHARGER) 
        {
        	g_temp_input_CC_value = APPLE_0_5A_CHARGER_CURRENT;
            g_temp_CC_value = APPLE_0_5A_CHARGER_CURRENT;
        }
        else 
        {
			g_temp_input_CC_value = CHARGE_CURRENT_500_00_MA;	
            g_temp_CC_value = CHARGE_CURRENT_500_00_MA;;
        }
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Default CC mode charging : %d, input current = %d\r\n", g_temp_CC_value,g_temp_input_CC_value);
#if defined(MTK_JEITA_STANDARD_SUPPORT)
	set_jeita_charging_current();
#endif		
    }

	
}


static kal_uint32 charging_full_check(void)
{
	kal_uint32 status;

	battery_charging_control(CHARGING_CMD_GET_CHARGING_STATUS,&status);

	return status;
}


static void pchr_turn_on_charging (void)
{
#if !defined(MTK_JEITA_STANDARD_SUPPORT) 
	BATTERY_VOLTAGE_ENUM cv_voltage;
#endif	
	kal_uint32 charging_enable = KAL_TRUE;

    if ( BMT_status.bat_charging_state == CHR_ERROR ) 
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Charger Error, turn OFF charging !\n");

		charging_enable = KAL_FALSE;
        
    }
    else if( (g_platform_boot_mode==META_BOOT) || (g_platform_boot_mode==ADVMETA_BOOT) )
    {   
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] In meta or advanced meta mode, disable charging.\n");    
        charging_enable = KAL_FALSE;
	// Bug 515 disable charging in Meta mode
	battery_charging_control(CHARGING_CMD_SET_HIZ,&charging_enable);
    }
    //  Bug 99 - [LVP5/LVP9] device attribute for enable/disable charing function (Len Tsai)
    else if(cci_charger_switch == 0)
    {
	battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] In RunIN Test or product line T1 station, adb for disabling charging\n");    
        charging_enable = KAL_FALSE;
    }
    //  Bug 99 - [LVP5/LVP9] device attribute for enable/disable charing function (Len Tsai)
    else
    {
        /*HW initialization*/
        battery_charging_control(CHARGING_CMD_INIT,NULL);
		
	    battery_xlog_printk(BAT_LOG_FULL, "charging_hw_init\n" );

        /* Set Charging Current */			
        if (g_bcct_flag == 1)
        {
            select_charging_curret_bcct();

            battery_xlog_printk(BAT_LOG_FULL, "[BATTERY] select_charging_curret_bcct !\n");
        }
        else
        {
            select_charging_curret();

            battery_xlog_printk(BAT_LOG_FULL, "[BATTERY] select_charging_curret !\n");
        }
        
        if( g_temp_CC_value == CHARGE_CURRENT_0_00_MA || g_temp_input_CC_value == CHARGE_CURRENT_0_00_MA)
        {
        
			charging_enable = KAL_FALSE;
						
            battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] charging current is set 0mA, turn off charging !\r\n");
        }
        else
        {    
#ifndef MTK_BQ27541_SUPPORT
		if(cci_mtktspmic_get_hw_temp() > 50000)
		{
			battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] PMIC OVER 50!\r\n");
			g_temp_input_CC_value = 120000;
		}
#endif
		battery_charging_control(CHARGING_CMD_SET_INPUT_CURRENT,&g_temp_input_CC_value);
		battery_charging_control(CHARGING_CMD_SET_CURRENT,&g_temp_CC_value);

			/*Set CV Voltage*/
			#if !defined(MTK_JEITA_STANDARD_SUPPORT)            
                #ifdef HIGH_BATTERY_VOLTAGE_SUPPORT
                    cv_voltage = BATTERY_VOLT_04_320000_V; //4304000
                #else
                    cv_voltage = BATTERY_VOLT_04_212500_V; //4208000
                #endif            
			    battery_charging_control(CHARGING_CMD_SET_CV_VOLTAGE,&cv_voltage);
			#endif
        }
    }
	
	/* enable/disable charging */
  	battery_charging_control(CHARGING_CMD_ENABLE,&charging_enable);
	
	battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] pchr_turn_on_charging(), enable =%d !\r\n", charging_enable);
}

 
PMU_STATUS BAT_PreChargeModeAction(void)
{
    battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Pre-CC mode charge, timer=%ld on %ld !!\n\r", BMT_status.PRE_charging_time, BMT_status.total_charging_time);    
    
    BMT_status.PRE_charging_time += BAT_TASK_PERIOD;
    BMT_status.CC_charging_time = 0;
    BMT_status.TOPOFF_charging_time = 0;
    BMT_status.total_charging_time += BAT_TASK_PERIOD;

    /*  Enable charger */
    pchr_turn_on_charging();            

	if (BMT_status.UI_SOC == 100)
	{
		BMT_status.bat_charging_state = CHR_BATFULL;
		BMT_status.bat_full = KAL_TRUE;
		g_charging_full_reset_bat_meter = KAL_TRUE;
	}
	else if ( BMT_status.bat_vol > V_PRE2CC_THRES )
	{
		BMT_status.bat_charging_state = CHR_CC;
	}

	

    return PMU_STATUS_OK;        
} 


PMU_STATUS BAT_ConstantCurrentModeAction(void)
{
    battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] CC mode charge, timer=%ld on %ld !!\n\r", BMT_status.CC_charging_time, BMT_status.total_charging_time);    

    BMT_status.PRE_charging_time = 0;
    BMT_status.CC_charging_time += BAT_TASK_PERIOD;
    BMT_status.TOPOFF_charging_time = 0;
    BMT_status.total_charging_time += BAT_TASK_PERIOD;

    /*  Enable charger */
    pchr_turn_on_charging();     

	if(charging_full_check() == KAL_TRUE)
	{
	    BMT_status.bat_charging_state = CHR_BATFULL;
		BMT_status.bat_full = KAL_TRUE;
		g_charging_full_reset_bat_meter = KAL_TRUE;
	}	
    	
    return PMU_STATUS_OK;        
}    


PMU_STATUS BAT_BatteryFullAction(void)
{
    battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery full !!\n\r");            
    
    BMT_status.bat_full = KAL_TRUE;
    BMT_status.total_charging_time = 0;
    BMT_status.PRE_charging_time = 0;
    BMT_status.CC_charging_time = 0;
    BMT_status.TOPOFF_charging_time = 0;
    BMT_status.POSTFULL_charging_time = 0;
	BMT_status.bat_in_recharging_state = KAL_FALSE;

	if(charging_full_check() == KAL_FALSE)
    {
        battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Battery Re-charging !!\n\r");                

		BMT_status.bat_in_recharging_state = KAL_TRUE;
        BMT_status.bat_charging_state = CHR_CC;
		battery_meter_reset();
    }        
           
  
    return PMU_STATUS_OK;
}


PMU_STATUS BAT_BatteryHoldAction(void)
{
	kal_uint32 charging_enable;
	
	battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Hold mode !!\n\r");
	 
	if(BMT_status.bat_vol < TALKING_RECHARGE_VOLTAGE || g_call_state == CALL_IDLE)
	{
		BMT_status.bat_charging_state = CHR_CC;
		battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] Exit Hold mode and Enter CC mode !!\n\r");
	}	
		
	/*  Disable charger */
	charging_enable = KAL_FALSE;
	battery_charging_control(CHARGING_CMD_ENABLE,&charging_enable);	

    return PMU_STATUS_OK;
}


PMU_STATUS BAT_BatteryStatusFailAction(void)
{
	kal_uint32 charging_enable;
	
    battery_xlog_printk(BAT_LOG_CRTI, "[BATTERY] BAD Battery status... Charging Stop !!\n\r");            

#if defined(MTK_JEITA_STANDARD_SUPPORT)
    if((g_temp_status == TEMP_ABOVE_POS_60) || (g_temp_status == TEMP_NEG_10_TO_POS_0) ||(g_temp_status == TEMP_BELOW_NEG_10))
    {
        temp_error_recovery_chr_flag=KAL_FALSE;
    }	
    if((temp_error_recovery_chr_flag==KAL_FALSE) && (g_temp_status != TEMP_ABOVE_POS_60) && (g_temp_status != TEMP_BELOW_NEG_10)
	&& (g_temp_status != TEMP_NEG_10_TO_POS_0))
    {
        temp_error_recovery_chr_flag=KAL_TRUE;
        BMT_status.bat_charging_state=CHR_PRE;
    }
#endif

    BMT_status.total_charging_time = 0;
    BMT_status.PRE_charging_time = 0;
    BMT_status.CC_charging_time = 0;
    BMT_status.TOPOFF_charging_time = 0;
    BMT_status.POSTFULL_charging_time = 0;

    /*  Disable charger */
	charging_enable = KAL_FALSE;
	battery_charging_control(CHARGING_CMD_ENABLE,&charging_enable);

    return PMU_STATUS_OK;
}


void mt_battery_charging_algorithm()
{
	battery_charging_control(CHARGING_CMD_RESET_WATCH_DOG_TIMER,NULL);

	switch(BMT_status.bat_charging_state)
    {            
        case CHR_PRE :
            BAT_PreChargeModeAction();
            break;    

		case CHR_CC :
		    BAT_ConstantCurrentModeAction();
		    break;	 
			 
        case CHR_BATFULL:
            BAT_BatteryFullAction();
            break;
            
        case CHR_HOLD:
			BAT_BatteryHoldAction();
			break;		    
			
        case CHR_ERROR:
            BAT_BatteryStatusFailAction();
            break;                
    }    

    battery_charging_control(CHARGING_CMD_DUMP_REGISTER,NULL);
}
 

