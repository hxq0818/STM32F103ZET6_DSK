/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-16 20:40:15
 * @LastEditors: 
 * @LastEditTime: 2023-04-18 21:04:31
 */
/**************
*  @File name : LOG.c
*  @Author  : xiaoqing.huang
*  @Version : 1.0
*  @Date : 2023-01-12
*  @Description ： 各个模块的log控制
***************/
#include "log.h"

#if DEBUG_SUPPORT

const uint8_t *hxq_debug_str[][35] = {
    {" "},
    {"HXQ_DEBUG_MODULE_SYSTEM_LVL"},
    {"HXQ_DEBUG_MODULE_KEY_LVL"},
		{"HXQ_DEBUG_MODULE_LED_LVL"},
    {"HXQ_DEBUG_MODULE_BEEP_LVL"},
    {"HXQ_DEBUG_MODULE_WWDG_LVL"},
};

unsigned char  hxq_log_buff[HXQ_LOG_MAX_BUFF_SIZE];

#endif /* DEBUG_SUPPORT */

