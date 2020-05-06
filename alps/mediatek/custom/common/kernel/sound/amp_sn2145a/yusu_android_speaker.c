/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
*                E X T E R N A L      R E F E R E N C E S
******************************************************************************
*/
#include <linux/delay.h>
#include "yusu_android_speaker.h"

#include <mach/mt_gpio.h>
#include <mach/mt_typedefs.h>

/*****************************************************************************
*                C O M P I L E R      F L A G S
******************************************************************************
*/
//#define CONFIG_DEBUG_MSG
#ifdef CONFIG_DEBUG_MSG
#define PRINTK(format, args...) printk( KERN_DEBUG format,##args )
#else
#define PRINTK(format, args...)
#endif

/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define SPK_WARM_UP_TIME        (40) //unit is ms
// SN2415A takes SPK_SHUTDOWN_TIME ms to transfer from shutdown state to operation state
#define SPK_SHUTDOWN_TIME       (80) //unit is ms

/*****************************************************************************
*                         D A T A      T Y P E S
******************************************************************************
*/
static bool gsk_on = false;
static bool gsk_resume = false;
static bool gsk_forceon = false;
static bool g_receiver_on = false;
static unsigned long long g_time_to_shutdown = 0;

/*****************************************************************************
*                  F U N C T I O N        D E F I N I T I O N
******************************************************************************
*/
extern void Yusu_Sound_AMP_Switch(BOOL enable);

bool Speaker_Init(void)
{
    PRINTK("+Speaker_Init Success\n");
    //jeffrey modify
    mt_set_gpio_mode(GPIO_SPEAKER_EN_PIN, GPIO_MODE_00);
    mt_set_gpio_pull_enable(GPIO_SPEAKER_EN_PIN, GPIO_PULL_ENABLE);
    mt_set_gpio_mode(GPIO_EXTERNAL_AMPLIFIER_PIN, GPIO_MODE_00);
    mt_set_gpio_pull_enable(GPIO_EXTERNAL_AMPLIFIER_PIN, GPIO_PULL_ENABLE);
    mt_set_gpio_mode(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_MODE_00);
    mt_set_gpio_pull_enable(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_PULL_ENABLE);
    g_time_to_shutdown = 0;
    PRINTK("-Speaker_Init Success\n");
    return true;
}

bool Speaker_Register(void)
{
    return false;
}

int ExternalAmp(void)
{
    return 0;
}

bool Speaker_DeInit(void)
{
    return false;
}

void Sound_SpeakerL_SetVolLevel(int level)
{
    PRINTK("Sound_SpeakerL_SetVolLevel level=%d\n", level);
}

void Sound_SpeakerR_SetVolLevel(int level)
{
    PRINTK("Sound_SpeakerR_SetVolLevel level=%d\n", level);
}

void Sound_Speaker_Turnon(int channel)
{
    PRINTK("+Sound_Speaker_Turnon channel = %d\n", channel);
    if(!gsk_on) {
        // check if shutdown time expires
        unsigned long long time_to_operate = sched_clock();
        if (g_time_to_shutdown != 0 && time_to_operate > g_time_to_shutdown) {
            unsigned long long elapse_time = time_to_operate - g_time_to_shutdown;
            if (elapse_time < (SPK_SHUTDOWN_TIME * 1000000)) {
                unsigned long sleep_time = SPK_SHUTDOWN_TIME - ((unsigned long)elapse_time / 1000000);
                printk("Sound_Speaker_Turnon wait %lu ms for shutdown time expiration\n", sleep_time);
                msleep(sleep_time);
            }
        }
        
        mt_set_gpio_dir(GPIO_SPEAKER_EN_PIN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_SPEAKER_EN_PIN, GPIO_OUT_ONE);
        mt_set_gpio_dir(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_OUT_ONE);
        mt_set_gpio_dir(GPIO_EXTERNAL_AMPLIFIER_PIN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_EXTERNAL_AMPLIFIER_PIN, GPIO_OUT_ONE);
        msleep(SPK_WARM_UP_TIME);
        gsk_on = true;
    }
    PRINTK("-Sound_Speaker_Turnon channel = %d\n", channel);
}

void Sound_Speaker_Turnoff(int channel)
{
    PRINTK("Sound_Speaker_Turnoff channel = %d\n", channel);
    if (gsk_on) {
        mt_set_gpio_dir(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_OUT_ZERO);
        mt_set_gpio_dir(GPIO_SPEAKER_EN_PIN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_SPEAKER_EN_PIN, GPIO_OUT_ZERO);
        mt_set_gpio_dir(GPIO_EXTERNAL_AMPLIFIER_PIN, GPIO_DIR_OUT);
        mt_set_gpio_out(GPIO_EXTERNAL_AMPLIFIER_PIN, GPIO_OUT_ZERO);
        gsk_on = false;
        g_time_to_shutdown = sched_clock();
    }
}

void Sound_Speaker_SetVolLevel(int level)
{
}

void Sound_Headset_Turnon(void)
{
}

void Sound_Headset_Turnoff(void)
{
}

void AudioAMPDevice_Suspend(void)
{
    PRINTK("AudioDevice_Suspend\n");
    if(gsk_on) {
        Sound_Speaker_Turnoff(Channel_Stereo);
        gsk_resume = true;
    }
}

void AudioAMPDevice_Resume(void)
{
    PRINTK("AudioDevice_Resume\n");
    if(gsk_resume)
        Sound_Speaker_Turnon(Channel_Stereo);
    gsk_resume = false;
}

void AudioAMPDevice_SpeakerLouderOpen(void)
{
    PRINTK("AudioDevice_SpeakerLouderOpen\n");
    gsk_forceon = false;
    Sound_Speaker_Turnon(Channel_Stereo);
    gsk_forceon = true;
}

void AudioAMPDevice_SpeakerLouderClose(void)
{
    PRINTK("AudioDevice_SpeakerLouderClose\n");
    if(gsk_forceon)
        Sound_Speaker_Turnoff(Channel_Stereo);
    gsk_forceon = false;
}

void AudioAMPDevice_mute(void)
{
    PRINTK("AudioDevice_mute\n");
    if(gsk_on)
        Sound_Speaker_Turnoff(Channel_Stereo);
}

int Audio_eamp_command(unsigned int type, unsigned long args, unsigned int count)
{
    switch (type)
    {
    case EAMP_EARPIECE_OPEN:
        PRINTK("Audio_eamp_command EAMP_EARPIECE_OPEN\n");        
        if (!g_receiver_on) {
            mt_set_gpio_dir(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_DIR_OUT);
            mt_set_gpio_out(GPIO_SPEAKER_EARPIECE_SWITCH_PIN, GPIO_OUT_ZERO);
            g_receiver_on = true;
        }
        break;
    case EAMP_EARPIECE_CLOSE:
        PRINTK("Audio_eamp_command EAMP_EARPIECE_CLOSE\n");
        if (g_receiver_on) {
            g_receiver_on = false;
        }
        break;
    default:
        break;
    }
    return 0;
}

kal_int32 Sound_ExtFunction(const char* name, void* param, int param_size)
{
    return 1;
}

