/*
 * @brief: 串口usart1打印应用
 * @version: V1.0
 * @Author: xiaoqing.huang
 * @Date: 2023-04-16 20:40:15
 * @LastEditors: LAPTOP-4DIHEQ1Q
 * @LastEditTime: 2023-04-19 20:03:21
 */

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

