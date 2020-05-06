#include <linux/types.h>
#include <cust_alsps.h>
#include <linux/platform_device.h>
#include <mach/mt_pm_ldo.h>

static struct alsps_hw cust_alsps_hw = {
    .i2c_num    = 0,             /* i2c bus number, for mt657x, default=0. For mt6589, default=3 */
         //.polling_mode =1,
         .polling_mode_ps =1,
         .polling_mode_als =1,
    .power_id   = MT65XX_POWER_NONE,    /*LDO is not used*/
    .power_vol  = VOL_DEFAULT,          /*LDO is not used*/
    .i2c_addr   = {0x90, 0x00, 0x00, 0x00},         /*STK3x1x*/
    .als_level  = {5,  9, 36, 59, 82, 132, 205, 273, 500, 845, 1136, 1545, 2364, 4655, 6982},  /* als_code */
    .als_value  = {0, 10, 40, 65, 90, 145, 225, 300, 550, 930, 1250, 1700, 2600, 5120, 7680, 10240},    /* lux */   
    .ps_threshold_high = 1700,
    .ps_threshold_low = 1500,
};
struct alsps_hw *get_cust_alsps_hw(void) {
    return &cust_alsps_hw;
}
