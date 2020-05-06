#ifndef BUILD_LK
#include <linux/string.h>
#include <linux/kernel.h>
#endif
#include "lcm_drv.h"

#ifdef BUILD_LK
#include <platform/mt_gpio.h>
#include <platform/mt_pmic.h>
#include <debug.h>
#elif (defined BUILD_UBOOT)
#include <asm/arch/mt6577_gpio.h>
#else
#include <mach/mt_gpio.h>
#include <linux/xlog.h>
//#include "mt8193_iic.h"
#include <mach/mt_pm_ldo.h>
#include <mach/upmu_common.h>
#endif

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  (800)
#define FRAME_HEIGHT (1280)

//#define LCM_ID_CMI (0x55)

#define GPIO_LCD_RST_EN      GPIO112 //GPIO131
#define GPIO_LCD_POWER_EN    GPIO118 //GPIO137
#define GPIO_LCD__ID    GPIO12 //GPIO154
#define GPIO_PWM_LCD GPIO90 //GPIO129
//#define GPIO_LCD_BL_EN       GPIO32
// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))

#define   LCM_DSI_CMD_MODE		0


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	        lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)											lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)   


static void lcd_power_en(unsigned char enabled)
{
    if (enabled)
    {    
#ifdef BUILD_LK
        /* VMCH1 3.3V */
       // pmic_config_interface(DIGLDO_CON26, 0x01, PMIC_RG_VMCH1_VOSEL_MASK, PMIC_RG_VMCH1_VOSEL_SHIFT);  
       // pmic_config_interface(DIGLDO_CON5, 0x1, PMIC_RG_VMCH1_EN_MASK, PMIC_RG_VMCH1_EN_SHIFT); 
//VRF28-2
#if 0
	pmic_config_interface( (U32)(ANALDO_CON13),
                             (U32)(0x01),
                             (U32)(PMIC_RG_VRF28_2_EN_MASK),
                             (U32)(PMIC_RG_VRF28_2_EN_SHIFT)
	                         );
	pmic_config_interface( (U32)(ANALDO_CON12),
                             (U32)(0),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_MASK),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_SHIFT)
	                         );
#endif
		pmic_config_interface( (kal_uint32)(DIGLDO_CON49),
                             (kal_uint32)(0x01),
                             (kal_uint32)(PMIC_RG_VIO18_EN_MASK),
                             (kal_uint32)(PMIC_RG_VIO18_EN_SHIFT)
	                         );

	#else
        hwPowerOn(MT6323_POWER_LDO_VIO18, VOL_1800, "LCM");
#endif
        MDELAY(20);

        mt_set_gpio_mode(GPIO_LCD_POWER_EN, GPIO_MODE_00);
        mt_set_gpio_dir(GPIO_LCD_POWER_EN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_LCD_POWER_EN, GPIO_OUT_ONE);

    }
    else
    {

        mt_set_gpio_mode(GPIO_LCD_POWER_EN, GPIO_MODE_00);
        mt_set_gpio_dir(GPIO_LCD_POWER_EN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_LCD_POWER_EN, GPIO_OUT_ZERO);

        MDELAY(20); 
		
#ifdef BUILD_LK
        /* VMCH1 3.3V */
        //pmic_config_interface(DIGLDO_CON26, 0x0, PMIC_RG_VMCH1_VOSEL_MASK, PMIC_RG_VMCH1_VOSEL_SHIFT); 
 //VRF28
#if 0
    pmic_config_interface( (U32)(ANALDO_CON12),
                             (U32)(0),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_MASK),
                             (U32)(PMIC_RG_VRF28_2_VOSEL_SHIFT)
	                         );

    pmic_config_interface( (U32)(ANALDO_CON13),
                             (U32)(0x0),
                             (U32)(PMIC_RG_VRF28_2_EN_MASK),
                             (U32)(PMIC_RG_VRF28_2_EN_SHIFT)
                                 );
#endif
	pmic_config_interface( (kal_uint32)(DIGLDO_CON49),
                             (kal_uint32)(0x00),
                             (kal_uint32)(PMIC_RG_VIO18_EN_MASK),
                             (kal_uint32)(PMIC_RG_VIO18_EN_SHIFT)
	                         );
    //pmic_config_interface(DIGLDO_CON5, 0x0, PMIC_RG_VMCH1_EN_MASK, PMIC_RG_VMCH1_EN_SHIFT);   
#else
        hwPowerDown(MT6323_POWER_LDO_VIO18, "LCM");
#endif     	
    }
}

static void lcd_reset(unsigned char enabled)
{
    if (enabled)
    {
        mt_set_gpio_mode(GPIO_LCD_RST_EN, GPIO_MODE_00);
        mt_set_gpio_dir(GPIO_LCD_RST_EN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_LCD_RST_EN, GPIO_OUT_ONE);
    }
    else
    {	
        mt_set_gpio_mode(GPIO_LCD_RST_EN, GPIO_MODE_00);
        mt_set_gpio_dir(GPIO_LCD_RST_EN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_LCD_RST_EN, GPIO_OUT_ZERO);    	
    }
}


static void init_cptlcm_registers(void)
{
    unsigned int data_array[256];

    /* F0,5a,5a */
    data_array[0] = 0x00033902;
    data_array[1] = 0x5a5af0; 
    dsi_set_cmdq(data_array, 2, 1);

    /* Internal setting */
    /* f1,5a,5a */
    data_array[0] = 0x00033902;
    data_array[1] = 0x5a5af1; 
    dsi_set_cmdq(data_array, 2, 1);

    /* 0xFc,A5,A5 */
    data_array[0] = 0x00033902;
    data_array[1] = 0xa5a5fc; 
    dsi_set_cmdq(data_array, 2, 1);
	
    /* 0xd0,00,10 */
    data_array[0] = 0x00033902;
    data_array[1] = 0x1000d0; 
    dsi_set_cmdq(data_array, 2, 1);
	
    /* 0xb1,10 */
    data_array[0] = 0x10b11500;
    dsi_set_cmdq(&data_array,1,1);
	
	
    /* b2,14,22,2f,04 */
    data_array[0] = 0x00053902;
    data_array[1] = 0x2f2214b2; 
    data_array[2] = 0x04;
    dsi_set_cmdq(data_array, 3, 1);

    /* 0xb5,01 */
    data_array[0] = 0x01b51500;
    dsi_set_cmdq(&data_array,1,1);

	
    /* ee,00,00,1f ,00 ,00,00,1f ,00 */
    data_array[0] = 0x00093902;
    data_array[1] = 0x1f0000ee; 
    data_array[2] = 0x1f000000;
    data_array[3] = 0x00;
    dsi_set_cmdq(data_array, 4, 1);

	
	/* ef,56,34,43,65,90,80,24,81,00,91,11,11,11 */
    data_array[0] = 0x000e3902;
    data_array[1] = 0x433456ef; 
    data_array[2] = 0x24809065;
    data_array[3] = 0x11910081;
    data_array[4] = 0x1111;
    dsi_set_cmdq(data_array, 5, 1);

	
	/* f7,04,08,09,0a,0b,0c,0d,0e,0f,16,17,10,01,01,01,04,08,09,0a,0b,0c,0d,0e
	 0f,16,17,10,01,01,01,01,*/
    data_array[0] = 0x00213902;
    data_array[1] = 0x090804f7; 
    data_array[2] = 0x0d0c0b0a; 
    data_array[3] = 0x17160f0e; 
    data_array[4] = 0x01010110; 
    data_array[5] = 0x09080401; 
    data_array[6] = 0x0d0c0b0a; 
    data_array[7] = 0x17160f0e; 
    data_array[8] = 0x01010110; 
    data_array[9] = 0x1; 
    dsi_set_cmdq(data_array, 10, 1);
	
/*f2,02,08,08,40,10*/	
    data_array[0] = 0x00063902;
    data_array[1] = 0x080802f2; 
    data_array[2] = 0x1040;
    dsi_set_cmdq(data_array, 3, 1);

/*f6,60,25,26,00,00,00*/	
    data_array[0] = 0x00073902;
    data_array[1] = 0x262560f6; 
    data_array[2] = 0x000000;
    dsi_set_cmdq(data_array, 3, 1);

/*fa,04,35,07,0b,12,0b,10,16,1a,24,2c,33,3b,3b,33,34,33*/
    data_array[0] = 0x00123902;
    data_array[1] = 0x073504fa; 
    data_array[2] = 0x100b120b; 
    data_array[3] = 0x2c241a16; 
    data_array[4] = 0x333b3b33; 
    data_array[5] = 0x3334; 
    dsi_set_cmdq(data_array, 6, 1);


/*fb,04,35,07,0b,12,0b,10,16,1a,24,2c,33,3b,3b,33,34,33*/
    data_array[0] = 0x00123902;
    data_array[1] = 0x073504fb; 
    data_array[2] = 0x100b120b; 
    data_array[3] = 0x2c241a16; 
    data_array[4] = 0x333b3b33; 
    data_array[5] = 0x3334; 
    dsi_set_cmdq(data_array, 6, 1);
/*f3,01,c4,e0,62,d4,83,37,3c,24,00*/	
    data_array[0] = 0x000b3902;
    data_array[1] = 0xe0c401f3; 
    data_array[2] = 0x3783d462; 
    data_array[3] = 0x00243c; 
    dsi_set_cmdq(data_array, 4, 1);
	
	
/*f4,00,02,03,26,03,02,09,00,07,16,16,03,00,08,08,03,00,08,
	 08,03,19,1a,12,1c,1d,1e,1a,,09,01,04,02,*/	


/*f4,00,02,03,26,03,02,09,00,07,16,16,03,00,08,08,03,00,08,
	 08,03,19,1c ,1a,12,1c,1d,1e,1a,,09,01,04,02,*/	

    data_array[0] = 0x00243902;
    data_array[1] = 0x030200f4; 
    data_array[2] = 0x09020326; 
    data_array[3] = 0x16160700;
	
    data_array[4] = 0x08080003; 
	
    data_array[5] = 0x121c1903; 
    data_array[6] = 0x1a1e1d1c; 
    data_array[7] = 0x02040109; 
    data_array[8] = 0x72757461; 
    data_array[9] = 0xf0808083; 
    dsi_set_cmdq(data_array, 10, 1);
/* 0xb0,01 */
    data_array[0] = 0x01b01500;
    dsi_set_cmdq(&data_array,1,1);

	
/*f5,2f,2f,5f,ab,98,52,0f,33,43,04,59,54,52,05,40,40,5d,59,40,*/	
    data_array[0] = 0x00143902;
    data_array[1] = 0x5f2f2ff5; 
    data_array[2] = 0x0f5298ab; 
    data_array[3] = 0x59044333;
	
    data_array[4] = 0x40055254; 
	
    data_array[5] = 0x40595d40; 

    
    dsi_set_cmdq(data_array, 6, 1);


/* bc,01,4e,08*/
    data_array[0] = 0x00063902;
    data_array[1] = 0x084e01bc; 
    dsi_set_cmdq(data_array, 2, 1);

/* e1,03,10,1c,a0,10 */
    data_array[0] = 0x00063902;
    data_array[1] = 0x1c1003e1; 
    data_array[2] = 0x10a0;
    dsi_set_cmdq(data_array, 3, 1);

/* fd,16,10,11,20,09 */
    data_array[0] = 0x00063902;
    data_array[1] = 0x111016fd; 
    data_array[2] = 0x0920;
    dsi_set_cmdq(data_array, 3, 1);

/*35*/	
    data_array[0] = 0x00350500;
    dsi_set_cmdq(data_array, 1, 1);
	
/*11*/	
    data_array[0] = 0x00110500;
    dsi_set_cmdq(data_array, 1, 1);

    MDELAY(10);
/* c3,40,00,28 */
    data_array[0] = 0x00043902;
    data_array[1] = 0x280040c3; 
    dsi_set_cmdq(data_array, 2, 1);

    MDELAY(150);
/*29*/	
    data_array[0] = 0x00290500;
    dsi_set_cmdq(data_array, 1, 1);
    //MDELAY(200);

}


// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------
static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{
  
    
{
   memset(params, 0, sizeof(LCM_PARAMS));

    params->type   = LCM_TYPE_DSI;

    params->width  = FRAME_WIDTH;
    params->height = FRAME_HEIGHT;

  

#if (LCM_DSI_CMD_MODE)
    params->dsi.mode   = CMD_MODE;
#else
    //params->dsi.mode   = SYNC_PULSE_VDO_MODE;
    params->dsi.mode   = BURST_VDO_MODE;
    //params->dsi.mode   = SYNC_EVENT_VDO_MODE; 
#endif

    // DSI
    /* Command mode setting */
    //1 Three lane or Four lane
    params->dsi.LANE_NUM				= LCM_FOUR_LANE;
    //The following defined the fomat for data coming from LCD engine.
    params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
    params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
    params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
    params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

    // Highly depends on LCD driver capability.
    // Not support in MT6573
    params->dsi.packet_size = 256;

    // Video mode setting		
    params->dsi.intermediat_buffer_num = 0;//because DSI/DPI HW design change, this parameters should be 0 when video mode in MT658X; or memory leakage

    params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;
    params->dsi.word_count = 800*3;	
//    params->dsi.cont_clock=1;
    params->dsi.vertical_sync_active                = 5;
    params->dsi.vertical_backporch                  = 3;
    params->dsi.vertical_frontporch                 = 8 ;
    params->dsi.vertical_active_line                = FRAME_HEIGHT; 
    //params->dsi.HS_TRAIL = 7 ;	

    params->dsi.horizontal_sync_active              = 5;
    params->dsi.horizontal_backporch                = 59;
    params->dsi.horizontal_frontporch               = 16;
    params->dsi.horizontal_active_pixel             = FRAME_WIDTH;

    //params->dsi.compatibility_for_nvk = 0;		// this parameter would be set to 1 if DriverIC is NTK's and when force match DSI clock for NTK's

    // Bit rate calculation
   
    params->dsi.PLL_CLOCK = 250; //LCM_DSI_6589_PLL_CLOCK_227_5;
  
    }
}


static void lcm_init(void)
{
    int lcd_id ;

	#ifdef BUILD_LK
			printf("%s, LK \n", __func__);
	#else
			printk("%s, kernel", __func__);
	#endif
    lcd_power_en(1);
    MDELAY(10);//Must > 5ms
    lcd_reset(0);
    MDELAY(10);//Must > 5ms
    lcd_reset(1);
    MDELAY(120);//Must > 50ms
 //   init_lcm_registers();

    
    init_cptlcm_registers();
       
    #ifdef BUILD_LK
		printf("====cpt initcode end==== \n\n\n");
    #else
		printk("====cpt initcode end====  \n");
    #endif

	
}


static void lcm_suspend(void)
{
    	unsigned int data_array[16];

		#ifdef BUILD_LK
			printf("%s, LK \n", __func__);
	#else
			printk("%s, kernel", __func__);
	#endif
 //   	MDELAY(200);
	    /*display off*/
            /*0x28*/
    #ifndef BUILD_LK
	printk("enter cpt operation ,display off \n");
#endif 
    	data_array[0] = 0x00280500;
        dsi_set_cmdq(data_array, 1, 1);

        MDELAY(80);

    #ifndef BUILD_LK
	printk("BC_CTRL_Disable \n");
#endif 
            /*BC_CTRL_Disable  c3,40,00,20*/
        data_array[0] = 0x00043902;
        data_array[1] = 0x200040c3; 
        dsi_set_cmdq(data_array, 2, 1);


    #ifndef BUILD_LK
	printk("wait for 2 frames to keep DSI videw mode signal \n");
#endif 
	    /*wait for 2 frames to keep DSI video mode signal ** 10 */
        data_array[0] = 0x00100500;
        dsi_set_cmdq(data_array, 1, 1);

        MDELAY(34);

     }
    
    

static void lcm_resume(void)
{
     unsigned int data_array[16];

#if 1
#ifdef BUILD_LK
			printf("%s, LK \n", __func__);
	#else
			printk("%s, kernel", __func__);
	#endif


#ifndef BUILD_LK
	printk("enter cpt resume \n");
	printk("enter mipi video mode on  \n");
#endif
	/* F0,5a,5a */
    	data_array[0] = 0x00033902;
    	data_array[1] = 0x5a5af0;
    	dsi_set_cmdq(data_array, 2, 1);
	/*11*/
#ifndef BUILD_LK
	printk("send sleep out command \n");
#endif
	data_array[0] = 0x00110500;
        dsi_set_cmdq(data_array, 1, 1);
  //      MDELAY(10);
        MDELAY(30);

#ifndef BUILD_LK
	printk("send BC_CTRL_Disable command \n");
#endif
	 /*BC_CTRL_Disable  c3,40,00,28*/
        data_array[0] = 0x00043902;
        data_array[1] = 0x280040c3;
        dsi_set_cmdq(data_array, 2, 1);

        MDELAY(150);
//        MDELAY(250);
/*29*/
#ifndef BUILD_LK
	printk("Send backlight turn on \n");
#endif
	data_array[0] = 0x00290500;
        dsi_set_cmdq(data_array, 1, 1);
        MDELAY(250);

#endif 
   
}

         
#if (LCM_DSI_CMD_MODE)
static void lcm_update(
    unsigned int x, 
    unsigned int y,
    unsigned int width, 
    unsigned int height)
{
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0>>8)&0xFF);
	unsigned char x0_LSB = (x0&0xFF);
	unsigned char x1_MSB = ((x1>>8)&0xFF);
	unsigned char x1_LSB = (x1&0xFF);
	unsigned char y0_MSB = ((y0>>8)&0xFF);
	unsigned char y0_LSB = (y0&0xFF);
	unsigned char y1_MSB = ((y1>>8)&0xFF);
	unsigned char y1_LSB = (y1&0xFF);

	unsigned int data_array[16];

	data_array[0]= 0x00053902;
	data_array[1]= (x1_MSB<<24)|(x0_LSB<<16)|(x0_MSB<<8)|0x2a;
	data_array[2]= (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);
	
	data_array[0]= 0x00053902;
	data_array[1]= (y1_MSB<<24)|(y0_LSB<<16)|(y0_MSB<<8)|0x2b;
	data_array[2]= (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0]= 0x00290508; //HW bug, so need send one HS packet
	dsi_set_cmdq(data_array, 1, 1);
	
	data_array[0]= 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);

}
#endif




LCM_DRIVER auo_s6d7aa0x04_dsi_vdo_lcm_drv = 
{
    .name           = "auo_s6d7aa0x04_dsi_vdo",
    .set_util_funcs = lcm_set_util_funcs,
    .get_params     = lcm_get_params,
    .init           = lcm_init,
    .suspend        = lcm_suspend,
    .resume         = lcm_resume,
    //.compare_id     = lcm_compare_id,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
};



