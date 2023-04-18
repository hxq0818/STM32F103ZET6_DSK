/*
 * @Descripttion: 
 * @version: 
 * @Author: xiaoqing.huang
 * @Date: 2023-04-16 20:40:24
 * @LastEditors: 
 * @LastEditTime: 2023-04-18 21:04:41
 */
/**************
*  @File name : LOG.h
*  @Author  : xiaoqing.huang
*  @Version : 1.0
*  @Date : 2023-01-12
*  @Description ： 各个模块的log控制
***************/
#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "user_project_config.h"
#include "bsp_usart.h"



#if DEBUG_SUPPORT

#define HXQ_DEBUG_MODULE_SYSTEM_LVL           			1
#define HXQ_DEBUG_MODULE_KEY_LVL       							2
#define HXQ_DEBUG_MODULE_LED_LVL       							3
#define HXQ_DEBUG_MODULE_BEEP_LVL       						4
#define HXQ_DEBUG_MODULE_WWDG_LVL       						5

#define HXQ_LOG_MAX_BUFF_SIZE 258
extern unsigned char hxq_log_buff[HXQ_LOG_MAX_BUFF_SIZE];

extern const uint8_t *hxq_debug_str[][35];

#define DEBUG_LOG(dbg_lvl,format, ...)\
{ \
   if(dbg_lvl!=0) \
      {\
				printf("[%s]:",hxq_debug_str[dbg_lvl][0]);\
				printf(format"\n",##__VA_ARGS__);\
      }\
}
#define DEBUG_LOG_BUFF(dbg_lvl,buff_name,buff, size)\
{ \
   if(dbg_lvl!=0) \
      {\
        int maxSize = HXQ_LOG_MAX_BUFF_SIZE/3;\
        unsigned char  *tmp = buff;\
        memset(hxq_log_buff,0,HXQ_LOG_MAX_BUFF_SIZE);\
        if(size<maxSize)\
        {\
            maxSize = size;\
        }\
        for(int i=0;i<maxSize;i++ )\
        {\
            sprintf((char *)&hxq_log_buff[2*i],"%02x",tmp[i]);\
        }\
           printf("%d,%s:%s\n",dbg_lvl,buff_name,&hxq_log_buff[0]);\
      }\
}
#else 
#define DEBUG_LOG(dbg_lvl,format, ...)
#define DEBUG_LOG_BUFF(dbg_lvl,buff_name,buff, size)
#endif

#endif
