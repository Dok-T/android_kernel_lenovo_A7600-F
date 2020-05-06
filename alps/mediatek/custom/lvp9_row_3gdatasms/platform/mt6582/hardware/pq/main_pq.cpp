#define LOG_TAG "PQ"

#include <cutils/xlog.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>

#include "ddp_drv.h"
#include "ddp_color_index.h"
#include "ddp_tdshp_index.h"

int drvID = -1;
unsigned long lcmindex = 0; 

//add for distinquishing different LCM and applying different parameters start
//For main source LCM
const DISP_PQ_PARAM pqparam_main =
{
    u4SHPGain:9,
    u4SatGain:8,
    u4HueAdj:{9,10,12,14},
    u4SatAdj:{0,9,18,15}
};

//For second source LCM
const DISP_PQ_PARAM pqparam_2nd =
{
    u4SHPGain:2,
    u4SatGain:0,
    u4HueAdj:{9,9,12,12},
    u4SatAdj:{0,2,6,6}
};

//For main source LCM
const DISP_PQ_PARAM pqparam_camera_main =
{
    u4SHPGain:7,
    u4SatGain:3,
    u4HueAdj:{9,8,10,10},
    u4SatAdj:{0,6,12,6}
};

//For second source LCM
const DISP_PQ_PARAM pqparam_camera_2nd =
{
    u4SHPGain:0,
    u4SatGain:0,
    u4HueAdj:{9,9,9,9},
    u4SatAdj:{0,0,0,0}
};
//add for distinquishing different LCM and applying different parameters end

//add for distinquishing different LCM and applying different parameters start
#define gpio_node "cat /sys/bus/i2c/devices/0-005d/lcm_id"
//add for distinquishing different LCM and applying different parameters end

//COLOR_TUNING_INDEX : 10


//DISPLAY_PQ_T pqindex;
int main(int argc, char** argv) 
{
    int actionID=0, RegBase = 0, RegValue = 0, err = 0;
    char fileName[256];
//add for distinquish different LCM and apply different parameters start
    char *gpio_state = new char;
    FILE *fp;
    if((fp = popen(gpio_node, "r")) == NULL)
    {
        XLOGE("opening gpio table: failed");
    }
    else
    {
        XLOGE("opening gpio table: succeeded");
        fread(gpio_state, sizeof(char), sizeof(*gpio_state), fp);
    }
    pclose(fp);
//add for distinquishing different LCM and applying different parameters end

    XLOGD("PQ init start...");
    if(drvID == -1) //initial
        drvID = open("/dev/mtk_disp", O_RDONLY, 0);

    XLOGD("PQ test...");
    ioctl(drvID, DISP_IOCTL_SET_PQINDEX, &pqindex);
//add for distinquishing different LCM and applying different parameters start
    if(gpio_state[0] == '1')
    {
        ioctl(drvID, DISP_IOCTL_SET_PQPARAM, &pqparam_main);
    }
    else
    {
        ioctl(drvID, DISP_IOCTL_SET_PQPARAM, &pqparam_2nd);
    }
//add for distinquishing different LCM and applying different parameters end
    ioctl(drvID, DISP_IOCTL_SET_GAMMALUT, &gammaindex);
    ioctl(drvID, DISP_IOCTL_SET_TDSHPINDEX, &tdshpindex);
//add for distinquishing different LCM and applying different parameters start
    if(gpio_state[0] == '1')
    {
        ioctl(drvID, DISP_IOCTL_SET_PQ_CAM_PARAM, &pqparam_camera_main);
        ioctl(drvID, DISP_IOCTL_SET_PQ_GAL_PARAM, &pqparam_main);
    }
    else
    {
        ioctl(drvID, DISP_IOCTL_SET_PQ_CAM_PARAM, &pqparam_camera_2nd);
        ioctl(drvID, DISP_IOCTL_SET_PQ_GAL_PARAM, &pqparam_2nd);
    }
    delete gpio_state;
//add for distinquishing different LCM and applying different parameters end

    XLOGD("PQ init end !");
    return 0;
}
